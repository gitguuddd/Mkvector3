//
// Created by Mindaugas K on 2/25/2019.
//

#include "Mutual.h"
Vector<stud> students;
Vector<stud> minksti;
Vector<stud>mldcstudents;
Vector <stud> mldc;
Vector <stud> L_laivs;
list<stud> studentsl;
list<stud> mldcstudentsl;
list <stud> mldcl;
list <stud> L_laivsl;
deque<stud> studentsd;
deque<stud> minkstid;
deque<stud> mldcstudentsd;
deque <stud> mldcd;
deque <stud> L_laivsd;
stud test;
int ndcount;
bool non_alpha;
string filename;
string subname;
string msg;
Timer t;
std::ofstream fv;
std::ofstream ft;
char pchoice;
char kiec;
char issamiai;
int maxname, maxsurname, maxcount;
high_resolution_clock::time_point start;
high_resolution_clock::time_point end;
duration<long double> diff;
void STLpick(char &STL,  bool pap){
    if(pap==false){
    printf("Su kuriuo STL konteineriu norite dirbti ? [d]eque/[v]ector/[l]ist\n");
    cin>>STL;
    while(STL!='d'&&STL!='v'&&STL!='l'){
        printf("Netinkama ivestis, bandykite is naujo\n");
        cin>>STL;
    }}
    else if(pap==true){
        printf("Su kuriuo STL konteineriu norite dirbti ? [d]eque\n");
        cin>>STL;
        while(STL!='d'){
            printf("Netinkama ivestis, bandykite is naujo\n");
            cin>>STL;
        }
    }
}
void Stratpick(char &strat){
    printf("Kuria skelimo strategija naudosite noredami perskelti studentus?\n");
    printf(" [a] - sukurti du naujus STL'us ir i juos atrinkti tinkamus studentus\n");
    printf(" [b] - sukurti viena nauja STL'a, sename STL'e istrinti naujame STL'e esancius studentus\n");
    printf(" [c] - isrikiuoti studentus, rasti iteratoriu i (i>=5), naudojant iteratoriu sukurti nauja STL'a\n");
    printf(" [d] - dirbti su papildomos uzduoties siulomais sprendimais\n");
    cin>>strat;
    while(strat!='a'&&strat!='b'&&strat!='c'&&strat!='d'){
        printf("Netinkama ivestis, bandykite is naujo - a, b, c arba d\n");
        cin>>strat;
    }
}
bool GavoSkola(const stud student1, char pchoice){
    if(pchoice=='v'){
        if(student1.vid2< 4.99999999)
            return true;
        else if(student1.vid2>4.9999999)
            return false;
        else if(student1.vid2==4.999999)
            return false;
    }
    else if(pchoice=='m'){
        if(student1.mvid<4.99999999){
            return true;
        }
        else if(student1.mvid>4.9999999){
            return false;
        }
        else if (student1.mvid==4.999999)
            return false;
    }
}
Vector<stud> raskMinkstus(Vector<stud> & students, char pchoice){
    start=high_resolution_clock::now();
    Vector<stud> minksti;
    Vector<stud>::size_type i = 0;
    while (i != students.size()) {
        if (GavoSkola(students[i],pchoice)) {
            minksti.push_back(students[i]);
            students.erase(students.begin() + i);
        } else
            ++i;
    }
    end=high_resolution_clock::now();
    diff=end-start;
    return minksti;
}
deque<stud> raskMinkstusd(deque<stud> & studentsd, char pchoice){
    start=high_resolution_clock::now();
    deque<stud> minksti;
    deque<stud>::size_type i = 0;
    while (i != studentsd.size()) {
        if (GavoSkola(studentsd[i],pchoice)) {
            minksti.push_back(studentsd[i]);
            studentsd.erase(studentsd.begin() + i);
        } else
            ++i;
    }
    end=high_resolution_clock::now();
    diff=end-start;
    return minksti;
}
deque<stud> raskKietusd(deque<stud> & studentsd, char pchoice){
    start=high_resolution_clock::now();
    deque<stud> minksti;
    deque<stud>::size_type i = 0;
    int dydis= studentsd.size();

    while (i != studentsd.size()) {
        if (GavoSkola(studentsd[i],pchoice)) {
            minksti.push_back(studentsd[i]);
            ++i;
        } else if(!GavoSkola(studentsd[i],pchoice)){
            studentsd.insert(studentsd.begin(),studentsd[i]);
            i=i+2;
        }
    }
    studentsd.resize((studentsd.size()-dydis));
    studentsd.shrink_to_fit();
    end=high_resolution_clock::now();
    diff=end-start;
    return minksti;
}
Vector<stud> raskKietus(Vector<stud> & students, char pchoice){
    start=high_resolution_clock::now();
    Vector<stud> minksti;
    Vector<stud>::size_type i = 0;
    int dydis=students.size();
 while (i != students.size()) {
        if (GavoSkola(students[i],pchoice)) {
            minksti.push_back(students[i]);
            ++i;
        } else if(!GavoSkola(students[i],pchoice)){
            students.insert(students.begin(),students[i]);
            i=i+2;
        }
    }
    students.resize((students.size()-dydis));
    students.shrink_to_fit();
    end=high_resolution_clock::now();
    diff=end-start;
    return minksti;
}
