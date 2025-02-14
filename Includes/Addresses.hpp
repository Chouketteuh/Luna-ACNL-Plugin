#ifndef ADDRESSES_HPP
#define ADDRESSES_HPP

// Above 0x31000000
// USA_TO_EUR - 0x28380
// USA_TO_JAP + 0x22A80

namespace CTRPluginFramework
{
	/*Functions*/
	static const u32 USA_PlayerInstance_Function = 0x5C3EA0;
	static const u32 EUR_PlayerInstance_Function = 0x5C2EE8;
	static const u32 USA_WorldCoordinates_Function = 0x5C13AC;
	static const u32 EUR_WorldCoordinates_Function = 0x5C03F4;
	static const u32 USA_AnimationInstance_Function = 0x6576F8;
	static const u32 EUR_AnimationInstance_Function = 0x656730;
	static const u32 USA_Animation_Function = 0x64DB90;
	static const u32 EUR_Animation_Function = 0x64CBC8;
	static const u32 USA_Pickup_Function = 0x661524;
	static const u32 USA_Room_Function = 0x5C3DDC;
	static const u32 EUR_Room_Function = 0x5C2E24;
	static const u32 USA_Drop_Function = 0x59FC7C;
	static const u32 EUR_Drop_Function = 0x59ECC4;
	static const u32 USA_OnlinePlayerIndex_Function = 0x305EF0;
	static const u32 EUR_OnlinePlayerIndex_Function = 0x305EF0;
	static const u32 USA_OnlinePlayerCount_Function = 0x75EFF8;
	static const u32 EUR_OnlinePlayerCount_Function = 0x75E000;
	static const u32 USA_Loading_Function = 0x304A60;
	static const u32 EUR_Loading_Function = 0x304AEC;
	static const u32 USA_Warp0_Function = 0x61E708;
	static const u32 USA_ArriveAtIsland_Function = 0x61E8BC;
	static const u32 USA_ArriveAtTourdesk_Function = 0x61F81C;
	static const u32 USA_ArriveAtTown_Function = 0x61F258;
	static const u32 USA_LeaveIsland_Function = 0x61E954;
	static const u32 USA_ItemAtWorldCoordinates_Function = 0x2FEF9C;
	static const u32 USA_CurrentMap_Function = 0x6A690C;
	static const u32 USA_PlaceBuildingUpdateCollisions_Function = 0x2425D8;
	static const u32 USA_APressAction_Function = 0x597154;
	static const u32 USA_DropIDSwitch_Function = 0x5A22F4;
	static const u32 USA_PlaySound_Function = 0x2505E0;
	static const u32 USA_DropCheck_Function = 0x5990AC;
	static const u32 EUR_DropCheck_Function = 0x5980F4;
	static const u32 USA_PseudoType0x21_Function = 0x59FFC0;
	static const u32 USA_PlayerObjectPointer_Function = 0x5C119C;
	static const u32 USA_Particles_Function = 0x207B90;
	static const u32 EUR_Particles_Function = 0x207BB0;
	static const u32 USA_ClearLockedSpot_Function = 0x5A1278;
	static const u32 EUR_ClearLockedSpot_Function = 0x5A02C0;
	static const u32 USA_CreateLockedSpot_Function = 0x5A13C4;
	static const u32 USA_LockedSpotIndex_Function = 0x5A11BC;
	static const u32 USA_BuildingName_Function = 0x5CA20C;
	static const u32 USA_RoomName_Function = 0x5B4BE4;
	static const u32 EUR_RoomName_Function = 0x5B3C2C;
	static const u32 USA_ItemBehaviour_Function = 0x2FCCD0;
	static const u32 USA_HasTreeBehaviour_Function = 0x2FE930;
	static const u32 USA_LoadItemIconWrapper_Function = 0x26DC00;
	static const u32 USA_SendChatMessage_Function = 0x52440C;
	static const u32 EUR_SendChatMessage_Function = 0x523454;
	static const u32 USA_WriteToChat_Function = 0x5231D0;
	static const u32 EUR_WriteToChat_Function = 0x522218;
	static const u32 USA_ChatCursor_Function = 0x5236CC;
	static const u32 EUR_ChatCursor_Function = 0x522714; // wrong?
	static const u32 USA_PopChatCharacterBack_Function = 0x523DB8;
	static const u32 EUR_PopChatCharacterBack_Function = 0x522E00; // wrong?

