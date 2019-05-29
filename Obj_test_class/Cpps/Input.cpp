//
// Created by Mindaugas K on 2/25/2019.
//
#include "../Headers/Mutual.h"
#include "../classes/ImportantValues/ImportantValues.h"
#include "../Headers/Input.h"
std::deque<stud>::iterator upd;
std::list<stud>::iterator upl;
Vector<stud>::iterator up;
long long seed=high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
std::uniform_real_distribution<double> dist(1.0, 100000.0);
std::uniform_real_distribution<double> dist2(1.0, 10.0);
bool sortingmvid(const stud student1, const stud student2){
    if(student1.getmvid()<student2.getmvid())
        return true;
    else if(student1.getmvid()>student2.getmvid())
        return false;
    else if(student1.getmvid()==student2.getmvid())
        return false;
}
bool sortingvid(const stud student1, const stud student2){
        if (student1.getvid()< student2.getvid())
            return true;
        else if (student1.getvid() > student2.getvid())
            return false;
        else if(student1.getvid()==student2.getvid())
            return false;

}
void split(char pchoice, char strat, Vector<stud>::iterator &up){
    if (strat == 'a'){
        mldc.reserve(v.getnamenum()/2);
        L_laivs.reserve(v.getnamenum()/2);
        if(pchoice=='v'){
            if(pchoice=='v')
                up=stable_partition(students.begin(),students.end(),[](stud v) {return v.getvid()<test.getvid();});}
            else if(pchoice=='m')
                up=stable_partition(students.begin(),students.end(),[](stud v) {return v.getmvid()<test.getmvid();});
        mldc.shrink_to_fit();
        L_laivs.shrink_to_fit();
    }
    else if(strat=='b'){
        if(pchoice=='v'){
            if(pchoice=='v')
                up=stable_partition(students.begin(),students.end(),[](stud v) {return v.getvid()<test.getvid();});}
        else if(pchoice=='m')
            up=stable_partition(students.begin(),students.end(),[](stud v) {return v.getmvid()<test.getmvid();});}
    else if(strat == 'c'){
    if(pchoice=='v'){
    up=std::upper_bound(students.begin(),students.end(),test,less_than_vid());}
    else if (pchoice=='m'){
        up=std::upper_bound(students.begin(),students.end(),test,less_than_mvid());}}
   /* else if(strat=='d'){
        if (v.getissamiai()!='k'){printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
        v.setkiec();
        while(v.getkiec()!='k'&&v.getkiec()!='m'){
            printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/ i prieki perkelti [k]ietus\n");
            v.setkiec();
        }}
        if(v.getkiec()=='m')
            minksti=raskMinkstus(students,pchoice);
        else if(v.getkiec()=='k')
            minksti=raskKietus(students,pchoice);
    }*/
}
void splitd(char pchoice, char strat, std::deque<stud>::iterator &upd){
    if(strat=='a'){
        if(pchoice=='v')
        upd=stable_partition(studentsd.begin(),studentsd.end(),[](stud v) {return v.getvid()<test.getvid();});
        else if(pchoice=='m')
            upd=stable_partition(studentsd.begin(),studentsd.end(),[](stud v) {return v.getmvid()<test.getmvid();});}
    else if(strat=='b'){
        if(pchoice=='v'){
            if(pchoice=='v')
                upd=stable_partition(studentsd.begin(),studentsd.end(),[](stud v) {return v.getvid()<test.getvid();});}
            else if(pchoice=='m')
                upd=stable_partition(studentsd.begin(),studentsd.end(),[](stud v) {return v.getmvid()<test.getmvid();});}
    else if (strat=='c'){
    if(pchoice=='v'){
        upd=std::upper_bound(studentsd.begin(),studentsd.end(),test,less_than_vid());}
    else if (pchoice=='m'){
        upd=std::upper_bound(studentsd.begin(),studentsd.end(),test,less_than_mvid());}
    }
    else if(strat=='d'){
       if(v.getissamiai()!='k') {printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
        v.setkiec();
        while(v.getkiec()!='k'&&v.getkiec()!='m'){
            printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/ i prieki perkelti [k]ietus\n");
            v.setkiec();
        }}
        if(v.getkiec()=='m')
            minkstid=raskMinkstusd(studentsd,pchoice);
        else if(v.getkiec()=='k')
                minkstid=raskKietusd(studentsd,pchoice);

    }
}
void splitl(char pchoice, char strat, std::list<stud>::iterator &upl){
    if (strat=='a'){
        if(pchoice=='v'){
            if(pchoice=='v')
                upl=stable_partition(studentsl.begin(),studentsl.end(),[](stud v) {return v.getvid()<test.getvid();});}
            else if(pchoice=='m')
                upl=stable_partition(studentsl.begin(),studentsl.end(),[](stud v) {return v.getmvid()<test.getmvid();});}
    else if(strat=='b'){
        if(pchoice=='v'){
            if(pchoice=='v')
                upl=stable_partition(studentsl.begin(),studentsl.end(),[](stud v) {return v.getvid()<test.getvid();});}
            else if(pchoice=='m')
                upl=stable_partition(studentsl.begin(),studentsl.end(),[](stud v) {return v.getmvid()<test.getmvid();});}
    else if(strat=='c'){
    if(pchoice=='v'){
        upl=std::upper_bound(studentsl.begin(),studentsl.end(),test,less_than_vid());}
    else if (pchoice=='m'){
        upl=std::upper_bound(studentsl.begin(),studentsl.end(),test,less_than_mvid());}
    }
}
stud Userinput() {
    stud student;
    string tempname;
    string tempsurname;
    int tempex;
    int nd = 1;
    printf("Iveskite studento varda\n");
    v.setmsg("Klaida ivedant studento varda, bandykite is naujo");
    cin >> tempname;
    handlename(tempname);
    student.setname(tempname);
    printf("Iveskite studento pavarde\n");
    v.setmsg("Klaida ivedant studento pavarde, bandykite is naujo");
    cin >> tempsurname;
    handlename(tempsurname);
    student.setsurname(tempsurname);
    printf("Iveskite studento egzamino ivertinima\n");
    v.setmsg("Klaida ivedant studento egzamino ivertinima, bandykite is naujo\n");
    cin >> tempex;
    handleinput(tempex, v.getmsg());
    if(tempex<0||tempex>10){
        printf("Ivestas egzamino pazymys iseina is pazymio ribu, egzamino ivertinimas nulinamas\n");
        tempex=0;
    }
    student.setex(tempex);
    printf("Iveskite studento namu darbu pazymius, skaiciaus -1 ivestis uzbaigia ivesti\n");
    while (nd != -1) {
        v.setmsg("Klaida ivedant studento namu darbu ivertinima, bandykite is naujo (-1 baigia ivesti)");
        cin >> nd;
        handleinput(nd, v.getmsg());
        if (nd >= 0 && nd < 11)
        student.setnd(nd);
        else if (nd > 10 || nd < -1)
            printf("\n Ivesta netinkama reiksme, teskite pildyma ivesdami skaiciu is intervalo [0;10] arba iveskite -1 (baigti) \n");


    }
    return student;
}
stud GenStudent() {
    stud student;
    v.setmsg("Ivedete ne skaiciu, bandykite is naujo (0 baigia ivesti)");
    int nd = 1;
    int temp;
    string tempname;
    string tempsurname;
    int tempex;
    int num =dist(mt);
    tempname = "Vardas" + std::to_string(num);
    student.setname(tempname);
    printf("Studento vardas: %s\n", tempname.c_str());
    tempsurname = "Pavarde" + std::to_string(num);
    student.setsurname(tempsurname);
    printf("Studento pavarde: %s\n", tempsurname.c_str());
    student.setex(dist2(mt));
    printf("Studento egzamino ivertinimas: %d \n", student.getex());
    printf("Iveskite bet koki  skaiciu, kad sugeneruotumete pazymi,  skaicius 0 ivestis uzbaigia ivesti\n");
    while (nd != 0) {
        cin >> nd;
            handleinput(nd, v.getmsg());
        temp = nd;
        nd = dist2(mt);
        printf("Sugeneruotas pazymys: %d\n", nd);
        student.setnd(nd);
        nd = temp;
    }
    if(student.getndsize()>1)
    student.pushb();
    return student;
}
void readfile(bool & isempty, int &readcount) {
    std::ifstream fd("kursiokai.txt");
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
        students.push_back(temp);
        temp={};
    }
    if (v.linecount == 1)
        isempty = true;
    else
        readcount++;
    fd.close();
}
void Genstudent(int gensize){
    t.reset();
    v.setdiff(0);
    v.setnamenum(int(round(pow(10,gensize))));
    v.setfilename(std::to_string(v.getnamenum())+"studentu");
    fv.open((v.getfilename()+".txt").c_str());
    if(fv.fail()){
        printf("Failas %s nerastas/neisejo sukurti",v.getfilename().c_str());
        fv.clear();}
    else {
    if(v.getissamiai()!='k'){
        v.setdiff(t.elapsed());
        printf("Kiek namu darbu pazymiu generuoti studentu faile %s ?\n", v.getfilename().c_str());
        v.setndcount();
        v.setmsg("Ivestis neteisinga, bandykite dar karta/ namu darbu kiekis nepriklauso intervalui [1;1000000]\n");
        while(v.getndcount()<1||v.getndcount()>1000000){
            cin.setstate(std::ios_base::failbit);
            handlend(v.getmsg());}
        handlend(v.getmsg());
        t.reset();}
        for (int i = 0; i < v.getnamenum()+1; i++) {
            v.setnum(dist(mt));
            if (i == 0) {
                fv<<"Pavarde"<<setw(27)<<"Vardas"<<setw(27);
                for (int j = 1; j <= v.getndcount(); j++) {
                    fv<<"ND"<<j<<setw(4);
                }
                fv<<" Egzaminas\n";
            } else {
                fv<<"Pavarde"<<v.getnum()<<setw(22)<<"Vardas"<<v.getnum()<<setw(21);
                for (int j = 1; j <= v.getndcount(); j++) {
                    fv<<int(dist2(mt))<<setw(5);
                }
                fv<<int(dist2(mt))<<"\n";
            }
        }
        fv.close();
        v.setdiff(v.getdiff()+t.elapsed());
    }
}
void splitnprint(char pchoice, char strat){
    if(strat!='d'){
    t.reset();
    vnames(students);
    if(pchoice=='v'){
        vcalc(students,pchoice);
        if(strat=='c')
        std::sort(students.begin(),students.end(),sortingvid);
        split(pchoice,strat, up);
        if(strat=='a'){
            v.setsar('m');
            Vector<stud>mldc;
            std::move(up,students.end(),std::back_inserter(mldc));
            vprinttofile(mldc,pchoice,v.getsar());
            v.setsar('v');
            Vector<stud>L_laivs;
            std::move(students.begin(),up,std::back_inserter(L_laivs));
            vprinttofile(L_laivs,pchoice,v.getsar());
            mldc.clear();
            L_laivs.clear();}
        else{
            v.setsar('m');
            Vector<stud>mldcstudents;
            std::copy(up,students.end(),std::back_inserter(mldcstudents));
            vprinttofile(mldcstudents,pchoice,v.getsar());
            v.setsar('v');
            students.resize((students.size()-mldcstudents.size()));
            vprinttofile(students,pchoice,v.getsar());}
    }
    else if(pchoice=='m'){
        vcalc(students,pchoice);
        if(strat=='c')
        std::sort(students.begin(),students.end(),sortingmvid);
        split(pchoice,strat, up);
        if(strat=='a'){
            v.setsar('m');
            Vector<stud>mldc;
            std::move(up,students.end(),std::back_inserter(mldc));
            vprinttofile(mldc,pchoice,v.getsar());
            v.setsar('v');
            Vector<stud>L_laivs;
            std::move(students.begin(),up,std::back_inserter(L_laivs));
            vprinttofile(L_laivs,pchoice,v.getsar());
            mldc.clear();
            L_laivs.clear();}
        else{
        v.setsar('m');
        Vector<stud>mldcstudents;
        std::copy(up,students.end(),std::back_inserter(mldcstudents));
        vprinttofile(mldcstudents,pchoice,v.getsar());
        v.setsar('v');
        students.resize((students.size()-mldcstudents.size()));
        vprinttofile(students,pchoice,v.getsar());}

    }
    v.setdiff(t.elapsed());}
    else if (strat=='d'){
        vnames(students);
        vcalc(students,pchoice);
        split(pchoice,strat, up);
        v.setsar('m');
        vprinttofile(students,pchoice,v.getsar());
        v.setsar('v');
        vprinttofile(minksti,pchoice,v.getsar());
    }
}
void splitnprintd( char pchoice, char strat){
    if(strat!='d'){
    t.reset();
    names(studentsd);
    if(pchoice=='v'){
        calc(studentsd,pchoice);
        if(strat=='c')
        sort(studentsd.begin(),studentsd.end(),sortingvid);
        splitd(pchoice,strat, upd);
        if(strat=='a'){
            v.setsar('m');
            deque<stud>mldcd(upd,studentsd.end());
            printtofile(mldcd,pchoice,v.getsar());
            v.setsar('v');
            deque<stud>L_laivsd(studentsd.begin(), upd);
            printtofile(L_laivsd,pchoice,v.getsar());
            mldcd.clear();
            L_laivsd.clear();}
        else{
        v.setsar('m');
        deque<stud>mldcstudentsd(upd,studentsd.end());
        printtofile(mldcstudentsd,pchoice,v.getsar());
        v.setsar('v');
        studentsd.resize((studentsd.size()-mldcstudentsd.size()));
        printtofile(studentsd,pchoice,v.getsar());}
    }
    else if(pchoice=='m'){
        calc(studentsd,pchoice);
        if(strat=='c')
        sort(studentsd.begin(),studentsd.end(),sortingmvid);
        splitd(pchoice, strat, upd);
        if(strat=='a'){
            v.setsar('m');
            deque<stud>mldcd(upd,studentsd.end());
            printtofile(mldcd,pchoice,v.getsar());
            v.setsar('v');
            deque<stud>L_laivsd(studentsd.begin(), upd);
            printtofile(L_laivsd,pchoice,v.getsar());
            mldcd.clear();
            L_laivsd.clear();}
        else{
        v.setsar('m');
        deque<stud>mldcstudentsd(upd,studentsd.end());
        printtofile(mldcstudentsd,pchoice,v.getsar());
        v.setsar('v');
        studentsd.resize((studentsd.size()-mldcstudentsd.size()));
        printtofile(studentsd,pchoice,v.getsar());}

    }
    v.setdiff(t.elapsed());}
    else if (strat=='d'){
        names(studentsd);
            calc(studentsd,pchoice);
            splitd(pchoice,strat, upd);
        v.setsar('m');
        printtofile(studentsd,pchoice,v.getsar());
        v.setsar('v');
        printtofile(minkstid,pchoice,v.getsar());
    }
}
void splitnprintl( char pchoice, char strat){
   t.reset();
    names(studentsl);
    if(pchoice=='v'){
        calc(studentsl,pchoice);
        if(strat=='c')
        studentsl.sort(sortingvid);
        splitl(pchoice, strat, upl);
        if(strat=='a'){
            v.setsar('m');
            mldcl.splice(mldcl.begin(),studentsl,upl,studentsl.end());
            printtofile(mldcl,pchoice,v.getsar());
            v.setsar('v');
            list<stud>L_laivsl(studentsl.begin(), studentsl.end());
            printtofile(L_laivsl,pchoice,v.getsar());
            mldcl.clear();
            L_laivsl.clear();}
        else{
        v.setsar('m');
        mldcstudentsl.splice(mldcstudentsl.begin(),studentsl,upl,studentsl.end());
        printtofile(mldcstudentsl,pchoice,v.getsar());
        v.setsar('v');
        printtofile(studentsl,pchoice,v.getsar());}
    }
    else if(pchoice=='m'){
        calc(studentsl,pchoice);
        if(strat=='c')
        studentsl.sort(sortingmvid);
        splitl(pchoice, strat, upl);
        if(strat=='a'){
            v.setsar('m');
            mldcl.splice(mldcl.begin(),studentsl,upl,studentsl.end());
            printtofile(mldcl,pchoice,v.getsar());
            v.setsar('v');
            list<stud>L_laivsl(studentsl.begin(), studentsl.end());
            printtofile(L_laivsl,pchoice,v.getsar());
        mldcl.clear();
        L_laivsl.clear();}
        else{
        v.setsar('m');
        mldcstudentsl.splice(mldcstudentsl.begin(),studentsl,upl,studentsl.end());
        printtofile(mldcstudentsl,pchoice,v.getsar());
        v.setsar('v');
        printtofile(studentsl,pchoice,v.getsar());}

    }
    v.setdiff(t.elapsed());


}