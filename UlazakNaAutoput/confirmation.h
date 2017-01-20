#ifndef CONFIRMATION_H_INCLUDED
#define CONFIRMATION_H_INCLUDED

#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<ctime>
#include <sstream>

using namespace std;

int confirmation(string username, string startPoint);
/*          Moguce povratne vrijednosti:
              0 : uspjesno je kreiran fajl
             -1 : potvrda nije kreirana
*/


#endif // CONFIRMATION_H_INCLUDED
