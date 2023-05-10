#ifndef GodographCalculatorFunctions
#define GodographCalculatorFunctions

#include <math.h> 

#include "../Core/Structures.h"
#include "../Core/AppConfiguration.h"

// ��������� ������� �������� ��������� ��� ���������� ������
void CalculateGodographForOne (
								// ��� �� ��������
								double StepBySeismicSpit, 
								// �������� �� � ������
								double LastFormationAcousticSpeed,
								// ���-�� ����� ����������
								int ExplorationPointsCount,
								// ������ ������
								TGodographData *GodographDataMassive
							  ) 
{
	double Depth = 0.0;
	double ArrivalTime = 0.0;
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		// ������ ��������
		Depth = round((Depth + StepBySeismicSpit) * pow(10, ROUND_BY))/pow(10, ROUND_BY);
		ArrivalTime = Depth / LastFormationAcousticSpeed;
		
		// ������������ ������������ �������� ��������� ������� ����������� ��������� TGodographData
		GodographDataMassive[c].Depth = Depth;
		GodographDataMassive[c].ArrivalTime = ArrivalTime;
	}
}

// ��������� ������� �������� ��������� ��� 2 � ������ �������
void CalculateGodograph (
							// ��� �� ��������
							double StepBySeismicSpit, 
							// �������� �� � ��������� (!) ������
							double LastFormationAcousticSpeed,
							// ���������� ������� � ������ ���������� ������
							int FormationsCount,
							// ������ � ������������ � �������
							TFormation *FormationsMassive,
							// ���-�� ����� ����������
							int ExplorationPointsCount,
							// ������ � ����������� � ������������ ���������
							TGodographData *GodographDataMassive
						) 
{
	// ������������� ����������
	int FormationCounter = 0;
	double Depth = 0.0;
	double DepthFormationCounter = 0.0;
	double ArrivalTime = 0.0;
	double CurrentFormationDepth = FormationsMassive[0].FormationCapacity;
	
	// ������ ��������
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		/* 	������ ������� ��������� ������� � �������� �� ����������� 
			�������� ������ (������������ ���������� FormationCounter) 
			��������������� ������ ���������� */
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
		
		// ������ ������� ������� �� � ������� ����� ����������
		if (FormationCounter != 0) 
		{
			// ������ �� � ������� ��������� ������������� ��� ������� � ����� �� ����� �������
			ArrivalTime = 0;
			/* 	��������� ������� curFormation - current formation - ������� ����� */
			for (int curFormation = 0; curFormation < FormationCounter; curFormation++) 
			{
				ArrivalTime += FormationsMassive[curFormation].FormationCapacity / FormationsMassive[curFormation].FormationAcousticSpeed;
			}
			
			// ��������� ��� ����������� ��������� ������� �������� ������� ������� ��
			/*	��� ���������� ������, ����� ��� ��������� ������������, 
				�������� ������� �� ��������� �� �������*/
			if (FormationCounter < FormationsCount - 1) 
			{
				// ������ ������� ������� ��� ������� �� 2 �� ����������
				ArrivalTime += 	(Depth - (CurrentFormationDepth - FormationsMassive[FormationCounter].FormationCapacity))
								/ 
								FormationsMassive[FormationCounter].FormationAcousticSpeed;
				}
			else 
			{
				// ������ ������� ������� ��� ���������� ������
				ArrivalTime += 	(Depth - CurrentFormationDepth)
								/ 
								LastFormationAcousticSpeed;
			}
		}
		else 
		{
			// ������ �� � ������� ��������� ������������� ��� ������� ������
			ArrivalTime = Depth / FormationsMassive[0].FormationAcousticSpeed;
		}
		// ���������� �������� ���������� ������� ��������� TGodographData ����������� ��������
		GodographDataMassive[c].Depth = Depth;
		GodographDataMassive[c].ArrivalTime = ArrivalTime;
	}
}

#endif