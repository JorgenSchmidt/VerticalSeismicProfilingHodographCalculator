#ifndef GodographCalculatorFunctions
#define GodographCalculatorFunctions

#include "../Core/Structures.h"

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
	printf("\nCalculateGodographForOne proc isnt implemented");
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