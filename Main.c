// 	�������: �������� �.�., ������: ���-20
//	��������� ������� ��������� ���

// ������ ����������� ����������� ���������
#include <stdio.h>
#include <locale.h>
#include <conio.h>

// ������ ����������� ������������ ������
#include "Core/Structures.h"
#include "Service/GodographCalculatorFunctions.h"
#include "Service/FileOperatorFunctions.h"
#include "Service/ConsoleDataWriterFunctions.h"

int main()
{
	// ��������� ����������� (rus)
	setlocale(LC_ALL, "Russian_Russia.1251");
	
	// ������������� ����������
	int FormationsCount;
	double WellDepth;
	double StepBySeismicSpit;
	double LastFormationAcousticSpeed;
	
	// ���� ������������� ��������
	printf("\n������� ���������� �������: ");
	scanf("%i", &FormationsCount);
	printf("\n������� ������� �������� (�): ");
	scanf("%lf", &WellDepth);
	printf("\n������� ��� �� ����������������� ���� (�): ");
	scanf("%lf", &StepBySeismicSpit);
	
	// �������� ������ �� ������������
	if (FormationsCount <= 0 || WellDepth <= 0.0 || StepBySeismicSpit <= 0.0) 
	{
		// ����� ��������� �� ������ � ���������� ������ ���������
		printf("������� ������������ ������. ");
		getch();
		return 0;
	}
	
	// �������� ����� ���������� ��������� ��� ������ � 1 �������
	/* � ������ ���� ���������� ������� ����� �������, 
	   �� ���������� ��������� ����������� ���������, 
	   ����� ���� ������������ ����� �� ��������� */
	if (FormationsCount == 1) 
	{
		printf("\n������� �������� ��������������� ������������ ����� ������ (�/�): ");
		scanf("%lf", &LastFormationAcousticSpeed);
		
		// ������������� ������� �������� � ����������� ����������� ���������
		int ExplorationPointsCount = WellDepth / StepBySeismicSpit;
		TGodographData GopographDataMassive[ExplorationPointsCount];
		
		/* 	������ �� ������ �������� ���������� �� �����, 
			��� ��� ������ ������� ��� �������� ������ �� 
			������ ������� �������. */
		CalculateGodographForOne (
									// ��� �� ��������
									StepBySeismicSpit,
									// �������� �� � ������
									LastFormationAcousticSpeed,
									// ���-�� ����� ����������
									ExplorationPointsCount,
									// ������ ������
									GopographDataMassive
								 );
		RecordGodographDataValues (
									// ���-�� ����� ����������
									ExplorationPointsCount,
									// ������ ������
									GopographDataMassive
								  );
		// ����� ������ � ������� �� ������ ������������
		int choise = 0;						  
		printf("\n������� ������ �� �����? ���� ��, ������� 1: ");
		scanf("%i", &choise);
		if (choise == 1) 
		{
			WriteDataValues(
							// ���-�� ����� ����������
							ExplorationPointsCount,
							// ������ � ����������� � ������������ ���������
							GopographDataMassive
						   ); 
		}
		getch();
		return 0;
	}
	
	
	// "��������" ����� ���������� ��������� ��� ������ �� 2 � ����� �������
	
	// ������������� ������� ����������� ��������� TFormation 
	/*	������������ �������� �� ��������� �����, � ��������
		� �������������� ������ ������� ��� ������� ���,
		������ ���������� ����� �������� ��������� ����������
		��� �������� ��������������� �� � ���*/
	TFormation FormationsMassive[FormationsCount-1];
	
	// ���������� ������� FormationsMassive
	for (int Counter = 0; Counter < FormationsCount - 1; Counter++) 
	{
		// ������������� ��������� ���������� (������������ ����� for) ��� ����� ������
		double DFormationCapacity;
		double DFormationAcousticSpeed;
		
		// ���� ��������
		printf("\n����� �%i\n", Counter + 1);
		printf("�������� �������� ������ (�): ");
		scanf("%lf", &DFormationCapacity);
		printf("�������� ��������������� ������������ ����� ��� ������ (�/�): ");
		scanf("%lf", &DFormationAcousticSpeed);
		
		// �������� �������� ������ �� ������������
		if (DFormationCapacity <= 0 || DFormationAcousticSpeed <= 0) 
		{
			printf("������� ������������ ������. ");
			getch();
			return 0;
		}
		
		// ������������ �������� ������� ����������� ��������� TFormation
		FormationsMassive[Counter].FormationCapacity = DFormationCapacity;
		FormationsMassive[Counter].FormationAcousticSpeed = DFormationAcousticSpeed;
	}
	// ���� �������� �������� ��������������� ������������ ����� ��� ���������� ����	
	printf("\n�������� ��������������� ������������ ����� ��� ���������� ������ (�/�): ");
	scanf("%lf", &LastFormationAcousticSpeed);
	
	// ������������� ������� �������� � ����������� ����������� ���������
	int ExplorationPointsCount = WellDepth / StepBySeismicSpit;
	TGodographData GopographDataMassive[ExplorationPointsCount];
	
	// ������ ��������� � ����� ��� � ����
	CalculateGodograph (
							// ��� �� ��������
							StepBySeismicSpit,
							// �������� �� � ��������� (!) ������
							LastFormationAcousticSpeed,
							// ���������� ������� � ������ ���������� ������
							FormationsCount,
							// ������ � ������������ � �������
							/*	���������� � ���������  
								������ �� �������� */
							FormationsMassive,
							// ���-�� ����� ����������
							ExplorationPointsCount,
							// ������ � ����������� � ������������ ���������
							GopographDataMassive
					   );
	RecordGodographDataValues (
								// ���-�� ����� ����������
								ExplorationPointsCount,
								// ������ ������
								GopographDataMassive
							  );
	// ����� ������ � ������� �� ������ ������������
	int choise = 0;						  
	printf("\n������� ������ �� �����? ���� ��, ������� 1: ");
	scanf("%i", &choise);
	if (choise == 1) 
	{
		WriteDataValues(
						// ���-�� ����� ����������
						ExplorationPointsCount,
						// ������ � ����������� � ������������ ���������
						GopographDataMassive
					   ); 
	}
		
	// �������� ����� ����� �������
	getch();
	return 0;
}