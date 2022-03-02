#include <iostream>
#include "MonsterList.h"
#include "GradeManager.h"
#include "BaseBall.h"
int main()
{
	//Monster_Data wolf{ Wolf, "황혼늑대", 10 };
	//Monster_Data demon{ Demon, "써큐버스", 100 };
	//Monster_Data slime{ Slime, "버블링", 500 };


	//Print_Monster(wolf);
	//Print_Monster(demon);
	//Print_Monster(slime);

	//Student_Data KIM{ 1, "KIM", 100 };
	//Student_Data LEE{ 2, "LEE", 90 };
	//Student_Data PARK{ 3, "PARK", 70 };
	//Student_Data CHOI{ 4, "CHOI", 95 };
	//Student_Data KANG{ 5, "KANG", 80 };

	//Student_Data student[5]{ KIM, LEE, PARK,CHOI,KANG };
	//for (int i = 0; i < 5; ++i)
	//{
	//	std::cout << student[i].grade << std::endl;
	//}

	//GradeManager(student);

	int Answer;
	Answer = GetRandom();
	std::cout << Answer << std::endl;
	Input(Answer);
}
