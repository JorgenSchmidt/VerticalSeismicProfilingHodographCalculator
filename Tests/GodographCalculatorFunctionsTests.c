// Подключение стандартных библиотек
#include <stdio.h>
#include <locale.h>
#include <conio.h>

// Подключение заголовочных файлов с базовыми сущностями и константами
#include "../Core/AppConfiguration.h"
#include "../Core/Structures.h"

// Подключение заголовочного файла тестируемых функций
#include "../Service/GodographCalculatorFunctions.h"

int main() 
{
	setlocale(LC_ALL, "Russian_Russia.1251");
	getch();
	return 0;
}