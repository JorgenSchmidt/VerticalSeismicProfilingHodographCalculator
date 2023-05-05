// 	Студент: Кузнецов Г.А., Группа: ГИН-20
//	Программа расчёта годографа ВСП

// Строки подключения стандартных библиотек
#include <stdio.h>
#include <locale.h>
#include <conio.h>

// Строки подключения заголовочных файлов
#include "Core/Structures.h"
#include "Service/GodographCalculatorFunctions.h"
#include "Service/FileOperatorFunctions.h"
#include "Service/ConsoleDataWriterFunctions.h"

int main()
{
	// Установка локализации (rus)
	setlocale(LC_ALL, "Russian_Russia.1251");
	
	// Инициализация переменных
	int FormationsCount;
	double WellDepth;
	double StepBySeismicSpit;
	double LastFormationAcousticSpeed;
	
	// Ввод пользователем значений
	printf("\nВведите количество пластов: ");
	scanf("%i", &FormationsCount);
	printf("\nВведите значение глубины скважины (м): ");
	scanf("%lf", &WellDepth);
	printf("\nВведите шаг по сейсморазведочной косе (м): ");
	scanf("%lf", &StepBySeismicSpit);
	
	// Проверка данных по геометрии скважины на корректность
	if 	(
				FormationsCount <= 0 
			|| 	WellDepth <= 0.0 
			|| 	StepBySeismicSpit <= 0.0 
			|| 	WellDepth <= StepBySeismicSpit + 5
		) 
	{
		// Вывод сообщения об ошибке и завершение работы программы
		printf("Введены некорректные данные. ");
		printf("\nПравила ввода информации на этапе определения геометрии среды: ");
		printf("\n1. Все введённые значения должны быть строго больше нуля.");
		printf("\n2. Значение глубины скважины должно превышать значение шага по ");
		printf("профилю на 5 и более. Например при глубине скважины в 30, ");
		printf("значение шага по профилю в 25 и меньше будет некорректно. ");
		getch();
		return 0;
	}
	
	// Побочная ветвь выполнения программы для данных с 1 пластом
	/* В случае если количество пластов равно единице, 
	   то управление передаётся специальной процедуре, 
	   после чего производится выход из программы */
	if (FormationsCount == 1) 
	{
		printf("\nВведите скорость распространения акустической волны пласта (м/с): ");
		scanf("%lf", &LastFormationAcousticSpeed);
		
		// Ввод координаты Y (для Surfer)
		double Coord_Y;
		printf("\nВведите координату Y (для Surfer): ");
		scanf("%lf", &Coord_Y);
		
		// Инициализация одноэлементного массива экземпляров структур TFormation
		/*	В целях универсализации процедуры вывода поля экземпляра структуры
			заданы равными нулю */
		TFormation FormationsMassive[1];
		FormationsMassive[0].FormationCapacity = 0;
		FormationsMassive[0].FormationAcousticSpeed = 0;
		
		// Инициализация массива структур с определённым количеством элементов
		int ExplorationPointsCount = WellDepth / StepBySeismicSpit;
		TGodographData GopographDataMassive[ExplorationPointsCount];
		
		/* 	Ссылку на массив структур передавать не стоит, 
			так как массив струтур уже содержит ссылку на 
			первый элемент массива. */
		CalculateGodographForOne (
									// Шаг по скважине
									StepBySeismicSpit,
									// Скорость АВ в пласте
									LastFormationAcousticSpeed,
									// Кол-во точек наблюдений
									ExplorationPointsCount,
									// Массив данных
									GopographDataMassive
								 );
		RecordGodographDataValues (
									// Скорость АВ в последнем (!) пласте
									LastFormationAcousticSpeed,
									// Количество пластов с учётом последнего пласта
									FormationsCount,
									// Массив с инфорамацией о пластах
									FormationsMassive,
									// Кол-во точек наблюдений
									ExplorationPointsCount,
									// Массив данных
									GopographDataMassive,
									// Координата Y (для Surfer)
									Coord_Y
								  );
		// Вывод данных в консоль по выбору пользователя
		int choise = 0;						  
		printf("\nВывести данные на экран? Если да, введите 1: ");
		scanf("%i", &choise);
		if (choise == 1) 
		{
			WriteDataValues(
							// Кол-во точек наблюдений
							ExplorationPointsCount,
							// Массив с информацией о рассчитанных значениях
							GopographDataMassive
						   ); 
		}
		getch();
		return 0;
	}
	
	
	// "Основная" ветвь выполнения программы для данных по 2 и более пластам
	
	// Инициализация массива экземпляров структуры TFormation 
	/*	Используется поправка на последний пласт, у которого
		в математической модели глубины как таковой нет,
		потому упомянутый пласт содержит отдельную переменную
		для скорости распространения АВ в нём*/
	double DepthCounter = 0.0;
	TFormation FormationsMassive[FormationsCount-1];
	
	// Заполнение массива FormationsMassive
	for (int Counter = 0; Counter < FormationsCount - 1; Counter++) 
	{
		// Инициализация локальных переменных (относительно цикла for) для ввода данных
		double DFormationCapacity;
		double DFormationAcousticSpeed;
		
		// Ввод значений
		printf("\nПласт №%i\n", Counter + 1);
		printf("Значение мощности пласта (м): ");
		scanf("%lf", &DFormationCapacity);
		printf("Значение распространения акустической волны для пласта (м/с): ");
		scanf("%lf", &DFormationAcousticSpeed);
		
		// Проверка введённых данных на корректность
		if 	(
					DFormationCapacity <= 0 
				|| DFormationAcousticSpeed <= 0 
				|| DFormationCapacity <= StepBySeismicSpit + 1
			) 
		{
			printf("\nВведены некорректные данные. ");
			printf("\nПравила ввода информации на этапе определения параметров среды: ");
			printf("\n1. Значения мощности пласта и распространения АВ должны быть строго больше 0;");
			printf("\n2. Значение мощности пласта должно превышать значение шага");
			printf(" по сейсморазведочной косе по меньшей мере на 1м.");
			printf(" Например для шага по косе в 25м будет некорректным значение 26 и меньше.");
			getch();
			return 0;
		}
		
		// Для вычисления глубины залегания подошвы предпоследнего пласта
		DepthCounter += DFormationCapacity;
		
		// Присваивание значений массиву экземпляров структуры TFormation
		FormationsMassive[Counter].FormationCapacity = DFormationCapacity;
		FormationsMassive[Counter].FormationAcousticSpeed = DFormationAcousticSpeed;
	}
	// Ввод значения скорости распространения акустической волны для последнего слоя	
	printf("\nЗначение распространения акустической волны для последнего пласта (м/с): ");
	scanf("%lf", &LastFormationAcousticSpeed);
	
	// Проверка на пересечение скважиной последнего пласта
	/*	Если глубина скважины не превышает значение глубины залегания 
		подошвы предпоследнего пласта, программа завершается*/
	if (WellDepth <= DepthCounter) 
	{
		printf("Скважина не пересекает последний пласт. ");
		getch();
		return 0;
	}
	
	// Ввод координаты Y (для Surfer)
	double Coord_Y;
	printf("\nВведите координату Y (для Surfer): ");
	scanf("%lf", &Coord_Y);
	
	// Инициализация массива структур с определённым количеством элементов
	int ExplorationPointsCount = WellDepth / StepBySeismicSpit;
	TGodographData GopographDataMassive[ExplorationPointsCount];
	
	// Расчёт годографа и вывод его в файл
	CalculateGodograph (
							// Шаг по скважине
							StepBySeismicSpit,
							// Скорость АВ в последнем (!) пласте
							LastFormationAcousticSpeed,
							// Количество пластов с учётом последнего пласта
							FormationsCount,
							// Массив с инфорамацией о пластах
							/*	Информации о последнем  
								пласте не содержит */
							FormationsMassive,
							// Кол-во точек наблюдений
							ExplorationPointsCount,
							// Массив с информацией о рассчитанных значениях
							GopographDataMassive
					   );
	RecordGodographDataValues (
									// Скорость АВ в последнем (!) пласте
									LastFormationAcousticSpeed,
									// Количество пластов с учётом последнего пласта
									FormationsCount,
									// Массив с инфорамацией о пластах
									FormationsMassive,
									// Кол-во точек наблюдений
									ExplorationPointsCount,
									// Массив данных
									GopographDataMassive,
									// Координата Y (для Surfer)
									Coord_Y
								  );
	// Вывод данных в консоль по выбору пользователя
	int choise = 0;						  
	printf("\nВывести данные на экран? Если да, введите 1: ");
	scanf("%i", &choise);
	if (choise == 1) 
	{
		WriteDataValues(
						// Кол-во точек наблюдений
						ExplorationPointsCount,
						// Массив с информацией о рассчитанных значениях
						GopographDataMassive
					   ); 
	}
		
	// Ожидание ввода любой клавиши
	getch();
	return 0;
}