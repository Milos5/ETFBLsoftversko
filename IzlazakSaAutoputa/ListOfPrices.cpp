#include "ListOfPrices.h"
#define DEFAULTFILE "Prices.txt"

ListOfPrices::ListOfPrices(){
    inputFile.open(DEFAULTFILE); // Ucitava se defaultni fajl Prices.txt
    if(inputFile.is_open()){ // Provjera da li je otvoren dati fajl
		inputFile >> numberOfCategories; // Upis broja kategorija iz fajla
        pricePerVehicleCategory = new int[numberOfCategories]; //Kreiranje dinamickog niza za kategorije
        for(int i = 0; i<numberOfCategories; i++){
            inputFile >> pricePerVehicleCategory[i]; // Upis cijena po kategoriji iz fajla
        }
        inputFile >> numberOfPoints; // Upis broja tacaka (ulazno/izlaznih tacaka izmedju dionica)
        pricePerPoint = new int*[numberOfPoints]; // Kreiranje matrice za upis cijena po dionici
        for(int i = 0; i<numberOfPoints; i++){
            pricePerPoint[i] = new int[numberOfPoints];
        }
        for(int i = 0; i<numberOfPoints; i++){
            for(int j = 0; j<numberOfPoints; j++){
                inputFile >> pricePerPoint[i][j]; // Upis u matricu za cuvanje cijena po dionicama iz fajla
            }
        }
        listOfPoints = new string[numberOfPoints]; // Kreiranje niza imena tacaka
        inputFile.ignore(225,'\n'); // Ignorisanje novog reda
        for(int i = 0; i<numberOfPoints; i++)
            getline(inputFile, listOfPoints[i],'\n'); // Unos imena tacaka iz fajla, delimiter \n
        inputFile.close(); //Zatvaranje fajla
    }
    else{
        cout << "\t Fajl se ne moze otvoriti." << endl;
        numberOfCategories = 0;
        numberOfPoints = 0;
    }
};
ListOfPrices::ListOfPrices(string fileLocation){
    inputFile.open(fileLocation.c_str()); //Ucitava se fajl iz lokacije u argumentu
    if(inputFile.is_open()){ // Provjera da li je otvoren dati fajl
		inputFile >> numberOfCategories; // Upis broja kategorija iz fajla
        pricePerVehicleCategory = new int[numberOfCategories]; //Kreiranje dinamickog niza za kategorije
        for(int i = 0; i<numberOfCategories; i++){
            inputFile >> pricePerVehicleCategory[i]; // Upis cijena po kategoriji iz fajla
        }
        inputFile >> numberOfPoints; // Upis broja tacaka (ulazno/izlaznih tacaka izmedju dionica)
        pricePerPoint = new int*[numberOfPoints]; // Kreiranje matrice za upis cijena po dionici
        for(int i = 0; i<numberOfPoints; i++){
            pricePerPoint[i] = new int[numberOfPoints];
        }
        for(int i = 0; i<numberOfPoints; i++){
            for(int j = 0; j<numberOfPoints; j++){
                inputFile >> pricePerPoint[i][j]; // Upis u matricu za cuvanje cijena po dionicama iz fajla
            }
        }
        listOfPoints = new string[numberOfPoints]; // Kreiranje niza imena tacaka
        inputFile.ignore(225,'\n'); // Ignorisanje novog reda
        for(int i = 0; i<numberOfPoints; i++)
            getline(inputFile, listOfPoints[i],'\n'); // Unos imena tacaka iz fajla, delimiter \n
        inputFile.close(); //Zatvaranje fajla
    }
    else{
        cout << "\t Fajl se ne moze otvoriti." << endl;
        numberOfCategories = 0;
        numberOfPoints = 0;
    }
};
ListOfPrices::~ListOfPrices(){ // Unistavanje dinamickih nizova
    delete [] pricePerVehicleCategory;
    for(int i = 0; i<numberOfPoints; i++)
        delete[] pricePerPoint[i];
    delete [] pricePerPoint;
    delete [] listOfPoints;
};
double ListOfPrices::calculate(string startPoint,string endPoint,int vehicleCategory){
    int startPointIndex = -1; // pocetna vrijednost za ulaznu tacku
    int endPointIndex = -1; // pocetna vrijednost za izlaznu tacku
    int result = 0;
    if((vehicleCategory>numberOfCategories)||(vehicleCategory<1))
        return -1; // Nepostojeca kategorija
    for(int i = 0; i < numberOfPoints; i++){ // Pretraga imena dionica kako bi se utvrdio index dionice
        if(startPoint==listOfPoints[i]){
            startPointIndex = i; //index ulazne tacke
        }
        if(endPoint==listOfPoints[i]){
            endPointIndex = i; //index izlazne tacke
        }
    }
    if((startPointIndex<0)||(startPointIndex>=numberOfPoints))
        return -2; // Nepostojeca ulazna tacka
    if((endPointIndex<0)||(endPointIndex>=numberOfPoints))
        return -3; // Nepostojeca izlazna tacka
    result = pricePerVehicleCategory[vehicleCategory-1]*pricePerPoint[endPointIndex][startPointIndex];
    if(result > 0)
        return result; // Vraca rezultat
    else if(result < 0){
        return -4; // Greska u racunanju
    }
    else{
        return -5; // Unijete su identicne tacke
    }
};
void ListOfPrices::updatePrices(){
    updatePrices(DEFAULTFILE); // Ucitava se defaultni fajl Prices.txt
};
void ListOfPrices::updatePrices(string fileLocation){
    inputFile.open(fileLocation.c_str()); //Ucitava se fajl iz lokacije u argumentu
    if(inputFile.is_open()){ // Provjera da li je otvoren dati fajl
        delete [] pricePerVehicleCategory; // Uklanjanje starih vrijednosti
        for(int i = 0; i<numberOfPoints; i++)
            delete[] pricePerPoint[i];
        delete [] pricePerPoint;
        delete [] listOfPoints;
		inputFile >> numberOfCategories; // Upis broja kategorija iz fajla
        pricePerVehicleCategory = new int[numberOfCategories]; //Kreiranje dinamickog niza za kategorije
        for(int i = 0; i<numberOfCategories; i++){
            inputFile >> pricePerVehicleCategory[i]; // Upis cijena po kategoriji iz fajla
        }
        inputFile >> numberOfPoints; // Upis broja tacaka (ulazno/izlaznih tacaka izmedju dionica)
        pricePerPoint = new int*[numberOfPoints]; // Kreiranje matrice za upis cijena po dionici
        for(int i = 0; i<numberOfPoints; i++){
            pricePerPoint[i] = new int[numberOfPoints];
        }
        for(int i = 0; i<numberOfPoints; i++){
            for(int j = 0; j<numberOfPoints; j++){
                inputFile >> pricePerPoint[i][j]; // Upis u matricu za cuvanje cijena po dionicama iz fajla
            }
        }
        listOfPoints = new string[numberOfPoints]; // Kreiranje niza imena tacaka
        inputFile.ignore(225,'\n'); // Ignorisanje novog reda
        for(int i = 0; i<numberOfPoints; i++)
            getline(inputFile, listOfPoints[i],'\n'); // Unos imena tacaka iz fajla, delimiter \n
        inputFile.close(); //Zatvaranje fajla
    }
    else{
        cout << "\t Fajl se ne moze otvoriti." << endl; //Ukoliko nije moguce otvoriti fajl nece se mijenjati vrijednosti starih cijena
        cout << "\t Vracanje na stare vrijednosti." << endl;
    }
};
