//
// Created by Mindaugas K on 2/25/2019.
//
#include "Mutual.h"
#include "Output.h"
bool sorting(const stud student1, const stud student2) {
    if (student1.surname != student2.surname)
        return (student1.surname < student2.surname);
    if (student1.name != student2.name)
        return (student1.name < student2.name);

}
void print(Vector<stud>students, char type) {
    int maxname = 0, maxsurname = 0, maxcount = 0;
    students.shrink_to_fit();
    for (stud& stud : students) {
        stud.nd.shrink_to_fit();
        if (stud.name.length() >= maxname)
            maxname = stud.name.length();
        if (stud.surname.length() >= maxsurname)
            maxsurname = stud.surname.length();
    }
    if (maxsurname <= 7)
        maxsurname = 7;
    if (maxname <= 6)
        maxname = 6;
    if (type == 'v') {
        maxcount = 0;
        for (stud& stud : students) {
            if (stud.nd.size() >= maxcount)
                maxcount = stud.nd.size();
        }
        for (stud& stud : students) {
            if (maxcount != 0) {
                try{
                stud.vid = (double)stud.sum / (double)maxcount;}
                catch(std::exception e){
                    printf("buvo bandyta apskaiciuototi studentu su 0 nd vidurkius :( \n");
                }
                stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
            }
            else {
                stud.vid = 0;
                stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
            }

        }
    }
    if (type == 'm') {
        for (stud& stud : students) {
            std::sort(stud.nd.begin(), stud.nd.end());
            if (stud.nd.size() % 2 != 0)
                stud.med = stud.nd[round((double)stud.nd.size() / 2)-1 ];
            else
                stud.med = (double)(stud.nd[stud.nd.size() / 2 -1] + stud.nd[(stud.nd.size() / 2) ]) / 2;
            stud.mvid = stud.med*0.4 + stud.ex*0.6;

        }
    }
    if (type == 'm') {
        printf("Pavarde%*cVardas%*cGalutinis (Med.)\n", maxsurname - 6, ' ', maxname - 5, ' ');
        printf("%s\n", (string(29 + maxsurname - 7 + maxname - 6, '-')).c_str());
        for (stud& stud : students) {
            printf("%s%*c%s%*c%.2lf\n", stud.surname.c_str(), maxsurname - stud.surname.length() + 1, ' ', stud.name.c_str(),
                   maxname - stud.name.length() + 1, ' ', stud.mvid);
        }
    }
    if (type == 'v') {
        printf("Pavarde%*cVardas%*cGalutinis (Vid.)\n", maxsurname - 6, ' ', maxname - 5, ' ');
        printf("%s\n", (string(29 + maxsurname - 7 + maxname - 6, '-')).c_str());
        for (stud& stud : students) {
            printf("%s%*c%s%*c%.2lf\n", stud.surname.c_str(), maxsurname - stud.surname.length() + 1, ' ', stud.name.c_str(),
                   maxname - stud.name.length() + 1, ' ', stud.vid2);
        }
    }
}