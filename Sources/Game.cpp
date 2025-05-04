#include "Game.hpp"

namespace CTRPluginFramework
{
	vu32(*pfunction0)();
	vu32(*pfunction1)(u32 param1);
	vu32(*pfunction2)(u32 param1, u32 param2);
	vu32(*pfunction3)(u32 param1, u32 param2, u32 param3);
	vu32(*pfunction4)(u32 param1, u32 param2, u32 param3, u32 param4);
	vu32(*pfunction5)(u32 param1, u32 param2, u32 param3, u32 param4, u32 param5);
	vu32(*pfunction6)(u32 param1, u32 param2, u32 param3, u32 param4, u32 param5, u32 param6);
	vu32(*pfunction7)(u32 param1, u32 param2, u32 param3, u32 param4, u32 param5, u32 param6, u32 param7);
	vu32(*pfunction8)(u32 param1, u32 param2, u32 param3, u32 param4, u32 param5, u32 param6, u32 param7, u32 param8);
	vu32(*pfunction9)(u32 param1, u32 param2, u32 param3, u32 param4, u32 param5, u32 param6, u32 param7, u32 param8, u32 param9);
	vu32(*pfunction10)(u32 param1, u32 param2, u32 param3, u32 param4, u32 param5, u32 param6, u32 param7, u32 param8, u32 param9, u32 param10);
	vu32(*pfunction11)(u32 param1, u32 param2, u32 param3, u32 param4, u32 param5, u32 param6, u32 param7, u32 param8, u32 param9, u32 param10, u32 param11);

	// Active cheats when the game is launched
	void Game::StartUpCheats(void)
	{
		if(Process::GetTitleID() == 0x0004000000086300)
		{
			//60 fps if drop 30 fps
				Process::Write8(0x20529D58, 1);

			// Online Drop Lag Remover
				Process::Patch(0x5A1454, 0xE1A00000); //create locked spot pkt send 	//0x5A049C EUR
				Process::Patch(0x5A12F4, 0xE1A00000); //clear locked spot pkt send		//0x5A033C EUR
				Process::Patch(0x59FF5C, 0xEA000010); //pkt is from host				//0x59EFA4 EUR
				Process::Patch(0x59FD98, 0xEA000003); //bypass check in 0x59FC7C		//0x59EDE0 EUR
				Process::Patch(0x5983F4, 0xE1A00000); //unnecessary?					//0x59743C EUR
				Process::Patch(0x5984DC, 0xE1A00000); //unnecessary?					//0x597524 EUR
				Process::Patch(0x59F8A0, 0xE1A00000); 									//0x59E8E8 EUR
				Process::Patch(0x5A09B0, 0xEA000022); //item tree drop					//0x59F9F8 EUR
				Process::Patch(0x5A0DF4, 0xEA00002D); //fruit tree drop					//0x59FE3C EUR

			// Drop Related Stuff
				Process::Patch(0x59FCA4, 0xEA000004); //0x59ECEC EUR
				for(u8 i = 0; i <= 0x21; i++)
					Process::Patch(0x5A0F54 + (i * 4), USA_ASM_DropReplaceSwitch);	//0x59FF9C EUR

			// Drop Items Everywhere
				Process::Patch(0x1655EC, 0xE3A00001);								//0x16560C EUR
				Process::Patch(0x1655F8, 0xEA000006);								//0x165618 EUR
				Process::Patch(0x1654EC, 0xEA000005);								//0x16550C EUR
				Process::Patch(0x165580, 0xEA000010); //on other players			//0x1655A0 EUR
		
			// Idle After Tree Shake/Cut
				// Process::Patch(0x660600, 0xE3A01006);	//0x65F638 EUR
				// Process::Patch(0x662328, 0xE3A01006);	//0x661360 EUR
		
			// Prevent Particle Crash
				//Process::Patch(0x5506D4, 0xE3A0C000);								//0x54F71C EUR
				//Process::Patch(0x5509CC, 0xE3A0C000);								//0x54FA14 EUR
				Process::Patch(0x721418, 0xE3A0C000);								//0x720420 EUR
				Process::Patch(0x5A2D20, 0xF3); // Rockbreak Particle				//0x5A1D68 EUR

			// Fix room edit crash online
				Process::Patch(0x6D2B44, 0xE3A0008A); //Menu Change to error
				Process::Patch(0x6708A0, 0xE3A01016); //In-Pocket Animation

			// Santa bag fix
				Process::Write16(0x68D0EC, 0x7FFE);
				Process::Write16(0x689574, 0x7FFE);

			// Prevent others from crashing you
				Process::Patch(0x5980F8, 0xE3A00001); //Disable Sprite Spawn for Anim 0x5F and 0x60
				Process::Patch(0x5A26B4, 0xE1A00000); //Makes Burying spawn toss sprite on the ground
				Process::Patch(0x6517E4, 0xE1A00000); //Another fix for buring items
				Process::Patch(0x651A9C, 0x01000540); //Fixes annoying as heck sound
				Process::Patch(0x665E50, 0xE3A01006); //Replaces Animation for falling into hole after sit, lay down. Prevents you from accidentally crashing others.
				Process::Patch(0x68B57C, 0xE3A01016); //Changes "putinpocket" anim after eat

			// Bypass Checks
				Process::Patch(0x1D43A4, 0xE3A00001);									//0x1D43C4 EUR
				Process::Patch(0x1D43C0, 0xE3A00001);									//0x1D43E0 EUR
				Process::Patch(0x1D43D0, 0xE3A00001);									//0x1D43F0 EUR
				Process::Patch(0x759024, 0xE1A00005);									//0x75802C EUR

			// Check for non seed item
				Process::Patch(0x76A894, 0xE3A00001);									//0x76989C EUR

			// Item to inv after pick up
				Process::Patch(0x323514, 0xE3A00001);									//0x322868 EUR

			// Inventory base
				Process::Write32(0x19C1F0, 0xE1A00000); //Eat							//0x19C210 EUR
				Process::Write32(0x19BA78, 0xE1A00000); //Show off						//0x19BA98 EUR
			
			// Patches NPCs from moving back to their fixed position
				Process::Patch(0x57B9C0, 0xE1A00000);									//0x57AA08 EUR

			// Disable mosquito bites
				Process::Patch(0x5C3B28, 0xE12FFF1E);
				
			// Disable falling down
				Process::Patch(0x665A84, 0x0A000050);

			// Don't fall in pitfalls / holes
				Process::Patch(0x65A668, 0xEA000014);									//0x6596A0 EUR
				Process::Patch(0x6789E4, 0xEA00002D);									//0x677A1C EUR

			// Other players can't push you
				Process::Patch(0x652288, 0xEA00002D);									//0x6512C0 EUR

			// Wear helmet and accesory
				Process::Patch(0x68C630, 0xE1A00000);									//0x68B668 EUR

			// Never bed head
				Process::Patch(0x20C798, 0xE1A00000);

			// More than 3 num on island
				Process::Write8(0xAD7158, 2);											//0xAD6158 EUR

			// Unbreakable flowers
				Process::Patch(USA_NoBreakFlowers_Address, 0xE3A0801D);
		}
	}

	/*
	Player
	*/
	
    Player* Player::m_Instance = nullptr;

	static const u8 m_CoordinateX = 0x14;
	static const u8 m_CoordinateY = 0x18;
	static const u8 m_CoordinateZ = 0x1C;
	static const u8 m_Rotation = 0x2C;	
	static const u8 m_Velocity = 0x40;
	static const u16 m_Animation = 0x1A9;
	static const u16 m_Snake = 0x224;
	static const u16 m_Collision = 0x4F4;
	static const u32 m_SaveGardenPlus = 0x89B00; //0x89B00 is SAVE_GARDENPLUS

	Player::Player()
	{
		Load(); //Set the variables of the class when the instance is created
	}

	// This should never be called as the instance will always be used, but if it is, set the global instance pointer to nullptr
	Player::~Player()
	{
    	m_Instance = nullptr;
	}

	// Wait until a player is loaded
	void Player::Load(void)
	{
		u32 offset, value;
		while(!Process::Read32(USA_Player_Pointer, offset) || !Process::Read32(offset, value))
			Sleep(Milliseconds(20));
	}

	/*
    void Player::GetInstance(void)
    => This function updates the variables of the class.
	=> Used to get the instance of the class, but also create one if there isn't one yet.
	*/
	Player* Player::GetInstance(void)
	{
    	if(m_Instance == nullptr)
        	m_Instance = new Player;

    	return m_Instance;
	}

	// Return current player's index
	u8 Player::GetActualPlayerIndex(void)
	{
		u8 PlayerIndex;
		Process::Read8((*(u32 *)USA_Game_Pointer) + 0x13268, PlayerIndex);
		
		if(PlayerIndex >= 4)
			return 0;
		else
			return PlayerIndex;
	}

	u8 Player::GetOnlinePlayerIndex(void)
	{
		Process::Write32((u32)&pfunction0, USA_OnlinePlayerIndex_Function);
		return pfunction0();
	}

	// Return player offset
	u32 Player::GetOffset(u8 PlayerIndex, bool NoChecks)
	{
		//Process::Read32(USA_PlayerInfo_Pointer + PlayerIndex * 4, PlayerOffset);

		Process::Write32((u32)&pfunction2, USA_PlayerInstance_Function);
		return pfunction2(PlayerIndex, NoChecks);
	}

	bool Player::Exists(u8 PlayerIndex)
	{
		if(Game::GetOnlinePlayerCount() == 0 && PlayerIndex == Player::GetOnlinePlayerIndex())
			return true;
		if(*(u8 *)(0x31FE28ED + PlayerIndex) != 0xA5)
			return true;

		return false;
	}

	bool Player::IsLoaded(u8 PlayerIndex)
	{
		return GetOffset(PlayerIndex) != 0;
	}

	u32 Player::GetAnimationInstance(u32 PlayerInstance, u8 someVal1, u8 someVal2, u32 encVal)
	{
		Process::Write32((u32)&pfunction4, USA_AnimationInstance_Function);
		return pfunction4(PlayerInstance, someVal1, someVal2, encVal);
	}

	PlayerStatus Player::GetPlayerStatus(u8 PlayerIndex)
	{
		Process::Write32((u32)&pfunction1, 0x2FF6CC); //0x2FF754 EUR
		return (PlayerStatus)pfunction1(PlayerIndex);
	}

	u32 Player::GetSpecificSave(u8 PlayerIndex)
	{
		Process::Write32((u32)&pfunction1, 0x2FBA60); //0x2FBAE8 EUR
		return pfunction1(PlayerIndex);
	}

	ACNL_Player *Player::GetSaveData(u8 PlayerIndex)
	{
		u32 *addr = (u32 *)GetSpecificSave(PlayerIndex >= 4 ? (u8)Player::GetPlayerStatus(4) : PlayerIndex);
		return (ACNL_Player *)addr;
	}

	u32 Player::GetSaveOffset(u8 PlayerIndex)
	{
  		vu32(*FUNC)(...);
  		Process::Write32((u32)&FUNC, USA_PlayerSave_Pointer);
  		return FUNC(PlayerIndex);
	}

