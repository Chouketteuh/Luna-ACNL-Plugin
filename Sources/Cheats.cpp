#include "Cheats.hpp"

namespace CTRPluginFramework
{
	bool WantReload = false;
    bool TimeMachineBool = false;

	bool Turbo = false;
    bool OSD = true;
	bool offlinemoonjump = false;
	bool SeedersOSD = true;
	bool TouchRemove = false;
	bool AutoRemove = false;
	bool ByPassing = false;
	bool MapEditorActive = false;
	bool IsCatalogOpen = false;
	bool AnimExecuting = false;
	bool IfForceAllowed = true;
	bool IslandAcresCreator = false;
	bool KbExtender = false;
	bool CameraPatch = false;
	bool Fov = false;
	bool ControlPlayer = false;
	bool Save = true;

	static float CoordSpeed = 5.0f;
	static float WalkSpeed = 1.5f;

	static u32 SeedersID = 0x80007FFE, ItemIDToReplace = 0x7FFE;
	u8 DropType = 0xA, DropAnim = 0x56;
	u32 selectedX, selectedY;
	static u8 MapEditorsize;
	static bool MapEditorRemoval = false;

	u8 Appearance[3] = {0, 0, 0};
	u8 AnimID = 6, EmotionID = 1, NPC_Anim = 0, NPC_Emotion = 1;
	u16 SnakeID = 0x1DC, NPC_Snake = 0x1DC, AnimItem, ToolID = 0x2001, NPC_AnimItem = 0x2001, SoundID = 0x7FA;
	static u8 Mode = 0, Index = 0, NPCMode = 0, NPCIndex = 0;
	static u32 CurrentNPCAddress = 0;
	static float NPC_CoordSpeed = 4.0f;

	static u32Vector IslandItems;
	static u8 CustomIslandAcres[16];
	u16 ShopItem[4] = {0x2083, 0x2083, 0x2083, 0x2083};

	struct Building 
	{
		u8 id;
		u8 x;
		u8 y;
	};
	struct Island
	{
		Building b[2];
	};
	static Island isl
	{ 
		0x69, 0x1F, 0x15, //Building 1
		0x6A, 0x1D, 0x15, //Building 2
	};
	
	std::string ShowT_AcreID[5][7] = {""};
	std::string ShowI_AcreID[4][4] = {""};
	static constexpr u8 TownAddage[5] = {0x7, 0xE, 0x15, 0x1C, 0x23};
	static constexpr u8 IslandAddage[4] = {0, 0x4, 0x8, 0xC};
	static constexpr u16 TownArceID_XPos[7] = {43, 79, 115, 151, 187, 223, 259};
	static constexpr u8 TownArceID_YPos[5] = {52, 88, 124, 160, 196};
	static constexpr u8 TownRect_XPos[7] = {34, 70, 106, 142, 178, 214, 250};
	static constexpr u8 TownRect_YPos[5] = {54, 90, 126, 162, 198};
	static constexpr u8 IslandArceID_XPos[4] = {83, 124, 165, 206};
	static constexpr u8 IslandArceID_YPos[4] = {50, 91, 132, 173};
	static constexpr u8 IslandRect_XPos[4] = {77, 118, 159, 200};
	static constexpr u8 IslandRect_YPos[4] = {37, 78, 119, 160};

	u16 SymbolID = 2;
	static bool HasSet[4] = {false, false, false, false};
	u16 pID[4];

	static float CamSpeed = 1.0f;
	static float FloatFov = 1.0f;

	u8 SelectedPlayerIndex = 0;

	static s8 toolsuchoice = 50;
	const float ParticleSpace = 32.0f; // Display interval

	float StartCoords[3] =
	{
		0,
		0,
		0,
	};

	u8 NumParticles[3] =
	{
		1, //x
		1, //y
		1, //z
	};

	StringVector NpcOpt =
	{
		"Set ID",
		Color::Magenta << "NPC Selection" << Color::Yellow,
		"Select Mode",
		"Teleport NPC -> You",
		"Teleport You -> NPC",
	};

	StringVector BuildingOpt =
	{
		"Place building",
		"Move building",
		"Remove building",
	};

    StringVector WeatherOpt =
	{
	    Color::Yellow << "Sunny",
		Color::Silver << "Cloudy",
	    Color::DarkGrey << "Covered",
		Color::Blue << "Rainy",
		Color::DimGrey << "Stromy",
		Color::SkyBlue << "Snowy",
		Color::DeepSkyBlue << "Heavily snowy",
		Color::Red << "DISABLE",
	};

    StringVector SaisonsOpt =
	{
	    Color::DeepSkyBlue << "Winter",
	    Color::LimeGreen << "Spring",
		Color::Red << "Summer",
		Color::Orange << "Autumn",
	};

	StringVector FestivalsOpt =
	{
	    "Fishing Tournament",
	    "Insect Tournament",
		"Bunny Day",
		"Toy Day",
		"Carnival",
	};

	StringVector NooklingOpt =
    {
		"Nookling Cranny",
        "T&T Mart",
        "Super T&T",
        "T.I.Y",
        "T&T Emporium",
    };

	StringVector IslandItemsOpt =
    {
		"Copy",
		"Paste",
        "Save dump",
        "Restore save",
    };

	StringVector CountryOpt =
	{
		Color::Red << "DISABLE" << Color::White,
		"France",
	    "Canada",
		"Royaume-Uni",
		"Etats-Unis",
		"Japon",
		"Chine",
		"Australie",
		"Mexique",
		"Hacker Island",
	};

	StringVector ToursOpt =
	{
	    "Ore",
	    "Fruits",
	};

	StringVector InvOpt =
    {
        "Clear Inventory",
        "Fill Inventory",
    };

    StringVector MoneysOpt =
    {
        "Set Wallet",
        "Set Bank",
        "Set Meow Coupons",
		"Set Medals",
    };

    StringVector PlayerOpt =
	{
		"Hair style",
		"Hair color",
		"Eyes style",
		"Eyes color",
		"Tan",
        "Gender",
		"Region TPC",
	};

	StringVector RegionOpt =
	{
		"Country",
		"Region",
    };

	StringVector GenderOpt =
	{
		Color::Blue << "Men",
		Color::Magenta << "Women",
	};

	StringVector OutfitsOpt =
	{
		"Save Outfit",
		"Load Outfit",
	};

	StringVector BadgesOpt =
    {
		"Empty",
		"Bronze",
        "Silver",
		"Gold",
    };

	StringVector CollectablesOpt =
    {
		"Fill Encyclopedia",
		"Fill Emoticons List",
        "Fill Songs List",
		"Fill Catalog",
    };

	StringVector ToolsOpt =
	{
	    "Shovel",
	    "Rod",
		"Net",
		"Can",
		"Axe",
		"Slingshot",
		"Toy Hammer",
		"Good-Luck Roll",
		"Beans",
		"Bubble wand",
		"Party Popper",
		"Sparkler",
	};

	void	ToggleTurbo(MenuEntry *entry)
	{
		if(entry->Hotkeys[0].IsPressed())
		{
			Turbo = !Turbo;
			OSD::Notify("Turbo mode:" + (Turbo ? Color::Green << "ON" : Color::Red << "OFF"));

			//Multi-Presses
			if(Turbo)
				Process::Patch(0x5C5BEC, 0x1A000028); //0xE1A00000
			else if(!Turbo)
				Process::Patch(0x5C5BEC, 0x0A000028); //0x5C4C34 EUR
		}
	}

	/*
	Movements Codes
	*/

	void    CoordinateModifier(MenuEntry *entry)
    {
        if(!MapEditorActive) // If not in MapEditor mode
        {
			if(entry->Hotkeys[0].IsDown())
				Player::AddToCoordinates(0.f, 0.f, 0 - CoordSpeed); // Up
			if(entry->Hotkeys[1].IsDown())
				Player::AddToCoordinates(0.f, 0.f, CoordSpeed); // Down
			if(entry->Hotkeys[2].IsDown())
				Player::AddToCoordinates(0 - CoordSpeed, 0.f, 0.f); // Left
			if(entry->Hotkeys[3].IsDown())
				Player::AddToCoordinates(CoordSpeed, 0.f, 0.f); // Right
		}
    }

	void    SetCoordSpeed(MenuEntry *entry)
	{
		SetUpKB("Enter the speed you want to use:", false, 4, CoordSpeed, CoordSpeed);
	}

    void    TouchCoordinates(MenuEntry *entry)
    {
		const UIntRect MapAreaTown(70, 32, 180, 175);
		const UIntRect MapAreaMainstreet(4, 43, 312, 159);
		const UIntRect MapAreaIsland(76, 36, 168, 168);
        const UIntRect MapAreaTour(65, 34, 190, 170);
        const UIntRect MapAreaStreetPass(86, 45, 233, 191);

		if(Touch::IsDown() && Game::MapBool()) // Check if bottomscreen is touched & if the map is visible
		{
            UIntVector TouchPos = Touch::GetPosition();
            Coordinates PlayerPos = Player::GetStructCoordinates();

			u8 RoomID = Player::ActualRoom();

            if(RoomID == 0) // Main map + Island Tours
            {
				if (MapAreaTown.Contains(TouchPos))
				{
					FloatVector fPos(TouchPos);

					PlayerPos.x = (fPos.x - 75.f) * 14.94f + 527.f;
					PlayerPos.z = (fPos.y - 50.f) * 15.21f + 527.f;
					Player::SetStructCoordinates(PlayerPos);
				}
            }
            else if(RoomID == 1) // Mainstreet
            {
				if (MapAreaMainstreet.Contains(TouchPos))
				{
					FloatVector fPos(TouchPos);
	
					PlayerPos.x = (fPos.x - 15.f) * 6.5f + 150.f;
					PlayerPos.z = (fPos.y - 40.f) * 6.5f - 117.f;
					Player::SetStructCoordinates(PlayerPos);
				}
            }
            else if(RoomID == 0x68) // Island
            {
				if (MapAreaIsland.Contains(TouchPos))
				{
					FloatVector fPos(TouchPos);
	
					PlayerPos.x = (fPos.x - 75.f) * 12.2f;
					PlayerPos.z = (fPos.y - 30.f) * 12.2f;
					Player::SetStructCoordinates(PlayerPos);
				}
            }
            else if((RoomID >= 0x69) && (RoomID < 0x80)) // Island Tours
            {
				if (MapAreaTour.Contains(TouchPos))
				{
					FloatVector fPos(TouchPos);
	
					PlayerPos.x = (fPos.x - 24.0) * 13.5;
					PlayerPos.z = (fPos.y - -7.0) * 13.5;
					Player::SetStructCoordinates(PlayerPos);
				}
            }
            else if(RoomID == (0x8F || 0x90 || 0x91)) //Plazas StreetPass
            {
				if (MapAreaStreetPass.Contains(TouchPos))
				{
					FloatVector fPos(TouchPos);
	
					PlayerPos.x = (fPos.x - 86.f) * 6.5f;
					PlayerPos.z = (fPos.y - 45.f) * 6.5f;
					Player::SetStructCoordinates(PlayerPos);
				}
            }
		}
    }

    void    WalkOverThings(MenuEntry *entry)
    {
        static bool Enabling = false;
		if(System::IsCitra)
		{
			if(entry->Hotkeys[0].IsPressed() && !Player::InLoadingState())
			{
				Enabling = !Enabling;
				OSD::Notify("Walk Over Things:" + (Enabling ? Color::Green << "ON" : Color::Red << "OFF"));
				Enabling ? Process::Write8(USA_WalkOver_Address, 0x83) : Process::Write8(USA_WalkOver_Address, 0);
			}
			if(Enabling && Game::MapBool())
			{
				Process::Write8(USA_WalkOver_Address, 0x83);
			}
			else if(Player::IsIndoor())
			{
				Enabling ? Process::Write8(USA_CollisionIn_Address, 0xFF) : Process::Write8(USA_CollisionIn_Address, 0);
			}
		}
		else
		{
        	const u32 Addresses[8] =
			{
            	0x6503FC, //0x64F434 EUR
            	0x650414, //0x64F44C EUR
            	0x650578, //0x64F5B0 EUR
            	0x6505F0, //0x64F628 EUR
            	0x6506A4, //0x64F6DC EUR
            	0x6506BC, //0x64F6F4 EUR
            	0x6506C0, //0x64F6F8 EUR
            	0x6506EC, //0x64F724 EUR
			};
        	const u32 patch[8] = {0xEA000094, 0xEA000052, 0xEA000001, 0xEA000014, 0xE1A00000, 0xE1A00000, 0xEA000026, 0xEA000065};
			const u32 Original[8] = {0x0A000094, 0x0A000052, 0x0A000001, 0xDA000014, 0xED841A05, 0xED840A07, 0x0A000026, 0x0A000065};

        	if(entry->Hotkeys[0].IsPressed())
			{
				Enabling = !Enabling;
				OSD::Notify("Walk Over Things:" + (Enabling ? Color::Green << "ON" : Color::Red << "OFF"));
				for(u8 i = 0; i < 8; i++) 
				{
					Enabling ? Process::Patch(Addresses[i], patch[i]) : Process::Patch(Addresses[i], Original[i]);
				}
			}
		}
    }

	void	MoonJump(MenuEntry *entry)
	{
		if(Player::InLoadingState())
			return;

		if(!offlinemoonjump)
		{
			if(entry->Hotkeys[0].IsDown()) //Up
			{		
				if(!Player::IsIndoor())
					Process::Write32(0x33077C82, 0x7FFFFF);
				else
					Process::Write32(0x33077DAE, 0x7FFFFF);
			}
			/*if(entry->Hotkeys[1].IsDown()) //Down
			{
				if(!Player::IsIndoor())
					Process::Write32(0x33077C82, 0x00010FF0);
				else
					Process::Write32(0x33077DAE, 0x00010FF0);
			}*/
		}
		else
		{
			if(entry->Hotkeys[0].IsDown()) //Up
			{
				Process::Write16(USA_Gravity_Address, 0xFFFF);
				Player::AddToCoordinates(0.f, 2.0, 0.f);
			}
			if(entry->Hotkeys[1].IsDown()) //Down
			{
				Player::AddToCoordinates(0.f, 0 - 2.0, 0.f);
			}
		}
	}

	void    OptionMoonJump(MenuEntry *entry)
	{
		s8 uchoice = OpenList("", {"Moon Jump Online", "Moon Jump Offline"});
		switch(uchoice)
		{
			case 0:
				offlinemoonjump = false;
				break;
			case 1:
				offlinemoonjump = true;
				break;
			default:
				return;
		}
		OSD::Notify("Moon Jump:" + (offlinemoonjump ? Color::Orange << "Offline" : Color::DeepSkyBlue << "Online"));
	}

	void	SpeedMod(MenuEntry *entry)
	{
		if(entry->IsActivated())
		{
			Process::WriteFloat(0x887880, WalkSpeed);
			Process::WriteFloat(0x887888, WalkSpeed); 
			Process::WriteFloat(0x887958, WalkSpeed);
			Process::WriteFloat(0x5D4C80, 1.8f * WalkSpeed * 4096.0f); //swim speed
			Process::Write16(0x8879B8, 0x16BC); //fast 0x20 rotate
			Process::Write16(0x887C68, 0xB5E); //fast 0x1F rotate
			Process::Write16(0x94EF34, 0xB5E); //fast 0x1F rotate
			Process::Write8(0x8878A4, 0x14 * WalkSpeed); //slide
		}
		else if(!entry->IsActivated())
		{
			Process::Write32(0x887880, 0x3F7851EC);
			Process::Write32(0x887888, 0x3F866666); 
			Process::Write32(0x887958, 0x3ED70A3D);
			Process::Write32(0x5D4C80, 0x45800000); //swim speed
			Process::Write16(0x8879B8, 0x2BC); //fast 0x20 rotate
			Process::Write16(0x887C68, 0x309); //fast 0x1F rotate
			Process::Write16(0x94EF34, 0); //fast 0x1F rotate
			Process::Write8(0x8878A4, 0x14); //slide
		}
	}

	void	MenuSpeedMod(MenuEntry *entry)
	{
		SetUpKB("Enter the speed you want to use:", false, 4, WalkSpeed, WalkSpeed);
	}

	void	SpeedHack(MenuEntry *entry)
	{
		if(entry->Hotkeys[0].IsDown() && (!Player::IsIndoor()))
		{
			u32 Velocity;
			float fVelocity;

			if(!Process::Read32(USA_Velocity_Address, Velocity) || !Process::ReadFloat(USA_Velocity_Address, fVelocity)) //check if we're on a loading screen or no
				return;

			if(Velocity >= 0x41A79DB3) //if limit
			{
				Process::Write32(USA_Velocity_Address, 0x41A79DB3);
			}
			else if(Velocity > 0)
			{
				Process::WriteFloat(USA_Velocity_Address, fVelocity + 2.0);
			}
		}
	}

	void	MovementChanger(MenuEntry *entry)
	{
		static bool Walking = false;
		const u32 Addresses[6] =
		{
			0x67F748, //0x67E780 EUR
			0x64E824, //0x64D85C EUR
			0x64E82C, //0x64D864 EUR
			0x56BE7C, //0x56AEC4 EUR
			0x65352C, //0x652564 EUR
			0x763ABC, //0x762AC4 EUR
		};
		const u32 patch[6] = {0x1A000067, 0x03A00000, 0xE3A00000, 0xED902A00, 0xE1A00004, 0xE3A00001};
		const u32 patch1[6] = {0xEA000067, 0x03A00001, 0xE3A00001, 0xE12FFF1E, 0xEA00000D, 0xE3A00000};
		const u32 Original[6] = {0x1A000067, 0x03A00001, 0xE3A00000, 0xED902A00, 0xE1A00004, 0xE3A00001};
		
		if(entry->Hotkeys[0].IsPressed())
		{
			Walking = !Walking;
			OSD::Notify("Movement Mode:" + (Walking ? Color::LimeGreen << "Walking" : Color::DeepSkyBlue << "Swimming"));
			for(u8 i = 0; i < 6; i++) 
			{
				Walking ? Process::Patch(Addresses[i], patch[i]) : Process::Patch(Addresses[i], patch1[i]);
			}
		}
		if(!entry->IsActivated())
		{
			OSD::Notify("Movement Mode:" << Color::Red << "Default");
			for(u8 i = 0; i < 6; i++)
			{
				Process::Patch(Addresses[i], Original[i]);
			}
		}
	}

	void	OnRoomChange(Keyboard &k, KeyboardEvent &e)
	{
		std::string& s = k.GetInput();
		k.GetMessage() = "Enter the ID of the room you want to go:" << Color::Lime << "\nHex: 0~A4 " << Color::White << "|" << Color::Magenta << " Actual room:" << Utils::Format("%02X", Player::ActualRoom()) << Color::DeepSkyBlue << "\n\nWarping to: " << IDList::GetRoomName(s != "" ? std::stoi(s, nullptr, 16) : 0);
	}

	void	RoomMod(MenuEntry *entry)
	{
		if(entry->Hotkeys[0].IsPressed() && !Player::InLoadingState())
		{
			// Allow warp for host
			Process::Write32(0x61B568, 0xE1A00000);
			Process::Write32(0x61B908, 0xE1A00000);
			Process::Write32(0x61BA10, 0xE1A00000);
			Process::Write32(0x61B980, 0xE1A00000);
			// Fix checks
			Process::Write32(0x75F830, 0xE3A00001);

			u8 Room = 0xA5;
			if(SetUpKBNo("Enter the ID of the room you want to go:" << Color::Lime << "\nHex: 0~A4 " << Color::White << "|" << Color::Magenta << " Actual room:" << Utils::Format("%02X", Player::ActualRoom()), true, 2, Room, OnRoomChange))
			{
				if(Player::CanWarp(Room))
				{
					OSD::Notify("Warping to room:" << Color::Lime << Utils::Format("%02X", Room));
					if(Room == Player::ActualRoom())
						Game::ReloadRoom();
					else
						Game::RoomWarp(Room);
				}
			}
			Sleep(Milliseconds(80));
			Process::Write32(0x75F830, 0xE1A00000);
		}
	}
	
	/*
	Items Codes
	*/

