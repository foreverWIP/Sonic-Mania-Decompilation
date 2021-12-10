#ifndef OBJ_MANIAMODEMENU_H
#define OBJ_MANIAMODEMENU_H

#include "SonicMania.h"

#if RETRO_USE_PLUS
// Object Class
typedef struct {
    RSDK_OBJECT
    int32 unused;
    Entity *saveSelectMenu;
    Entity *noSaveMenu;
    Entity *secretsMenu;
    Entity *prompt1;
    Entity *encoreSaveSelect;
    Entity *prompt2;
    Entity *noSaveMenuEncore;
    bool32 inSecretsMenu;
    int32 saveSelLastButtonID;
} ObjectManiaModeMenu;

// Entity Class
typedef struct {
	RSDK_ENTITY
} EntityManiaModeMenu;

// Object Struct
extern ObjectManiaModeMenu *ManiaModeMenu;

// Standard Entity Events
void ManiaModeMenu_Update(void);
void ManiaModeMenu_LateUpdate(void);
void ManiaModeMenu_StaticUpdate(void);
void ManiaModeMenu_Draw(void);
void ManiaModeMenu_Create(void* data);
void ManiaModeMenu_StageLoad(void);
#if RETRO_INCLUDE_EDITOR
void ManiaModeMenu_EditorDraw(void);
void ManiaModeMenu_EditorLoad(void);
#endif
void ManiaModeMenu_Serialize(void);

// Extra Entity Functions
void ManiaModeMenu_Initialize(void);
bool32 ManiaModeMenu_InitAPI(void);
void ManiaModeMenu_InitLocalization(bool32 success);
int32 ManiaModeMenu_GetActiveMenu(void);
void ManiaModeMenu_ChangeMenuTrack(void);
int32 ManiaModeMenu_StartReturnToTitle(void);
void ManiaModeMenu_SetBGColours(void);
void ManiaModeMenu_ReturnToTitle(void);
void ManiaModeMenu_State_HandleTransition(void);
void ManiaModeMenu_HandleUnlocks(void);
void ManiaModeMenu_SetupActions(void);
void ManiaModeMenu_HandleMenuReturn(void);
#endif

#endif //!OBJ_MANIAMODEMENU_H
