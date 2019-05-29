#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
using std::string;
using std::cin;
struct stud {
     string name;
     string surname;
    int *C;
    int ex;
    int sum=0;
    double vid;
    double med;
    double mvid;
    double vid2;
    int count;
};
int main() {
    char type, check;
    int maxname=0, maxsurname=0;
    int *Sub;
    int num, grade, size, maxgr;
    srand((unsigned int)time(nullptr));
    printf("-----------Duomenu ivestis-----------\n");
    printf("Keliu studentu duomenys bus ivesti?\n");
    cin >> num;
    auto students = new stud[num];
    for (int i = 0; i < num; i++) {
        check = 't';
        printf("Iveskite studento varda\n");
        cin >> students[i].name;
        if (students[i].name.length()>=maxname)
            maxname=students[i].name.length();

        printf("Iveskite studento pavarde\n");
        cin >> students[i].surname;
        if (students[i].surname.length()>=maxsurname)
            maxsurname=students[i].surname.length();
        students[i].count = 0;
        while (check == 't' || check == 'T') {
            size = students[i].count;
            if (size == 0) {
                grade = (double)rand() / RAND_MAX * 11;
                printf("Pirmas nd pazymys: %d\n", grade);
                students[i].C = new int[1];
                students[i].C[0] = grade;
                students[i].count++;
                students[i].sum+=grade;
            }
            else {
                printf("Generuoti %d-a nd pazymi ? [t]aip/[n]e\n", size + 1);
                cin >> check;
                if (check == 't' || check == 'T') {
                    Sub = new int[size];
                    for (int j = 0; j < size; j++) {
                        Sub[j] = students[i].C[j];
                    }
                    delete[] students[i].C;

                    students[i].C = new int[size+ 1];
                    for (int j = 0; j < size;j++) {
                        students[i].C[j] = Sub[j];
                    }
                    grade = (double)rand() / RAND_MAX * 11;
                    students[i].sum+=grade;
                    printf("%d-as nd pazymys: %d\n", size + 1, grade);
                    students[i].C[size] = grade;
                    delete[] Sub;
                    students[i].count++;

                }
            }

        }
        students[i].ex = (double)rand() / RAND_MAX * 11;
        printf("egzamino pazymys - %d\n",students[i].ex);
        std::sort(students[i].C,students[i].C+students[i].count);
        if(students[i].count%2!=0)
            students[i].med=students[i].C[students[i].count/2];
        else
            students[i].med=(students[i].C[(students[i].count)/2] + students[i].C[students[i].count/2+1])/2.0;
        students[i].mvid=0.4*students[i].med+0.6*students[i].ex;


    }

    maxgr=students[0].count;
    for(int i=0;i<num;i++){
        if (students[i].count>maxgr){
            maxgr=students[i].count;
        }
    }
    for(int i=0;i<num;i++){
        students[i].vid=students[i].sum/maxgr;
        students[i].vid2=0.4*students[i].vid+0.6*students[i].ex;
    }
    if(maxsurname<=7)
        maxsurname=7;
    if(maxname<=6)
        maxname=6;
    printf ("Spausdinti galutini pagal [m]ediana/[n]d vidurki? /n");
    cin>>type;
    if(type=='m'||type=='M')
        printf("Pavarde%*cVardas%*cGalutinis (Med.)\n",maxsurname-6,' ',maxname-5,' ');
        else if(type=='n'||type=='N')
        printf("Pavarde%*cVardas%*cGalutinis (Vid.)\n", maxsurname-6, ' ', maxname-5, ' ');
    printf("%s\n",(string(29+maxsurname-6+maxname-5,'-')).c_str());


    for(int i=0;i<num;i++){

            if(type=='m'||type=='M'){
                printf("%s%*c%s%*c%.2lf\n", students[i].surname.c_str(), maxsurname-students[i].surname.length()+1,' ', students[i].name.c_str(),
                       maxname-students[i].name.length()+1,' ', students[i].mvid);
            }
            else if (type=='n'||type=='N') {
                    printf("%s%*c%s%*c%.2lf\n", students[i].surname.c_str(), maxsurname-students[i].surname.length()+1,' ', students[i].name.c_str(),
                           maxname-students[i].name.length()+1,' ', students[i].vid2);

                }

    }

    return 0;
}