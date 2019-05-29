//
// Created by Mindaugas K on 2/25/2019.
//

#include "../Headers/Mutual.h"
#include "../classes/ImportantValues/ImportantValues.h"
Vector<stud> students;
Vector<stud> minksti;
Vector<stud>mldcstudents;
Vector<stud> mldc;
Vector<stud> L_laivs;
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
bool non_alpha;
std::ofstream fv;
std::ofstream ft;
Timer t;
long double diff;
void handlend( string message) {
    if(cin.fail()){
        do {
            cin.clear();
            cin.ignore(256,'\n');
            std::cout << message;
            v.setndcount();
        } while (cin.fail());}
}
void STLpick(bool pap){
    if(pap==false){
    printf("Su kuriuo STL konteineriu norite dirbti ? [d]eque/[v]ector/[l]ist\n");
    v.setSTL();
    while(v.getSTL()!='d'&&v.getSTL()!='v'&&v.getSTL()!='l'){
        printf("Netinkama ivestis, bandykite is naujo\n");
        v.setSTL();
    }}
    else if(pap==true){
        printf("Su kuriuo STL konteineriu norite dirbti ? [d]eque\n");
        v.setSTL();
        while(v.getSTL()!='d'){
            printf("Netinkama ivestis, bandykite is naujo\n");
            v.setSTL();
        }
    }
}
void Stratpick(){
    printf("Kuria skelimo strategija naudosite noredami perskelti studentus?\n");
    printf(" [a] - sukurti du naujus STL'us ir i juos atrinkti tinkamus studentus\n");
    printf(" [b] - sukurti viena nauja STL'a, sename STL'e istrinti naujame STL'e esancius studentus\n");
    printf(" [c] - isrikiuoti studentus, rasti iteratoriu i (i>=5), naudojant iteratoriu sukurti nauja STL'a\n");
    printf(" [d] - dirbti su papildomos uzduoties siulomais sprendimais\n");
    v.setstrat();
    while(v.getstrat()!='a'&&v.getstrat()!='b'&&v.getstrat()!='c'&&v.getstrat()!='d'){
        printf("Netinkama ivestis, bandykite is naujo - a, b, c arba d\n");
        v.setstrat();
    }
}
bool GavoSkola(const stud student1, char pchoice){
    if(pchoice=='v'){
        if(student1.getvid()< 4.99999999)
            return true;
        else if(student1.getvid()>4.999999999)
            return false;
        else if(student1.getvid()==4.999999999)
            return false;
    }
    else if(pchoice=='m'){
        if(student1.getmvid()<4.99999999){
            return true;
        }
        else if(student1.getmvid()>4.9999999){
            return false;
        }
        else if (student1.getmvid()==4.999999)
            return false;
    }
}
Vector<stud> raskMinkstus(Vector<stud> & students, char pchoice){
    t.reset();
    Vector<stud> minksti;
    Vector<stud>::size_type i = 0;
    while (i != students.size()) {
        if (GavoSkola(students[i],pchoice)) {
            minksti.push_back(students[i]);
            students.erase(students.begin() + i);
        } else
            ++i;
    }
    diff=t.elapsed();
    return minksti;
}
deque<stud> raskMinkstusd(deque<stud> & studentsd, char pchoice){
    t.reset();
    deque<stud> minksti;
    deque<stud>::size_type i = 0;
    while (i != studentsd.size()) {
        if (GavoSkola(studentsd[i],pchoice)) {
            minksti.push_back(studentsd[i]);
            studentsd.erase(studentsd.begin() + i);
        } else
            ++i;
    }
    diff=t.elapsed();
    return minksti;
}
deque<stud> raskKietusd(deque<stud> & studentsd, char pchoice){
    t.reset();
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
    diff=t.elapsed();
    return minksti;
}
Vector<stud> raskKietus(Vector<stud> & students, char pchoice){
    t.reset();
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
    diff=t.elapsed();
    return minksti;
}
