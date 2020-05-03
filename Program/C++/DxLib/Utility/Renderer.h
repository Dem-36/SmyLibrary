#ifndef _RENDERER_H_
#define _RENDERER_H_

#include"DxLib.h"
#include"Vector2.h"
#include"Rectangle.h"

//https://dxlib.xsrv.jp/dxfunc.html
//DxLibの描画関数のラップ
class Renderer
{
public:

	//--------------------------------------------------------
	//線

	int DrawLine(Vector2 startPos, Vector2 endPos, int color = GetColor(255, 255, 255));
	int DrawLineAA(Vector2 startPos, Vector2 endPos, int color = GetColor(255, 255, 255));

	//--------------------------------------------------------
	//四角形

	int DrawBox(Vector2 topLeftPos, Vector2 bottomRightPos,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);
	int DrawBox(struct Rectangle* rect,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);

	int DrawBoxAA(Vector2 topLeftPos, Vector2 bottomRightPos,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);
	int DrawBoxAA(struct Rectangle* rect,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);

	//--------------------------------------------------------
	//円

	int DrawCircle(Vector2 position, int r,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);
	//posnum = 円を形成する頂点数
	int DrawCircleAA(Vector2 position, float r, int posnum,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);

	//--------------------------------------------------------
	//楕円

	int DrawOval(Vector2 position, Vector2 radius_xy,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);
	//posnum = 楕円を形成する頂点数
	int DrawOvalAA(Vector2 position, Vector2 radius_xy, int posnum,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);

	//--------------------------------------------------------
	//三角形

	int DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);
	int DrawTriangleAA(Vector2 v1, Vector2 v2, Vector2 v3,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);

	//--------------------------------------------------------
	//ピクセル

	int DrawPixel(Vector2 position, int color = GetColor(255, 255, 255));

	//--------------------------------------------------------
	//文字

	int DrawString(Vector2 position, const char* text, int color = GetColor(255, 255, 255));
	//printfのように書式を指定できる
	int DrawFormatString(Vector2 position, int color, char* formatString, ...);

	int GetDrawStringWidth(const char* text, int length);

	int GetDrawFormatStringWidth(char* formatString, ...);

	//https://dxlib.xsrv.jp/function/dxfunc_graph2.html#R17N10
	int CreateFontToHandle(const char* fontName, int size, int thick, int fontType = DX_FONTTYPE_NORMAL);

	//フォントデータの削除
	int DeleteFontToHandle(int fontHandle);

	int DrawStringToHandle(Vector2 position, const char* text, int color, int fontHandle);

	int DrawFormatStringToHandle(Vector2 position, int color, int fontHandle, char* formatString, ...);

	int GetDrawStringWidthToHandle(const char* text, int length, int fontHandle);

	int GetDrawFormatStringWidthToHandle(int fontHandle, char* formatString, ...);

	//フォントのデータを取得する(不要な場合はNULL指定)
	int GetFontStateToHandle(char* text, int* size, int* thick, int fontHandle);

	int InitFontToHandle(void);

	//--------------------------------------------------------
	//画像

	int DrawGraph_TL(Vector2 position, int handle, int transFlag = TRUE);

	int DrawGraph_C(Vector2 position, Vector2 spriteSize, int handle, int transFlag = TRUE);

	int DrawTurnGraph_TL(Vector2 position, int handle, int transFlag = TRUE);
	int DrawTurnGraph_C(Vector2 position, Vector2 spriteSize, int handle, int transFlag = TRUE);

	int DrawScaleGraph(Vector2 position, float scale, int handle, int transFlag = TRUE, int turnFlag = FALSE);

	int DrawRotateGraph(Vector2 position, float angle, int handle, int transFlag = TRUE, int turnFlag = FALSE);

	int DrawRotaGraph(Vector2 position, float scale, float angle, int handle, int transFlag = TRUE, int turnFlag = FALSE);

	int DrawRotateGraph2(Vector2 position, Vector2 rotaPosition, float angle, int handle, int transFlag = TRUE, int turnFlag = FALSE);

	int DrawRotaGraph2(Vector2 position, Vector2 rotaPosition, float scale, float angle, int handle, int transFlag = TRUE, int turnFlag = FALSE);

	int DrawScaleGraph3(Vector2 position,Vector2 spriteSize, Vector2 scale, int handle, int transFlag = TRUE);

	int DrawRotaGraph3(Vector2 position, Vector2 rotaPosition, Vector2 scale, float angle, int handle, int transFlag = TRUE);

	int DrawModiGraph(Vector2 topLeftPos, Vector2 topRightPos, Vector2 bottomRightPos, Vector2 bottomLeftPos, int handle, int transFlag = TRUE);

	int DrawRectGraph(Vector2 position, struct Rectangle* rect, int handle, int transFlag = TRUE);

	int GetGraphSize(int handle, int* widthBuf, int* heightBuf);

	int InitGraph(void);

	int DeleteGraph(int handle);

	//--------------------------------------------------------
};

#endif