#ifndef WRAPPERS_HPP
#define WRAPPERS_HPP

#include "CTRPluginFramework.hpp"

namespace CTRPluginFramework
{
	using StringVector = std::vector<std::string>;
    using OnInputChange = void(*)(Keyboard &keyboard, KeyboardEvent &event);
    
    bool    GetInput(u8 &input, const std::string &msg = "", bool useHex = false);
    bool    GetInput(u16 &input, const std::string &msg = "", bool useHex = false);
    bool    GetInput(u32 &input, const std::string &msg = "", bool useHex = false);
    bool    GetInput(float &input, const std::string &msg = "");
    bool    GetInput(u16 &input, const StringVector &choices, const std::string &msg = "");
    u32 	CalculateBranchInstruction(u32 PC, u32 target);

    s8		OpenList(const std::string &msg, StringVector list);
	bool	SetUpKB(const std::string &msg, bool hex, const int length, std::string &output, std::string def, OnInputChange cb = nullptr);
	bool	SetUpKB(const std::string &msg, bool hex, const int length, float &output, float def, OnInputChange cb = nullptr);
	bool	SetUpKB(const std::string &msg, bool hex, const int length, u64 &output, u64 def, OnInputChange cb = nullptr);
	bool	SetUpKB(const std::string &msg, bool hex, const int length, u32 &output, u32 def, OnInputChange cb = nullptr);
	bool	SetUpKB(const std::string &msg, bool hex, const int length, u16 &output, u16 def, OnInputChange cb = nullptr);
	bool	SetUpKB(const std::string &msg, bool hex, const int length, u8 &output, u8 def, OnInputChange cb = nullptr);
	bool	SetUpKBNo(const std::string &msg, bool hex, const int length, std::string &output, OnInputChange cb = nullptr);
	bool	SetUpKBNo(const std::string &msg, bool hex, const int length, float &output, OnInputChange cb = nullptr);
	bool	SetUpKBNo(const std::string &msg, bool hex, const int length, u64 &output, OnInputChange cb = nullptr);
	bool	SetUpKBNo(const std::string &msg, bool hex, const int length, u32 &output, OnInputChange cb = nullptr);
	bool	SetUpKBNo(const std::string &msg, bool hex, const int length, u16 &output, OnInputChange cb = nullptr);
	bool	SetUpKBNo(const std::string &msg, bool hex, const int length, u8 &output, OnInputChange cb = nullptr);
}

#endif