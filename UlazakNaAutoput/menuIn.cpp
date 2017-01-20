#include "menuIn.h"
#include "confirmation.h"

void create(string nodeId, string workerId) {
//kreiranje potvrde o ulasku na autoput
        cout << endl << endl << "\t Kreiranje potvrde : " << endl << endl;
        cout << "\t\t\t ===================================" << endl;
        cout << "\t\t\t Radnik : " << workerId << endl;
        cout << "\t\t\t Ulazna tacka : " << nodeId << endl;
//trenutno vrijeme sistema
        time_t rawTime;
        struct tm * timeInfo;
        time (&rawTime);
        timeInfo = localtime (&rawTime);
        cout << "\t\t\t Vrijeme : " << asctime(timeInfo);
        cout << "\t\t\t ===================================" << endl << endl;
        if (confirmation(workerId, nodeId)==0)
            cout<< "\t Potvrda je uspjesno sacuvana.";
        else
            cout<< "\t Greska pri cuvanju potvrde.";
}

void help() {
//pomoc za korisnika
    cout << endl << "\t Pomoc" << endl << "\t =====" << endl << endl;
    cout <<"\t Dobrodosli, hvala sto koristite nasu aplikaciju!" << endl;
    cout <<"\t Da biste izdali potvrdu, u meniju unesite 1 i pritisnite enter." << endl;
    cout <<"\t Otvorice vam se meni za unos podataka i kreiranje nove potvrde." << endl;
    cout <<"\t Da biste se izlogovali iz aplikacije, u meniju nesite 3 i pritisnite \n\t enter.";
    cout << endl;
}


void menu(string nodeId, string workerId) {
//funkcija menu za ulazak na autoput
//char se koristi kao sprecavanje pogresnog unosa
    char input[10] = {0};
    int select;    //select za switch
//petlja menija, omogucava se visestruko pozivanje menija, dok se ne odabere odjava
    while(select){
        cout<< endl << "\t\t\t\t < < < MENU > > >\n\n\n";
        cout<<"\t\t\t Odaberite opciju :\n";
        cout << "\n\t\t\t 1. Kreiranje potvrde o ulasku na autoput.\n" << endl;
        cout << "\t\t\t 2. Pomoc.\n" << endl;
        cout << "\t\t\t 3. Odjava.\n" << endl;
        cout << "\t Opcija : ";
        cin >> input;
//dodjela vrijednosti select, da bi switch radio kako treba
        if(strcmp(input,"1")==0)
            select=1;
        else if(strcmp(input,"2")==0)
            select=2;
        else if(strcmp(input,"3")==0)
            select=3;
        else
            select=4;
//switch za obradu korisnikovog unosa
        switch (select) {
            case 3:
                select = 0;
                cout << endl <<"\t Odjava sa sistema.\n" << endl;
                break;

            case 1:
                create(nodeId, workerId);
                cout << endl << endl;
                break;

            case 2:
                help();             //pozivanje f-je help
                break;

            default:
                cout << endl <<"\t\t\t Izabrali ste opciju koja nije validna." << endl;
                cout << "\t\t\t Pritisnite enter da udjete u glavni meni." << endl;
                cout << endl;
                break;
        }
    }
}
