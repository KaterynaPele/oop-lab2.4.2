#pragma once
#include "Discipline.h"
#include "Group.h"

const int MAX_SIZE = 100;

class PlanEducation {
private:
    string code;
    string name;
    string date;
    int totalHours;

    Discipline disciplines[MAX_SIZE];
    int size;
    int count;

public:
    PlanEducation();
    PlanEducation(string code, string name, string date, int total);
    PlanEducation(const PlanEducation& other);

    void addDiscipline(const Discipline& d);
    void removeDiscipline(int id);

    int getTotalHours() const;

    PlanEducation operator+(const PlanEducation& other) const;
    PlanEducation operator-(const PlanEducation& other) const;
    PlanEducation operator*(const PlanEducation& other) const;

    Discipline& operator[](int index);

    Group makeGroupBySemester(int semester) const;
    Group makeGroupByType(DisciplineType type) const;
    Group makeGroupByControl(ControlType control) const;

    friend ostream& operator<<(ostream& out, const PlanEducation& p);
};