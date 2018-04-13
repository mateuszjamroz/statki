#ifndef _STATKI_INCLUDE_
#define _STATKI_INCLUDE_
#include <cstdlib>
#include "stdafx.h"
#include <memory.h>

typedef enum  
{
	UP,
	RIGHT,
	DOWN,
	LEFT
}DIRECTION;


#define N 5
#define M 5
#define DEPTH_MIN 5

int move(int** pTab, int nRow, int nCol, int nDepth, int DIRECTION, int x, int y, int* px, int* py, int** pRoot);
int root(int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest);
void setTab(char* f1, int** pTab, int nRow, int nCol);
void clearRoot(int*** pRoot, int nRow, int nCol);
int CreateMatrix(int*** pTab, int nCol, int nRow);
void PrintMatrix(int** pTab, int nCol, int nRow);

#endif
