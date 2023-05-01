#ifndef GodographCalculatorFunctions
#define GodographCalculatorFunctions

#include "../Core/Structures.h"

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
	printf("\nCalculateGodographForOne proc isnt implemented");
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