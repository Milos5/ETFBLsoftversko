#include <iostream>
#include "menuOut.h"
#include "form.h"

using namespace std;

int main(){
    string username;
    bool stayInside=true; // Omogucava ponovni prikaz menija dok ne odlucimo da izadjemo
    while(stayInside){
        username = loginform(); // dobijamo korisnika koji se logovao na sistem ili "0" ako je izabrana opcija za izlaz
        if(username != "0"){
            cout << "\n\t Dobrodosli " << username << ".\n\n";
            menuOut(username); // pristupamo glavnom meniju programa
        }
        if(username == "0") // Obrada koda "0", tj. detekcija izlaza iz programa
            stayInside = false;
    }
    cout<<"\t\tHvala sto koristite nasu aplikaciju!\n";
    return 0;
}
