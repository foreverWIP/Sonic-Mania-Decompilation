#ifndef OBJ_BOMB_H
#define OBJ_BOMB_H

#include "SonicMania.h"

// Object Class
typedef struct {
    RSDK_OBJECT
    Hitbox hitboxHurt;
    Hitbox hitboxRange;
    Hitbox hitboxShrapnel;
    ushort aniFrames;
    ushort sfxExplosion;
} ObjectBomb;

// Entity Class
typedef struct {
    RSDK_ENTITY
    StateMachine(state);
    int planeFilter;
    Vector2 startPos;
    byte startDir;
    int timer;
    int fuseOffset;
    Animator animator;
    Animator animator2;
} EntityBomb;

// Object Entity
extern ObjectBomb *Bomb;

// Standard Entity Events
void Bomb_Update(void);
void Bomb_LateUpdate(void);
void Bomb_StaticUpdate(void);
void Bomb_Draw(void);
void Bomb_Create(void* data);
void Bomb_StageLoad(void);
void Bomb_EditorDraw(void);
void Bomb_EditorLoad(void);
void Bomb_Serialize(void);

// Extra Entity Functions
void Bomb_DebugSpawn(void);
void Bomb_DebugDraw(void);

void Bomb_CheckOnScreen(void);
void Bomb_CheckPlayerCollisions(void);

void Bomb_State_Setup(void);
void Bomb_State_Walk(void);
void Bomb_State_Idle(void);
void Bomb_State_Explode(void);
void Bomb_State_Shrapnel(void);

#endif //!OBJ_BOMB_H