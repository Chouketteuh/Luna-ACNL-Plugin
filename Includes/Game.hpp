#ifndef GAME_HPP
#define GAME_HPP

#include "CTRPluginFramework.hpp"
#include "RegionAddress.hpp"
#include "Addresses.hpp"
#include "Structs.hpp"
#include "Wrappers.hpp"
#include "Strings.hpp"

namespace CTRPluginFramework
{
    extern const ID_Data Buildings[205];
    extern const ID_Data Rooms[109];
    extern const ID_Data OutdoorMusics[256];

	class Player
    {
    public:
        void                    Load(void);

        static Player*          GetInstance(void);
        static u8               GetActualPlayerIndex(void);
        static u8               GetOnlinePlayerIndex(void);
        static u32              GetOffset(u8 PlayerIndex = GetActualPlayerIndex());
        static bool             Exists(u8 PlayerIndex = GetActualPlayerIndex());
        static bool             IsLoaded(u8 PlayerIndex = GetActualPlayerIndex());
        static u32              GetAnimationInstance(u32 PlayerInstance, u8 someVal1, u8 someVal2, u32 encVal);
        static u32              GetSpecificSave(u8 PlayerIndex = GetActualPlayerIndex());
        static u32              GetPlayerSave(u8 PlayerIndex = GetActualPlayerIndex());

        static bool             InLoadingState(void);

        static float* 			GetVelocity(u8 PlayerIndex = GetActualPlayerIndex());
        static u8*              GetAnimation(u8 PlayerIndex = GetActualPlayerIndex());
        static u16*             GetSnake(u8 PlayerIndex = GetActualPlayerIndex());

        static u8               ActualRoom(u8 PlayerIndex = GetActualPlayerIndex());
        static bool             IsIndoor();
        static bool             IsInRoom(u8 Room, u8 PlayerIndex = GetActualPlayerIndex(), bool NotLoaded = false);
        static bool             IsOnTour(u8 PlayerIndex = GetActualPlayerIndex());
        static u8               NextRoomCheck();
        static bool             CanWarp(u8 Room);

        static bool             GetWorldCoords(u32 *wX, u32 *wY, u8 PlayerIndex = GetActualPlayerIndex());
        static Coordinates      GetStructCoordinates(u8 PlayerIndex = GetActualPlayerIndex());
        static void             SetStructCoordinates(Coordinates pos, u8 PlayerIndex = GetActualPlayerIndex());
        static float*           GetCoordinates(u8 PlayerIndex = GetActualPlayerIndex());
        static bool             GetCoordinatesRef(float &X, float &Z, u8 PlayerIndex = GetActualPlayerIndex());
        static void             SetCoordinatesX(float x, u8 PlayerIndex = GetActualPlayerIndex());
        static void             SetCoordinatesY(float y, u8 PlayerIndex = GetActualPlayerIndex());
        static void             SetCoordinatesZ(float z, u8 PlayerIndex = GetActualPlayerIndex());
        static void             AddToCoordinates(float xDiff, float yDiff, float zDiff, u8 PlayerIndex = GetActualPlayerIndex());

        static u8               GetCurrentInventory();
        static u32              ReadInventory(u8 Slot);
        static void             WriteInventory(u8 Slot, u32 ID);

        static void             SetOutfit(u16 Out1, u16 Out2, u16 Out3, u16 Out4, u16 Out5, u16 Out6);
        static u64              GetFriendCode(u8 PlayerIndex);

    private:
        Player(void);
        ~Player(void);

        static Player* m_Instance;
    };

    class Game
	{
    public:
        static void             StartUpCheats(void);
        
        static bool             IsSaving();
        static bool             MapBool();
        static void             RoomWarp(u8 Room);
        static void			    ReloadRoom(float *coords = Player::GetCoordinates());
        static void             AskReloadRoom(void);
        static u32 			    GetRoomData();
        static float*           WorldCoordsToCoords(u8 wX, u8 wY, float res[3], u8 PlayerIndex = Player::GetActualPlayerIndex());
        static u8               GetOnlinePlayerCount();
        static u32              GetCurrentMap();
        static vec32            GetMapItems(bool Include7FFE = false, u8 WorldX = 0, u8 WorldY = 0, u8 Width = 0xFF, u8 Length = 0xFF);
		static u32              GetMapItemsCount(bool Include7FFE = false, u8 WorldX = 0, u8 WorldY = 0, u8 Width = 0xFF, u8 Length = 0xFF);