	bool IsReplaceable(u32 *item)
	{
		if(ItemIDToReplace == 0xFFFFFFFF || *item == ItemIDToReplace || (*item == 0x80007FFE && ItemIDToReplace == 0x7FFE))
			return true;
		else
			return false;
	}

	bool    SetSeedersOSD(const Screen &screen)
	{
		u32 x = 3, y;
		if(screen.IsTop && !Player::InLoadingState())
		{
			y = screen.Draw("SeedersID:" << ((SeedersID == 0 || SeedersID == 0x7FFE || SeedersID == 0x80007FFE) ? Color::Blue << "Nothing" : (IDList::ItemValid(SeedersID) ? Color::Lime : Color::Yellow) << Utils::Format("%08X", SeedersID) << (((SeedersID & 0xFFFF) == 0 || (SeedersID & 0xFFFF) == 0x7FFE || IDList::GetItemName(SeedersID) == "") ? "" : Color::White << "|" << (IDList::ItemValid(SeedersID) ? Color::Lime : Color::Yellow) << IDList::GetItemName(SeedersID))), x, 0);
			if(ItemIDToReplace != 0x7FFE)
				y = screen.Draw("Replace:" << (ItemIDToReplace == 0xFFFFFFFF ? Color::Red << "All" : Color::Orange << Utils::Format("%08X", ItemIDToReplace) << (((ItemIDToReplace & 0xFFFF) == 0 || (ItemIDToReplace & 0xFFFF) == 0x7FFE || ItemIDToReplace == 0xFFFFFFFF || IDList::GetItemName(ItemIDToReplace) == "") ? "" : Color::White << "|" << Color::Orange << IDList::GetItemName(ItemIDToReplace))), x+12, y);
		}
		return true;
	}

	void	SetSeeders(MenuEntry *entry)
	{
		static u32 KeysPressedTicks = 0;

		if(entry->WasJustActivated())
		{
			// Enable EverythingSeeder, allow cheat items in inventory
			Process::Write32(USA_EverythingSeeder1_Address, 0xE1A00000);
			Process::Write32(USA_EverythingSeeder2_Address, 0xE1A00000);

			if(SeedersOSD)
				OSD::Run(SetSeedersOSD);
		}

		if(entry->Hotkeys[0].IsPressed() && !Player::InLoadingState()) // Set
		{
			if(!SetUpKBNo("Type the ID of the item you want." << Color::Lime << "\nHex: 0~80007FFE", true, 8, SeedersID))
				return;

			if(!(SeedersID == 0 || SeedersID == 0x7FFE || SeedersID == 0x80007FFE))
				Player::WriteInventory(0, SeedersID);
		}

		if(entry->Hotkeys[1].IsPressed()) // Copy
		{
			u32 x, y;
			if(Player::GetWorldCoords(&x, &y))
			{
				SeedersID = (u32)Items::GetItemAtWorldCoords(x, y);
				if(SeedersID >= 0)
				{
					Process::Read32(SeedersID, SeedersID);
					OSD::Notify("Copy:" << (IDList::ItemValid(SeedersID) ? Color::Lime : Color::Yellow) << Utils::Format("%08X", SeedersID));
				}
			}
		}

		if(entry->Hotkeys[2].IsPressed() && !Player::InLoadingState()) // Replace
		{
			if(!SetUpKB("Type ID to remplace:" << Color::LimeGreen << "\nReset = 7FFE" << Color::White << " | " << Color::Red << "Replace everything = FFFFFFFF", true, 8, ItemIDToReplace, 0x7FFE))
				return;

			if(ItemIDToReplace == 0)
				ItemIDToReplace = 0x7FFE;
		}

		if(Controller::IsKeysReleased(entry->Hotkeys[3].GetKeys()) || Controller::IsKeysReleased(entry->Hotkeys[4].GetKeys())) 
			KeysPressedTicks = 0;

		if(entry->Hotkeys[3].IsDown())
		{
			KeysPressedTicks++;
			if((KeysPressedTicks < 90 ? (KeysPressedTicks % 10) == 1 : (KeysPressedTicks % 3) == 1) || KeysPressedTicks > 220)
			{
				switch(SeedersID - 1)
				{
					case 0x2000:
						SeedersID = 0xFD;
						break;
					case 0xFFFFFFFF: //-1
					case 0x7FFD:
					case 0x80007FFD:
						SeedersID = 0x372A;
						break;
					default:
						SeedersID--;
						break;
				}
				Process::Read32(SeedersID, SeedersID);
			}
		}

		if(entry->Hotkeys[4].IsDown())
		{
			KeysPressedTicks++;
			if((KeysPressedTicks < 90 ? (KeysPressedTicks % 10) == 1 : (KeysPressedTicks % 3) == 1) || KeysPressedTicks > 220)
			{
				switch(SeedersID + 1)
				{
					case 0xFE:
						SeedersID = 0x2001;
						break;
					case 0x372B:
						SeedersID = 0;
						break;
					case 0x7FFF:
					case 0x80007FFF:
						SeedersID = 1;
						break;
					default:
						SeedersID++;
						break;
				}
				Process::Read32(SeedersID, SeedersID);
			}
		}

		if(!entry->IsActivated())
			OSD::Stop(SetSeedersOSD);
	}

	void	OptionSetSeeders(MenuEntry *entry)
	{
		if(MessageBox("Display of OSD? (ID Viewer)", DialogType::DialogYesNo).SetClear(ClearScreen::Top)())
		{
			OSD::Run(SetSeedersOSD);
			SeedersOSD = true;
		}
		else
		{
			OSD::Stop(SetSeedersOSD);
			SeedersOSD = false;
		}
	}

	void	TouchDrop(MenuEntry *entry)
	{
		Hook h;
		u32 worldX, worldY;

		if(entry->WasJustActivated())
		{
			Process::Write32(USA_Repalce_Hook, 0xE1A00000);
			h.Initialize(USA_Repalce_Hook, (u32)&IsReplaceable);
			h.Enable();
		}
		if((Turbo ? Touch::IsDown() : Controller::IsKeyPressed(Key::Touchpad)) && Game::MapBool())
		{
			UIntVector pos = Touch::GetPosition();
			switch(Player::ActualRoom())
			{
				case 0:
					if(pos.x >= 68 && pos.x <= 245 && pos.y >= 50 && pos.y <= 192)
					{
						worldX = ((pos.x - 68) / 2.2125) + 0x10;
						worldY = ((pos.y - 50) / 2.2125) + 0x10;
					}
					else
						return;
					break;
				case 0x68:
					if(pos.x >= 116 && pos.x <= 201 && pos.y >= 70 && pos.y <= 157)
					{
						worldX = ((pos.x - 116) / 2.65) + 0x10;
						worldY = ((pos.y - 70) / 2.65) + 0x10;
					}
					else
						return;
					break;
				default:
					return;
			}
			if(!Player::InLoadingState() && !MapEditorActive && !AnimExecuting)
			{
				if(!TouchRemove) Items::PlaceItemWrapper(DropType, ItemIDToReplace, (SeedersID & 0xFFFF) == 0x339F ? (u32 *)0x597870 : &SeedersID, &SeedersID, worldX, worldY, 0, 0, 0, 0, 0, DropAnim, 0xA5);
				else Items::TrampleAt(worldX, worldY);
			}
		}
	}

	void    OptionTouchDrop(MenuEntry *entry)
	{
		s8 uchoice = OpenList("", {"Touch Drop", "Touch Remove"});
		switch(uchoice)
		{
			case 0:
				TouchRemove = false;
				break;
			case 1:
				TouchRemove = true;
				break;
			default:
				return;
		}		
		OSD::Notify("Mode:" + (TouchRemove ? Color::Orange << "Touch Remove" : Color::DeepSkyBlue << "Touch Drop"));
	}

	void	AutoDropRemove(MenuEntry *entry)
	{
		static u16 Particles[2] = {0x214, 0x20C};
		static bool Enabling = false;
		Hook h;
		u32 worldX, worldY, u0;

		if(entry->WasJustActivated())
		{
			Process::Write32(USA_Repalce_Hook, 0xE1A00000);
			h.Initialize(USA_Repalce_Hook, (u32)&IsReplaceable);
			h.Enable();
		}
		if((entry->Hotkeys[0].IsPressed()))
		{
			Enabling = !Enabling;
			OSD::Notify("Auto " << (AutoRemove ? "remove:" : "drop:") + (Enabling ? Color::Green << "ON" : Color::Red << "OFF"));
		}
		if(Enabling && !Player::InLoadingState() && !MapEditorActive && !AnimExecuting)
		{
			if(!AutoRemove)
			{
				if(Items::DropCheck(&worldX, &worldY, &u0, 0, 0))
					Items::PlaceItemWrapper(DropType, ItemIDToReplace, (SeedersID & 0xFFFF) == 0x339F ? (u32 *)0x597870 : &SeedersID, &SeedersID, worldX, worldY, 0, 0, 0, 0, 0, DropAnim, 0xA5);
			}
			else if(AutoRemove)
			{
				float ParticleCoords[3];

				if(!Player::GetWorldCoords(&worldX, &worldY))
					return;

				u8 x, y, z;
				for(x = 0; x < 3; x++)
				{
					for(z = 0; z < 3; z++)
					{
						Items::TrampleAt((worldX - 1 + x), (worldY - 1 + z));
						/*for(y = 0; y < 1; y++)
						{
							ParticleCoords[0] = Player::GetCoordinates()[0] + -32 + x * ParticleSpace;
							ParticleCoords[1] = Player::GetCoordinates()[1] + 0 + y * ParticleSpace;
							ParticleCoords[2] = Player::GetCoordinates()[2] + -32 + z * ParticleSpace;
							Game::Particles(Particles[1], ParticleCoords);
						}*/
					}
				}
			}
		}
	}

	void    OptionAutoDropRemove(MenuEntry *entry)
	{
		s8 uchoice = OpenList("", {"Auto Drop", "Auto Remove"});
		switch(uchoice)
		{
			case 0:
				AutoRemove = false;
				break;
			case 1:
				AutoRemove = true;
				break;
			default:
				return;
		}		
		OSD::Notify("Mode:" + (AutoRemove ? Color::Orange << "Auto Remove" : Color::DeepSkyBlue << "Auto Drop"));
	}

	void	DropModifier(MenuEntry *entry)
	{
		static u8 Mode = 1;

		if(entry->WasJustActivated())
		{
			Process::Write32(USA_DropMode1_Address, 0xE1A00000);
			Process::Write8(USA_DropMode2_Address, 6); // Set anim after bury
		}
		if(entry->Hotkeys[0].IsPressed())
		{
			switch(Mode) 
			{
				case 0:
					Mode++;
					OSD::Notify("Drop Type:" << Color::Red << "Drop");
					DropType = 0xA; //Drop
					DropAnim = 0x56;
					break;
				case 1:
					Mode++;
					OSD::Notify("Drop Type:" << Color::Orange << "Plant");
					DropType = 0xC; //Plant
					break;
				case 2:
					Mode++;
					OSD::Notify("Drop Type:" << Color::Yellow << "Pattern");
					DropType = 0xD; //DisplayPattern
					break;
				case 3:
					Mode++;
					OSD::Notify("Drop Type:" << Color::LimeGreen << "SmashRock");
					DropType = 0x12; //SmashRock
					break;
				case 4:
					Mode++;
					OSD::Notify("Drop Type:" << Color::Turquoise << "Dig");
					DropType = 0x13; //Dig
					DropAnim = 0x73;
					break;
				case 5:
					Mode++;
					OSD::Notify("Drop Type:" << Color::DeepSkyBlue << "Bury");
					DropType = 0xB; //Bury
					DropAnim = 0x56;
					break;
				case 6:
					Mode++;
					OSD::Notify("Drop Type:" << Color::Magenta << "FillHole");
					DropType = 0x7; //FillHole
					DropAnim = 0x5D;
					break;
				case 7: // should I keep this?
					Mode = 0;
					OSD::Notify("Drop Type:" << Color::Purple << "ShakeTree");
					DropType = 0x9; //ShakeTree
					DropAnim = 0x6B;
					break;
				default:
					break;
			}
			Process::Write8(USA_DropType_Address, DropType);
		}
	}

	void    OptionDropModifier(MenuEntry *entry)
	{
		const u32 Addresses[4] =
		{
			USA_ByPassItemDrop1_Address,
			USA_ByPassItemDrop2_Address,
			USA_ByPassItemDrop3_Address,
			USA_ByPassItemDrop4_Address,
		};
		const u32 Patch[4] = {0xE3E00000, 0xEA000012, 0xE3A00000, 0xE8BD83F0};
		const u32 Original[4] = {0xE1A05001, 0x1A000001, 0xE24DD01C, 0xE1A07001};

		// Bypass Items Locked
		if(MessageBox("Bypass items locked? (Fast drop)", DialogType::DialogYesNo).SetClear(ClearScreen::Top)())
		{
			for(u8 i = 0; i < 4; i++)
				Process::Write32(Addresses[i], Patch[i]);
			ByPassing = true;
		}
		else
		{
			for(u8 i = 0; i < 4; i++)
				Process::Write32(Addresses[i], Original[i]);
			ByPassing = false;
		}
	}

	void    PickUpMod(MenuEntry *entry)
	{
		static bool Enabling = true, AutoPick = false;
		static u8 Mode = 0, Index = 0;
		const u32 Addresses[8] =
		{
			0x598D9C, //0x597DE4 EUR
			0x599FD0, //0x599018 EUR
			0x59A1C0, //0x599208 EUR
			0x59A24C, //0x599294 EUR
			0x661894, //0x6608CC EUR
			0x661898, //0x6608D0 EUR
			0x66189C, //0x6608D4 EUR
			0x6618C0, //0x6608F8 EUR
		};
		const u32 AutoPickAddr[3] =
		{
			0x67CCB8, //0x67BCF0 EUR
			0x59A0D0, //0x599118 EUR
			0x59A1BC, //0x599204 EUR
		};
		const u32 Patchs[5][8] =
		{
			{0xE3A00001, 0xE3A00001, 0xE3A04001, 0xE3A00001, 0xE5840000, 0xE5C48004, 0xE5CA9013, 0xE3A0103D},
			{0xE3A00003, 0xE3A00003, 0xE3A04003, 0xE3A00003, 0xE5840000, 0xE5C48004, 0xE5CA9013, 0xE3A01040},
			{0xE3A0000A, 0xE3A0000A, 0xE3A0400A, 0xE3A0000A, 0xE5840002, 0xE5C48000, 0xE5CA900F, 0xE3A01061},
			{0xE3A00012, 0xE3A00012, 0xE3A04012, 0xE3A00012, 0xE5840002, 0xE5C48000, 0xE5CA900F, 0xE3A0105A},
			{0xE3A00013, 0xE3A00013, 0xE3A04013, 0xE3A00013, 0xE5840002, 0xE5C48000, 0xE5CA900F, 0xE3A0104F}
		};
		const u32 Original[8] = {0xE3A00007, 0xE1A00004, 0xE3A04001, 0xE1A00004, 0xE5840000, 0xE5C48004, 0xE5CA9013, 0xE3A0103C};
		const u32 ToggleAutoPick[2][3] =
		{
            {0xE1A00000, 0xE1A00000, 0xE1A00000},
            {0x0A000039, 0x1A000041, 0x0A000006}
        };


		if(entry->WasJustActivated()) 
		{
			Process::Write32(Addresses[3], 0xE3A00001);
			if(Index == Mode)
			{
				Index = 0;
				Mode = 1;
				OSD::Notify("PickUp Type:" << Color::Red << "PickUp");
				for(u8 i = 0; i < 8; i++)
				{
					Process::Write32(Addresses[i], Patchs[Index][i]);
				}
			}
		}
		if(entry->IsActivated())
		{
			if(!IDList::ItemValid(SeedersID) || SeedersID == 0 || SeedersID == 0x7FFE || SeedersID == 0x80007FFE)
				Process::Write32(USA_PickUpSeeder_Address, 0x80007FFE);
			else if(IDList::ItemValid(SeedersID))
				Process::Write32(USA_PickUpSeeder_Address, SeedersID);
		}
		if(entry->Hotkeys[0].IsPressed())
		{
			switch(Mode) 
			{
				case 0:
				    Index = Mode;
					Mode++;
					OSD::Notify("PickUp Type:" << Color::Red << "PickUp");
					break;
				case 1:
				    Index = Mode;
					Mode++;
					OSD::Notify("PickUp Type:" << Color::Orange << "Pluck");
					break;
				case 2:
				    Index = Mode;
				    Mode++;
					OSD::Notify("PickUp Type:" << Color::Green << "FlipDrop");
					break;
				case 3:
				    Index = Mode;
				    Mode++;
					OSD::Notify("PickUp Type:" << Color::Blue << "SmashRock");
					break;
				case 4:
				    Index = Mode;
				    Mode = 0;
					OSD::Notify("PickUp Type:" << Color::Purple << "Dig");
				default:
					break;
			}
		}
		if(entry->Hotkeys[1].IsPressed())
		{
			Enabling = !Enabling;
			OSD::Notify("PickUp Mod:" + (Enabling ? Color::Green << "ON" : Color::Red << "OFF"));
		}
		if(entry->Hotkeys[2].IsPressed())
		{
			AutoPick = !AutoPick;
			
			if(!AutoPick)
			{
				for(u8 i = 0; i < 3; i++)
					Process::Write32(AutoPickAddr[i], ToggleAutoPick[1][i]);
			}

			OSD::Notify("Auto PickUp:" + (AutoPick ? Color::Green << "ON" : Color::Red << "OFF"));
		}
		if(Enabling)
		{
			Process::Write32(USA_PickUpItem_Address, 0x9E0000);
			Process::Patch(USA_AlwaysPickUp_Address, 0xEA00003D);
			Process::Write32(USA_PickUpAnim_Address, 0xE3A01006);
			Process::Write32(USA_PickUpInventoryFix_Address, 0xEA000008);
			for(u8 i = 0; i < 8; i++)
			{
				Process::Write32(Addresses[i], Patchs[Index][i]);
			}
			if(AutoPick)
			{
				for(u8 i = 0; i < 3; i++)
                	Process::Write32(AutoPickAddr[i], ToggleAutoPick[0][i]);
			}
		}
		if(!entry->IsActivated() || !Enabling)
		{
			for(u8 i = 0; i < 8; i++)
			{
                Process::Write32(Addresses[i], Original[i]);
			}
			Process::Write32(USA_PickUpItem_Address, 0x95CFFC);
			Process::Patch(USA_AlwaysPickUp_Address, 0x0A000044);
			Process::Write32(USA_PickUpAnim_Address, 0xE3A01054);
			Process::Write32(USA_PickUpInventoryFix_Address, 0x0A000008);

			for(u8 i = 0; i < 3; i++)
                Process::Write32(AutoPickAddr[i], ToggleAutoPick[1][i]);
		}
	}

