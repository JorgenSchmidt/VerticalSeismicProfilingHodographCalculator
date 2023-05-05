/*	��� ����������� ������� � �����������: 
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
*/

//	������� ��������� ������ ����������� ��������� ��������: 
/*	typedef struct 
	{
		double Depth; 	double ArrivalTime;
	} TGodographData; */
/*	typedef struct 
	{
		// �������� ������
		double FormationCapacity;
		// �������� �������� ��������������� �� ��� ������
		double FormationAcousticSpeed;
	} TFormation; */

// ����������� ����������� ���������
#include <stdio.h>
#include <locale.h>
#include <conio.h>

// ����������� ������������ ������ � �������� ���������� � �����������
#include "../Core/Structures.h"

// ����������� ������������� ����� ����������� �������
#include "../Service/GodographCalculatorFunctions.h"

// ��������� ������ ������� ����� ���������� ������������������ � ��������� ��������
	/*	���� ����� ������� �������, ���� ������ � ��������� 
		�� ��������� 0,00001 �� ������ */
	
	/*	��� �������� ����� ����������� ������ ������ 5 � 
	��������� 5 ����������� ������.
	������ ������ ������ �� ��������� � ��������
	������������ ����� ���������, ��� ��� � ������
	������ ����������� ��������� �������, ������
	���������� ������ ������ �� �������� �����������
	� Excel ���� � ������� */
void CheckDataByDifference 	(
								int ExplorationPointsCount,
								TGodographData *TestDataMassive,
								TGodographData *GopographDataMassive
							) 
{
	if (ExplorationPointsCount <= 9) 
	{
		printf(". � ������ ����� ��������� ������ 10 ��������. \n");
		getch();
		return;
	}
	int ErrorCounter = 0;
	printf("\n������� � ���������: ");
	for (int c = 0; c < 5; c++) 
	{
		double DifferenceDepth = 
				TestDataMassive[c].Depth 
				- GopographDataMassive[c].Depth ;
		double DifferenceArrival = 
				TestDataMassive[c].ArrivalTime 
				- GopographDataMassive[c].ArrivalTime;
		printf("\n%i. ������� ����� ����������:", c+1);
		printf(
				"\n �: %lf, �: %lf, �: %lf", 
				TestDataMassive[c].Depth,
				GopographDataMassive[c].Depth,
				DifferenceDepth
			  );
		printf("\n����� �������: ");
		printf(
				"\n �: %lf, �: %lf, �: %lf\n", 
				TestDataMassive[c].ArrivalTime,
				GopographDataMassive[c].ArrivalTime,
				DifferenceArrival
			  );
		if (DifferenceDepth != 0 || DifferenceArrival != 0) 
		{
			ErrorCounter += 1;
		}
	}
	for (int c = ExplorationPointsCount - 5; c < ExplorationPointsCount; c++) 
	{
		double DifferenceDepth = 
				TestDataMassive[c].Depth 
				- GopographDataMassive[c].Depth ;
		double DifferenceArrival = 
				TestDataMassive[c].ArrivalTime 
				- GopographDataMassive[c].ArrivalTime;
		printf("\n%i. ������� ����� ����������:", c+1);
		printf(
				"\n �: %lf, �: %lf, �: %lf", 
				TestDataMassive[c].Depth,
				GopographDataMassive[c].Depth,
				DifferenceDepth
			  );
		printf("\n����� �������: ");
		printf(
				"\n �: %lf, �: %lf, �: %lf\n", 
				TestDataMassive[c].ArrivalTime,
				GopographDataMassive[c].ArrivalTime,
				DifferenceArrival
			  );
		if (DifferenceDepth != 0 || DifferenceArrival != 0) 
		{
			ErrorCounter += 1;
		}
	}
	printf("\n������������� ������: %i\n", ErrorCounter);
}

// �������� ������������������ � ������������ �������� �� ���������� �������� �� �������
int CheckMassiveSizes (int TestPointsCount, int ExplorationPointsCount) 
{
	int Answer = 0;
	if (ExplorationPointsCount != TestPointsCount) 
	{
		printf("\n�� ��������� ������� ��������� � ������������������ ��������");
		printf("\n�������� - %i ��, ����������� - %i ��.", TestPointsCount, ExplorationPointsCount);
		Answer = 1;
	}
	return Answer;
}

