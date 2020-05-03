#include "Renderer.h"

#define INT_CAST(x) static_cast<int>(x)

//����`��(�A���`�G�C���A�X�Ȃ�)
int Renderer::DrawLine(Vector2 startPos, Vector2 endPos, int color)
{
	return DxLib::DrawLine(INT_CAST(startPos.x), INT_CAST(startPos.y),
		INT_CAST(endPos.x), INT_CAST(endPos.y), color);
}

//����`��(�A���`�G�C���A�X����)
int Renderer::DrawLineAA(Vector2 startPos, Vector2 endPos, int color)
{
	return DxLib::DrawLineAA(startPos.x, startPos.y, endPos.x, endPos.y, color);
}

//�l�p�`��`��(�A���`�G�C���A�X�Ȃ�)
int Renderer::DrawBox(Vector2 topLeftPos, Vector2 bottomRightPos, int color, int fillFlag)
{
	return DxLib::DrawBox(INT_CAST(topLeftPos.x), INT_CAST(topLeftPos.y),
		INT_CAST(bottomRightPos.x), INT_CAST(bottomRightPos.y), color, fillFlag);
}

//�l�p�`��`��(�A���`�G�C���A�X�Ȃ�)
int Renderer::DrawBox(struct Rectangle* rect, int color, int fillFlag)
{
	return DxLib::DrawBox(INT_CAST(rect->Left()), INT_CAST(rect->Top()),
		INT_CAST(rect->Right()), INT_CAST(rect->Bottom()), color, fillFlag);
}

//�l�p�`��`��(�A���`�G�C���A�X����)
int Renderer::DrawBoxAA(Vector2 topLeftPos, Vector2 bottomRightPos, int color, int fillFlag)
{
	return DxLib::DrawBoxAA(topLeftPos.x, topLeftPos.y, bottomRightPos.x, bottomRightPos.y, color, fillFlag);
}

//�l�p�`��`��(�A���`�G�C���A�X����)
int Renderer::DrawBoxAA(struct Rectangle* rect, int color, int fillFlag)
{
	return DxLib::DrawBoxAA(rect->Left(), rect->Top(),
		rect->Right(), rect->Bottom(), color, fillFlag);
}

//�~��`��
int Renderer::DrawCircle(Vector2 position, int r, int color, int fillFlag)
{
	return DxLib::DrawCircle(INT_CAST(position.x), INT_CAST(position.y), r, color, fillFlag);
}

//�~��`��(�A���`�G�C���A�X����)
int Renderer::DrawCircleAA(Vector2 position, float r, int posnum, int color, int fillFlag)
{
	return DxLib::DrawCircleAA(position.x, position.y, r, posnum, color, fillFlag);
}

//�ȉ~��`��
int Renderer::DrawOval(Vector2 position, Vector2 radius_xy, int color, int fillFlag)
{
	return DxLib::DrawOval(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(radius_xy.x), INT_CAST(radius_xy.y), color, fillFlag);
}

//�ȉ~��`��(�A���`�G�C���A�X����)
int Renderer::DrawOvalAA(Vector2 position, Vector2 radius_xy, int posnum, int color, int fillFlag)
{
	return DxLib::DrawOvalAA(position.x, position.y,
		radius_xy.x, radius_xy.y, posnum, color, fillFlag);
}

//�O�p�`��`��
int Renderer::DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, int color, int fillFlag)
{
	return DxLib::DrawTriangle(INT_CAST(v1.x), INT_CAST(v1.y),
		INT_CAST(v2.x), INT_CAST(v2.y),
		INT_CAST(v3.x), INT_CAST(v3.y), color, fillFlag);
}

//�O�p�`��`��(�A���`�G�C���A�X����)
int Renderer::DrawTriangleAA(Vector2 v1, Vector2 v2, Vector2 v3, int color, int fillFlag)
{
	return DxLib::DrawTriangleAA(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, color, fillFlag);
}

//�s�N�Z����`��
int Renderer::DrawPixel(Vector2 position, int color)
{
	return DxLib::DrawPixel(INT_CAST(position.x), INT_CAST(position.y), color);
}

//������`��
int Renderer::DrawString(Vector2 position, const char* text, int color)
{
	return DxLib::DrawString(INT_CAST(position.x), INT_CAST(position.y), text, color);
}

