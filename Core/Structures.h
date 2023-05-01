#ifndef Structures
#define Structures

// Описание структуры данных для отдельного пласта
typedef struct 
{
	// Мощность пласта
	double FormationCapacity;
	// Значение скорости распространения АВ для пласта
	double FormationAcousticSpeed;
} TFormation;

// Описание структуры данных для значений времени прихода АВ
typedef struct 
{
	// Глубина сейсмодатчика
	double Depth;
	// Значение времени прихода АВ к сейсмодатчику
	double ArrivalTime;
} TGodographData;

#endif