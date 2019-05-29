//
// Created by Mindaugas K on 2/18/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_HEADERS_H
#define OBJ_DUOMENU_APDOROJIMAS_HEADERS_H
#include "Mutual.h"
#include <random>
#include <ctime>
extern int namenum;
extern int gensize;
extern int num;
extern char sar;
extern Vector<stud>::iterator up;
extern long long seed;
extern std::mt19937 mt;
extern std::uniform_real_distribution<double> dist;
extern std::uniform_real_distribution<double> dist2;
stud Userinput();
void Genstudent(int gensize);
stud GenStudent();
void readfile(bool & isempty, int &readcount);
bool sortingvid(const stud student1, const stud student2);
bool sortingmvid(const stud student1, const stud student2);
extern void split(char pchoice, char strat, std::vector<stud>::iterator &up);
extern void splitd(char pchoice, char strat, std::deque<stud>::iterator &upd);
extern void splitl(char pchoice, char strat, std::list<stud>::iterator &upl);
extern void splitnprint(char pchoice, char strat);
extern void splitnprintd( char pchoice, char strat);
extern void splitnprintl( char pchoice, char strat);



#endif //OBJ_DUOMENU_APDOROJIMAS_Input_H
