#pragma once
#include <iostream>
#include <string>
using namespace std;

enum DisciplineType {
    NORMATIVE,
    UNIVERSITY_CHOICE,
    STUDENT_CHOICE
};

enum ControlType {
    EXAM,
    CREDIT
};

class Discipline {
private:
    int id;
    string name;
    DisciplineType type;
    int semester;
    ControlType control;
    int totalHours;
    int lectureHours;
    int practiceHours;
    bool hasCoursework;

public:
    Discipline();
    Discipline(int id, string name, DisciplineType type, int semester,
        ControlType control, int total, int lec, int prac, bool course);
    Discipline(const Discipline& other);

    // getters/setters
    int getId() const;
    string getName() const;
    int getSemester() const;
    DisciplineType getType() const;
    ControlType getControl() const;
    bool hasCourse() const { return hasCoursework; }

    int selfStudyHours() const;

    string toString() const;

    friend ostream& operator<<(ostream& out, const Discipline& d);
    friend istream& operator>>(istream& in, Discipline& d);

    bool operator==(const Discipline& other) const;
};