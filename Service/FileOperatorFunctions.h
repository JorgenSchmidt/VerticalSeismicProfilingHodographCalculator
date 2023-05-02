#ifndef FileOperatorFunctions
#define FileOperatorFunctions

#include "../Core/AppConfiguration.h"
#include "../Core/Structures.h"

/* 	Записывает информацию по пластам и итоговым значениям
	в файл, формат должен быть удобен для вставки в Excel или Surfer 
	Каждый блок состоит из двух частей:
	1. Запись в файл информации о пластах
	2. Запись в файл расчитанных данных 
	Различие только в том, что для Excel 
	генерируется один файл, для Surfer сразу два */
void RecordGodographDataValues
								(
									// Скорость АВ в последнем (!) пласте
									double LastFormationAcousticSpeed,
									// Количество пластов с учётом последнего пласта
									int FormationsCount,
									// Массив с инфорамацией о пластах без учёта последнего
									TFormation *FormationsMassive,
									// Кол-во точек наблюдений
									int ExplorationPointsCount,
									// Массив с информацией о рассчитанных значениях
									TGodographData *GopographDataMassive,
									// Координата Y (для Surfer)
									double CoordY
								) 
{
	// I. Запись Excel-ориентированного файла
	FILE *FilePointerExc = fopen(EXCEL_FILE_NAME, "w");
	
	// 1. Запись в файл информации о пластах
	fprintf(FilePointerExc, "Параметры моделируемой среды: \n");
	fprintf(FilePointerExc, "№ пласта\tМощность пласта (м)\tСкорость АВ в пласте (м/с)\n");
	for (int c = 0; c < FormationsCount - 1; c++) 
	{
		fprintf(FilePointerExc, "%i\t%lf\t%lf\n", c+1, FormationsMassive[c].FormationCapacity, FormationsMassive[c].FormationAcousticSpeed);
	} 
	fprintf(FilePointerExc, "%i (последний)\t\t%lf\n\n", FormationsCount, LastFormationAcousticSpeed);
	
	// 2. Запись в файл расчитанных данных
	fprintf(FilePointerExc, "Записанные показания: \n");
	fprintf(FilePointerExc, "№ пикета\tГлубина точки измерения (м)\tВремя прихода волны к пикету (с)\n");
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		fprintf(FilePointerExc, "%i\t%lf\t%lf\n", c+1, GopographDataMassive[c].Depth, GopographDataMassive[c].ArrivalTime);
	}
	fclose(FilePointerExc);
	
	// II. Запись Surfer-ориентированных файлов
	
	// 1. Запись в файл информации о пластах
	
	// 2. Запись в файл расчитанных данных
}

#endif