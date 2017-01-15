#ifndef MENUIN_H_INCLUDED
#define MENUIN_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

//create pravi novu potvrdu o ulazu na autoput
void create(string, string);
//help ispisuje uputstvo za koriscenje aplikacije
void help();
//glavna f-ja koja predstavlja glavni meni za aplikaciju
void menu(string, string);

#endif // MENUIN_H_INCLUDED
