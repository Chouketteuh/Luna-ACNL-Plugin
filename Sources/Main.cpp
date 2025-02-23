#include "Cheats.hpp"
#include "QuickMenu.hpp"
#include "KeySequence.hpp"
#include "Strings.hpp"
#include "3ds.h"
#include <cstdarg>

namespace CTRPluginFramework
{
	// A =  / B =  / X =  / Y =  / L =  / R =  / Up =  / Down =  / Left =  / Right =  / Smiley =  / Cloud = 

	// Folders
	MenuFolder *OptionsFolder;
	MenuFolder *MovementsFolder;
	MenuFolder *ItemsFolder;
	MenuFolder *AnimationsFolder;
	MenuFolder *EnvironnementFolder;
	MenuFolder *IslandFolder;
	MenuFolder *KeyboardChatFolder;
	MenuFolder *VisualSoundsFolder;
	MenuFolder *PlayerFolder;
	MenuFolder *SaveFolder;
	MenuFolder *MiscellaneousFolder;
	MenuFolder *DevFolder;


	//Exemple: new MenuEntry(rouge + "Speed Hack" + Soon, SpeedHack, SpeedHackNote),
	const std::string Soon = " | Soon... ";
	const std::string Crash = " | Crash ";
	const std::string Test = " | Testing ";
	const std::string USA = " | USA Only ";
	const std::string Online = " | Online Only ";

	// Notes / Descriptions
	const std::string OnOffNote = Color::Yellow << "ON/OFF";
	const std::string MenuNote = Color::Yellow << "Open menu";
	const std::string SelectModeNote = Color::Yellow << "Mode selector";
	const std::string ReloadNote = Color::Yellow << "Reload the area to see all the effects.";
	const std::string TurboNote = Color::Yellow << "Affected by turbo mode.";

	const std::string SetSeedersNote = "Sets ID for:" << Color::DeepSkyBlue << "\n-1st slot of the inventory (+ copy)\n-All droppers\n-PickUp Mod\n-Map Editor" << Color::White;
	const std::string TouchDropNote = "BEST DROP EVER\n\n" + TurboNote;
	const std::string AnimModNote = "Select your animation with the\nanimation selector,\nthen execute it with (Execution Key)\n\n" + TurboNote << Color::White;
	const std::string ForceAnimationsToOthersNote = "Force on everyone:" << Color::DeepSkyBlue << "\n-Animations\n-Moonjump\n-Restore movements (Idle)\n\n" + TurboNote << Color::White;
	const std::string OnlineIslandModelNote = " If you want this cheat working " << Color::White << "\n\n-Enable it before going to the online island\n-Require to be the host\n(The one with the chat bar in " << Color::Blue << "BLUE" << Color::White << ")";
	const std::string ChatSpamNote = "Let you spam the last message you sended!" << Color::Yellow << "Cannot be used with \"Keyboard Extender\".";

    #define MAJOR_VERSION		2
	#define MINOR_VERSION		0
	#define REVISION_VERSION	0
	#define STRINGIFY(x)		#x
	#define TOSTRING(x)			STRINGIFY(x)
	#define STRING_VERSION		"[" TOSTRING(MAJOR_VERSION) "." TOSTRING(MINOR_VERSION) "." TOSTRING(REVISION_VERSION) "]"
    static const std::string	PluginName = "" << Color::Magenta << "UN" << Color::Purple << " CN PUGIN";
    static const std::string	Credits =
		"LUNA ACNL PLUGIN - Version" STRING_VERSION "\n"
		"Creation date:26/04/19\n\n"
		" Credits \n"
		" Thib:Creator of this plugin.\n"
		" Kominost:Developer & cheats creator.\n"
		" Woshishee:Help with updates and plugin operation.\n"
		" FOXXY/FEX plugin:Multiple additions of cheats to the plugin.\n"
		" RyDog plugin:Multiple additions of cheats to the plugin.\n"
		" Vapecord plugin:Multiple additions of cheats to the plugin.\n\n"
		"Discord:thib.py\n";

