//
// Created by Mindaugas K on 2/25/2019.
//
#include "Mutual.h"
#include "Input.h"
int namenum;
int num=0;
std::deque<stud>::iterator upd;
std::list<stud>::iterator upl;
Vector<stud>::iterator up;
char sar;
long long seed=high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
std::uniform_real_distribution<double> dist(1.0, 100000.0);
std::uniform_real_distribution<double> dist2(1.0, 10.0);
bool sortingmvid(const stud student1, const stud student2){
    if(student1.mvid<student2.mvid)
        return true;
    else if(student1.mvid>student2.mvid)
        return false;
    else if(student1.mvid==student2.mvid)
        return false;
}
bool sortingvid(const stud student1, const stud student2){
        if (student1.vid2 < student2.vid2)
            return true;
        else if (student1.vid2 > student2.vid2)
            return false;
        else if(student1.vid2==student2.vid2)
            return false;

}
void split(char pchoice, char strat, Vector<stud>::iterator &up){
    test.vid2=4.999999999;
    test.mvid=4.999999999;
    if (strat == 'a'){
        mldc.reserve(namenum/2);
        L_laivs.reserve(namenum/2);
        if(pchoice=='v'){
            if(pchoice=='v')
                up=stable_partition(students.begin(),students.end(),[](auto v) {return v.vid2<test.vid2;});}
            else if(pchoice=='m')
                up=stable_partition(students.begin(),students.end(),[](auto v) {return v.mvid<test.mvid;});
        mldc.shrink_to_fit();
        L_laivs.shrink_to_fit();
    }
    else if(strat=='b'){
        if(pchoice=='v'){
            if(pchoice=='v')
                up=stable_partition(students.begin(),students.end(),[](auto v) {return v.vid2<test.vid2;});}
        else if(pchoice=='m')
            up=stable_partition(students.begin(),students.end(),[](auto v) {return v.mvid<test.mvid;});}
    else if(strat == 'c'){
    if(pchoice=='v'){
    up=std::upper_bound(students.begin(),students.end(),test,stud::less_than_vid2());}
    else if (pchoice=='m'){
        up=std::upper_bound(students.begin(),students.end(),test,stud::less_than_mvid());}}
   /* else if(strat=='d'){
        if (issamiai!='k'){printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
        cin>>kiec;
        while(kiec!='k'&&kiec!='m'){
            printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/ i prieki perkelti [k]ietus\n");
            cin>>kiec;
        }}
        if(kiec=='m')
            minksti=raskMinkstus(students,pchoice);
        else if(kiec=='k')
            minksti=raskKietus(students,pchoice);
    }*/
}
void splitd(char pchoice, char strat, std::deque<stud>::iterator &upd){
    test.vid2=4.999999999;
    test.mvid=4.999999999;
    if(strat=='a'){
        if(pchoice=='v')
        upd=stable_partition(studentsd.begin(),studentsd.end(),[](auto v) {return v.vid2<test.vid2;});
        else if(pchoice=='m')
            upd=stable_partition(studentsd.begin(),studentsd.end(),[](auto v) {return v.mvid<test.mvid;});}
    else if(strat=='b'){
        if(pchoice=='v'){
            if(pchoice=='v')
                upd=stable_partition(studentsd.begin(),studentsd.end(),[](auto v) {return v.vid2<test.vid2;});}
            else if(pchoice=='m')
                upd=stable_partition(studentsd.begin(),studentsd.end(),[](auto v) {return v.mvid<test.mvid;});}
    else if (strat=='c'){
    if(pchoice=='v'){
        upd=std::upper_bound(studentsd.begin(),studentsd.end(),test,stud::less_than_vid2());}
    else if (pchoice=='m'){
        upd=std::upper_bound(studentsd.begin(),studentsd.end(),test,stud::less_than_mvid());}
    }
    else if(strat=='d'){
       if(issamiai!='k') {printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
        cin>>kiec;
        while(kiec!='k'&&kiec!='m'){
            printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/ i prieki perkelti [k]ietus\n");
            cin>>kiec;
        }}
        if(kiec=='m')
            minkstid=raskMinkstusd(studentsd,pchoice);
            else if(kiec=='k')
                minkstid=raskKietusd(studentsd,pchoice);

    }
}
void splitl(char pchoice, char strat, std::list<stud>::iterator &upl){
    test.vid2=4.999999999;
    test.mvid=4.999999999;
    if (strat=='a'){
        if(pchoice=='v'){
            if(pchoice=='v')
                upl=stable_partition(studentsl.begin(),studentsl.end(),[](auto v) {return v.vid2<test.vid2;});}
            else if(pchoice=='m')
                upl=stable_partition(studentsl.begin(),studentsl.end(),[](auto v) {return v.mvid<test.mvid;});}
    else if(strat=='b'){
        if(pchoice=='v'){
            if(pchoice=='v')
                upl=stable_partition(studentsl.begin(),studentsl.end(),[](auto v) {return v.vid2<test.vid2;});}
            else if(pchoice=='m')
                upl=stable_partition(studentsl.begin(),studentsl.end(),[](auto v) {return v.mvid<test.mvid;});}
    else if(strat=='c'){
    if(pchoice=='v'){
        upl=std::upper_bound(studentsl.begin(),studentsl.end(),test,stud::less_than_vid2());}
    else if (pchoice=='m'){
        upl=std::upper_bound(studentsl.begin(),studentsl.end(),test,stud::less_than_mvid());}
    }
}
stud Userinput() {
    stud student;
    student.nd.reserve(200);
    int nd = 1;
    printf("Iveskite studento varda\n");
    msg = "Klaida ivedant studento varda, bandykite is naujo";
    cin >> student.name;
    handlename(student.name);
    printf("Iveskite studento pavarde\n");
    msg = "Klaida ivedant studento pavarde, bandykite is naujo";
    cin >> student.surname;
    handlename(student.surname);
    printf("Iveskite studento egzamino ivertinima\n");
    msg = "Klaida ivedant studento egzamino ivertinima, bandykite is naujo\n";
    cin >> student.ex;
    handleinput(student.ex, msg);
    if(student.ex<0||student.ex>10){
        printf("Ivestas egzamino pazymys iseina is pazymio ribu, egzamino ivertinimas nulinamas\n");
        student.ex=0;
    }
    printf("Iveskite studento namu darbu pazymius, skaiciaus -1 ivestis uzbaigia ivesti\n");
    while (nd != -1) {
        msg = "Klaida ivedant studento namu darbu ivertinima, bandykite is naujo (-1 baigia ivesti)";
        cin >> nd;
        handleinput(nd, msg);
        if (nd >= 0 && nd < 11) {
            student.sum += nd;
            try{
            student.nd.push_back(nd);}
            catch(std::exception e){
                printf("Perzengtos %d studento namu darbu vektoriaus ribos",students.size()+1);
            }
        }
        else if (nd > 10 || nd < -1)
            printf("\n Ivesta netinkama reiksme, teskite pildyma ivesdami skaiciu is intervalo [0;10] arba iveskite -1 (baigti) \n");


    }
    return student;
}
stud GenStudent() {
    stud student;
    student.nd.reserve(200);
    msg = "Ivedete ne skaiciu, bandykite is naujo (0 baigia ivesti)";
    int nd = 1;
    int temp;
    int num =dist(mt);
    student.name = "Vardas" + std::to_string(num);
    printf("Studento vardas: %s\n", student.name.c_str());
    student.surname = "Pavarde" + std::to_string(num);
    printf("Studento pavarde: %s\n", student.surname.c_str());
    student.ex = dist2(mt);
    printf("Studento egzamino ivertinimas: %d \n", student.ex);
    printf("Iveskite bet koki  skaiciu, kad sugeneruotumete pazymi,  skaiciaus 0 ivestis uzbaigia ivesti\n");
    while (nd != 0) {
        cin >> nd;
            handleinput(nd, msg);
        temp = nd;
        nd = dist2(mt);
        printf("Sugeneruotas pazymys: %d\n", nd);
        student.sum += nd;
        try{
        student.nd.push_back(nd);}
        catch(std::exception e){
            printf("Perzengtos %d studento namu darbu vektoriaus ribos\n",students.size()+1);}
        nd = temp;
    }
    return student;
}
void readfile(bool & isempty, int &readcount) {
    std::ifstream fd("kursiokai.txt");
    int i = students.size();
    int linecount = 1;
    int countnd;
    int tempnd;
    bool fsio;
    string line;
    std::getline(fd, line);
    while (std::getline(fd, line)) {
        fsio = false;
        countnd = 0;
        std::istringstream scan(line);
        try{
            students.push_back(stud());}
        catch(std::exception e){
            printf("Perzengtos studentu vektoriaus ribos\n");
        }
        students[i].nd.reserve(200);
        scan >> students[i].surname;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("kursiokai.txt faile ivyko klaida nuskaitant %d studento pavarde\n", linecount);
        }
        scan >> students[i].name;
        if (scan.fail()) {
            scan.clear();
            scan.ignore(4);
            printf("kursiokai.txt faile ivyko klaida nuskaitant %d studento varda\n", linecount);
        }
        while (scan) {
            scan >> tempnd;
            if (scan.fail()) {
                do {
                    scan.clear();
                    scan.ignore(4);
                    printf("kursiokai.txt faile ivyko klaida nuskaitant %d studento %d pazymi\n", linecount,
                           countnd + 1);
                    try{
                        students[i].nd.push_back(0);}
                    catch(std::exception e){
                        printf("Perzengtos %d studento namu darbu vektoriaus ribos\n",linecount);
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
                students[i].sum += tempnd;
                try{
                    students[i].nd.push_back(tempnd);}
                catch(std::exception e){
                    printf("Perzengtos %d studento namu darbu vektoriaus ribos\n",linecount);
                }
                countnd++;
            }
            if (scan.peek() == '\n' || scan.peek() == EOF)
                break;

        }
        students[i].ex = students[i].nd.back();
        students[i].sum-=students[i].nd.back();
        students[i].nd.pop_back();
        linecount++;
        i++;

    }
    if (linecount == 1)
        isempty = true;
    else
        readcount++;
    fd.close();
}
void Genstudent(int gensize){
    start=high_resolution_clock::now();
    diff={};
    namenum=int(round(pow(10,gensize)));
    filename=std::to_string(namenum)+"studentu";
    fv.open((filename+".txt").c_str());
    if(fv.fail()){
        printf("Failas %s nerastas/neisejo sukurti",filename.c_str());
        fv.clear();}
    else {
    if(issamiai!='k'){
        end=high_resolution_clock::now();
        diff=end-start;
        printf("Kiek namu darbu pazymiu generuoti studentu faile %s ?\n", filename.c_str());
        cin >> ndcount;
        ::msg = "Ivestis neteisinga, bandykite dar karta/ namu darbu kiekis nepriklauso intervalui [1;1000000]\n";
        while(ndcount<1||ndcount>1000000){
            cin.setstate(std::ios_base::failbit);
            handleinput(ndcount, msg);}
        handleinput(ndcount, msg);
        start=high_resolution_clock::now();}
        for (int i = 0; i < namenum+1; i++) {
            num = dist(mt);
            if (i == 0) {
                fv<<"Pavarde"<<setw(27)<<"Vardas"<<setw(27);
                for (int j = 1; j <= ndcount; j++) {
                    fv<<"ND"<<j<<setw(4);
                }
                fv<<" Egzaminas\n";
            } else {
                fv<<"Pavarde"<<num<<setw(22)<<"Vardas"<<num<<setw(21);
                for (int j = 1; j <= ndcount; j++) {
                    fv<<int(dist2(mt))<<setw(5);
                }
                fv<<int(dist2(mt))<<"\n";
            }
        }
        fv.close();
        end=high_resolution_clock::now();
        diff=diff+(end-start);
    }
}
void splitnprint(char pchoice, char strat){
    if(strat!='d'){
    start=high_resolution_clock::now();
    names(students);
    if(pchoice=='v'){
        calc(students,pchoice);
        if(strat=='c')
        std::sort(students.begin(),students.end(),sortingvid);
        split(pchoice,strat, up);
        if(strat=='a'){
            sar='m';
            Vector<stud>mldc;
            std::copy(up,students.end(),std::back_inserter(mldc));
            printtofile(mldc,pchoice,sar);
            sar='v';
            Vector<stud>L_laivs;
            std::copy(students.begin(),up,std::back_inserter(L_laivs));
            printtofile(L_laivs,pchoice,sar);
            mldc.clear();
            L_laivs.clear();}
        else{
            sar='m';
            Vector<stud>mldcstudents;
            std::copy(up,students.end(),std::back_inserter(mldc));
            printtofile(mldcstudents,pchoice,sar);
            sar='v';
            students.resize((students.size()-mldcstudents.size()));
            printtofile(students,pchoice,sar);}
    }
    else if(pchoice=='m'){
        calc(students,pchoice);
        if(strat=='c')
        std::sort(students.begin(),students.end(),sortingmvid);
        split(pchoice,strat, up);
        if(strat=='a'){
            sar='m';
            Vector<stud>mldc;
            std::copy(up,students.end(),std::back_inserter(mldc));
            printtofile(mldc,pchoice,sar);
            sar='v';
            Vector<stud>L_laivs;
            std::copy(students.begin(),up,std::back_inserter(L_laivs));
            printtofile(L_laivs,pchoice,sar);
            mldc.clear();
            L_laivs.clear();}
        else{
        sar='m';
        Vector<stud>mldcstudents;
            std::copy(up,students.end(),std::back_inserter(mldc));
        printtofile(mldcstudents,pchoice,sar);
        sar='v';
        students.resize((students.size()-mldcstudents.size()));
        printtofile(students,pchoice,sar);}

    }
    end=high_resolution_clock::now();
    diff=end-start;}
    else if (strat=='d'){
        names(students);
        calc(students,pchoice);
        split(pchoice,strat, up);
        sar='m';
        printtofile(students,pchoice,sar);
        sar='v';
        printtofile(minksti,pchoice,sar);
    }
}
void splitnprintd( char pchoice, char strat){
    if(strat!='d'){
    start=high_resolution_clock::now();
    names(studentsd);
    if(pchoice=='v'){
        calc(studentsd,pchoice);
        if(strat=='c')
        sort(studentsd.begin(),studentsd.end(),sortingvid);
        splitd(pchoice,strat, upd);
        if(strat=='a'){
            sar='m';
            deque<stud>mldcd(upd,studentsd.end());
            printtofile(mldcd,pchoice,sar);
            sar='v';
            deque<stud>L_laivsd(studentsd.begin(), upd);
            printtofile(L_laivsd,pchoice,sar);
            mldcd.clear();
            L_laivsd.clear();}
        else{
        sar='m';
        deque<stud>mldcstudentsd(upd,studentsd.end());
        printtofile(mldcstudentsd,pchoice,sar);
        sar='v';
        studentsd.resize((studentsd.size()-mldcstudentsd.size()));
        printtofile(studentsd,pchoice,sar);}
    }
    else if(pchoice=='m'){
        calc(studentsd,pchoice);
        if(strat=='c')
        sort(studentsd.begin(),studentsd.end(),sortingmvid);
        splitd(pchoice, strat, upd);
        if(strat=='a'){
            sar='m';
            deque<stud>mldcd(upd,studentsd.end());
            printtofile(mldcd,pchoice,sar);
            sar='v';
            deque<stud>L_laivsd(studentsd.begin(), upd);
            printtofile(L_laivsd,pchoice,sar);
            mldcd.clear();
            L_laivsd.clear();}
        else{
        sar='m';
        deque<stud>mldcstudentsd(upd,studentsd.end());
        printtofile(mldcstudentsd,pchoice,sar);
        sar='v';
        studentsd.resize((studentsd.size()-mldcstudentsd.size()));
        printtofile(studentsd,pchoice,sar);}

    }
    end=high_resolution_clock::now();
    diff=end-start;}
    else if (strat=='d'){
        names(studentsd);
            calc(studentsd,pchoice);
            splitd(pchoice,strat, upd);
        sar='m';
        printtofile(studentsd,pchoice,sar);
        sar='v';
        printtofile(minkstid,pchoice,sar);
    }
}
void splitnprintl( char pchoice, char strat){
    start=high_resolution_clock::now();
    names(studentsl);
    if(pchoice=='v'){
        calc(studentsl,pchoice);
        if(strat=='c')
        studentsl.sort(sortingvid);
        splitl(pchoice, strat, upl);
        if(strat=='a'){
            sar='m';
            mldcl.splice(mldcl.begin(),studentsl,upl,studentsl.end());
            printtofile(mldcl,pchoice,sar);
            sar='v';
            list<stud>L_laivsl(studentsl.begin(), studentsl.end());
            printtofile(L_laivsl,pchoice,sar);
            mldcl.clear();
            L_laivsl.clear();}
        else{
        sar='m';
        mldcstudentsl.splice(mldcstudentsl.begin(),studentsl,upl,studentsl.end());
        printtofile(mldcstudentsl,pchoice,sar);
        sar='v';
        printtofile(studentsl,pchoice,sar);}
    }
    else if(pchoice=='m'){
        calc(studentsl,pchoice);
        if(strat=='c')
        studentsl.sort(sortingmvid);
        splitl(pchoice, strat, upl);
        if(strat=='a'){
            sar='m';
            mldcl.splice(mldcl.begin(),studentsl,upl,studentsl.end());
            printtofile(mldcl,pchoice,sar);
            sar='v';
            list<stud>L_laivsl(studentsl.begin(), studentsl.end());
            printtofile(L_laivsl,pchoice,sar);
        mldcl.clear();
        L_laivsl.clear();}
        else{
        sar='m';
        mldcstudentsl.splice(mldcstudentsl.begin(),studentsl,upl,studentsl.end());
        printtofile(mldcstudentsl,pchoice,sar);
        sar='v';
        printtofile(studentsl,pchoice,sar);}

    }
    end=high_resolution_clock::now();
    diff=end-start;


}