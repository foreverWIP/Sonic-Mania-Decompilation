#ifndef OBJ_BUTTON_H
#define OBJ_BUTTON_H

#include "../SonicMania.h"

// Object Class
typedef struct {
    RSDK_OBJECT
    ushort spriteIndex;
    ushort field_6;
    bool32 hasEggman;
    bool32 hasPhantomRider;
    Hitbox hitbox2;
    Hitbox hitbox1;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    ushort sfxButton;
    ushort field_32;
} ObjectButton;

// Entity Class
typedef struct {
    RSDK_ENTITY
    int type;
    bool32 walkOnto;
    byte tag;
    int field_64;
    int field_68;
    int stood;
    int field_70;
    int field_74;
    int field_78;
    Hitbox hitbox;
    Animator data1;
    Animator data2;
} EntityButton;

// Object Struct
extern ObjectButton *Button;

// Standard Entity Events
void Button_Update(void);
void Button_LateUpdate(void);
void Button_StaticUpdate(void);
void Button_Draw(void);
void Button_Create(void* data);
void Button_StageLoad(void);
void Button_EditorDraw(void);
void Button_EditorLoad(void);
void Button_Serialize(void);

// Extra Entity Functions
void Button_CheckEggmanCollisions(void);
void Button_CheckPRiderCollisions(void);

void Button_Type0(void);
void Button_Type1(void);
void Button_Type2(void);
void Button_Type3(void);

#endif //!OBJ_BUTTON_H