// ��������� �������� ������
void test_1();
void test_2();
void test_3();
void test_4();
void test_5();

// �������� �����
int main() 
{
	setlocale(LC_ALL, "Russian_Russia.1251");
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	getch();
	return 0;
}

// ��������� ������ (��. ��������������� Excel ����)
void test_1() // ������� CalculateGodographForOne
{
	printf("\n���� �1");
	// �������� ������
	int TestPointsCount = 10;
	TGodographData TestDataMassive[TestPointsCount];
	TestDataMassive[0].Depth = 5;
	TestDataMassive[1].Depth = 10;
	TestDataMassive[2].Depth = 15;
	TestDataMassive[3].Depth = 20;
	TestDataMassive[4].Depth = 25;
	TestDataMassive[5].Depth = 30;
	TestDataMassive[6].Depth = 35;
	TestDataMassive[7].Depth = 40;
	TestDataMassive[8].Depth = 45;
	TestDataMassive[9].Depth = 50;
	TestDataMassive[0].ArrivalTime = 0.01;
	TestDataMassive[1].ArrivalTime = 0.02;
	TestDataMassive[2].ArrivalTime = 0.03;
	TestDataMassive[3].ArrivalTime = 0.04;
	TestDataMassive[4].ArrivalTime = 0.05;
	TestDataMassive[5].ArrivalTime = 0.06;
	TestDataMassive[6].ArrivalTime = 0.07;
	TestDataMassive[7].ArrivalTime = 0.08;
	TestDataMassive[8].ArrivalTime = 0.09;
	TestDataMassive[9].ArrivalTime = 0.1;
	
	// ������� ������ 
	double WellDepth = 50;
	double StepBySeismicSpit = 5;
	double LastFormationAcousticSpeed = 500;
	
	int ExplorationPointsCount = WellDepth/StepBySeismicSpit;
	TGodographData GopographDataMassive[ExplorationPointsCount];
	
	// ��������� �������������� �������
	if (CheckMassiveSizes(TestPointsCount, ExplorationPointsCount)) 
	{
		return;
	}
	
	// ����� ����������� �������
	CalculateGodographForOne(
								StepBySeismicSpit, 
								LastFormationAcousticSpeed, 
								ExplorationPointsCount, 
								GopographDataMassive
							);
	
	// ����� ������� ����� ���������� ������������������ � ��������� ��������
	CheckDataByDifference(ExplorationPointsCount, TestDataMassive, GopographDataMassive);
}

void test_2() // ������� CalculateGodographForOne
{
	printf("\n���� �2");
	// �������� ������
	int TestPointsCount = 28;
	TGodographData TestDataMassive[TestPointsCount];
	TestDataMassive[0].Depth = 7;
	TestDataMassive[1].Depth = 14;
	TestDataMassive[2].Depth = 21;
	TestDataMassive[3].Depth = 28;
	TestDataMassive[4].Depth = 35;
	TestDataMassive[23].Depth = 168;
	TestDataMassive[24].Depth = 175;
	TestDataMassive[25].Depth = 182;
	TestDataMassive[26].Depth = 189;
	TestDataMassive[27].Depth = 196;
	TestDataMassive[0].ArrivalTime = 0.011666667;
	TestDataMassive[1].ArrivalTime = 0.023333333;
	TestDataMassive[2].ArrivalTime = 0.035;
	TestDataMassive[3].ArrivalTime = 0.046666667;
	TestDataMassive[4].ArrivalTime = 0.058333333;
	TestDataMassive[23].ArrivalTime = 0.28;
	TestDataMassive[24].ArrivalTime = 0.291666667;
	TestDataMassive[25].ArrivalTime = 0.303333333;
	TestDataMassive[26].ArrivalTime = 0.315;
	TestDataMassive[27].ArrivalTime = 0.326666667;
	
	// ������� ������ 
	double WellDepth = 200;
	double StepBySeismicSpit = 7;
	double LastFormationAcousticSpeed = 600;
	
	int ExplorationPointsCount = WellDepth/StepBySeismicSpit;
	TGodographData GopographDataMassive[ExplorationPointsCount];
	
	// ��������� �������������� �������
	if (CheckMassiveSizes(TestPointsCount, ExplorationPointsCount)) 
	{
		return;
	}
	
	// ����� ����������� �������
	CalculateGodographForOne(
								StepBySeismicSpit, 
								LastFormationAcousticSpeed, 
								ExplorationPointsCount, 
								GopographDataMassive
							);
	
	// ����� ������� ����� ���������� ������������������ � ��������� ��������
	CheckDataByDifference(ExplorationPointsCount, TestDataMassive, GopographDataMassive);
}

