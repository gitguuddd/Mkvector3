//
// Created by Mindaugas K on 5/2/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_HUMIE_H
#define OBJ_DUOMENU_APDOROJIMAS_HUMIE_H
#include <sstream>
#include <vector>
#include "../../Headers/Vector.h"
using std::istringstream;
using std::string;
using std::iostream;
class Humie{

protected:
    string name_;
    int tempnd;
    string surname_;
    Vector<int> nd_;
    Humie():name_("Vardas"),surname_("Pavarde"){nd_.reserve(200);}
    Humie(string name, string surname, Vector<int> nd):name_(name),surname_(surname),nd_(nd){}
    Humie( Vector<int> nd2,string name, string surname):name_(name),surname_(surname){
        nd_=std::move(nd2);
    }
public:
    void scanname(istringstream& stream);
    void scansurname(istringstream& stream);
    inline void setname (string name){name_=move(name);}
    inline void setsurname (string surname){surname_=move(surname);}
    inline void setnd (int nd){nd_.push_back(nd);}
    inline void pushb (){nd_.pop_back();}
    inline string getname() const {return name_;}
    inline string getsurname() const {return surname_;}
    inline int getndsize() const {return nd_.size();}

};
#endif //OBJ_DUOMENU_APDOROJIMAS_HUMIE_H
