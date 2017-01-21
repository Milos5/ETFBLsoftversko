/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListOfPrices.cpp
 * Author: Milos Sukara
 *
 * Created on January 21, 2017, 6:59 PM
 */

#include <stdlib.h>
#include <iostream>
#include "ListOfPrices.h"

using namespace std;


/*
 * Simple C++ Test Suite
 */

void testListOfPrices() {
    string fileName="Prices.txt";
    string startPoint="Novi Sad";
    string endPoint="Nis";
    int vehicleCategory=2;
    double expectedResult=3;
    ListOfPrices* list = new ListOfPrices(fileName);
    if (list==NULL) {
        cout << "%TEST_FAILED% time=0 testname=testListOfPrices (ListOfPrices) message=Objekat nije napravljen" << endl;
    }
    double result = list->calculate(startPoint, endPoint, vehicleCategory);
    cout << result;
    if ((result != expectedResult)||(result==0)) {
        cout << "%TEST_FAILED% time=0 testname=testCalculate (ListOfPrices) message=Greska u racunanju" << endl;
    }
    if (result == -1) {
        cout << "%TEST_FAILED% time=0 testname=testCalculate (ListOfPrices) message=Kategorija nije pronadjena u cjenovniku" << endl;
    }
    if (result == -2){
        cout << "%TEST_FAILED% time=0 testname=testCalculate (ListOfPrices) message=Ulazna tacka nije pronadjena u cjenovniku" << endl;
    }
    if (result == -3){
        cout << "%TEST_FAILED% time=0 testname=testCalculate (ListOfPrices) message=Izlazna tacka nije pronadjena u cjenovniku" << endl;
    }
    if (result == -5){
        cout << "%TEST_FAILED% time=0 testname=testCalculate (ListOfPrices) message=Nadjene su identicne tacke(ulazna tacka je izlazna tacka" << endl;
    }
}


int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% ListOfPrices.calculate()" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testListOfPrices (ListOfPrices.calculate())" << std::endl;
    testListOfPrices();
    std::cout << "%TEST_FINISHED% time=0 testListOfPrices (ListOfPrices.calculate())" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}