	/*Pointers*/
	static const u32 USA_PlayerInfo_Pointer = 0xAAE994;
	static const u32 EUR_PlayerInfo_Pointer = 0xAAE994;
	static const u32 USA_Player_Pointer = 0xAB014C;
	static const u32 EUR_Player_Pointer = 0xAAF14C;
	static const u32 USA_PlayerSave_Pointer = 0x2FEB2C;
	static const u32 EUR_PlayerSave_Pointer = 0x2FEBB4;
	static const u32 USA_Game_Pointer = 0x954648;
	static const u32 EUR_Game_Pointer = 0x953648;
	static const u32 USA_GardenPlus_Pointer = 0x2FB344;
	static const u32 EUR_GardenPlus_Pointer = 0x2FB340;
	static const u32 USA_Location_Pointer = 0x1E890C;
	static const u32 EUR_Location_Pointer = 0x1E892C;
	static const u32 USA_Inventory_Pointer = 0x9509EC;
	static const u32 USA_BaseInventory_Pointer = 0x98D500;
	static const u32 EUR_BaseInventory_Pointer = 0x98C500;
	static const u32 USA_Keyboard_Pointer = 0x95F104;
	static const u32 EUR_Keyboard_Pointer = 0x95E0FC; // wrong?
	static const u32 USA_Chat_Pointer = 0x95F11C;
	static const u32 EUR_Chat_Pointer = 0x95E114;
	static const u32 USA_Island_Pointer = 0x953708;
	static const u32 EUR_Island_Pointer = 0x952704;
	static const u32 USA_IslandShop_Pointer = 0x953708;
	static const u32 EUR_IslandShop_Pointer = 0x953238;
	static const u32 USA_CameraInstance_Pointer = 0x951884;
	static const u32 EUR_CameraInstance_Pointer = 0x950880;

	/*RAM*/
	static const u32 USA_PlayerControler_Address = 0x75F010;
	static const u32 EUR_PlayerControler_Address = 0x75E018;
	static const u32 USA_PlayerSave_Address = 0x31F27020; // from playerpointer
	static const u32 EUR_PlayerSave_Address = 0x31EFECA0; // from playerpointer
	static const u32 USA_Inventory_Address = 0x31F2DBF0;
	static const u32 EUR_Inventory_Address = 0x31F05870;
	static const u32 USA_OnlineInventory0_Address = 0xAAB0E0;
	static const u32 USA_OnlineInventory1_Address = 0xA8C360;
	static const u32 USA_OnlineInventory2_Address = 0xA967E0;
	static const u32 USA_OnlineInventory3_Address = 0xAA0C60;
	static const u32 USA_Outfit_Address = 0x31F2702A; //0x3307770, 0x33077CDC
	static const u32 USA_ActualRoom_Address = 0x94F4C5;
	static const u32 USA_RoomID_Address = 0x958342;
	static const u32 USA_Island_Address = 0x301DC290;
	static const u32 EUR_Island_Address = 0x301B4F30; // wrong?
	static const u32 USA_IslandsShop_Address = 0x33038D80;
	static const u32 EUR_IslandsShop_Address = 0x33010A00;
	static const u32 USA_Tours_Address = 0x76FCC0; //0x95D734
	static const u32 EUR_Tours_Address = 0x76ECC8;
	static const u32 USA_ToursGetNeeded_Address = 0x33038DD4;
	static const u32 EUR_ToursGetNeeded_Address = 0x33010A54;
	static const u32 USA_MapBool_Address = 0x950C30;
	static const u32 EUR_MapBool_Address = 0x94FC30;
	static const u32 USA_BottomScreenMenu_Address = 0x950D1F;
	static const u32 USA_OnlineMode_Address = 0x31FF59C9;
	static const u32 USA_SaveMenu_Address = 0x1A0980;
	static const u32 EUR_SaveMenu_Address = 0x1A09A0;
	static const u32 USA_UnlockCamera_Address = 0x1A51C8;
	static const u32 EUR_UnlockCamera_Address = 0x1A51E8;
	static const u32 USA_Thought_Address = 0x94FD88;
	static const u32 EUR_Thought_Address = 0x94ED88;
	static const u32 USA_PlayerIndex_Address = 0x82E93EC;
	static const u32 EUR_PlayerIndex_Address = 0x82E93EC;
	static const u32 USA_Player_Address = 0xAAE990; //0xAAD990, 0xAA6990


