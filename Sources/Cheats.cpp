#include "Cheats.hpp"

namespace CTRPluginFramework
{
	bool Turbo = false;
    bool OSD = true;
	bool Save = true;
    bool Fov = false;
	bool ByPassing = false;
	bool AnimExecuting = false;
	bool IfForceAllowed = true;
	bool KbExtender = false;

	static float CoordSpeed = 5.0;

	static u32 SeedersID = 0x80007FFE, ItemIDToReplace = 0x7FFE;
	u8 DropType = 0xA, DropAnim = 0x56;
	u32 selectedX = 0, selectedY = 0;
	bool SeedersOSD = true;
	bool TouchRemove = false;
	bool MapEditorActive = false;
	bool IsCatalogOpen = false;

	u8 Appearance[3] = {0, 0, 0};
	u8 AnimID = 6, EmotionID = 1, NPC_Anim = 6, NPC_Emotion = 1;
	u16 SnakeID = 0x1DC, NPC_Snake = 0x1DC, AnimItem, ToolID = 0x2001, NPC_AnimItem = 0x2001, SoundID = 0x7FA;
	static u8 Mode = 0, Index = 0;

	static u8 CustomIslandAcres[16];
	bool IslandAcresCreator = false;
	u16 ShopItem[4] = {0x2083, 0x2083, 0x2083, 0x2083};

	struct Building 
	{
		u16 id;
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

	const u8 TownSlot[6][7] =
	{
		{0x00, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C},
		{0x0E, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1A},
		{0x1C, 0x1E, 0x20, 0x22, 0x24, 0x26, 0x28},
		{0x2A, 0x2C, 0x2E, 0x30, 0x32, 0x34, 0x36},
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

	static float FloatFov = 1.0;

	u8 SelectedPlayerIndex = 0;
	bool ControlPlayer = false;
	using OutfitVector = std::vector<Outfit>;

	static s8 toolsuchoice = 50;

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

	StringVector CustomOutfitsOpt =
	{
		"Team Pharaon",
		"Thib",
		"Yopi",
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
				Process::Write32(0x5C5BEC, 0x1A000028); //0xE1A00000
			else if(!Turbo)
				Process::Write32(0x5C5BEC, 0x0A000028); //0x5C4C34 EUR
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
        	static const u32 Addresses[8] =
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
        	static const u32 patch[8] = {0xEA000094, 0xEA000052, 0xEA000001, 0xEA000014, 0xE1A00000, 0xE1A00000, 0xEA000026, 0xEA000065};
			static const u32 Original[8] = {0x0A000094, 0x0A000052, 0x0A000001, 0xDA000014, 0xED841A05, 0xED840A07, 0x0A000026, 0x0A000065};

        	if(entry->Hotkeys[0].IsPressed())
			{
				Enabling = !Enabling;
				OSD::Notify("Walk Over Things:" + (Enabling ? Color::Green << "ON" : Color::Red << "OFF"));
				for(u8 i = 0; i < 8; i++) 
				{
					Enabling ? Process::Write32(Addresses[i], patch[i]) : Process::Write32(Addresses[i], Original[i]);
				}
			}
		}
    }

	void	MoonJump(MenuEntry *entry)
	{
		if(entry->Hotkeys[0].IsDown() && !Player::InLoadingState()) //Up
		{		
			if(!Player::IsIndoor())
				Process::Write32(0x33077C82, 0x007FFFFF);
			else
				Process::Write32(0x33077DAE, 0x007FFFFF);
		}
		/*if (entry->Hotkeys[1].IsDown()) //Down
		{
			if(!Player::IsIndoor())
				Process::Write32(0x33077C82, 0x00010FF0);
			else
				Process::Write32(0x33077DAE, 0x00010FF0);
		}*/
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
		static bool Enabling = false;
		static const u32 Addresses[6] =
		{
			0x67F748, //0x67E780 EUR
			0x64E824, //0x64D85C EUR
			0x64E82C, //0x64D864 EUR
			0x56BE7C, //0x56AEC4 EUR
			0x65352C, //0x652564 EUR
			0x763ABC, //0x762AC4 EUR
		};
		static const u32 patch[6] = {0x1A000067, 0x03A00000, 0xE3A00000, 0xED902A00, 0xE1A00004, 0xE3A00001};
		static const u32 patch1[6] = {0xEA000067, 0x03A00001, 0xE3A00001, 0xE12FFF1E, 0xEA00000D, 0xE3A00000};
		static const u32 Original[6] = {0x1A000067, 0x03A00001, 0xE3A00000, 0xED902A00, 0xE1A00004, 0xE3A00001};
		
		if(entry->Hotkeys[0].IsPressed())
		{
			Enabling = !Enabling;
			OSD::Notify("Movement Mode:" + (Enabling ? Color::LimeGreen << "Walking" : Color::DeepSkyBlue << "Swimming"));
			for(u8 i = 0; i < 6; i++) 
			{
				Enabling ? Process::Write32(Addresses[i], patch[i]) : Process::Write32(Addresses[i], patch1[i]);
			}
		}
		if(!entry->IsActivated())
		{
			OSD::Notify("Movement Mode:" << Color::Red << "Default");
			for(u8 i = 0; i < 6; i++)
			{
                Process::Write32(Addresses[i], Original[i]);
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
		u32 y;
		if(screen.IsTop && !Player::InLoadingState())
		{
			y = screen.Draw("SeedersID:" << ((SeedersID == 0 || SeedersID == 0x7FFE || SeedersID == 0x80007FFE) ? Color::Blue << "Nothing" : (IDList::ItemValid(SeedersID) ? Color::Lime : Color::Yellow) << Utils::Format("%08X", SeedersID)), 288, 0);
			if(ItemIDToReplace != 0x7FFE) 
				y = screen.Draw("Replace:" << (ItemIDToReplace == 0xFFFFFFFF ? Color::Red << "All" : Color::Orange << Utils::Format("%08X", ItemIDToReplace)), 300, y);
		}
		return true;
	}

    void    SetSeeders(MenuEntry *entry)
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
				SeedersID = (SeedersID - 1 == 0x1FFF ? 0xFD : SeedersID - 1) % 0x4000;
				Process::Read32(SeedersID, SeedersID);
			}
		}
			
		if(entry->Hotkeys[4].IsDown())
		{
			KeysPressedTicks++;
			if((KeysPressedTicks < 90 ? (KeysPressedTicks % 10) == 1 : (KeysPressedTicks % 3) == 1) || KeysPressedTicks > 220)
			{
				SeedersID = (SeedersID + 1 == 0xFE ? 0x2000 : SeedersID + 1) % 0x4000;
				Process::Read32(SeedersID, SeedersID);
			}
		}

		if(!entry->IsActivated())
			OSD::Stop(SetSeedersOSD);
	}

	void    OptionSetSeeders(MenuEntry *entry)
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

