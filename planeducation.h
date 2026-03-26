#pragma once
#include "discipline.h"
#include <iostream>
using namespace std;

struct PlanElement {
    Discipline d;
    bool courseWork;
    int selfHours;
    PlanElement() : courseWork(false), selfHours(0) {}
    PlanElement(Discipline dd, bool cw) : d(dd), courseWork(cw), selfHours(dd.getSelf()) {}
    bool operator==(const PlanElement& p) { return d == p.d; }
};

#define MAX 100

class PlanEducation {
    string code, name, date;
    int standardHours;
    PlanElement arr[MAX];
    int count;

public:
    PlanEducation();
    PlanEducation(string, string, string, int);

    void Add(PlanElement);
    void Remove(int);

    void findBySemester(int);
    void findByType(Type);
    void findByControl(Control);

    int totalHours();
    void examsTestsPerSemester(int sem);

    // Множини
    friend PlanEducation operator+(PlanEducation&, PlanEducation&);
    friend PlanEducation operator-(PlanEducation&, PlanEducation&);
    friend PlanEducation operator*(PlanEducation&, PlanEducation&);

    // Генерація групи
    PlanElement* makeGroupBySemester(int&, int);
    PlanElement* makeGroupByType(int&, Type);
    PlanElement* makeGroupByControl(int&, Control);
    PlanElement* makeGroupByCourse(int&, bool);

    friend ostream& operator<<(ostream&, const PlanEducation&);
};