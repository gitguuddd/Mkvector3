//
// Created by Mindaugas K on 2/25/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
#define OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
#include <iostream>
#include "Timer.h"
#include <iomanip>
#include <iterator>
#include <string>
#include <vector>
#include "Vector.h"
#include <deque>
#include <cmath>
#include <list>
#include <fstream>
#include <cctype>
#include <typeinfo>
#include <sstream>
#include <algorithm>
using std::setw;
using std::setprecision;
using std::string;
using std::cin;
using std::deque;
using std::list;
using std::stable_partition;
using namespace std::chrono;
extern char kiec;
extern Timer t;
extern char issamiai;
extern bool pap;
extern int maxname;
extern int ndcount;
extern int maxsurname;
extern int maxcount;
extern string filename;
extern string subname;
extern char pchoice;
extern char STL;
extern string msg;
extern int maxname, maxsurname, maxcount;
extern const double numb;
extern std::ofstream fv;
extern std::ofstream ft;
extern high_resolution_clock::time_point start;
extern high_resolution_clock::time_point end;
extern duration<long double> diff;
struct stud {
    string name;
    string surname;
    Vector<int> nd;
    int ex;
    double vid;
    double med;
    double mvid;
    double vid2;
    int sum = 0;
    struct less_than_vid2{
        bool operator()(const  stud & a, const stud & b){
            return a.vid2<b.vid2;

        }
    };
    struct less_than_mvid{
        bool operator()(const  stud & a, const stud & b){
            return a.mvid<b.mvid;
        }
    };
};
extern void STLpick(char &STL, bool pap);
extern void Stratpick(char &strat);
extern Vector<stud> students;
extern Vector<stud> minksti;
extern Vector<stud> mldcstudents;
extern Vector <stud> mldc;
extern Vector <stud> L_laivs;
extern Vector<stud>::iterator up;
extern list<stud> studentsl;
extern list<stud> mldcstudentsl;
extern list <stud> mldcl;
extern list <stud> L_laivsl;
extern list<stud>::iterator upl;
extern deque<stud> studentsd;
extern deque<stud> minkstid;
extern deque<stud> mldcstudentsd;
extern deque <stud> mldcd;
extern deque <stud> L_laivsd;
extern deque<stud>::iterator upd;
extern stud test;
template<template<class,class> class STL, class type, class Allocator>
extern bool GavoSkola(STL<type, Allocator>  & kontikas, char pchoice){if(pchoice=='v'){
        if(kontikas.vid2< 4.99999999)
            return true;
        else if(kontikas.vid2>4.9999999)
            return false;
        else if(kontikas.vid2==4.999999)
            return false;
    }
    else if(pchoice=='m'){
        if(kontikas.mvid<4.99999999){
            return true;
        }
        else if(kontikas.mvid>4.9999999){
            return false;
        }
        else if (kontikas.mvid==4.999999)
            return false;
    }
}
template<template<class> class STL, class type>
extern bool GavoSkola(STL<type>  & kontikas, char pchoice){if(pchoice=='v'){
        if(kontikas.vid2< 4.99999999)
            return true;
        else if(kontikas.vid2>4.9999999)
            return false;
        else if(kontikas.vid2==4.999999)
            return false;
    }
    else if(pchoice=='m'){
        if(kontikas.mvid<4.99999999){
            return true;
        }
        else if(kontikas.mvid>4.9999999){
            return false;
        }
        else if (kontikas.mvid==4.999999)
            return false;
    }
}
extern Vector<stud> raskMinkstus(Vector<stud> & students, char pchoice);
extern Vector<stud> raskKietus(Vector<stud> & students, char pchoice);
extern deque<stud> raskMinkstusd(deque<stud> & studentsd, char pchoice);
extern deque<stud> raskKietusd(deque<stud> & studentsd, char pchoice);
extern bool non_alpha;
void Stratpick(char &strat);
template <typename T1, typename T2>
extern void handleinput( T1 &input, T2 message) {
    if(cin.fail()){
        do {
            cin.clear();
            cin.ignore(256,'\n');
            std::cout << message;
            cin >> input;
        } while (cin.fail());}
}
template <typename T1>
extern void handlename( T1 &input) {
    if(typeid(input).name()==typeid(msg).name()){
        non_alpha=std::find_if(input.begin(), input.end(),
                               [](char c) { return !std::isalpha(c); }) != input.end();
        if(non_alpha){
            printf("Aptiktas klaidingas vardas/pavarde, irasomas sablonas\n");
            input="BadInput";
        }

    }
}
template<template<class,class> class STL, class type, class Allocator>
        extern void printtofile (STL<type, Allocator>  & kontikas, char pchoice, char sar){
    (sar=='m')?filename=subname+pchoice+"_mldc.txt":filename=subname+pchoice+"_L_laivas.txt";
    fv.open(filename.c_str());
    if(pchoice == 'v'){
    fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
    fv<<"Galutinis (vid.)\n";
    fv<<"-------------------------------------------------------\n";}
    else if(pchoice == 'm'){
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (med.)\n";
        fv<<"-------------------------------------------------------\n";
    }
    if(pchoice == 'v'){
    for(stud& stud : kontikas){
        fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
        fv<<stud.vid2<<setprecision(3)<<"\n";
    }}
    else if(pchoice == 'm'){
        for(stud& stud : kontikas){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.mvid<<setprecision(3)<<"\n";
        }
    }
    fv.close();
        }
