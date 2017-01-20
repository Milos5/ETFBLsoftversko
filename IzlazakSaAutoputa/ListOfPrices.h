#ifndef LISTOFPRICES_H
#define LISTOFPRICES_H
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class ListOfPrices{
    private:
        int numberOfCategories;
        int* pricePerVehicleCategory;
        int numberOfPoints;
        int** pricePerPoint;
        string* listOfPoints;
        ifstream inputFile;
    public:
        ListOfPrices(); // Konstruktor, pretpostavlja da se Cjenovnik.txt nalazi u izvrsnom direktorijumu, ukoliko ne otvori fajl staviti ce duzine nizova na 0
        ListOfPrices(string fileLocation); // Konstruktor, prima putanju do Prices.txt (U putanju ukljuciti Prices.txt), ukoliko ne otvori fajl staviti ce duzine nizova na 0
        ~ListOfPrices(); // Destruktor
        double calculate(string startPoint,string endPoint,int vehicleCategory); // Racunanje putarine, vraca negativnu vrijednost ukoliko dodje do greske
            /*
                Moguce povrate vrijednosti:
                    >0 : trazeni rezultat
                    -1 : kategorija nije pronadjena u cjenovniku
                    -2 : ulazna tacka nije pronadjena u cjenovniku
                    -3 : izlazna tacka nije pronadjena u cjenovniku
                    -4 : doslo je do greske u racunanju, tj. rezultat izracunavanja je negativna vrijesnost
                    -5 : nadjene su identicne tacke(ulazna tacka je izlazna tacka)
            */
        void updatePrices(); // Azurira vrijednosti cijenovnika iz novog fajla
        void updatePrices(string fileLocation); // Azurira vrijednosti cijenovnika iz novog fajla koji je argument funkcije
};
#endif // LISTOFPRICES_H

