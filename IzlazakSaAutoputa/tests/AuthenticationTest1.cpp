/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AuthenticationTest1.cpp
 * Author: Ace
 *
 * Created on January 21, 2017, 6:57 PM
 */

#include <stdlib.h>
#include <iostream>
#include "authentication.h"

/*
 * Simple C++ Test Suite
 */

void testAuthentication() {
    string p0="nikola_blagojevic";
    string p1="nikola93";
    bool result = authentication(p0, p1);
    if (result == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testAuthentication (AuthenticationTest1) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% AuthenticationTest1" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testAuthentication (AuthenticationTest1)" << std::endl;
    testAuthentication();
    std::cout << "%TEST_FINISHED% time=0 testAuthentication (AuthenticationTest1)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

