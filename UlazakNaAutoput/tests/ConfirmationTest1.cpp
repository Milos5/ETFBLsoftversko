/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConfirmationTest1.cpp
 * Author: User
 *
 * Created on 21 January 2017, 23:51
 */

#include <stdlib.h>
#include <iostream>
#include "confirmation.h"

/*
 * Simple C++ Test Suite
 */

void testConfirmation() {
    string username ("nikola_blagojevic");
    string startPoint ("Vrbas");
    int result = confirmation(username, startPoint);
    if ( result == -1 ) {
        std::cout << "%TEST_FAILED% time=0 testname=testConfirmation (ConfirmationTest1) message= Potvrda nije sacuvana" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% ConfirmationTest1" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testConfirmation (ConfirmationTest1)" << std::endl;
    testConfirmation();
    std::cout << "%TEST_FINISHED% time=0 testConfirmation (ConfirmationTest1)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