/*	������ ���� ��� ����� ���������� ��� ������������ ���������
	�� ����������� ��������� ����������� ������� ��������� �����
	����������, ��� ����� ����, � ������� ����� �������� ����������
	�����, ������� ��� ��������� �� ����������� � �������� �����, ���
	�������� 0.9 (��� �������� 0.9 � �� ���������� ����� ������ � 
	�������� ���������� ����������� ����� � ������� 0.11100(1100))*/
void test_3() // ������� CalculateGodographForOne
{
	printf("\n���� �3");
	// �������� ������
	int TestPointsCount = 25;
	TGodographData TestDataMassive[TestPointsCount];
	TestDataMassive[0].Depth = 3.9;
	TestDataMassive[1].Depth = 7.8;
	TestDataMassive[2].Depth = 11.7;
	TestDataMassive[3].Depth = 15.6;
	TestDataMassive[4].Depth = 19.5;
	TestDataMassive[20].Depth = 81.9;
	TestDataMassive[21].Depth = 85.8;
	TestDataMassive[22].Depth = 89.7;
	TestDataMassive[23].Depth = 93.6;
	TestDataMassive[24].Depth = 97.5;
	TestDataMassive[0].ArrivalTime = 0.007090909;
	TestDataMassive[1].ArrivalTime = 0.014181818;
	TestDataMassive[2].ArrivalTime = 0.021272727;
	TestDataMassive[3].ArrivalTime = 0.028363636;
	TestDataMassive[4].ArrivalTime = 0.035454545;
	TestDataMassive[20].ArrivalTime = 0.148909091;
	TestDataMassive[21].ArrivalTime = 0.156;
	TestDataMassive[22].ArrivalTime = 0.163090909;
	TestDataMassive[23].ArrivalTime = 0.170181818;
	TestDataMassive[24].ArrivalTime = 0.177272727;
	
	// ������� ������ 
	double WellDepth = 100;
	double StepBySeismicSpit = 3.9;
	double LastFormationAcousticSpeed = 550;
	int ExplorationPointsCount = WellDepth/StepBySeismicSpit;
	TGodographData GopographDataMassive[ExplorationPointsCount];
	
	// ��������� �������������� �������
	if (CheckMassiveSizes(TestPointsCount, ExplorationPointsCount)) 
	{
		return;
	}
	
	// ����� ����������� �������
	CalculateGodographForOne(
								StepBySeismicSpit, 
								LastFormationAcousticSpeed, 
								ExplorationPointsCount, 
								GopographDataMassive
							);
	
	// ����� ������� ����� ���������� ������������������ � ��������� ��������
	CheckDataByDifference(ExplorationPointsCount, TestDataMassive, GopographDataMassive);
}

