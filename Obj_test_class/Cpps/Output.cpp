//
// Created by Mindaugas K on 2/25/2019.
//
#include "../Headers/Output.h"

bool sorting(const stud &student1, const stud &student2) {
    if (student1.getsurname() != student2.getsurname())
        return (student1.getsurname() < student2.getsurname());
    if (student1.getname() != student2.getname())
        return (student1.getname() < student2.getname());

}
void print(Vector<stud>students, char type) {
    int maxname = 0, maxsurname = 0, maxcount = 0;
    students.shrink_to_fit();
    for (stud& stud : students) {
        if (stud.getname().length() >= maxname)
            maxname = stud.getname().length();
        if (stud.getsurname().length() >= maxsurname)
            maxsurname = stud.getsurname().length();
    }
    if (maxsurname <= 7)
        maxsurname = 7;
    if (maxname <= 6)
        maxname = 6;
    if (type == 'v') {
        maxcount = 0;
        for (stud& stud : students) {
            if (stud.getndsize() >= maxcount)
                maxcount = stud.getndsize();
        }
        for (stud& stud : students)
            stud.setvid(maxcount);

    }
    if (type == 'm') {
        for (stud& stud : students)
            stud.setmvid();
    }
    if (type == 'm') {
        printf("Pavarde%*cVardas%*cGalutinis (Med.)\n", maxsurname - 6, ' ', maxname - 5, ' ');
        printf("%s\n", (string(29 + maxsurname - 7 + maxname - 6, '-')).c_str());
        for (stud& stud : students) {
            printf("%s%*c%s%*c%.2lf\n", stud.getsurname().c_str(), maxsurname - stud.getsurname().length() + 1, ' ', stud.getname().c_str(),
                   maxname - stud.getname().length() + 1, ' ', stud.getmvid());
        }
    }
    if (type == 'v') {
        printf("Pavarde%*cVardas%*cGalutinis (Vid.)\n", maxsurname - 6, ' ', maxname - 5, ' ');
        printf("%s\n", (string(29 + maxsurname - 7 + maxname - 6, '-')).c_str());
        for (stud& stud : students) {
            printf("%s%*c%s%*c%.2lf\n", stud.getsurname().c_str(), maxsurname - stud.getsurname().length() + 1, ' ', stud.getname().c_str(),
                   maxname - stud.getname().length() + 1, ' ', stud.getvid());
        }
    }
}