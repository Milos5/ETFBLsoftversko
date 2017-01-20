#include "menuIn.h"
#include "confirmation.h"

void create(string nodeId, string workerId) {
//kreiranje potvrde o ulasku na autoput
        cout << endl << endl << "\t\t\t Kreiranje potvrde" << endl;
        cout << "\t\t\t =================" << endl;
        cout << "\t\t\t Trenutno logovani: " << workerId << endl;
        cout << "\t\t\t Trenutni cvor: " << nodeId << endl;
//trenutno vrijeme sistema
        time_t rawTime;
        struct tm * timeInfo;
        time (&rawTime);
        timeInfo = localtime (&rawTime);
        cout << "\t\t\t Trenutno vrijeme: " << asctime(timeInfo) << endl;
        if (confirmation(workerId, nodeId)==0)
            cout<< "\t\t\t Uspjesno je sacuvana potvrda!";
        else
            cout<< "Greska pri cuvanju potvrde!";
}

void help() {
//pomoc za korisnika
    cout << endl << endl << "\t Pomoc" << endl << "\t =====" << endl;
    cout <<"\t Dobrodosli, hvala sto koristite nasu aplikaciju!" << endl;
    cout <<"\t Da biste izdali potvrdu, u meniju unesite 1 i pritisnite enter." << endl;
    cout <<"\t Otvorice vam se meni za unos podataka i kreiranje nove potvrde!" << endl << endl;
    cout <<"\t Da biste se izlogovali iz aplikacije, u meniju nesite 0 i pritisnite \n\t enter.";
    cout << endl << endl;
}


void menu(string nodeId, string workerId) {
//funkcija menu za ulazak na autoput
//char se koristi kao sprecavanje pogresnog unosa
    char input[10] = {0};
    int select;    //select za switch
    cout<< endl << "\t\t\t\t < < < MENU > > >\n\n\n";
    cout<<"\t\t\t Odaberite opciju\n\n";
//petlja menija, omogucava se visestruko pozivanje menija, dok se ne odabere odjava
    while(select){
        cout << "\n\t\t\t 1. Kreiranje potvrde o ulasku na autoput\n" << endl;
        cout << "\t\t\t 2. Pomoc\n" << endl;
        cout << "\t\t\t 0. Odjava\n" << endl << endl;
        cout << "\t Opcija : ";
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
                cout << endl <<"\t Odjava sa sistema\n" << endl;
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
                cout << endl << endl <<"\t\t\t Izabrali ste opciju koja nije validna" << endl;
                cout << "\t\t\t Pritisnite enter da udjete u glavni meni." << endl;
                cout << endl << endl;
                break;
        }
    }
}