void test_4 () // ������� CalculateGodograph
{
	printf("\n���� �4");
	// �������� ������
	int TestPointsCount = 30;
	TGodographData TestDataMassive[TestPointsCount];
	TestDataMassive[0].Depth = 4.9;
	TestDataMassive[1].Depth = 9.8;
	TestDataMassive[2].Depth = 14.7;
	TestDataMassive[3].Depth = 19.6;
	TestDataMassive[4].Depth = 24.5;
	TestDataMassive[25].Depth = 127.4;
	TestDataMassive[26].Depth = 132.3;
	TestDataMassive[27].Depth = 137.2;
	TestDataMassive[28].Depth = 142.1;
	TestDataMassive[29].Depth = 147;
	TestDataMassive[0].ArrivalTime = 0.006533333;
	TestDataMassive[1].ArrivalTime = 0.013066667;
	TestDataMassive[2].ArrivalTime = 0.0196;
	TestDataMassive[3].ArrivalTime = 0.026133333;
	TestDataMassive[4].ArrivalTime = 0.032666667;
	TestDataMassive[25].ArrivalTime = 0.156166667;
	TestDataMassive[26].ArrivalTime = 0.16025;
	TestDataMassive[27].ArrivalTime = 0.164333333;
	TestDataMassive[28].ArrivalTime = 0.168416667;
	TestDataMassive[29].ArrivalTime = 0.1725;
	
	// ��������� ������� ����������
	double WellDepth = 150;
	double StepBySeismicSpit = 4.9;
	
	// ��������� ������������ �����
	int FormationsCount = 2;
	TFormation FormationsMassive[FormationsCount-1];
	FormationsMassive[0].FormationCapacity = 100;
	FormationsMassive[0].FormationAcousticSpeed = 750;
	double LastFormationAcousticSpeed = 1200;
	
	// ������������� � ������ �������� ������� ������� ��
	int ExplorationPointsCount = WellDepth/StepBySeismicSpit;
	TGodographData GopographDataMassive[ExplorationPointsCount];
	
	// ��������� �������������� �������
	if (CheckMassiveSizes(TestPointsCount, ExplorationPointsCount)) 
	{
		return;
	}
	
	// ����� ����������� �������
	CalculateGodograph	(
							StepBySeismicSpit, 
							LastFormationAcousticSpeed,
							FormationsCount,
							FormationsMassive,
							ExplorationPointsCount,
							GopographDataMassive
						);
	
	// ����� ������� ����� ���������� ������������������ � ��������� ��������
	CheckDataByDifference(ExplorationPointsCount, TestDataMassive, GopographDataMassive);
}

void test_5() // ������� CalculateGodograph
{
	printf("\n���� �5");
	// �������� ������
	int TestPointsCount = 70;
	TGodographData TestDataMassive[TestPointsCount];
	TestDataMassive[0].Depth = 9.9;
	TestDataMassive[1].Depth = 19.8;
	TestDataMassive[2].Depth = 29.7;
	TestDataMassive[3].Depth = 39.6;
	TestDataMassive[4].Depth = 49.5;
	TestDataMassive[65].Depth = 653.4;
	TestDataMassive[66].Depth = 663.3;
	TestDataMassive[67].Depth = 673.4;
	TestDataMassive[68].Depth = 683.1;
	TestDataMassive[69].Depth = 693;
	TestDataMassive[0].ArrivalTime = 0.0099;
	TestDataMassive[1].ArrivalTime = 0.0198;
	TestDataMassive[2].ArrivalTime = 0.0297;
	TestDataMassive[3].ArrivalTime = 0.0396;
	TestDataMassive[4].ArrivalTime = 0.0495;
	TestDataMassive[65].ArrivalTime = 0.772714286;
	TestDataMassive[66].ArrivalTime = 0.786857143;
	TestDataMassive[67].ArrivalTime = 0.801;
	TestDataMassive[68].ArrivalTime = 0.815142857;
	TestDataMassive[69].ArrivalTime = 0.829285714;
	
	// ��������� ������� ����������
	double WellDepth = 700;
	double StepBySeismicSpit = 9.9;
	
	// ��������� ������������ �����
	int FormationsCount = 4;
	TFormation FormationsMassive[FormationsCount-1];
	FormationsMassive[0].FormationCapacity = 100;
	FormationsMassive[0].FormationAcousticSpeed = 1000;
	FormationsMassive[1].FormationCapacity = 200;
	FormationsMassive[1].FormationAcousticSpeed = 500;
	FormationsMassive[2].FormationCapacity = 250;
	FormationsMassive[2].FormationAcousticSpeed = 2000;
	double LastFormationAcousticSpeed = 700;
	
	// ������������� � ������ �������� ������� ������� ��
	int ExplorationPointsCount = WellDepth/StepBySeismicSpit;
	TGodographData GopographDataMassive[ExplorationPointsCount];
	
	// ��������� �������������� �������
	if (CheckMassiveSizes(TestPointsCount, ExplorationPointsCount)) 
	{
		return;
	}
	
	// ����� ����������� �������
	CalculateGodograph	(
							StepBySeismicSpit, 
							LastFormationAcousticSpeed,
							FormationsCount,
							FormationsMassive,
							ExplorationPointsCount,
							GopographDataMassive
						);
	
	// ����� ������� ����� ���������� ������������������ � ��������� ��������
	CheckDataByDifference(ExplorationPointsCount, TestDataMassive, GopographDataMassive);
}