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
								TGodographData *GodographDataMassive
							  ) 
{
	double Depth = 0.0;
	double ArrivalTime = 0.0;
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		// Расчёт значений
		Depth = round((Depth + StepBySeismicSpit) * pow(10, ROUND_BY))/pow(10, ROUND_BY);
		ArrivalTime = Depth / LastFormationAcousticSpeed;
		
		// Присваивание рассчитанных значений элементам массива экземпляров структуры TGodographData
		GodographDataMassive[c].Depth = Depth;
		GodographDataMassive[c].ArrivalTime = ArrivalTime;
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
							TGodographData *GodographDataMassive
						) 
{
	// Инициализация переменных
	int FormationCounter = 0;
	double Depth = 0.0;
	double DepthFormationCounter = 0.0;
	double ArrivalTime = 0.0;
	double CurrentFormationDepth = FormationsMassive[0].FormationCapacity;
	
	// Расчёт значений
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		/* 	Расчёт глубины залегания датчика и проверка на пересечение 
			текущего пласта (определяется переменной FormationCounter) 
			рассматриваемой точкой наблюдения */
		Depth = round((Depth + StepBySeismicSpit) * pow(10, ROUND_BY))/pow(10, ROUND_BY);
		if ( Depth > CurrentFormationDepth) 
		{
			if (FormationCounter < FormationsCount - 2) 
			{
				FormationCounter++;
				CurrentFormationDepth += FormationsMassive[FormationCounter].FormationCapacity;
			}
			else 
			{
				FormationCounter = FormationsCount - 1;
			}
		}
		
		// Расчёт времени прихода АВ к текущей точке наблюдений
		if (FormationCounter != 0) 
		{
			// Расчёт АВ и глубины залегания сейсмодатчика для второго и далее по счёту пластов
			ArrivalTime = 0;
			/* 	Дословный перевод curFormation - current formation - текущий пласт */
			for (int curFormation = 0; curFormation < FormationCounter; curFormation++) 
			{
				ArrivalTime += FormationsMassive[curFormation].FormationCapacity / FormationsMassive[curFormation].FormationAcousticSpeed;
			}
			
			// Ветвление для определения стратегии расчёта значений времени прихода АВ
			/*	для последнего пласта, ввиду его некоторых особенностей, 
				значение прихода АВ считается по разному*/
			if (FormationCounter < FormationsCount - 1) 
			{
				// Расчёт времени прихода для пластов от 2 до последнего
				ArrivalTime += 	(Depth - (CurrentFormationDepth - FormationsMassive[FormationCounter].FormationCapacity))
								/ 
								FormationsMassive[FormationCounter].FormationAcousticSpeed;
				}
			else 
			{
				// Расчёт времени прихода для последнего пласта
				ArrivalTime += 	(Depth - CurrentFormationDepth)
								/ 
								LastFormationAcousticSpeed;
			}
		}
		else 
		{
			// Расчёт АВ и глубины залегания сейсмодатчика для первого пласта
			ArrivalTime = Depth / FormationsMassive[0].FormationAcousticSpeed;
		}
		// Присвоение текущему экземпляру массива структуры TGodographData расчитанных значений
		GodographDataMassive[c].Depth = Depth;
		GodographDataMassive[c].ArrivalTime = ArrivalTime;
	}
}

#endif