	bool Player::InLoadingState(void)
	{
		if(IDList::ValidID8(Player::ActualRoom(), 0x27, 0x2A) || IDList::ValidID8(Player::ActualRoom(), 0x5D, 0x66) || IDList::ValidID8(Player::ActualRoom(), 0x80, 0x8D) || IDList::ValidID8(Player::ActualRoom(), 0x98, 0x9C) || IDList::ValidID8(Player::ActualRoom(), 0xA5, 0xFF))
			return true;
		
		switch(ActualRoom())
		{
			case 0x2D:
			case 0x2F:
			case 0x6A:
			case 0x6C:
			case 0x6E:
			case 0x70:
			case 0x72:
			case 0x74:
			case 0x76:
			case 0x78:
			case 0x7A:
			case 0x7C:
			case 0x7E:
				return true;
		}

		//If game is saving
		if(Game::IsSaving())
			return true;

		//If loading screen is active
		bool LoadingScreen = *(bool *)0x94F451; //0x94E451 EUR
		if(LoadingScreen)
			return true;
		
		return false;
	}

	float *Player::GetVelocity(u8 PlayerIndex)
	{
        if(IsLoaded(PlayerIndex))
			return (float *)(GetOffset(PlayerIndex) + m_Velocity);
		
		return nullptr;
    }

	u8 *Player::GetAnimation(u8 PlayerIndex) 
    {
		if(IsLoaded(PlayerIndex))
			return (u8 *)(GetOffset(PlayerIndex) + m_Animation);
		
        return nullptr;
    }

	u16 *Player::GetSnake(u8 PlayerIndex)
	{
		if(IsLoaded(PlayerIndex))
			return (u16 *)(GetOffset(PlayerIndex) + m_Snake);
		
		return nullptr;
	}

	u8 Player::ActualRoom(u8 PlayerIndex)
	{
		Process::Write32((u32)&pfunction1, USA_Room_Function);
		u32 room = pfunction1(PlayerIndex);
		return room == 0 ? 0xFF : *(u8 *)room;
	}

	bool Player::IsIndoor()
	{
		Process::Write32((u32)&pfunction0, USA_Location_Pointer);
		return (bool)pfunction0();
	}

	bool Player::IsInRoom(u8 Room, u8 PlayerIndex, bool NotLoaded)
	{
		if(NotLoaded && PlayerIndex == Player::GetActualPlayerIndex() && *(u8 *)USA_ActualRoom_Address == Room)
			return true;
		else if(Player::ActualRoom(PlayerIndex) == Room)
			return true;
		else
			return false;
	}

	bool Player::IsOnTour(u8 PlayerIndex)
	{
		switch(Player::ActualRoom(PlayerIndex)) 
		{
			case 0x69:
			case 0x6B:
			case 0x6D:
			case 0x6F:
			case 0x71:
			case 0x73:
			case 0x75:
			case 0x77:
			case 0x79:
			case 0x7B:
			case 0x7D:
			case 0x7F:
				return true;
		}
	
		return false;
	}

	// Get next loaded room ID
	u8 Player::NextRoomCheck()
	{
		Process::Write32((u32)&pfunction0, 0x5B4C08); //0x5B3C50 EUR
		return pfunction0();
	}

	bool Player::CanWarp(u8 Room)
	{
		if(!IDList::RoomValid(Room & 0xFF))
			return false;

		if(Player::InLoadingState())
			return false;

		//if(Game::GetOnlinePlayerCount() != 0)
			//return false;

		return true;
	}

	bool Player::GetWorldCoords(u32 *wX, u32 *wY, u8 PlayerIndex, bool NoChecks)
	{
		if(IsLoaded(PlayerIndex))
		{
			Process::Write32((u32)&pfunction4, USA_WorldCoordinates_Function);
			return pfunction4((u32)wX, (u32)wY, PlayerIndex, NoChecks);
		}
		return false;
	}

	Coordinates Player::GetStructCoordinates(u8 PlayerIndex)
	{
        if(IsLoaded(PlayerIndex))
			return (*(reinterpret_cast<Coordinates *>(GetOffset(PlayerIndex) + m_CoordinateX)));
		
		// Else return a zero filled struct
        Coordinates zero = { 0.f, 0.f, 0.f };
        return (zero);
    }

	void Player::SetStructCoordinates(Coordinates pos, u8 PlayerIndex)
    {
        if(IsLoaded(PlayerIndex))
            *(reinterpret_cast<Coordinates *>(GetOffset(PlayerIndex) + m_CoordinateX)) = pos;
    }

	float *Player::GetCoordinates(u8 PlayerIndex)
	{
        if(IsLoaded(PlayerIndex))
			return (float *)(GetOffset(PlayerIndex) + m_CoordinateX);
		
		return nullptr;
    }

	bool Player::GetCoordinatesRef(float &X, float &Z, u8 PlayerIndex)
	{
		if(IsLoaded(PlayerIndex))
		{
			u32 PlayerOffset = GetOffset(PlayerIndex);
			PlayerOffset += 0x14;
			X = *(volatile float *)PlayerOffset;
			Z = *(volatile float *)(PlayerOffset + 8);
			return true;
		}
		else
			return false;
	}

	void Player::SetCoordinatesX(float x, u8 PlayerIndex)
    {
        if(!IsLoaded(PlayerIndex))
            return;

        reinterpret_cast<Coordinates *>(GetOffset(PlayerIndex) + m_CoordinateX)->x = x;
    }

    void Player::SetCoordinatesY(float y, u8 PlayerIndex)
    {
        if(!IsLoaded(PlayerIndex))
            return;

        reinterpret_cast<Coordinates *>(GetOffset(PlayerIndex) + m_CoordinateX)->y = y;
    }

    void Player::SetCoordinatesZ(float z, u8 PlayerIndex)
    {
        if(!IsLoaded(PlayerIndex))
            return;

        reinterpret_cast<Coordinates *>(GetOffset(PlayerIndex) + m_CoordinateX)->z = z;
    }

    void Player::AddToCoordinates(float xDiff, float yDiff, float zDiff, u8 PlayerIndex)
    {
        if(!IsLoaded(PlayerIndex))
            return;

        Coordinates *coord = reinterpret_cast<Coordinates *>(GetOffset(PlayerIndex) + m_CoordinateX);
        
        coord->x += xDiff;
        coord->y += yDiff;
        coord->z += zDiff;
    }

	u8 Player::GetCurrentInventory()
	{
		u32 BaseInventory = *(u32 *)USA_BaseInventory_Pointer;
		if(BaseInventory == 0) 
			return 0xFF;
		
		return *(u8 *)(*(u32 *)(BaseInventory + 0xC) + 0x24);
	}

	u32 Player::ReadInventory(u8 Slot)
	{
		u32 ID;
		Process::Read32((GetSaveOffset() + 0x6BD0) + (Slot * 4), ID);
		return ID;
	}

	void Player::WriteInventory(u8 Slot, u32 ID)
	{
		Process::Write32((GetSaveOffset() + 0x6BD0) + (Slot * 4), ID);
		Process::Write32((GetSaveOffset() + 0x6C10) + Slot, 0);
	}

	/*void Player::ReloadInvIcons() 
	{
	//if inv is not loaded return
		if(Game::BaseInvPointer() == 0) 
			return;
		
	//If inv is not opened return
		if(!Opened())
			return;

		for(int i = 0; i < 16; ++i)
			Code::LoadIcon.Call<void>(*(u32 *)(Game::BaseInvPointer() + 0xC) + GetAddData(), i);
	}*/

	void Player::UpdateStyle(void)
	{
		Process::Write32((u32)&pfunction1, 0x68B2E4); //0x68A31C EUR
		(void)pfunction1(GetOffset());
	}

	void Player::UpdateTan(void)
	{
		ACNL_Player *PlayerSave = Player::GetSaveData();
		if(!PlayerSave)
			return;
		
		u32 GetStoredData = GetOffset() + 0x1B4; //0x33077570
		//This Stores the Tan Data Correctly
		
		vu32(*TanFunc)(Player_Features* param1);
		Process::Write32((u32)&TanFunc, 0x713798); //0x7127A0 EUR
		u8 Tan = TanFunc(&PlayerSave->PlayerFeatures);
		
		Process::Write8(GetStoredData + 0x1C0, Tan);
		
		//This Updates the Tan
		Process::Write32((u32)&pfunction1, 0x1D0B90); //0x1D0BB0 EUR
		(void)pfunction1(GetStoredData);
	}

	void Player::UpdateGender(u8 Gender)
	{
		ACNL_Player *PlayerSave = Player::GetSaveData();
		if(!PlayerSave)
			return;

		Process::Write32((u32)&pfunction0, USA_GardenPlus_Pointer);
		u32 GardenPlus = pfunction0();

		PlayerID oldPlayerID = PlayerSave->PlayerInfo.PlayerData;
		PlayerSave->PlayerInfo.PlayerData.Gender = Gender;
		PlayerID newPlayerID = PlayerSave->PlayerInfo.PlayerData;

		for(u32 addr = GardenPlus; addr < (GardenPlus + m_SaveGardenPlus); addr++)
		{
			if(*(PlayerID *)addr == oldPlayerID)
			{
				*(PlayerID *)addr = newPlayerID;
			}
		}
	}

