#include"receipt.h"
#define DEFAULTFOLDER "Receipts"

string intToString (int number){ // funkcija za konverziju iz int-a u string
    ostringstream oss;
    oss << number;
    return oss.str();
}
int receipt(string username,string startPoint,string endPoint,int vehicleCategory){
    ListOfPrices* list = new ListOfPrices(); // konstruktor cjenovnika
    double price; //promjenljiva u kojoj se cuva vrijednost
    ofstream outputFile; // izlazni fajl
    string fileLocation; // string koji cuva adresu recepta
    string folder;
    string timeYear; // string koji predstavlja godinu
    string timeMonth; // string koji predstavlja mjesec
    string timeDay; // string koji predstavlja dan
    string timeHour; // string koji predstavlja sat
    string timeMinute; // string koji predstavlja minut
    string timeSecond; // string koji predstavlja sekund
    string timeAll; // string koji predstavlja i vrijeme i datum
    folder = DEFAULTFOLDER; // folder u kojem se smjestaju fajlovi
    CreateDirectory(folder.c_str(), NULL); // pravi se direktorijum za cuvanje racuna
    time_t t = time(0);   // pribavljanje vremena
    struct tm * now = localtime( & t ); // setovanje u odgovarajuc oblik
    timeYear = intToString(now->tm_year+1900); // konverzija godine u odgovarajucu formu i u string
    timeMonth = intToString(now->tm_mon+1); // konverzija mjeseca u odgovarajucu formu i u string
    timeDay = intToString(now->tm_mday); // konverzija dana u string
    timeHour = intToString(now->tm_hour); // konverzija sata u string
    timeMinute = intToString(now->tm_min); // konverzija minuta u string
    timeSecond = intToString(now->tm_sec); // konverzija sekunda u string
    if(now->tm_mday<10)  // prebacivanje u oblik sa vodecom nulom ukoliko je vrijednost manja od 10
        timeDay="0"+timeDay;
    if((now->tm_mon+1)<10)
        timeMonth="0"+timeMonth;
    if((now->tm_hour)<10)
        timeHour="0"+timeHour;
    if((now->tm_min)<10)
        timeMinute="0"+timeMinute;
    if((now->tm_sec)<10)
        timeSecond="0"+timeSecond;
    timeAll = timeHour+"_"+timeMinute+"_"+timeSecond+"_"+timeDay+"_"+timeMonth+"_"+timeYear; // formiranje stringa u obliku HH_MM_SS_DD_MM_YYYY
    fileLocation = ".\\"+folder+"\\"+username+"_"+endPoint+"_"+timeAll+".txt"; // formiranje naziva falja i lokacije za upis
    price = list->calculate(startPoint,endPoint,vehicleCategory); // racunanje cijene
    if(price>0){  // analiza povratnih vrijednosti iz calculate
        outputFile.open(fileLocation.c_str());
        if(outputFile.is_open()){
            outputFile << "Radnik:"<< username << endl;
            outputFile << "Ulazna tacka:"<< startPoint << endl;
            outputFile << "Izlazna tacka:" << endPoint<< endl;
            outputFile << "Kategorija voizla: "<< vehicleCategory << endl;
            outputFile << "Cijena: "<< price << endl;
            outputFile << "Vrijeme izdavanja: " << timeHour << ":" << timeMinute << ":" <<timeSecond<<endl;
            outputFile << "Datum izdavanja: " << timeDay << "." << timeMonth <<"."<<timeYear<<"."<<endl;
            outputFile.close();
            return 0;
        }
        return -6; // ne moze se otvoriti novi racun
    }
    return price;
}
