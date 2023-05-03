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
	for (int c = 0; c < ExplorationPointsCount; c++) 
	{
		// ������ ��������
		Depth = round((Depth + StepBySeismicSpit) * pow(10, ROUND_BY))/pow(10, ROUND_BY);
		double ArrivalTime = Depth / LastFormationAcousticSpeed;
		
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
	printf("\nCalculateGodograph proc isnt implemented");
}

#endif