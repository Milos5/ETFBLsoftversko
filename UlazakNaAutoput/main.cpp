
#include "form.h"
#include "authentication.h"
#include "menuIn.h"

using namespace std;

int main() {
    string userId = "0";
    int counter = 1;
    while(counter){
        userId = loginform();

        if (userId!="0"){
            cout << "\n\n\t Dobrodosli " << userId << "!\n\n";
            cout << "\t Unesite ulazni cvor : ";
            string nodeId = "0";
            cin.get();
            std::getline(std::cin,nodeId, '\n');
            if(nodeId=="0" || nodeId=="" || nodeId==" " || nodeId =="\n")
                do {
                    cout << "\t Greska pri unosu ulaznog cvora!\n";
                    cout << "\t\t Unesite ulazni cvor : ";
                    std::getline(std::cin,nodeId, '\n');
                }while(nodeId=="0" || nodeId=="" || nodeId==" " || nodeId =="\n");
                menu(nodeId, userId);
        }
        else {
            cout<<"\n\n\t\t Hvala sto koristite nasu aplikaciju!\n";
            counter = 0;
        }
    }
    return 0;
}