	// This function is called before main and before the game starts
	// Useful to do code edits safely
	void	PatchProcess(FwkSettings &settings)
	{
		settings.ThreadPriority = 0x30;

		ToggleTouchscreenForceOn();
		settings.CachedDrawMode = true;

		// Initialize settings
		settings.AllowActionReplay = true;
        settings.AllowSearchEngine = true;
        settings.AreN3DSButtonsAvailable = true;
        settings.TryLoadSDSounds = true;

		// Plugin interface color changer
		settings.WindowTitleColor = Color::Yellow;
		settings.MenuUnselectedItemColor = Color::Silver;
		settings.Keyboard.Background = Color::Black;
		settings.Keyboard.KeyBackground = Color::Black;
		settings.Keyboard.KeyBackgroundPressed = Color::DimGrey;
		settings.Keyboard.KeyText = Color::Yellow;
		settings.Keyboard.KeyTextPressed = Color::Yellow;
		settings.Keyboard.Cursor = Color::Yellow;
		settings.Keyboard.Input = Color::Yellow;
		settings.CustomKeyboard.BackgroundMain = Color::Black;
		settings.CustomKeyboard.BackgroundSecondary = Color::Black;
		settings.CustomKeyboard.BackgroundBorder = Color::Silver;
		settings.CustomKeyboard.KeyBackground = Color::Black;
		settings.CustomKeyboard.KeyBackgroundPressed = Color::DimGrey;
		settings.CustomKeyboard.KeyText = Color::Yellow;
		settings.CustomKeyboard.KeyTextPressed = Color::Yellow;
		settings.CustomKeyboard.ScrollBarBackground = Color::DimGrey;
		settings.CustomKeyboard.ScrollBarThumb = Color::Yellow;
	}

	// This function is called when the process exits
	// Useful to save settings, undo patchs or clean up things
	void	OnProcessExit(void)
	{
		ToggleTouchscreenForceOn();
	}

	static const std::string	UnsupportedVersion = "" << Color::Red << "INVALID " << Color::White << "Version\n\nUpdate to: " << Color::Green << "ver. 1.5";

	static bool	CheckGameVersion(void)
	{
		u16 Version = Process::GetVersion();

		if(Version != 6192 && (!System::IsCitra))
			goto unsupported;

		return(0);

		unsupported:
		(MessageBox(UnsupportedVersion))();
		return(1);
	}

	void	DevMenuCallback(void)
	{
		static KeySequence ButtonsCombo({ Key::DPadUp, Key::DPadUp, Key::DPadDown, Key::DPadDown, Key::DPadLeft, Key::DPadRight, Key::DPadLeft, Key::DPadRight, Key::L, Key::R });

		if(ButtonsCombo())
		{
			if(MessageBox("You found the secret menu :o", Color::Magenta << "Do you want to launch the developer mode?" << Color::White << "\nDev mode will let you access to new cheats\nthat are meant for developers \nor are still in developement!", DialogType::DialogYesNo).SetClear(ClearScreen::Top)())
			{
				IsFolderUsable(DevFolder, true);
				MessageBox(Color::Green << "\"Dev Folder\" is now active!")();
			}
		}
	}

	static MenuEntry *EntryWithHotkey(MenuEntry *entry, const Hotkey &hotkey)
	{
		if(entry != nullptr)
		{
			entry->Hotkeys += hotkey;
			entry->SetArg(new std::string(entry->Name()));
			entry->Name() += ": " + hotkey.ToString();
			entry->Hotkeys.OnHotkeyChangeCallback([](MenuEntry *entry, int index)
			{
				std::string *name = reinterpret_cast<std::string *>(entry->GetArg());

				entry->Name() = *name + ": " + entry->Hotkeys[0].ToString();
			});
		}
		return(entry);
	}

