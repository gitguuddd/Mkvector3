
// Created by Mindaugas K on 2/25/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
#define OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
#include "../classes/Timer/Timer.h"
#include "../classes/ImportantValues/ImportantValues.h"
#include "../classes/stud/stud.h"
#include <iostream>
#include <iterator>
#include <iomanip>
#include <string>
#include <chrono>
#include <vector>
#include <deque>
#include <cmath>
#include <list>
#include <fstream>
#include <cctype>
#include <typeinfo>
#include <sstream>
#include <algorithm>
#include <numeric>
using std::setw;
using std::setprecision;
using std::string;
using std::cin;
using std::move;
using std::deque;
using std::list;
using std::istream;
using std::stable_partition;
using namespace std::chrono;
extern Timer t;
extern std::ofstream fv;
extern std::ofstream ft;
extern void STLpick(bool pap);
extern void Stratpick();
extern Vector<stud> students;
extern Vector<stud> minksti;
extern Vector<stud> mldcstudents;
extern Vector<stud> mldc;
extern Vector<stud> L_laivs;
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
extern Vector<stud> raskMinkstus(Vector<stud> & students, char pchoice);
extern Vector<stud> raskKietus(Vector<stud> & students, char pchoice);
extern deque<stud> raskMinkstusd(deque<stud> & studentsd, char pchoice);
extern deque<stud> raskKietusd(deque<stud> & studentsd, char pchoice);
extern bool non_alpha;
void Stratpick(char &strat);
extern void handlend( string message);
template <typename T1, typename T2>
extern void handleinput ( T1& input, T2 message) {
    if(cin.fail()){
        do {
            cin.clear();
            cin.ignore(256,'\n');
            std::cout << message;
            cin>>input;
        } while (cin.fail());}
}
template <typename T1>
extern void handlename( T1 &input) {
    if(typeid(input).name()==typeid(v.getmsg()).name()){
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
    (sar=='m')?v.setfilename(v.getsubname()+pchoice+"_mldc.txt"):v.setfilename(v.getsubname()+pchoice+"_L_laivas.txt");
    fv.open(v.getfilename().c_str());
    fv<<kontikas;
    fv.close();
        }
template<template<class> class STL, class type>
extern void vprinttofile (STL<type>  & kontikas, char pchoice, char sar){
    (sar=='m')?v.setfilename(v.getsubname()+pchoice+"_mldc.txt"):v.setfilename(v.getsubname()+pchoice+"_L_laivas.txt");
    fv.open(v.getfilename().c_str());
    fv<<kontikas;
    fv.close();
}
template<template<class,class> class STL, class type, class Allocator>
        extern void calc(STL<type, Allocator> &kontikas, char pchoice){
            if(pchoice=='v'){
                v.setmaxcount(0);
                for (stud& stud : kontikas) {
                    if (stud.getndsize() >= v.getmaxcount())
                        v.setmaxcount(stud.getndsize());
                }
                for (stud& stud : kontikas)
                    stud.setvid(v.getmaxcount());
        }
    if(pchoice=='m'){
        for (stud& stud : kontikas)
            stud.setmvid();
    }}
template<template<class> class STL, class type>
extern void vcalc(STL<type> &kontikas, char pchoice){
    if(pchoice=='v'){
        v.setmaxcount(0);
        for (stud& stud : kontikas) {
            if (stud.getndsize() >= v.getmaxcount())
                v.setmaxcount(stud.getndsize());
        }
        for (stud& stud : kontikas)
            stud.setvid(v.getmaxcount());
    }
    if(pchoice=='m'){
        for (stud& stud : kontikas)
            stud.setmvid();
    }}
template<template<class,class> class STL, class type, class Allocator>
        extern void names(STL<type, Allocator> & kontikas){
    v.setmaxname(0);
    v.setmaxsurname(0);
    v.setmaxcount(0);
    v.setsubname(v.getfilename());
    for (stud& stud : kontikas) {
        if (stud.getname().length() >= v.getmaxname())
            v.setmaxname(stud.getname().length());
        if (stud.getsurname().length() >= v.getmaxsurname())
            v.setmaxsurname(stud.getsurname().length());
    }
    if (v.getmaxsurname() <= 7)
        v.setmaxsurname(7);
    if (v.getmaxname() <= 6)
        v.setmaxname(6);
        }
template<template<class> class STL, class type>
extern void vnames(STL<type> & kontikas){
    v.setmaxname(0);
    v.setmaxsurname(0);
    v.setmaxcount(0);
    v.setsubname(v.getfilename());
    for (stud& stud : kontikas) {
        if (stud.getname().length() >= v.getmaxname())
            v.setmaxname(stud.getname().length());
        if (stud.getsurname().length() >= v.getmaxsurname())
            v.setmaxsurname(stud.getsurname().length());
    }
    if (v.getmaxsurname() <= 7)
        v.setmaxsurname(7);
    if (v.getmaxname() <= 6)
        v.setmaxname(6);
}
template<template<class,class> class STL, class type, class Allocator>
        extern void readfile(STL<type, Allocator> & kontikas, string filename){
    t.reset();
    std::ifstream fd((filename+".txt").c_str());
    v.linecount=0;
    stud temp;
    string line;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        v.fsio = false;
        v.countnd = 0;
        std::istringstream scan(line);
        scan>>temp;
        temp.setex();
        v.linecount++;
        kontikas.push_back(temp);
        temp={};
    }
    fd.close();
    v.setdiff(t.elapsed());
        };
template<template<class> class STL, class type>
extern void vreadfile(STL<type> & kontikas, string filename){
    t.reset();
    std::ifstream fd((filename+".txt").c_str());
    v.linecount=0;
    stud temp;
    string line;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        v.fsio = false;
        v.countnd = 0;
        std::istringstream scan(line);
        scan>>temp;
        temp.setex();
        v.linecount++;
        kontikas.push_back(temp);
        temp={};
    }
    fd.close();
    v.setdiff(t.elapsed());
};
#endif //OBJ_DUOMENU_APDOROJIMAS_MUTUAL_H
