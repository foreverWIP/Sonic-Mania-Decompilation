#include "../SonicMania.h"

ObjectBSS_HUD *BSS_HUD;

void BSS_HUD_Update(void) {}

void BSS_HUD_LateUpdate(void) {}

void BSS_HUD_StaticUpdate(void) {}

void BSS_HUD_Draw(void)
{
    Vector2 drawPos;
    RSDK_THIS(BSS_HUD);
    drawPos.y             = 0xD0000;
    drawPos.x             = (RSDK_screens->centerX - 141) << 16;
    RSDK.DrawSprite(&entity->animData1, &drawPos, true);

    drawPos.x += 0x250000;
    drawPos.y = 0x110000;
    int x     = drawPos.x;
    BSS_HUD_DrawNumbers(BSS_Setup->sphereCount, &drawPos);
    drawPos.x = x + 0xA80000;
    drawPos.y = 0xD0000;
    RSDK.DrawSprite(&entity->animData2, &drawPos, true);

    drawPos.x += 0x380000;
    drawPos.y = 0x110000;
    BSS_HUD_DrawNumbers(BSS_Setup->ringCount, &drawPos);

    // DEBUG
    if (true) {
        ushort *playFields[3] = { BSS_Setup->playField, BSS_Setup->playField2, BSS_Setup->playField3 };

        uint colours[24] = { 0x000000, 0x0000FF, 0xFF0000, 0xFFFFFF, 0xFFFF00, 0x00FF00, 0xFF00FF, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000,
                             0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000 };

        for (int p = 0; p < 3; ++p) {
            for (int y = 0; y < BSS_PLAYFIELD_H; ++y) {
                for (int x = 0; x < BSS_PLAYFIELD_W; ++x) {
                    int playFieldPos = (x * BSS_PLAYFIELD_H) + y;
                    ushort type      = playFields[p][playFieldPos] & 0x7F;

                    RSDK.DrawRect((RSDK_screens->width - 64) + (x << 1), (RSDK_screens->height - (3 * 64)) + (p * 64) + (y << 1), 2, 2, colours[type],
                                  0xFF, INK_NONE, true);
                }
            }
        }
    }
}

void BSS_HUD_Create(void *data)
{
    RSDK_THIS(BSS_HUD);
    if (!RSDK_sceneInfo->inEditor) {
        entity->active        = ACTIVE_NORMAL;
        entity->visible       = true;
        entity->drawOrder     = DRAWLAYER_COUNT - 1;
        entity->updateRange.x = 0x800000;
        entity->updateRange.y = 0x800000;
        RSDK.SetSpriteAnimation(BSS_HUD->spriteIndex, 0, &entity->animData1, true, 0);
        RSDK.SetSpriteAnimation(BSS_HUD->spriteIndex, 0, &entity->animData2, true, 1);
        RSDK.SetSpriteAnimation(BSS_HUD->spriteIndex, 1, &entity->numbersData, true, 0);
    }
}

void BSS_HUD_StageLoad(void)
{
    BSS_HUD->spriteIndex = RSDK.LoadSpriteAnimation("SpecialBS/HUD.bin", SCOPE_STAGE);
    RSDK.ResetEntitySlot(SLOT_BSS_HUD, BSS_HUD->objectID, 0);
}

void BSS_HUD_DrawNumbers(int value, Vector2 *drawPos)
{
    RSDK_THIS(BSS_HUD);
    int mult              = 1;
    for (int i = 0; i < 3; ++i) {
        entity->numbersData.frameID = value / mult % 10;
        RSDK.DrawSprite(&entity->numbersData, drawPos, true);
        drawPos->x -= 0x100000;
        mult *= 10;
    }
}

void BSS_HUD_EditorDraw(void) {}

void BSS_HUD_EditorLoad(void) {}

void BSS_HUD_Serialize(void) {}