	void MapEditor(MenuEntry *entry)
	{
		Clock ParticlesDelay;

		if(!Player::IsLoaded())
		{
			if(MapEditorActive)
				goto OFF;

			return; //if player is not loaded return
		}

		static u32 DPadKeyPressedTicks = 0;

		if(entry->IsActivated())
		{
			if(*(u8 *)0x32DC49C0 != 1)
			{
				u8 *Anim = Player::GetAnimation();
				if(Anim != nullptr && *Anim == 6)
					Process::Write32(Camera::GetInstance() + 0xF0, 0x500);
			}
		}
		else if(!entry->IsActivated())
			goto OFF;
			
		if(!MapEditorActive) //If Map Editor is OFF get Coords
			Player::GetWorldCoords(&selectedX, &selectedY);
		
		if(entry->Hotkeys[0].IsPressed())
		{
			if(!MapEditorActive) //Map Editor ON
			{
				Fov = true;
				
				if(Save)
					Process::Patch(USA_SaveMenu_Address, 0xE1A00000);

				Process::Patch(USA_UnlockCamera_Address, 0xE8BD81F0);
				OSD::Notify("Map Editor:" << Color::Green << "ON");
				MapEditorActive = true;

				*(float *)(Camera::GetInstance() + 4) = (float)(selectedX * 0x20 + 0x10);
				Camera::AddToY(90.0f);
				*(float *)(Camera::GetInstance() + 0xC) = (float)(selectedY * 0x20 + 0x70);
				Camera::AddToYRotation(0x700);
			}
			else
			{ 
				OFF:
				Fov = false;
				
				if(Save)
					Process::Patch(USA_SaveMenu_Address, 0xE8900006);
				
				Process::Patch(USA_UnlockCamera_Address, 0xE2805C01);
				OSD::Notify("Map Editor:" << Color::Red << "OFF");
				MapEditorActive = false;
			}
		}
		
		if(MapEditorActive)
		{	
			if(Controller::IsKeyDown(Key::DPadRight) || Controller::IsKeyPressed(Key::DPadRight))
			{
				DPadKeyPressedTicks++;
				if((DPadKeyPressedTicks < 50 ? (DPadKeyPressedTicks % 8) == 1 : (DPadKeyPressedTicks % 3) == 1) || DPadKeyPressedTicks > 100)
				{
					selectedX += 1;
					Camera::AddToX(32.0f);
				}
			}
			
			if(Controller::IsKeyDown(Key::DPadLeft) || Controller::IsKeyPressed(Key::DPadLeft))
			{
				DPadKeyPressedTicks++;
				if((DPadKeyPressedTicks < 50 ? (DPadKeyPressedTicks % 8) == 1 : (DPadKeyPressedTicks % 3) == 1) || DPadKeyPressedTicks > 100)
				{
					selectedX -= 1;
					Camera::AddToX(-32.0f);
				}
			}
			
			if(Controller::IsKeyDown(Key::DPadDown) || Controller::IsKeyPressed(Key::DPadDown))
			{
				DPadKeyPressedTicks++;
				if((DPadKeyPressedTicks < 50 ? (DPadKeyPressedTicks % 8) == 1 : (DPadKeyPressedTicks % 3) == 1) || DPadKeyPressedTicks > 100)
				{
					selectedY += 1;
					Camera::AddToZ(32.0f);
				}
			}
			
			if(Controller::IsKeyDown(Key::DPadUp) || Controller::IsKeyPressed(Key::DPadUp))
			{
				DPadKeyPressedTicks++;
				if((DPadKeyPressedTicks < 50 ? (DPadKeyPressedTicks % 8) == 1 : (DPadKeyPressedTicks % 3) == 1) || DPadKeyPressedTicks > 100)
				{
					selectedY -= 1;
					Camera::AddToZ(-32.0f);
				}
			}

			if(Controller::IsKeyReleased(Key::DPadRight) || Controller::IsKeyReleased(Key::DPadLeft) || Controller::IsKeyReleased(Key::DPadDown) || Controller::IsKeyReleased(Key::DPadUp)) 
				DPadKeyPressedTicks = 0;
			
			if(Controller::IsKeysPressed(Key::Start + Key::DPadDown))
			{
				MapEditorsize++;
				if(MapEditorsize >= 3)
					MapEditorsize = 0;
				
				OSD::Notify("Size:" << Color::Yellow << std::to_string(MapEditorsize+1));
			}
			
			if(Controller::IsKeysPressed(Key::Start + Key::DPadLeft)) 
			{
				MapEditorRemoval = !MapEditorRemoval;

				OSD::Notify("Removal mode:" << (MapEditorRemoval ? Color::Green << "ON" : Color::Red << "OFF"));
			}
			
			if(Turbo ? Controller::IsKeyDown(Key::A) : Controller::IsKeyPressed(Key::A))
			{
				u32 *pItem = Items::GetItemAtWorldCoords(selectedX, selectedY);
				
				if(!pItem) 
					return;
				
				for(s8 i = -MapEditorsize; i <= MapEditorsize; ++i)
				{
					for(s8 j = -MapEditorsize; j <= MapEditorsize; ++j)
					{
						if(!MapEditorRemoval)
							Items::PlaceItemWrapper(DropType, ItemIDToReplace, &SeedersID, &SeedersID, (selectedX + j), (selectedY + i), 0, 0, 0, 0, 0, DropAnim, 0xA5);
						else 
							Items::TrampleAt((selectedX + j), (selectedY + i)); 
					}
				}
			}

			/*if(ParticlesDelay.HasTimePassed(Seconds(1)))
			{
				static u16 Particles[2] = {0x214, 0x20C};
				float ParticleCoords[3];

				for(s8 i = -MapEditorsize; i <= MapEditorsize; ++i)
				{
					for(s8 j = -MapEditorsize; j <= MapEditorsize; ++j)
					{
						ParticleCoords[0] = (selectedX + j) * 0x20 + 0x10;
						ParticleCoords[1] = Player::GetCoordinates()[1];
						ParticleCoords[2] = (selectedY + i) * 0x20 + 0x10;
						Game::Particles(Particles[MapEditorRemoval], ParticleCoords);
					}
				}
				ParticlesDelay.Restart();
			}*/
		}
	}

    void	Trampler(MenuEntry *entry)
	{
		static bool Enabling = false;
		const u32 addresses[6] = {0x64E4D4, 0x597F38, USA_NoBreakFlowers_Address, 0x597FA0, 0x597FE8, 0x597FAC};
        const u32 original[6] = {0x0A000032, 0x0A000056, 0xE3A0801D, 0x1A00003C, 0x0A00002A, 0x0A000039};
        const u32 patch[6] = {0xE1A00000, 0xE1A00000, 0xE1A00000, 0xE1A00000, 0xE1A00000, 0xE1A00000};
		if(entry->Hotkeys[0].IsPressed())
		{
			Enabling = !Enabling;
			OSD::Notify("Trampler:" + (Enabling ? Color::Green << "ON" : Color::Red << "OFF"));
			for(u8 i = 0; i < 6; i++) 
			{
				Enabling ? Process::Patch(addresses[i], patch[i]) : Process::Patch(addresses[i], original[i]);
			}
		}
		if(!entry->IsActivated())
		{
			for(u8 i = 0; i < 6; i++) 
			{
				Process::Patch(addresses[i], original[i]);
			}
		}
	}

	void	CatalogGetItem(u32 InvData) 
	{
		u32 CurrentItem = *(u32 *)(InvData + 0x3B9C - 0x28);
		u8 i = 0;

		while(Player::ReadInventory(i) != 0x7FFE && Player::ReadInventory(i) != 0x80007FFE)
		{
			i++;
			if(i >= 16)
				break;
		}
		if(i < 16)
		{
			Player::WriteInventory(i, CurrentItem);
			OSD::Notify("Slot " + Utils::Format("%d", i+1) + ":" << Color::Lime << Utils::Format("%04X", CurrentItem));
		}
		else
			OSD::Notify("Inventory Full!", Color::Orange);

		Game::GiveItemFunction(InvData);
	}

	void	CatalogToPockets(MenuEntry *entry)
	{
		Hook h;
		u32 x, y;

		if((!entry->IsActivated() || !IsCatalogOpen) && Save)
			Process::Patch(USA_SaveMenu_Address, 0xE1A00000);
		
		if(entry->Hotkeys[0].IsPressed() && !Player::InLoadingState() && !IsCatalogOpen && !MapEditorActive && !AnimExecuting)
		{
			Sleep(Seconds(1));
			if(Player::GetCurrentInventory() == 0xFF)
			{
				Animation::ExecuteAnimationWrapper(Player::GetActualPlayerIndex(), 6, 0, 0, 0, 0, 0, false, 0);
				h.Initialize(0x21B4B0, (u32)CatalogGetItem); //0x21B4D0 EUR
				h.SetFlags(USE_LR_TO_RETURN);

				Game::OpenCatalog();
			}
			else 
			{
				OSD::Notify(Color::Red << "Unable to open the catalog.");
			}
		}
		if(Player::GetCurrentInventory() == 0x7C)
		{ 
			IsCatalogOpen = true;

			h.Enable();
			Process::Patch(0x70E494, 0xE3A00000); // All items buyable
			Process::Patch(0x70E494 + 4, 0xEA00000B); // All items buyable
		}
		else if(Player::GetCurrentInventory() != 0x7C && IsCatalogOpen)
		{
			Animation::ExecuteAnimationWrapper(Player::GetActualPlayerIndex(), 6, 0, 0, 0, 0, 0, false, 0);
			IsCatalogOpen = false;
		}
		if(!entry->IsActivated() || !IsCatalogOpen)
		{
			if(Save)
				Process::Patch(USA_SaveMenu_Address, 0xE8900006);

			h.Disable();
			Process::Patch(0x70E494, 0x03A00001);		//0x70D4B4 EUR
			Process::Patch(0x70E494 + 4, 0x0A00000B);	//0x70D4B4 EUR

			IsCatalogOpen = false;
		}
	}

	void	InfiniteDropPlant(MenuEntry *entry)
	{
		if(entry->WasJustActivated())
		{
			Process::Patch(0x19C574, 0xE2805A00); //drop
			Process::Patch(0x19C4D0, 0xE2805A00); //plant
			Process::Patch(0x19B02C, 0xE2805A00); //bury
			Process::Patch(0x1A00F0, 0xE2805A00); //display
		}
		else if(!entry->IsActivated())
		{
			Process::Patch(0x19C574, 0xE2805A06); //drop
			Process::Patch(0x19C4D0, 0xE2805A06); //plant
			Process::Patch(0x19B02C, 0xE2805A06); //bury
			Process::Patch(0x1A00F0, 0xE2805A06); //display
		}
	}

	/*void	DropAndDigAnywhere(MenuEntry *entry)
	{
		if(entry->WasJustActivated())
		{
			// Drop
			Process::Write32(0x1655EC, 0xE3A00001);								//0x16560C EUR
			Process::Write32(0x1655F8, 0xEA000006);								//0x165618 EUR
			Process::Write32(0x1654EC, 0xEA000005);								//0x16550C EUR
			Process::Write32(0x165580, 0xEA000010); //on other players			//0x1655A0 EUR

			// Dig
			Process::Write32(0x5999F8, 0xE3A00001);
			Process::Write32(0x599A0C, 0xE3A04013);
			Process::Write32(0x6761B8, 0xE3A01050);
			Process::Write32(0x676214, 0xE3A01050);
			Process::Write32(0x67A2F4, 0x3414);
		}
		else if(!entry->IsActivated())
		{
			// Drop
			Process::Write32(0x1655EC, 0xEBA8068D);
			Process::Write32(0x1655F8, 0x1A000005);
			Process::Write32(0x1654EC, 0x0A000005);
			Process::Write32(0x165580, 0x0A000010); //on other players
		}
	}*/

	/*
	Animations Codes
	*/

