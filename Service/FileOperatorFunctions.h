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
	/*	Оптимизирован под добавление с помощью инструмента Base map */
	FILE *FilePointerSurf_Form = fopen(SURFER_FORMINFO_FILE_NAME, "w");
	
	// Добавление линии поверхности
	fprintf(FilePointerExc, "2\t1\n");
	fprintf(FilePointerExc, "0\t%lf\n", 0.0);
	fprintf(FilePointerExc, "1\t%lf\n", 0.0);
	
	// Счётчик глубин залегания пластов
	double DepthCounter = 0.0;
	
	// Добавление линий 
	for (int c = 0; c < FormationsCount - 1; c++) 
	{
		DepthCounter += FormationsMassive[c].FormationCapacity;
		fprintf(FilePointerExc, "2\t1\n");
		fprintf(FilePointerExc, "0\t%lf\n", DepthCounter);
		fprintf(FilePointerExc, "1\t%lf\n", DepthCounter);
	} 
	
	fclose(FilePointerSurf_Form);
	
	// 2. Запись в файл расчитанных данных
	/*	Оптимизирован под добавление с помощью инструмента Grid Data*/
	FILE *FilePointerSurf_Data = fopen(SURFER_DATAINFO_FILE_NAME, "w");
	
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		fprintf(FilePointerExc, "%lf\t%lf\t%lf\n", GopographDataMassive[c].Depth, CoordY, GopographDataMassive[c].ArrivalTime);
	}
	
	fclose(FilePointerSurf_Data);
}

#endif