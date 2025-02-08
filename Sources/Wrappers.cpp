#include "Wrappers.hpp"

namespace CTRPluginFramework
{
    bool    GetInput(u8 &input, const std::string &msg, bool useHex)
    {
        Keyboard    keyboard(msg);

        if(msg.empty())
            keyboard.DisplayTopScreen = false;
        keyboard.IsHexadecimal(useHex);

        if(keyboard.Open(input, input) != -1)
            return (true);

        return (false);
    }

    bool    GetInput(u16 &input, const std::string &msg, bool useHex)
    {
        Keyboard    keyboard(msg);

        if(msg.empty())
            keyboard.DisplayTopScreen = false;
        keyboard.IsHexadecimal(useHex);

        if(keyboard.Open(input, input) != -1)
            return (true);

        return (false);
    }

    bool    GetInput(u32 &input, const std::string &msg, bool useHex)
    {
        Keyboard    keyboard(msg);

        if(msg.empty())
            keyboard.DisplayTopScreen = false;
        keyboard.IsHexadecimal(useHex);

        if(keyboard.Open(input, input) != -1)
            return (true);

        return (false);
    }

    bool    GetInput(float &input, const std::string &msg)
    {
        Keyboard    keyboard(msg);

        if(msg.empty())
            keyboard.DisplayTopScreen = false;

        if(keyboard.Open(input, input) != -1)
            return (true);

        return (false);
    }

    bool    GetInput(u16 &input, const StringVector &choices, const std::string &msg)
    {
        Keyboard    keyboard(msg);

        if(msg.empty())
            keyboard.DisplayTopScreen = false;

        keyboard.Populate(const_cast<StringVector &>(choices));

        int selected = keyboard.Open();

        if(selected != -1)
        {
            input = selected;
            return (true);
        }

        return (false);
    }

    u32    CalculateBranchInstruction(u32 PC, u32 target)
    {
		u32 instruction = ((target - PC) >> 2) - 2;

		if(PC > target)
			instruction -= 0x3F000000;

		return instruction;
	}

	//OpenList(DisplayMsg, NameOfList);
	s8 OpenList(const std::string &msg, StringVector list)
	{
		Sleep(Milliseconds(80));
		Keyboard ListKB(msg);
		ListKB.Populate(list);
		s8 choice = ListKB.Open();
		return choice;
	}

	//SetUpKB(HexORnot, Length, Output, DefaultValue); With a default value
	bool SetUpKB(const std::string &msg, bool hex, const int length, std::string &output, std::string def, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output, def) == 0;
	}

	bool SetUpKB(const std::string &msg, bool hex, const int length, float &output, float def, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output, def) == 0;
	}

	bool SetUpKB(const std::string &msg, bool hex, const int length, u64 &output, u64 def, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output, def) == 0;
	}

    bool SetUpKB(const std::string &msg, bool hex, const int length, u32 &output, u32 def, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output, def) == 0;
	}

	bool SetUpKB(const std::string &msg, bool hex, const int length, u16 &output, u16 def, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output, def) == 0;
	}

	bool SetUpKB(const std::string &msg, bool hex, const int length, u8 &output, u8 def, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output, def) == 0;
	}

	//SetUpKBNo(HexORnot, Length, Output); Without a default value
	bool SetUpKBNo(const std::string &msg, bool hex, const int length, std::string &output, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output) == 0;
	}

	bool SetUpKBNo(const std::string &msg, bool hex, const int length, float &output, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output) == 0;
	}

	bool SetUpKBNo(const std::string &msg, bool hex, const int length, u64 &output, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output) == 0;
	}

	bool SetUpKBNo(const std::string &msg, bool hex, const int length, u32 &output, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output) == 0;
	}

	bool SetUpKBNo(const std::string &msg, bool hex, const int length, u16 &output, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output) == 0;
	}

	bool SetUpKBNo(const std::string &msg, bool hex, const int length, u8 &output, OnInputChange cb)
	{
		Sleep(Milliseconds(80));
		Keyboard SetUp(msg);
		SetUp.IsHexadecimal(hex);
		SetUp.SetMaxLength(length);
		SetUp.OnKeyboardEvent(cb);
		return SetUp.Open(output) == 0;
	}
}