	static const u32 USA_Location_Address = 0x33077504;
	static const u32 EUR_Location_Address = 0x3304F184;
	static const u32 USA_IndoorPosX_Address = 0x330774FC;
	static const u32 USA_IndoorPosY_Address = 0x33077500;
	static const u32 USA_IndoorPosZ_Address = 0x33077504;
	static const u32 USA_OutdoorPosX_Address = 0x330773D0;
	static const u32 USA_OutdoorPosY_Address = 0x330773D4;
	static const u32 USA_OutdoorPosZ_Address = 0x330773D8;
	static const u32 USA_TownItems_Address = 0x31F7A458;
	static const u32 USA_IslandItems_Address = 0x31F96E58;
	static const u32 USA_PWP_Address = 0x31F772A8;
	static const u32 USA_Velocity_Address = 0x330773FC;
	static const u32 EUR_Velocity_Address = 0x3304F07C;
	static const u32 USA_GrassStart_Address = 0x31F80880;
	static const u32 USA_GrassEnd_Address = 0x31F8307F;
	static const u32 USA_Shop_Address = 0x31F891E4;
	static const u32 EUR_Shop_Address = 0x31F60E64;
	static const u32 USA_Tan_Address = 0x31F27028;
	static const u32 EUR_Tan_Address = 0x31EFECA8;
	static const u32 USA_Gender_Address = 0x31F2C5DA;
	static const u32 EUR_Gender_Address = 0x31F0425A;
	static const u32 USA_Seed_Address = 0x9B5268; //0x9AD248, 0x9B4268
	static const u32 USA_Edible_Address = 0x33077C86;
	static const u32 USA_ID_Address = 0x32CB0F60;
	static const u32 USA_Savetime_Address = 0x31F89120;
	static const u32 USA_Realtime_Address = 0x95D508; //0x955500, 0x95C500
	static const u32 USA_WorldX_Address = 0x33077838; //MainStreet_X
	static const u32 USA_WorldY_Address = 0x3307783C; //MainStreet_Y
	static const u32 USA_InputText_Address = 0x32CB0F60;
	static const u32 USA_InputTextOnline0_Address = 0x3200C7D0; //Blue
	static const u32 USA_InputTextOnline1_Address = 0x3200C860; //Red
	static const u32 USA_InputTextOnline2_Address = 0x3200C8F0; //Green
	static const u32 USA_InputTextOnline3_Address = 0x3200C980; //Yellow

	static const u32 USA_VISITOR_OUTDOOR_X_Address = 0x33079190;
	static const u32 USA_VISITOR_OUTDOOR_Z_Address = 0x33079198;
	static const u32 USA_VISITOR1_OUTDOOR_X_Address = 0x3307A2E0;
	static const u32 USA_VISITOR1_OUTDOOR_Z_Address = 0x3307A2E8;
	static const u32 USA_VISITOR2_OUTDOOR_X_Address = 0x3307B42C;
	static const u32 USA_VISITOR2_OUTDOOR_Z_Address = 0x3307B434;
	static const u32 USA_VISITOR_INDOOR_X_Address = 0x330792BC;
	static const u32 USA_VISITOR_INDOOR_Z_Address = 0x330792C4;
	static const u32 USA_VISITOR1_INDOOR_X_Address = 0x3307A3F4;
	static const u32 USA_VISITOR1_INDOOR_Z_Address = 0x3307A3FC;
	static const u32 USA_VISITOR2_INDOOR_X_Address = 0x3307B77C;
	static const u32 USA_VISITOR2_INDOOR_Z_Address = 0x3307B784;

	static const u32 USA_Minutes_Address = 0x9515BA;
	static const u32 USA_Hours_Address = 0x9515BB;

	static const u32 USA_Keyboard_Address = 0x32DC4A10;
	static const u32 USA_KeyboardIsland_Address = 0x32DF7D14;
	static const u32 USA_KeyboadIsland_Address = 0x32DCF994;
	static const u32 USA_InputTextIsland_Address = 0x32CBD508;
	static const u32 USA_ABD_Address = 0x32DD1AC8; //this one stays in memory, so it is used to write to the inventory. nvm, it doesn't
	static const u32 USA_ABD_REAL_Address = 0x32DD1EF8; //this one is the real decimal offset,
	static const u32 USA_ABD_OFFLINE_Address = 0x32DC5520;
	static const u32 USA_WalkOver_Address = 0x33077533;
	static const u32 EUR_WalkOver_Address = 0x3304F1B3;
	static const u32 USA_CollisionOut_Address = 0x33077534;
	static const u32 EUR_CollisionOut_Address = 0x3304F1B4;
	static const u32 USA_CollisionIn_Address = 0x33077663;
	static const u32 EUR_CollisionIn_Address = 0x3304F2E3;

	static const u32 USA_Wallet_Address = 0x31F2DF28;
	static const u32 USA_OnlineWallet0_Address = 0xAAB418;
	static const u32 USA_OnlineWallet1_Address = 0xA8C698;
	static const u32 USA_OnlineWallet2_Address = 0xA96B18;
	static const u32 USA_OnlineWallet3_Address = 0xAA0F98;
	static const u32 USA_OnlineWallet4_Address = 0xA8C698;
	static const u32 USA_OnlineWallet5_Address = 0xA96B18;
	static const u32 USA_OnlineWallet6_Address = 0xA9EF98;