	static MenuEntry *EntryWithHotkey(MenuEntry *entry, const std::vector<Hotkey> &hotkeys)
	{
		if(entry != nullptr)
		{
			for(const Hotkey &hotkey : hotkeys)
				entry->Hotkeys += hotkey;
		}
		return(entry);
	}

	int	 main(void)
	{
		PluginMenu *m = new PluginMenu(PluginName, MAJOR_VERSION, MINOR_VERSION, REVISION_VERSION, Credits);
		PluginMenu &menu = *m;

		// Synchronize the menu with frame event
		menu.SynchronizeWithFrame(true);

		// StartUp Message
		// menu.OnFirstOpening = StartMsg;

		if(CheckGameVersion())
			return(1); // Unsupported version

		OptionsFolder = new MenuFolder(Color::Red << "Options");
		{
			OptionsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Red << " Quick Menu", nullptr),{Hotkey(Key::B | Key::DPadUp, MenuNote)})),
			OptionsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Orange << " Turbo mode", ToggleTurbo),{Hotkey(Key::L | Key::Start, OnOffNote)})),

			menu.Append(OptionsFolder);
		}

		MovementsFolder = new MenuFolder(Color::Orange << "Movements");
		{
			MovementsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Red << " Coordinates Modifier", CoordinateModifier, SetCoordSpeed),{Hotkey(Key::A | Key::DPadUp, Color::Yellow << "Up"), Hotkey(Key::A | Key::DPadDown, "Down"), Hotkey(Key::A | Key::DPadLeft, "Left"), Hotkey(Key::A | Key::DPadRight, "Right")})),
			MovementsFolder->Append(new MenuEntry(Color::Orange << " Coordinates Modifier: ", TouchCoordinates)),
			MovementsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Yellow << " Walk Over Things", WalkOverThings, ""),{Hotkey(Key::L | Key::DPadDown, OnOffNote)})),
			MovementsFolder->Append(EntryWithHotkey(new MenuEntry(Color::LimeGreen << " Moon Jump", MoonJump, OptionMoonJump, ""),{Hotkey(Key::L | Key::DPadUp, Color::Yellow << "Moon Jump Up"), Hotkey(Key::L | Key::DPadDown, "Moon Jump Down")})),
			MovementsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Turquoise << " Speed Hack", SpeedHack),{Hotkey(Key::B, Color::Yellow << "Sonic")})),
			MovementsFolder->Append(EntryWithHotkey(new MenuEntry(Color::DeepSkyBlue << " Movement Changer", MovementChanger, ""),{Hotkey(Key::L | Key::DPadLeft, SelectModeNote)})),
			MovementsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Purple << " Room Warping", RoomMod, ""),{Hotkey(Key::L | Key::X, Color::Yellow << "Set ID")})),

			menu.Append(MovementsFolder);
		}

		ItemsFolder = new MenuFolder(Color::Yellow << "Items");
		{
			ItemsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Red << " All Seeders", SetSeeders, OptionSetSeeders, SetSeedersNote),{Hotkey(Key::B | Key::DPadRight, Color::Yellow << "Set ID"), Hotkey(Key::B | Key::DPadDown, "Copy ID on the ground"), Hotkey(Key::Start | Key::B, "Set ID to replace"), Hotkey(Key::L, "Scroll Item Left"), Hotkey(Key::R, "Scroll Item Right")})),
			ItemsFolder->Append(new MenuEntry(Color::Orange << " Touch Drop: ", TouchDrop, OptionTouchDrop, TouchDropNote)), // add particles?
			ItemsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Yellow << " Auto Drop", AutoDrop),{Hotkey(Key::B | Key::DPadLeft, OnOffNote)})),
			ItemsFolder->Append(EntryWithHotkey(new MenuEntry(Color::LimeGreen << " Drop Modifier", DropModifier, OptionDropModifier, ""),{Hotkey(Key::X | Key::DPadUp, SelectModeNote)})),
			ItemsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Turquoise << " PickUp Mod", PickUpMod, TurboNote << Color::White),{Hotkey(Key::L | Key::B, SelectModeNote), Hotkey(Key::R | Key::B, OnOffNote + " PickUp Mod"), Hotkey(Key::Y | Key::Start, OnOffNote + " Auto PickUp")})),
			ItemsFolder->Append(EntryWithHotkey(new MenuEntry(Color::DeepSkyBlue << " Map Editor" + Crash, MapEditor),{Hotkey(Key::Start | Key::DPadUp, OnOffNote)})),
			ItemsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Magenta << " Trampler", Trampler),{Hotkey(Key::L | Key::DPadRight, OnOffNote)})),
			ItemsFolder->Append(new MenuEntry(Color::Purple << " Sets drop" + Soon, nullptr)), // soon
			ItemsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Red << " Catalog to pockets", CatalogToPockets),{Hotkey(Key::L | Key::R, Color::Yellow << "Open catalog")})),
			ItemsFolder->Append(new MenuEntry(Color::Orange << " Drop & Dig Anywhere" + Test, DropAndDigAnywhere)), // soon (need tests)

			menu.Append(ItemsFolder);
		}

		AnimationsFolder = new MenuFolder(Color::Orange << "Animations");
        {
			AnimationsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Red << " Idle", Idle),{Hotkey(Key::L, Color::Yellow << "Restore movements")})),
			AnimationsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Orange << " Animations Mod", AnimMod, AnimModNote),{Hotkey(Key::Y | Key::DPadRight, Color::Yellow << "Set ID"), Hotkey(Key::Y | Key::DPadUp, SelectModeNote), Hotkey(Key::Y | Key::DPadLeft, "ON/OFF"), Hotkey(Key::A, "Execute animation")})),
			AnimationsFolder->Append(EntryWithHotkey(new MenuEntry(Color::Yellow << " Force Animations To Everyone", ForceAnimationsToOthers, ForceAnimationsToOthersNote),{Hotkey(Key::X | Key::DPadRight, Color::Yellow << "Animations"), Hotkey(Key::X | Key::DPadDown, "Restore movements"), Hotkey(Key::X | Key::DPadLeft, "Moonjump")})),
			AnimationsFolder->Append(new MenuEntry(Color::LimeGreen << " Infinite Expressions", InfiniteExpression)),
			AnimationsFolder->Append(new MenuEntry(Color::Turquoise << " Slow-Motion Animations" + Test, SlowMotionAnim)), // fix?
			AnimationsFolder->Append(new MenuEntry(Color::DeepSkyBlue << " Anti Animation", AntiAnimation)),
			AnimationsFolder->Append(new MenuFolder(Color::Magenta << "NPCs Animations", "",
        	{
            	EntryWithHotkey(new MenuEntry(Color::Red << " NPCs Menu", NPCMenu),{Hotkey(Key::Y | Key::DPadDown, MenuNote)}),
				EntryWithHotkey(new MenuEntry(Color::Orange << " NPCs Animations Executer", NPCAnimationExecuter),{Hotkey(Key::Y | Key::B, Color::Yellow << "Execute animation")}),
				EntryWithHotkey(new MenuEntry(Color::Yellow << " NPCs Coordinates Modifier", NPCCoordinates, SetNPCCoordSpeed),{Hotkey(Key::Start | Key::DPadUp, Color::Yellow << "Up"), Hotkey(Key::Start | Key::DPadDown, "Down"), Hotkey(Key::Start | Key::DPadLeft, "Left"), Hotkey(Key::Start | Key::DPadRight, "Right")})
			}));

			menu.Append(AnimationsFolder);
		}

		EnvironnementFolder = new MenuFolder(Color::Red << "Environnement");
		{
			EnvironnementFolder->Append(new MenuEntry(Color::Red << " Building Mod", nullptr, BuildingMod, ReloadNote)),
			EnvironnementFolder->Append(new MenuEntry(Color::Orange << " Town Acres Editor", AcresEditor)), // add for island?
			EnvironnementFolder->Append(new MenuEntry(Color::Yellow << " Weather Mod", nullptr, WeatherMod)),
			EnvironnementFolder->Append(new MenuEntry(Color::LimeGreen << " Season Mod", nullptr, SeasonMod)),
			EnvironnementFolder->Append(new MenuEntry(Color::Turquoise << " Festival Mod" + Crash, nullptr, FestivalMod)),
			EnvironnementFolder->Append(new MenuEntry(Color::Magenta << " Mainstreet Shops Open", MainStreetShopOpen)),
			EnvironnementFolder->Append(new MenuEntry(Color::Purple << " Nookling Upgrades", nullptr, NookAmeliorations)),
			//add unlockqrmachine, CompleteMuseum, Permit100%, PWPUnlock (change de place?)

			menu.Append(EnvironnementFolder);
		}

		IslandFolder = new MenuFolder(Color::Orange << "Island");
		{
			IslandFolder->Append(EntryWithHotkey(new MenuEntry(Color::Red << " Island Items Saves", IslandItemsSaves),{Hotkey(Key::R | Key::X, MenuNote)})),
			IslandFolder->Append(new MenuFolder(Color::Orange << "Island Acres Modifier" + Online, "",
        	{
				new MenuEntry(Color::Red << "Island Acres Preset Creator", OnlineIslandAcresCreator, ModelsCreator, OnlineIslandModelNote),
				new MenuEntry(Color::Orange << "Island Acres Preset:Funny Island", OnlineIslandAcresModel1, OnlineIslandModelNote),
				new MenuEntry(Color::Yellow << "Island Acres Preset:Town", OnlineIslandAcresModel2, OnlineIslandModelNote),
			}));
			IslandFolder->Append(new MenuEntry(Color::Yellow << " Island Building Mod" + Online, OnlineIslandBuildingMod, MenuOnlineIslandBuildingMod)),
			IslandFolder->Append(new MenuEntry(Color::LimeGreen << " Change Island Shop" + Online, OnlineChangeItemsShopOnIsland, MenuOnlineChangeItemsShopOnIsland)),
			IslandFolder->Append(new MenuEntry(Color::Turquoise << " Change Lloid Tools", nullptr, LloidIslandToolEditor)),
			IslandFolder->Append(new MenuEntry(Color::DeepSkyBlue << " Island Region Spoofer", nullptr, IslandRegionSpoofer)),
			IslandFolder->Append(new MenuEntry(Color::Magenta << " Enable All Tours", EnableAllTours)),
			IslandFolder->Append(new MenuEntry(Color::Purple << " Get Bonus Ore & Needed Fruits", nullptr, OreAndFruitsTours)),
			IslandFolder->Append(new MenuEntry(Color::Red << " End Actual Tour", nullptr, TourEnd)),

			menu.Append(IslandFolder);
		}

		KeyboardChatFolder = new MenuFolder(Color::Yellow << "Keyboard & Chat");
		{
			KeyboardChatFolder->Append(new MenuEntry(Color::Red << " Commands Chat" + Soon, nullptr)), // soon
			KeyboardChatFolder->Append(new MenuEntry(Color::Orange << " Player Comming Info" + Test, PlayerComming)),
			KeyboardChatFolder->Append(new MenuEntry(Color::Yellow << " Talk through anyone" + Soon, nullptr)), // soon
			KeyboardChatFolder->Append(new MenuEntry(Color::LimeGreen << " Unlock \"@\" and \"Enter\"", UnlockCaracters)),
			KeyboardChatFolder->Append(new MenuEntry(Color::Turquoise << " Keyboard Extender", KeyboardExtender)),
			KeyboardChatFolder->Append(new MenuEntry(Color::DeepSkyBlue << " Custom Keyboard", CustomKeyboard, SetSymbolCustomKeyboard)),
			KeyboardChatFolder->Append(EntryWithHotkey(new MenuEntry(Color::Magenta << " Spamming Sended Chat", ChatSpam, ChatSpamNote),{Hotkey(Key::R, Color::Yellow << "Spam")})), //NEED FIX

			menu.Append(KeyboardChatFolder);
		}

		VisualSoundsFolder = new MenuFolder(Color::Orange << "Visual & Sounds");
		{
			VisualSoundsFolder->Append(new MenuEntry(Color::Red << " Effects Mod" + Soon, nullptr)),
			VisualSoundsFolder->Append(new MenuEntry(Color::Orange << " Camera Mod" + Soon, nullptr)),
			VisualSoundsFolder->Append(new MenuEntry(Color::Yellow << " Disable L + R Screenshots", DisableScreenshots)),
			VisualSoundsFolder->Append(new MenuEntry(Color::LimeGreen << " FOV Modifier", ChangeFOV, SetFOV)),
			VisualSoundsFolder->Append(new MenuEntry(Color::Turquoise << " Game Speed", GameSpeed)),
			VisualSoundsFolder->Append(new MenuEntry(Color::DeepSkyBlue << " Fast Talk NPC", FastTalkNPC)),
			VisualSoundsFolder->Append(new MenuEntry(Color::Magenta << " Always Cherry Blossom Trees", AlwaysCherryBlossomTrees, ReloadNote)),
			VisualSoundsFolder->Append(new MenuEntry(Color::Purple << " Town BGM Modifier", nullptr, TownBGMModifier)),
			VisualSoundsFolder->Append(new MenuEntry(Color::Red << " Island Hut BGM Modifier", nullptr, IslandHutBGMModifier, ReloadNote)),

			menu.Append(VisualSoundsFolder);
		}

		PlayerFolder = new MenuFolder(Color::Red << "Player");
		{
			PlayerFolder->Append(new MenuEntry(Color::Red << " Clear/Fill Inventory", nullptr, ClearOrFillInvetory)),
			PlayerFolder->Append(new MenuEntry(Color::Orange << " Money Mod", nullptr, MoneyMod)),
			PlayerFolder->Append(new MenuEntry(Color::Yellow << " Player Options Mod", nullptr, PlayerOptionsMod, ReloadNote)), //notif?
			PlayerFolder->Append(EntryWithHotkey(new MenuEntry(Color::LimeGreen << " Player Controller / Teleporter", PlayerControllerTeleporter),{Hotkey(Key::R | Key::DPadUp, Color::Yellow << "Player Selector"), Hotkey(Key::R | Key::DPadDown, "Control Selected Player"), Hotkey(Key::R | Key::DPadLeft, "TP You -> Selected Player"), Hotkey(Key::R | Key::DPadRight, "TP Everyone -> You")})),
			PlayerFolder->Append(new MenuEntry(Color::Turquoise << " Player Infos OSD", PlayersInfos)),
			PlayerFolder->Append(new MenuEntry(Color::DeepSkyBlue << " Show All Players On Map", ShowAllPlayersOnMap)),
			PlayerFolder->Append(EntryWithHotkey(new MenuEntry(Color::Magenta << " Magic Wand ACNH", MagicWandACNH),{Hotkey(Key::L | Key::Y, MenuNote)})),

			menu.Append(PlayerFolder);
		}

		SaveFolder = new MenuFolder(Color::Orange << "Save");
		{
			SaveFolder->Append(new MenuEntry(Color::Red << " Player Name Changer", nullptr, PlayerNameChanger)),
			SaveFolder->Append(new MenuEntry(Color::Orange << " Town Name Changer", nullptr, TownNameChanger)),
			SaveFolder->Append(new MenuEntry(Color::Yellow << " TPC Picture Export", nullptr, TPCPictureExport)),
			SaveFolder->Append(new MenuEntry(Color::LimeGreen << " TPC Picture Import", nullptr, TPCPictureImport)),
			SaveFolder->Append(new MenuEntry(Color::Turquoise << " Dump Save", nullptr, DumpSave)),
			SaveFolder->Append(new MenuEntry(Color::DeepSkyBlue << " Restore Save", nullptr, RestoreSave, ReloadNote)),
			SaveFolder->Append(new MenuEntry(Color::Magenta << " Player Badges", nullptr, Badges)),
			SaveFolder->Append(new MenuEntry(Color::Purple << " Fill Player Collectables", nullptr, FillCollectablesList)),
			SaveFolder->Append(new MenuEntry(Color::Red << " Dream Code Modifier", nullptr, DreamCodeModifier)),

			menu.Append(SaveFolder);
		}

		MiscellaneousFolder = new MenuFolder(Color::Yellow << "Miscellaneous");
		{
			MiscellaneousFolder->Append(new MenuEntry(Color::Red << " Disable Save Menu", DisableSaveMenu)),
			MiscellaneousFolder->Append(new MenuEntry(Color::Orange << " Fast Menus", FastMenus)),
			MiscellaneousFolder->Append(new MenuEntry(Color::Yellow << " Census Menu", CensusMenu)),
			MiscellaneousFolder->Append(new MenuEntry(Color::LimeGreen << " Time Machine", nullptr, TimeMachine)),
			MiscellaneousFolder->Append(new MenuEntry(Color::Turquoise << " Tools effect", ToolsEffects, ToolsChoice)),
			MiscellaneousFolder->Append(new MenuEntry(Color::DeepSkyBlue << " Tree Shake Chop", TreeShakeChop)),
			MiscellaneousFolder->Append(EntryWithHotkey(new MenuEntry(Color::Magenta << " Particles Spawner", ParticlesSpawner, ParticlesSize, Color::Red << "ONLY VISIBLE TO YOU" + TurboNote << Color::White),{Hotkey(Key::R | Key::Y, Color::Yellow << "Set ID"), Hotkey(Key::R | Key::A, "Spawn Particle(s)")})),
			MiscellaneousFolder->Append(new MenuEntry(Color::Purple << " Edit All Furnitures Online", EditEveryRoomOnline)),
			MiscellaneousFolder->Append(new MenuEntry(Color::Red << " Skip Isabelle", SkipIsabelle)),

			menu.Append(MiscellaneousFolder);
		}

		DevFolder = new MenuFolder(Color::Lime << "Dev Menu");
		{
			DevFolder->Append(EntryWithHotkey(new MenuEntry(Color::Lime << " Address Test", AddressTest),{Hotkey(Key::Start | Key::DPadLeft, Color::Yellow << "Set Address"), Hotkey(Key::Start | Key::DPadDown, "Read Address"), Hotkey(Key::Start | Key::DPadRight, "Display"), Hotkey(Key::Start | Key::X, "Write Address")})),
			DevFolder->Append(EntryWithHotkey(new MenuEntry(Color::Lime << " Game Function Call", GameFuncCall),{Hotkey(Key::Start | Key::R, MenuNote)})),
			DevFolder->Append(new MenuEntry(Color::Lime << " Get Players 3DS Friend Code", nullptr, GetFriendCodeMenu)),
			DevFolder->Append(new MenuEntry(Color::Lime << " .png Display Keyboard Menu", nullptr, DisplayRegion)),

			menu.Append(DevFolder);
			IsFolderUsable(DevFolder, false);
		}

		// Initialize some cheats
        Game::StartUpCheats();

		// Initialize player
        Player::GetInstance();

		// Wait until a player is loaded
		menu += PlayerUpdateCallback;

		menu.Callback(DevMenuCallback);

		// Welcome message
		menu.ShowWelcomeMessage(false);

		OSD::Notify(Color::Red << "P" << 
					Color::Orange << "l" << 
					Color::Yellow << "u" <<
					Color::Lime << "g" <<
					Color::Green << "i" << 
					Color::Cyan << "n " << 
					Color::Blue << "R" <<
					Color::Purple << "e" << 
					Color::Red << "a" << 
					Color::Orange << "d" << 
					Color::Yellow << "y" << 
					Color::Lime << "!");

		// Launch menu and mainloop
		menu.Run();

		// Exit plugin
		return(0);
	}
}