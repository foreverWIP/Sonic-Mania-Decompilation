#include "../SonicMania.h"

ObjectTilePlatform *TilePlatform;

void TilePlatform_Update(void) { Platform_Update(); }

void TilePlatform_LateUpdate(void) {}

void TilePlatform_StaticUpdate(void) {}

void TilePlatform_Draw(void)
{
    RSDK_THIS(TilePlatform);
    RSDK.DrawTile(entity->tiles, entity->size.x >> 20, entity->size.y >> 20, &entity->drawPos, NULL, false);
}

void TilePlatform_Create(void *data)
{
    RSDK_THIS(TilePlatform);
    entity->collision = 2;
    Platform_Create(NULL);
    if (!RSDK_sceneInfo->inEditor) {
        entity->hitbox.bottom = entity->size.y >> 17;
        entity->hitbox.right  = entity->size.x >> 17;
        entity->updateRange.x += 2 * entity->size.x;
        entity->updateRange.y += 2 * entity->size.y;
        entity->hitbox.top  = -(entity->size.y >> 17);
        entity->hitbox.left = -entity->size.x >> 17;
        entity->size.x += 0x80000;
        entity->size.y += 0x80000;
        int originX = (entity->targetPos.x >> 20) - (entity->size.x >> 21);
        int originY = (entity->targetPos.y >> 20) - (entity->size.y >> 21);

        int h = entity->size.y >> 20;
        int w = entity->size.x >> 20;

        int id = 0;
        if ((entity->size.y & 0xFFF00000) > 0) {
            for (int y = 0; y < h; ++y) {
                if ((entity->size.x & 0xFFF00000) > 0) {
                    for (int x = 0; x < w; ++x) {
                        entity->tiles[id] = RSDK.GetTileInfo(Zone->moveLayer, x + originX, y + originY);
                        id                = x + y * (entity->size.x >> 20);
                    }
                }
            }
        }
    }
}

void TilePlatform_StageLoad(void) {}

void TilePlatform_EditorDraw(void) {}

void TilePlatform_EditorLoad(void) {}

void TilePlatform_Serialize(void)
{
    RSDK_EDITABLE_VAR(TilePlatform, VAR_ENUM, type);
    RSDK_EDITABLE_VAR(TilePlatform, VAR_VECTOR2, amplitude);
    RSDK_EDITABLE_VAR(TilePlatform, VAR_ENUM, speed);
    RSDK_EDITABLE_VAR(TilePlatform, VAR_BOOL, hasTension);
    RSDK_EDITABLE_VAR(TilePlatform, VAR_VECTOR2, targetPos);
    RSDK_EDITABLE_VAR(TilePlatform, VAR_ENUM, childCount);
    RSDK_EDITABLE_VAR(TilePlatform, VAR_VECTOR2, size);
    RSDK_EDITABLE_VAR(TilePlatform, VAR_INT32, angle);
}