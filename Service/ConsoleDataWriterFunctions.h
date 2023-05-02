#ifndef ConsoleDataWriterFunctions
#define ConsoleDataWriterFunctions

#include "../Core/Structures.h"

void WriteDataValues(
						// ���-�� ����� ����������
						int ExplorationPointsCount,
						// ������ � ����������� � ������������ ���������
						TGodographData *GopographDataMassive
					) 
{
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		printf("�����%i.\t%lf\t%lf\n", c+1, GopographDataMassive[c].Depth, GopographDataMassive[c].ArrivalTime);
	}
}

#endif