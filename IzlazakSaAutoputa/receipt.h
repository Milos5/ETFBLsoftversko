#ifndef RECEIPT_H
#define RECEIPT_H
#include<iostream>
#include"ListOfPrices.h"
#include<fstream>
#include<string>
#include<windows.h>
#include<ctime>
#include <sstream>

using namespace std;

int receipt(string username,string startPoint,string endPoint,int vehicleCategory);
/*
                Moguce povrate vrijednosti:
                     0 : Uspjesno je napravljen racun
                    -1 : kategorija nije pronadjena u cjenovniku
                    -2 : ulazna tacka nije pronadjena u cjenovniku
                    -3 : izlazna tacka nije pronadjena u cjenovniku
                    -4 : doslo je do greske u racunanju, tj. rezultat izracunavanja je negativna vrijesnost
                    -5 : nadjene su identicne tacke(ulazna tacka je izlazna tacka)
                    -6 : ne moze se otvoriti novi txt fajl za racun
*/
#endif
