#pragma once
#include "Discipline.h"
#include "PlanEducation.h"

class Group {
private:
    Discipline list[MAX_SIZE];
    int count;

public:
    Group();

    void add(const Discipline& d);

    void filterBySemester(const Discipline arr[], int size, int semester);
    void filterByType(const Discipline arr[], int size, DisciplineType type);
    void filterByControl(const Discipline arr[], int size, ControlType control);
    void filterByCoursework(const Discipline arr[], int size, bool hasCourse);

    int totalHours() const;
    int countExams() const;

    bool isValidSemester() const;

    friend ostream& operator<<(ostream& out, const Group& g);
};