	void	Idle(MenuEntry *entry)
	{
		if(entry->Hotkeys[0].IsDown() && !Player::InLoadingState())
		{
			Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 6, 0, 0, 0, 0, 0, false, 0);
		}
	}

	void	AnimMod(MenuEntry *entry)
    {
		static bool Button = false, Enabling = true, EnablingC = false;
		u16 CatchRdm = Utils::Random(0x228E, 0x234B);
		u16 ToolRdm = Utils::Random(0x334C, 0x3383);
		u8 EmotionRdm = Utils::Random(1, 0x40);
		u16 SoundRdm = Utils::Random(0x500, 0xE50);
		static u8 C_AnimID = 0xCA;
		s8 offsetX, offsetY;
		u32 wX, wY;

		if(entry->WasJustActivated()) 
		{
			if(Index == Mode)
			{
				Index = 0;
				Mode = 1;
				OSD::Notify("Animation Mode", Color::Red);
			}
		}
		if(entry->Hotkeys[0].IsPressed())
		{
			switch(Index)
			{
				case 0: //Animation
					SetUpKB("Enter the ID of an animation." << Color::Lime << "\nHex: 0~EB\nRandom animal capture = FF", true, 2, AnimID, AnimID);
					break;
				case 1: //Tool
					SetUpKB("Enter the ID of a tool." << Color::Lime << "\nHex: 334C~33A6 & 3729\nRandom tools = FFFF", true, 4, ToolID, ToolID);
					break;
				case 2: //Snake
					SetUpKB("Enter the ID of a snake animation." << Color::Lime << "\nHex: 1~275", true, 3, SnakeID, SnakeID); // onSnakeChange
					break;
				case 3: //Emotion
					SetUpKB("Enter the ID of an emotion." << Color::Lime << "\nHex: 1~40\nRandom emotion = FF", true, 2, EmotionID, EmotionID);
					break;
				case 4: //Sound
					SetUpKB("Enter the ID of a sound." << Color::Lime << "\nHex: 0~FFE\nRandom sound = FFFF", true, 4, SoundID, SoundID);
					break;
				case 5: //Appearance
				{
					Part1:
					if(!SetUpKB("Enter the ID of a hairstyle." << Color::Lime << "\nHex: 0~21", true, 2, Appearance[0], Appearance[0]))
						break;
					Part2:
					if(!SetUpKB("Enter the ID of a hairstyle color." << Color::Lime << "\nHex: 0~F", true, 1, Appearance[1], Appearance[1]))
						goto Part1;
					if(!SetUpKB("Enter the ID of an eye color." << Color::Lime << "\nHex: 0~4", true, 2, Appearance[2], Appearance[2]))
						goto Part2;
					break;
				}
				case 6: //Custom Animation
					SetUpKB("Enter the ID of a custom animation." << Color::Lime << "\nHex: D~E2" << Color::Magenta << "\nOperation button = " << Color::Green << "ON" << Color::White << "/" << Color::Red << "OFF", true, 2, C_AnimID, C_AnimID);
					break;
				default:
					break;
			}
		}
		if(entry->Hotkeys[1].IsPressed()) 
		{	
			switch(Mode) 
			{
				case 0:
					EnablingC = false;
					Index = Mode;
					Mode++;
					OSD::Notify("Animation Mode", Color::Red);
					break;
				case 1:
					Index = Mode;
					Mode++;
					OSD::Notify("Tool Mode", Color::Orange);
					break;
				case 2:
					Index = Mode;
					Mode++;
					OSD::Notify("Snake Mode", Color::Yellow);
					break;
				case 3:
					Index = Mode;
					Mode++;
					OSD::Notify("Emotion Mode", Color::LimeGreen);
					break;
				case 4:
					Index = Mode;
					Mode++;
					OSD::Notify("Sound Mode", Color::Green);
					break;
				case 5:
					Index = Mode;
					Mode++;
					OSD::Notify("Appearance Mode", Color::DeepSkyBlue);
					break;
				case 6:
					Index = Mode;
					Mode = 0;
					OSD::Notify("Custom Anim Mode", Color::Purple);
					break;
				default: 
					break;
			}
		}
		if(entry->Hotkeys[2].IsPressed())
		{
			Enabling = !Enabling;
			OSD::Notify("Anim Mod:" + (Enabling ? Color::Green << "ON" : Color::Red << "OFF"));
		}
		if(entry->Hotkeys[3].IsPressed())
		{
			Player::GetWorldCoords(&wX, &wY, Player::GetActualPlayerIndex());
		}
		if((Turbo ? entry->Hotkeys[3].IsDown() : entry->Hotkeys[3].IsPressed()) && !Player::InLoadingState() && !Button && Enabling && !MapEditorActive)
		{
			AnimExecuting = true;
			switch(Index)
			{
				case 0: //Animation
					if(!IDList::AnimValid(AnimID))
						return;

					if(AnimID == 0xFF)
						Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0x71, CatchRdm, 0, 0, 0, 0, wX + offsetX, wY + offsetY, false, 0); 
					else
						Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, AnimID, 0, 0, 0, SoundID, 0, wX + offsetX, wY + offsetY, false, 0);
					break;
				case 1: //Tool
					if(!IDList::ToolValid(ToolID))
						return;

					if(ToolID == 0xFFFF)
						Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0x38, ToolRdm, 0, 0, 0, 0, wX + offsetX, wY + offsetY, false, 0);
					else
						Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0x38, ToolID, 0, 0, 0, 0, wX + offsetX, wY + offsetY, false, 0);
					break;
				case 2: //Snake
					if(!IDList::SnakeValid(SnakeID))
						return;

					if(!IDList::ToolValid(ToolID))
						AnimItem = 0x2001;
					else
						AnimItem = ToolID;

					Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0xC5, AnimItem, 0, SnakeID, 0, 0, wX + offsetX, wY + offsetY, false, 0);
					break;
				case 3: //Emotion
					if(!IDList::EmotionValid(EmotionID))
						return;

					if(!IDList::ToolValid(ToolID))
						AnimItem = 0x2001;
					else
						AnimItem = ToolID;
					
					if(EmotionID == 0xFF)
						Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0xAF, AnimItem, EmotionRdm, 0, 0, 0, wX + offsetX, wY + offsetY, false, 0);
					else
						Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0xAF, AnimItem, EmotionID, 0, 0, 0, wX + offsetX, wY + offsetY, false, 0);
					break;
				case 4: //Sound
					if(!IDList::SoundValid(SoundID))
						return;

					if(!IDList::ToolValid(ToolID))
						AnimItem = 0x2001;
					else
						AnimItem = ToolID;
					
					if(SoundID == 0xFFFF)
						Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0xC4, AnimItem, 0, 0, SoundRdm, 0, wX + offsetX, wY + offsetY, false, 0); 
					else
						Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0xC4, AnimItem, 0, 0, SoundID, 0, wX + offsetX, wY + offsetY, false, 0);
					Sleep(Milliseconds(50));
					Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 6, 0, 0, 0, 0, 0, false, 0);
					break;
				case 5: //Appearance
					if(Appearance[0] > 0x21 || Appearance[1] > 0xF || Appearance[2] > 4)
						return;
					
					Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 0xB9, 0, 0, 0, 0, 0, wX + offsetX, wY + offsetY, false, Appearance);
					Sleep(Seconds(2));
					Animation::ExecuteAnimationWrapper(Player::GetOnlinePlayerIndex() & 3, 6, 0, 0, 0, 0, 0, false, 0);
					break;
				case 6: //Custom Animation					
					EnablingC = !EnablingC;

					if(EnablingC && IDList::CustomAnimValid(C_AnimID))
						OSD::Notify("Custom Animation:" << Color::Green << "ON");
					else
					{
						u32 val;
						Process::Read32(0x64DCB0, val); //0x64CCE8 EUR
						val = (val >> 8) & 0xFFFFFF;

						if(val == 0xE3A050) // Only if custom animation was enabled
							OSD::Notify("Custom Animation:" << Color::Red << "OFF");
						
						Process::Patch(0x64DCB0, 0xE1A02005); //Disable Custom Animation
						EnablingC = false;
					}	
					Button = true;
					break;
				default: 
					break;
			}
			if(Controller::IsKeyDown(Key::CPadRight)) offsetX++;
			if(Controller::IsKeyDown(Key::CPadLeft)) offsetX--;
			if(Controller::IsKeyDown(Key::CPadDown)) offsetY++;
			if(Controller::IsKeyDown(Key::CPadUp)) offsetY--;
		}
		else
		{
			AnimExecuting = false;
			offsetX = 0;
			offsetY = 0;
		}

		if(Enabling && EnablingC && IDList::CustomAnimValid(C_AnimID) && (Index == 6))
			Process::Patch(0x64DCB0, 0xE3A05000 + C_AnimID); // Enable Custom Animation
		else
		{
			Process::Patch(0x64DCB0, 0xE1A02005); // Disable Custom Animation
			EnablingC = false;
		}	

		if(!entry->Hotkeys[3].IsDown())
			Button = false;

		if(!entry->IsActivated() || Player::InLoadingState())
			Process::Patch(0x64DCB0, 0xE1A02005); // Disable Custom Animation
	}

	void	ForceAnimationsToOthers(MenuEntry *entry)
	{
		u16 CatchRdm = Utils::Random(0x228E, 0x234B);
		u16 ToolRdm = Utils::Random(0x334C, 0x3383);
		u8 EmotionRdm = Utils::Random(1, 0x40);
		u16 SoundRdm = Utils::Random(0x500, 0xE50);
		u8 DATAIndexRandom = Utils::Random(0, 3);
		u32 wX, wY;
		
		if(entry->Hotkeys[0].IsPressed()) 
			Player::GetWorldCoords(&wX, &wY);
		
		if((Turbo ? entry->Hotkeys[0].IsDown() : entry->Hotkeys[0].IsPressed()) && !Player::InLoadingState())
		{		
			for(u8 i = 0; i < 4; i++)
			{
				switch(Index)
				{
					case 0: //Animation
						if(!IDList::AnimValid(AnimID))
							return;

						if(AnimID == 0xFF)
							Animation::ExecuteAnimationWrapper(i, 0x71, CatchRdm, 0, 0, 0, 0, wX, wY, true, 0); 
						else
							Animation::ExecuteAnimationWrapper(i, AnimID, 0, 0, 0, SoundID, 0, wX, wY, true, 0);
						break;
					case 1: //Tool
						if(!IDList::ToolValid(ToolID))
							return;

						if(ToolID == 0xFFFF)
							Animation::ExecuteAnimationWrapper(i, 0x38, ToolRdm, 0, 0, 0, 0, wX, wY, true, 0);
						else
							Animation::ExecuteAnimationWrapper(i, 0x38, ToolID, 0, 0, 0, 0, wX, wY, true, 0);
						break;
					case 2: //Snake
						if(!IDList::SnakeValid(SnakeID))
							return;

						if(!IDList::ToolValid(ToolID))
							AnimItem = 0x2001;
						else
							AnimItem = ToolID;

						Animation::ExecuteAnimationWrapper(i, 0xC5, AnimItem, 0, SnakeID, 0, 0, wX, wY, true, 0);
						break;
					case 3: //Emotion
						if(!IDList::EmotionValid(EmotionID))
							return;

						if(!IDList::ToolValid(ToolID))
							AnimItem = 0x2001;
						else
							AnimItem = ToolID;
					
						if(EmotionID == 0xFF)
							Animation::ExecuteAnimationWrapper(i, 0xAF, AnimItem, EmotionRdm, 0, 0, 0, wX, wY, true, 0);
						else
							Animation::ExecuteAnimationWrapper(i, 0xAF, AnimItem, EmotionID, 0, 0, 0, wX, wY, true, 0);
						break;
					case 4: //Sound
						if(!IDList::SoundValid(SoundID))
							return;

						if(!IDList::ToolValid(ToolID))
							AnimItem = 0x2001;
						else
							AnimItem = ToolID;
					
						if(SoundID == 0xFFFF)
							Animation::ExecuteAnimationWrapper(i, 0xC4, AnimItem, 0, 0, SoundRdm, 0, wX, wY, true, 0); 
						else
							Animation::ExecuteAnimationWrapper(i, 0xC4, AnimItem, 0, 0, SoundID, 0, wX, wY, true, 0);
						Sleep(Milliseconds(70));
						Animation::ExecuteAnimationWrapper(i, 6, 0, 0, 0, 0, 0, wX, wY, true, 0);
						break;
					case 5: //Appearance
						Animation::ExecuteAnimationWrapper(i, 0xB9, 0, 0, 0, 0, 0, wX, wY, true, Appearance);
						Sleep(Seconds(2));
						Animation::ExecuteAnimationWrapper(i, 6, 0, 0, 0, 0, 0, wX, wY, true, 0);
						break;
					default: 
						break;
				}
			}
		}
		
		if((Turbo ? entry->Hotkeys[1].IsDown() : entry->Hotkeys[1].IsPressed()) && !Player::InLoadingState())
		{
			u32 x, y;
			if(Player::GetWorldCoords(&x, &y))
			{
				for(u8 i = 0; i < 4; i++)
					Animation::ExecuteAnimationWrapper(i, 6, 0, 0, 0, 0, 0, x, y, true, 0);
			}
		}
		
		if(entry->Hotkeys[2].IsDown())
		{
			if(!Player::InLoadingState())
				return;

			u32 PlayerInstance = Player::GetOffset();
			u32 AnimInstance;

			Process::Write32(0x677504, 0xE1A00000); //0x67653C EUR
			Process::Write32(0x628B54, 0xE3A01000 + DATAIndexRandom); //0x627B8C EUR
			
			for(u8 i = 0; i < 4; i++)
			{
				AnimInstance = Player::GetAnimationInstance(PlayerInstance, 0, 0, 0);
        		Animation::DoMoonJump(AnimInstance, PlayerInstance);
				
				if(i == Player::GetActualPlayerIndex())
					Animation::ExecuteAnimation(PlayerInstance, 0xC4, AnimInstance);
				else 
					Animation::SendPacket(i, AnimInstance, 0xC4, Player::ActualRoom(i), i);
			}
        } 
		if(!entry->Hotkeys[2].IsDown())
		{
            Process::Write32(0x677504, 0x1A000017);
			Process::Write32(0x628B54, 0xE5D11268);
		}
	}

	void    InfiniteExpression(MenuEntry *entry) //Only visible by you?
    {
        if(entry->IsActivated())
			Process::Patch(0x65E9B0, 0xE3A010FF); //0x65D9E8 EUR
		else if(!entry->IsActivated())
			Process::Patch(0x65E9B0, 0xE1D010B0);
	}

	void	SlowMotionAnim(MenuEntry *entry)
	{
		if(!System::IsCitra) // can crash on citra
		{
			if(entry->WasJustActivated())
			{
				Process::WriteFloat(0x652C10, 8.0); //0x651C48 EUR
				Process::WriteFloat(0x887880, 6.0); //0x88670C EUR
				Process::Patch(0x654578, 0xE3A00001); //0x6535B0 EUR
			}
			if(!entry->IsActivated())
			{
				Process::WriteFloat(0x652C10, 1.0);
				Process::WriteFloat(0x887880, 1.0);
				Process::Patch(0x654578, 0x0A000004);
        	}
		}
	}

	u32 AntiAnimCheck(u32 pID)
	{
	    u32 PlayerInstance = Player::GetOffset(pID, 0);
	    if(PlayerInstance == Player::GetOffset(4, 0))
		    return 0;

	    return PlayerInstance; 
	}

	void	AntiAnimation(MenuEntry *entry) 
	{ 
		static Hook h;
		if(entry->WasJustActivated())
		{	
			h.Initialize(0x6786D4, (u32)AntiAnimCheck); //0x67770C EUR
			h.SetFlags(USE_LR_TO_RETURN);
			h.Enable();
			IfForceAllowed = false;
		}
		if(!entry->IsActivated())
		{
			h.Disable();
			IfForceAllowed = true;
        }
	}

	void    NPCMenu(MenuEntry *entry)
	{
		static std::string SelectedNPCname = "";

		if(entry->WasJustActivated()) 
		{
			if(NPCIndex == NPCMode)
			{
				NPCIndex = 0;
				NPCMode = 1;
				OSD::Notify("NPC Animation Mode", Color::Red);
			}
		}
		if(entry->Hotkeys[0].IsPressed() && !Player::InLoadingState())
		{
			s8 uchoice = OpenList(Color::Yellow << "NPCs Menu", NpcOpt);
			switch(uchoice)
			{
				case 0:
				{
					switch(NPCIndex)
					{
						case 0: //Animation
							SetUpKB("Enter the ID of an animation." << Color::Lime << "\nHex: 0~EB", true, 2, NPC_Anim, NPC_Anim);
							break;
						case 1: //Tool
							SetUpKB("Enter the ID of a tool." << Color::Lime << "\nHex: 334C~33A6 & 3729\nRandom tools = FFFF", true, 4, NPC_AnimItem, NPC_AnimItem);
							break;
						case 2: //Snake
							SetUpKB("Enter the ID of a snake animation." << Color::Lime << "\nHex: 1~275", true, 3, NPC_Snake, NPC_Snake); // onSnakeChange
							break;
						case 3: //Emotion
							SetUpKB("Enter the ID of an emotion." << Color::Lime << "\nHex: 1~40\nRandom emotion = FF", true, 2, NPC_Emotion, NPC_Emotion);
							break;
						default:
							break;
					}
					break;
				}
				case 1:
				{
					NPC_DataVector NPCList;
					StringVector NPCLoadedList;

					NPC::GetLoadedNPC(NPCList);

					if(NPCList.empty())
					{
						MessageBox("Error!", "No NPCs are currently loaded!")();
						return;
					}

					for(NPC_Data& str : NPCList) // Add all loaded npcs into a list
						NPCLoadedList.push_back(str.name);

					s8 selectednpc = OpenList("Select Loaded NPC:", NPCLoadedList); // Open the loaded npcs list
					if(selectednpc < 0)
						return;

					CurrentNPCAddress = NPCList[selectednpc].data;
					SelectedNPCname = NPCList[selectednpc].name;

					OSD::Notify(Utils::Format("%s selected!", SelectedNPCname.c_str()));
					break;
				}
				case 2:
				{
					switch(NPCMode) 
					{
						case 0:
							NPCIndex = NPCMode;
							NPCMode++;
							OSD::Notify("NPC Animation Mode", Color::Red);
							break;
						case 1:
							NPCIndex = NPCMode;
							NPCMode++;
							OSD::Notify("NPC Tool Mode", Color::Orange);
							break;
						case 2:
							NPCIndex = NPCMode;
							NPCMode++;
							OSD::Notify("NPC Snake Mode", Color::Yellow);
							break;
						case 3:
							NPCIndex = NPCMode;
							NPCMode = 0;
							OSD::Notify("NPC Emotion Mode", Color::LimeGreen);
							break;
						default: 
							break;
					}
					break;
				}
				case 3:
				case 4:
				{
					if(CurrentNPCAddress == 0)
					{
						OSD::Notify("No NPC selected!", Color::Orange);
						return;
					}

					float *NPCCoords = (float *)(CurrentNPCAddress + 0x14);
					float *Coords = Player::GetCoordinates();
					if(NPCCoords == nullptr || Coords == nullptr)
						return;
					
					if(uchoice == 3)
					{
						NPCCoords[0] = Coords[0];
						NPCCoords[1] = Coords[1];
						NPCCoords[2] = Coords[2];
					}
					else
					{
						Coords[0] = NPCCoords[0];
						Coords[1] = NPCCoords[1];
						Coords[2] = NPCCoords[2];
					}
					OSD::Notify(Utils::Format((uchoice == 3) ? "%s teleported to you!" : "Teleported to %s!", SelectedNPCname.c_str()));
					break;
				}
				default:
					break;
			}
		}
	}

	void    NPCAnimationExecuter(MenuEntry *entry)
	{
		if(Player::InLoadingState())
			return;

		if(entry->Hotkeys[0].IsPressed() && (CurrentNPCAddress == 0))
			OSD::Notify("No NPC selected!", Color::Orange);
		
		if(entry->Hotkeys[0].IsPressed() && (NPCIndex == 0))
		{
			NPC::AnimationExecuter(NPCIndex, CurrentNPCAddress, 0, NPC_AnimItem, NPC_Snake, NPC_Emotion); //Restore Movements
			Sleep(Milliseconds(100));
		}
		if(Turbo ? entry->Hotkeys[0].IsDown() : entry->Hotkeys[0].IsPressed())
			NPC::AnimationExecuter(NPCIndex, CurrentNPCAddress, NPC_Anim, NPC_AnimItem, NPC_Snake, NPC_Emotion);
	}

	void	NPCCoordinates(MenuEntry *entry)
	{
		if(Player::InLoadingState() || (CurrentNPCAddress == 0))
			return;

		float *NPCCoords = (float *)(CurrentNPCAddress + 0x14);
		if(NPCCoords != nullptr && !MapEditorActive)
		{
			if(entry->Hotkeys[0].IsDown()) //DPadUp
				NPCCoords[2] -= NPC_CoordSpeed;
			if(entry->Hotkeys[1].IsDown()) //DPadDown
				NPCCoords[2] += NPC_CoordSpeed;
			if(entry->Hotkeys[2].IsDown()) //DPadLeft
				NPCCoords[0] -= NPC_CoordSpeed;
			if(entry->Hotkeys[3].IsDown()) //DPadRight
				NPCCoords[0] += NPC_CoordSpeed;
		}
	}

	void	SetNPCCoordSpeed(MenuEntry *entry)
	{
		SetUpKB("Enter the speed you want to use:", false, 4, NPC_CoordSpeed, NPC_CoordSpeed);
	}

	/*
	Environnement Codes
	*/

    void	BuildingMod(MenuEntry *entry)
	{
		if(Player::InLoadingState())
		{
			MessageBox(Color::Red << "Error", Color::White << "Your player need to be loaded.").SetClear(ClearScreen::Top)();
			return;
		}
		
		if(Game::GetOnlinePlayerCount() != 0)
		{
			MessageBox(Color::Red << "Error", Color::White << "You need to be offline.").SetClear(ClearScreen::Top)();
			return;
		}

		s8 uchoice = OpenList("Choose an option:", BuildingOpt);
		switch(uchoice) 
		{
			case 0:
				Game::PlaceBuilding();
				break;
			case 1:
				Game::MoveBuilding();
				break;
			case 2:
				Game::RemoveBuilding();
				break;
			default: 
				break;
		}
	}

	//OSD for Map Editor
	bool	MapDraw(const Screen &screen)
	{
		TownSaveData *Town = Game::GetTownSaveData();

		if(!screen.IsTop && Game::MapBool() && Town)
		{
			switch(Player::ActualRoom())
			{
				case 0:
					for(u8 j = 0; j < 5; j++)
					{
						for(u8 i = 0; i < 7; i++)
						{
							//screen.DrawSysfont(ShowT_AcreID[j][i], TownArceID_XPos[i], TownArceID_YPos[j], Color::Black); // Show ID, cause some lags
							screen.DrawRect(TownRect_XPos[i], TownRect_YPos[j], 36, 36, Color::Black, false);
						}
					}
					break;
				/*case 0x68:
					for(u8 j = 0; j < 4; j++)
					{
						for(u8 i = 0; i < 4; i++)
						{
							ShowI_AcreID[j][i] = (Utils::Format("%02X", Town->IslandAcres[IslandAddage[j] + i])); //need changes
							screen.DrawSysfont(ShowI_AcreID[j][i], IslandArceID_XPos[i], IslandArceID_YPos[j], Color::Black);
							screen.DrawRect(IslandRect_XPos[i], IslandRect_YPos[j], 43, 43, Color::Black, false);
						}
					}
					break;*/
				default:
					break;
			}
		}
		return true;
    }

	void	AcresEditor(MenuEntry *entry)
	{
		TownSaveData *Town = Game::GetTownSaveData();
		if(Game::MapBool() && Controller::IsKeyPressed(Key::Touchpad) && Town && (Game::GetOnlinePlayerCount() == 0))
		{
			u8 Acre = 0;

			switch(Player::ActualRoom())
			{
				case 0:
					for(u8 j = 0; j < 5; j++)
					{
						for(u8 i = 0; i < 7; i++)
						{
							UIntRect rec(TownRect_XPos[i], TownRect_YPos[j], 36, 36);
							Acre++;

							if(!rec.Contains(Touch::GetPosition()))
								continue;

							u8 AcreID = 0;
							ShowT_AcreID[j][i] = (Utils::Format("%02X", Town->TownAcres[TownAddage[j] + i]));
							if(!SetUpKBNo(Color::Lime << Utils::Format("Acre selected:%d", Acre) << Color::White << " | " << Color::Magenta << "Acre ID:" << ShowT_AcreID[j][i], true, 2, AcreID))
								return;
							
							Town->TownAcres[TownAddage[j] + i] = AcreID;
							OSD::Notify("Save and quit your game to see your changes!");
						}
					}
					break;
				case 0x68:
					break;
				default:
					break;
			}
		}
		
		if(entry->IsActivated() && (Game::GetOnlinePlayerCount() == 0))
			OSD::Run(MapDraw);
		else
			OSD::Stop(MapDraw);
	}

	void    WeatherMod(MenuEntry *entry)
    {
		constexpr u32 value = 0xE3A00000;

		s8 uchoice = OpenList("Choose the weather you want.", WeatherOpt);
		if(uchoice < 0)
			return;

		if(uchoice == 7)
		{
			Process::Patch(USA_Weather_Address, 0xE1A00004);
			return;
		}
			
		Process::Patch(USA_Weather_Address, value + uchoice);
		OSD::Notify("Meteo:" + WeatherOpt[uchoice]);
		WeatherMod(entry);
	}

    void	SeasonMod(MenuEntry *entry)
    {
		const u32 value = 0xE3A01002;
		const u8 offsets[4] = {0, 1, 5, 0x10};

		s8 uchoice = OpenList("Choose the season you want.", SaisonsOpt);
		if(uchoice < 0)
			return;
		
		Process::Patch(USA_Saison_Address, value + offsets[uchoice]);
		OSD::Notify("Season:" + SaisonsOpt[uchoice]);

		Game::AskReloadRoom();
    }

	void	FestivalMod(MenuEntry *entry)
	{
		const u16 Festivals[5] = {0x3C04, 0x4004, 0x3F04, 0x3D44, 0x3EC4};

		s8 uchoice = OpenList("Choose the festival you want.", FestivalsOpt);
		if(uchoice < 0)
			return;

		if(*(u16 *)USA_Festival_Address == 0)
		{
			OSD::Notify("There actually is no festival!");
			return;
		}

		Process::Patch(USA_Festival_Address, 0x9B0000 + Festivals[uchoice]);
		OSD::Notify("Festival:" << Color::Lime << FestivalsOpt[uchoice]);

		Game::AskReloadRoom();
	}

	void    MainStreetShopOpen(MenuEntry *entry)
	{
		const u32 Addresses[9] = 
		{
			USA_OpenReTail_Address,
			USA_OpenNookling_Address, 
			USA_OpenGarden_Address, 
			USA_OpenAbles_Address, 
			USA_OpenShampoodle_Address, 
			USA_OpenKicks_Address, 
			USA_OpenNooks_Address, 
			USA_OpenKatrina_Address, 
			USA_OpenRedd_Address,
		};

		const u32 value = 0xE3A00000;
		if (entry->WasJustActivated())
		{
			s8 byte = 1;

			for (u8 i = 0; i < 9; i++)
				Process::Patch(Addresses[i], value|(byte&1));
		}
		if (!entry->IsActivated())
		{
			s8 byte = 0;

			for (u8 i = 0; i < 9; i++) 
				Process::Patch(Addresses[i], value|(byte&1));
		}
	}

	void    MainStreetShopUnlock(MenuEntry *entry)
    {
        const u16 offsets[6] = {0x45C8, 0x8A58, 0x8B1E, 0x8B3E, 0x8B40, 0x8B50}; 

        StringVector list =
        {
            "Débloquer",
            "Bloquer",
        };

		s8 uchoice = OpenList("", list);
        switch(uchoice) 
		{
			case 0:
        	{
				Process::Write8(USA_Shop_Address + offsets[0], 2);
				Process::Write8(USA_Shop_Address + offsets[1], 1);
				Process::Write8(USA_Shop_Address + offsets[2], 2);
				Process::Write8(USA_Shop_Address + offsets[3], 1);
				Process::Write8(USA_Shop_Address + offsets[4], 1);
				Process::Write8(USA_Shop_Address + offsets[5], 2);
				OSD::Notify("MainStreet Shops:" << Color::Green << "Unlocked");
				break;
        	}
			case 1:
        	{
				for (u8 i = 0; i < 6; i++)
					Process::Write8(USA_Shop_Address + offsets[i], 0);
				OSD::Notify("MainStreet Shops:" << Color::Red << "Locked");
				break;
        	}
			default: 
				break;
		}
    }

    void    NookAmeliorations(MenuEntry *entry)
    {
		s8 uchoice = OpenList("", NooklingOpt);
		if(uchoice < 0)
			return;
		
		Process::Write16(USA_Shop_Address, 0x0101 * uchoice);
        Process::Write8(USA_Shop_Address + 0x4490, uchoice == 1 ? 2 : uchoice);
    }

	/*
	Island Codes
	*/

	void	IslandItemsSaves(MenuEntry *entry)
    {
		if(entry->Hotkeys[0].IsPressed())
        {
			if(Player::InLoadingState())
				return;

			if(!Player::IsInRoom(0x68))
			{
				OSD::Notify(Color::Orange << "You are not on the island!");
				return;
			}

			s8 uchoice = OpenList("Choose an option:" << Color::Yellow << "\n\nIsland Items Saves", IslandItemsOpt);
			switch(uchoice)
			{
				case 0:
				{
					if(Game::GetMapItemsCount(false))
					{
						if(!IslandItems.empty())
						IslandItems.clear();
	
						IslandItems = Game::GetMapItems(true);
						OSD::Notify(Color::Magenta << "Ctrl+C");
					}
					else
						OSD::Notify(Color::Yellow << "This island is empty!");
					break;
				}
				case 1:
				{
					if(IslandItems.empty())
					{
						OSD::Notify(Color::Yellow << "There is nothing to past!");
						return;
					}

					u32 X = 0x10, Y = 0x10, Count = 0;
                    s32 i = -1;
                    bool Check = true;

                    Sleep(Milliseconds(500));
                    Process::Patch(USA_ByPassItemDrop1_Address, 0xE3E00000); //0x5A0210 EUR
					Process::Patch(USA_ByPassItemDrop2_Address, 0xEA000012); //0x5A0214 EUR
					Process::Patch(USA_ByPassItemDrop3_Address, 0xE3A00000); //0x5A0410 EUR
					Process::Patch(USA_ByPassItemDrop4_Address, 0xE8BD83F0); //0x5A0414 EUR
                    while(Check)
                    {
                        while(Check)
                        {
                            if((u32)Items::GetItemAtWorldCoords(X, Y))
                            {  
                                if(i != IslandItems.size())
                                    i++;

                                if(*Items::GetItemAtWorldCoords(X, Y) == 0x80007FFE)
                                    Items::TrampleAt(X, Y);

                                if(Items::GetLockedSpotIndex(X, Y) != 0xFFFFFFFF)
                                    Items::ClearLockedSpot(X, Y, 0xA5);

                                if(*Items::GetItemAtWorldCoords(X, Y) != IslandItems.at(i))
                                {
                                    if(Items::PlaceItemWrapper(0x1, 0xFFFFFFFF, &IslandItems.at(i), &IslandItems.at(i), X, Y, 0, 0, 0, 0, 0, 0x3D, 0xA5))
                                        Count++;
                                }
                            }
                            else
								Check = false;
                            Y++;
                        }
                        Check = true;
                        Y = 0x10;
                        X++;
                        if(!(u32)Items::GetItemAtWorldCoords(X, Y))
                            Check = false;
                    }
                    if(ByPassing == false)
					{
						Process::Patch(USA_ByPassItemDrop1_Address, 0xE1A05001);
						Process::Patch(USA_ByPassItemDrop2_Address, 0x1A000001);
						Process::Patch(USA_ByPassItemDrop3_Address, 0xE24DD01C);
						Process::Patch(USA_ByPassItemDrop4_Address, 0xE1A07001);
					}
					OSD::Notify(Color::Purple << "Ctrl+V");
					break;
				}
				case 2:
				{
					Directory Luna("Luna", true); //create the directory if it doesn't exist
					Directory dir("Luna/IslandSaves", true); //create the directory if it doesn't exist
	
					if(Game::GetMapItemsCount(false))
					{
						File IslandBackup;
	
						if(!IslandItems.empty())
							IslandItems.clear();
	
						IslandItems = Game::GetMapItems(true);
						
						std::string IslandName;
						if(SetUpKB("Name your backup." << Color::Yellow << "\n\nIsland Items Dumper", false, 20, IslandName, "", 0))
						{
							if(!File::Exists("Luna/IslandSaves/" + IslandName + ".bin"))
							{
								File::Create("Luna/IslandSaves/" + IslandName + ".bin");
								File::Open(IslandBackup, "Luna/IslandSaves/" + IslandName + ".bin", File::WRITE | File::SYNC);
	
								for(int i = 0; i != IslandItems.size(); i++)
									IslandBackup.Write(&IslandItems.at(i), 4);
	
								MessageBox("Created file at:\n" << Color::Yellow << "Luna/IslandSaves/" + IslandName + ".bin").SetClear(ClearScreen::Top)();
								IslandBackup.Close();
							}
							else
							{
								Sleep(Milliseconds(200));
								if(MessageBox(Color::Lime << IslandName + ".bin" << Color::White << " already exist!\n\n" << Color::Yellow << "Do you want to replace it?", DialogType::DialogYesNo)())
								{
									File::Open(IslandBackup, "Luna/IslandSaves/" + IslandName + ".bin", File::WRITE | File::SYNC);
	
									for(int i = 0; i != IslandItems.size(); i++)
										IslandBackup.Write(&IslandItems.at(i), 4);
	
									IslandBackup.Close();
	
									OSD::Notify("Updated file:" << Color::Lime << IslandName + ".bin");
								}
							}
						}
					}
					else
						OSD::Notify(Color::Yellow << "This island is empty!");
					break;
				}
				case 3:
				{
					Directory Luna("Luna", true); //create the directory if it doesn't exist
					Directory dir("Luna/IslandSaves", true); // create the directory if it doesn't exist
	
					StringVector IslandsList;
					Directory::Open(dir, "Luna/IslandSaves");
					dir.ListFiles(IslandsList, ".bin");
	
	
					if(IslandsList.empty())
					{
						OSD::Notify(Color::Yellow << "No backup is available!");
						dir.Close();
						return;
					}
	
					File IslandFile;
	
					Keyboard IslandListKB("Select the backup to restore.");
					IslandListKB.Populate(IslandsList);
	
					int User_Choice = IslandListKB.Open();
	
					if(User_Choice < 0)
						return;
	
					dir.OpenFile(IslandFile, IslandsList.at((size_t)User_Choice), File::READ | File::SYNC);
					IslandItems.clear();
					IslandItems.resize(1024);
	
					OSD::Notify(Color::DeepSkyBlue << "Loading...");
	
					for(int i = 0; i != IslandItems.size(); i++)
						IslandFile.Read(&IslandItems.at(i), 4);
	
					dir.Close();
					IslandFile.Close();
	
					u32 X = 0x10, Y = 0x10, Count = 0;
					s32 i = -1;
					bool Check = true;
	
					Sleep(Milliseconds(500));
					Process::Patch(USA_ByPassItemDrop1_Address, 0xE3E00000);
					Process::Patch(USA_ByPassItemDrop2_Address, 0xEA000012);
					Process::Patch(USA_ByPassItemDrop3_Address, 0xE3A00000);
					Process::Patch(USA_ByPassItemDrop4_Address, 0xE8BD83F0);
					while(Check)
					{
						while(Check)
						{
							if((u32)Items::GetItemAtWorldCoords(X, Y))
							{  
								if(i != IslandItems.size())
									i++;
	
								if(*Items::GetItemAtWorldCoords(X, Y) == 0x80007FFE)
									Items::TrampleAt(X, Y);
	
								if(Items::GetLockedSpotIndex(X, Y) != 0xFFFFFFFF)
									Items::ClearLockedSpot(X, Y, 0xA5);
	
								if(*Items::GetItemAtWorldCoords(X, Y) != IslandItems.at(i))
								{
									if(Items::PlaceItemWrapper(0x1, 0xFFFFFFFF, &IslandItems.at(i), &IslandItems.at(i), X, Y, 0, 0, 0, 0, 0, 0x3D, 0xA5))
										Count++;
								}
							}
							else
								Check = false;
							Y++;
						}
						Check = true;
						Y = 0x10;
						X++;
						if(!(u32)Items::GetItemAtWorldCoords(X, Y))
							Check = false;
					}
					if(ByPassing == false)
					{
						Process::Patch(USA_ByPassItemDrop1_Address, 0xE1A05001);
						Process::Patch(USA_ByPassItemDrop2_Address, 0x1A000001);
						Process::Patch(USA_ByPassItemDrop3_Address, 0xE24DD01C);
						Process::Patch(USA_ByPassItemDrop4_Address, 0xE1A07001);
					}
					OSD::Notify("Readed file:" << Color::Lime << IslandsList.at((size_t)User_Choice));
					break;
				}
				default:
					break;
			}
		}
	}

	void	OnlineIslandAcresCreator(MenuEntry *entry)
	{
		if(entry->IsActivated())
		{
			for(u8 i = 0; i < 16; i++) 
				Process::Write8(USA_Island_Address + 2 + i * 2, CustomIslandAcres[i]);
			IslandAcresCreator = true;
		}
		else if(!entry->IsActivated())
			IslandAcresCreator = false;
	}

	void	ModelsCreator(MenuEntry* entry)
    {
		Keyboard IslArce("");
		IslArce.SetMaxLength(2);
		IslArce.IsHexadecimal(true);
		{
			for (u8 i = 0; i < 16; i++)
			{
				Sleep(Milliseconds(50));
				IslArce.GetMessage() = "Type the ID of an acre:" << Color::DeepSkyBlue << "\nAcre n°" << Utils::Format("%01X", (i+1));
				IslArce.Open(CustomIslandAcres[i], CustomIslandAcres[i]);
			}
		}
	}

	void	OnlineIslandAcresModel1(MenuEntry *entry)
	{
		const u8 IslandAcres[16] =
		{
			0xB2, 0x8B, 0x9B, 0xA9,
			0xA6, 0xCF, 0xCF, 0xBA,
			0xCF, 0xD2, 0xD2, 0x02,
			0x95, 0x31, 0x22, 0x9F
		};

		if(IslandAcresCreator) 
			entry->Disable();
		
		if(entry->IsActivated())
		{
			for(u8 i = 0; i < 16; i++) 
				Process::Write8(USA_Island_Address + 2 + i * 2, IslandAcres[i]);
		}
	}

	void	OnlineIslandAcresModel2(MenuEntry *entry)
	{
		const u8 IslandAcres[16] =
		{
			0xA4, 0x9E, 0x9F, 0xA1,
			0xA4, 0x03, 0x08, 0x6C,
			0xA6, 0x4A, 0x1B, 0x93,
			0xA7, 0x85, 0x7B, 0x5A
		};

		if(IslandAcresCreator) 
			entry->Disable();

		if(entry->IsActivated())
		{
			for(u8 i = 0; i < 16; i++) 
				Process::Write8(USA_Island_Address + 2 + i * 2, IslandAcres[i]);
		}
	}

	void    OnlineIslandBuildingMod(MenuEntry *entry)
	{
		if(entry->IsActivated())
		{
			for(u8 i = 0; i < 2; i++)
			{
				Process::Write16(USA_Island_Address + 0x1022 + (i * 4), isl.b[i].id);
				Process::Write8(USA_Island_Address + 0x1022 + 2 + (i * 4), isl.b[i].x);
				Process::Write8(USA_Island_Address + 0x1022 + 3 + (i * 4), isl.b[i].y);
			}
		}
	}

	void	OnIslandBuildingChange(Keyboard &k, KeyboardEvent &e)
	{
		std::string& s = k.GetInput();
		k.GetMessage() = "Enter ID of a building:\n\nID entered: " << IDList::GetBuildingName(s != "" ? std::stoi(s, nullptr, 16) : 0);
	}

	void    MenuOnlineIslandBuildingMod(MenuEntry *entry)
	{
		StringVector list =
	    {
	        "Building 1 options (Island Hut)",
	        "Building 2 options (Lloid)",
	    };

		StringVector list2 =
	    {
	        "Set building ID",
	        "Set coordinates",
	    };

		redo:
		s8 uchoice = OpenList("", list);
		if(uchoice < 0)
			return;
		s8 uchoice2 = OpenList("", list2);
		switch(uchoice2)
		{
			case 0:
			{
				SetUpKB("Enter ID of a building:\n\nID entered: ", true, 2, isl.b[uchoice].id, isl.b[uchoice].id, OnIslandBuildingChange);
			}
			break;
			case 1:
				AskX:
				SetUpKB("Entrer coordinates " << Color::Yellow << "\"X\"" << Color::White << " of building:", true, 2, isl.b[uchoice].x, isl.b[uchoice].x);
				if(!SetUpKB("Entrer coordinates " << Color::Yellow << "\"Y\"" << Color::White << " of building:", true, 2, isl.b[uchoice].y, isl.b[uchoice].y))
					goto AskX;
				break;
			
			default:
				goto redo;
				break;
		}
	}

	void    OnlineChangeItemsShopOnIsland(MenuEntry *entry)
	{
		if(*(u32 *)USA_IslandShop_Pointer == 0)
			return;
		
		if(Player::NextRoomCheck() == 0xA5 && Player::IsInRoom(0x65))
		{
			for(u8 i = 0; i < 4; i++)
			{
				Process::Write32(*(u32 *)USA_IslandShop_Pointer + 0x10 + (i * 4), IDList::ItemValid(ShopItem[i]) ? ShopItem[i] : 0x2083);
			}
		}
	}

	void	MenuOnlineChangeItemsShopOnIsland(MenuEntry *entry)
	{
		u16 ItemID;
		for(u8 i = 0; i < 4; i++)
		{
			if(!SetUpKBNo("Type the ID of the item you want." << Color::Lime << "\nHex: 0~7FFE", true, 4, ItemID))
				break;

			ShopItem[i] = ItemID;
		}
	}

	void    LloidIslandToolEditor(MenuEntry *entry)
    {
        u16 ItemID;
        StringVector list =
        {
            "Slot 1",
            "Slot 2",
		    "Slot 3",
		    "Slot 4",
		    "Slot 5",
		    "Slot 6",
		    "Slot 7",
		    "Slot 8",
        };

        s8 uchoice = OpenList("", list);
		if(uchoice < 0)
			return;
    
		if(!SetUpKBNo("Type the ID of the item you want." << Color::Lime << "\nHex: 0~7FFE", true, 4, ItemID))
			return;

		Process::Write32(0x986A10 + (uchoice * 4), ItemID); //0x985A10 EUR
		Process::Write32(0x33038E9C + (uchoice * 4), ItemID);
		OSD::Notify("Lloid " + list[uchoice] + ":" << Color::Lime << Utils::Format("%04X", ItemID));
	}

	void 	IslandRegionSpoofer(MenuEntry *entry)
	{
		const u8 CountryListID[10] = {0, 0x4D, 0x12, 0x6E, 0x31, 0x01, 0xA0, 0x41, 0x24, 0xFF};

		s8 uchoice = OpenList("Choose the island you want to go on.", CountryOpt);
		if(uchoice < 0)
			return;

		if(uchoice == 0)
			Process::Write32(0x350B18, 0xE1A00C20); //0x34FC60 EUR
		else
			Process::Write32(0x350B18, 0xE3A00000 + CountryListID[uchoice]);

		OSD::Notify("Country set to:" << Color::Lime << CountryOpt[uchoice]);
	}

	void    EnableAllTours(MenuEntry *entry)
    {
        if(entry->WasJustActivated()) 
		{
			Process::Patch(USA_Tours_Address, 0xE1A00000); //unsure? (still keeping it for safety)
			Process::Patch(USA_Tours_Address + 0x54, 0xE1A00000); //Adds tour difficulty
			Process::Patch(USA_Tours_Address + 0xD0, 0xE1A00000); //Adds tour names and tour infos
			Process::Patch(USA_Tours_Address + 0x138, 0xE1A00000); //Adds tour time
			Process::Patch(USA_Tours_Address + 0xA8, 0xE2800001); //Adds all tours to be selectable
		}
		else if(!entry->IsActivated()) 
		{
			Process::Patch(USA_Tours_Address, 0x0A000004);
			Process::Patch(USA_Tours_Address + 0x54, 0x0A000004);
			Process::Patch(USA_Tours_Address + 0xD0, 0x0A000004);
			Process::Patch(USA_Tours_Address + 0x138, 0x0A000004); 
			Process::Patch(USA_Tours_Address + 0xA8, 0x12800001);
		}
    }

	void	OreAndFruitsTours(MenuEntry *entry)
	{
		if(!Player::IsOnTour())
			return;
		
		s8 uchoice = OpenList("", ToursOpt);
		if(uchoice == 0)
		{
			for(int i = 0; i < 0x10; i++)
			{
				Player::WriteInventory(*(u16 *)USA_ToursGetNeeded_Address, i * 4);
			}
		}
		else if(uchoice == 1)
		{
			u8 index = Player::GetOnlinePlayerIndex() & 3;
			if (index <= 3 && index >= 0)
			{
				for (u8 i = 0; i < 3; i++)
				{
					for (u8 j = 0; j < 3; j++)
					{
						Player::WriteInventory(*(u16 *)(USA_ToursGetNeeded_Address + 2 * (index * 3 + i)), 4 * (i * 3 + j));
					}
				}
			}
		}
	}

	void	TourEnd(MenuEntry *entry)
    {
		if(Player::IsOnTour())
		{
        	Process::Write8(0x95171D, 1);
			MessageBox(Color::Green << "Success!", Color::White << "Note:" << Color::Yellow << "\nThe tour is over.").SetClear(ClearScreen::Top)();
		}
    }

	/*
	Keyboard / Chat Codes
	*/

	void	PlayerComming(MenuEntry *entry)
	{
  		std::string PlayerName;
  		std::string PlayerTown;
		Color PlayerColor;
  		u32 Address = 0;

  		for(u8 i = 0; i < 4; i++)
		{
    		Address = Player::GetSaveOffset(i);
    		if(Address == 0)
			{
      			if(!HasSet[i])
				{
        			pID[i] = 0;
        			HasSet[i] = true;
      			}
      			continue;
    		}

    		if(!HasSet[i])
			{
      			Process::Read16(Address + 0x55A6, pID[i]);
      			HasSet[i] = true;
    		}
    		else if(HasSet[i] && *(u16 *)(Address + 0x55A6) != pID[i])
			{
      			Process::ReadString(Address + 0x55A8, PlayerName, 16, StringFormat::Utf16);
	  			Process::ReadString(Address + 0x55BE, PlayerTown, 16, StringFormat::Utf16);

				switch(i)
				{
					case 0:
						PlayerColor = Color::Blue;
						break;
					case 1:
						PlayerColor = Color::Red;
						break;
					case 2:
						PlayerColor = Color::Green;
						break;
					case 3:
						PlayerColor = Color::Yellow;
						break;
					default:
						break;
				}

				if(!ControlPlayer)
      				OSD::Notify("Player " << PlayerColor << std::to_string(i) << Color::White << ":" << Color::Magenta << PlayerName << Color::White << " from " << Color::Magenta << PlayerTown << Color::White << " is here");
      			HasSet[i] = false;
    		}
  		}
	}

	void	UnlockCaracters(MenuEntry *entry)
	{
		if(entry->IsActivated() && Chat::IsOpen())
		{
			Process::Write8(0xAD75C0, 1);	//0xAD65C0 EUR
			Process::Write8(0xAD7253, 1);	//0xAD6253 EUR
		}
		else
		{
			Process::Write8(0xAD75C0, 0x40);
			Process::Write8(0xAD7253, 0);
		}
    }

	void	KeyboardExtender(MenuEntry *entry)
	{
		if(entry->IsActivated() && Chat::IsOpen())
		{
			u32 KbExtenderAddr = *(u32 *)USA_Chat_Pointer;
			if(KbExtenderAddr == 0)
				return;
			
            Process::Write8(KbExtenderAddr + 0xC, 0x41);
            Process::Write8(KbExtenderAddr + 0x12B, 0x44);
			KbExtender = true;
		}
		if(!entry->IsActivated())
		{
			KbExtender = false;
		}
    }

	void	CustomKeyboard(MenuEntry *entry)
    {
		const u16 Empty = 2;
        bool Enabling = false;

		if(entry->IsActivated())
		{
        	u32 KeyboardAddr = *(u32 *)USA_Keyboard_Pointer;
        	if(KeyboardAddr != 0 && !Enabling)
			{
            	Sleep(Seconds(0.25f));
            	u16 Layout[100] =
            	{
					//Empty
					Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                	Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,

					//Start Keyboard 1
					//Keyboard Line 1
					0xE000, 0xE001, 0xE002, 0xE003, 0xE004, 0xE005, 0xE006, 0xE077, 0xE056,
					//Keyboard Line 2
                	0xE008, 0xE009, 0xE06D, 0xE06E, 0xE007, 0xE019, 0xE01A, 0xE01B, 0xE01C,
					//Keyboard Line 3
                	0xE020, 0xE021, 0xE022, 0xE023, 0xE01E, 0xE03C, 0xE03D, 0xE06C, 0xE073,
					//Keyboard Line 4
                	0xE062, 0xE058, 0xE05D, 0xE017, 0xE015, 0xE016, 0xE018, 
					//Empty
					Empty, Empty,

					//Start MAJ Keyboard 1
					//Keyboard Line 1
                	0xE036, 0xE037, 0xE038, 0xE039, 0xE00D, 0xE070, 0xE071,
					//Keyboard Line 2
                	0xE040, 0xE042, 0xE043, 0xE04A, 0xE04B, 0xE045, 0xE046, 0xE047, 0xE048,
					//Keyboard Line 3
                	0xE04C, 0xE04D, 0xE04E, 0xE04F, 0xE052, 0xE053, 0xE067, 0xE075, 0xE00C,
					//Keyboard Line 4
                	0xFFFF, 0xE033, 0xE030, 0xE028, 0xE029, 0xE02A,
					//Empty
					Empty, Empty, Empty,

					//Start Keyboard 2
					SymbolID
				};
				KeyboardAddr = KeyboardAddr - 0xA8A; //Address
            	Process::Patch(KeyboardAddr, Layout, 0x6E * 2, nullptr);
            	Enabling = true;
        	}
        	else if(KeyboardAddr == 0)
            	Enabling = false;
        }
    }

	void	SetSymbolCustomKeyboard(MenuEntry *entry)
	{
		u16 SetSymbolID;
		SetUpKB("Enter ID of a symbol:" << Color::LimeGreen << "\nHex: E000~E07E" << Color::Yellow << "\n\nChanges the first symbol on page 2", true, 4, SetSymbolID, SymbolID);

		if(IDList::ValidID16(SetSymbolID, 0xE000, 0xE07E))
			SymbolID = SetSymbolID;
	}

	void    ChatSpam(MenuEntry *entry)
	{
		bool Readed = false;
		if(KbExtender) // Crash with Keyboard Extender
			entry->Disable();
		
		if(!Chat::IsOpen())
			return;

		std::string TextString;
		u32 ChatOffset = *(u32 *)((*(u32 *)USA_BaseInventory_Pointer) + 0xC) + 0x58; //Final address

		if(entry->Hotkeys[0].IsPressed() && !Readed) //Read msg
		{
			TextString = "";
			Process::WriteString(0x1E81300, TextString, StringFormat::Utf16); //Clear Storage
			Process::ReadString(ChatOffset, TextString, 0x80, StringFormat::Utf16); //Read In-Game Keyboard
			Process::WriteString(0x1E81300, TextString, StringFormat::Utf16); //Storing Value
			Readed = true;
		}
		if(entry->Hotkeys[0].IsDown()) //Write/Send msg
		{
			Process::ReadString(0x1E81300, TextString, 0x80, StringFormat::Utf16); //Read Stored Value
			Process::WriteString(ChatOffset, TextString, StringFormat::Utf16); //Write In-Game Keyboard
			Process::Write8(0x95F0E9, 1); //Send message
			Readed = false;
		}
    }

	/*
	Visual / Sound Codes
	*/

	void	EffectsMod(MenuEntry *entry)
    {
        
    }

	void	CameraMod(MenuEntry *entry)
    {
		static bool isOn = false;

		static const u16 OriginalVal[2] = { *(u16 *)(Camera::GetInstance() + 0x12C), *(u16 *)(Camera::GetInstance() + 0x12E) };
		
		static Clock time;
        Time delta = time.Restart();

        float speed = 400.0f * delta.AsSeconds() * CamSpeed;
        u16 difference = 0x1000 * delta.AsSeconds() * CamSpeed;

		float *coord = Camera::GetCoordinates();

		if(entry->WasJustActivated()) 
			Process::Patch(USA_CameraPan_Address, 0xE3A00000); //disables camera panning

		if(!entry->IsActivated() || MapEditorActive)
		{
			if(coord != nullptr)
				coord = Player::GetCoordinates();

			Animation::ExecuteAnimationWrapper(Player::GetActualPlayerIndex(), 6, 0, 0, 0, 0, 0, false, 0); //idles player
			Process::Patch(USA_ASM_Camera, 0x2A000020); //0x76350C EUR
			Process::Patch(USA_ASM_CameraRotation, 0xE18020B4); //0x1A3250 EUR
            Process::Write32(USA_ASM_CameraRotation + 0xC, 0xE18020B4);
			Process::Patch(USA_CameraPan_Address, 0xE3A00009); //0x1A2078 EUR
			*(u16 *)(Camera::GetInstance() + 0x12C) = OriginalVal[0];
			*(u16 *)(Camera::GetInstance() + 0x12E) = OriginalVal[1];
			return;
		}
	
        if(Camera::GetInstance() != 0)
		{
            if(!Player::IsIndoor()) //check if you're outside
			{
                if(Player::IsInRoom(1))
				{
                    Process::Patch(USA_ASM_CameraRotation, 0xE18020B4);
                    Process::Patch(USA_ASM_CameraRotation + 0xC, 0xE18020B4);
                }
                else
				{
                    Process::Patch(USA_ASM_CameraRotation, 0xE1A00000);
                    Process::Patch(USA_ASM_CameraRotation + 0xC, 0xE1A00000);
                }
            }
            else
			{
                Process::Patch(USA_ASM_CameraRotation, 0xE18020B4);
                Process::Patch(USA_ASM_CameraRotation + 0xC, 0xE18020B4);
            }
			
            if(entry->Hotkeys[0].IsDown()) //R
			{
                if(Controller::IsKeyDown(Key::CPadUp))
                    *(u16 *)(Camera::GetInstance() + 0x12C) += difference;
                if(Controller::IsKeyDown(Key::CPadDown))
                   *(u16 *)(Camera::GetInstance() + 0x12C) -= difference;
                if(Controller::IsKeyDown(Key::CPadLeft))
                    *(u16 *)(Camera::GetInstance() + 0x12E) += difference;
                if(Controller::IsKeyDown(Key::CPadRight))
                    *(u16 *)(Camera::GetInstance() + 0x12E) -= difference;
            }

			if(entry->Hotkeys[1].IsDown()) //B
			{
				if(Player::InLoadingState() || (coord == nullptr))
					return;

				if(Controller::IsKeyDown(Key::DPadUp))
				{
					coord[2] -= speed;
					goto patch;
				}

				if(Controller::IsKeyDown(Key::DPadRight))
				{
					coord[0] += speed;
					goto patch;
				}

				if(Controller::IsKeyDown(Key::DPadDown))
				{
					coord[2] += speed;
					goto patch;
				}

				if(Controller::IsKeyDown(Key::DPadLeft))
				{
					coord[0] -= speed;
					goto patch;
				}

				if(Controller::IsKeyDown(Key::L))
				{
					coord[1] -= speed;
					goto patch;
				}

				if(Controller::IsKeyDown(Key::R))
				{
					coord[1] += speed;
					goto patch;
				}
			}

			//Stop/follow camera from moving
            if(entry->Hotkeys[2].IsPressed()) //R+X
			{
				switch(CameraPatch)
				{
					case 0: goto patch;
					case 1: goto unpatch;
				}
			}
			
			//lock/unlock player
            if(entry->Hotkeys[3].IsPressed()) //R+Y
			{
				switch(isOn)
				{
					case 0: 
						OSD::Notify("Player:" << Color::Red << "Locked"); 
						Animation::ExecuteAnimationWrapper(Player::GetActualPlayerIndex(), 0xF, 0, 0, 0, 0, 0, false, 0);
						isOn = true;
					break;
					case 1: 
						OSD::Notify("Player:" << Color::Green << "Unlocked");
						Animation::ExecuteAnimationWrapper(Player::GetActualPlayerIndex(), 6, 0, 0, 0, 0, 0, false, 0);
						isOn = false;
					break;
				}
			}
            return;

        	patch:
            if(!CameraPatch)
			{
            	//disable camera following
				OSD::Notify("Camera following:" << Color::Red << "OFF");
                Process::Patch(USA_ASM_Camera, 0xEA000020);
                CameraPatch = true;
            }
            return;

        	unpatch:
            if(CameraPatch)
			{
				//reenable camera following
				OSD::Notify("Camera following:" << Color::Green << "ON");
                Process::Patch(USA_ASM_Camera, 0x2A000020);
                CameraPatch = false;
            }
        }
    }

	void	SetCameraModSpeed(MenuEntry *entry)
	{
		SetUpKB("Set speed for Camera Mod:" << Color::Magenta << "\nDefault: 1.0", false, 4, CamSpeed, CamSpeed);
	}

	void	DisableScreenshots(MenuEntry *entry)
    {
        if(entry->WasJustActivated())
            Process::Patch(0x5B41A8, 0xE3A00001);

        if(!entry->IsActivated())
            Process::Patch(0x5B41A8, 0xE3500000);
    }

	void	ChangeFOV(MenuEntry *entry)
	{
		static float OnOff = 1.0f;
		if(entry->IsActivated())
		{
			if(Player::IsInRoom(1) || Fov)
				OnOff = 1.0f;
			else 
				OnOff = FloatFov;
			
			Process::WriteFloat(0x47E48C, OnOff); //0x47D4D4 EUR
		}
		if(!entry->IsActivated()) 
			Process::WriteFloat(0x47E48C, 1.0f);
	}

	void	SetFOV(MenuEntry *entry)
	{
		float SetFloatFov;
		SetUpKB("Entre une ID:" << Color::Lime << "\nFloat: 0.70~1.00", false, 4, SetFloatFov, FloatFov);

		if(IDList::ValidIDFloat(SetFloatFov, 0.69f, 1.0f))
			FloatFov = SetFloatFov;
	}

	void	GameSpeed(MenuEntry *entry)
    {
    	if(entry->IsActivated())
			Process::Patch(0x54DDB4, Player::InLoadingState() ? 0xE59400A0 : 0xE3E004FF); //0x54CDFC EUR
		else if(!entry->IsActivated()) 
			Process::Patch(0x54DDB4, 0xE59400A0);
    }

	void	FastTalkNPC(MenuEntry *entry)
	{
    	if(entry->WasJustActivated())
		{
			Process::Patch(0x5FC6AC, 0xEA000000); //0x5FC6AC EUR
			Process::Patch(0x5FC6AC + 8, 0xE3500001);
		}
		else if(!entry->IsActivated())
		{
			Process::Patch(0x5FC6AC, 0xE1A00004);
			Process::Patch(0x5FC6AC + 8, 0xE3500000);
		}
	}

	void	AlwaysCherryBlossomTrees(MenuEntry *entry)
	{
		if(entry->WasJustActivated())
		{
			Process::Patch(0x296A64, 0xE3A00001);
			Process::Patch(0x296A8C, 0xE3A00001);
			Process::Patch(0x296AB4, 0xE3A00004);
			Process::Patch(0x296AC4, 0xE3A01001);
			Process::Patch(0x296ACC, 0xFF);
			Process::Patch(0x59ABEC, 0xE3A08005);
			Process::Patch(0x59AD3C, 0xE28F2074);
			Process::Patch(0x62FC30, 0xE3A00000);
		}
		else if(!entry->IsActivated())
		{
			Process::Patch(0x296A64, 0xE596000);
			Process::Patch(0x296A8C, 0xEB0E686A);
			Process::Patch(0x296AB4, 0xE5DD0004);
			Process::Patch(0x296AC4, 0xE2401007);
			Process::Patch(0x296ACC, 0x93A0003C);
			Process::Patch(0x59ABEC, 0xE1A08000);
			Process::Patch(0x59AD3C, 0xE28F206C);
			Process::Patch(0x62FC30, 0xE1A00004);
		}
	}

	void	TownBGMModifier(MenuEntry *entry)
	{
		static u8 BGM = 0;

		SetUpKB("Enter a music/sound ID:" << Color::Lime << "\nHex: 0~FF", true, 2, BGM, BGM);
		if(BGM < 0)
			return;
			
		if(!IDList::MusicValid(BGM))
			return;

        for(u32 i = 0x846784; i < 0x8468A0; i += 4)
            *(u8 *)i = BGM;
		OSD::Notify("Town BGM:" << Color::Lime << Utils::Format("%02X", BGM));
	}

	void	IslandHutBGMModifier(MenuEntry *entry)
	{
		static u8 BGM = 0;

		SetUpKB("Enter a music/sound ID:" << Color::Lime << "\nHex: 0~FF", true, 2, BGM, BGM);
		if(BGM < 0)
			return;

		if(!IDList::MusicValid(BGM))
			return;

        *(u8 *)0x815880 = BGM;
		OSD::Notify("Island hut BGM:" << Color::Lime << Utils::Format("%02X", BGM));

		if(Player::IsInRoom(0x67))
		{
			Game::AskReloadRoom();
		}
	}

	/*
	Player Codes
	*/

	void	ClearOrFillInvetory(MenuEntry *entry)
    {
		if(Player::InLoadingState())
		{
			MessageBox(Color::Red << "Error", Color::White << "Your player need to be loaded.").SetClear(ClearScreen::Top)();
			return;
		}

		u32 ID;
		u32 ClearOrFill[2] = {0x7FFE, ID};
        s8 uchoice = OpenList("", InvOpt);
        if(uchoice < 0)
            return;
        
        if(uchoice == 0)
            OSD::Notify("Inventory cleared!");
        else if(uchoice == 1)
        {
			if(!SetUpKBNo("Type the ID of the item you want.", true, 8, ClearOrFill[1]))
				return;
            OSD::Notify("Inventory filled!");
            OSD::Notify("ID:" << Color::Lime << Utils::Format("%08X", ClearOrFill[1]));
        }

		for(u8 i = 0; i < 16; i++)
			Player::WriteInventory(i, ClearOrFill[uchoice]);
    }

    void	MoneyMod(MenuEntry *entry)
    {
		if(Player::InLoadingState())
		{
			MessageBox(Color::Red << "Error", Color::White << "Your player need to be loaded.").SetClear(ClearScreen::Top)();
			return;
		}

		const u16 offsets[4] = {0x6F08, 0x6B8C, 0x8D1C, 0x6B9C};
		const u8 numbersmax[4] = {5, 9, 5, 5};

		s8 uchoice = OpenList("", MoneysOpt);
		if(uchoice < 0)
            return;

		u32 input = 0;
		if(!SetUpKBNo("", false, numbersmax[uchoice], input))
            return;

		Process::Write64(Player::GetSaveOffset() + offsets[uchoice], Game::EncryptACNLMoney(input));
    }

    void    PlayerOptionsMod(MenuEntry *entry)
	{
		if(Game::GetOnlinePlayerCount() != 0)
		{
			MessageBox(Color::Red << "Error", Color::White << "You need to be in solo.").SetClear(ClearScreen::Top)();
			return;
		}

		if(Player::InLoadingState())
		{
			MessageBox(Color::Red << "Error", Color::White << "Your player need to be loaded.").SetClear(ClearScreen::Top)();
			return;
		}

		StringVector HexList =
		{
			"\nHex: 0~21",
			"\nHex: 0~F",
			"\nHex: 0~B",
			"\nHex: 0~4",
		};

		ACNL_Player *PlayerSave = Player::GetSaveData();

		redo:
		u8 input;
		s8 uchoice = OpenList("Choose an option:" << Color::Red << "\nOFFLINE", PlayerOpt);
		if(uchoice < 0)
			return;

		if(uchoice < 4)
		{
			if(!SetUpKBNo("Type an ID:" << Color::Lime << HexList[uchoice], true, 2, input))
				goto redo;

			switch(uchoice)
			{
				case 0:
				{
					if(input <= 0x21)
						PlayerSave->PlayerFeatures.HairStyle = input;
					break;
				}
				case 1:
				{
					if(input <= 0xF)
						PlayerSave->PlayerFeatures.HairColor = input;
					break;
				}
				case 2:
				{
					if(input <= 0xB)
					{
						PlayerSave->PlayerFeatures.Face = input;
						Game::AskReloadRoom();
					}
					break;
				}
				case 3: 
				{
					if(input <= 4)
						PlayerSave->PlayerFeatures.EyeColor = input;
					break;
				}
			}
			Player::UpdateStyle();
		}
		else if(uchoice == 4)
		{
			if(!SetUpKBNo("Type an ID:" << Color::Lime << "\nHex: 0~F", true, 1, input) || (input > 0xF))
				goto redo;
			else if(input > 0xF)
				return;
			
			PlayerSave->PlayerFeatures.Tan = input;
			Player::UpdateTan();
		}
		else if(uchoice == 5)
		{
			s8 Genderchoice = OpenList("", GenderOpt);
			if(Genderchoice < 0)
				goto redo;
			
			Process::Write8(USA_Gender_Address, Genderchoice);
			Player::UpdateGender(Genderchoice);
                
            Game::AskReloadRoom();
		}
		else if(uchoice == 6)
		{
			s8 RegionChoice = OpenList("Country or Region?", RegionOpt);
			if(RegionChoice == 0)
			{
				if(!SetUpKBNo("Country ID:" << Color::Lime << "\nDec: 1~52", false, 2, input) || (input > 52))
					return;
				
				Process::Write8(Player::GetSaveOffset() + 0x55D2, input);
			}
			else if(RegionChoice == 1)
			{
				if(!SetUpKBNo("Region ID:" << Color::Lime << "\n(Depends on the country)", false, 2, input))
					return;
				
				Process::Write8(Player::GetSaveOffset() + 0x55D3, input);
			}
		}
		goto redo;
    }

	void    PlayerControllerTeleporter(MenuEntry *entry)
	{
		Color PlayerColor;
		Color sPlayerColor;
		if(entry->IsActivated())
		{
			switch(SelectedPlayerIndex)
			{
				case 0:
		    		PlayerColor = Color::Blue;
					break;
				case 1:
		    		PlayerColor = Color::Red;
					break;
				case 2:
		    		PlayerColor = Color::Green;
					break;
				case 3:
		    		PlayerColor = Color::Yellow;
					break;
			}

			switch(SelectedPlayerIndex)
			{
				case 0:
		    		sPlayerColor = Color::Red;
					break;
				case 1:
		    		sPlayerColor = Color::Green;
					break;
				case 2:
		    		sPlayerColor = Color::Yellow;
					break;
				case 3:
		    		sPlayerColor = Color::Blue;
					break;
			}
		}

		if(ControlPlayer) //reset bool
			ControlPlayer = false;

		if((entry->Hotkeys[0].IsPressed()))
        {
			if(*(u32 *)0x75F010 == 0xE1500000)
			{
				ControlPlayer = true;
				Process::Patch(0x75F010, 0xE3520000);
                Process::Write8(0x75F020, 0);
                OSD::Notify("Control player:" << Color::Red << "OFF");
			}
            SelectedPlayerIndex = (SelectedPlayerIndex + 1) % 4;
            OSD::Notify("Selected player:" << sPlayerColor << Utils::Format("%01X", SelectedPlayerIndex));
        }

        if(entry->Hotkeys[1].IsPressed())
        {
			ControlPlayer = true;
            if(*(u32 *)0x75F010 == 0xE3520000)
            {
				if(SelectedPlayerIndex == Player::GetActualPlayerIndex()) // Cannot control ourself x)
					return;

                Process::Patch(0x75F010, 0xE1500000);
                Process::Write8(0x75F020, SelectedPlayerIndex);
                OSD::Notify("Control player " << PlayerColor << Utils::Format("%01X", SelectedPlayerIndex) << Color::White << ":" << Color::Green << "ON");
            }
            else
            {
                Process::Patch(0x75F010, 0xE3520000);
                Process::Write8(0x75F020, 0);
                OSD::Notify("Control player:" << Color::Red << "OFF");
            }
        }

		if(entry->Hotkeys[2].IsPressed() && SelectedPlayerIndex != Player::GetActualPlayerIndex())
		{
			if((u32)Player::GetCoordinates(SelectedPlayerIndex) != 0 && (u32)Player::GetCoordinates() != 0)
				OSD::Notify("Teleport to player:" << PlayerColor << Utils::Format("%01X", SelectedPlayerIndex));
		}
		if(entry->Hotkeys[2].IsDown() && SelectedPlayerIndex != Player::GetActualPlayerIndex())
		{
			if((u32)Player::GetCoordinates(SelectedPlayerIndex) != 0 && (u32)Player::GetCoordinates() != 0)
			{
				*Player::GetCoordinates() = *Player::GetCoordinates(SelectedPlayerIndex);
				*((float *)((vu32)Player::GetCoordinates() + 8)) = *((float *)((vu32)Player::GetCoordinates(SelectedPlayerIndex) + 8));
			}
		}

		if(entry->Hotkeys[3].IsPressed())
		{
			u32 x, y;
			if(!Player::GetWorldCoords(&x, &y))
				return;

			for(u8 i = 0; i < 4; i++)
				Animation::ExecuteAnimationWrapper(i, 0x34, 1, 1, 1, 1, 0, x, y, true);
			OSD::Notify("Everyone TP to you");
		}
	}

	bool    PlayersInfosOSD(const Screen &screen)
	{
		Color PlayerColor;
		switch(SelectedPlayerIndex)
		{
			case 0:
		    	PlayerColor = Color::Blue;
				break;
			case 1:
		    	PlayerColor = Color::Red;
				break;
			case 2:
		    	PlayerColor = Color::Green;
				break;
			case 3:
		    	PlayerColor = Color::Yellow;
				break;
		}

		u32 y = 0;
		if(screen.IsTop && Player::IsLoaded(SelectedPlayerIndex))
		{
			u32 pItem;
			u32 selectedX = 0, selectedY = 0;

			float X = *Player::GetCoordinates(SelectedPlayerIndex), Z = *(float *)((u32)Player::GetCoordinates(SelectedPlayerIndex) + 8);
			Player::GetWorldCoords(&selectedX, &selectedY, SelectedPlayerIndex);
			pItem = (u32)Items::GetItemAtWorldCoords(selectedX, selectedY);

			y = screen.Draw("Player:" << Utils::Format("%01X", SelectedPlayerIndex) << (SelectedPlayerIndex == Player::GetOnlinePlayerIndex() ? " (You)" : ""), 0, y, PlayerColor);
			y = screen.Draw("Room:" << Hex(Player::ActualRoom(Player::GetOnlinePlayerIndex())), 0, y);
			y = screen.Draw("Coordinates:" << std::to_string(X).erase(4) << "|" << std::to_string(Z).erase(4), 0, y);
			y = screen.Draw("X|Y:" << Hex((u8)(selectedX & 0xFF)) << "|" << Hex((u8)(selectedY & 0xFF)), 0, y);
			y = screen.Draw("Standing on:" << (pItem != 0 ? Hex(*(u32 *)pItem) : "N/A") << (Items::GetLockedSpotIndex(selectedX, selectedY) != 0xFFFFFFFF ? " (Locked)" : ""), 0, y);
			y = screen.Draw("Animations:" << Hex(*Player::GetAnimation(SelectedPlayerIndex)) << "/" << Hex(*Player::GetSnake(SelectedPlayerIndex)), 0, y);

			if(SelectedPlayerIndex == Player::GetActualPlayerIndex()) // Own player infos
			{
				y = screen.Draw("Menu:" << Hex(Player::GetCurrentInventory()), 0, y);
			}
		}
		else if(screen.IsTop)
		{
			u32 AnimObjPtr;
			vu32(*AnimFunc)(u32 param1);
			Process::Write32((u32)&AnimFunc, USA_Room_Function);
			AnimObjPtr = AnimFunc(SelectedPlayerIndex);
			
			if(AnimObjPtr != 0 && *(u8 *)AnimObjPtr != 0xFF)
			{
				y = screen.Draw("Player:" << Utils::Format("%01X", SelectedPlayerIndex) << (SelectedPlayerIndex == Player::GetOnlinePlayerIndex() ? " (You)" : ""), 0, y, PlayerColor);
				y = screen.Draw("Room:" << Hex(SelectedPlayerIndex == Player::GetOnlinePlayerIndex() ? Player::ActualRoom() : *(u8 *)AnimObjPtr), 0, y);
				y = screen.Draw("Animation:" << Hex(*(u8 *)(AnimObjPtr + 1)), 0, y);
			}
		}
		return true;
	}

	void    PlayersInfos(MenuEntry *entry)
	{
		if(entry->IsActivated())
			OSD::Run(PlayersInfosOSD);
		else if(!entry->IsActivated())
			OSD::Stop(PlayersInfosOSD);
	}

	bool    ShowAllPlayersOnMapOSD(const Screen &screen)
	{
		if(!screen.IsTop && Game::MapBool())
		{
			float X, Z;
			if((Player::IsInRoom(0) || (Player::ActualRoom() >= 0x6D && Player::ActualRoom() < 0x80)))
			{
				if(Player::GetCoordinatesRef(X, Z, 0)) screen.DrawRect((u32)(32.0f + (X / 14.2f)), (u32)(13.0f + (Z / 14.2f)), 6, 6, Color::Blue);
				if(Player::GetCoordinatesRef(X, Z, 1)) screen.DrawRect((u32)(32.0f + (X / 14.2f)), (u32)(13.0f + (Z / 14.2f)), 6, 6, Color::Red);
				if(Player::GetCoordinatesRef(X, Z, 2)) screen.DrawRect((u32)(32.0f + (X / 14.2f)), (u32)(13.0f + (Z / 14.2f)), 6, 6, Color::Green);
				if(Player::GetCoordinatesRef(X, Z, 3)) screen.DrawRect((u32)(32.0f + (X / 14.2f)), (u32)(13.0f + (Z / 14.2f)), 6, 6, Color::Yellow);
				// if(NPC::GetCoordinatesRef(npc, X, Z)) screen.DrawRect((u32)(33.0f + (X / 14.2f)), (u32)(14.0f + (Z / 14.2f)), 4, 4, Color::Orange);
			}
			if(Player::IsInRoom(0x68))
			{
				if(Player::GetCoordinatesRef(X, Z, 0)) screen.DrawRect((u32)(73.0f + (X / 12.1f)), (u32)(30.6f + (Z / 12.1f)), 6, 6, Color::Blue);
				if(Player::GetCoordinatesRef(X, Z, 1)) screen.DrawRect((u32)(73.0f + (X / 12.1f)), (u32)(30.6f + (Z / 12.1f)), 6, 6, Color::Red);
				if(Player::GetCoordinatesRef(X, Z, 2)) screen.DrawRect((u32)(73.0f + (X / 12.1f)), (u32)(30.6f + (Z / 12.1f)), 6, 6, Color::Green);
				if(Player::GetCoordinatesRef(X, Z, 3)) screen.DrawRect((u32)(73.0f + (X / 12.1f)), (u32)(30.6f + (Z / 12.1f)), 6, 6, Color::Yellow);
			}
		}
		return true;
	}

	void	ShowAllPlayersOnMap(MenuEntry *entry)
	{
		if(entry->IsActivated())
			OSD::Run(ShowAllPlayersOnMapOSD);
		else if(!entry->IsActivated())
			OSD::Stop(ShowAllPlayersOnMapOSD);
	}

    void	MagicWandACNH(MenuEntry *entry)
	{
		OutfitVector PlayerOutfit;

		if(entry->Hotkeys[0].IsPressed())
		{
			if(Player::InLoadingState() || MapEditorActive || AnimExecuting)
				return;

			std::string OutFitsFolder = "Luna/Outfits";
			std::string FilePath = OutFitsFolder + "/Outfits.txt";
			
			Directory Luna("Luna", true); // Create "Luna" folder if it doesnt exist
			Directory dir(OutFitsFolder, true); // Create "Luna/Outfits" folder if it doesnt exist
			
			s8 uchoice = OpenList(Color::Yellow << "Magic Wand ACNH", OutfitsOpt);
			switch(uchoice)
			{
				case 0: // Save actual player outfit into a file
				{
					s8 PlayerChoice;
					if(Game::GetOnlinePlayerCount() != 0)
					{
						PlayerChoice = OpenList("Select a player to save their outfit to." << Color::Yellow << "\n\nOutfits Saver", Game::GetOnlinePlayerList());
						if(PlayerChoice < 0)
							return;
						else if(!Player::IsLoaded(PlayerChoice))
						{
							OSD::Notify(Color::Yellow << "You must be in the same room as your target!");
							return;
						}
					}
					u32 BaseAddress = (Game::GetOnlinePlayerCount() != 0) ? (Player::GetOffset(PlayerChoice) + 0x3B4) : (Player::GetOffset() + 0x3B4);

					if(*(u16 *)BaseAddress == 0x2000)
					{
						OSD::Notify(Color::Orange << "You cannot save a Mii!");
						return;
					}

					std::string OutfitName;
					if(SetUpKB("Name your outfit." << Color::Yellow << "\n\nOutfits Saver", false, 20, OutfitName, "", 0))
					{
						Outfit ReadedOutfit;
						u16 ActualPlayerOutfit[6];

						for(u8 i = 0; i < 7; i++)
						{
							if(i == 3) // jump, there is nothing here (maybe girl outfit?)
								continue;
							
							u8 OutfitPiece = (i > 3) ? (i - 1) : i;

							Process::Read16(BaseAddress + (i * 4), ActualPlayerOutfit[OutfitPiece]);
						}

						File OutfitSave;

						StringVector FileExist;
						dir.ListFiles(FileExist, ".txt"); // Read all .txt inside the folder

						// If .txt savefile doesnt exist
						if(!File::Exists(FilePath))
						{
							File::Create(FilePath);
							MessageBox("Created file at:\n" << Color::Yellow << FilePath).SetClear(ClearScreen::Top)();
						}

						// Open savefile in APPEND mode to go at the end
						if(File::Open(OutfitSave, FilePath, File::WRITE | File::APPEND) != 0)
						{
							MessageBox(Color::Red << "Error", Color::White << "Unable to open the file for saving.")();
							break;
						}

						std::string line = Utils::Format("\nName: %s\n0x%04X\n0x%04X\n0x%04X\n0x%04X\n0x%04X\n0x%04X\n//",
							OutfitName.c_str(), // Convert "std::string" in "const char*"
							ActualPlayerOutfit[0],
							ActualPlayerOutfit[1],
							ActualPlayerOutfit[2],
							ActualPlayerOutfit[3],
							ActualPlayerOutfit[4],
							ActualPlayerOutfit[5]);

						OutfitSave.Write(line.c_str(), line.size());
						OutfitSave.Close();

						OSD::Notify(Color::Green << "Outfit saved!");
					}
					break;
				}
				case 1:
				{
					StringVector OutFitsList;
					Directory::Open(dir, "Luna/Outfits");
					dir.ListFiles(OutFitsList, ".txt"); // Read all .txt inside the folder

					if(OutFitsList.empty())
					{
						MessageBox(Color::Red << "Error", "No \".txt\" outfits files found!")();
						dir.Close();
						break;
					}

					File OutfitRestore;

					// Open savefile in READ mode
					if(File::Open(OutfitRestore, FilePath, File::READ) != 0)
					{
						MessageBox(Color::Red << "Error", "\"Outfits.txt\" not found!")();
						break;
					}
					
					Outfit ReadedOutfit;
					bool ReadingOutfit = false;

					std::string FileContent = ReadWholeTxtFile(FilePath);

					size_t start = 0;
					size_t end = FileContent.find('\n');
					while(end != std::string::npos)
					{
						std::string line = FileContent.substr(start, end - start);

						line = line.substr(0, line.find("//")); // Remove spaces and comments (after "//")
						line.erase(0, line.find_first_not_of(' ')); // Remove spaces at the beginning
						line.erase(line.find_last_not_of(' ') + 1); // Remove spaces at the end
						
						if(line.empty()) // If the line is empty, it’s the end of an outfit (Bcs we deleted "//" it creates a space)
						{
							if(ReadingOutfit && !ReadedOutfit.OutfitPiece.empty())
							{
								PlayerOutfit.push_back(ReadedOutfit);
								ReadedOutfit = Outfit(); // Reset for next outfit
								ReadingOutfit = false;
							}
						}
						else if(line.find("Name:") == 0) // If the line starts with "Name:", it is the name of the outfit
						{
							ReadedOutfit.Name = line.substr(5); // Extract name after "Name: "
							ReadingOutfit = true;
						}
						else if(ReadingOutfit)
						{
							u16 value = static_cast<u16>(std::stoul(line, nullptr, 16)); // Convert line in u16
							ReadedOutfit.OutfitPiece.push_back(value);
						}
						
						start = end + 1;
						end = FileContent.find('\n', start);
					}

					if(!ReadedOutfit.OutfitPiece.empty()) // Add last outfit if it was not added
					{
						PlayerOutfit.push_back(ReadedOutfit);
					}

					OutfitRestore.Close();

					if(PlayerOutfit.empty())
					{
						MessageBox(Color::Red << "Error", "No outfits found in the file!")();
						return;
					}

					StringVector OutfitsList;
					for(const Outfit& outfit : PlayerOutfit)
						OutfitsList.push_back(outfit.Name); // All available outfits

					s8 OutfitChoice = OpenList("Select an outfit to load." << Color::Yellow << "\n\nOutfits Loader", OutfitsList);
					if(OutfitChoice < 0)
						return;
					
					if(PlayerOutfit[OutfitChoice].OutfitPiece.size() == 6) // If there are 6 cloth pieces in the saved outfit.
					{
						Player::SetOutfit(PlayerOutfit[OutfitChoice].OutfitPiece[0], PlayerOutfit[OutfitChoice].OutfitPiece[1], PlayerOutfit[OutfitChoice].OutfitPiece[2], PlayerOutfit[OutfitChoice].OutfitPiece[3], PlayerOutfit[OutfitChoice].OutfitPiece[4], PlayerOutfit[OutfitChoice].OutfitPiece[5]);
						OSD::Notify("Outfit applied ->" << Color::Lime << OutfitsList[OutfitChoice]);
					}
					else
						MessageBox(Color::Red << "Error", "Invalid number of values in the outfit!" << Color::Magenta << "\nExpected values: 6")();
				}
			}
		}
	}

	/*
	Save Codes
	*/

	void	PlayerNameChanger(MenuEntry* entry)
    {
		const u16 offset = 0x55A8;
		u32 PSaveOffset = Player::GetSaveOffset();
		std::string input;
		
        Keyboard Name("Entrez le nom que vous souhaitez avoir:" << Color::Yellow << "\n\nPlayer Name changer");
        Name.SetMaxLength(8);
        if(PSaveOffset == 0)
			return;
        
		if(Name.Open(input) != -1 && input.size() != 8)
        {					
            Keyboard Align("How would you like your name to \nbe aligned?");
            StringVector Alignments = { "Normal", "Align text to the left", "Align text to the right", "Higher", "Lower", "Empty" };
            Align.Populate(Alignments);
 
            s8 uchoice = Align.Open();
            if(uchoice < 0)
				return;
			
            //Wipe Name String entirely first
            Process::Write32((PSaveOffset + offset), 0);
            Process::Write32((PSaveOffset + offset + 0x4), 0);
            Process::Write32((PSaveOffset + offset + 0x8), 0);
            Process::Write32((PSaveOffset + offset + 0xC), 0);

			switch(uchoice)
			{
				case 0: // Normal
					Process::WriteString((PSaveOffset + offset), input, StringFormat::Utf16);
					break;
				case 1: // Align Left   0x0009 = big Seperator
					Process::WriteString((PSaveOffset + offset), input, StringFormat::Utf16);
                    Process::Write16((PSaveOffset + offset + (input.size() * 0x2)), 0x9);
					break;
				case 2: // Align Right   0x0009 = big Seperator
					Process::Write16((PSaveOffset + offset), 0x9);
                    Process::WriteString((PSaveOffset + offset + 0x2), input, StringFormat::Utf16);
					break;
				case 3: // Higher   0x000A = next Line
					Process::WriteString((PSaveOffset + offset), input, StringFormat::Utf16);
                    Process::Write16((PSaveOffset + offset + (input.size() * 0x2)), 0xA);
					break;
				case 4: // Lower   0x000A = next Line
					Process::Write16((PSaveOffset + offset), 0xA);
                    Process::WriteString((PSaveOffset + offset + 0x2), input, StringFormat::Utf16);
					break;
				case 5: // Empty   0x000E <= makes string Invalid
					Process::Write16((PSaveOffset + offset), 0xE);
                    Process::WriteString((PSaveOffset + offset + 0x2), input, StringFormat::Utf16);
					break;
				default:
					break;
			}
		}
        else if (input.size() == 8) 
		{
            //Wipe Name String entirely first
            Process::Write32((PSaveOffset + offset), 0);
            Process::Write32((PSaveOffset + offset + 0x4), 0);
            Process::Write32((PSaveOffset + offset + 0x8), 0);
            Process::Write32((PSaveOffset + offset + 0xC), 0);
            Process::WriteString((PSaveOffset + offset), input, StringFormat::Utf16);
        }
    }

	void	TownNameChanger(MenuEntry *entry)
    {
        std::string input;

        Keyboard TownName("Enter the name of the town \nyou wish to have:" << Color::Yellow << "\n\nTown Name changer");
        TownName.SetMaxLength(8);
        if(TownName.Open(input) < 0)
			return;

        Process::WriteString(Player::GetSaveOffset() + 0x55BE, input, StringFormat::Utf16);
        Process::WriteString(0x31F8913A, input, StringFormat::Utf16);
    }

	void    TPCPictureExport(MenuEntry *entry)
	{
        File Picture; //File Object
		Directory Luna("Luna", true); //create the directory if it doesn't exist
        Directory dir("Luna/Pictures", true); //Create the directory if it doesn't exist
 
        Keyboard keyboard("Choose a name for your photo." << Color::Yellow << "\n\nTPC Picture Export");
 
        std::string SavePName; //name for the save
 
        if(keyboard.Open(SavePName) < 0)
			return;

        if(SavePName.find(".jpg") == std::string::npos) //if the entered name haven't got .jpg at the end
            SavePName += ".jpg";                         //add .jpg
        if(dir.OpenFile(Picture, SavePName, File::RWC) == 0)
        {
            if((Picture.Dump(0x31F2C758, 0x1400)) == 0)
                MessageBox("Created file at:\n" << Color::Yellow << "Luna/Pictures/" + SavePName).SetClear(ClearScreen::Top)();
            else //if Failed
                MessageBox(Color::Red << "Error", Color::White << "Unable to create backup file.").SetClear(ClearScreen::Top)();
        }
        else //if Failed
			MessageBox(Color::Red << "Error", Color::White << "Unable to create/open file.").SetClear(ClearScreen::Top)();
    }
	
	void    TPCPictureImport(MenuEntry *entry)
	{
		StringVector PicturesList; //Vector for our Save Names
        File Picture; //File Object

		Directory Luna("Luna", true); //create the directory if it doesn't exist
		Directory dir("Luna/Pictures", true); //Create the directory if it doesn't exist
		Directory::Open(dir, "Luna/Pictures");
        dir.ListFiles(PicturesList, ".jpg");

        if(PicturesList.empty())
        {
            MessageBox(Color::Yellow << "No backup is available!")();
            dir.Close();
            return;
        }
 
        Keyboard PictureImport("Choose a photo to import:" << Color::Yellow << "\n\nTPC Picture Import");
        PictureImport.Populate(PicturesList);
		s8 uchoice = PictureImport.Open();

        if(uchoice < 0)
			return;
		
        if(dir.OpenFile(Picture, PicturesList[uchoice], File::RW) == 0)
        {
            if((Picture.Inject(0x31F2C758, 0x1400)) == 0)
                MessageBox(Color::Green << "You have restored your picture!").SetClear(ClearScreen::Top)();
            else //if failed
				MessageBox(Color::Red << "Error", Color::White << "Unable to inject the file.").SetClear(ClearScreen::Top)();
        }
        else //if Failed
			MessageBox(Color::Red << "Error", Color::White << "Unable to open the file.").SetClear(ClearScreen::Top)();
    }

	void	SavesManager(MenuEntry* entry)
	{
		File Garden; //File Object
		StringVector GardenList; //Vector for our Save Names
		Directory Luna("Luna", true); //create the directory if it doesn't exist
		Directory dir("Luna/Towns", true); //Create the directory if it doesn't exist

		redo:
		s8 uchoice = OpenList("", {"Dump Save", "Restore Save"});
		switch(uchoice)
		{
			case 0:
			{
				Keyboard DumpSave("Name the town you want to dump." << Color::Yellow << "\n\nGarden Dumper");
		
				std::string savename;  //name for the save
		
				if(DumpSave.Open(savename) < 0)
					goto redo;

				if(savename.find(".dat") == std::string::npos) //if the entered name haven't got .dat at the end
					savename += ".dat";                         //add .dat
				if(dir.OpenFile(Garden, savename, File::RWC) == 0)
				{
					if((Garden.Dump(0x31F26F80, 0x89B00)) == 0)
						MessageBox("Created file at:\n" << Color::Yellow << "Luna/Towns/" + savename).SetClear(ClearScreen::Top)();
					else //if Failed
					{
						MessageBox(Color::Red << "Error", Color::White << "Unable to create backup file.").SetClear(ClearScreen::Top)();
						goto redo;
					}
				}
				else //if Failed
				{
					MessageBox(Color::Red << "Error", Color::White << "Unable to create/open file.").SetClear(ClearScreen::Top)();
					goto redo;
				}
				break;
			}
			case 1:
			{
				Directory::Open(dir, "Luna/Towns");
				dir.ListFiles(GardenList, ".dat");

				if(GardenList.empty())
				{
					MessageBox(Color::Yellow << "No backup is available!").SetClear(ClearScreen::Top)();
					dir.Close();
					goto redo;
				}
		
				Keyboard RestoreSave("Select the backup to restore." << Color::Yellow << "\n\nGarden Restore");
				RestoreSave.Populate(GardenList);
				s8 uchoice = RestoreSave.Open();
		
				if(uchoice < 0)
					goto redo;

				if(dir.OpenFile(Garden, GardenList[uchoice], File::RW) == 0)
				{
					if((Garden.Inject(0x31F26F80, 0x89B00)) == 0)
					{
						MessageBox(Color::Green << "You have restored your backup!").SetClear(ClearScreen::Top)();
						
						Game::AskReloadRoom();
					}
					else //if failed
					{
						MessageBox(Color::Red << "Error", Color::White << "Unable to inject the backup file.").SetClear(ClearScreen::Top)();
						goto redo;
					}
				}
				else //if Failed
				{
					MessageBox(Color::Red << "Error", Color::White << "Unable to open the file.").SetClear(ClearScreen::Top)();
					goto redo;
				}
				break;
			}
			default:
				break;
		}
	}

	void    Badges(MenuEntry *entry)
    {
		s8 uchoice = OpenList("", BadgesOpt);
		if(uchoice < 0 || (*(u8 *)USA_Player_Address > 0x3))
			return;
		
		for(u8 i = 0; i < 24; i++)
        {
            Process::Write8(USA_Badge_Address + (*(u8 *)USA_Player_Address * 0xA480) + i, uchoice);
        }
    }

	void	FillCollectablesList(MenuEntry *entry)
    {
		s8 uchoice = OpenList("", CollectablesOpt);
		switch(uchoice)
		{
			case 0: //Encyclopedia
			{
				const u8 encyclopediabuffer[] =
				{ 
					0xCC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
					0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD0, 0x9A
				};
				Process::CopyMemory(reinterpret_cast<void *>(Player::GetSaveOffset() + 0x6C70), encyclopediabuffer, sizeof(encyclopediabuffer));
				break;
			}
			case 1: //Emoticons
			{
				const u8 emoticonbuffer[] =
				{ 
					0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 
					0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x20, 0x21, 0x24, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2E
				};
				Process::CopyMemory(reinterpret_cast<void *>(Player::GetSaveOffset() + 0x89D0), emoticonbuffer, sizeof(emoticonbuffer));
				break;
			}
			case 2: //Song
				for(u8 i = 0; i < 3; i++)
					Process::Write32(Player::GetSaveOffset() + 0x8F9C + (i * 4), 0xFFFFFFFF);
				break;
			case 3: //Catalog
				std::memset((void *)(Player::GetSaveOffset() + 0x6C90), 0xFF, 106 * 4);
				break;
			default: 
				break;
        }
    }

	void 	DreamCodeModifier(MenuEntry *entry)
    {
		u16 Part1, Part2, Part3;
		ACNL_Player *PlayerSave = Player::GetSaveData();
		if(!PlayerSave)
			return;

		AskPart1:
		if(!SetUpKBNo("Dial the dream code numbers\nyou would like to have." << Color::Lime << "\n 4 Numbers | Part 1", true, 4, Part1))
			return;
		
		AskPart2:
		if(!SetUpKBNo("Dial the dream code numbers\nyou would like to have." << Color::Lime << "\n 4 Numbers | Part 2", true, 4, Part2))
			goto AskPart1;

		if(!SetUpKBNo("Dial the dream code numbers\nyou would like to have." << Color::Lime << "\n 4 Numbers | Part 3", true, 4, Part3))
			goto AskPart2;

		PlayerSave->DreamCode.DCPart1 = (Part2 << 16) + Part3;
		PlayerSave->DreamCode.DCPart2 = (Part1 & 0xFF);
		PlayerSave->DreamCode.DCPart3 = (Part1 >> 8);
		PlayerSave->DreamCode.HasDreamAddress = true;
		MessageBox(Color::Green << "Success!", Color::White << "\nNew dream code:" << Color::Yellow << Utils::Format("\n%04X-%04X-%04X", Part1, Part2, Part3)).SetClear(ClearScreen::Top)();
    }

	/*
	Misc Codes
	*/

	void	DisableSaveMenu(MenuEntry *entry)
	{
		if(entry->WasJustActivated())
		{
			Process::Patch(USA_SaveMenu_Address, 0xE1A00000);
			Save = false;
		}
		else if(!entry->IsActivated())
		{
			Process::Patch(USA_SaveMenu_Address, 0xE8900006);
			Save = true;
		}
	}

	void	FastMenus(MenuEntry *entry)
	{
		if(entry->WasJustActivated())
			Process::Patch(0x56A2C0, 0x7F7FFFFF);
		else if(!entry->IsActivated())
			Process::Patch(0x56A2C0, 0x3F800000);
	}

	void	CensusMenu(MenuEntry *entry)
	{ 
		if(entry->WasJustActivated())
			Process::Write8(0x31F2C74F, 0x40);
		else if(!entry->IsActivated())
			Process::Write8(0x31F2C74F, 0);
	}

	void	TimeMachine(MenuEntry *entry)
	{
		if(Game::GetOnlinePlayerCount() != 0)
			return;

		u32 x, y;
		if(Player::GetWorldCoords(&x, &y) && !Player::InLoadingState() && !IsCatalogOpen && !WantReload && !TimeMachineBool)
		{
			Process::Write32(0x6D3CB4, 0xE3A0002E);
			Process::Write32(0x6578B0, 0xE3A0101A);
			Animation::ExecuteAnimationWrapper(Player::GetActualPlayerIndex(), 0x3F, 0, 1, 1, 1, 0, x, y, true);
			MessageBox(Color::Green << "Success!", Color::White << " Note:" << Color::Yellow << "\nPlease close the plugin menu \nif you want to change the time.").SetClear(ClearScreen::Top)();
			TimeMachineBool = true;
		}
	}

	void	ToolsEffects(MenuEntry *entry)
    {
		const u16 ToolsListID[12] = {0x335B, 0x3357, 0x3353, 0x335F, 0x334F, 0x3363, 0x3365, 0x338F, 0x338E, 0x336B, 0x336A, 0x3368};

		if((entry->IsActivated()) && (toolsuchoice < 12) && !Player::InLoadingState())
		{
			Process::Write16(0x33073CB4, ToolsListID[toolsuchoice]);
		}
    }

	void	ToolsChoice(MenuEntry *entry)
	{
		s8 uchoice = OpenList("Your current tool will be transformed into:", ToolsOpt);
		if(uchoice != -1)
		{
			toolsuchoice = uchoice;
			OSD::Notify("Tool effect:" << Color::Lime << ToolsOpt[uchoice]);
		}
	}

	void	TreeShakeChop(MenuEntry *entry)
	{
		if(entry->WasJustActivated())
		{
			Process::Patch(0x5971D4, 0xE1A00000);
			Process::Patch(0x5971DC, 0xE1A00000);
			Process::Patch(0x5971E4, 0x1A00001B);
			Process::Patch(0x5971EC, 0xEA000080);
			Process::Patch(0x59945C, 0xE1A00000);
		}
		else if(!entry->IsActivated())
		{
			Process::Patch(0x5971D4, 0x0A000008);
			Process::Patch(0x5971DC, 0x0A00005B);
			Process::Patch(0x5971E4, 0x0A00001B);
			Process::Patch(0x5971EC, 0x0A000080);
			Process::Patch(0x59945C, 0xCA000005);
		}
	}

	void	OnParticleChange(Keyboard &k, KeyboardEvent &e)
	{
		std::string& s = k.GetInput();
		k.GetMessage() = "Type the ID of a particle:" << Color::Lime << "\nHex: 0~246" << Color::DeepSkyBlue << "\n\nParticle ID: " << IDList::GetParticleName(s != "" ? std::stoi(s, nullptr, 16) : 0);
	}

	void	ParticlesSpawner(MenuEntry *entry)
	{
		static u16 ParticleID = 0x20C;
		const float ParticleSpace = 32.0f; // Display interval
		float ParticleCoords[3];
		
		if(entry->Hotkeys[0].IsPressed())
		{
			u16 SetParticle;
			SetUpKB("Type the ID of a particle:" << Color::Lime << "\nHex: 0~246", true, 3, SetParticle, ParticleID, OnParticleChange);
			if(IDList::ParticleValid(SetParticle))
				ParticleID = SetParticle;
		}
		else if(Turbo ? entry->Hotkeys[1].IsDown() : entry->Hotkeys[1].IsPressed()) // if u switch Turbo mode, need to go in some menu if u dont wanna crash (idk why, its a BUG from 'Particles' function)
		{
			u8 x, y, z;
			for(x = 0; x < NumParticles[0]; x++)
			{
				for(y = 0; y < NumParticles[1]; y++)
				{
					for(z = 0; z < NumParticles[2]; z++)
					{
						ParticleCoords[0] = Player::GetCoordinates()[0] + StartCoords[0] + x * ParticleSpace;
						ParticleCoords[1] = Player::GetCoordinates()[1] + StartCoords[1] + y * ParticleSpace;
						ParticleCoords[2] = Player::GetCoordinates()[2] + StartCoords[2] + z * ParticleSpace;
						Game::Particles(ParticleID, ParticleCoords);
					}
				}
			}
		}
	}

	void	ParticlesSize(MenuEntry *entry)
	{
		StringVector list =
        {
            "Size 1 (Def.)",
            "Size 2",
		    "Size 3",
        };

		const float Coords[3][3] =
		{
			{0, 0, 0},
			{-32, 0, -32},
			{-64, 0, -64},
		};

		const u8 Sizes[3][3] =
		{
			{1, 1, 1},
			{3, 1, 3},
			{5, 1, 5},
		};

        s8 uchoice = OpenList("", list);
		if(uchoice < 0)
			return;

		for(u8 i = 0; i < 3; i++)
		{
			StartCoords[i] = Coords[uchoice][i];
			NumParticles[i] = Sizes[uchoice][i];
		}
	}

	void	EditEveryRoomOnline(MenuEntry *entry)
	{
        Process::Write32(0x998C7A, 0x10101010);
        Process::Write8(0x998C7E, 0x10);
        if(entry->WasJustActivated())
        {
			Process::Patch(0x5B4B60, 0xE3A00001); //allow wallpaper change
            Process::Patch(0x5B5268, 0xE1A00000);
            Process::Patch(0x5B5284, 0xEA000026);
			Process::Patch(0x5B7558, 0xE3A00001); //lightswitch
        }
        else if(!entry->IsActivated())
        {
			Process::Patch(0x5B4B60, 0xE3A00000); //allow wallpaper change
            Process::Patch(0x5B5268, 0x0A00000D);
            Process::Patch(0x5B5284, 0x0A000026);
			Process::Patch(0x5B7558, 0xE3A00000); //lightswitch
        }
    }

	void	SkipIsabelle(MenuEntry *entry)
	{
		if(entry->IsActivated())
		{
        	if(Player::IsInRoom(0x63, Player::GetActualPlayerIndex(), true) && !Game::IsSaving())
				Process::Write32(0x31FF599C, 0xFEDFEDFF); //force error
		}
    }

	static u32 readaddress;
	bool    AddressTestOSD(const Screen &screen)
	{
		u32 y;
		if(screen.IsTop)
		{
			y = screen.Draw("Addr:0x" << (Utils::Format("%08X", readaddress)), 306, 0);
			y = screen.Draw("Value:0x" << (Utils::Format("%08X", *(u32 *)readaddress)), 300, y);
		}
		return true;
	}

	void	AddressTest(MenuEntry *entry)
	{
		static u32 writeaddress;
		u32 writevalue;
		if(entry->IsActivated())
		{
			OSD::Run(AddressTestOSD);
		}
		else if(!entry->IsActivated())
		{
			OSD::Stop(AddressTestOSD);
		}
		if(entry->Hotkeys[0].IsPressed())
		{
			SetUpKB("Enter an address. Read", true, 8, readaddress, readaddress);
		}
		if(entry->Hotkeys[1].IsPressed())
		{
			SetUpKB("Enter an address. Write", true, 8, writeaddress, writeaddress);
			Process::Read32(writeaddress, writevalue);
			SetUpKB("Enter a value. Write", true, 8, writevalue, writevalue);
		}
	}

	void	GameFuncCall(MenuEntry *entry)
	{
		StringVector FuncCallOpt =
		{
			"Get Player Offset",
			"Get Online Player Count",
		};

		if(entry->Hotkeys[0].IsPressed())
		{
			s8 uchoice = OpenList("", FuncCallOpt);
			switch(uchoice)
			{
				case 0:
				{
					StringVector Meth =
					{
						"Instance Function",
						"Player Pointer",
					};

					u8 PlayerIndex = 4;
					u32 PlayerOffset;
					bool ValidOffset;
					vu32(*FUNC)(u32 param1, u32 param2);

					s8 plyoffuchoice = OpenList("", Meth);
					if(plyoffuchoice < 0)
						return;

					if(!SetUpKB("Player Index:\nType > or = 4, to get yours", true, 1, PlayerIndex, PlayerIndex))
						return;

					if(PlayerIndex >= 4)
						PlayerIndex = Player::GetActualPlayerIndex();
					
					switch(plyoffuchoice)
					{
						case 0:
							Process::Write32((u32)&FUNC, USA_PlayerInstance_Function);
							PlayerOffset = FUNC(PlayerIndex, 1);
							break;
						case 1:
							Process::Read32(USA_PlayerInfo_Pointer + (PlayerIndex * 4), PlayerOffset);
							break;
						default:
							break;
					}

					ValidOffset = (PlayerOffset == 0x330773BC) || (PlayerOffset == 0x330774E8);

					if(ValidOffset)
						OSD::Notify("Your player", Color::Green);
					else if(!ValidOffset)
						OSD::Notify("Not your player", Color::Red);

					OSD::Notify("PlayerOffset (" << Meth[plyoffuchoice] << Utils::Format("):0x%08X", PlayerOffset) << Utils::Format(" Index:%01X", PlayerIndex));
					break;
				}
				case 1:
					OSD::Notify(Utils::Format("Online Player Count:%01X", Game::GetOnlinePlayerCount()));
					break;
				default:
					break;
			}
		}
	}

	void	GetFriendCodeMenu(MenuEntry *entry)
	{
		u8 PlayerIndex = 4;
		if(!SetUpKB("Only works online (I guess?)\nPlayer Index:\nType > or = 4, to get yours", true, 1, PlayerIndex, PlayerIndex))
			return;

		if(PlayerIndex >= 4)
			PlayerIndex = Player::GetActualPlayerIndex();

		u64 fCode = Player::GetFriendCode(PlayerIndex);

		if(!fCode)
		{
			OSD::Notify(Utils::Format("Player %d: Not Loaded!", PlayerIndex));
			return;
		}

		std::string str = (Utils::Format("%012lld", fCode));
		OSD::Notify(Utils::Format("Player %d: %s - %s - %s", PlayerIndex, str.substr(0, 4).c_str(), str.substr(4, 4).c_str(), str.substr(8, 4).c_str()));
	}

	/*
	void DisplayImagePart(BMPImage& image, u32 x, u32 y, u32 width, u32 height)
	{
		// Crée une nouvelle image pour stocker la partie découpée
		BMPImage croppedImage(image, width, height);
	
		// Découpe la région spécifiée de l'image
		if(!image.Region(x, y, width, height, croppedImage))
		{
			MessageBox("Erreur", "Impossible de découper l'image.")();
			return;
		}
	
		// Affiche l'image découpée à l'écran
		for(u8 i = 0; i < 50; i++)
		{
			croppedImage.Draw(100, 100); // Ajustez les coordonnées selon vos besoins
			Sleep(Milliseconds(100));
		}
	}

	void DisplayRegion(MenuEntry *entry)
	{
		// Charge l'image BMP
		BMPImage image("ARCES.bmp");
	
		if(!image.IsLoaded())
		{
			MessageBox("Erreur", "Impossible de charger l'image BMP.")();
			return;
		}
	
		// Demander à l'utilisateur de saisir les coordonnées
		u32 x, y, width, height;
	
		// Saisir la position X
		if(!SetUpKBNo("Entrez la position X :", false, 4, x))
			return; // Annuler si l'utilisateur a annulé
	
		// Saisir la position Y
		if(!SetUpKBNo("Entrez la position Y :", false, 4, y))
			return; // Annuler si l'utilisateur a annulé
	
		// Saisir la largeur
		if(!SetUpKBNo("Entrez la largeur :", false, 4, width))
			return; // Annuler si l'utilisateur a annulé
	
		// Saisir la hauteur
		if(!SetUpKBNo("Entrez la hauteur :", false, 4, height))
			return; // Annuler si l'utilisateur a annulé
	
		// Afficher la région spécifiée
		DisplayImagePart(image, x, y, width, height);
	}

	static Screen::Image texture;
	bool isTextureLoaded = false;

	void LoadTexture()
	{
		texture = SF2D_CreateTexture("ACRES.png");
	}

	void DrawImagePart(int srcX, int srcY, int width, int height, int posX, int posY)
	{
		if (!texture) return;
		
		sf2d_draw_texture_part(texture, posX, posY, srcX, srcY, width, height);
	}


	void	PngDisplayTestMenu(MenuEntry *entry)
	{
		if (!isTextureLoaded)  // Charge seulement si l'image n'est pas encore chargée
    	{
        	LoadTexture();
        	isTextureLoaded = true;
    	}

		Keyboard keyboard("Entrez un ID (ex: 3C):");
		std::string input;
		
		if(keyboard.Open(input) == -1)
			return;
		
		int tileSize = 16;  // Taille d'une case
		int x = (std::stoi(input, nullptr, 16) % 16) * tileSize;
		int y = (std::stoi(input, nullptr, 16) / 16) * tileSize;
		
		DrawImagePart(x, y, tileSize, tileSize, 100, 50);  // Afficher la case au centre
	}*/

	void FishThrower(MenuEntry *entry)
	{				
		static u8 playerID = 0;
		static bool random = false;
		u32 FishID = 0x22E1;

		vu32(*FUNC)(u32* param1, float* param2, u32 param3);

		if(entry->Hotkeys[0].IsPressed())
		{
			if(playerID == 3) playerID = 0;		
			else playerID++;

			OSD::Notify(Utils::Format("Player %02X selected!", playerID));
		}

		if(entry->Hotkeys[1].IsPressed())
		{
			random = !random;
			OSD::Notify("Random Mode: " << (random ? (Color::Green << "ON") : (Color::Red << "OFF")));
		}

		if(entry->Hotkeys[2].IsPressed())
		{
			if(random)
			{
				FishID = Utils::Random(0x22E1, 0x234A);
				//if(Items::GetItemCategorie(FishID) != Item_Categories::Fish)
					//return;
			}

			if(Player::IsLoaded(playerID))
			{
				Process::Write32((u32)&FUNC, 0x5C2DAC);
				(void)FUNC(&FishID, Player::GetCoordinates(playerID), 1);
			}
		}

		if(entry->Hotkeys[3].IsPressed())
			SetUpKB("Set Fish ID:", true, 4, FishID, FishID);
	}
}