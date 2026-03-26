#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Type { NORM, UNI_SELECT, FREE_SELECT };
enum Control { EXAM, TEST };

class Discipline {
    int id;
    Type type;
    string name;
    int semester;
    Control control;
    int totalHours;
    int lec, prac;

public:
    Discipline();
    Discipline(int, Type, string, int, Control, int, int, int);
    Discipline(const Discipline&);

    // getters
    int getSemester() const;
    Type getType() const;
    Control getControl() const;
    string getName() const;
    int getTotal() const;
    int getAuditory() const;
    int getSelf() const;

    // setters
    void setSemester(int);
    void setName(string);

    // operators
    bool operator==(const Discipline&) const;
    Discipline& operator=(const Discipline&);

    operator string() const;
    friend ostream& operator<<(ostream&, const Discipline&);
    friend istream& operator>>(istream&, Discipline&);
};