#pragma once
#include "Discipline.h"

class Group {
    Discipline* arr;
    int count;

public:
    Group();
    ~Group();

    void Add(Discipline);
    void Print();

    int totalHours();
    int examCount(int semester);
};