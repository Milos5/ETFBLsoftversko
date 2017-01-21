
#include "form.h"
#include "authentication.h"
#include "menuIn.h"

using namespace std;

int main() {
    string userId = "0";            //ime korisnika
    string nodeInFile;              //pomocna promjenjiva koja sluzi za provjeru da li ima unijetog cvora u fajlu
    int counter = 1;                //omogucava izlazak iz while petlje
    int check;                      //provjera kod trazenja imena cvora u fajlu
    ifstream in;                    //in file za citanje iz fajla gdje se nalaze ulazni cvorovi
    while(counter){                 //petlja za ponavljanje login forme
        userId = loginform();       //login forma, vraca ime korisnika
                                    //ukoliko ima korisnika nastavlja se program, ukoliko ne, izlazi se iz programa
        check = 0;
        if (userId!="0"){
            cout << "\n\t\t Dobrodosli " << userId << ".\n\n";
            cout<<"\t\t Unesite radno mjesto na kojem se nalazite."<<endl<<endl;
            cout<<"\t Cvor : ";
            string nodeId = "0";                    //id ulaznog cvora
            getline(cin,nodeId);
                                                    //provjera da li se uneseni cvor nalazi u ulazno fajlu nodes.txt
            in.open("nodes.txt");
            if(in.is_open()) {
                while(!in.eof()){
                    while( getline (in,nodeInFile)) {
                        if(nodeId == nodeInFile){
                            check = 1;
                            break;
                        }
                    }

                }
                in.close();
            }
                                                    //ukoliko nije pronadjen, ponavlja se unos i trazenje u fajlu nodes.txt dok se ne unese korektna vrijednost
            if(check == 0){
                do {
                    cout << "\n\t Greska pri unosu ulaznog cvora!\n";
                    cout << "\n\t Unesite ulazni cvor : ";
                    getline(cin,nodeId);
                    in.open("nodes.txt");
                    if(in.is_open()) {
                        while(!in.eof()){
                            getline(in,nodeInFile);
                                if(nodeId == nodeInFile) {
                                    check = 1;
                                    break;
                            }
                        }
                    }
                    in.close();
                }while(check == 0);
            }
            if(check)
                menu(nodeId, userId);               //pozivanje f-je meni za rad sa aplikacijom za odgovarajuceg korisnika na njegovom radnom mjestu
        }
        else {
            cout<<"\t\t Hvala sto koristite nasu aplikaciju!\n";
            counter = 0;                            //izlaz iz glavne petlje
        }
    }
    return 0;
}
