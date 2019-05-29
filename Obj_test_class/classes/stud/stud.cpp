//
// Created by Mindaugas K on 4/29/2019.
#include "../../Headers/Mutual.h"
void stud::setex (){
    ex_=nd_.back();
    nd_.pop_back();
    nd_.shrink_to_fit();}
    void stud::setvid (int max){
    if(max!=0)
        vid_=((double)std::accumulate(nd_.begin(),nd_.end(),0)/(double)max)*0.4+ex_*0.6;
    else
        vid_=ex_*0.6;
nd_.clear();}
void stud::setmvid (){
    std::sort(nd_.begin(), nd_.end());
    if (nd_.size() % 2 != 0)
        mvid_ = nd_[round((double)nd_.size() / 2)-1 ]*0.4+ex_*0.6;
    else
        mvid_ = ((double)(nd_[nd_.size() / 2 -1] + nd_[(nd_.size() / 2) ]) / 2)*0.4+ex_*0.6;
    nd_.clear();
}
stud::stud(const stud& s):Humie(s.name_,s.surname_,s.nd_),vid_{s.vid_},mvid_{s.mvid_},ex_{s.ex_}{
}
stud& stud::operator=(const stud& s){
    if(&s==this)return *this;
    nd_.reserve(s.nd_.size());
    for( int nd: s.nd_)
        nd_.push_back(nd);
    name_=s.name_;
    surname_=s.surname_;
    ex_=s.ex_;
    mvid_=s.mvid_;
    vid_=s.vid_;
    return *this;
}
stud::stud(stud&& s)noexcept:Humie(std::move(s.nd_),s.name_,s.surname_),vid_{s.vid_},mvid_{s.mvid_},ex_{s.ex_}{
    s.name_.clear();
    s.surname_.clear();
    s.ex_=0;
    s.mvid_=0;
    s.vid_=0;
    s.nd_.clear();
}
stud& stud::operator=(stud&& s)noexcept{
    if(&s==this)return *this;
    nd_=move(s.nd_);
    name_=s.name_;
    s.name_.clear();
    surname_=s.surname_;
    s.surname_.clear();
    ex_=s.ex_;
    s.ex_=0;
    mvid_=s.mvid_;
    s.mvid_=0;
    vid_=s.vid_;
    s.vid_=0;
    return *this;
}
bool stud::operator!=(const stud &A) {
    if(v.getpchoice()=='v')
        return vid_!=A.getvid();
    else
        return mvid_!=A.getmvid();
}
bool stud::operator==(const stud &A) {
    if(v.getpchoice()=='v')
        return vid_==A.getvid();
    else
        return mvid_==A.getmvid();}
bool stud::operator>=(const stud &A) {
    if(v.getpchoice()=='v')
        return vid_>=A.getvid();
    else
        return mvid_>=A.getmvid();
}
bool stud::operator<=(const stud &A) {
    if(v.getpchoice()=='v')
        return vid_<=A.getvid();
    else
        return mvid_<=A.getmvid();
}
bool stud::operator>(const stud &A) {
    if(v.getpchoice()=='v')
        return vid_>A.getvid();
    else
        return mvid_>A.getmvid();
}
bool stud::operator<(const stud &A) {
    if(v.getpchoice()=='v')
        return vid_<A.getvid();
    else
        return mvid_<A.getmvid();
}

