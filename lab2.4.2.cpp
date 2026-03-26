#include <iostream>
#include "PlanEducation.h"
using namespace std;

int main() {

#pragma pack(push,1)
    cout << "Size packed: " << sizeof(Discipline) << endl;
#pragma pack(pop)

    cout << "Size normal: " << sizeof(Discipline) << endl;

    PlanEducation p1("121", "SE", "2024", 240);

    Discipline d1(1, "OOP", NORMATIVE, 2, EXAM, 120, 40, 20, true);
    Discipline d2(2, "Math", NORMATIVE, 2, EXAM, 100, 30, 20, false);
    Discipline d3(3, "Physics", NORMATIVE, 2, EXAM, 90, 30, 20, false);

    p1.addDiscipline(d1);
    p1.addDiscipline(d2);
    p1.addDiscipline(d3);

    cout << "Plan:\n" << p1;

    Group g = p1.makeGroupBySemester(2);

    cout << "\nGroup:\n" << g;

    cout << "Valid exams count: " << g.isValidSemester() << endl;

    return 0;
}