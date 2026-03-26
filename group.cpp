#include "Group.h"

Group::Group() {
    count = 0;
}

void Group::add(const Discipline& d) {
    list[count++] = d;
}

void Group::filterBySemester(const Discipline arr[], int size, int semester) {
    count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i].getSemester() == semester)
            add(arr[i]);
}

void Group::filterByType(const Discipline arr[], int size, DisciplineType type) {
    count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i].getType() == type)
            add(arr[i]);
}

void Group::filterByControl(const Discipline arr[], int size, ControlType control) {
    count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i].getControl() == control)
            add(arr[i]);
}

void Group::filterByCoursework(const Discipline arr[], int size, bool hasCourse) {
    count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i].hasCourse() == hasCourse)
            add(arr[i]);
}

int Group::totalHours() const {
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += list[i].selfStudyHours();
    return sum;
}

int Group::countExams() const {
    int c = 0;
    for (int i = 0; i < count; i++)
        if (list[i].getControl() == EXAM)
            c++;
    return c;
}

bool Group::isValidSemester() const {
    int exams = countExams();
    return exams >= 3 && exams <= 5;
}

ostream& operator<<(ostream& out, const Group& g) {
    for (int i = 0; i < g.count; i++)
        out << g.list[i] << endl;
    return out;
}