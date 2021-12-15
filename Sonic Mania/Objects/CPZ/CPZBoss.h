#ifndef OBJ_CPZBOSS_H
#define OBJ_CPZBOSS_H

#include "SonicMania.h"

typedef enum {
    CPZBOSS_PLAYER,
    CPZBOSS_EGGMAN,
}CPZBossTypes;

// Object Class
typedef struct {
    RSDK_OBJECT
    Hitbox hitbox;
    Entity* managers[2];
    uint16 hudSlotID;
    uint16 aniFrames;
    uint16 playerFrames;
    uint16 sfxExplosion;
} ObjectCPZBoss;

// Entity Class
typedef struct {
    RSDK_ENTITY
    StateMachine(state);
    uint8 type;
    int32 timer;
    Vector2 startPos;
    Vector2 explosionPos;
    Animator panelAnimator;
    Animator enterAnimator;
    Animator playerAnimator;
} EntityCPZBoss;

// Object Struct
extern ObjectCPZBoss *CPZBoss;

// Standard Entity Events
void CPZBoss_Update(void);
void CPZBoss_LateUpdate(void);
void CPZBoss_StaticUpdate(void);
void CPZBoss_Draw(void);
void CPZBoss_Create(void* data);
void CPZBoss_StageLoad(void);
#if RETRO_INCLUDE_EDITOR
void CPZBoss_EditorDraw(void);
void CPZBoss_EditorLoad(void);
#endif
void CPZBoss_Serialize(void);

// Extra Entity Functions
void CPZBoss_DrawLayerCB_SetupPuyoDropperClip(void);
void CPZBoss_DrawLayerCB_RemovePuyoDropperClip(void);

bool32 CPZBoss_CheckMatchReset(void);

void CPZBoss_State_SetupArena(void);
void CPZBoss_State_EnterPlayer(void);
void CPZBoss_State_CheckPlayerReady(void);
void CPZBoss_State_PlayPlayerEnterAnim(void);
void CPZBoss_State_SetupMatch(void);
void CPZBoss_State_HandleMatch_Player(void);
void CPZBoss_State_HandleMatch_Eggman(void);
void CPZBoss_State_HandleMatchFinish_EggmanLose(void);
void CPZBoss_State_PlayerWin(void);
void CPZBoss_State_HandleMatchFinish_PlayerLose(void);
void CPZBoss_State_EggmanFall(void);
void CPZBoss_State_PlayerExit(void);
void CPZBoss_State_Destroyed(void);

#endif //!OBJ_CPZBOSS_H