//������`�� �t�H�[�}�b�g�`��
int Renderer::DrawFormatString(Vector2 position, int color, char* formatString, ...)
{
	return DxLib::DrawFormatString(INT_CAST(position.x), INT_CAST(position.y), color, formatString);
}

//�����̕`�悵���ۂ̕����擾
int Renderer::GetDrawStringWidth(const char* text, int length)
{
	return DxLib::GetDrawStringWidth(text, length);
}

//�t�H�[�}�b�g�`���ŕ�����`�悵���ۂ̕����擾
int Renderer::GetDrawFormatStringWidth(char* formatString, ...)
{
	return DxLib::GetDrawFormatStringWidth(formatString);
}

//�t�H���g�f�[�^���쐬���� size = �t�H���g�T�C�Y thick = �t�H���g�̑���
int Renderer::CreateFontToHandle(const char* fontName, int size, int thick, int fontType)
{
	return DxLib::CreateFontToHandle(fontName, size, thick, fontType);
}

//�t�H���g�f�[�^���폜����
int Renderer::DeleteFontToHandle(int fontHandle)
{
	return DxLib::DeleteFontToHandle(fontHandle);
}

//�t�H���g�f�[�^�����Ƃɕ�����`�悷��
int Renderer::DrawStringToHandle(Vector2 position, const char* text, int color, int fontHandle)
{
	return DxLib::DrawStringToHandle(INT_CAST(position.x), INT_CAST(position.y),
		text, color, fontHandle);
}

//�t�H���g�f�[�^�����ƂɃt�H�[�}�b�g�`���ŕ�����`��
int Renderer::DrawFormatStringToHandle(Vector2 position, int color, int fontHandle, char* formatString, ...)
{
	return DxLib::DrawFormatStringToHandle(INT_CAST(position.x), INT_CAST(position.y), color, fontHandle, formatString);
}

//�t�H���g�f�[�^�ŕ�����`�悵���ۂ̕����擾
int Renderer::GetDrawStringWidthToHandle(const char* text, int length, int fontHandle)
{
	return DxLib::GetDrawStringWidthToHandle(text, length, fontHandle);
}

//�t�H���g�f�[�^�ŕ�����`�悵���ۂ̕����擾(�t�H�[�}�b�g�`��)
int Renderer::GetDrawFormatStringWidthToHandle(int fontHandle, char* formatString, ...)
{
	return DxLib::GetDrawFormatStringWidthToHandle(fontHandle, formatString);
}

//�t�H���g�f�[�^�̕����T�C�Y�Ƒ������擾�B�s�v�ȏꍇ��NULL����
int Renderer::GetFontStateToHandle(char* text, int* size, int* thick, int fontHandle)
{
	return DxLib::GetFontStateToHandle(text, size, thick, fontHandle);
}

//�t�H���g�f�[�^�����ׂč폜����
int Renderer::InitFontToHandle(void)
{
	return DxLib::InitFontToHandle();
}

//�摜�̍�����N�_�ɕ`�悷��
int Renderer::DrawGraph_TL(Vector2 position, int handle, int transFlag)
{
	return DxLib::DrawGraph(INT_CAST(position.x), INT_CAST(position.y), handle, transFlag);
}

//�摜�̒��S���N�_�ɕ`�悷��
int Renderer::DrawGraph_C(Vector2 position, Vector2 spriteSize, int handle, int transFlag)
{
	return DxLib::DrawGraph(INT_CAST(position.x - (spriteSize.x / 2.0f)),
		INT_CAST(position.y - (spriteSize.y - 2.0f)), handle, transFlag);
}

//�摜��������N�_�ɍ��E���]���ĕ`�悷��
int Renderer::DrawTurnGraph_TL(Vector2 position, int handle, int transFlag)
{
	return DxLib::DrawTurnGraph(INT_CAST(position.x), INT_CAST(position.y), handle, transFlag);
}

//�摜�𒆐S���N�_�ɍ��E���]���ĕ`�悷��
int Renderer::DrawTurnGraph_C(Vector2 position, Vector2 spriteSize, int handle, int transFlag)
{
	return DxLib::DrawTurnGraph(INT_CAST(position.x - (spriteSize.x / 2.0f)),
		INT_CAST(position.y - (spriteSize.y / 2.0f)), handle, transFlag);
}

