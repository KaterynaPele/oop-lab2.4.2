#include "discipline.h"
#include <sstream>

Discipline::Discipline() : id(0), semester(1), totalHours(0), lec(0), prac(0), type(NORM), control(EXAM) {}
Discipline::Discipline(int i, Type t, string n, int s, Control c, int th, int l, int p)
    : id(i), type(t), name(n), semester(s), control(c), totalHours(th), lec(l), prac(p) {}
Discipline::Discipline(const Discipline& d) { *this = d; }

int Discipline::getSemester() const { return semester; }
Type Discipline::getType() const { return type; }
Control Discipline::getControl() const { return control; }
string Discipline::getName() const { return name; }
int Discipline::getTotal() const { return totalHours; }
int Discipline::getAuditory() const { return lec + prac; }
int Discipline::getSelf() const { return totalHours - (lec + prac); }

void Discipline::setSemester(int s) { if (s > 0) semester = s; }
void Discipline::setName(string n) { if (!n.empty()) name = n; }

bool Discipline::operator==(const Discipline& d) const { return name == d.name && semester == d.semester; }
Discipline& Discipline::operator=(const Discipline& d) {
    id = d.id; type = d.type; name = d.name; semester = d.semester;
    control = d.control; totalHours = d.totalHours; lec = d.lec; prac = d.prac;
    return *this;
}

Discipline::operator string() const {
    stringstream ss;
    ss << name << " | sem: " << semester << " | hours: " << totalHours;
    return ss.str();
}

ostream& operator<<(ostream& out, const Discipline& d) {
    out << string(d); return out;
}

istream& operator>>(istream& in, Discipline& d) {
    cout << "Name: "; in >> d.name;
    cout << "Semester: "; in >> d.semester;
    cout << "Total hours: "; in >> d.totalHours;
    cout << "Lectures: "; in >> d.lec;
    cout << "Practice: "; in >> d.prac;
    int t, c;
    cout << "Type (0=NORM,1=UNI_SELECT,2=FREE_SELECT): "; in >> t;
    d.type = static_cast<Type>(t);
    cout << "Control (0=EXAM,1=TEST): "; in >> c;
    d.control = static_cast<Control>(c);
    return in;
}