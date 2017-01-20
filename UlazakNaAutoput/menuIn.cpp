#include "menuIn.h"
#include "confirmation.h"

void create(string nodeId, string workerId) {
//kreiranje potvrde o ulasku na autoput
        cout << endl << endl << "\t\t\tKreiranje potvrde" << endl;
        cout << "\t\t\t=================" << endl;
        cout << "\t\t\tTrenutno logovani: " << workerId << endl;
        cout << "\t\t\tTrenutni cvor: " << nodeId << endl;
//trenutno vrijeme sistema
        time_t rawTime;
        struct tm * timeInfo;
        time (&rawTime);
        timeInfo = localtime (&rawTime);
        cout << "\t\t\tTrenutno vrijeme: " << asctime(timeInfo) << endl;
        if (confirmation(workerId, nodeId)==0)
            cout<< "\t\t\tUspjesno je sacuvana potvrda!";
        else
            cout<< "Greska pri cuvanju potvrde!";
}

void help() {
//pomoc za korisnika
    cout << endl << endl << "\tPomoc" << endl << "\t=====" << endl;
    cout <<"\tDobrodosli, hvala sto koristite nasu aplikaciju!" << endl;
    cout <<"\tDa biste izdali potvrdu, u meniju unesite 1 i pritisnite enter." << endl;
    cout <<"\tOtvorice vam se meni za unos podataka i kreiranje nove potvrde!" << endl << endl;
    cout <<"\tDa biste se izlogovali iz aplikacije," << endl;
    cout <<"\tu meniju nesite 0 i pritisnite enter.";
    cout << endl << endl;
}


void menu(string nodeId, string workerId) {
//funkcija menu za ulazak na autoput
//char se koristi kao sprecavanje pogresnog unosa
    char input[10] = {0};
    int select;    //select za switch
    cout<< endl << "\t\t\t\t  < < < MENU > > >\n\n\n";
    cout<<"\t\t\tOdaberite opciju\n\n";
//petlja menija, omogucava se visestruko pozivanje menija, dok se ne odabere odjava
    while(select){
        cout << "\t\t\t1. Kreiranje potvrde o ulasku na autoput" << endl;
        cout << "\t\t\t2. Pomoc" << endl;
        cout << "\t\t\t0. Odjava" << endl << endl;
        cout << "\t Vas izbor: ";
        cin >> input;
//dodjela vrijednosti select, da bi switch radio kako treba
        if(strcmp(input,"1")==0) select=1;
        else if(strcmp(input,"2")==0) select=2;
        else if(strcmp(input,"0")==0) select=0;
        else select=3;
//switch za obradu korisnikovog unosa
        switch (select) {
            case 0:
                select = 0;
                cout << endl <<"\t\t\tOdjava sa sistema\n" << endl;
                break;

            case 1:
                create(nodeId, workerId);
                cout << endl << endl;
                break;

            case 2:
                help();             //pozivanje f-je help
                cout << endl << endl;
                break;

            default:
                cout << endl << endl <<"\t\t\tIzabrali ste opciju koja nije validna" << endl;
                cout << "\t\t\tPritisnite enter da udjete u glavni meni." << endl;
                cout << endl << endl;
                break;
        }
    }
}