	void Player::SetOutfit(u16 Out1, u16 Out2, u16 Out3, u16 Out4, u16 Out5, u16 Out6)
	{
		u32 x, y;
		if(Player::GetWorldCoords(&x, &y, Player::GetOnlinePlayerIndex() & 3))
		{
		    if(Out1 != 0xFFFF && Out1 != 0) Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0x36, Out1, 0, 0, 1, 0, x, y, false, 0); //Hat
		    if(Out2 != 0xFFFF && Out2 != 0) Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0x36, Out2, 1, 1, 1, 0, x, y, false, 0); //Accessory
		    if(Out3 != 0xFFFF && Out3 != 0) Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0x36, Out3, 2, 2, 1, 0, x, y, false, 0); //TopWear
		    if(Out4 != 0xFFFF && Out4 != 0) Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0x36, Out4, 4, 4, 1, 0, x, y, false, 0); //BottomWear
		    if(Out5 != 0xFFFF && Out5 != 0) Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0x36, Out5, 5, 5, 1, 0, x, y, false, 0); //Socks
		    if(Out6 != 0xFFFF && Out6 != 0) Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0x36, Out6, 6, 6, 1, 0, x, y, false, 0); //Shoes
			Sleep(Milliseconds(550));
			Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 6, 0, 0, 0, 0, 0, x, y, false, 0);
		}
	}

	u64 Player::GetFriendCode(u8 PlayerIndex)
	{
		u32 GamePointer = *(u32 *)USA_Game_Pointer;
		if(GamePointer == 0)
			return 0;

		frdInit();

		u32 pID = *(u32 *)((GamePointer + 0xC0) + (0x18 * PlayerIndex));

		if((int)pID == -3)
			return 0;
			
		u64 FriendCode = 0;
		FRD_PrincipalIdToFriendCode(pID, &FriendCode);

		frdExit();

		return FriendCode;
	}

	bool Game::IsSaving()
	{
		Process::Write32((u32)&pfunction0, 0x126568); //0x12658C EUR
		return (bool)pfunction0();
	}

	bool Game::MapBool()
	{
		return *(bool *)USA_MapBool_Address;
	}

	void Game::RoomWarp(u8 Room)
	{
		Process::Write32((u32)&pfunction4, USA_Loading_Function);
		pfunction4(Room, 1, 1, 0);
	}

	void Game::ReloadRoom(float *coords)
	{
		vu32(*ReloadRoomFunction)(u32 param1, u32 param2, float* param3, u32* param4, u32 param5, u32 param6, u32 param7, u32 param8, u32 param9);

		u32 u0Data = 0x976C0E; //0x975C06 EUR
		Process::Write32((u32)&ReloadRoomFunction, 0x5B6660); //0x5B56A8 EUR
		ReloadRoomFunction(Game::GetRoomData(), Player::ActualRoom(), coords, (u32 *)u0Data, 6, 0, 0, 1, 1);
	}

	void Game::AskReloadRoom(void)
	{
		extern bool WantReload;
		extern bool TimeMachineBool;

		if(WantReload || TimeMachineBool)
			return;

		Sleep(Milliseconds(20));
		if(MessageBox("Do you want to reload room?", DialogType::DialogYesNo)())
		{
			WantReload = true;
			Game::ReloadRoom();
		}
	}
	
	//Get Room Reload Data
	u32 Game::GetRoomData()
	{
		Process::Write32((u32)&pfunction0, 0x308154); //0x3081F4 EUR
		return pfunction0();
	}

	float *Game::WorldCoordsToCoords(u8 wX, u8 wY, float res[3])
	{
		volatile float *coords = Player::GetCoordinates();
		if(coords != nullptr)
			res[1] = *(volatile float *)((u32)coords + 4);
		res[0] = (float)(wX * 0x20 + 0x10);
		res[2] = (float)(wY * 0x20 + 0x10);
		return &res[0];
	}

	// Get amount of online players 
	u8 Game::GetOnlinePlayerCount()
	{
		Process::Write32((u32)&pfunction1, USA_OnlinePlayerCount_Function);
		return pfunction1(*(u32 *)USA_Game_Pointer);
	}

	StringVector Game::GetOnlinePlayerList()
	{	
		StringVector PlayersList;
		StringVector PresetPlayersList =
		{
			Color::Blue << "Player 1 - Blue",
			Color::Red << "Player 2 - Red",
			Color::Green << "Player 3 - Green",
			Color::Yellow << "Player 4 - Yellow",
		};

		for(u8 i = 0; i < GetOnlinePlayerCount(); i++) // Create a list with all avaliable online players
		{
			if(Player::GetOffset(i) == 0x330773BC || Player::GetOffset(i) == 0x330774E8) // If readed offset is yours
			{
				PlayersList.push_back(PresetPlayersList[i] + " (You)");
			}
			else
			{
				PlayersList.push_back(PresetPlayersList[i]);
			}
		}
		return PlayersList;
	}

	bool Game::OnOnlineIsland()
	{
		if(Player::GetOffset() == 0x330774E8)
			return true;
		else
			return false;
	}

	u32 Game::GetCurrentMap()
	{
		Process::Write32((u32)&pfunction0, 0x6A690C); //0x6A5944 EUR
		return pfunction0();
	}

	u32 Game::GetMapItemsCount(bool Include7FFE, u8 WorldX, u8 WorldY, u8 Width, u8 Length)
	{
		if(Include7FFE)
			return (u32)Game::GetMapItems(true, WorldX, WorldY, Width, Length).size();
		else
			return (u32)Game::GetMapItems(false, WorldX, WorldY, Width, Length).size();
	}

	u32Vector Game::GetMapItems(bool Include7FFE, u8 WorldX, u8 WorldY, u8 Width, u8 Length)
	{
		u32Vector Items;

		u8 X = WorldX, Y = WorldY;

		if(!Player::IsIndoor())
		{
			X = 0x10;
			Y = 0x10;
		}
		else
		{
			X = 0;
			Y = 0;
		}

		while(X - WorldX < Width)
		{
			while(Y - WorldY < Length)
			{
				if(Include7FFE)
				{
					if((u32)Items::GetItemAtWorldCoords(X, Y))
						Items.push_back(*Items::GetItemAtWorldCoords(X, Y));
				}
				else
				{
					if((u32)Items::GetItemAtWorldCoords(X, Y))
						if(*Items::GetItemAtWorldCoords(X, Y) != 0x7FFE)
							Items.push_back(*Items::GetItemAtWorldCoords(X, Y));
				}
				Y++;
			}

			if(!Player::IsIndoor())
				Y = 0x10;
			else
				Y = 0;
			X++;
		}

		return Items;
	}

	void Game::AppendCoordData(u32 AnimInst, u32 pos, float* Coords)
	{
		Process::Write32((u32)&pfunction2, 0x5D4C88); //0x5D3CD0 EUR
		pfunction2(AnimInst + pos, *Coords);
    }

	//Spawn Particles
	void Game::Particles(u32 ParticleID, float *wCoords, u32 u0, u32 u1)
	{
		if(wCoords == nullptr) 
			return;

		Process::Write32((u32)&pfunction4, USA_Particles_Function);
		pfunction4(ParticleID, (u32)wCoords, u0, u1);
	}

	void Game::OpenMenu(u8 MenuID, bool NoMenuCall)
	{
		Process::Write32((u32)&pfunction1, 0x5C5398); // Open menu //0x5C43E0 EUR
		pfunction1(1);

		if(NoMenuCall)
			return;
		
		Process::Write32((u32)&pfunction3, 0x6D3F8C); // Open catalog //0x6D2FC4 EUR
		pfunction3(MenuID, 0, 0);;
    }

	void Game::OpenCatalog()
	{
		Game::OpenMenu(0, true);
		Process::Write32((u32)&pfunction1, 0x6D33D8); // Open catalog //0x6D2410 EUR
		pfunction1(0);
    }

	void Game::GiveItemFunction(u32 InvData)
	{
		u32 ArgData = 0x8499E4; //0x848870 EUR

		Process::Write32((u32)&pfunction3, 0x81825C); //0x817264 EUR
		pfunction3(InvData, *(u32 *)ArgData, *(u32 *)(ArgData + 4));
    }

	TownSaveData *Game::GetTownSaveData(void)
	{
		Process::Write32((u32)&pfunction0, USA_GardenPlus_Pointer);
		u32 *addr = (u32 *)(pfunction0() + 0x53424);
		return (TownSaveData *)addr;
	}

	void Game::PlaceBuildingUpdateCollisions(u32 x, u32 y, u16 BuildingID)
	{
		Process::Write32((u32)&pfunction3, 0x2425D8); //0x2425D4 EUR
		pfunction3(x, y, BuildingID);
	}

	void	OnBuildingChange(Keyboard &k, KeyboardEvent &e) 
	{
		u32 TargetBuilding;
		u8 MaxBuildings = 0;

		for(u8 i = 0; i < 56; i++) // 56 = Max building slots
		{
			TargetBuilding = USA_Building_Address + (i * 4);
			if(*(u8 *)(TargetBuilding) < 0xFC) // If isn't an empty slot
				MaxBuildings++;
		}
		
		u32 x, y;	
		Player::GetWorldCoords(&x, &y);
		std::string& s = k.GetInput();
		k.GetMessage() = "Type the ID of the building you want." << Color::Lime << "\nHex: 0~FB " << Color::White << "|" << Color::Magenta << Utils::Format(" Actual world coords: x%02Xy%02X\nBuildings: %d/56", x, y, MaxBuildings) << Color::DeepSkyBlue << "\n\nPlacing: " << IDList::GetBuildingName(s != "" ? std::stoi(s, nullptr, 16) : 0);
	}

	void Game::PlaceBuilding()
	{
		if(!(Player::IsInRoom(0) || Player::IsInRoom(0x68)))
		{
			MessageBox(Color::Red << "Error", Color::White << "You cannot place building in this map.")();
			return;
		}

		u8 ID;
		u32 x, y;	
		Player::GetWorldCoords(&x, &y);

		u32 TargetBuilding;
		u8 MaxBuildings = 0;

		for(u8 i = 0; i < 56; i++) // 56 = Max building slots
		{
			TargetBuilding = USA_Building_Address + (i * 4);
			if(*(u8 *)(TargetBuilding) < 0xFC) // If isn't an empty slot
				MaxBuildings++;
		}

		if(MaxBuildings >= 56)
		{
			MessageBox(Color::Red << "Error", Color::White << "You have reached the max buildings possible.")();
			return;
		}

		redo:
		if(!SetUpKBNo("Type the ID of the building you want." << Color::Lime << "\nHex: 0~FB " << Color::White << "|" << Color::Magenta << Utils::Format(" Actual world coords: x%02Xy%02X\nBuildings: %d/56", x, y, MaxBuildings), true, 2, ID, OnBuildingChange))
			return;

		if(!IDList::BuildingValid(ID))
		{
			MessageBox(Color::Red << "Error", Color::White << "Invalid building ID.")();
			goto redo;
		}

		ID &= 0xFFFF;
		Game::PlaceBuildingUpdateCollisions(x, y, ID);

		OSD::Notify("Building:" << Color::Lime << Utils::Format("%02X", ID));

		Player::AddToCoordinates(0.f, 0.f, 40);
		Game::AskReloadRoom();
	}

	void Game::MoveBuilding()
	{
		if(!Player::IsInRoom(0))
		{
			MessageBox(Color::Red << "Error", Color::White << "You cannot move building in this map.")();
			return;
		}

		u32 x, y;
		Player::GetWorldCoords(&x, &y);
		
		u32 TargetBuilding;
		u8 MaxBuildings = 0;

		u8Vector index;
		StringVector BuildingList;
		BuildingList.clear();

		for(u8 i = 0; i < 56; i++) // 56 = Max building slots
		{
			TargetBuilding = USA_Building_Address + (i * 4);
			if(*(u8 *)(TargetBuilding) < 0xFC) // If isn't an empty slot
			{
				// Add all avaliable buildings to a list
				MaxBuildings++;
				index.push_back(i);
				BuildingList.push_back(IDList::GetBuildingName(*(u8 *)(TargetBuilding)) << Color::White << "|" << Color::Lime << "x" << Hex(*(u8 *)(TargetBuilding + 2)) << "y" << Hex(*(u8 *)(TargetBuilding + 3)));
			}
		}

		Keyboard BuildingKb("Choose a building:" << Color::Magenta << Utils::Format("\nActual world coords: x%02Xy%02X\nBuildings: %d/56", x, y, MaxBuildings));

		Sleep(Milliseconds(80));
		
		BuildingKb.Populate(BuildingList);
		s8 val = BuildingKb.Open();
		if(val < 0) 
			return;

		Process::Write8(USA_Building_Address + index.at(val) * 4 + 2, x & 0xFF);
		Process::Write8(USA_Building_Address + index.at(val) * 4 + 3, y & 0xFF);

		Game::AskReloadRoom();
	}

	void Game::RemoveBuilding()
	{
		if(!Player::IsInRoom(0))
		{
			MessageBox(Color::Red << "Error", Color::White << "You cannot move building in this map.")();
			return;
		}
		
		u32 x, y;
		Player::GetWorldCoords(&x, &y);
		
		u32 TargetBuilding;
		u8 MaxBuildings = 0;

		u8Vector index;
		StringVector BuildingList;
		BuildingList.clear();

		for(u8 i = 0; i < 56; i++) // 56 = Max building slots
		{
			TargetBuilding = USA_Building_Address + (i * 4);
			if(*(u8 *)(TargetBuilding) < 0xFC) // If isn't an empty slot
			{
				// Add all avaliable buildings to a list
				MaxBuildings++;
				index.push_back(i);
				BuildingList.push_back(IDList::GetBuildingName(*(u8 *)(TargetBuilding)) << Color::White << "|" << Color::Lime << "x" << Hex(*(u8 *)(TargetBuilding + 2)) << "y" << Hex(*(u8 *)(TargetBuilding + 3)));
			}
		}

		Keyboard BuildingKb("Choose a building:" << Color::Magenta << Utils::Format("\nActual world coords: x%02Xy%02X\nBuildings: %d/56", x, y, MaxBuildings));

		Sleep(Milliseconds(80));
		
		BuildingKb.Populate(BuildingList);
		int val = BuildingKb.Open();
		if(val < 0) 
			return;
		
		if(!IDList::BuildingValid(USA_Building_Address + index.at(val) * 4))
		{
			MessageBox(Color::Red << "Error", Color::White << "You cannot remove that building!")();
			return;
		}

		Process::Write32(USA_Building_Address + index.at(val) * 4, 0xFC);
		*(u8 *)(USA_Building_Address - 4) = *(u8 *)(USA_Building_Address - 4) - 1;

		Game::AskReloadRoom();
	}

	u64 Game::EncryptACNLMoney(int dec)
    {
        // Make a new RNG
        u16 adjust = Utils::Random(0, 0x10000);
        u8  shift_val = Utils::Random(0, 0x1A);

        // Encipher value
        u32 enc = dec + adjust + 0x8F187432;
        enc = (enc >> (0x1C - shift_val)) + (enc << (shift_val + 4));

        // Calculate Checksum
        u8  chk = (((enc >> 0) + (enc >> 8) + (enc >> 16) + (enc >> 24) + 0xBA) & 0xFF);

        // Pack result
        return ((u64)enc << 0) | ((u64)adjust << 32) | ((u64)shift_val << 48) | ((u64)chk << 56);
    }

	u32 Items::PlaceItem(u8 ID, u32 *ItemToReplace, u32 *ItemToPlace, u32 *ItemToShow, u8 worldX, u8 worldY, bool u0, bool u1, bool u2, bool u3, bool u4)
	{
		Process::Write32((u32)&pfunction11, USA_Drop_Function);
		return pfunction11(ID, (u32)ItemToReplace, (u32)ItemToPlace, (u32)ItemToShow, worldX, worldY, u0, u1, u2, u3, u4);
	}

	bool Items::DropCheck(u32 *wX, u32 *wY, u32 *u0, bool disallowConcrete, bool u1)
	{
		Process::Write32((u32)&pfunction5, USA_DropCheck_Function);
		return (bool)pfunction5((u32)wX, (u32)wY, (u32)u0, disallowConcrete, u1);
	}

	//Drop Item Wrapper
	bool Items::PlaceItemWrapper(u8 ID, u32 ItemToReplace, u32 *ItemToPlace, u32 *ItemToShow, u8 worldX, u8 worldY, bool u0, bool u1, bool u2, bool u3, bool u4, u8 WaitAnim, u8 RoomID, bool itemsequenceallowed)
	{
		if(Player::InLoadingState())
			return false;

		if(!IDList::ItemValid(*ItemToPlace))
		{
			Process::Patch(USA_Drop_Function + 0x64, 0xE59D1028);
			return false;
		}

		//sets WaitAnim as autoWaitAnim
		u8 AutoWaitAnim = WaitAnim;
		
		if(ID == 0xB || ID == 0x13)
		{
			if(Player::IsIndoor())
			{
				ID = 0xA;
				AutoWaitAnim = 0x53;
			}
		}

		//Enable dropper
		Process::Patch(0x839A00, 0xE59F1004);
        Process::Patch(0x839A04, 0xE12FFF1E);
        Process::Write32(0x839A0C, 0x9E0020);

		//If item sequence is enabled use next item if not use standard ItemToPlace
		//Item *ActualItemToPlace = (ItemSequence::Enabled() && itemsequenceallowed) ? ItemSequence::Next() : ItemToPlace;
		u32 *ActualItemToPlace = ItemToPlace;
		
		//If item sequence is enabled use ActualItemToPlace as the item to show, if not use standard ItemToShow
		//Item *ActualItemToShow = (ItemSequence::Enabled() && itemsequenceallowed) ? ActualItemToPlace : ItemToShow;
		u32 *ActualItemToShow = ItemToShow;

		//gets current player index -> player you selected
		u8 CurrentIndex = Player::GetOnlinePlayerIndex();
		
		//checks if the drop is forced on someone else
		bool forced = (CurrentIndex != Player::GetActualPlayerIndex()) && (Player::GetActualPlayerIndex() <= 3);
		
		//not too sure when it is not 0xFFFFFFFF but if it is return
		if(Items::GetLockedSpotIndex(worldX, worldY, RoomID) != 0xFFFFFFFF)
			return false;
		
		//checks if item at coords is not 0 -> if place is valid to drop
		u32 *ActualItemAtCoords = Items::GetItemAtWorldCoords(worldX, worldY);
		if(ActualItemAtCoords == nullptr)
			return false;

		//writes the item to replace, if 0xFFFFFFFF is selected as item it will replace item at coords, if not use standard ItemToReplace
		u32 *ActualItemToReplace = (ItemToReplace == 0xFFFFFFFF ? ActualItemAtCoords : &ItemToReplace);

		//if item to replace is not item at coords return -> means there wont be an item to replace
		if(*ActualItemToReplace != *ActualItemAtCoords && !(*ActualItemToReplace == 0x7FFE && *ActualItemAtCoords == 0x80007FFE))
			return false;

		if(!Player::IsIndoor() && (*ActualItemToPlace == 0x207A || *ActualItemToPlace == 0x2079))
			return false;
		if(Player::IsIndoor() && (*ActualItemToPlace <= 0xFF || (*ActualItemToPlace & 0x80000000) != 0 || ID == 8 || ID == 9 || ID == 0xE || ID == 0xF))
			return false;

		if(ID == 9 || ID == 0xF) *ActualItemToReplace = 0x26;
		if(ID == 8 || ID == 0xE) *ActualItemToReplace = 0x3E;
		if(ID == 3 || ID == 4 || ID == 5) *ActualItemToReplace = 0x2001;

		u32 CrashPreventItem = (Player::IsIndoor() ? 0x2001 : 0x80007FFE);

		u32 *ItemReplace = (*ActualItemToReplace == 0x7FFE ? &CrashPreventItem : ActualItemToReplace);
		u32 *ItemPlace = (*ActualItemToPlace == 0x7FFE && ID != 0x1C && !(ID >= 0x6 && ID <= 0x9) && ID != 0xE && ID != 0xF ? &CrashPreventItem : ActualItemToPlace);
		u32 *ItemShow =  (*ActualItemToShow == 0x7FFE && ID != 0x1C && !(ID >= 0x6 && ID <= 0x9) && ID != 0xE && ID != 0xF ? &CrashPreventItem : ActualItemToShow);

		if(*ItemPlace == 0 || *ItemPlace == 0x7FFE || *ItemPlace == 0x80007FFE)
			*ItemPlace = CrashPreventItem;
		if(*ItemShow == 0 || *ItemShow == 0x7FFE || *ItemShow == 0x80007FFE)
			*ItemShow = CrashPreventItem;

		Process::Patch(USA_Drop_Function + 0x64, *ItemPlace == CrashPreventItem ? 0xE59D1028 : 0xEB0A6746);
		Process::Write32(USA_DropSeeder_Address, *ItemPlace);

		//place item function
		Items::PlaceItem(ID == 0x21 ? 0xF : ID, ItemReplace, ItemPlace, ItemShow, worldX, worldY, u0, u1, ID == 0x8 || ID == 0xE ? 1 : 0, u3, u4);

		if(!(ID >= 0xA && ID <= 0xD) && ID != 0x22)
		{
			bool noWait = false;
			
			//gets player data
			u32 PlayerInstance = Player::GetOffset();
			
			//gets animation data
			u32 AnimInstance = Player::GetAnimationInstance(PlayerInstance, 0, 0, 0);

			//AnimData data;
			//data.Init(AnimInstance, player, CurrentIndex);

			Process::Write32(PlayerInstance + 0x844, 0);
			Process::Write8(PlayerInstance + 0x8CC, ID);

			//animation patch
			static u32 AnimPatch = 0x682434; //0x68146C EUR

			//display pattern, smash rock, bury
			if(WaitAnim == 0x5D || WaitAnim == 0x6B || WaitAnim == 0x4F || WaitAnim == 0x4C || WaitAnim == 0x50 || WaitAnim == 0x52 || WaitAnim == 0x5A || WaitAnim == 0x5F || WaitAnim == 0x60 || WaitAnim == 0x61 || WaitAnim == 0x7E || WaitAnim == 0x87 || WaitAnim == 0xAC)
				noWait = true;
			
			//if pick or pluck
			if(WaitAnim == 0x3D || WaitAnim == 0x40 || WaitAnim == 0x41)
			{
				noWait = true;
				goto noWaitPick;
			}
			
			//if pick or pluck
			if(ID >= 1 && ID <= 6 && !noWait)
			{
				if(forced)
				{
					switch(ID)
					{
						case 1:
						case 2:
							AutoWaitAnim = 0x3D;
							break;
						case 3:
						case 4:
						case 5:
							AutoWaitAnim = 0x41;
							break;
						case 6:
							AutoWaitAnim = 0x40;
							break;
					}
				}
				else 
					AutoWaitAnim = 0x3C;
			
				//write coords and item and ID to animation
				noWaitPick:
				Process::Write32(AnimInstance + 0xE, *(u32 *)ActualItemToReplace);
        		Process::Write8(AnimInstance + 0x12, ID == 0x21 ? *(u8 *)(PlayerInstance + 0x47C) : worldX);
        		Process::Write8(AnimInstance + 0x13, ID == 0x21 ? *(u8 *)(PlayerInstance + 0x480) : worldY);
        		Process::Write8(AnimInstance + 0x15, ID);
        		Game::AppendCoordData(AnimInstance, 0x17, Player::GetCoordinates(CurrentIndex));
			}
			else
			{
				//write coords and item to animation
				Process::Write8(AnimInstance + 0xE, ID == 0x21 ? *(u8 *)(PlayerInstance + 0x47C) : worldX);
				Process::Write8(AnimInstance + 0xF, ID == 0x21 ? *(u8 *)(PlayerInstance + 0x480) : worldY);
				Process::Write16(AnimInstance + 0x10, *(u16 *)ActualItemToReplace == 0x7FFE ? 0x2001 : *(u16 *)ActualItemToReplace);

				if(WaitAnim == 0x60 || WaitAnim == 0x61)
				{
					volatile float *pCoords = Player::GetCoordinates();
					if (pCoords != nullptr)
					{
						*pCoords = worldX * 0x20 + 0x10;
						*((float *)((vu32)pCoords + 8)) = worldY * 0x20 + 0x10;
					}
				}
				
				if(ID == 0x7 && !noWait && WaitAnim != 0x5C && WaitAnim != 0x6A)
					AutoWaitAnim = forced ? 0x5D : 0x5C;
				else if(ID >= 0x8 && ID <= 0xF && !noWait && WaitAnim != 0x6A)
					AutoWaitAnim = forced ? 0x6B : 0x6A;
				else if(forced && !noWait)
					AutoWaitAnim = 0x4C;
				
				//if bury animation
				if(((ID >= 0x13 && ID <= 0x1C) || AutoWaitAnim == 0x4A) && !noWait && !forced)
				{
					AutoWaitAnim = 0x4A;
					Process::Write32(AnimPatch, 0xE3A00000);
					Process::Write16(AnimInstance + 0x10, ID);
					Sleep(Milliseconds(5));
				}
				//if forced with noWait true
				else if(forced) 
					AutoWaitAnim = 0x4F;
			}
			
			//if selected index is the same as your player
			if(CurrentIndex == Player::GetActualPlayerIndex()) 
				Animation::ExecuteAnimation(PlayerInstance, AutoWaitAnim, AnimInstance);
			//if not aka another player
			else 
				Animation::SendPacket(Player::GetActualPlayerIndex(), AnimInstance, AutoWaitAnim, RoomID == 0xA5 ? Player::ActualRoom(CurrentIndex) : RoomID, CurrentIndex);	
			
			//sleep if noWait is turned off
			if(!noWait)
			{
				Sleep(Milliseconds(40));
				Process::Write32(AnimPatch, 0xE3700001);
			}
		}
		return true;
	}

	void Items::TrampleAt(u8 worldX, u8 worldY)
	{		
		u32 *pItem = Items::GetItemAtWorldCoords(worldX, worldY);
		
		if(!pItem) 
			return;
		
		u8 Room = Player::ActualRoom(Player::GetActualPlayerIndex());
		if(Game::GetOnlinePlayerCount() != 0)
		{
			TramplePkt data { *pItem, Room, worldX, worldY, 0 };

			Process::Write32((u32)&pfunction4, 0x625488); //0x6244C0 EUR
			pfunction4(0x47, 4, (u32)&data, 8);
		}
		
		Process::Write32((u32)&pfunction5, 0x168E20); //0x168E40 EUR
		pfunction5(worldX, worldY, 0, Room, 0x95CFFC);

		Process::Write32((u32)&pfunction3, 0x59F144); //0x59E18C EUR
		pfunction3(worldX, worldY, 1);
	}

	u32 *Items::GetItemAtWorldCoords(u32 x, u32 y, bool u0)
	{
		Process::Write32((u32)&pfunction4, 0x2FEF9C); //0x2FEF0C EUR
		return (u32 *)pfunction4(Game::GetCurrentMap(), x, y, u0);
	}

	u32 Items::GetLockedSpotIndex(u8 wX, u8 wY, u8 RoomID)
	{
		Process::Write32((u32)&pfunction3, 0x5A11BC); //0x5A0204 EUR
		return pfunction3(wX, wY, RoomID);
	}

	void Items::ClearLockedSpot(u8 wX, u8 wY, u8 RoomID, u32 param_4)
	{
		Process::Write32((u32)&pfunction4, USA_ClearLockedSpot_Function);
		pfunction4(wX, wY, RoomID, param_4);
	}

	Item_Categories Items::GetItemCategorie(u32 itemID)
	{
		Process::Write32((u32)&pfunction1, 0x2FCBC4); //0x2FCC4C EUR
		return (Item_Categories)pfunction1(itemID);
	}

	bool Animation::ExecuteAnimation(u32 PlayerInst, u8 AnimID, u32 AnimInst)
	{
		Process::Write32((u32)&pfunction4, USA_Animation_Function);
		return pfunction4(PlayerInst, AnimID, AnimInst, 0);
	}

	bool Animation::ExecuteAnimationWrapper(u8 PlayerIndex, u8 AnimID, u32 AnimItem, u8 EmotionID, u16 SnakeID, u16 SoundID, bool u0, u8 wX, u8 wY, bool directSend, u8 Appearance[])
	{	
	//Gets actual PlayerIndex
		u8 ActualIndex = Player::GetActualPlayerIndex();
		
	//If PlayerIndex is not the same as yours
		bool forced = (PlayerIndex != ActualIndex) && (ActualIndex <= 3);
	//This gets used if the player you want to force is not the player you selected
		bool needOverwrite = (Player::GetOnlinePlayerIndex() != PlayerIndex);
		
	//Gets Player Instance
		u32 PlayerInstance = Player::GetOffset(PlayerIndex);
		
	//If selected player is not loaded return false
		if(!Player::IsLoaded(PlayerIndex))
			return false;
		
	//Gets Animation Instance to append anim data
		u32 AnimInstance = Player::GetAnimationInstance(PlayerInstance, 0, 0, 0);
		
	//If animation instance returns 0, probably means animation can't be executed
		if(AnimInstance == 0) 
			return false;

		//AnimData data;
		//data.Init(AnimInstance, PlayerInstance, PlayerIndex);
		
	//Gets used to write the coordinates of the animation
		float coords[3];
		Process::Write32((u32)&pfunction2, 0x5D4C88);
		pfunction2(AnimInstance + 2, (u32)Game::WorldCoordsToCoords(wX, wY, coords));
		
	//Knock Door patch
		u32 Knock = 0x655400; //0x654438 EUR
		
	//sets animation data for each animation correctly	
		switch(AnimID)
		{
		//item anims
			case 0x24:
			case 0x38:
			case 0x3D:
			case 0x3E:
			case 0x3F:
			case 0x71:
			case 0x72:
			case 0x92:
			case 0x93:
			case 0x94:
			case 0xB7:
				{
					Sleep(Milliseconds(75));
					Process::Write16(AnimInstance + 0xE, AnimItem & 0xFFFF);
        			Process::Write16(AnimInstance + 0x10, (AnimItem >> 0x10) & 0xFFFF);
					if (AnimID == 0x3E) //pick up item
					{
						Process::Write16(AnimInstance + 0x12, SnakeID);
						Process::Write32(AnimInstance + 0x14, 0x00020101);
					}
					if (AnimID == 0x38) //equip item
					{
						Process::Write8(AnimInstance + 0x12, 1);
					}
					if (AnimID == 0x41 || AnimID == 0x42) //clover pick up | item to inv
					{
						Process::Write8(AnimInstance + 0x14, 3);
						Game::AppendCoordData(AnimInstance, 0x15, Player::GetCoordinates(PlayerIndex));
					}
				}
				break;
		//get santa bag | changes to sting removal as santa bag is annoying
			case 0x39:
				{
					AnimID = 0xA7;
					Process::Write8(AnimInstance + 0xE, 1);
				}
				break;
		//emotion anims
			case 0xAF:
			case 0x88:
				{
					Process::Write8(AnimInstance + 0xE, EmotionID & 0xFF);
        			Process::Write8(AnimInstance + 0xF, 1);
				}
				break;
		//snake anim 1
			case 0xC4:
				{
					Process::Write16(AnimInstance + 0xE, SnakeID & 0xFFF);
        			Process::Write16(AnimInstance + 0x10, SoundID & 0xFFFF);

        			Process::Write8(AnimInstance + 0x13, 1);
        			Process::Write16(AnimInstance + 0x15, 0xFFFE);
        			Process::Write8(AnimInstance + 0x17, 4);
        			Process::Write8(AnimInstance + 0x18, *(u8 *)(PlayerInstance + 0x2F));
				}
				break;
		//snake & sound anim
			case 0xC5:
				{
					Process::Write16(AnimInstance + 0xE, SnakeID & 0xFFF);
        			Process::Write16(AnimInstance + 0x10, SnakeID & 0xFFFF);

        			Process::Write8(AnimInstance + 0x12, *(u8 *)(PlayerInstance + 0x2F));
        			Process::Write8(AnimInstance + 0x13, 1);
        			Process::Write8(AnimInstance + 0x17, 5);
				}
				break;
		//knock door
			case 0x45:
				{
					Process::Write32(Knock, 0xE8BD8FF0); // Patch so knocking doesn't happen
					Process::Write16(AnimInstance + 0xE, SoundID & 0xFFF);
        			Process::Write8(AnimInstance + 0x11, 1);

        			Game::AppendCoordData(AnimInstance, 0x12, Player::GetCoordinates(PlayerIndex));
				}
				break;
		//put item out
			case 0x3B:
				Process::Write8(AnimInstance + 0xF, EmotionID & 0xFF);
				break;
		//Hold item
			case 0x3C:
				{
					Process::Write32(AnimInstance + 0xE, AnimItem);

        			Process::Write8(AnimInstance + 0x12, wX);
        			Process::Write8(AnimInstance + 0x13, wY);

        			Process::Write8(AnimInstance + 0x15, EmotionID & 0xFF);
				}
				break;
		//shovel hits nothing
			case 0x4A:
				{
					Process::Write8(AnimInstance + 0xE, wX);
        			Process::Write8(AnimInstance + 0xF, wY);

        			Process::Write8(AnimInstance + 0x10, EmotionID & 0xFF);
				}
				break;
		//change outfit
			case 0x36:
				{
					Process::Write32(AnimInstance + 0xE, AnimItem);
        			Process::Write8(AnimInstance + 0x12, EmotionID & 0xFF); //Not emotion, position of outfit
        			Process::Write32(AnimInstance + 0x1C, 0x01480000);
				}
				break;
		//sitting
			case 0x7B:
			case 0x7C:
			case 0x7D:
			case 0x7F:
				{
					Process::Write32((u32)&pfunction2, 0x5D4C88);
					pfunction2(AnimInstance + 0xF, (u32)Game::WorldCoordsToCoords(wX, wY, coords));
    
        			Process::Write8(AnimInstance + 0x13, *(u8 *)(PlayerInstance + 0x2F));
				}
				break;
		//Face Cutout Standee standing
			case 0xC1:
				{
					Game::AppendCoordData(AnimInstance, 0xE, Player::GetCoordinates(PlayerIndex));
        			Process::Write8(AnimInstance + 0x12, 0);
        			Process::Write8(AnimInstance + 0x13, EmotionID);
				}
				break;
		//a lot of random ones
			case 0x1C:
			case 0x25:
			case 0x1D: 
			case 0xE2:
			case 0xE5:
			case 0xA8:
			case 0xA9:
			case 0xAA:
			case 0xAB:
			case 0xAD:
			case 0xAE:
			case 0x80:
			case 0x81:
			case 0x82:
			case 0x83:
			case 0x84:
			case 0x85:
			case 0x86:
			case 0x87:
			case 0x2B:
			case 0x2C:
			case 0x2D:
			case 0x2E:
			case 0x2F:
			case 0x30:
			case 0x31:
			case 0x32:
				{
					Game::AppendCoordData(AnimInstance, 0x2, Player::GetCoordinates(PlayerIndex));

					Process::Write32((u32)&pfunction2, 0x5D4C88);
					pfunction2(AnimInstance + 0xE, (u32)Game::WorldCoordsToCoords(wX, wY, coords));
    
        			Process::Write8(AnimInstance + 0x12, *(u8 *)(PlayerInstance + 0x2F));
        			Process::Write8(AnimInstance + 0x13, EmotionID & 0xFF);
				}
				break;
		//unused fall down for fishing
			case 0xB3:
			case 0xB4:
			case 0xB5:
				{
					Process::Write32((u32)&pfunction2, 0x5D4C88);
					pfunction2(AnimInstance + 0xE, (u32)Game::WorldCoordsToCoords(wX, wY, coords));
    
        			Process::Write32(AnimInstance + 0x12, AnimItem);
				}
				break;
		//appearance change
			case 0xB9:
				{
					Process::Write8(AnimInstance + 0xC, 0x10);
        			Process::Write8(AnimInstance + 0xD, 0);
    			// Write Appearance to Animation
        			Process::Write8(AnimInstance + 0xE, Appearance[0]);
        			Process::Write8(AnimInstance + 0xF, Appearance[1]);
        			Process::Write8(AnimInstance + 0x10, Appearance[2]);
    			// Writes Item to animation //used for mii head
        			Process::Write16(AnimInstance + 0x11, AnimItem & 0xFFFF);
				}
				break;
		//faint
			case 0x9D:
				Game::AppendCoordData(AnimInstance, 0xF, Player::GetCoordinates(PlayerIndex));
				break;
		//door open
			case 0x44:
				Game::AppendCoordData(AnimInstance, 0x10, Player::GetCoordinates(PlayerIndex));
				break;
		//random ones
			case 0xD9:
			case 0x75:
				Game::AppendCoordData(AnimInstance, 0xE, Player::GetCoordinates(PlayerIndex));
				break;
		//Open mailbox
			case 0x8B:
			case 0xDE:
				{
					Process::Write32(AnimInstance + 0x12, 0x528000 >> 8);
        			Game::AppendCoordData(AnimInstance, 0xE, Player::GetCoordinates(PlayerIndex));
				}
				break;
		//close mailbox
			case 0x8C:
			case 0xDF:
				{
					Process::Write32(AnimInstance + 0x12, 0x8000 >> 8);
        			Process::Write8(AnimInstance + 0x13, 1);
        			Game::AppendCoordData(AnimInstance, 0xE, Player::GetCoordinates(PlayerIndex));
				}
				break;
		//bury item in
			case 0x53:
			case 0x52:
				{
					Process::Write8(AnimInstance + 0xE, wX);
        			Process::Write8(AnimInstance + 0xF, wY);

        			Process::Write32(AnimInstance + 0x10, PlayerInstance);

        			Process::Write8(AnimInstance + 0x11, 1);
        			Process::Write8(AnimInstance + 0x16, 1);
				}
				break;
		//Bury
			case 0x4F:
				{
					Process::Write8(AnimInstance + 0xE, wX);
        			Process::Write8(AnimInstance + 0xF, wY);

        			Process::Write16(AnimInstance + 0x10, 0x7FFE);
        			Process::Write8(AnimInstance + 0x14, 0);
        			Process::Write8(AnimInstance + 0x15, 0);
        			Process::Write8(AnimInstance + 0x16, 0);
        			Game::AppendCoordData(AnimInstance, 0x17, Player::GetCoordinates(PlayerIndex));
				}
				break;
		//Bury item out
			case 0x50:
			case 0x51:
				{
					Process::Write8(AnimInstance + 5, 0);
        			Process::Write8(AnimInstance + 0x16, 1);

        			Process::Write32(AnimInstance + 0x10, AnimItem);

        			Process::Write8(AnimInstance + 0xE, wX);
        			Process::Write8(AnimInstance + 0xF, wY);

        			Process::Write8(AnimInstance + 0x15, 0);

        			Game::AppendCoordData(AnimInstance, 0x17, Player::GetCoordinates(PlayerIndex));
				}
				break;
		//random one
			case 0x14:
				{
					Process::Write8(AnimInstance + 0x14, wX);
        			Process::Write8(AnimInstance + 0x15, wY);

        			Game::AppendCoordData(AnimInstance, 0xE, Player::GetCoordinates(PlayerIndex));
				}
				break;
		//sit down
			case 0x79:
				Game::AppendCoordData(AnimInstance, 0xF, Player::GetCoordinates(PlayerIndex));
				break;
		//sit down v2
			case 0x7A:
				Player::GetCoordinates(PlayerIndex);
				break;
		//stand up
			case 0xAC:
				{
					Process::Write32(AnimInstance + 0x17, *(u32 *)(PlayerInstance + 0x8D3) << 8);
        			Process::Write8(AnimInstance + 0x18, 2);

        			Game::AppendCoordData(AnimInstance, 0xE, Player::GetCoordinates(PlayerIndex));
        			Game::AppendCoordData(AnimInstance, 0x13, Player::GetCoordinates(PlayerIndex));
				}
				break;
		//throw fish rod
			case 0xB0:
				Game::AppendCoordData(AnimInstance, 0x14, Player::GetCoordinates(PlayerIndex));
				break;
		//random ones
			case 0xE1:
			case 0x62:
				Game::AppendCoordData(AnimInstance, 0xE, Player::GetCoordinates(PlayerIndex));
				break;
		//player blinking
			case 0x95:
			case 0x33:
				{
					Process::Write8(AnimInstance + 0x15, 1);

					Process::Write32((u32)&pfunction2, 0x5D4C88);
					pfunction2(AnimInstance + 0xF, (u32)Game::WorldCoordsToCoords(wX, wY, coords));
				}
				break;
		//switch on light
			case 0x69:
				{
					Process::Write8(AnimInstance + 0xE, wX);
        			Process::Write8(AnimInstance + 0xF, wY);

					Process::Write32((u32)&pfunction2, 0x5D4C88);
					pfunction2(AnimInstance + 0x10, (u32)Game::WorldCoordsToCoords(wX, wY, coords));
				}
				break;
		//rock hit
			case 0x4C:
				{
					Process::Write8(AnimInstance + 0xE, wX);
        			Process::Write8(AnimInstance + 0xF, wY);
        			Process::Write8(AnimInstance + 0x10, 1);
			
				//Rock Break
        			Process::Write8(AnimInstance + 0x11, 1); //rock hit
        			Process::Write8(AnimInstance + 0x1A, 1); //rock break

					Process::Write32((u32)&pfunction2, 0x5D4C88);
					pfunction2(AnimInstance + 0x12, (u32)Game::WorldCoordsToCoords(wX, wY, coords));
				}
				break;
		//congrats
			case 0x2A: //0xAAEAD8 is pointer for it
				{
					Process::Write32(AnimInstance + 0xE, 0xFD041C);
        			Process::Write32(AnimInstance + 0x12, 0x208800);
        			Process::Write32(AnimInstance + 0x16, 0);
        			Process::Write32(AnimInstance + 0x1A, 0x40000FE);
        			Process::Write32(AnimInstance + 0x1E, 0x7F00000C);
        			Process::Write32(AnimInstance + 0x22, 0xB32300);

        			Process::Write32(PlayerInstance + 0x146C, 0);
				}
				break;
		//toy hammer
			case 0x9C: 
				{
					Process::Write8(AnimInstance + 0xE, 2);
       				Process::Write32(AnimInstance + 0xF, *(u32 *)(PlayerInstance + 0x5A8));


					Process::Write32((u32)&pfunction2, 0x5D4C88);
					pfunction2(AnimInstance + 0x12, (u32)Game::WorldCoordsToCoords(wX, wY, coords));
    
        			u16 var1 = *(u16 *)(PlayerInstance + 0x2E);
        			Process::Write8(AnimInstance + 0x17, (char)((int)var1 >> 8));
				}
				break;
		//every other animation
			default:
				{
					Process::Write8(AnimInstance + 0xE, wX);
        			Process::Write8(AnimInstance + 0xF, wY);

        			Process::Write16(AnimInstance + 0x10, AnimItem & 0xFFFF);
				}
				break;
		}

		if(!directSend)
		{
		//If animation is forced and needs overwrite patch code
			u32 OverWriteInstance = 0x1ABADC; //0x1ABAFC EUR
			if(forced && needOverwrite)
			{
				Process::Patch(USA_PlayerInstance_Function + 0x10, 0xE3A00000 + PlayerIndex); //Patches code so player instance returns Index Address of selected player
				Process::Patch(OverWriteInstance, 0xE3A00000 + PlayerIndex); //Patches code so instead of own player selected player gets used
			}
		//If animation is forced on someone else patch code
			u32 PlayerDataCondition = 0x2FEB64; //0x2FEBEC EUR
			u32 IndexCondition = 0x677530; //0x676568 EUR
			u32 InstanceCondition = 0x677537; //0x67656F EUR
			u32 Condition1 = 0x677454; //0x67648C EUR
			u32 Condition2 = 0x6774F0; //0x676528 EUR
			u32 AnimConditionPatch = 0x677504; //0x67653C EUR
			u32 IndexChange = 0x628B54; //0x627B8C EUR

			if(forced)
			{
				Process::Patch(PlayerDataCondition, 0xE1A00000); //removes condition
				
				Process::Patch(IndexCondition, 0xE1A01006); //removes condition
				Process::Write8(InstanceCondition, 0xEB); //removes condition
				Process::Patch(Condition1, 0xE1A00000); //removes condition
				Process::Patch(Condition2, 0xE1A00000); //removes condition
				Process::Patch(AnimConditionPatch, 0xE1A00000); //removes condition
				Process::Patch(IndexChange, 0xE3A01000 + PlayerIndex); //in sendPkt Function GetOnlinePlayerIndex inline
				Sleep(Milliseconds(5));
			}
		//Executes Animation
			Animation::ExecuteAnimation(PlayerInstance, AnimID, AnimInstance);
			
		//If animation is forced on someone else undo patches
			if(forced)
			{
				Sleep(Milliseconds(5));
				
				Process::Patch(PlayerDataCondition, 0x1A000002); //Undo Patch

				Process::Patch(IndexCondition, 0x01A01006); //Undo Patch
				Process::Write8(InstanceCondition, 0x0B); //Undo Patch
				Process::Patch(Condition1, 0x0A000038); //Undo Patch	
				Process::Patch(Condition2, 0x0A00001C); //Undo Patch
				Process::Patch(AnimConditionPatch, 0x1A000017); //Undo Patch
				Process::Patch(IndexChange, 0xE5D11268); //Undo Patch
		
				u32 res = CalculateBranchInstruction(USA_PlayerInstance_Function + 0x10, USA_OnlinePlayerIndex_Function);
				Process::Patch(USA_PlayerInstance_Function + 0x10, 0x2B000000 + res); //Undo Patch
				Process::Patch(OverWriteInstance, 0xE3A00004); //Undo Patch
			}
		}
	//If it's a direct send
		else
		{
			if(forced) 
				Animation::SendPacket(ActualIndex, AnimInstance, AnimID, Player::ActualRoom(PlayerIndex), PlayerIndex); //Uses Animation Pack if forced
			else		
				Animation::ExecuteAnimation(PlayerInstance, AnimID, AnimInstance); //Executes Animation on yourself
		}
		
		//After it's over undo the patch with the Knock Animation
		Process::Write32(Knock, 0xE24DD00C);    
		
		Sleep(Milliseconds(25));
		return true;
	}

	void Animation::SendPacket(u8 senderIndex, u32 AnimObj, u8 AnimID, u8 RoomID, u8 TargetPlayerIndex)
	{
 		u32 PatchIndex = 0x5C3CAC; //0x5C2CF4 EUR
		u32 IndexChange = 0x628B54; //0x627B8C EUR

		Process::Write8(AnimObj, RoomID);
		Process::Write8(AnimObj + 1, AnimID);

		Process::Patch(IndexChange, 0xE3A01000 + TargetPlayerIndex); //in sendPkt Function GetOnlinePlayerIndex inline
		Process::Write8(PatchIndex, TargetPlayerIndex);
		Sleep(Milliseconds(5));

		Process::Write32((u32)&pfunction2, 0x5C3C7C); //0x5C2CC4 EUR
		pfunction2(TargetPlayerIndex, AnimObj);

		Sleep(Milliseconds(5));
		Process::Patch(IndexChange, 0xE5D11268);
		Process::Write8(PatchIndex, 4);
	}

	void Animation::DoMoonJump(u32 AnimInstance, u32 PlayerInstance)
	{
        Process::Write16(AnimInstance + 0xA, 0xFFFF);
        Process::Write16(AnimInstance + 0xC, 0x7F);
        Process::Write16(AnimInstance + 0xE, 0xC);
        Process::Write16(AnimInstance + 0x10, 0x38C);

        Process::Write8(AnimInstance + 0x13, 0);
        Process::Write16(AnimInstance + 0x15, 0xFFFE);
        Process::Write8(AnimInstance + 0x17, 4);
        Process::Write8(AnimInstance + 0x18, *(u8 *)(PlayerInstance + 0x2F));
    }

	u32 Chat::GetChatOffset(void)
	{
		return *(u32 *)USA_Chat_Pointer;
	}

	bool Chat::IsOpen(void)
	{
		return GetChatOffset() ? true : false;
	}

	bool Chat::IsEmpty(void)
	{
		if(Chat::IsOpen())
			return *(u8 *)(GetChatOffset() + 0x8) ? false : true;
		else
			return false;
	}

	u8 Chat::GetCursorPosition(bool OnTheLeft)
	{
		if(Chat::IsOpen())
			return (OnTheLeft) ? *(u8 *)(GetChatOffset() + 0x14) : *(u8 *)(GetChatOffset() + 0x1C);
		else
			return 0;
	}

	bool Chat::IsHighlighted(void)
	{
		if(Chat::IsOpen())
			return *(bool *)(GetChatOffset() + 0x20);
		else
			return false;
	}

	u8 Chat::GetCharactersCount(void)
	{
		return (Chat::IsOpen()) ? *(u8 *)(GetChatOffset() + 0x8) : 0;
	}

	u16Vector Chat::GetHighlightedCharacters(void)
	{
		u16Vector HighlightedString;

		if(!Chat::IsOpen())
			return HighlightedString;

		if(!Chat::IsHighlighted())
			return HighlightedString;

		u32 BaseInventory = *(u32 *)USA_BaseInventory_Pointer;
		if(Chat::GetCursorPosition() < Chat::GetCursorPosition(false))
		{
			for(int i = Chat::GetCursorPosition(); i < Chat::GetCursorPosition(false); i++)
				HighlightedString.push_back(*(u16 *)(BaseInventory + 0x44 + (i * 2)));
		}
		else
		{
			for(int j = Chat::GetCursorPosition(false); j < Chat::GetCursorPosition(); j++)
				HighlightedString.push_back(*(u16 *)(BaseInventory + 0x44 + (j * 2)));
		}

		return HighlightedString;
	}

	void Chat::SendMessage(void)
	{
		if(!Chat::IsOpen())
			return;

		Process::Write32((u32)&pfunction2, USA_SendChatMessage_Function);
		pfunction2(1, 2);
	}

	void Chat::WriteCharacter(u16 Character, u8 Position)
	{
		if(!Chat::IsOpen())
			return;

		if(Position > 32)
			return;

		Process::Write32((u32)&pfunction4, USA_WriteToChat_Function);
		pfunction4(GetChatOffset(), Character, Position, 0);
	}

	void Chat::MoveCursor(u8 Position1, u8 Position2, bool IsNotHighlighted)
	{
		if(!Chat::IsOpen())
			return;

		if(!(Position1 <= 32 && Position2 <= 32))
			return;

		Process::Write32((u32)&pfunction4, USA_ChatCursor_Function);
		pfunction4(GetChatOffset(), Position1, Position2, IsNotHighlighted);
	}

	void Chat::PopCharacterBack(bool NoSound)
	{
        if(!Chat::IsOpen())
			return;

        if(!Chat::IsHighlighted())
			return;

		u32 BaseInventory = *(u32 *)USA_BaseInventory_Pointer;
        if(Chat::GetCursorPosition() < Chat::GetCursorPosition(false))
        {
            for(int i = Chat::GetCursorPosition(); i < Chat::GetCursorPosition(false); i++)
                *(u16 *)(BaseInventory + 0x44 + (i * 2)) = 0;
        }
        else
        {
            for(int j = Chat::GetCursorPosition(false); j < Chat::GetCursorPosition(); j++)
                *(u16 *)(BaseInventory + 0x44 + (j * 2)) = 0;	
        }	
		Process::Write32((u32)&pfunction2, USA_PopChatCharacterBack_Function);
		pfunction2(GetChatOffset(), NoSound);
	}

	u32 NPC::GetData(u16 ID, int count)
	{
		u32 point = *(u32 *)0x95D3F4; //0x95C3EC EUR
		if(point == 0)
			return 0;

		u32 res = 0;
		u16 val = 0;
		u32 data = *(u32 *)(point + 0xD00C);
		int cvar = 0;

		while(res = data, res != 0)
		{
			data = *(u32 *)(res + 4);
			if(*(u8 *)(*(u32 *)(res + 8) + 0xF) == 0)
			{
				val = *(u16 *)(*(u32 *)(res + 8) + 4);
				if((val < 0x400) || (0x1FF < (val & 0x3FF))) 
					val = val & 0x3FF;
				else 
					val = (val & 0x3FF) + 0x200;

				if((*(u8 *)(val + point + 0x1102C) & 2) == 0)
				{
					if(*(u16 *)(res + 0xC) == ID)
					{
						cvar++;
						if(count == cvar || count == -1)
							return *(u32 *)(res + 8);
					}
				}
			}
    	}
		return 0;
	}

	std::string NPC::GetSPName(u8 SPVID)
	{
		u32 Stack[44];
		vu32(*AddStackFunction)(u32* param1);
		Process::Write32((u32)&AddStackFunction, 0x81F9D0);
		u32 add = AddStackFunction(Stack);

		vu32(*GetSPNameFunction)(u32 param1, u32 param2, char* param3, u32 param4);
		Process::Write32((u32)&GetSPNameFunction, 0x75D108);
		(void)GetSPNameFunction(*(u32 *)0x95EEDC, add, (char *)"STR_SPNpc_name", SPVID);

		std::string SPNPCName = "";
		Process::ReadString(Stack[1], SPNPCName, 0x20, StringFormat::Utf16);
		return SPNPCName.empty() ? "???" : SPNPCName;
	}

	std::string NPC::GetNName(u16 VID)
	{
		u32 Stack[44];
		vu32(*AddStackFunction)(u32* param1);
		Process::Write32((u32)&AddStackFunction, 0x81F9D0);
		u32 add = AddStackFunction(Stack);

		u32 npcModel = *(u32 *)(0xA84AF0) + VID * 0x22;
		vu32(*GetNNameFunction)(u32 param1, u32 param2, char* param3, u32 param4);
		Process::Write32((u32)&GetNNameFunction, 0x308210);
		(void)GetNNameFunction(*(u32 *)0x95EEDC, add, (char *)"STR_NNpc_name", npcModel + 10);

		std::string NNPCName = "";
		Process::ReadString(Stack[1], NNPCName, 0x20, StringFormat::Utf16);
		return NNPCName.empty() ? "???" : NNPCName;
	}

	//0x01 to 0x34
	u8 NPC::GetSPVID(u32 npcData)
	{
		u32 var = *(u32 *)(npcData + 0x660);
		var = *(u8 *)(var + 0x260);
		return var;
	}

	u16 NPC::GetVID(u32 npcData)
	{
		Process::Write32((u32)&pfunction1, 0x51D288);
		return pfunction1(npcData);
	}

	u32 NPC::GetPlayerSave(u32 npcData)
	{
		return *(u32 *)(npcData + 0x9AC);
	}

	void NPC::GetLoadedNPC(NPC_DataVector &vec)
	{
		vec.clear();
		u32 data = 0;
		u8 SPVID = 0;
		u16 VID = 0;
		std::string str = "";
		u32 save = 0;

		//SPNPC
		for(u16 i = 0x0196; i < 0x1FC; i++)
		{
			data = GetData(i);
			if(data != 0)
			{
				SPVID = GetSPVID(data);
				vec.push_back(NPC_Data{ GetSPName(SPVID), data });
			}
		}

		//Special Case (Boat SPNPC (Kappn))	
		data = GetData(0x18C);
		if(data != 0)
		{
			vec.push_back(NPC_Data{ GetSPName(0x15), data }); //0x15 is Kappn's SPVID (it isn't in the RAM when he is loaded there)
		}

		//Special Case (Tour Tortimer (specifically at the tour results))	
		data = GetData(0x18B);
		if(data != 0)
		{
			vec.push_back(NPC_Data{ GetSPName(0x41), data }); //0x41 is Tortimers's SPVID (it isn't in the RAM when he is loaded there)
		}

		//NNPC
		for(int i = 0; i < 0xA; i++)
		{
			data = GetData(0x191 + !Player::IsIndoor(), i);
			if(data != 0)
			{
				VID = GetVID(data);
				vec.push_back(NPC_Data{ GetNName(VID), data });
			}
		}

		//Special Case (Mainstreet NNPC)
		for(int i = 0; i < 0xA; i++)
		{
			data = GetData(0x194, i);
			if(data != 0)
			{
				VID = GetVID(data);
				vec.push_back(NPC_Data{ GetNName(VID), data });
			}
		}

		//Special Case (Tour NNPC (specifically the Hide and Seek Tour))
		for(int i = 0; i < 5; i++)
		{
			data = GetData(0x1FC, i);
			if(data != 0)
			{
				VID = GetVID(data);
				vec.push_back(NPC_Data{ GetNName(VID), data });
			}
		}

		//PNPC
		for(int i = 0; i < 8; i++)
		{
			data = GetData(0x193, i);
			if(data != 0)
			{
				save = GetPlayerSave(data);
				str = "";
				Process::ReadString(save + 0x55A8, str, 16, StringFormat::Utf16); 
				vec.push_back(NPC_Data{ str, data });
			}
		}

		//Special Case (Tour PNPC (specifically at the tour results))
		for(int i = 0; i < 5; i++)
		{
			data = GetData(0x189, i);
			if(data != 0)
			{
				save = GetPlayerSave(data);
				str = "";
				Process::ReadString(save + 0x55A8, str, 16, StringFormat::Utf16); 
				vec.push_back(NPC_Data{ str, data });
			}
		}

		//Special Case (Boat PNPC (When going to the island/leaving island))
		for(int i = 0; i < 5; i++)
		{
			data = GetData(0x18D, i);
			if(data != 0)
			{
				save = GetPlayerSave(data);
				str = "";
				Process::ReadString(save + 0x55A8, str, 16, StringFormat::Utf16); 
				vec.push_back(NPC_Data{ str, data });
			}
		}
	}

	void NPC::AnimationExecuter(u8 Mode, u32 Address, u8 Anim, u16 Tool, u16 Snake, u8 Emotion)
	{
		u16 ToolRdm = Utils::Random(0x334C, 0x3383);
		u8 EmotionRdm = Utils::Random(1, 0x40);

		if(Address == 0)
			return;

		u32 null[]{0};
		switch(Mode)
		{
			case 0: //Animation
			{
				if(!IDList::AnimValid(Anim) || (Anim == 0xFF))
					return;

				Process::Write32((u32)&pfunction8, 0x6E7D54); //0x6E6D74 EUR
				(void)pfunction8(Address + 0x78, Anim, 0, 0xAE6864, (u32)null, (u32)null, 0, 0x8816C4);
				break;
			}
			case 1: //Tool
			{
				u16 ToolOk;
				if(!IDList::ToolValid(Tool))
					ToolOk = 0x2001;
				else
					ToolOk = Tool;
				
				Process::Write32((u32)&pfunction3, 0x6EE778); //0x6ED798 EUR
				if(Tool == 0xFFFF)
					(void)pfunction3(Address + 0x78, 0, (u32)&ToolRdm);
				else
					(void)pfunction3(Address + 0x78, 0, (u32)&ToolOk);
				break;
			}
			case 2: //Snake
			{
				if(!IDList::SnakeValid(Snake))
					return;
				Process::Write32((u32)&pfunction5, 0x6EB384); //0x6EA3A4 EUR
				(void)pfunction5(Address + 0x78, 0, Snake, 0, 0);
				break;
			}
			case 3: //Emote
			{
				if(!IDList::EmotionValid(Emotion))
					return;
				Process::Write32((u32)&pfunction3, 0x6EC4E0); //0x6EB500 EUR
				if(Emotion == 0xFF)
					(void)pfunction3(Address + 0x78, 0, EmotionRdm);
				else
					(void)pfunction3(Address + 0x78, 0, Emotion);
				break;
			}
		}
	}

	bool IDList::ValidIDFloat(float ID, float StardID, float EndID)
	{
		return (ID >= StardID && ID <= EndID);
	}

	bool IDList::ValidID32(u32 ID, u32 StardID, u32 EndID) 
	{
		return (ID >= StardID && ID <= EndID);
	}

	bool IDList::ValidID16(u16 ID, u16 StardID, u16 EndID)
	{
		return (ID >= StardID && ID <= EndID);
	}

	bool IDList::ValidID8(u8 ID, u8 StardID, u8 EndID) 
	{
		return (ID >= StardID && ID <= EndID);
	}

	bool IDList::ItemValid(u32 ItemID)
	{
		u16 Flags = (ItemID >> 16) & 0xFFFF;

		if(((ItemID == 0x7FFE) || (ItemID == 0x80007FFE) || (ItemID == 0x585B) || ValidID16(ItemID, 0, 0xFD)) && ((Flags <= 0x3407) || (Flags == 0x8000)))
			return true;

		if((ValidID16(ItemID, 0x2001, 0x2060) || ValidID16(ItemID, 0x2089, 0x2185) || ValidID16(ItemID, 0x21E4, 0x22DF) || ValidID16(ItemID, 0x22E1, 0x30CB) || ValidID16(ItemID, 0x30D2, 0x3108) || ValidID16(ItemID, 0x3130, 0x33B4) || ValidID16(ItemID, 0x33BC, 0x34CD) || ValidID16(ItemID, 0x3726, 0x372A) || ValidID16(ItemID, 0x4000, 0x50CB) || ValidID16(ItemID, 0x50D2, 0x5FFF)) && ((Flags <= 0x3407) || (Flags == 0x8000)))
			return true;
		
		return false;
	}

	bool IDList::RoomValid(u8 RoomID)
	{
		//if villager not exists room warp not work
		//if no exhibtion house those crash: 0x92 - 0x97

		if(!ValidID8(RoomID, 0, 0xA4))
			return false;

		if(ValidID8(RoomID, 0x27, 0x2A) || ValidID8(RoomID, 0x5D, 0x66) || ValidID8(RoomID, 0x69, 0x8D) || ValidID8(RoomID, 0x98, 0x9C))
			return false;
		
		switch(RoomID) 
		{
			case 0x62: 
			case 0x65: 
			case 0x66: 
				return false;
		}
		
		return true;
	}

	bool IDList::AnimValid(u8 AnimID)
	{
		if(AnimID == 0xFF)
			return true;

		if(!ValidID8(AnimID, 0, 0xEB))
			return false;

		return true;
	}

	bool IDList::ToolValid(u16 ToolID)
	{
		if((ToolID == 0xFFFF) || (ToolID == 0x3729))
			return true;

		if(!ValidID16(ToolID, 0x334C, 0x33A6))
			return false;

		return true;
	}

	bool IDList::SnakeValid(u16 SnakeID)
	{
		if(!ValidID16(SnakeID, 1, 0x275))
			return false;

		switch(SnakeID) 
		{
			case 0xF7: 
			case 0xFA: 
			case 0xFB: 
			case 0xFC: 
			case 0xFD: 
			case 0x124: 
			case 0x125: 
				return false;
		}

		return true;
	}

	bool IDList::EmotionValid(u8 EmotionID)
	{
		if(EmotionID == 0xFF)
			return true;

		if(!ValidID8(EmotionID, 1, 0x40))
			return false;

		return true;
	}

	bool IDList::SoundValid(u16 SoundID)
	{
		if((SoundID == 0xFFFF))
			return true;

		if(!ValidID16(SoundID, 0, 0xFFE))
			return false;

		if(ValidID16(SoundID, 0xDC, 0x10A))
			return false;

		return true;
	}

	bool IDList::CustomAnimValid(u8 CustomAnim)
	{
		if(!ValidID8(CustomAnim, 0xD, 0xE2))
			return false;
		
		if(ValidID8(CustomAnim, 0x17, 0x1B) || ValidID8(CustomAnim, 0x2A, 0x33) || ValidID8(CustomAnim, 0x62, 0x6A) || ValidID8(CustomAnim, 0xB9, 0xBC) || ValidID8(CustomAnim, 0xD1, 0xDB))
			return false;

		switch(CustomAnim) 
		{
			case 0x13:
			case 0x14:
			case 0x15:
			case 0x22: 
			case 0x23: 
			case 0x25: 
			case 0x36: 
			case 0x37: 
			case 0x3E: 
			case 0x42:
			case 0x43:
			case 0x44:
			case 0x46: 
			case 0x47:
			case 0x48:
			case 0x4A:
			case 0x55:
			case 0x5E:
			case 0x6D:
			case 0x75:
			case 0x79:
			case 0x80:
			case 0x95:
			case 0x96:
			case 0x97:
			case 0x9A:
			case 0x9D:
			case 0xA4:
			case 0xA8:
			case 0xBF:
			case 0xC2:
			case 0xC4:
			case 0xC5:
				return false;
		}

		return true;
	}

	bool IDList::BuildingValid(u8 BuildingID)
	{
		if(!ValidID8(BuildingID, 0, 0xFB))
			return false;

		return true;
	}

	bool IDList::MusicValid(u8 MusicID) // not completed
	{
		switch(MusicID) 
		{
			case 0x40:
			case 0x42:
			case 0x43:
			case 0x45:
			case 0x47:
				return false;
		}

		return true;
	}

	bool IDList::ParticleValid(u16 Particle)
	{
		if(!ValidID16(Particle, 0, 0x246))
			return false;

		return true;
	}

	static const ID_DataVector& GetItemsList()
	{
		static const ID_DataVector ItemsList = []()
		{
			ID_DataVector Database;
			std::string FilePath = "Luna/ItemsList.txt";
			File ItemsFile(FilePath, File::READ);
			
			if(ItemsFile.IsOpen())
			{
				std::string content = ReadWholeTxtFile(FilePath);
				size_t lineStart = 0;
				
				while(lineStart < content.length())
				{
					size_t lineEnd = content.find('\n', lineStart);
					if(lineEnd == std::string::npos)
						lineEnd = content.length();
					
					// Line extraction and cleaning
					std::string line = content.substr(lineStart, lineEnd - lineStart);
					line.erase(0, line.find_first_not_of(" \t"));
					line.erase(line.find_last_not_of(" \t") + 1);
					
					if(!line.empty())
					{
						size_t spacePos = line.find(' ');
						if(spacePos != std::string::npos)
						{
							// ID Conversion
							u16 ID = 0;
							std::string idStr = line.substr(0, spacePos);
							for(char c : idStr)
							{
								ID = (ID << 4) | (c >= '0' && c <= '9' ? c - '0' :
									c >= 'A' && c <= 'F' ? 10 + c - 'A' :
									c >= 'a' && c <= 'f' ? 10 + c - 'a' : 0);
							}
							
							// Name extraction
							std::string name = line.substr(spacePos + 1);
							name.erase(0, name.find_first_not_of(" \t"));
							name.erase(name.find_last_not_of(" \t") + 1);
							
							if(ID != 0 && !name.empty())
							{
								ID_Data entry;
								name.pop_back();
								entry.Name = strdup(name.c_str()); // Storage Name
								entry.IDs.push_back(ID); // Storage ID
								Database.push_back(entry);
							}
						}
					}
					lineStart = lineEnd + 1;
				}
			}
			return Database;
		}();

		return ItemsList;
	}

	std::string IDList::GetItemName(u16 ID)
	{
		const ID_DataVector& Items = GetItemsList();

		for(const ID_Data& item : Items)
		{
			if(std::find(item.IDs.begin(), item.IDs.end(), ID) != item.IDs.end())
			{
				return std::string(item.Name);
			}
		}

		return Items.empty() ? "" : "Unknown Item";
	}

	std::string IDList::GetRoomName(u8 ID)
	{
		for(const ID_Data& room : Rooms)
		{
			if(std::find(room.IDs.begin(), room.IDs.end(), ID) != room.IDs.end())
			{
				return std::string(room.Name);
			}
		}

		return Color::Red << "Invalid room!";
	}

	std::string IDList::GetBuildingName(u8 ID)
	{
		for(const ID_Data& building : Buildings)
		{
			if(std::find(building.IDs.begin(), building.IDs.end(), ID) != building.IDs.end())
			{
				return std::string(building.Name);
			}
		}

		return Color::Red << "Invalid building!";
	}

	std::string IDList::GetOutdoorMusicName(u8 ID)
	{
		for(const ID_Data& outdoormusic : OutdoorMusics)
		{
			if(std::find(outdoormusic.IDs.begin(), outdoormusic.IDs.end(), ID) != outdoormusic.IDs.end())
			{
				return std::string(outdoormusic.Name);
			}
		}

		return Color::Red << "Invalid music!";
	}

	std::string IDList::GetParticleName(u16 ID)
	{
		for(const ID_Data& particle : Particles)
		{
			if(std::find(particle.IDs.begin(), particle.IDs.end(), ID) != particle.IDs.end())
			{
				return std::string(particle.Name);
			}
		}

		return Color::Red << "Invalid particle!";
	}

	u32 Camera::GetInstance()
	{
		return *(u32 *)USA_CameraInstance_Pointer;
	}
	
	float* Camera::GetCoordinates()
	{
		return (float *)0x9866F4; //0x9856F4 EUR
	}

	void Camera::AddToX(float val)
	{
		*(float *)(Camera::GetInstance() + 4) += val;
	}

	void Camera::AddToY(float val)
	{
		*(float *)(Camera::GetInstance() + 8) += val;
	}

	void Camera::AddToZ(float val)
	{
		*(float *)(Camera::GetInstance() + 0xC) += val;
	}
	
	void Camera::AddToYRotation(u16 val)
	{
		*(u16 *)(Camera::GetInstance() + 0x1C) += val;
	}
}