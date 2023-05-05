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
								TGodographData *GopographDataMassive
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
		GopographDataMassive[c].Depth = Depth;
		GopographDataMassive[c].ArrivalTime = ArrivalTime;
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
							TGodographData *GopographDataMassive
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
			// ������ �� ��� 2 � ����� �������
			ArrivalTime = 0;
			/* 	��������� ������� curFormation - current formation - ������� ����� */
			for (int curFormation = 0; curFormation < FormationCounter; curFormation++) 
			{
				ArrivalTime += FormationsMassive[curFormation].FormationCapacity / FormationsMassive[curFormation].FormationAcousticSpeed;
			}
			
			//
			if (FormationCounter < FormationsCount - 1) 
			{
				ArrivalTime += 	(Depth - (CurrentFormationDepth - FormationsMassive[FormationCounter].FormationCapacity))
								/ 
								FormationsMassive[FormationCounter].FormationAcousticSpeed;
				}
			else 
			{
				ArrivalTime += 	(Depth - CurrentFormationDepth)
								/ 
								LastFormationAcousticSpeed;
			}
		}
		else 
		{
			ArrivalTime = Depth / FormationsMassive[0].FormationAcousticSpeed;
		}
		GopographDataMassive[c].Depth = Depth;
		GopographDataMassive[c].ArrivalTime = ArrivalTime;
	}
}

#endif