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
	printf("\n������� �������� ������� �������� (�): ");
	scanf("%lf", &WellDepth);
	printf("\n������� ��� �� ����������������� ���� (�): ");
	scanf("%lf", &StepBySeismicSpit);
	
	// �������� ������ �� ��������� �������� �� ������������
	if 	(
				FormationsCount <= 0 
			|| 	WellDepth <= 0.0 
			|| 	StepBySeismicSpit <= 0.0 
			|| 	WellDepth <= StepBySeismicSpit + 5
		) 
	{
		// ����� ��������� �� ������ � ���������� ������ ���������
		printf("������� ������������ ������. ");
		printf("\n������� ����� ���������� �� ����� ����������� ��������� �����: ");
		printf("\n1. ��� �������� �������� ������ ���� ������ ������ ����.");
		printf("\n2. �������� ������� �������� ������ ��������� �������� ���� �� ");
		printf("������� �� 5 � �����. �������� ��� ������� �������� � 30, ");
		printf("�������� ���� �� ������� � 25 � ������ ����� �����������. ");
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
		
		// ���� ���������� Y (��� Surfer)
		double Coord_Y;
		printf("\n������� ���������� Y (��� Surfer): ");
		scanf("%lf", &Coord_Y);
		
		// ������������� ��������������� ������� ����������� �������� TFormation
		/*	� ����� ��������������� ��������� ������ ���� ���������� ���������
			������ ������� ���� */
		TFormation FormationsMassive[1];
		FormationsMassive[0].FormationCapacity = 0;
		FormationsMassive[0].FormationAcousticSpeed = 0;
		
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
									// �������� �� � ��������� (!) ������
									LastFormationAcousticSpeed,
									// ���������� ������� � ������ ���������� ������
									FormationsCount,
									// ������ � ������������ � �������
									FormationsMassive,
									// ���-�� ����� ����������
									ExplorationPointsCount,
									// ������ ������
									GopographDataMassive,
									// ���������� Y (��� Surfer)
									Coord_Y
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
		��� �������� ��������������� �� � ��*/
	double DepthCounter = 0.0;
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
		if 	(
					DFormationCapacity <= 0 
				|| DFormationAcousticSpeed <= 0 
				|| DFormationCapacity <= StepBySeismicSpit + 1
			) 
		{
			printf("\n������� ������������ ������. ");
			printf("\n������� ����� ���������� �� ����� ����������� ���������� �����: ");
			printf("\n1. �������� �������� ������ � ��������������� �� ������ ���� ������ ������ 0;");
			printf("\n2. �������� �������� ������ ������ ��������� �������� ����");
			printf(" �� ����������������� ���� �� ������� ���� �� 1�.");
			printf(" �������� ��� ���� �� ���� � 25� ����� ������������ �������� 26 � ������.");
			getch();
			return 0;
		}
		
		// ��� ���������� ������� ��������� ������� �������������� ������
		DepthCounter += DFormationCapacity;
		
		// ������������ �������� ������� ����������� ��������� TFormation
		FormationsMassive[Counter].FormationCapacity = DFormationCapacity;
		FormationsMassive[Counter].FormationAcousticSpeed = DFormationAcousticSpeed;
	}
	// ���� �������� �������� ��������������� ������������ ����� ��� ���������� ����	
	printf("\n�������� ��������������� ������������ ����� ��� ���������� ������ (�/�): ");
	scanf("%lf", &LastFormationAcousticSpeed);
	
	// �������� �� ����������� ��������� ���������� ������
	/*	���� ������� �������� �� ��������� �������� ������� ��������� 
		������� �������������� ������, ��������� �����������*/
	if (WellDepth <= DepthCounter) 
	{
		printf("�������� �� ���������� ��������� �����. ");
		getch();
		return 0;
	}
	
	// ���� ���������� Y (��� Surfer)
	double Coord_Y;
	printf("\n������� ���������� Y (��� Surfer): ");
	scanf("%lf", &Coord_Y);
	
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
									// �������� �� � ��������� (!) ������
									LastFormationAcousticSpeed,
									// ���������� ������� � ������ ���������� ������
									FormationsCount,
									// ������ � ������������ � �������
									FormationsMassive,
									// ���-�� ����� ����������
									ExplorationPointsCount,
									// ������ ������
									GopographDataMassive,
									// ���������� Y (��� Surfer)
									Coord_Y
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