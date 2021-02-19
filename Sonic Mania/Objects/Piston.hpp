#ifndef OBJ_PISTON_H
#define OBJ_PISTON_H

#include "../SonicMania.hpp"

// Object Class
struct ObjectPiston : Object{

};

// Entity Class
struct EntityPiston : Entity {

};

// Object Struct
extern ObjectPiston *Piston;

// Standard Entity Events
void Piston_Update();
void Piston_LateUpdate();
void Piston_StaticUpdate();
void Piston_Draw();
void Piston_Create(void* data);
void Piston_StageLoad();
void Piston_EditorDraw();
void Piston_EditorLoad();
void Piston_Serialize();

// Extra Entity Functions


#endif //!OBJ_PISTON_H