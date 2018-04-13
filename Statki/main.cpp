#include "Statki.h"

#define PRINT

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("ERROR! There is no parameters!\n");
		return 0;
	}
	
	int nCol = M;
	int nRow = N;
	int** pTab = NULL;
	CreateMatrix(&pTab, nCol, nRow);
	if (!pTab)
	{
		printf("Unable to allocate memory!\n");
		return 1;
	}
	int** rTab = NULL;
	CreateMatrix(&rTab, nCol, nRow);
	if (!rTab)
	{
		printf("Unable to allocate memory!\n");
		return 1;
	}
	setTab(argv[1], pTab, nRow, nCol);
	//-------------------------------
	
#ifdef PRINT
	PrintMatrix(pTab, nRow, nCol);
	PrintMatrix(rTab, nRow, nCol);
#endif
	
	//--------------------------------
	int nDepth = DEPTH_MIN;

	if (root(pTab, nRow, nCol, nDepth, 0, 0, rTab, 4, 4))
	{
		PrintMatrix(rTab, nCol, nRow);
	}
	else
	{
		printf("There is no way to find the port!\n");
	}

	clearRoot(&pTab, nRow, nCol);
	clearRoot(&rTab, nRow, nCol);
	
	return 0;
}



