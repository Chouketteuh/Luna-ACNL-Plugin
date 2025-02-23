#ifndef CHEATS_H
#define CHEATS_H

#include "Game.hpp"
#include "unicode.h"
#include <ostream>
#include <cmath>
#include <algorithm>
#include <unordered_set>

enum Region
{
    USA = 0,
    EUR
};

namespace CTRPluginFramework
{
    /*Options*/
    void	ToggleTurbo(MenuEntry *entry);

    /*Movements Codes*/
    void    CoordinateModifier(MenuEntry *entry);
    void    SetCoordSpeed(MenuEntry *entry);
    void    TouchCoordinates(MenuEntry *entry);
    void    WalkOverThings(MenuEntry *entry);
    void	MoonJump(MenuEntry *entry);
    void    OptionMoonJump(MenuEntry *entry);
    void	SpeedHack(MenuEntry *entry);
    void	MovementChanger(MenuEntry *entry);
    void	RoomMod(MenuEntry *entry);

    /*Items Codes*/
    void	SetSeeders(MenuEntry *entry);
	void	OptionSetSeeders(MenuEntry *entry);
    void    TouchDrop(MenuEntry *entry);
    void	OptionTouchDrop(MenuEntry *entry);
    void    AutoDrop(MenuEntry *entry);
    void    DropModifier(MenuEntry *entry);
    void    OptionDropModifier(MenuEntry *entry);
    void    PickUpMod(MenuEntry *entry);
    void    MapEditor(MenuEntry *entry);
    void	Trampler(MenuEntry *entry);
    void	CatalogToPockets(MenuEntry *entry);
    void	DropAndDigAnywhere(MenuEntry *entry);

    /*Animations Codes*/
    void	Idle(MenuEntry *entry);
    void	AnimMod(MenuEntry *entry);
    void	ForceAnimationsToOthers(MenuEntry *entry);
    void    InfiniteExpression(MenuEntry *entry);
    void	SlowMotionAnim(MenuEntry *entry);
    void	AntiAnimation(MenuEntry *entry);
    void    NPCMenu(MenuEntry *entry);
    void    NPCAnimationExecuter(MenuEntry *entry);
    void	NPCCoordinates(MenuEntry *entry);
    void	SetNPCCoordSpeed(MenuEntry *entry);

    /*Environnement Codes*/
    void	BuildingMod(MenuEntry *entry);
    void	AcresEditor(MenuEntry *entry);
    void    WeatherMod(MenuEntry *entry);
    void	SeasonMod(MenuEntry *entry);
    void	FestivalMod(MenuEntry *entry);
    void    MainStreetShopOpen(MenuEntry *entry);
    void    MainStreetShopUnlock(MenuEntry *entry);
    void    NookAmeliorations(MenuEntry *entry);

    /*Island Codes*/
    void	IslandItemsSaves(MenuEntry *entry);
    void	OnlineIslandAcresCreator(MenuEntry *entry);
    void	ModelsCreator(MenuEntry* entry);
    void	OnlineIslandAcresModel1(MenuEntry *entry);
    void	OnlineIslandAcresModel2(MenuEntry *entry);
    void    OnlineIslandBuildingMod(MenuEntry *entry);
    void    MenuOnlineIslandBuildingMod(MenuEntry *entry);
    void    OnlineChangeItemsShopOnIsland(MenuEntry *entry);
    void	MenuOnlineChangeItemsShopOnIsland(MenuEntry *entry);
    void    LloidIslandToolEditor(MenuEntry *entry);
    void 	IslandRegionSpoofer(MenuEntry *entry);
    void    EnableAllTours(MenuEntry *entry);
    void	OreAndFruitsTours(MenuEntry *entry);
    void	TourEnd(MenuEntry *entry);

    /*Keyboard & Chat Codes*/
    // Command Chat
    void	PlayerComming(MenuEntry *entry);
    // Talk through anyone
    void    UnlockCaracters(MenuEntry *entry);
    void    KeyboardExtender(MenuEntry *entry);
    void    CustomKeyboard(MenuEntry *entry);
    void    SetSymbolCustomKeyboard(MenuEntry *entry);
    void    ChatSpam(MenuEntry *entry);

    /*Visual & Sound Codes*/
    void    GameSpeed(MenuEntry *entry);
    void	FastTalkNPC(MenuEntry *entry);
    void	ChangeFOV(MenuEntry *entry);
    void	SetFOV(MenuEntry *entry);
    void	TownBGMModifier(MenuEntry *entry);
    void	IslandHutBGMModifier(MenuEntry *entry);
    void	AlwaysCherryBlossomTrees(MenuEntry *entry);
    void	DisableScreenshots(MenuEntry *entry);
    // Camera Mod

    /*Player Codes*/
    void    ClearOrFillInvetory(MenuEntry *entry);
    void	MoneyMod(MenuEntry *entry);
    void    PlayerOptionsMod(MenuEntry *entry);
    void    PlayerControllerTeleporter(MenuEntry *entry);
    void    PlayersInfos(MenuEntry *entry);
    void    ShowAllPlayersOnMap(MenuEntry *entry);
    void	MagicWandACNH(MenuEntry *entry);

    /*Save Codes*/
    void	PlayerNameChanger(MenuEntry* entry);
    void	TownNameChanger(MenuEntry *entry);
    void	TPCPictureExport(MenuEntry *entry);
    void	TPCPictureImport(MenuEntry *entry);
    void	DumpSave(MenuEntry* entry);
    void	RestoreSave(MenuEntry* entry);
    void    Badges(MenuEntry *entry);
    void	FillCollectablesList(MenuEntry *entry);
    void 	DreamCodeModifier(MenuEntry *entry);

    /*Misc Codes*/
    void	DisableSaveMenu(MenuEntry *entry);
    void	FastMenus(MenuEntry *entry);
    void	CensusMenu(MenuEntry *entry);
    void	TimeMachine(MenuEntry *entry);
    void	ToolsEffects(MenuEntry *entry);
    void	ToolsChoice(MenuEntry *entry);
    void	TreeShakeChop(MenuEntry *entry);
    void	ParticlesSpawner(MenuEntry *entry);
    void	ParticlesSize(MenuEntry *entry);
    void	EditEveryRoomOnline(MenuEntry *entry);
    void	SkipIsabelle(MenuEntry *entry);

    /*Dev Menu*/
    void	AddressTest(MenuEntry *entry);
    void	GameFuncCall(MenuEntry *entry);
    void	GetFriendCodeMenu(MenuEntry *entry);
    void	DisplayRegion(MenuEntry *entry);

    /*Helpers*/
    void	PlayerUpdateCallback(void);
    void	ToggleTouchscreenForceOn(void);
    bool	IsFolderUsable(MenuFolder *folder, bool OnOff);
}
#endif