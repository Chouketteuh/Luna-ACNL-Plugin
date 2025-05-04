#include "Cheats.hpp"
#include "Game.hpp"
#include "KeySequence.hpp"
#include "QuickMenu.hpp"
#include "csvc.h"

#define ONLINETHREADSAMOUNT 5
#define THREADVARS_MAGIC  0x21545624

std::tuple<u32, u32*> onlineThreadsInfo[ONLINETHREADSAMOUNT];

namespace CTRPluginFramework
{
	bool DevMode = false;

	void PlayerUpdateCallback(void)
	{
		Player::GetInstance()->Load();
	}

	// This patch the NFC disabling the touchscreen when scanning an amiibo, which prevents ctrpf to be used
	void ToggleTouchscreenForceOn(void)
    {
        static u32 original = 0;
        static u32 *patchAddress = nullptr;

        if (patchAddress && original)
        {
            *patchAddress = original;
            return;
        }

        static const u32Vector pattern =
        {
            0xE59F10C0, 0xE5840004, 0xE5841000, 0xE5DD0000,
            0xE5C40008, 0xE28DD03C, 0xE8BD80F0, 0xE5D51001,
            0xE1D400D4, 0xE3510003, 0x159F0034, 0x1A000003
        };

        Result  res;
        Handle  processHandle;
        s64     textTotalRoundedSize = 0;
        s64     startAddress = 0;
        u32 *   found;

        if (R_FAILED(svcOpenProcess(&processHandle, 16)))
            return;

        svcGetProcessInfo(&textTotalRoundedSize, processHandle, 0x10002);
        svcGetProcessInfo(&startAddress, processHandle, 0x10005);
        if(R_FAILED(svcMapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, processHandle, (u32)startAddress, textTotalRoundedSize, static_cast<MapExFlags>(0))))
            goto exit;

        found = (u32 *)Utils::Search<u32>(0x14000000, (u32)textTotalRoundedSize, pattern);

        if (found != nullptr)
        {
            original = found[13];
            patchAddress = (u32 *)PA_FROM_VA((found + 13));
            found[13] = 0xE1A00000;
        }

        svcUnmapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, textTotalRoundedSize);
		exit:
        svcCloseHandle(processHandle);
    }


	bool IsFolderUsable(MenuFolder *folder, bool OnOff)
	{
		if(OnOff)
		{
			if(!folder->IsVisible()) 
				folder->Show();
		}
		else
		{
			if(folder->IsVisible()) 
				folder->Hide();	
		}
		return folder->IsVisible();
	}

	u32 FindBasePtr(u32 pbw)
	{
		u32 *addr = (u32 *)0x00100000;
		u32 totalSize = Process::GetTextSize() + Process::GetRoDataSize() + Process::GetRwDataSize();

		totalSize /= 4;

		u32 *addrEnd = (u32 *)0x00100000 + totalSize;

		while (addr != addrEnd)
		{
			u32 val = *addr++;

			if (Process::CheckAddress(val + 0xE30))
			{
				if (*(vu32 *)(val + 0xE30) == pbw)
				{
					return (u32)addr;
				}
			}
		}
		return 0;
	}

	void ResetBools(void)
	{
		extern bool WantReload;
		extern bool TimeMachineBool;

		if(TimeMachineBool && (Player::GetCurrentInventory() == 0x2E)) // Wait until the player as open the time menu
		{
			TimeMachineBool = false;
		}
		if(WantReload && Player::InLoadingState()) // Wait until the player is in loading state
		{
			WantReload = false;
		}
	}

	/*
	Thanks to PabloMK7 for the huge help with the thread loading! (From Vapecord)
	*/
	void KeepConnectionInCTRPF(bool runOnline)
	{
		static bool isRunOnline = false;

		if(isRunOnline == runOnline)
			return;

		isRunOnline = runOnline;
		static u32 tlsBackup[ONLINETHREADSAMOUNT];
		static s32 prioBackup[ONLINETHREADSAMOUNT];

		for(int i = 0; i < ONLINETHREADSAMOUNT; i++)
		{
			u32 onlineThreadID = std::get<0>(onlineThreadsInfo[i]);
			u32* onlineThreadTls = std::get<1>(onlineThreadsInfo[i]);

			if(onlineThreadID == 0xFFFFFFFF) 
				continue;

			Handle onlineThreadHandle;
			Result res = svcOpenThread(&onlineThreadHandle, CUR_PROCESS_HANDLE, onlineThreadID);
			if(R_FAILED(res)) 
				return;

			if(runOnline)
			{
				tlsBackup[i] = *onlineThreadTls;
				*onlineThreadTls = THREADVARS_MAGIC;
				svcGetThreadPriority(&prioBackup[i], onlineThreadHandle);
				svcSetThreadPriority(onlineThreadHandle, FwkSettings::Get().ThreadPriority - 1);
			}
			else
			{
				*onlineThreadTls = tlsBackup[i];
				svcSetThreadPriority(onlineThreadHandle, prioBackup[i]);
			}

			svcCloseHandle(onlineThreadHandle);
		}
	}

	u32 getThread1Func(s8 threadPos, int param_1, u32 param_2, u32 param_3, u32 param_4)
	{
		u32 obj_threadID = 0;
		u32* threadTls = nullptr;
		Result res = svcGetThreadId(&obj_threadID, CUR_THREAD_HANDLE);
		if(R_FAILED(res)) 
			obj_threadID = 0xFFFFFFFF;
		else 
			threadTls = (u32*)getThreadLocalStorage();

		onlineThreadsInfo[threadPos] = std::tuple<u32, u32*>(obj_threadID, threadTls);

		vu32(*origFunc)(u32 param1, u32 param2, u32 param3, u32 param4);
		Process::Write32((u32)&origFunc, 0x55D728); //0x55C770 EUR
		return origFunc(param_1, param_2, param_3, param_4);
	}

	u32 getThread2Func(s8 threadPos, int param_1, u32 param_2, u32 param_3, u32 param_4)
	{
		u32 obj_threadID = 0;
		u32* threadTls = nullptr;
		Result res = svcGetThreadId(&obj_threadID, CUR_THREAD_HANDLE);
		if(R_FAILED(res)) 
			obj_threadID = 0xFFFFFFFF;
		else 
			threadTls = (u32*)getThreadLocalStorage();

		onlineThreadsInfo[threadPos] = std::tuple<u32, u32*>(obj_threadID, threadTls);

		vu32(*origFunc)(u32 param1, u32 param2, u32 param3, u32 param4);
		Process::Write32((u32)&origFunc, 0x53C04C); //0x53B094 EUR
		return origFunc(param_1, param_2, param_3, param_4);
	}

	u32 GetThreadInfo1(int param_1, u32 param_2, u32 param_3, u32 param_4)
	{
		return getThread1Func(0, param_1, param_2, param_3, param_4);
	}

	u32 GetThreadInfo2(int param_1, u32 param_2, u32 param_3, u32 param_4)
	{
		return getThread2Func(1, param_1, param_2, param_3, param_4);
	}

	u32 GetThreadInfo3(int param_1, u32 param_2, u32 param_3, u32 param_4) 
	{
		return getThread2Func(2, param_1, param_2, param_3, param_4);
	}

	u32 GetThreadInfo4(int param_1, u32 param_2, u32 param_3, u32 param_4)
	{
		return getThread2Func(3, param_1, param_2, param_3, param_4);
	}

	u32 GetThreadInfo5(int param_1, u32 param_2, u32 param_3, u32 param_4)
	{
		return getThread1Func(4, param_1, param_2, param_3, param_4);
	}

	void PatchThreadBegin(u32 threadfunc, u32 threadargs, u32 startFunc, u32 u0)
	{
		static u32 threadAddress = *(u32 *)(*(u32 *)(0x953CA0) + 0xA8 + 0x80) - 0x2C;

		static u32 onlineThreadArgs[ONLINETHREADSAMOUNT] =
		{
			0x82C0FF8, //Region Free
			0x82C2DD0, //Region Free
			0x82D7588, //Region Free
			0x82E5AE0, //Region Free
			threadAddress
		};

		if(threadargs-0x18 == onlineThreadArgs[0])
			threadfunc = (u32)GetThreadInfo1;
		else if(threadargs-0x18 == onlineThreadArgs[1])
			threadfunc = (u32)GetThreadInfo2;
		else if(threadargs-0x18 == onlineThreadArgs[2])
			threadfunc = (u32)GetThreadInfo3;
		else if(threadargs-0x18 == onlineThreadArgs[3])
			threadfunc = (u32)GetThreadInfo4;
		else if(threadargs-0x18 == onlineThreadArgs[4]) 
			threadfunc = (u32)GetThreadInfo5;
		
		vu32(*sFunc)(u32 param1, u32 param2);
		Process::Write32((u32)&sFunc, startFunc);
		(void)sFunc(threadfunc, threadargs);
	}

	void SendPlayerData/*0x1B6C28*/(Time time) //needs to be set into OnNewFrame callback
	{
		if(Game::GetOnlinePlayerCount() <= 1 || PluginMenu::GetRunningInstance() == nullptr)
			return;

		vu32(*sendData1)(u32 param1);
		Process::Write32((u32)&sendData1, 0x617D20); //0x616D58 EUR
		(void)sendData1(*(u32 *)USA_Game_Pointer);

		if(*(u8 *)(0x95D3F4-4) == 0) //0x95C3EC EUR
		{
			vu32(*getData1)();
			vu32(*getData2)(u32 param1, u32 param2);
			Process::Write32((u32)&getData1, 0x5204DC); //0x51F524 EUR
			Process::Write32((u32)&getData2, 0x520C98); //0x51FCE0 EUR
			u32 uVar3 = getData1();
			int iVar2 = getData2(uVar3, 2);
			if(iVar2 == 0)
			{
				vu32(*sendData2)();
				Process::Write32((u32)&sendData2, 0x60758C); //0x6065C4 EUR
				(void)sendData2();
			}

			vu32(*sendData3)(u32 param1);
			Process::Write32((u32)&sendData3, 0x618024); //0x61705C EUR
			(void)sendData3(*(u32 *)USA_Game_Pointer);
		}
	}

	void InitKeepConnection(void)
	{
		static Hook onlineThreadHook;
		onlineThreadHook.Initialize(0x12F3A8, (u32)PatchThreadBegin);
		onlineThreadHook.SetFlags(USE_LR_TO_RETURN);
		onlineThreadHook.Enable();
		
		if(Process::IsPaused())
		{
			KeepConnectionInCTRPF(true);
			Keyboard::OnNewFrame(SendPlayerData); //to also send player data while in keyboards
		}
	}
}