#include "Discipline.h"

Discipline::Discipline() :
    id(0),
    name(""),
    type(NORMATIVE),
    semester(1),
    control(EXAM),
    totalHours(0),
    lectureHours(0),
    practiceHours(0),
    hasCoursework(false) {}

Discipline::Discipline(int id, string name, DisciplineType type, int semester,
    ControlType control, int total, int lec, int prac, bool course)
{
    this->id = id;
    this->name = name;
    this->type = type;
    this->semester = semester;
    this->control = control;
    this->totalHours = total;
    this->lectureHours = lec;
    this->practiceHours = prac;
    this->hasCoursework = course;
}

Discipline::Discipline(const Discipline& other) {
    *this = other;
}

int Discipline::getId() const { return id; }
string Discipline::getName() const { return name; }
int Discipline::getSemester() const { return semester; }
DisciplineType Discipline::getType() const { return type; }
ControlType Discipline::getControl() const { return control; }

int Discipline::selfStudyHours() const {
    return totalHours - (lectureHours + practiceHours);
}

string Discipline::toString() const {
    return name + " (semester " + to_string(semester) + ")";
}

ostream& operator<<(ostream& out, const Discipline& d) {
    out << d.toString();
    return out;
}

istream& operator>>(istream& in, Discipline& d) {
    in >> d.id >> d.name >> d.semester;
    return in;
}

bool Discipline::operator==(const Discipline& other) const {
    return id == other.id;
}