/* 	Одна тестируемая функция со следующей сигнатурой:
	void WriteDataValues(
	*/						// Кол-во точек наблюдений
	/*						int ExplorationPointsCount,*/
							// Массив с информацией о рассчитанных значениях
	/*						TGodographData *GopographDataMassive */
	/*					) 
*/

/*	Функция принимает массив экземпляров следующей структуры: 
typedef struct 
{
	double Depth; 	double ArrivalTime;
} TGodographData; */

// Подключение стандартных библиотек
#include <stdio.h>
#include <locale.h>
#include <conio.h>

// Подключение заголовочных файлов с базовыми сущностями и константами
#include "../Core/AppConfiguration.h"
#include "../Core/Structures.h"

// Подключение заголовочного файла тестируемых функций
#include "../Service/ConsoleDataWriterFunctions.h"

// Прототипы процедур тестов
void test_1();
void test_2();

// Основная часть
int main() 
{
	setlocale(LC_ALL, "Russian_Russia.1251");
	test_1();
	test_2();
	printf("\nДля выхода из режима тестирования нажмите любую клавишу...");
	getch();
	return 0;
}

// Процедуры тестов
void test_1() 
{
	int count = 4;
	TGodographData data[count];
	
	data[0].Depth = 50;
	data[0].ArrivalTime = 0.1;
	data[1].Depth = 100;
	data[1].ArrivalTime = 0.2;
	data[2].Depth = 150;
	data[2].ArrivalTime = 0.3;
	data[3].Depth = 200;
	data[3].ArrivalTime = 0.4;
	
	printf("Тест №1:\n");
	WriteDataValues(count, data);
	printf("\n");
}

void test_2() 
{
	int count = 5;
	TGodographData data[count];
	
	data[0].Depth = 50;
	data[0].ArrivalTime = 0.0025;
	data[1].Depth = 100;
	data[1].ArrivalTime = 0.05;
	data[2].Depth = 150;
	data[2].ArrivalTime = 0.075;
	data[3].Depth = 200;
	data[3].ArrivalTime = 0.1;
	data[4].Depth = 250;
	data[4].ArrivalTime = 0.125;
	
	printf("Тест №2:\n");
	WriteDataValues(count, data);
	printf("\n");
}