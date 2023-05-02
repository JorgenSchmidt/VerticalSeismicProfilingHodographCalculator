#ifndef FileOperatorFunctions
#define FileOperatorFunctions

#include "../Core/AppConfiguration.h"
#include "../Core/Structures.h"

/* 	���������� ���������� �� ������� � �������� ���������
	� ����, ������ ������ ���� ������ ��� ������� � Excel ��� Surfer 
	������ ���� ������� �� ���� ������:
	1. ������ � ���� ���������� � �������
	2. ������ � ���� ����������� ������ 
	�������� ������ � ���, ��� ��� Excel 
	������������ ���� ����, ��� Surfer ����� ��� */
void RecordGodographDataValues
								(
									// �������� �� � ��������� (!) ������
									double LastFormationAcousticSpeed,
									// ���������� ������� � ������ ���������� ������
									int FormationsCount,
									// ������ � ������������ � ������� ��� ����� ����������
									TFormation *FormationsMassive,
									// ���-�� ����� ����������
									int ExplorationPointsCount,
									// ������ � ����������� � ������������ ���������
									TGodographData *GopographDataMassive,
									// ���������� Y (��� Surfer)
									double CoordY
								) 
{
	// I. ������ Excel-���������������� �����
	FILE *FilePointerExc = fopen(EXCEL_FILE_NAME, "w");
	
	// 1. ������ � ���� ���������� � �������
	fprintf(FilePointerExc, "��������� ������������ �����: \n");
	fprintf(FilePointerExc, "� ������\t�������� ������ (�)\t�������� �� � ������ (�/�)\n");
	for (int c = 0; c < FormationsCount - 1; c++) 
	{
		fprintf(FilePointerExc, "%i\t%lf\t%lf\n", c+1, FormationsMassive[c].FormationCapacity, FormationsMassive[c].FormationAcousticSpeed);
	} 
	fprintf(FilePointerExc, "%i (���������)\t\t%lf\n\n", FormationsCount, LastFormationAcousticSpeed);
	
	// 2. ������ � ���� ����������� ������
	fprintf(FilePointerExc, "���������� ���������: \n");
	fprintf(FilePointerExc, "� ������\t������� ����� ��������� (�)\t����� ������� ����� � ������ (�)\n");
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		fprintf(FilePointerExc, "%i\t%lf\t%lf\n", c+1, GopographDataMassive[c].Depth, GopographDataMassive[c].ArrivalTime);
	}
	fclose(FilePointerExc);
	
	// II. ������ Surfer-��������������� ������
	
	// 1. ������ � ���� ���������� � ������� 
	/*	������������� ��� ���������� � ������� ����������� Base map */
	FILE *FilePointerSurf_Form = fopen(SURFER_FORMINFO_FILE_NAME, "w");
	
	// ���������� ����� �����������
	fprintf(FilePointerExc, "2\t1\n");
	fprintf(FilePointerExc, "0\t%lf\n", 0.0);
	fprintf(FilePointerExc, "1\t%lf\n", 0.0);
	
	// ������� ������ ��������� �������
	double DepthCounter = 0.0;
	
	// ���������� ����� 
	for (int c = 0; c < FormationsCount - 1; c++) 
	{
		DepthCounter += FormationsMassive[c].FormationCapacity;
		fprintf(FilePointerExc, "2\t1\n");
		fprintf(FilePointerExc, "0\t%lf\n", DepthCounter);
		fprintf(FilePointerExc, "1\t%lf\n", DepthCounter);
	} 
	
	fclose(FilePointerSurf_Form);
	
	// 2. ������ � ���� ����������� ������
	/*	������������� ��� ���������� � ������� ����������� Grid Data*/
	FILE *FilePointerSurf_Data = fopen(SURFER_DATAINFO_FILE_NAME, "w");
	
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		fprintf(FilePointerExc, "%lf\t%lf\t%lf\n", GopographDataMassive[c].Depth, CoordY, GopographDataMassive[c].ArrivalTime);
	}
	
	fclose(FilePointerSurf_Data);
}

#endif