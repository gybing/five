// ChessAI.h: interface for the CChessAI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHESSAI_H__DAD6397F_6A68_414B_88B9_7C41E5CCA982__INCLUDED_)
#define AFX_CHESSAI_H__DAD6397F_6A68_414B_88B9_7C41E5CCA982__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <list>
#include <map>

using namespace std;

typedef struct stAI_POINT
{
	LONG x;
	LONG y;
	INT64 score;
}AI_POINT;


#define BASE_ADDR 0x0041D148

#define WIDTH_COUNT 15
#define HEIGHT_COUNT 15

#define WHITE_CHESS		1	// ����
#define BLACK_CHESS		2	// ����
#define NO_CHESS		0	// �հ�

#define COLOR_INVERT(color)  (color) == WHITE_CHESS ? BLACK_CHESS : WHITE_CHESS

#define CUT_SCORE		(0x8FFFFFFFFFFFFFF)

#define F_INFINITE      10000000000

// �÷����ָ��
#define FIVE_SCORE		F_INFINITE		 // ���ӵ÷�
#define FOUR_SCORE		5000			 // ���ӵ÷�
#define THREE_SCORE     1000			 // ���ӵ÷�
#define TWO_SCORE		100			     // ���ӵ÷�
#define ONE_SCORE		1				 // ���ӵ÷�

#define S_THREE_SCORE   10				 // �����÷�
#define D_THREE_SCORE   F_INFINITE 		 // ˫���÷�

#define MAX_LEVEL 20  // ����������

#define MAX_CANDIDATE  20 // ����ѡ�ڵ����


#define FIVECELL_MAX	 3*3*3*3*3
#define TENCELL_MAX		 3*3*3*3*3*3*3*3*3*3

#define MAX(a,b)   (a) > (b) ? (a) : (b)

#define MIN(a,b)   (a) < (b) ? (a) : (b)


extern LARGE_INTEGER g_tc;
extern INT64 g_FiveCellMap[3][3][3][3][3];
extern INT64 g_aui64LevelScore[MAX_LEVEL];


#define GET_NS(b,e)  (((e.QuadPart)-(b.QuadPart))*1000*1000*1000)/(g_tc.QuadPart)


enum DIRECTION
{
	DIRECTION_A = 0,	// X����
	DIRECTION_B = 1,	// Y����
	DIRECTION_C = 2,	// X��Yͬ����
	DIRECTION_D = 3,	// X��Y������
	DIRECTION_MAX,
};
//#define DIRECTION_A		0	// X����
//#define DIRECTION_B		1	// Y����
//#define DIRECTION_C		2	// X��Yͬ����
//#define DIRECTION_D		3	// X��Y������


AI_POINT AI(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiAIColor, UINT32 uiLevel, INT64 *score, INT64 uiBase);
void ClearLevelScore();
void FiveCellMapInit();
extern inline INT64 Evaluate(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor);  // 53300ns
extern inline INT64 Evaluate2(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor);  // 53300ns
inline INT64 Get15CellScore(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9,
							int a10, int a11, int a12, int a13, int a14);
inline INT64 GetALLObliqueLinesScore(BYTE a[HEIGHT_COUNT][WIDTH_COUNT]);
extern inline BOOL IsWin(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor, UINT32 uiX, UINT32 uiY);
extern inline INT64 GetPointScore(BYTE a[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor, UINT32 uiX, UINT32 uiY);




class CChessAI  
{
public:
	// �������ݡ�
	BYTE m_chessArray[HEIGHT_COUNT][WIDTH_COUNT]; // 0��ʾû���壬1��ʾ���壬2��ʾ����
	CChessAI();
	virtual ~CChessAI();

	vector<AI_POINT> m_blackChessArray;
	vector<AI_POINT> m_whiteChessArray;

	void UpdataChessData(BYTE *pData);

	void GetPos(AI_POINT &pt);

	BOOL CanFive(AI_POINT pt, int nColor);

	BOOL CanFour(AI_POINT pt, int nColor);

	BOOL CanThree(AI_POINT pt, int nColor, int nDirection);

};

#endif // !defined(AFX_CHESSAI_H__DAD6397F_6A68_414B_88B9_7C41E5CCA982__INCLUDED_)
