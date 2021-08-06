#ifndef OBJ_ANNOUNCER_H
#define OBJ_ANNOUNCER_H

#include "SonicMania.h"

// Object Class
typedef struct {
    RSDK_OBJECT
    ushort spriteIndex;
    ushort sfx_Three;
    ushort sfx_Two;
    ushort sfx_One;
    ushort sfx_Go;
    ushort sfx_Goal;
    ushort sfx_SonicWins;
    ushort sfx_TailsWins;
    ushort sfx_KnuxWins;
    ushort sfx_MightyWins;
    ushort sfx_RayWins;
    ushort sfx_NewRecordTop;
    ushort sfx_NewRecordMid;
    ushort sfx_Sonic;
    ushort sfx_Tails;
    ushort sfx_Knuckles;
    ushort sfx_Mighty;
    ushort sfx_Ray;
    ushort sfx_TheWinnerIs;
    ushort sfx_Player1;
    ushort sfx_Player2;
    ushort sfx_Player3;
    ushort sfx_Player4;
    ushort sfx_ItsADraw;
    ushort sfx_ItsADraw_Set;
    int dword38;
} ObjectAnnouncer;

// Entity Class
typedef struct {
    RSDK_ENTITY
    StateMachine(state);
    StateMachine(stateDraw);
    int timer;
    int playerID;
    int screen;
    Vector2 pos;
    Animator animator;
    Animator animator2;
} EntityAnnouncer;

// Object Struct
extern ObjectAnnouncer *Announcer;

// Standard Entity Events
void Announcer_Update(void);
void Announcer_LateUpdate(void);
void Announcer_StaticUpdate(void);
void Announcer_Draw(void);
void Announcer_Create(void* data);
void Announcer_StageLoad(void);
void Announcer_EditorDraw(void);
void Announcer_EditorLoad(void);
void Announcer_Serialize(void);

// Extra Entity Functions
void Announcer_Unknown1(void);
void Announcer_Unknown2(int screen);
void Announcer_Unknown3(void);
void Announcer_Unknown4(void);
void Announcer_Unknown5(void);
void Announcer_Unknown6(void);
void Announcer_Unknown7(void);
void Announcer_Unknown8(void);
void Announcer_Unknown9(void);

#endif //!OBJ_ANNOUNCER_H