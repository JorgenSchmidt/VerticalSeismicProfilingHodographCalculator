/*	Одна тестируемая функция с сигнатурой
	void RecordGodographDataValues
								(
	*/								// Скорость АВ в последнем (!) пласте
	/*								double LastFormationAcousticSpeed,
	*/								// Количество пластов с учётом последнего пласта
	/*								int FormationsCount,
	*/								// Массив с инфорамацией о пластах
	/*								TFormation *FormationsMassive,
	*/								// Кол-во точек наблюдений
	/*								int ExplorationPointsCount,
	*/								// Массив с информацией о рассчитанных значениях
	/*								TGodographData *GopographDataMassive
								)
*/ 

//	Функция принимает массив экземпляров следующих структур: 
/*	typedef struct 
	{
		double Depth; 	double ArrivalTime;
	} TGodographData; */
/*	typedef struct 
	{
		// Мощность пласта
		double FormationCapacity;
		// Значение скорости распространения АВ для пласта
		double FormationAcousticSpeed;
	} TFormation; */

// Подключение стандартных библиотек
#include <stdio.h>
#include <locale.h>
#include <conio.h>

// Подключение заголовочных файлов с базовыми сущностями и константами
#include "../Core/AppConfiguration.h"
#include "../Core/Structures.h"

// Подключение заголовочного файла тестируемых функций
#include "../Service/FileOperatorFunctions.h"

// Прототипы процедур тестов
void test_1();
void test_2();
void test_3();

// Основная часть
int main() 
{
	setlocale(LC_ALL, "Russian_Russia.1251");
	test_1();
	test_2();
	test_3();
	printf("\nДля выхода из режима тестирования нажмите любую клавишу...");
	getch();
	return 0;
}

// Процедуры тестов

// Тест на забивку в файл данных по двум пластам
void test_1 () 
{
	// Параметры среды
	int formCount = 2;
	TFormation Formations[formCount - 1];
	Formations[0].FormationCapacity = 100;
	Formations[0].FormationAcousticSpeed = 500;
	
	// Снятые показания
	/*	Дословный перевод e_data exploration data*/
	int countData = 6;
	TGodographData e_data[countData];
	e_data[0].Depth = 25;
	e_data[0].ArrivalTime = 0.05;
	e_data[1].Depth = 50;
	e_data[1].ArrivalTime = 0.1;
	e_data[2].Depth = 75;
	e_data[2].ArrivalTime = 0.15;
	e_data[3].Depth = 100;
	e_data[3].ArrivalTime = 0.2;
	e_data[4].Depth = 125;
	e_data[4].ArrivalTime = 0.23125;
	e_data[5].Depth = 150;
	e_data[5].ArrivalTime = 0.2625;
	
	printf("Тест №1:\n");
	RecordGodographDataValues(800, formCount, Formations, countData, e_data, 20, 200);
	printf("\nНеобходимо просмотреть результат выполнения.\n");
	getch();
}

// Тест на забивку в файл данных по четырём пластам
void test_2 () 
{
	// Параметры среды
	int formCount = 4;
	TFormation Formations[formCount - 1];
	Formations[0].FormationCapacity = 100;
	Formations[0].FormationAcousticSpeed = 700;
	Formations[1].FormationCapacity = 200;
	Formations[1].FormationAcousticSpeed = 500;
	Formations[2].FormationCapacity = 150;
	Formations[2].FormationAcousticSpeed = 1000;
	
	// Снятые показания
	int countData = 10;
	TGodographData e_data[countData];
	e_data[0].Depth = 50;
	e_data[0].ArrivalTime = 0.071429;
	e_data[1].Depth = 100;
	e_data[1].ArrivalTime = 0.142857;
	e_data[2].Depth = 150;
	e_data[2].ArrivalTime = 0.242857143;
	e_data[3].Depth = 200;
	e_data[3].ArrivalTime = 0.342857143;
	e_data[4].Depth = 250;
	e_data[4].ArrivalTime = 0.442857143;
	e_data[5].Depth = 300;
	e_data[5].ArrivalTime = 0.542857143;
	e_data[6].Depth = 350;
	e_data[6].ArrivalTime = 0.592857143;
	e_data[7].Depth = 400;
	e_data[7].ArrivalTime = 0.642857143;
	e_data[8].Depth = 450;
	e_data[8].ArrivalTime = 0.692857143;
	e_data[9].Depth = 500;
	e_data[9].ArrivalTime = 0.73452381;
	
	printf("Тест №2:\n");
	RecordGodographDataValues(1200, formCount, Formations, countData, e_data, 100, 550);
	printf("\nНеобходимо просмотреть результат выполнения.\n");
	getch();
}

// Тест на забивку в файл данных по одному пласту
void test_3() 
{
	// Параметры среды
	int formCount = 1;
	TFormation Formations[1];
	Formations[0].FormationCapacity = 0;
	Formations[0].FormationAcousticSpeed = 0;
	
	// Снятые показания
	int countData = 5;
	TGodographData e_data[countData];
	e_data[0].Depth = 10;
	e_data[0].ArrivalTime = 0.02;
	e_data[1].Depth = 20;
	e_data[1].ArrivalTime = 0.04;
	e_data[2].Depth = 30;
	e_data[2].ArrivalTime = 0.06;
	e_data[3].Depth = 40;
	e_data[3].ArrivalTime = 0.08;
	e_data[4].Depth = 50;
	e_data[4].ArrivalTime = 0.1;
	
	printf("Тест №3:\n");
	RecordGodographDataValues(500, formCount, Formations, countData, e_data, 50, 75);
	printf("\nНеобходимо просмотреть результат выполнения.\n");
	getch();
}