#include "PlanEducation.h"

PlanEducation::PlanEducation() : totalHours(0), size(MAX_SIZE), count(0) {}

PlanEducation::PlanEducation(string code, string name, string date, int total)
{
    this->code = code;
    this->name = name;
    this->date = date;
    this->totalHours = total;
    size = MAX_SIZE;
    count = 0;
}

PlanEducation::PlanEducation(const PlanEducation& other) {
    *this = other;
}

void PlanEducation::addDiscipline(const Discipline& d) {
    if (count >= size) return;

    for (int i = 0; i < count; i++)
        if (disciplines[i] == d) return;

    disciplines[count++] = d;
}

void PlanEducation::removeDiscipline(int id) {
    for (int i = 0; i < count; i++) {
        if (disciplines[i].getId() == id) {
            disciplines[i] = disciplines[count - 1];
            count--;
            return;
        }
    }
}

int PlanEducation::getTotalHours() const {
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += disciplines[i].selfStudyHours();
    return sum;
}

// UNION
PlanEducation PlanEducation::operator+(const PlanEducation& other) const {
    PlanEducation result = *this;
    for (int i = 0; i < other.count; i++)
        result.addDiscipline(other.disciplines[i]);
    return result;
}

// DIFFERENCE
PlanEducation PlanEducation::operator-(const PlanEducation& other) const {
    PlanEducation result;
    for (int i = 0; i < count; i++) {
        bool found = false;
        for (int j = 0; j < other.count; j++)
            if (disciplines[i] == other.disciplines[j])
                found = true;

        if (!found)
            result.addDiscipline(disciplines[i]);
    }
    return result;
}

// INTERSECTION
PlanEducation PlanEducation::operator*(const PlanEducation& other) const {
    PlanEducation result;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < other.count; j++) {
            if (disciplines[i] == other.disciplines[j])
                result.addDiscipline(disciplines[i]);
        }
    }
    return result;
}

Discipline& PlanEducation::operator[](int index) {
    return disciplines[index];
}

ostream& operator<<(ostream& out, const PlanEducation& p) {
    for (int i = 0; i < p.count; i++)
        out << p.disciplines[i] << endl;
    return out;
}

Group PlanEducation::makeGroupBySemester(int semester) const {
    Group g;
    g.filterBySemester(disciplines, count, semester);
    return g;
}

Group PlanEducation::makeGroupByType(DisciplineType type) const {
    Group g;
    g.filterByType(disciplines, count, type);
    return g;
}

Group PlanEducation::makeGroupByControl(ControlType control) const {
    Group g;
    g.filterByControl(disciplines, count, control);
    return g;
}