//�摜�𒆐S���N�_�ɂ��ĕ`�� �g�嗦���w��
int Renderer::DrawScaleGraph(Vector2 position, float scale, int handle, int transFlag, int turnFlag)
{
	return DxLib::DrawRotaGraph(INT_CAST(position.x), INT_CAST(position.y),
		scale, 0.0, handle, transFlag, turnFlag);
}

//�摜�𒆐S���N�_�ɂ��ĕ`�� �p�x���w��
int Renderer::DrawRotateGraph(Vector2 position, float angle, int handle, int transFlag, int turnFlag)
{
	return DxLib::DrawRotaGraph(INT_CAST(position.x), INT_CAST(position.y),
		1.0, angle, handle, transFlag, turnFlag);
}

//�摜�𒆐S���N�_�ɂ��ĕ`�� �g�嗦�A�p�x���w��
int Renderer::DrawRotaGraph(Vector2 position, float scale, float angle, int handle, int transFlag, int turnFlag)
{
	return DxLib::DrawRotaGraph(INT_CAST(position.x), INT_CAST(position.y),
		scale, angle, handle, transFlag, turnFlag);
}

//�摜�̒��S���N�_�ɕ`�悵�A��]����_���w�肷��
int Renderer::DrawRotateGraph2(Vector2 position, Vector2 rotaPosition, float angle, int handle, int transFlag, int turnFlag)
{
	return DxLib::DrawRotaGraph2(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(rotaPosition.x), INT_CAST(rotaPosition.y),
		1.0f, angle, handle, transFlag, turnFlag);
}

//�摜�̒��S���N�_�ɕ`�悵�A��]����_���w�肷��
int Renderer::DrawRotaGraph2(Vector2 position, Vector2 rotaPosition, float scale, float angle, int handle, int transFlag, int turnFlag)
{
	return DxLib::DrawRotaGraph2(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(rotaPosition.x), INT_CAST(rotaPosition.y),
		scale, angle, handle, transFlag, turnFlag);
}

//�摜�̒��S���N�_�ɕ`�� XY�̊g�嗦���w�肷��
int Renderer::DrawScaleGraph3(Vector2 position, Vector2 spriteSize, Vector2 scale, int handle, int transFlag)
{
	return DxLib::DrawRotaGraph3(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(spriteSize.x / 2.0f), INT_CAST(spriteSize.y / 2.0f),
		scale.x, scale.y, 0.0, handle, transFlag);
}

//�摜�̒��S���N�_�ɕ`�悵�A��]����_���w�肷��
int Renderer::DrawRotaGraph3(Vector2 position, Vector2 rotaPosition, Vector2 scale, float angle, int handle, int transFlag)
{
	return DxLib::DrawRotaGraph3(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(rotaPosition.x), INT_CAST(rotaPosition.y),
		scale.x, scale.y, angle, handle, transFlag);
}

//�`��_���w�肵�ĉ摜��\������
int Renderer::DrawModiGraph(Vector2 topLeftPos, Vector2 topRightPos, Vector2 bottomRightPos, Vector2 bottomLeftPos, int handle, int transFlag)
{
	return DxLib::DrawModiGraph(INT_CAST(topLeftPos.x), INT_CAST(topLeftPos.y),
		INT_CAST(topRightPos.x), INT_CAST(topRightPos.y),
		INT_CAST(bottomRightPos.x), INT_CAST(bottomRightPos.y),
		INT_CAST(bottomLeftPos.x), INT_CAST(bottomLeftPos.y), handle, transFlag);
}

//��`�����w�肵�A���̕����݂̂�`�悷��
int Renderer::DrawRectGraph(Vector2 position, struct Rectangle* rect, int handle, int transFlag)
{
	return DxLib::DrawRectGraph(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(rect->x), INT_CAST(rect->y),
		INT_CAST(rect->width), INT_CAST(rect->height), handle, transFlag);
}

//�摜�̕��ƍ������擾���� �s�v�ȏꍇ��NULL����
int Renderer::GetGraphSize(int handle, int* widthBuf, int* heightBuf)
{
	return DxLib::GetGraphSize(handle, widthBuf, heightBuf);
}

//���ׂẲ摜�̃n���h�����폜����
int Renderer::InitGraph(void)
{
	return DxLib::InitGraph();
}

//�w�肵���摜�̃n���h�����폜����
int Renderer::DeleteGraph(int handle)
{
	return DxLib::DeleteGraph(handle);
}
