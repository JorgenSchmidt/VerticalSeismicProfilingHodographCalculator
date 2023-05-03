#ifndef GodographCalculatorFunctions
#define GodographCalculatorFunctions

#include <math.h> 

#include "../Core/Structures.h"
#include "../Core/AppConfiguration.h"

// Процедура расчёта значений годографа для единичного пласта
void CalculateGodographForOne (
								// Шаг по скважине
								double StepBySeismicSpit, 
								// Скорость АВ в пласте
								double LastFormationAcousticSpeed,
								// Кол-во точек наблюдений
								int ExplorationPointsCount,
								// Массив данных
								TGodographData *GopographDataMassive
							  ) 
{
	double Depth = 0.0;
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		// Расчёт значений
		Depth = round((Depth + StepBySeismicSpit) * pow(10, ROUND_BY))/pow(10, ROUND_BY);
		double ArrivalTime = Depth / LastFormationAcousticSpeed;
		
		// Присваивание рассчитанных значений элементам массива экземпляров структуры TGodographData
		GopographDataMassive[c].Depth = Depth;
		GopographDataMassive[c].ArrivalTime = ArrivalTime;
	}
}

// Процедура расчёта значений годографа для 2 и больше пластов
void CalculateGodograph (
							// Шаг по скважине
							double StepBySeismicSpit, 
							// Скорость АВ в последнем (!) пласте
							double LastFormationAcousticSpeed,
							// Количество пластов с учётом последнего пласта
							int FormationsCount,
							// Массив с инфорамацией о пластах
							TFormation *FormationsMassive,
							// Кол-во точек наблюдений
							int ExplorationPointsCount,
							// Массив с информацией о рассчитанных значениях
							TGodographData *GopographDataMassive
						) 
{
	printf("\nCalculateGodograph proc isnt implemented");
}

#endif