//
// Created by Mindaugas K on 5/2/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_MAXVALUES_H
#define OBJ_DUOMENU_APDOROJIMAS_MAXVALUES_H
#include "iostream"
using std::string;
class ImportantValues{
private:
     int namenum_;
     int gensize_;
     int num_;
     int maxname_;
     int ndcount_;
     int maxsurname_;
     int maxcount_;
     char kiec_;
     char issamiai_;
     bool pap_;
     string filename_;
     string subname_;
     char pchoice_;
     char STL_;
     char sar_;
     char strat_;
     string msg_;
     long double diff_;
public:
    //setters
    inline void setnamenum(int namenum){
        namenum_=namenum;
    }
    inline void setgensize(int gensize){
        gensize_=gensize;
    };
    inline void setnum(int num){
        num_=num;
    }
    inline void setmaxname(int maxname){
        maxname_=maxname;
    }
    inline void setmaxsurname(int ndcount){
        ndcount_=ndcount;
    }
    inline void setndcount(){
        std::cin>>ndcount_;
    }
    inline void setmaxcount(int maxcount){
        maxcount_=maxcount;
    }
    inline void setkiec(){
        std::cin>>kiec_;
    }
    inline void setissamiai(){
        std::cin>>issamiai_;
    }
    inline void setpchoice(){
        std::cin>>pchoice_;
    }
    inline void setsar(char sar){
        sar_=sar;
    }
    inline void setSTL(){
        std::cin>>STL_;
    }
    inline void setstrat(){
        std::cin>>strat_;
    }
    inline void setstrat2(char strat){
        strat_=strat;
    }
    inline void setpap(bool pap){
        pap_=pap;
    }
    inline void setfilename(string filename){
        filename_=filename;
    }
    inline void setsubname(string subname){
        subname_=subname;
    }
    inline void setmsg(string msg){
        msg_=msg;
    }
    inline void setdiff(long double diff){
        diff_=diff;}
    //getters
    inline int getnamenum(){return namenum_;}
    inline int getgensize(){return gensize_;}
    inline int getnum(){return num_;}
    inline int getmaxname(){return maxname_;}
    inline int getmaxsurname(){return maxsurname_;}
    inline int getndcount(){
        return ndcount_;}
    inline int getmaxcount(){return maxcount_;}
    inline char getkiec(){return kiec_;}
    inline char getissamiai(){return issamiai_;}
    inline char getpchoice(){return pchoice_;}
    inline char getSTL(){return STL_;}
    inline bool getpap(){return pap_;}
    inline char getsar(){return sar_;}
    inline char getstrat(){return strat_;}
    inline string getfilename(){return filename_;}
    inline string getsubname(){return subname_;}
    inline string getmsg(){return msg_;}
    inline long double getdiff(){return diff_;}
    //for input
    int linecount = 1;
    int countnd;
    int tempnd;
    bool fsio;;
};
extern ImportantValues v;

#endif //OBJ_DUOMENU_APDOROJIMAS_MAXVALUES_H
