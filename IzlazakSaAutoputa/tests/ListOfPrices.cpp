/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListOfPrices.cpp
 * Author: Ace
 *
 * Created on January 21, 2017, 6:59 PM
 */

#include <stdlib.h>
#include <iostream>
#include "ListOfPrices.h"

/*
 * Simple C++ Test Suite
 */

void testListOfPrices() {
    string fileLocation="C:\\Users\\Ace\\git\\ETFBLsoftversko\\IzlazakSaAutoputa\\Prices.txt";
    ListOfPrices* list = new ListOfPrices(fileLocation);
    if (list==NULL) {
        std::cout << "%TEST_FAILED% time=0 testname=testListOfPrices (ListOfPrices) message=error message sample" << std::endl;
    }
    string startPoint="Vrbas";
    string endPoint="Novi Sad";
    int vehicleCategory=2;
    double result = list->calculate(startPoint, endPoint, vehicleCategory);
    if (result - 1.8 > 0.0001) {
        std::cout << "%TEST_FAILED% time=0 testname=testCalculate (ListOfPrices) message=error message sample" << std::endl;
    }
}


int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% ListOfPrices" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testListOfPrices (ListOfPrices)" << std::endl;
    testListOfPrices();
    std::cout << "%TEST_FINISHED% time=0 testListOfPrices (ListOfPrices)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