	static const u32 USA_Medals_Address = 0x31F2DBBC;
	static const u32 USA_OnlineMedals0_Address = 0xAAB0B0;
	static const u32 USA_OnlineMedals1_Address = 0xA8C330;
	static const u32 USA_OnlineMedals2_Address = 0xA967B0;
	static const u32 USA_OnlineMedals3_Address = 0xAA0C30;
	static const u32 USA_OnlineMedals4_Address = 0xA8C330;
	static const u32 USA_OnlineMedals5_Address = 0xA967B0;
	static const u32 USA_OnlineMedals6_Address = 0xA9EC30;
	static const u32 USA_Badge_Address = 0x31F2C6BC;

	static const u32 USA_Weather_Address = 0x62FC30;
	static const u32 EUR_Weather_Address = 0x62EC68;
	static const u32 USA_Saison_Address = 0x56C758;
	static const u32 USA_Festival_Address = 0x9534EC;

	static const u32 USA_OpenReTail_Address = 0x309348;
	static const u32 EUR_OpenReTail_Address = 0x309344;
	static const u32 USA_OpenNookling_Address = 0x711B14;
	static const u32 EUR_OpenNookling_Address = 0x710B1C;
	static const u32 USA_OpenGarden_Address = 0x711BCC;
	static const u32 EUR_OpenGarden_Address = 0x710BD4;
	static const u32 USA_OpenAbles_Address = 0x713EB0;
	static const u32 EUR_OpenAbles_Address = 0x712EB8;
	static const u32 USA_OpenShampoodle_Address = 0x71D42C;
	static const u32 EUR_OpenShampoodle_Address = 0x71C434;
	static const u32 USA_OpenKicks_Address = 0x71184C;
	static const u32 EUR_OpenKicks_Address = 0x710854;
	static const u32 USA_OpenNooks_Address = 0x71F654;
	static const u32 EUR_OpenNooks_Address = 0x71E65C;
	static const u32 USA_OpenKatrina_Address = 0x718098;
	static const u32 EUR_OpenKatrina_Address = 0x7170A0;
	static const u32 USA_OpenRedd_Address = 0x718444;
	static const u32 EUR_OpenRedd_Address = 0x71744C;

	static const u32 USA_NoBreakFlowers_Address = 0x597F64;
	static const u32 EUR_NoBreakFlowers_Address = 0x596FAC;
	static const u32 USA_EverythingSeeder1_Address = 0x19C050;
	static const u32 USA_EverythingSeeder2_Address = 0x725124;
	static const u32 USA_DropSeeder_Address = 0x9E0020;
	static const u32 EUR_DropSeeder_Address = 0x9DF020; // wrong?
	static const u32 USA_DropMode1_Address = 0x19CFFC;
	static const u32 EUR_DropMode1_Address = 0x19D01C;
	static const u32 USA_DropMode2_Address = 0x660430;
	static const u32 EUR_DropMode2_Address = 0x66F8D8;
	static const u32 USA_DropType_Address = 0x59771C;
	static const u32 EUR_DropType_Address = 0x596764;
	static const u32 USA_ByPassItemDrop1_Address = 0x5A11C8;
	static const u32 EUR_ByPassItemDrop1_Address = 0x5A0210;
	static const u32 USA_ByPassItemDrop2_Address = 0x5A11CC;
	static const u32 EUR_ByPassItemDrop2_Address = 0x5A0214;
	static const u32 USA_ByPassItemDrop3_Address = 0x5A13C8;
	static const u32 EUR_ByPassItemDrop3_Address = 0x5A0410;
	static const u32 USA_ByPassItemDrop4_Address = 0x5A13CC;
	static const u32 EUR_ByPassItemDrop4_Address = 0x5A0414;
	static const u32 USA_PickUpSeeder_Address = 0x9E0000;
	static const u32 EUR_PickUpSeeder_Address = 0x9DF000; // wrong?
	static const u32 USA_PickUpItem_Address = 0x59A268;
	static const u32 EUR_PickUpItem_Address = 0x5992B0;
	static const u32 USA_AlwaysPickUp_Address = 0x59A0C4;
	static const u32 EUR_AlwaysPickUp_Address = 0x59910C;
	static const u32 USA_PickUpAnim_Address = 0x65D410;
	static const u32 EUR_PickUpAnim_Address = 0x65C448;
	static const u32 USA_PickUpInventoryFix_Address = 0x599FA8;
	static const u32 EUR_PickUpInventoryFix_Address = 0x598FF0;


	/*ASM*/
	static const u32 USA_ASM_DropReplaceSwitch = 0x5A1120;
	static const u32 EUR_ASM_DropReplaceSwitch = 0x5A0168;
	static const u32 USA_ASM_RemoveSentCharacters = 0x1939F0;
	static const u32 USA_ASM_BottomScreenMenu = 0x6D2B50;

	static const u32 USA_Repalce_Hook = 0x165528;
	static const u32 EUR_Repalce_Hook = 0x165548;
}

#endif