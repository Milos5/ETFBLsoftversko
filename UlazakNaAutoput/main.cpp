
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
            cout << "\n\n\tDobrodosli " << userId << "!\n";
            cout << "\tUnesite ulazni cvor: ";
            string nodeId = "0";
            cin.get();
            std::getline(std::cin,nodeId, '\n');
            if(nodeId=="0" || nodeId=="" || nodeId==" " || nodeId =="\n")
                do {
                    cout << "Greska pri unosu ulaznog cvora!\n";
                    cout << "\t\tUnesite ulazni cvor: ";
                    std::getline(std::cin,nodeId, '\n');
                }while(nodeId=="0" || nodeId=="" || nodeId==" " || nodeId =="\n");
                menu(nodeId, userId);
        }
        else {
            cout<<"\n\n\t\tHvala sto koristite nasu aplikaciju!\n";
            counter = 0;
        }
    }
    return 0;
}
