#include "planeducation.h"
#include <iostream>
using namespace std;

int main() {
    PlanEducation plan("121", "Software", "2026", 240);

    Discipline d1(1, NORM, "Math", 1, EXAM, 100, 30, 20);
    Discipline d2(2, UNI_SELECT, "OOP", 2, TEST, 120, 40, 30);
    Discipline d3(3, FREE_SELECT, "AI", 2, EXAM, 80, 30, 20);

    plan.Add(PlanElement(d1, true));
    plan.Add(PlanElement(d2, false));
    plan.Add(PlanElement(d3, false));

    cout << "Full plan:\n" << plan << endl;

    cout << "Semester 2:\n";
    plan.findBySemester(2);

    int gCount;
    PlanElement* group = plan.makeGroupByControl(gCount, EXAM);
    cout << "Group with exams:\n";
    for (int i = 0; i < gCount; i++) cout << group[i].d << endl;

    PlanEducation plan2("122", "AI", "2026", 180);
    plan2.Add(PlanElement(d2, false));
    plan2.Add(PlanElement(d3, true));

    PlanEducation u = plan + plan2;
    cout << "\nUnion:\n" << u;

    PlanEducation inter = plan * plan2;
    cout << "\nIntersection:\n" << inter;

    PlanEducation diff = plan - plan2;
    cout << "\nDifference:\n" << diff;

    return 0;
}