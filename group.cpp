#include "Group.h"
#include <iostream>
using namespace std;

Group::Group() {
    arr = new Discipline[100];
    count = 0;
}

Group::~Group() { delete[] arr; }

void Group::Add(Discipline d) {
    arr[count++] = d;
}

void Group::Print() {
    for (int i = 0; i < count; i++)
        cout << arr[i] << endl;
}

int Group::totalHours() {
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += arr[i].getTotal();
    return sum;
}

int Group::examCount(int sem) {
    int c = 0;
    for (int i = 0; i < count; i++)
        if (arr[i].getSemester() == sem && arr[i].getControl() == EXAM)
            c++;
    return c;
}