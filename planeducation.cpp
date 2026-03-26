#include "planeducation.h"

PlanEducation::PlanEducation() : standardHours(0), count(0) {}
PlanEducation::PlanEducation(string c, string n, string d, int h)
    : code(c), name(n), date(d), standardHours(h), count(0) {}

void PlanEducation::Add(PlanElement p) { arr[count++] = p; }
void PlanEducation::Remove(int idx) { for (int i = idx; i < count - 1; i++) arr[i] = arr[i + 1]; count--; }

void PlanEducation::findBySemester(int s) { for (int i = 0; i < count; i++) if (arr[i].d.getSemester() == s) cout << arr[i].d << endl; }
void PlanEducation::findByType(Type t) { for (int i = 0; i < count; i++) if (arr[i].d.getType() == t) cout << arr[i].d << endl; }
void PlanEducation::findByControl(Control c) { for (int i = 0; i < count; i++) if (arr[i].d.getControl() == c) cout << arr[i].d << endl; }

int PlanEducation::totalHours() { int sum = 0; for (int i = 0; i < count; i++) sum += arr[i].d.getTotal(); return sum; }

void PlanEducation::examsTestsPerSemester(int sem) {
    int ex = 0, t = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i].d.getSemester() == sem) {
            if (arr[i].d.getControl() == EXAM) ex++; else t++;
        }
    }
    cout << "Exams: " << ex << " Tests: " << t << endl;
}

// Множини
PlanEducation operator+(PlanEducation& a, PlanEducation& b) {
    PlanEducation r = a;
    for (int i = 0; i < b.count; i++) {
        bool found = false;
        for (int j = 0; j < a.count; j++) if (b.arr[i] == a.arr[j]) found = true;
        if (!found) r.Add(b.arr[i]);
    }
    return r;
}

PlanEducation operator*(PlanEducation& a, PlanEducation& b) {
    PlanEducation r;
    for (int i = 0; i < a.count; i++)
        for (int j = 0; j < b.count; j++)
            if (a.arr[i] == b.arr[j]) r.Add(a.arr[i]);
    return r;
}

PlanEducation operator-(PlanEducation& a, PlanEducation& b) {
    PlanEducation r;
    for (int i = 0; i < a.count; i++) {
        bool found = false;
        for (int j = 0; j < b.count; j++) if (a.arr[i] == b.arr[j]) found = true;
        if (!found) r.Add(a.arr[i]);
    }
    return r;
}

// Генерація групи
PlanElement* PlanEducation::makeGroupBySemester(int& outCount, int sem) {
    static PlanElement group[MAX]; outCount = 0;
    for (int i = 0; i < count; i++) if (arr[i].d.getSemester() == sem) group[outCount++] = arr[i];
    return group;
}
PlanElement* PlanEducation::makeGroupByType(int& outCount, Type t) {
    static PlanElement group[MAX]; outCount = 0;
    for (int i = 0; i < count; i++) if (arr[i].d.getType() == t) group[outCount++] = arr[i];
    return group;
}
PlanElement* PlanEducation::makeGroupByControl(int& outCount, Control c) {
    static PlanElement group[MAX]; outCount = 0;
    for (int i = 0; i < count; i++) if (arr[i].d.getControl() == c) group[outCount++] = arr[i];
    return group;
}
PlanElement* PlanEducation::makeGroupByCourse(int& outCount, bool cw) {
    static PlanElement group[MAX]; outCount = 0;
    for (int i = 0; i < count; i++) if (arr[i].courseWork == cw) group[outCount++] = arr[i];
    return group;
}

ostream& operator<<(ostream& out, const PlanEducation& p) {
    for (int i = 0; i < p.count; i++) out << p.arr[i].d << endl;
    return out;
}