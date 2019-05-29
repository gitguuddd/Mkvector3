#include "Mutual.h"
#include "Input.h"
#include "Output.h"
int main() {
    char STL;
    bool pap= false;
    char strat='c';
    int ind;
    int choice=0;
    int specchoice =-1;
    int printfail=0;
    int readcount=0;
    bool isempty=false;
    printf("Pasirinkite programos rezima: [i]ssamus, [k]onkretus ?");
    cin>>issamiai;
    while(issamiai!='i'&&issamiai!='k'){
        printf("Neteisinga ivestis, galimi variantai: [i]ssamus, [k]onkretus\n");
        cin>>issamiai;
    }
    while (choice == 0) {
        if (specchoice == -1) {
            printf("Saugomi %d studentu(o) duomenys, pasirinkite ka daryti toliau:\n", students.size());
            printf("1. Ivesti studenta paciam\n");
            printf("2. Generuoti studenta\n");
            printf("3. Skaityti is failo\n");
            /*printf("4. Atspausdinti (galutinis pagal nd mediana)\n");
            printf("5. Atspausdinti (galutinis pagal nd vidurki)\n");*/
            printf("6. Generuoti studentu faila (v1.0)\n");
            printf("7. Skelti studentus i maladec ir L-laivo sarasus, atspausdinti\n");
            printf("8. Atlikti grow() tyrima\n");
            printf("9. Atlikti push_back tyrima\n");
            cin >> choice;
            if (choice!=1&&choice!=2&&choice!=3&&choice!=6&&choice!=7&&choice!=8&&choice!=9) {
                do {
                    cin.clear();
                    cin.ignore(256,'\n');
                    printf("Ivestas netinkamas pasirinkimas, bandykite is naujo\n");
                    cin >> choice;
                } while (choice!=1&&choice!=2&&choice!=3&&choice!=6&&choice!=7&&choice!=8&&choice!=9);

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
                    printf("Perzengtos studentu vektoriaus riblos\n");
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
                    std::sort(students.begin(), students.end(), sorting);
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
                    std::sort(students.begin(), students.end(), sorting);
                    print(students, 'v');
                    choice = -1;
                    break;
                }*/
            case 6:
                Stratpick(strat);
                if(strat!='d'){
                STLpick(STL, pap);
                    ft.open("V1.0_laikai.txt");
                    (STL=='v')?ft<<"Pasirinktas konteineris - vektorius\n":
                        (STL=='d')?ft<<"Pasirinktas konteineris - dekas\n":
                        ft<<"Pasirinktas konteineris - listas\n";
                    if(issamiai=='k'){
                        printf("Kiek namu darbu pazymiu generuoti studentu failuose ?\n");
                        cin >> ndcount;
                        ::msg = "Ivestis neteisinga, bandykite dar karta/ namu darbu kiekis nepriklauso intervalui [1;1000000]\n";
                        while(ndcount<1||ndcount>1000000){
                            cin.setstate(std::ios_base::failbit);
                            handleinput(ndcount, msg);}
                        handleinput(ndcount, msg);

                        printf("Galutini pazymi studentu failuose skaiciuoti pagal [v]idurki/[m]ediana ?\n");
                        cin>>pchoice;
                        while(pchoice!='v'&&pchoice!='m'){
                            printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                            cin>>pchoice;}
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
                    ft<<"Studentai sugeneruoti ir isvesti i faila per "<<diff.count()<<" s.\n";
                    if(STL=='v')
                        students.reserve(namenum);
                       (STL=='v')?readfile(students,filename):
                        (STL=='d')?readfile(studentsd,filename):
                        readfile(studentsl,filename);
                        if(STL=='v')
                            students.shrink_to_fit();
                            else if (STL=='d')
                                studentsd.shrink_to_fit();
                    ft<<"Studentai nuskaityti is failo  "<<filename<<" per "<<diff.count()<<" s.\n";
                    if(issamiai!='k'){
                    printf("Galutini pazymi %s faile skaiciuoti pagal [v]idurki/[m]ediana ?\n",filename.c_str());
                    cin>>pchoice;
                    while(pchoice!='v'&&pchoice!='m'){
                        printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                        cin>>pchoice;
                    }}(STL=='v')?splitnprint(pchoice, strat):
                        (STL=='d')?splitnprintd( pchoice, strat):
                        splitnprintl(pchoice, strat);
                    ft<<"Studentai perskelti i mldc ir L_laivo sarasus, bei atspausdinti atitinkamuose failuose per "<<diff.count()<<" s.\n";
                    ft<<"--------------------------------\n";
                        if(issamiai=='k')
                        printf("Darbas baigtas su failu %s \n", subname.c_str());
                    }
                    ft.close();
                    mldcstudents.clear();
                    students.clear();
                choice=-1;
                break;}
                else{
                    pap=true;
                    STLpick(STL, pap);
                    if(issamiai=='k'){
                        printf("Kiek namu darbu pazymiu generuoti studentu failuose ?\n");
                        cin >> ndcount;
                        ::msg = "Ivestis neteisinga, bandykite dar karta/ namu darbu kiekis nepriklauso intervalui [1;1000000]\n";
                        while(ndcount<1||ndcount>1000000){
                            cin.setstate(std::ios_base::failbit);
                            handleinput(ndcount, msg);}
                        handleinput(ndcount, msg);

                        printf("Galutini pazymi studentu failuose skaiciuoti pagal [v]idurki/[m]ediana ?\n");
                        cin>>pchoice;
                        while(pchoice!='v'&&pchoice!='m'){
                            printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                            cin>>pchoice;}
                        printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
                        cin>>kiec;
                        while(kiec!='k'&&kiec!='m'){
                            printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/perkelti [k]ietus\n");
                            cin>>kiec;
                        }
                    }
                    ft.open("Papildomos_uzduoties_laikai.txt");
                    (STL=='v')?ft<<"Pasirinktas konteineris - vektorius\n":ft<<"Pasirinktas konteineris - dekas\n";
                    for(int i=1;i<=5;i++){
                        students.clear();
                        minksti.clear();
                        studentsd.clear();
                        minkstid.clear();
                        ft<<int(round(pow(10,i)))<<"studentu\n";
                        ft<<"--------------------------------\n";
                        Genstudent(i);
                        if(STL=='v')
                            students.reserve(namenum);
                        (STL=='v')?readfile(students,filename):readfile(studentsd,filename);
                        if(STL=='v')
                            students.shrink_to_fit();
                        else
                            studentsd.shrink_to_fit();
                        if(issamiai!='k') {
                            printf("Galutini pazymi %s faile skaiciuoti pagal [v]idurki/[m]ediana ?\n",
                                   filename.c_str());
                            cin >> pchoice;
                            while (pchoice != 'v' && pchoice != 'm') {
                                printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                                cin >> pchoice;
                            }
                        }(STL=='v')?splitnprint(pchoice,strat):splitnprintd(pchoice,strat);
                        if(issamiai=='k')
                        printf("Darbas baigtas su  %s \n", subname.c_str());
                        ft<<"Papildomos uzduoties split'inimo algoritmas uztruko "<<diff.count()<<" s.\n";
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
                    Stratpick(strat);
                    filename=std::to_string(students.size())+"kursioku";
                    printf("Galutini pazymi %s faile skaiciuoti pagal [v]idurki/[m]ediana ?\n",filename.c_str());
                    cin>>pchoice;
                    while(pchoice!='v'&&pchoice!='m'){
                        printf("Netinkama ivestis, galimi variantai: [v]idurkis/[m]ediana\n");
                        cin>>pchoice;
                    }
                   if(strat=='d'&& issamiai=='k') {printf("Papildomai uzduociai trinti [m]inkstus/ i prieki perkelti [k]ietus?\n");
                    cin>>kiec;
                    while(kiec!='k'&&kiec!='m'){
                        printf("Netinkama ivestis, galimi variantai: trinti [m]inkstus/perkelti [k]ietus\n");
                        cin>>kiec;
                    }}
                    splitnprint(pchoice, strat);
                    choice = -1;
                    break;
                }
            case 8:{
                Vector<int> test;
                std::vector<int>test2;
                int dydis=0;
                int sz=100000000;
                int kartai=0;
                for(int i=0;i<sz;i++){
                    if(test.capacity()!=dydis){
                        dydis=test.capacity();
                        kartai++;
                    }
                    test.push_back(1);}
                printf("idedant %d elementu i mano vektoriu vektoriaus talpa buvo padidinta %d kartu\n",sz,kartai);
                /*dydis=0;
                kartai=0;
                for(int i=0;i<sz;i++){
                    if(test2.capacity()!=dydis){
                        dydis=test2.capacity();
                        kartai++;
                    }
                    test2.push_back(i);}
                printf("idedant %d elementu i std vektoriu vektoriaus talpa buvo padidinta %d kartu\n",sz,kartai);*/
                choice=-1;
                break;}
            case 9:
            {
                Vector<int>test2;
                std::vector<int>test3;
                int temp;
                int sz=100000000;
                t.reset();
                for(int i=0;i<sz;i++)
                    test2.push_back(temp);
                printf("idedant %d elementu i mano vektoriu push_back uztruko %lf s\n",sz,t.elapsed());
               /*t.reset();
                for(int i=0;i<sz;i++)
                    test3.push_back(temp);
                printf("idedant %d elementu i std vektoriu push_back uztruko %lf s\n",sz,t.elapsed());*/
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