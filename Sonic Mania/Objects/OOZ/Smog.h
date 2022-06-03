#ifndef OBJ_SMOG_H
#define OBJ_SMOG_H

#include "SonicMania.h"

// Object Class
struct ObjectSmog {
    RSDK_OBJECT
    bool32 forceEnabled;
    ScanlineInfo *scanlines;
    uint8 scanlineData[0x100 * sizeof(ScanlineInfo)];
    uint16 aniFrames;
    int32 starPostID;
};

// Entity Class
struct EntitySmog {
    RSDK_ENTITY
    StateMachine(state); // unused
    int32 timer;
    Animator animator; // unused
    int32 unused1;     // unused
    int32 unused2;     // unused
};

// Object Struct
extern ObjectSmog *Smog;

// Standard Entity Events
void Smog_Update(void);
void Smog_LateUpdate(void);
void Smog_StaticUpdate(void);
void Smog_Draw(void);
void Smog_Create(void *data);
void Smog_StageLoad(void);
#if RETRO_INCLUDE_EDITOR
void Smog_EditorDraw(void);
void Smog_EditorLoad(void);
#endif
void Smog_Serialize(void);

// Extra Entity Functions
void Smog_DrawLayerCB(void);

#endif //! OBJ_SMOG_H