        static void             AppendCoordData(u32 AnimInst, u32 pos, float *Coord);

        static void             Particles(u32 ParticleID, float *wCoords, u32 u0 = 0x976C0E, u32 u1 = 0xAE6870);

        static void			    OpenMenu(u8 MenuID, bool NoMenuCall = false);
        static void             OpenCatalog();
        static void             GiveItemFunction(u32 InvData);

        static TownSaveData*    GetTownSaveData(void);
        static void             PlaceBuildingUpdateCollisions(u32 x, u32 y, u16 BuildingID);
        static void             PlaceBuilding();
        static void             MoveBuilding();
        static void             RemoveBuilding();

        static u64              EncryptACNLMoney(int dec);
	};

    class Items
	{
    public:
        static u32              PlaceItem(u8 ID, u32 *ItemToReplace, u32 *ItemToPlace, u32 *ItemToShow, u8 worldX, u8 worldY, bool IsInside, bool u1, bool u2, bool u3, bool u4);
        static bool             DropCheck(u32 *wX, u32 *wY, u32 *u0, bool disallowConcrete, bool u1);
        static bool			    PlaceItemWrapper(u8 ID, u32 ItemToReplace, u32 *ItemToPlace, u32 *ItemToShow, u8 worldX, u8 worldY, bool u0, bool u1, bool u2, bool u3, bool u4, u8 WaitAnim, u8 RoomID, bool itemsequenceallowed = true);
        static void             TrampleAt(u8 wX, u8 wY);
        static u32*             GetItemAtWorldCoords(u32 x, u32 y, bool u0 = 0);
        static u32              GetLockedSpotIndex(u8 wX, u8 wZ, u8 RoomID = 0xA5);
        static void			    ClearLockedSpot(u8 wX, u8 wY, u8 RoomID, u32 param_4 = 4);
    };
    
    class Animation
	{
    public:
        static bool             ExecuteAnimation(u32 PlayerInst, u8 AnimID, u32 AnimInst);
        static bool             ExecuteAnimationWrapper(u8 PlayerIndex, u8 AnimID, u32 AnimItem, u8 EmotionID, u16 SnakeID, u16 SoundID, bool u0, u8 wX, u8 wY, bool directSend = false, u8 Appearance[] = nullptr);
        static void             SendPacket(u8 senderIndex, u32 AnimObj, u8 AnimID, u8 RoomID, u8 TargetPlayerIndex);
        static void             DoMoonJump(u32 AnimInstance, u32 PlayerInstance);
	};

    class Chat
	{
    public:
        static u32              GetChatOffset(void);
        static bool             IsOpen(void);
        static bool             IsEmpty(void);
        static u8               GetCursorPosition(bool OnTheLeft = true);
        static bool             IsHighlighted(void);
        static u8               GetCharactersCount(void);
        static vec16            GetHighlightedCharacters(void);
        static void             SendMessage(void);
        static void             WriteCharacter(u16 Character, u8 Position = 25);
        static void             MoveCursor(u8 Position1 = 0, u8 Position2 = 0, bool IsNotHighlighted = true);
        static void             PopCharacterBack(bool NoSound = false);
	};

    class IDList
	{
    public:
        static bool             ValidIDFloat(float ID, float StardID, float EndID);
        static bool             ValidID32(u32 ID, u32 StardID, u32 EndID);
        static bool             ValidID16(u16 ID, u16 StardID, u16 EndID);
        static bool             ValidID8(u8 ID, u8 StardID, u8 EndID);
        
        static bool             ItemValid(u32 ItemID);
        static bool             RoomValid(u8 RoomID);
        static bool             AnimValid(u8 AnimID);
        static bool             ToolValid(u16 ToolID);
        static bool             SnakeValid(u16 SnakeID);
        static bool             EmotionValid(u8 EmotionID);
        static bool             SoundValid(u16 SoundID);
        static bool             CustomAnimValid(u8 CustomAnim);
        static bool             BuildingValid(u8 BuildingID);
        static bool             MusicValid(u8 MusicID);

        static std::string      GetRoomName(u8 ID);
        static std::string      GetBuildingName(u8 ID);
        static std::string      GetOutdoorMusicName(u8 ID);
	};

    class Camera
	{
	public:
		static u32		        GetInstance();
        static float* 		    GetCoordinates();
		static void		        AddToX(float val);
		static void		        AddToY(float val);
		static void		        AddToZ(float val);
		static void		        AddToYRotation(u16 val);
	};
}
#endif