template<template<class> class STL, class type>
extern void printtofile (STL<type>  & kontikas, char pchoice, char sar){
    (sar=='m')?filename=subname+pchoice+"_mldc.txt":filename=subname+pchoice+"_L_laivas.txt";
    fv.open(filename.c_str());
    if(pchoice == 'v'){
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (vid.)\n";
        fv<<"-------------------------------------------------------\n";}
    else if(pchoice == 'm'){
        fv<<"Vardas"<<setw(maxname+2)<<"Pavarde"<<setw(maxname+maxsurname+3);
        fv<<"Galutinis (med.)\n";
        fv<<"-------------------------------------------------------\n";
    }
    if(pchoice == 'v'){
        for(stud& stud : kontikas){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.vid2<<setprecision(3)<<"\n";
        }}
    else if(pchoice == 'm'){
        for(stud& stud : kontikas){
            fv<<stud.name<<setw(maxname+2)<<std::right<<stud.surname<<setw(maxname-4+(maxname-stud.name.length()));
            fv<<stud.mvid<<setprecision(3)<<"\n";
        }
    }
    fv.close();
}
template<template<class,class> class STL, class type, class Allocator>
        extern void calc(STL<type, Allocator> &kontikas, char pchoice){
            if(pchoice=='v'){
                maxcount = 0;
                for (stud& stud : kontikas) {
                    if (stud.nd.size() >= maxcount)
                        maxcount = stud.nd.size();
                }
                for (stud& stud : kontikas) {
                    if (maxcount != 0) {
                        try{
                            stud.vid = (double)stud.sum / (double)maxcount;}
                        catch(std::exception e){
                            printf("buvo bandyta apskaiciuototi studentu su 0 nd vidurkius :( \n");
                            stud.vid=0;
                        }
                        stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
                    }
                    else {
                        stud.vid = 0;
                        stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
                    }

                }
        }
    if(pchoice=='m'){
        for (stud& stud : kontikas) {
            std::sort(stud.nd.begin(), stud.nd.end());
            if (stud.nd.size() % 2 != 0)
                stud.med = stud.nd[round((double)stud.nd.size() / 2)-1 ];
            else
                stud.med = (double)(stud.nd[stud.nd.size() / 2 -1] + stud.nd[(stud.nd.size() / 2) ]) / 2;
            stud.mvid = stud.med*0.4 + stud.ex*0.6;

        }
    }}
template<template<class> class STL, class type>
extern void calc(STL<type> &kontikas, char pchoice){
    if(pchoice=='v'){
        maxcount = 0;
        for (stud& stud : kontikas) {
            if (stud.nd.size() >= maxcount)
                maxcount = stud.nd.size();
        }
        for (stud& stud : kontikas) {
            if (maxcount != 0) {
                try{
                    stud.vid = (double)stud.sum / (double)maxcount;}
                catch(std::exception e){
                    printf("buvo bandyta apskaiciuototi studentu su 0 nd vidurkius :( \n");
                    stud.vid=0;
                }
                stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
            }
            else {
                stud.vid = 0;
                stud.vid2 = stud.vid*0.4 + stud.ex*0.6;
            }

        }
    }
    if(pchoice=='m'){
        for (stud& stud : kontikas) {
            std::sort(stud.nd.begin(), stud.nd.end());
            if (stud.nd.size() % 2 != 0)
                stud.med = stud.nd[round((double)stud.nd.size() / 2)-1 ];
            else
                stud.med = (double)(stud.nd[stud.nd.size() / 2 -1] + stud.nd[(stud.nd.size() / 2) ]) / 2;
            stud.mvid = stud.med*0.4 + stud.ex*0.6;

        }
    }}
