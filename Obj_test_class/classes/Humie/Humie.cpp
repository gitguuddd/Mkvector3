//
// Created by Mindaugas K on 5/2/2019.
#include "Humie.h"

void Humie::scanname(istringstream& stream){
    stream>>name_;
    if(stream.fail())
        name_="Vardas";
}
void Humie::scansurname(istringstream& stream){
    stream>>surname_;
    if(stream.fail())
        surname_="Pavarde";
}