	void    TouchDrop(MenuEntry *entry)
	{
		static Hook h;
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
				if(!TouchRemove) Items::PlaceItemWrapper(DropType, ItemIDToReplace, &SeedersID, &SeedersID, worldX, worldY, 0, 0, 0, 0, 0, DropAnim, 0xA5);
				else Items::TrampleAt(worldX, worldY);
			}
		}
	}

	void	OptionTouchDrop(MenuEntry *entry)
	{
		if(MessageBox("Touch remove items?", DialogType::DialogYesNo).SetClear(ClearScreen::Top)())
			TouchRemove = true;
		else
			TouchRemove = false;
	}

	void	AutoDrop(MenuEntry *entry)
	{
        static bool Enabling = false;
		static Hook h;
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
			OSD::Notify("Auto drop:" + (Enabling ? Color::Green << "ON" : Color::Red << "OFF"));
		}
		if(Enabling)
		{
			if(Items::DropCheck(&worldX, &worldY, &u0, 0, 0) && !Player::InLoadingState() && !MapEditorActive && !AnimExecuting)
			{
				Items::PlaceItemWrapper(DropType, ItemIDToReplace, &SeedersID, &SeedersID, worldX, worldY, 0, 0, 0, 0, 0, DropAnim, 0xA5);
			}
		}
	}

	void    DropModifier(MenuEntry *entry)
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
				case 7:
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
		static const u32 Addresses[4] =
		{
			USA_ByPassItemDrop1_Address,
			USA_ByPassItemDrop2_Address,
			USA_ByPassItemDrop3_Address,
			USA_ByPassItemDrop4_Address,
		};
		static const u32 Patch[4] = {0xE3E00000, 0xEA000012, 0xE3A00000, 0xE8BD83F0};
		static const u32 Original[4] = {0xE1A05001, 0x1A000001, 0xE24DD01C, 0xE1A07001};

		// Bypass Items Locked
		if(MessageBox("Bypass items locked? (Fast drop)", DialogType::DialogYesNo).SetClear(ClearScreen::Top)())
		{
			for(u8 i = 0; i < 4; i++)
				Process::Write32(Addresses[i], Patch[i]);
			ByPassing = true;
		}
		else
		{
			// Bypass Items Locked
			for(u8 i = 0; i < 4; i++)
				Process::Write32(Addresses[i], Original[i]);
			ByPassing = false;
		}
	}

	void    PickUpMod(MenuEntry *entry)
	{
		static bool Enabling = true;
		static u8 Mode = 0, Index = 0;
		static const u32 Addresses[8] =
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
		static const u32 Patchs[5][8] =
		{
			{0xE3A00001, 0xE3A00001, 0xE3A04001, 0xE3A00001, 0xE5840000, 0xE5C48004, 0xE5CA9013, 0xE3A0103D},
			{0xE3A00003, 0xE3A00003, 0xE3A04003, 0xE3A00003, 0xE5840000, 0xE5C48004, 0xE5CA9013, 0xE3A01040},
			{0xE3A0000A, 0xE3A0000A, 0xE3A0400A, 0xE3A0000A, 0xE5840002, 0xE5C48000, 0xE5CA900F, 0xE3A01061},
			{0xE3A00012, 0xE3A00012, 0xE3A04012, 0xE3A00012, 0xE5840002, 0xE5C48000, 0xE5CA900F, 0xE3A0105A},
			{0xE3A00013, 0xE3A00013, 0xE3A04013, 0xE3A00013, 0xE5840002, 0xE5C48000, 0xE5CA900F, 0xE3A0104F}
		};
		static const u32 Original[8] = {0xE3A00007, 0xE1A00004, 0xE3A04001, 0xE1A00004, 0xE5840000, 0xE5C48004, 0xE5CA9013, 0xE3A0103C};


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
		if(Enabling)
		{
			Process::Write32(USA_PickUpItem_Address, 0x9E0000);
			Process::Write32(USA_AlwaysPickUp_Address, 0xEA00003D);
			Process::Write32(USA_PickUpAnim_Address, 0xE3A01006);
			Process::Write32(USA_PickUpInventoryFix_Address, 0xEA000008);
			for(u8 i = 0; i < 8; i++)
			{
				Process::Write32(Addresses[i], Patchs[Index][i]);
			}
		}
		if(!entry->IsActivated() || !Enabling)
		{
			for(u8 i = 0; i < 8; i++)
			{
                Process::Write32(Addresses[i], Original[i]);
			}
			Process::Write32(USA_PickUpItem_Address, 0x95CFFC);
			Process::Write32(USA_AlwaysPickUp_Address, 0x0A000044);
			Process::Write32(USA_PickUpAnim_Address, 0xE3A01054);
			Process::Write32(USA_PickUpInventoryFix_Address, 0x0A000008);
		}
	}

	void	MapEditor(MenuEntry *entry)
	{
		if(Player::GetOffset() == 0)
			return;

		static u32 DPadKeyPressedTicks = 0;
		static u8 size;
		static bool Removal = false;
		float Y = *(float *)((u32)Player::GetCoordinates() + 4);
		float ParticleCoords[3] = {0, Y, 0};
		u16 ParticleID = 0x214;
		u32 pItem;

		if(entry->IsActivated())
		{
			if(*(u8 *)0x32DC49C0 != 1)
			{
				u8 *Anim = Player::GetAnimation();
				if(Anim != nullptr && *Anim == 6)
					Process::Write32(Camera::GetInstance() + 0xF0, 0x500);
			}
		}
		
		// Freeze values when cheat is ON
		if(!MapEditorActive) // If Map Editor is OFF get coords
			Player::GetWorldCoords(&selectedX, &selectedY);

		pItem = (u32)Items::GetItemAtWorldCoords(selectedX, selectedY, 0);
		
		if(entry->Hotkeys[0].IsPressed())
		{
			if(!MapEditorActive) // Map Editor ON
			{
				//Process::Write32(0x764504, 0xEA000020); //unlock camera
				Process::Write32(USA_UnlockCamera_Address, 0xE8BD81F0);
				OSD::Notify("Map Editor:" << Color::Green << "ON");

				MapEditorActive = true;
				Fov = true;

				*(float *)(Camera::GetInstance() + 4) = (float)(selectedX * 0x20 + 0x10);
				Camera::AddToY(90.0f);
				*(float *)(Camera::GetInstance() + 0xC) = (float)(selectedY * 0x20 + 0x70);
				Camera::AddToYRotation(0x700);
			}
			else // Map Editor OFF
			{
				if(Save)
				{
					Process::Write32(USA_SaveMenu_Address, 0xE8900006);
					Process::Write32(0x1A0968, 0xE3A01040);
					Process::Write32(0x1A096C, 0xE5900000);
					Process::Write32(0x1A0970, 0xEB14D0AB);
				}
				
				//Process::Write32(0x764504, 0x2A000020); //lock camera
				Process::Write32(USA_UnlockCamera_Address, 0xE2805C01);
				OSD::Notify("Map Editor:" << Color::Red << "OFF");

				MapEditorActive = false;
				Fov = false;
			}
		}
		
		if(MapEditorActive)
		{
			if(Save)
			{
				Process::Write32(USA_SaveMenu_Address, 0xE1A00000);
				Process::Write32(0x1A0968, 0xE1A00000);
     			Process::Write32(0x1A096C, 0xE3A00000);
        		Process::Write32(0x1A0970, 0xEB0E069C);
			}
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
				size++;
				if(size >= 3)
					size = 0;
				
				OSD::Notify("Size:" << Color::Yellow << std::to_string(size+1));
			}
			if(Controller::IsKeysPressed(Key::Start + Key::DPadLeft))
			{
				Removal = !Removal;

				OSD::Notify("Removal mode:" << (Removal ? Color::Green << "ON" : Color::Red << "OFF")); 
			}
			if(Turbo ? Controller::IsKeyDown(Key::A) : Controller::IsKeyPressed(Key::A))
			{
				if(pItem == 0)
					return;

				for(s8 i = -size; i <= size; i++)
				{
					for(s8 j = -size; j <= size; j++)
					{
						if(!Removal) Items::PlaceItemWrapper(DropType, ItemIDToReplace, &SeedersID, &SeedersID, (selectedX + j), (selectedY + i), 0, 0, 0, 0, 0, DropAnim, 0xA5);
						else Items::TrampleAt(selectedX + j, selectedY + i);
					}
				}
			}
			for(s8 i = -size; i <= size; i++)
			{
				for(s8 j = -size; j <= size; j++)
				{
					ParticleCoords[0] = (selectedX + j) * 0x20 + 0x10;
					ParticleCoords[2] = (selectedY + i) * 0x20 + 0x10;
					Game::Particles(ParticleID, ParticleCoords);
				}
			}
		}
		
		if(!entry->IsActivated())
		{ 
			Fov = false;
			Process::Write32(USA_UnlockCamera_Address, 0xE2805C01);
				
			if(Save)
			{
				Process::Write32(USA_SaveMenu_Address, 0xE8900006);
				Process::Write32(0x1A0968, 0xE3A01040);
				Process::Write32(0x1A096C, 0xE5900000);
				Process::Write32(0x1A0970, 0xEB14D0AB);
			}
		}
	}

    void	Trampler(MenuEntry *entry)
	{
		static bool Enabling = false;
		static const u32 addresses[6] = {0x64E4D4, 0x597F38, USA_NoBreakFlowers_Address, 0x597FA0, 0x597FE8, 0x597FAC};
        static const u32 original[6] = {0x0A000032, 0x0A000056, 0xE3A0801D, 0x1A00003C, 0x0A00002A, 0x0A000039};
        static const u32 patch[6] = {0xE1A00000, 0xE1A00000, 0xE1A00000, 0xE1A00000, 0xE1A00000, 0xE1A00000};
		if(entry->Hotkeys[0].IsPressed())
		{
			Enabling = !Enabling;
			OSD::Notify("Trampler:" + (Enabling ? Color::Green << "ON" : Color::Red << "OFF"));
			for(u8 i = 0; i < 6; i++) 
			{
				Enabling ? Process::Write32(addresses[i], patch[i]) : Process::Write32(addresses[i], original[i]);
			}
		}
		if(!entry->IsActivated())
		{
			for(u8 i = 0; i < 6; i++) 
			{
				Process::Write32(addresses[i], original[i]);
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
		static Hook h;
		u32 x, y;

		if(!entry->IsActivated() || !IsCatalogOpen)
		{
			if(Save)
			{
				Process::Write32(USA_SaveMenu_Address, 0xE1A00000);
				Process::Write32(0x1A0968, 0xE1A00000);
     			Process::Write32(0x1A096C, 0xE3A00000);
        		Process::Write32(0x1A0970, 0xEB0E069C);
			}
		}
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
			Process::Write32(0x70E494, 0xE3A00000); // All items buyable
			Process::Write32(0x70E494 + 4, 0xEA00000B); // All items buyable
		}
		else if(Player::GetCurrentInventory() != 0x7C && IsCatalogOpen)
		{
			Animation::ExecuteAnimationWrapper(Player::GetActualPlayerIndex(), 6, 0, 0, 0, 0, 0, false, 0);
			IsCatalogOpen = false;
		}
		if (!entry->IsActivated() || !IsCatalogOpen)
		{
			if(Save)
			{
				Process::Write32(USA_SaveMenu_Address, 0xE8900006);
				Process::Write32(0x1A0968, 0xE3A01040);
				Process::Write32(0x1A096C, 0xE5900000);
				Process::Write32(0x1A0970, 0xEB14D0AB);
			}

			h.Disable();
			Process::Write32(0x70E494, 0x03A00001);		//0x70D4B4 EUR
			Process::Write32(0x70E494 + 4, 0x0A00000B);	//0x70D4B4 EUR

			IsCatalogOpen = false;
		}
	}

	void	DropAndDigAnywhere(MenuEntry *entry)
	{
		if(entry->WasJustActivated())
		{
			// Drop
			Process::Write32(0x1655EC, 0xE3A00001);								//0x16560C EUR
			Process::Write32(0x1655F8, 0xEA000006);								//0x165618 EUR
			Process::Write32(0x1654EC, 0xEA000005);								//0x16550C EUR
			Process::Write32(0x165580, 0xEA000010); //on other players			//0x1655A0 EUR

			// Dig
		}
		else if(!entry->IsActivated())
		{
			// Drop
			Process::Write32(0x1655EC, 0xEBA8068D);
			Process::Write32(0x1655F8, 0x1A000005);
			Process::Write32(0x1654EC, 0x0A000005);
			Process::Write32(0x165580, 0x0A000010); //on other players
		}
	}

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
					SetUpKB("Enter the ID of an animation." << Color::Lime << "\nHex: 0~EB & FF\nRandom animal capture = FF", true, 2, AnimID, AnimID);
					break;
				case 1: //Tool
					SetUpKB("Enter the ID of a tool." << Color::Lime << "\nHex: 334C~33A6 & 3729 & FFFF\nRandom tools = FFFF", true, 4, ToolID, ToolID);
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
					SetUpKB("Enter the ID of a hairstyle." << Color::Lime << "\nHex: 0~21", true, 2, Appearance[0], Appearance[0]);
					SetUpKB("Enter the ID of a hairstyle color." << Color::Lime << "\nHex: 0~F", true, 1, Appearance[1], Appearance[1]);
					SetUpKB("Enter the ID of an eye color." << Color::Lime << "\nHex: 0~4", true, 2, Appearance[2], Appearance[2]);
					break;
				case 6: //Custom Animation
					SetUpKB("Enter the ID of a custom animation." << Color::Lime << "\nHex: D~E2\nOperation button = " << Color::Green << "ON" << Color::Lime << "/" << Color::Red << "OFF", true, 2, C_AnimID, C_AnimID);
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
						
						Process::Write32(0x64DCB0, 0xE1A02005); //Disable Custom Animation
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
			Process::Write32(0x64DCB0, 0xE3A05000 + C_AnimID); // Enable Custom Animation
		else
		{
			Process::Write32(0x64DCB0, 0xE1A02005); // Disable Custom Animation
			EnablingC = false;
		}	

		if(!entry->Hotkeys[3].IsDown())
			Button = false;

		if(!entry->IsActivated())
			Process::Write32(0x64DCB0, 0xE1A02005); // Disable Custom Animation
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
			u32 AnimInstance = Player::GetAnimationInstance(PlayerInstance, 0, 0, 0);

			Process::Write32(0x677504, 0xE1A00000); //0x67653C EUR
			Process::Write32(0x628B54, 0xE3A01000 + DATAIndexRandom); //0x627B8C EUR
			
			for(u8 i = 0; i < 4; i++)
			{
        		Animation::DoMoonJump(AnimInstance, PlayerInstance);
				
				if((Player::GetOnlinePlayerIndex() & 3) == Player::GetActualPlayerIndex())
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

	void    InfiniteExpression(MenuEntry *entry)
    {
        if(entry->IsActivated())
			Process::Write32(0x65E9B0, 0xE3A010FF); //0x65D9E8 EUR
		else if(!entry->IsActivated())
			Process::Write32(0x65E9B0, 0xE1D010B0);
	}

	void	SlowMotionAnim(MenuEntry *entry)
	{
		if(!System::IsCitra) // can crash on citra
		{
			if(entry->WasJustActivated())
			{
				Process::WriteFloat(0x652C10, 8.0); //0x651C48 EUR
				Process::WriteFloat(0x887880, 6.0); //0x88670C EUR
				Process::Write32(0x654578, 0xE3A00001); //0x6535B0 EUR
			}
			if(!entry->IsActivated())
			{
				Process::WriteFloat(0x652C10, 1.0);
				Process::WriteFloat(0x887880, 1.0);
				Process::Write32(0x654578, 0x0A000004);
        	}
		}
	}

	u32 AntiAnimCheck(u32 pID)
	{
	    u32 PlayerInstance = Player::GetOffset(pID);
	    if(PlayerInstance == Player::GetOffset())
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
				case 0x68:
					for(u8 j = 0; j < 4; j++)
					{
						for(u8 i = 0; i < 4; i++)
						{
							ShowI_AcreID[j][i] = (Utils::Format("%02X", Town->IslandAcres[IslandAddage[j] + i])); //need changes
							screen.DrawSysfont(ShowI_AcreID[j][i], IslandArceID_XPos[i], IslandArceID_YPos[j], Color::Black);
							screen.DrawRect(IslandRect_XPos[i], IslandRect_YPos[j], 43, 43, Color::Black, false);
						}
					}
					break;
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

			switch (Player::ActualRoom())
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
		static const u32 value = 0xE3A00000;

		s8 uchoice = OpenList("Choose the weather you want.", WeatherOpt);
		if(uchoice < 0)
			return;

		if(uchoice == 7)
			Process::Write32(USA_Weather_Address, 0xE1A00004);
		else
		{
			Process::Write32(USA_Weather_Address, value + uchoice);
			OSD::Notify("Meteo:" + WeatherOpt[uchoice]);
		}
	}

    void	SeasonMod(MenuEntry *entry)
    {
		static const u32 value = 0xE3A01002;
		static const u8 offsets[4] = {0, 1, 5, 0x10};

		s8 uchoice = OpenList("Choose the season you want.", SaisonsOpt);
		if(uchoice < 0)
			return;
		
		Process::Write32(USA_Saison_Address, value + offsets[uchoice]);
		OSD::Notify("Season:" + SaisonsOpt[uchoice]);

		Game::AskReloadRoom();
    }

	void	FestivalMod(MenuEntry *entry)
	{
		static const u16 Festivals[5] = {0x3C04, 0x4004, 0x3F04, 0x3D44, 0x3EC4};

		s8 uchoice = OpenList("Choose the festival you want.", FestivalsOpt);
		if(uchoice < 0)
			return;

		if(*(u16 *)USA_Festival_Address == 0)
			return;

		Process::Write16(USA_Festival_Address, Festivals[uchoice]);
		Process::Write8(USA_Festival_Address + 2, 0x9B);
		OSD::Notify("Festival:" << Color::Lime << FestivalsOpt[uchoice]);

		Game::AskReloadRoom();
	}

	void    MainStreetShopOpen(MenuEntry *entry)
	{
		static const u32 Addresses[9] = 
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

		static const u32 value = 0xE3A00000;
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
        static const u16 offsets[6] = {0x45C8, 0x8A58, 0x8B1E, 0x8B3E, 0x8B40, 0x8B50}; 

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
		static vec32 IslandItemsCopyPaste;
		static vec32 IslandItemsDumpRestore;
    	static std::string IslandName;
		
        StringVector IslandsList;

		if (entry->Hotkeys[0].IsPressed())
        {
			if(Player::InLoadingState())
				return;

			if(!Player::IsInRoom(0x68))
			{
				OSD::Notify(Color::Orange << "You are not on the island!");
				return;
			}

			s8 uchoice = OpenList("Choose an option:" << Color::Yellow << "\n\nIsland Items Saves", IslandItemsOpt);
			if(uchoice == 0)
			{
				if(Game::GetMapItemsCount(false))
                {
                    if(!IslandItemsCopyPaste.empty())
					IslandItemsCopyPaste.clear();

                    IslandItemsCopyPaste = Game::GetMapItems(true);
					OSD::Notify(Color::Magenta << "Ctrl+C");
				}
				else
					OSD::Notify(Color::Yellow << "This island is empty!");
			}
			else if(uchoice == 1)
			{
				if(!IslandItemsCopyPaste.empty())
                {
                    u32 X = 0x10, Y = 0x10, Count = 0;
                    s32 i = -1;
                    bool Check = true;

                    Sleep(Milliseconds(500));
                    Process::Write32(0x5A11C8, 0xE3E00000); //0x5A0210 EUR
					Process::Write32(0x5A11CC, 0xEA000012); //0x5A0214 EUR
					Process::Write32(0x5A13C8, 0xE3A00000); //0x5A0410 EUR
					Process::Write32(0x5A13CC, 0xE8BD83F0); //0x5A0414 EUR
                    while(Check)
                    {
                        while(Check)
                        {
                            if((u32)Items::GetItemAtWorldCoords(X, Y))
                            {  
                                if(i != IslandItemsCopyPaste.size())
                                    i++;

                                if(*Items::GetItemAtWorldCoords(X, Y) == 0x80007FFE)
                                    Items::TrampleAt(X, Y);

                                if(Items::GetLockedSpotIndex(X, Y) != 0xFFFFFFFF)
                                    Items::ClearLockedSpot(X, Y, 0xA5);

                                if(*Items::GetItemAtWorldCoords(X, Y) != IslandItemsCopyPaste.at(i))
                                {
                                    if(Items::PlaceItemWrapper(0x1, 0xFFFFFFFF, &IslandItemsCopyPaste.at(i), &IslandItemsCopyPaste.at(i), X, Y, 0, 0, 0, 0, 0, 0x3D, 0xA5))
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
						Process::Write32(0x5A11C8, 0xE1A05001);
						Process::Write32(0x5A11CC, 0x1A000001);
						Process::Write32(0x5A13C8, 0xE24DD01C);
						Process::Write32(0x5A13CC, 0xE1A07001);
					}
					OSD::Notify(Color::Purple << "Ctrl+V");
				}

			}
			else if(uchoice == 2)
			{
				Directory Luna("Luna", true); //create the directory if it doesn't exist
				Directory dir("Luna/IslandSaves", true); //create the directory if it doesn't exist

        		if(Game::GetMapItemsCount(false))
        		{
					File IslandBackup;

					if(!IslandItemsDumpRestore.empty())
						IslandItemsDumpRestore.clear();

					IslandItemsDumpRestore = Game::GetMapItems(true);

            		if(SetUpKB("Name your backup." << Color::Yellow << "\n\nIsland Items Dumper", false, 20, IslandName, "", 0))
            		{
                		if(!File::Exists("Luna/IslandSaves/" + IslandName + ".bin"))
                		{
                    		File::Create("Luna/IslandSaves/" + IslandName + ".bin");
                    		File::Open(IslandBackup, "Luna/IslandSaves/" + IslandName + ".bin", File::WRITE | File::SYNC);

                    		for(int i = 0; i != IslandItemsDumpRestore.size(); i++)
                        		IslandBackup.Write(&IslandItemsDumpRestore.at(i), 4);

							MessageBox("Created file at:\n" << Color::Yellow << "Luna/IslandSaves/" + IslandName + ".bin").SetClear(ClearScreen::Top)();

                    		IslandBackup.Close();
                		}
                		else
                		{
                    		Sleep(Milliseconds(200));
                    		if(MessageBox(Color::Lime << IslandName + ".bin" << Color::White << " already exist!\n\n" << Color::Yellow << "Do you want to replace it?", DialogType::DialogYesNo)())
                    		{
                        		File::Open(IslandBackup, "Luna/IslandSaves/" + IslandName + ".bin", File::WRITE | File::SYNC);

                        		for(int i = 0; i != IslandItemsDumpRestore.size(); i++)
                            		IslandBackup.Write(&IslandItemsDumpRestore.at(i), 4);

                        		IslandBackup.Close();

                        		OSD::Notify("Updated file:" << Color::Lime << IslandName + ".bin");
                    		}
                		}
            		}
				}
				else
					OSD::Notify(Color::Yellow << "This island is empty!");
			}
			else if (uchoice == 3)
			{
				Directory Luna("Luna", true); //create the directory if it doesn't exist
				Directory dir("Luna/IslandSaves", true); // create the directory if it doesn't exist

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
        		IslandItemsDumpRestore.clear();
        		IslandItemsDumpRestore.resize(1024);

        		OSD::Notify(Color::DeepSkyBlue << "Loading...");

        		for(int i = 0; i != IslandItemsDumpRestore.size(); i++)
            		IslandFile.Read(&IslandItemsDumpRestore.at(i), 4);

        		dir.Close();
        		IslandFile.Close();

				u32 X = 0x10, Y = 0x10, Count = 0;
				s32 i = -1;
				bool Check = true;

				Sleep(Milliseconds(500));
                Process::Write32(0x5A11C8, 0xE3E00000);
				Process::Write32(0x5A11CC, 0xEA000012);
				Process::Write32(0x5A13C8, 0xE3A00000);
				Process::Write32(0x5A13CC, 0xE8BD83F0);
				while(Check)
                {
                    while(Check)
                    {
                        if((u32)Items::GetItemAtWorldCoords(X, Y))
                        {  
                            if(i != IslandItemsDumpRestore.size())
                                i++;

                            if(*Items::GetItemAtWorldCoords(X, Y) == 0x80007FFE)
                                Items::TrampleAt(X, Y);

                            if(Items::GetLockedSpotIndex(X, Y) != 0xFFFFFFFF)
                                Items::ClearLockedSpot(X, Y, 0xA5);

                            if(*Items::GetItemAtWorldCoords(X, Y) != IslandItemsDumpRestore.at(i))
                            {
                                if(Items::PlaceItemWrapper(0x1, 0xFFFFFFFF, &IslandItemsDumpRestore.at(i), &IslandItemsDumpRestore.at(i), X, Y, 0, 0, 0, 0, 0, 0x3D, 0xA5))
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
					Process::Write32(0x5A11C8, 0xE1A05001);
					Process::Write32(0x5A11CC, 0x1A000001);
					Process::Write32(0x5A13C8, 0xE24DD01C);
					Process::Write32(0x5A13CC, 0xE1A07001);
				}
				OSD::Notify("Readed file:" << Color::Lime << IslandsList.at((size_t)User_Choice));
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
		static u8 IslandAcres[16] =
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
		static u8 IslandAcres[16] =
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

		s8 uchoice = OpenList("", list);
		s8 uchoice2 = OpenList("", list2);
		if(uchoice2 == 0)
		{
			SetUpKB("Entre l'ID d'un batiment:", true, 2, isl.b[uchoice].id, isl.b[uchoice].id);
		}
		else if(uchoice2 == 1)
		{
			SetUpKB("Entrer coordinates " << Color::Yellow << "\"X\"" << Color::White << " of building:", true, 2, isl.b[uchoice].x, isl.b[uchoice].x);
			SetUpKB("Entrer coordinates " << Color::Yellow << "\"Y\"" << Color::White << " of building:", true, 2, isl.b[uchoice].y, isl.b[uchoice].y);
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
		static const u8 CountryListID[2] = {0, 0xFF};
		static const u32 value = 0xE3A00000;

		s8 uchoice = OpenList("Choose the island you want to go on.", CountryOpt);
		if(uchoice < 0)
			return;

		if(uchoice == 0)
			Process::Write32(0x350B18, 0xE1A00C20); //0x34FC60 EUR
		else
			Process::Write32(0x350B18, value + CountryListID[uchoice]);

		OSD::Notify("Country set to:" << Color::Lime << CountryOpt[uchoice]);
	}

	void    EnableAllTours(MenuEntry *entry)
    {
        if(entry->WasJustActivated()) 
		{
			Process::Write32(USA_Tours_Address, 0xE1A00000); //unsure? (still keeping it for safety)
			Process::Write32(USA_Tours_Address + 0x54, 0xE1A00000); //Adds tour difficulty
			Process::Write32(USA_Tours_Address + 0xD0, 0xE1A00000); //Adds tour names and tour infos
			Process::Write32(USA_Tours_Address + 0x138, 0xE1A00000); //Adds tour time
			Process::Write32(USA_Tours_Address + 0xA8, 0xE2800001); //Adds all tours to be selectable
		}
		else if(!entry->IsActivated()) 
		{
			Process::Write32(USA_Tours_Address, 0x0A000004);
			Process::Write32(USA_Tours_Address + 0x54, 0x0A000004);
			Process::Write32(USA_Tours_Address + 0xD0, 0x0A000004);
			Process::Write32(USA_Tours_Address + 0x138, 0x0A000004); 
			Process::Write32(USA_Tours_Address + 0xA8, 0x12800001);
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
    		Address = Player::GetPlayerSave(i);
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
		if(entry->IsActivated())
		{
			KbExtender = true;
        	if(!Chat::IsOpen())
				return;

            Process::Write8(USA_Chat_Pointer + 0xC, 0x41);
            Process::Write8(USA_Chat_Pointer + 0x12B, 0x44);
		}
		if(!entry->IsActivated())
		{
			KbExtender = false;
		}
    }

	void	CustomKeyboard(MenuEntry *entry)
    {
		static const u16 Empty = 2;
        static bool Enabling = false;

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

	/*
	Visual / Sound Codes
	*/

	void	GameSpeed(MenuEntry *entry)
    {
    	if(entry->IsActivated())
			Process::Write32(0x54DDB4, Player::InLoadingState() ? 0xE59400A0 : 0xE3E004FF); //0x54CDFC EUR
		else if(!entry->IsActivated()) 
			Process::Write32(0x54DDB4, 0xE59400A0);
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

	void	ChangeFOV(MenuEntry *entry)
	{
		static float OnOff = 1.0;
		if(entry->IsActivated())
		{
			if(Player::IsInRoom(1) || Fov)
				OnOff = 1.0;
			else 
				OnOff = FloatFov;
			
			Process::WriteFloat(0x47E48C, OnOff); //0x47D4D4 EUR
		}
		if(!entry->IsActivated()) 
			Process::WriteFloat(0x47E48C, 1.0);
	}

	void	SetFOV(MenuEntry *entry)
	{
		float SetFloatFov;
		SetUpKB("Entre une ID:" << Color::Lime << "\nFloat: 0.70~1.00", false, 4, SetFloatFov, FloatFov);

		if(IDList::ValidIDFloat(SetFloatFov, 0.69, 1.0))
			FloatFov = SetFloatFov;
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

	void	AlwaysCherryBlossomTrees(MenuEntry *entry)
	{
		if(entry->WasJustActivated())
		{
			Process::Write32(0x296A64, 0xE3A00001);
			Process::Write32(0x296A8C, 0xE3A00001);
			Process::Write32(0x296AB4, 0xE3A00004);
			Process::Write32(0x296AC4, 0xE3A01001);
			Process::Write32(0x296ACC, 0xFF);
			Process::Write32(0x59ABEC, 0xE3A08005);
			Process::Write32(0x59AD3C, 0xE28F2074);
			Process::Write32(0x62FC30, 0xE3A00000);
		}
		else if(!entry->IsActivated())
		{
			Process::Write32(0x296A64, 0xE596000);
			Process::Write32(0x296A8C, 0xEB0E686A);
			Process::Write32(0x296AB4, 0xE5DD0004);
			Process::Write32(0x296AC4, 0xE2401007);
			Process::Write32(0x296ACC, 0x93A0003C);
			Process::Write32(0x59ABEC, 0xE1A08000);
			Process::Write32(0x59AD3C, 0xE28F206C);
			Process::Write32(0x62FC30, 0xE1A00004);
		}
	}

	void	DisableScreenshots(MenuEntry *entry)
    {
        if(entry->WasJustActivated())
            Process::Write32(0x5B41A8, 0xE3A00001);

        if(!entry->IsActivated())
            Process::Write32(0x5B41A8, 0xE3500000);
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

		static const u16 offsets[4] = {0x6F08, 0x6B8C, 0x8D1C, 0x6B9C};
		static const u8 numbersmax[4] = {5, 9, 5, 5};

		s8 uchoice = OpenList("", MoneysOpt);
		if(uchoice < 0)
            return;

		u32 input = 0;
		if(!SetUpKBNo("", false, numbersmax[uchoice], input))
            return;

		Process::Write64(Player::GetPlayerSave() + offsets[uchoice], Game::EncryptACNLMoney(input));
    }

    void    PlayerOptionsMod(MenuEntry *entry)
	{
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

		u8 input;

		s8 uchoice = OpenList("Choose an option:" << Color::Red << "\nOFFLINE", PlayerOpt);
        switch(uchoice)
        {
            case 0:
			case 1:
			case 2:
            case 3:
            {
                if(!SetUpKBNo("Type an ID:" << Color::Lime << HexList[uchoice], true, 2, input))
                    return;
                
                Process::Write8(Player::GetPlayerSave() + 4 + uchoice, input);

                Game::AskReloadRoom();
                break;
            }
            case 4:
            {
                if(!SetUpKBNo("Type an ID:" << Color::Lime << "\nHex: 0~F", true, 1, input))
                    return;
                
                Process::Write8(USA_Tan_Address, input);

                Game::AskReloadRoom();
                break;
            }
            case 5:
            {
                s8 Genderchoice = OpenList("", GenderOpt);
        	    if(Genderchoice < 0)
            	    return;
                
                Process::Write8(USA_Gender_Address, Genderchoice);
                
                Game::AskReloadRoom();
                break;
            }
            case 6:
            {
                s8 RegionChoice = OpenList("Country or Region?", RegionOpt);
                if(RegionChoice == 0)
                {
                    if(!SetUpKBNo("Country ID:" << Color::Lime << "\nDec: 1~52", false, 2, input))
                        return;
                    
                    Process::Write8(Player::GetPlayerSave() + 0x55D2, input);
                }
                else if(RegionChoice == 1)
                {
                    if(!SetUpKBNo("Region ID:" << Color::Lime << "\n(Depends on the country)", false, 2, input))
                        return;
                    
                    Process::Write8(Player::GetPlayerSave() + 0x55D3, input);
                }
                break;
            }
            default:
                break;
        }
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

		if((entry->Hotkeys[0].IsPressed()))
        {
			if(*(u32 *)0x75F010 == 0xE1500000)
			{
				ControlPlayer = true;
				Process::Write32(0x75F010, 0xE3520000);
                Process::Write8(0x75F020, 0);
                OSD::Notify("Control player:" << Color::Red << "OFF");
				ControlPlayer = false;
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

                Process::Write32(0x75F010, 0xE1500000);
                Process::Write8(0x75F020, SelectedPlayerIndex);
                OSD::Notify("Control player " << PlayerColor << Utils::Format("%01X", SelectedPlayerIndex) << Color::White << ":" << Color::Green << "ON");
            }
            else
            {
                Process::Write32(0x75F010, 0xE3520000);
                Process::Write8(0x75F020, 0);
                OSD::Notify("Control player:" << Color::Red << "OFF");
            }
			ControlPlayer = false;
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
			float X = *Player::GetCoordinates(SelectedPlayerIndex), Z = *(float *)((u32)Player::GetCoordinates(SelectedPlayerIndex) + 8);

			if(!MapEditorActive)
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
				if(MapEditorActive) screen.DrawRect((u32)(33.0f + ((selectedX * 0x20 + 0x10) / 14.2f)), (u32)(14.0f + ((selectedY * 0x20 + 0x10) / 14.2f)), 4, 4, Color::Black);
				// if(NPC::GetCoordinatesRef(npc, X, Z)) screen.DrawRect((u32)(33.0f + (X / 14.2f)), (u32)(14.0f + (Z / 14.2f)), 4, 4, Color::Orange);
			}
			if(Player::IsInRoom(0x68))
			{
				if(Player::GetCoordinatesRef(X, Z, 0)) screen.DrawRect((u32)(73.0f + (X / 12.1f)), (u32)(30.6f + (Z / 12.1f)), 6, 6, Color::Blue);
				if(Player::GetCoordinatesRef(X, Z, 1)) screen.DrawRect((u32)(73.0f + (X / 12.1f)), (u32)(30.6f + (Z / 12.1f)), 6, 6, Color::Red);
				if(Player::GetCoordinatesRef(X, Z, 2)) screen.DrawRect((u32)(73.0f + (X / 12.1f)), (u32)(30.6f + (Z / 12.1f)), 6, 6, Color::Green);
				if(Player::GetCoordinatesRef(X, Z, 3)) screen.DrawRect((u32)(73.0f + (X / 12.1f)), (u32)(30.6f + (Z / 12.1f)), 6, 6, Color::Yellow);
				if(MapEditorActive) screen.DrawRect((u32)(74.0f + ((selectedX * 0x20 + 0x10) / 12.1f)), (u32)(31.6f + ((selectedY * 0x20 + 0x10) / 12.1f)), 4, 4, Color::Black);
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
			Directory Luna("Luna", true); // Create the directory if it doesn't exist
			Directory dir(OutFitsFolder, true); // Create the directory if it doesn't exist
			
			s8 uchoice = OpenList(Color::Yellow << "Magic Wand ACNH", OutfitsOpt);
			switch(uchoice)
			{
				case 0: // Save actual player outfit into a file
				{
					std::string OutfitName;
					if(SetUpKB("Name your outfit." << Color::Yellow << "\n\nOutfits Saver", false, 20, OutfitName, "", 0))
					{
						Outfit ReadedOutfit;
						u16 ActualPlayerOutfit[6];
						for(u8 i = 0; i < 7; i++)
						{
							if(i != 3) // jump, there is nothing here (maybe girl outfit?)
							{
								if(i > 3)
									Process::Read16((USA_Outfit_Address + (i * 4)), ActualPlayerOutfit[(i - 1)]); // Read actual each piece of player outfit
								else
									Process::Read16((USA_Outfit_Address + (i * 4)), ActualPlayerOutfit[i]); // Read actual each piece of player outfit
							}
						}

						File OutfitSave;

						StringVector FileExist;
						dir.ListFiles(FileExist, ".txt"); // Read all .txt inside the folder

						// If .txt savefile doesnt exist
						if(!File::Exists(OutFitsFolder + "/Outfits.txt"))
						{
							OSD::Notify(Color::DeepSkyBlue << "Creating a new savefile...");
							File::Create("Luna/Outfits/Outfits.txt");
							Sleep(Milliseconds(500));
						}

						// Open savefile in APPEND mode to go at the end
						if(File::Open(OutfitSave, OutFitsFolder + "/Outfits.txt", File::RWC | File::APPEND) == 0)
						{
							std::string line = Utils::Format("\n//\nName: %s\n0x%04X\n0x%04X\n0x%04X\n0x%04X\n0x%04X\n0x%04X",
								OutfitName.c_str(), // Convert "std::string" in "const char*"
								ActualPlayerOutfit[0],
								ActualPlayerOutfit[1],
								ActualPlayerOutfit[2],
								ActualPlayerOutfit[3],
								ActualPlayerOutfit[4],
								ActualPlayerOutfit[5]);

							OutfitSave.Write(line.c_str(), line.size());

							OutfitSave.Close();
							OSD::Notify("Outfit saved -> " << Color::Lime << OutfitName);
						}
						else
						{
							MessageBox(Color::Red << "Error", "Failed to open the file for saving!")();
						}
					}
					break;
				}
				case 1: // Read an outfit from a file and apply to the player
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
					if(File::Open(OutfitRestore, OutFitsFolder + "/Outfits.txt", File::READ) == 0)
					{
						// Get size of the file
						u64 FileSize = OutfitRestore.GetSize();

						// Read savefile contents in a buffer
						vecchar buffer(FileSize + 1, 0); // +1 for the null character
						OutfitRestore.Read(buffer.data(), FileSize);
						OutfitRestore.Close();

						// Convert buffer to string
						std::string FileContent(buffer.data());

						// Use a stringstream to read the content line by line
						std::stringstream ss(FileContent);
						std::string line;
						Outfit ReadedOutfit;
						bool ReadingOutfit = false;

						while(std::getline(ss, line))
						{
							// Delete spaces and comments (after "//")
							line = line.substr(0, line.find("//"));
							line.erase(0, line.find_first_not_of(' ')); // Remove spaces at the beginning
							line.erase(line.find_last_not_of(' ') + 1); // Remove spaces at the end

							if(line.empty())
							{
								// If the line is empty, it’s the end of an outfit
								if(ReadingOutfit && !ReadedOutfit.OutfitPiece.empty())
								{
									PlayerOutfit.push_back(ReadedOutfit);
									ReadedOutfit = Outfit(); // Reset for next outfit
									ReadingOutfit = false;
								}
							}
							else if(line.find("Name:") == 0)
							{
								// If the line starts with "Name:", it is the name of the outfit
								ReadedOutfit.Name = line.substr(5); // Extract name after "Name: "
								ReadingOutfit = true;
							}
							else if(ReadingOutfit)
							{
								// Convert line in u16
								u16 value;
								std::stringstream LineStream;
								LineStream << std::hex << line; // Read hexa
								LineStream >> value;
								ReadedOutfit.OutfitPiece.push_back(value);
							}
						}

						// Add last outfit if it was not added
						if(!ReadedOutfit.OutfitPiece.empty())
						{
							PlayerOutfit.push_back(ReadedOutfit);
						}
					}
					else
					{
						MessageBox(Color::Red << "Error", "\"Outfits.txt\" not found!")();
						break;
					}

					if(PlayerOutfit.empty())
					{
						MessageBox(Color::Red << "Error", "No outfits found in the file!")();
						break;
					}

					StringVector OutfitsList;
					for(const Outfit& outfit : PlayerOutfit)
					{
						OutfitsList.push_back(outfit.Name);
					}

					s8 OutfitChoice = OpenList("Select an outfit to load." << Color::Yellow << "\n\nOutfits Loader", OutfitsList);
					if(OutfitChoice < 0)
						break;
				
					if(PlayerOutfit[OutfitChoice].OutfitPiece.size() == 6) // If there are 6 cloth pieces in the saved outfit.
					{
						Player::SetOutfit(PlayerOutfit[OutfitChoice].OutfitPiece[0], PlayerOutfit[OutfitChoice].OutfitPiece[1], PlayerOutfit[OutfitChoice].OutfitPiece[2], PlayerOutfit[OutfitChoice].OutfitPiece[3], PlayerOutfit[OutfitChoice].OutfitPiece[4], PlayerOutfit[OutfitChoice].OutfitPiece[5]);
						OSD::Notify("Outfit applied ->" << Color::Lime << OutfitsList[OutfitChoice]);
					}
					else
						MessageBox(Color::Red << "Error", "Invalid number of values in the outfit!" << Color::Magenta << "Expected values:6")();
					break;
				}
				default:
					break;
			}
		}
	}

	/*
	Save Codes
	*/

	void	PlayerNameChanger(MenuEntry* entry)
    {
		static const u16 offset = 0x55A8;
		std::string input;
		
        Keyboard Name("Entrez le nom que vous souhaitez avoir:" << Color::Yellow << "\n\nPlayer Name changer");
        Name.SetMaxLength(8);
        if(Player::GetPlayerSave() == 0)
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
            Process::Write32((Player::GetPlayerSave() + offset), 0);
            Process::Write32((Player::GetPlayerSave() + offset + 0x4), 0);
            Process::Write32((Player::GetPlayerSave() + offset + 0x8), 0);
            Process::Write32((Player::GetPlayerSave() + offset + 0xC), 0);

			switch(uchoice)
			{
				case 0: // Normal
					Process::WriteString((Player::GetPlayerSave() + offset), input, StringFormat::Utf16);
					break;
				case 1: // Align Left   0x0009 = big Seperator
					Process::WriteString((Player::GetPlayerSave() + offset), input, StringFormat::Utf16);
                    Process::Write16((Player::GetPlayerSave() + offset + (input.size() * 0x2)), 0x9);
					break;
				case 2: // Align Right   0x0009 = big Seperator
					Process::Write16((Player::GetPlayerSave() + offset), 0x9);
                    Process::WriteString((Player::GetPlayerSave() + offset + 0x2), input, StringFormat::Utf16);
					break;
				case 3: // Higher   0x000A = next Line
					Process::WriteString((Player::GetPlayerSave() + offset), input, StringFormat::Utf16);
                    Process::Write16((Player::GetPlayerSave() + offset + (input.size() * 0x2)), 0xA);
					break;
				case 4: // Lower   0x000A = next Line
					Process::Write16((Player::GetPlayerSave() + offset), 0xA);
                    Process::WriteString((Player::GetPlayerSave() + offset + 0x2), input, StringFormat::Utf16);
					break;
				case 5: // Empty   0x000E <= makes string Invalid
					Process::Write16((Player::GetPlayerSave() + offset), 0xE);
                    Process::WriteString((Player::GetPlayerSave() + offset + 0x2), input, StringFormat::Utf16);
					break;
				default:
					break;
			}
		}
        else if (input.size() == 8) 
		{
            //Wipe Name String entirely first
            Process::Write32((Player::GetPlayerSave() + offset), 0);
            Process::Write32((Player::GetPlayerSave() + offset + 0x4), 0);
            Process::Write32((Player::GetPlayerSave() + offset + 0x8), 0);
            Process::Write32((Player::GetPlayerSave() + offset + 0xC), 0);
            Process::WriteString((Player::GetPlayerSave() + offset), input, StringFormat::Utf16);
        }
    }

	void	TownNameChanger(MenuEntry *entry)
    {
        std::string input;

        Keyboard TownName("Enter the name of the town \nyou wish to have:" << Color::Yellow << "\n\nTown Name changer");
        TownName.SetMaxLength(8);
        if(TownName.Open(input) < 0)
			return;

        Process::WriteString(Player::GetPlayerSave() + 0x55BE, input, StringFormat::Utf16);
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

	void	DumpSave(MenuEntry* entry)
    {
        File Garden; //File Object
		Directory Luna("Luna", true); //create the directory if it doesn't exist
        Directory dir("Luna/Towns", true); //Create the directory if it doesn't exist
 
        Keyboard keyboard("Name the town you want to dump." << Color::Yellow << "\n\nGarden Dumper");
 
        std::string savename;  //name for the save
 
        if(keyboard.Open(savename) < 0)
			return;

        if(savename.find(".dat") == std::string::npos) //if the entered name haven't got .dat at the end
            savename += ".dat";                         //add .dat
        if(dir.OpenFile(Garden, savename, File::RWC) == 0)
        {
            if((Garden.Dump(0x31F26F80, 0x89B00)) == 0)
                MessageBox("Created file at:\n" << Color::Yellow << "Luna/Towns/" + savename).SetClear(ClearScreen::Top)();
            else //if Failed
                MessageBox(Color::Red << "Error", Color::White << "Unable to create backup file.").SetClear(ClearScreen::Top)();
        }//if Failed
        else MessageBox(Color::Red << "Error", Color::White << "Unable to create/open file.").SetClear(ClearScreen::Top)();
    }
 
    void	RestoreSave(MenuEntry* entry)
    {
        StringVector GardenList; //Vector for our Save Names
        File Garden; //File Object

		Directory Luna("Luna", true); //create the directory if it doesn't exist
		Directory dir("Luna/Towns", true); //Create the directory if it doesn't exist
		Directory::Open(dir, "Luna/Towns");
        dir.ListFiles(GardenList, ".dat");

        if(GardenList.empty())
        {
            MessageBox(Color::Yellow << "No backup is available!").SetClear(ClearScreen::Top)();
            dir.Close();
            return;
        }
 
        Keyboard RestoreSave("Select the backup to restore." << Color::Yellow << "\n\nGarden Restore");
        RestoreSave.Populate(GardenList);
		s8 uchoice = RestoreSave.Open();
 
        if(uchoice < 0)
			return;

        if(dir.OpenFile(Garden, GardenList[uchoice], File::RW) == 0)
        {
            if((Garden.Inject(0x31F26F80, 0x89B00)) == 0)
			{
                MessageBox(Color::Green << "You have restored your backup!").SetClear(ClearScreen::Top)();
				
				Game::AskReloadRoom();
			}
            else //if failed
				MessageBox(Color::Red << "Error", Color::White << "Unable to inject the backup file.").SetClear(ClearScreen::Top)();
        }// if Failed
        else MessageBox(Color::Red << "Error", Color::White << "Unable to open the file.").SetClear(ClearScreen::Top)();
    }

	void    Badges(MenuEntry *entry)
    {
		s8 uchoice = OpenList("", BadgesOpt);
		if(uchoice == -1 || (*(u8 *)USA_Player_Address > 0x3))
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
				static u8 encyclopediabuffer[] =
				{ 
					0xCC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
					0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD0, 0x9A
				};
				Process::CopyMemory(reinterpret_cast<void *>(Player::GetPlayerSave() + 0x6C70), encyclopediabuffer, sizeof(encyclopediabuffer));
				break;
			case 1: //Emoticons
				static u8 emoticonbuffer[] =
				{ 
					0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 
					0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x20, 0x21, 0x24, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2E
				};
				Process::CopyMemory(reinterpret_cast<void *>(Player::GetPlayerSave() + 0x89D0), emoticonbuffer, sizeof(emoticonbuffer));
				break;
			case 2: //Song
				for(u8 i = 0; i < 3; i++)
					Process::Write32(Player::GetPlayerSave() + 0x8F9C + (i * 4), 0xFFFFFFFF);
				break;
			case 3: //Catalog
				std::memset((void *)(Player::GetPlayerSave() + 0x6C90), 0xFF, 106 * 4);
				break;
			default: 
				break;
        }
    }

	void 	DreamCodeModifier(MenuEntry *entry)
    {
		u8 Part1, Part2;
        u32 Part3;

		if(!SetUpKBNo("Dial the dream code numbers\nyou would like to have." << Color::Lime << "\n 2 Numbers", true, 2, Part1))
			return;

		if(!SetUpKBNo("Dial the dream code numbers\nyou would like to have." << Color::Lime << "\n 2 Numbers", true, 2, Part2))
			return;

		if(!SetUpKBNo("Dial the dream code numbers\nyou would like to have." << Color::Lime << "\n 8 Numbers", true, 8, Part3))
			return;

		Process::Write16(0x31F2C711, Part1);
		Process::Write16(0x31F2C714, Part2);
		Process::Write16(0x31F2C710, Part3);
		MessageBox(Color::Green << "Success!", Color::White << "\nNew dream code:\n" << Color::Yellow << Utils::Format("%02X", Part1) + Utils::Format("%02X", Part2) + "-" + Utils::Format("%04X", (Part3 >> 16) & 0xFFFF) + "-" + Utils::Format("%04X", Part3 & 0xFFFF)).SetClear(ClearScreen::Top)();
    }

	/*
	Misc Codes
	*/

	void	DisableSaveMenu(MenuEntry *entry)
	{
		if(entry->WasJustActivated())
		{
			Process::Write32(USA_SaveMenu_Address, 0xE1A00000);
			Process::Write32(0x1A0968, 0xE1A00000);
     		Process::Write32(0x1A096C, 0xE3A00000);
        	Process::Write32(0x1A0970, 0xEB0E069C);
			Save = false;
		}
		else if(!entry->IsActivated())
		{
			Process::Write32(USA_SaveMenu_Address, 0xE8900006);
			Process::Write32(0x1A0968, 0xE3A01040);
			Process::Write32(0x1A096C, 0xE5900000);
			Process::Write32(0x1A0970, 0xEB14D0AB);
			Save = true;
		}
	}

	void	FastMenus(MenuEntry *entry)
	{
		if(entry->WasJustActivated())
			Process::Write32(0x56A2C0, 0x7F7FFFFF);
		else if(!entry->IsActivated())
			Process::Write32(0x56A2C0, 0x3F800000);
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
		if(Player::GetWorldCoords(&x, &y) && !Player::InLoadingState() && !IsCatalogOpen)
		{
			Process::Write32(0x6D3CB4, 0xE3A0002E);
			Process::Write32(0x6578B0, 0xE3A0101A);
			Animation::ExecuteAnimationWrapper(Player::GetActualPlayerIndex(), 0x3F, 0, 1, 1, 1, 0, x, y, true);
			MessageBox(Color::Green << "Success!", Color::White << " Note:" << Color::Yellow << "\nPlease close the plugin menu \nif you want to change the time.").SetClear(ClearScreen::Top)();
		}
	}

	void	ToolsEffects(MenuEntry *entry)
    {
		static const u16 ToolsListID[12] = {0x335B, 0x3357, 0x3353, 0x335F, 0x334F, 0x3363, 0x3365, 0x338F, 0x338E, 0x336B, 0x336A, 0x3368};

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
			Process::Write32(0x5971D4, 0xE1A00000);
			Process::Write32(0x5971DC, 0xE1A00000);
			Process::Write32(0x5971E4, 0x1A00001B);
			Process::Write32(0x5971EC, 0xEA000080);
			Process::Write32(0x59945C, 0xE1A00000);
		}
		else if(!entry->IsActivated())
		{
			Process::Write32(0x5971D4, 0x0A000008);
			Process::Write32(0x5971DC, 0x0A00005B);
			Process::Write32(0x5971E4, 0x0A00001B);
			Process::Write32(0x5971EC, 0x0A000080);
			Process::Write32(0x59945C, 0xCA000005);
		}
	}

	void	ParticlesSpawner(MenuEntry *entry)
	{
		static u16 ParticleID = 0x20C;
		
		// Display interval
		static const float ParticleSpace = 32.0f;
		
		float ParticleCoords[3];
		
		if(entry->Hotkeys[0].IsPressed())
		{
			SetUpKB("Type the ID of a particle:" << Color::Lime << "\nHex: 0~FFFF", true, 4, ParticleID, ParticleID);
		}
		if(Turbo ? entry->Hotkeys[1].IsDown() : entry->Hotkeys[1].IsPressed())
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

		static const float Coords[3][3] =
		{
			{0, 0, 0},
			{-32, 0, -32},
			{-64, 0, -64},
		};

		static const u8 Sizes[3][3] =
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
			Process::Write32(0x5B4B60, 0xE3A00001); //allow wallpaper change
            Process::Write32(0x5B5268, 0xE1A00000);
            Process::Write32(0x5B5284, 0xEA000026);
			Process::Write32(0x5B7558, 0xE3A00001); //lightswitch
        }
        else if(!entry->IsActivated())
        {
			Process::Write32(0x5B4B60, 0xE3A00000); //allow wallpaper change
            Process::Write32(0x5B5268, 0x0A00000D);
            Process::Write32(0x5B5284, 0x0A000026);
			Process::Write32(0x5B7558, 0xE3A00000); //lightswitch
        }
    }

	void	SkipIsabelle(MenuEntry *entry)
	{
		if(entry->IsActivated())
		{
        	if(Player::IsInRoom(0x63, Player::GetActualPlayerIndex(), true) && !Game::IsSaving())
				Process::Write32(0x31FF599C, 0xFEDFEDFF);
		}
    }

	void	AddressTest(MenuEntry *entry)
	{
		static u32 readaddress;
		static u32 readvalue;
		static u32 writeaddress;
		u32 writevalue;
		if(entry->Hotkeys[0].IsPressed())
		{
			SetUpKB("Enter an address. Read", true, 8, readaddress, readaddress);
		}
		if(entry->Hotkeys[1].IsPressed())
		{
			Process::Read32(readaddress, readvalue);
			OSD::Notify("Address Readed");
		}
		if(entry->Hotkeys[2].IsPressed())
		{
			OSD::Notify(Utils::Format("Addr:0x%08X", readaddress) << Utils::Format(" Value:0x%08X", readvalue));
		}
		if(entry->Hotkeys[3].IsPressed())
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
			"Get Player 3DS Friend Code",
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
				{
					u8 PlayerIndex = 4;
					if(!SetUpKB("Player Index:\nType > or = 4, to get yours", true, 1, PlayerIndex, PlayerIndex))
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
					break;
				}
				case 2:
					OSD::Notify(Utils::Format("Online Player Count:%02X", Game::GetOnlinePlayerCount()));
					break;
				default:
					break;
			}
		}
	}
}