template<template<class,class> class STL, class type, class Allocator>
        extern void names(STL<type, Allocator> & kontikas){
    maxname = 0;
    maxsurname=0;
    maxcount = 0;
    subname=filename;
    for (stud& stud : kontikas) {
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
        }
template<template<class> class STL, class type>
extern void names(STL<type> & kontikas){
    maxname = 0;
    maxsurname=0;
    maxcount = 0;
    subname=filename;
    for (stud& stud : kontikas) {
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
}
template<template<class,class> class STL, class type, class Allocator>
        extern void readfile(STL<type, Allocator> & kontikas, string filename){
    start=high_resolution_clock::now();
    std::ifstream fd((filename+".txt").c_str());
    int linecount = 1;
    int countnd;
    int tempnd;
    stud temp;
    bool fsio;
    string line;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        fsio = false;
        countnd = 0;
        std::istringstream scan(line);
        scan >> temp.surname;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento pavarde\n",filename.c_str(), linecount);
        }
        scan >> temp.name;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento varda\n",filename.c_str(), linecount);
        }
        while (scan) {
            scan >> tempnd;
            if (scan.fail()) {
                do {
                    scan.clear();
                    scan.ignore(4);
                    printf("%s faile ivyko klaida nuskaitant %d studento %d pazymi\n",filename.c_str(), linecount,
                           countnd + 1);
                    try{
                        temp.nd.push_back(0);}
                    catch(std::exception &e){
                        printf("Perzengtos %d studento namu darbu vektoriaus ribos\n", linecount);
                    }
                    countnd++;
                    if (scan.peek() != '\n'&&scan.peek() != EOF)
                        scan >> tempnd;
                    else {
                        fsio = true;
                        break;
                    }
                } while (scan.fail());

            }
            if (!fsio) {
                if (tempnd < 0 || tempnd > 10) {
                    tempnd = 0;
                }
                temp.sum += tempnd;
                try{
                    temp.nd.push_back(tempnd);}
                catch(std::exception &e){
                    printf("Perzengtos %d studento namu darbu vektoriaus ribos\n",linecount);
                }
                countnd++;
            }
            if (scan.peek() == '\n' || scan.peek() == EOF)
                break;

        }
        temp.ex = temp.nd.back();
        temp.sum-=temp.nd.back();
        temp.nd.pop_back();
        linecount++;
        kontikas.push_back(temp);
        temp = {};
    }
    fd.close();
    end=high_resolution_clock::now();
    diff=end-start;
        }
template<template<class> class STL, class type>
extern void readfile(STL<type> & kontikas, string filename){
    start=high_resolution_clock::now();
    std::ifstream fd((filename+".txt").c_str());
    int linecount = 1;
    int countnd;
    int tempnd;
    stud temp;
    bool fsio;
    string line;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        fsio = false;
        countnd = 0;
        std::istringstream scan(line);
        scan >> temp.surname;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento pavarde\n",filename.c_str(), linecount);
        }
        scan >> temp.name;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("%s faile ivyko klaida nuskaitant %d studento varda\n",filename.c_str(), linecount);
        }
        while (scan) {
            scan >> tempnd;
            if (scan.fail()) {
                do {
                    scan.clear();
                    scan.ignore(4);
                    printf("%s faile ivyko klaida nuskaitant %d studento %d pazymi\n",filename.c_str(), linecount,
                           countnd + 1);
                    try{
                        temp.nd.push_back(0);}
                    catch(std::exception &e){
                        printf("Perzengtos %d studento namu darbu vektoriaus ribos\n", linecount);
                    }
                    countnd++;
                    if (scan.peek() != '\n'&&scan.peek() != EOF)
                        scan >> tempnd;
                    else {
                        fsio = true;
                        break;
                    }
                } while (scan.fail());

            }
            if (!fsio) {
                if (tempnd < 0 || tempnd > 10) {
                    tempnd = 0;
                }
                temp.sum += tempnd;
                try{
                    temp.nd.push_back(tempnd);}
                catch(std::exception &e){
                    printf("Perzengtos %d studento namu darbu vektoriaus ribos\n",linecount);
                }
                countnd++;
            }
            if (scan.peek() == '\n' || scan.peek() == EOF)
                break;

        }
        temp.ex = temp.nd.back();
        temp.sum-=temp.nd.back();
        temp.nd.pop_back();
        linecount++;
        kontikas.push_back(temp);
        temp={};
    }
    fd.close();
    end=high_resolution_clock::now();
    diff=end-start;
}
#endif //OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
