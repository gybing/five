// ChessAI.h: interface for the CChessAI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHESSAI_H__DAD6397F_6A68_414B_88B9_7C41E5CCA982__INCLUDED_)
#define AFX_CHESSAI_H__DAD6397F_6A68_414B_88B9_7C41E5CCA982__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <map>

using namespace std;

#define WIDTH_COUNT 15
#define HEIGHT_COUNT 15

#define WHITE_CHESS		1	// ����
#define BLACK_CHESS		2	// ����
#define NO_CHESS		0	// �հ�

#define COLOR_INVERT(color)  (color) == WHITE_CHESS ? BLACK_CHESS : WHITE_CHESS

#define CUT_SCORE		0xFFFFFFFFFFFFFFF

#define F_INFINITE      1000000000

// �÷����ָ��
#define FIVE_SCORE		F_INFINITE		 // ���ӵ÷�
#define FOUR_SCORE		100000			 // ���ӵ÷�
#define THREE_SCORE     1000			 // ���ӵ÷�
#define TWO_SCORE		10			     // ���ӵ÷�
#define ONE_SCORE		1				 // ���ӵ÷�

#define S_THREE_SCORE   10				 // �����÷�
#define D_THREE_SCORE   F_INFINITE 		 // ˫���÷�

#define MAX_LEVEL 20  // ����������

extern LARGE_INTEGER g_tc;


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


POINT AI(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiAIColor, UINT32 uiLevel, INT64 *score);


class CChessAI  
{
public:
	// �������ݡ�
	BYTE m_chessArray[HEIGHT_COUNT][WIDTH_COUNT]; // 0��ʾû���壬1��ʾ���壬2��ʾ����
	CChessAI();
	virtual ~CChessAI();

	vector<POINT> m_blackChessArray;
	vector<POINT> m_whiteChessArray;

	void UpdataChessData(BYTE *pData);

	void GetPos(POINT &pt);

	BOOL CanFive(POINT pt, int nColor);

	BOOL CanFour(POINT pt, int nColor);

	BOOL CanThree(POINT pt, int nColor, int nDirection);

};

#endif // !defined(AFX_CHESSAI_H__DAD6397F_6A68_414B_88B9_7C41E5CCA982__INCLUDED_)
