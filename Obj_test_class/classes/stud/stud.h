//
// Created by Mindaugas K on 4/29/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_STUD_H
#define OBJ_DUOMENU_APDOROJIMAS_STUD_H
#include <string>
#include <iomanip>
#include "../Humie/Humie.h"
#include "../ImportantValues/ImportantValues.h"
using std::string;
using std::setw;
using std::setprecision;
class stud:public Humie{
private:
    int ex_;
    double mvid_;
    double vid_;
public:
    stud():ex_(0), mvid_(4.999999999), vid_(4.999999999){};
    stud(const stud& s);
    stud& operator=(const stud& s);
    stud(stud&& s)noexcept;
    stud& operator=(stud&& s)noexcept;
    inline void setex (int ex){ex_=ex;}
    void setex ();
    void setvid (int max);
    void setmvid ();
    inline int getex() const {return ex_;}
    inline double getmvid() const {return mvid_;}
    inline double getvid() const {return vid_;}
    bool operator==(const stud& A);
    bool operator<=(const stud& A);
    bool operator>=(const stud& A);
    bool operator!=(const stud& A);
    bool operator>(const stud& A);
    bool operator<(const stud& A);
    friend istringstream& operator>>(std::istringstream& scan, stud &temp) {
        temp.scansurname(scan);
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento pavarde\n", v.getfilename().c_str(), v.linecount);
        }
        temp.scanname(scan);
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento varda\n", v.getfilename().c_str(), v.linecount);
        }
        while (scan) {
            scan >> v.tempnd;
            if (scan.fail()) {
                do {
                    scan.clear();
                    scan.ignore(4);
                    printf("%s faile ivyko klaida nuskaitant %d studento %d pazymi\n", v.getfilename().c_str(),
                           v.linecount,
                           v.countnd + 1);
                    v.countnd++;
                    temp.setnd(0);
                    if (scan.peek() != '\n' && scan.peek() != EOF)
                        scan >> v.tempnd;
                    else {
                        v.fsio = true;
                        break;
                    }
                } while (scan.fail());

            }
            if (!v.fsio) {
                if (v.tempnd < 0 || v.tempnd > 10) {
                    v.tempnd = 0;
                }
                temp.setnd(v.tempnd);
                v.countnd++;
            }
            if (scan.peek() == '\n' || scan.peek() == EOF)
                break;

        }
    }
    template<template<class> class STL, class type>
    friend std::ostream& operator<<(std::ostream& fv,  STL<type>  &kontikas){
        if(v.getpchoice()== 'v'){
            fv<<"Vardas"<<setw(v.getmaxname()+2)<<"Pavarde"<<setw(v.getmaxname()+v.getmaxsurname()+3);
            fv<<"Galutinis (vid.)\n";
            fv<<"-------------------------------------------------------\n";}
        else if(v.getpchoice()== 'm'){
            fv<<"Vardas"<<setw(v.getmaxname()+2)<<"Pavarde"<<setw(v.getmaxname()+v.getmaxsurname()+3);
            fv<<"Galutinis (med.)\n";
            fv<<"-------------------------------------------------------\n";
        }
        if(v.getpchoice()== 'v'){
            for(stud& stud : kontikas){
                fv<<stud.getname()<<setw(v.getmaxname()+2)<<std::right<<stud.getsurname()<<setw(v.getmaxname()-4+(v.getmaxname()-stud.getname().length()));
                fv<<stud.getvid()<<setprecision(3)<<"\n";
            }}
        else if(v.getpchoice() == 'm'){
            for(stud& stud : kontikas){
                fv<<stud.getname()<<setw(v.getmaxname()+2)<<std::right<<stud.getname()<<setw(v.getmaxname()-4+(v.getmaxname()-stud.getname().length()));
                fv<<stud.getmvid()<<setprecision(3)<<"\n";
            }
        }
    }
    template<template<class,class> class STL, class type, class Allocator>
    friend std::ostream& operator<<(std::ostream& fv,  STL<type,Allocator>  &kontikas){
        if(v.getpchoice()== 'v'){
            fv<<"Vardas"<<setw(v.getmaxname()+2)<<"Pavarde"<<setw(v.getmaxname()+v.getmaxsurname()+3);
            fv<<"Galutinis (vid.)\n";
            fv<<"-------------------------------------------------------\n";}
        else if(v.getpchoice()== 'm'){
            fv<<"Vardas"<<setw(v.getmaxname()+2)<<"Pavarde"<<setw(v.getmaxname()+v.getmaxsurname()+3);
            fv<<"Galutinis (med.)\n";
            fv<<"-------------------------------------------------------\n";
        }
        if(v.getpchoice()== 'v'){
            for(stud& stud : kontikas){
                fv<<stud.getname()<<setw(v.getmaxname()+2)<<std::right<<stud.getsurname()<<setw(v.getmaxname()-4+(v.getmaxname()-stud.getname().length()));
                fv<<stud.getvid()<<setprecision(3)<<"\n";
            }}
        else if(v.getpchoice() == 'm'){
            for(stud& stud : kontikas){
                fv<<stud.getname()<<setw(v.getmaxname()+2)<<std::right<<stud.getname()<<setw(v.getmaxname()-4+(v.getmaxname()-stud.getname().length()));
                fv<<stud.getmvid()<<setprecision(3)<<"\n";
            }
        }
    }

};
struct less_than_mvid{
    bool operator()(const  stud & a, const stud & b){
        return a.getmvid()<b.getmvid();
    }
};
struct less_than_vid {
    bool operator()(const  stud & a, const stud & b){
        return a.getvid()<b.getvid();
    }
};
#endif //OBJ_DUOMENU_APDOROJIMAS_STUD_H
