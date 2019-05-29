#include "./Headers/Mutual.h"
#include "./Headers/Input.h"
#include "./Headers/Output.h"
int main() {
    v.setpap(false);
    v.setstrat2('c');
    v.setnum(0);
    int ind;
    int choice=0;
    int specchoice =-1;
    int printfail=0;
    int readcount=0;
    bool isempty=false;
    printf("Pasirinkite programos rezima: [i]ssamus, [k]onkretus ?");
    v.setissamiai();
    while(v.getissamiai()!='i'&&v.getissamiai()!='k'){
        printf("Neteisinga ivestis, galimi variantai: [i]ssamus, [k]onkretus\n");
        v.setissamiai();
    }
    students.reserve(100);
    while (choice == 0 ) {
        if (specchoice == -1) {
            printf("Saugomi %d studentu(o) duomenys, pasirinkite ka daryti toliau:\n", students.size());
            printf("1. Ivesti studenta paciam\n");
            printf("2. Generuoti studenta\n");
            printf("3. Skaityti is failo\n");
            /*printf("4. Atspausdinti (galutinis pagal nd mediana)\n");
            printf("5. Atspausdinti (galutinis pagal nd vidurki)\n");*/
            printf("6. Generuoti studentu faila (v1.5)\n");
            printf("7. Skelti studentus i maladec ir L-laivo sarasus, atspausdinti\n");
            printf("8. push_back test (stud)");
            cin >> choice;
            if (choice!=1&&choice!=2&&choice!=3&&choice!=6&&choice!=7&&choice!=8) {
                do {
                    cin.clear();
                    cin.ignore(256,'\n');
                    printf("Ivestas netinkamas pasirinkimas, bandykite is naujo\n");
                    cin >> choice;
                } while (choice!=1&&choice!=2&&choice!=3&&choice!=6&&choice!=7&&choice!=8);

            }
        }
        switch (choice) {
            case 1:
                try{
                students.push_back(Userinput());}
                catch(std::exception e){
                    printf("Perzengtos studentu vektoriaus ribos\n");
                }
                choice = 0;
                break;
            case 2:
                try{
                students.push_back(GenStudent());}
                catch(std::exception e){
                    printf("Perzengtos studentu vektoriaus ribos\n");
                }
                choice = 0;
                break;
            case 3:
                if (readcount == 0) {
                    readfile(isempty, readcount);
                }
                else
                    printfail=3;
                choice = 0;
                if (isempty)
                    printfail=32;
                    specchoice = 0;
                break;
            /*case 4:
                if (students.empty()) {
                    specchoice = 0;
                    choice = 0;
                    printfail=4;
                    break;
                }
                else {
                    std::sort(students.begin(), students.end(), sortingmvid);
                    print(students, 'm');
                    choice = -1;
                    break;
                }
            case 5:
                if (students.empty()) {
                    specchoice = 0;
                    printfail=4;
                    choice = 0;
                    break;
                }
                else {
                    std::sort(students.begin(), students.end(), sortingvid);
                    print(students, 'v');
                    choice = -1;
                    break;
                }*/
            case 6:
                Stratpick();
                if(v.getstrat()!='d'){
                STLpick(v.getpap());
                    ft.open("V1.5_laikai.txt");
                    (v.getSTL()=='v')?ft<<"Pasirinktas konteineris - vektorius\n":
                        (v.getSTL()=='d')?ft<<"Pasirinktas konteineris - dekas\n":
                        ft<<"Pasirinktas konteineris - listas\n";
                    if(v.getissamiai()=='k'){
                        printf("Kiek namu darbu pazymiu generuoti studentu failuose ?\n");
                        v.setndcount();
                        v.setmsg("Ivestis neteisinga, bandykite dar karta/ namu darbu kiekis nepriklauso intervalui [1;1000000]\n");
                        while(v.getndcount()<1||v.getndcount()>1000000){
                            cin.setstate(std::ios_base::failbit);
                            handlend(v.getmsg());}
                        handlend(v.getmsg());

                        printf("Galutini pazymi studentu failuose skaiciuoti pagal [v]idurki/[m]ediana ?\n");
                        v.setpchoice();
                        while(v.getpchoice()!='v'&&v.getpchoice()!='m'){
                            printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                            v.setpchoice();}
                    }
                    for(int i=1;i<=6;i++){
                        students.clear();
                        studentsl.clear();
                        studentsd.clear();
                        mldcstudents.clear();
                        mldcstudentsl.clear();
                        mldcstudentsd.clear();
                        ft<<int(round(pow(10,i)))<<"studentu\n";
                        ft<<"--------------------------------\n";
                    Genstudent(i);
                    ft<<"Studentai sugeneruoti ir isvesti i faila per "<<v.getdiff()<<" s.\n";
                    if(v.getSTL()=='v')
                        students.reserve(v.getnamenum());
                       (v.getSTL()=='v')?vreadfile(students,v.getfilename()):
                        (v.getSTL()=='d')?readfile(studentsd,v.getfilename()):
                        readfile(studentsl,v.getfilename());
                        if(v.getSTL()=='v')
                            students.shrink_to_fit();
                            else if (v.getSTL()=='d')
                                studentsd.shrink_to_fit();
                    ft<<"Studentai nuskaityti is failo  "<<v.getfilename()<<" per "<<v.getdiff()<<" s.\n";
                    if(v.getissamiai()!='k'){
                    printf("Galutini pazymi %s faile skaiciuoti pagal [v]idurki/[m]ediana ?\n",v.getfilename().c_str());
                    v.setpchoice();
                    while(v.getpchoice()!='v'&&v.getpchoice()!='m'){
                        printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                        v.setpchoice();
                    }}(v.getSTL()=='v')?splitnprint(v.getpchoice(), v.getstrat()):
                        (v.getSTL()=='d')?splitnprintd( v.getpchoice(), v.getstrat()):
                        splitnprintl(v.getpchoice(), v.getstrat());
                    ft<<"Studentai perskelti i mldc ir L_laivo sarasus, bei atspausdinti atitinkamuose failuose per "<<v.getdiff()<<" s.\n";
                    ft<<"--------------------------------\n";
                        if(v.getissamiai()=='k')
                        printf("Darbas baigtas su failu %s \n", v.getsubname().c_str());
                    }
                    ft.close();
                    mldcstudents.clear();
                    students.clear();
                choice=-1;
                break;}
                else{
                    v.setpap(true);
                    STLpick(v.getpap());
                    if(v.getissamiai()=='k'){
                        printf("Kiek namu darbu pazymiu generuoti studentu failuose ?\n");
                        v.setndcount();
                        v.setmsg("Ivestis neteisinga, bandykite dar karta/ namu darbu kiekis nepriklauso intervalui [1;1000000]\n");
                        while(v.getndcount()<1||v.getndcount()>1000000){
                            cin.setstate(std::ios_base::failbit);
                            handlend(v.getmsg());}
                        handlend(v.getmsg());
                        printf("Galutini pazymi studentu failuose skaiciuoti pagal [v]idurki/[m]ediana ?\n");
                        v.setpchoice();
                        while(v.getpchoice()!='v'&&v.getpchoice()!='m'){
                            printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                            v.setpchoice();}
                        printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
                        v.setkiec();
                        while(v.getkiec()!='k'&&v.getkiec()!='m'){
                            printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/perkelti [k]ietus\n");
                            v.setkiec();
                        }
                    }
                    ft.open("Papildomos_uzduoties_laikai.txt");
                    (v.getSTL()=='v')?ft<<"Pasirinktas konteineris - vektorius\n":ft<<"Pasirinktas konteineris - dekas\n";
                    for(int i=1;i<=5;i++){
                        students.clear();
                        minksti.clear();
                        studentsd.clear();
                        minkstid.clear();
                        ft<<int(round(pow(10,i)))<<"studentu\n";
                        ft<<"--------------------------------\n";
                        Genstudent(i);
                        if(v.getSTL()=='v')
                            students.reserve(v.getnamenum());
                        (v.getSTL()=='v')?vreadfile(students,v.getfilename()):readfile(studentsd,v.getfilename());
                        if(v.getSTL()=='v')
                            students.shrink_to_fit();
                        else
                            studentsd.shrink_to_fit();
                        if(v.getissamiai()!='k') {
                            printf("Galutini pazymi %s faile skaiciuoti pagal [v]idurki/[m]ediana ?\n",
                                   v.getfilename().c_str());
                            v.setpchoice();
                            while (v.getpchoice() != 'v' && v.getpchoice() != 'm') {
                                printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                                v.setpchoice();
                            }
                        }(v.getSTL()=='v')?splitnprint(v.getpchoice(),v.getstrat()):splitnprintd(v.getpchoice(),v.getstrat());
                        if(v.getissamiai()=='k')
                        printf("Darbas baigtas su  %s \n", v.getsubname().c_str());
                        ft<<"Papildomos uzduoties split'inimo algoritmas uztruko "<<v.getdiff()<<" s.\n";
                        ft<<"--------------------------------\n";}
                    ft.close();
                    choice= -1;
                    break;
                }
            case 7:
                if (students.empty()) {
                    specchoice = 0;
                    choice = 0;
                    printfail=4;
                    break;
                }
                else {
                    Stratpick();
                    v.setfilename(std::to_string(students.size())+"kursioku");
                    printf("Galutini pazymi %s faile skaiciuoti pagal [v]idurki/[m]ediana ?\n",v.getfilename().c_str());
                    v.setpchoice();
                    while(v.getpchoice()!='v'&&v.getpchoice()!='m'){
                        printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                        v.setpchoice();
                    }
                   if(v.getstrat()=='d'&& v.getissamiai()=='k') {printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
                    v.setkiec();
                    while(v.getkiec()!='k'&&v.getkiec()!='m'){
                        printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/perkelti [k]ietus\n");
                        v.setkiec();
                    }}
                    splitnprint(v.getpchoice(), v.getstrat());
                    choice = -1;
                    break;
                }
            case 8:
            {
                Vector<stud>test2;
                std::vector<stud>test3;
                stud temp;
                int sz=1000000;
                t.reset();
                for(int i=0;i<sz;i++)
                    test2.push_back(temp);
                printf("idedant %d elementu i mano vektoriu push_back uztruko %lf s\n",sz,t.elapsed());
                t.reset();
                 for(int i=0;i<sz;i++)
                     test3.push_back(temp);
                 printf("idedant %d elementu i std vektoriu push_back uztruko %lf s\n",sz,t.elapsed());
                break;}

            default:
                switch(printfail){
                    case 3:
                        printf("Sis failas jau buvo nuskaitytas\n");
                        break;
                    case 32:
                        printf("Failas tuscias arba neegzistuoja\n");
                        break;
                    case 4:
                        printf("Bandote atspausdinti tuscia sarasa\n");
                        break;
                    
                }
                specchoice = -1;
                choice = 0;
                printfail=0;
        }
    }
    return 0;
}