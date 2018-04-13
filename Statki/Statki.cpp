#include "Statki.h"

int move(int** pTab, int nRow, int nCol, int nDepth, int DIRECTION, int x, int y, int* px, int* py, int** pRoot)
{   
	switch (DIRECTION)
	{
	case UP:
		*px=x-1;
		*py = y;
		break;
	case DOWN:
		*px=x+1;
		*py = y;
		break;
	case LEFT:
		*py =y-1;
		*px = x;
		break;
	case RIGHT:
		*py=y+1;
		*px = x;
		break;
	}
	if ((*px>nRow-1 || *px<0 || *py<0 || *py>nCol-1))
		return 0;
	if ((pTab[*px][*py] < nDepth + 1))
		return 0;
	if (pRoot[*px][*py])
		return 0;
	return 1;
}

//----------------------------------------------------------------------------------
int root(int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest)
{
	pRoot[x][y] = 1;

	if (pRoot[x_dest][y_dest])
	{
		return 1;
	}
	int px=x;
	int py=y;
	for (int i = UP; i <= LEFT; i++)
	{
		if (move(pTab, nRow, nCol, nDepth, i, x, y, &px, &py, pRoot))
		{
			if(root(pTab, nRow, nCol, nDepth, px, py, pRoot, x_dest, y_dest))
				return 1;
		}
	}
	pRoot[x][y] = 0;
	return 0;
}

void setTab(char* f, int** pTab, int nRow, int nCol)
{
	FILE* f1 = fopen(f, "r");
	if (!f1)
	{
		printf("Error! File not opened\n\n");
		return;
	}
	for (int i = 0; i < nRow; i++)
	{
		int* v = *pTab++;
		for (int j = 0; j < nCol; j++)
		{
			fscanf(f1, "%d" , v++);
		}
	}
	fclose(f1);
}

void clearRoot(int*** pRoot, int nRow, int nCol)
{
	for (int i = 0; i < nRow; i++)
	{
		free((*pRoot)[i]);
	}
	free(*pRoot);
	*pRoot = NULL;
}

//-------------------------------------------------

int CreateMatrix(int*** pTab, int nCol, int nRow)
{
	int** t = *pTab = (int**)calloc(nRow, sizeof(int*));
	if (!t)
	{
		printf("\nUnable to allocate memory\n");
		return -1;
	}
	for (int i = 0; i < nRow; i++)
	{
		*t++ = (int*)calloc(nCol, sizeof(int));
		if (!t)
		{
			printf("Unable to allocate memory!");
			return -1;
		}
	}
	return 1;
}

void PrintMatrix(int** pTab, int nCol, int nRow)
{
	for (int i = 0; i < nRow; i++)
	{
		int * v = pTab[i];
		for (int j = 0; j < nCol; j++)
			printf(" %d", *v++);
		printf("\n");
	}
	printf("\n");
}


