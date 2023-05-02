#ifndef ConsoleDataWriterFunctions
#define ConsoleDataWriterFunctions

#include "../Core/Structures.h"

void WriteDataValues(
						// Кол-во точек наблюдений
						int ExplorationPointsCount,
						// Массив с информацией о рассчитанных значениях
						TGodographData *GopographDataMassive
					) 
{
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		printf("Пикет№%i.\t%lf\t%lf\n", c+1, GopographDataMassive[c].Depth, GopographDataMassive[c].ArrivalTime);
	}
}

#endif