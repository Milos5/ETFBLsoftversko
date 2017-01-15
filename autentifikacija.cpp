#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include"autentifikacija.h"
using namespace std;
bool authentication(char user[],char pass[]){
	ifstream in("database.txt"); //.txt fajl u kojem se nalaze imena korisnika i njehove lozinke
	char username[255];
	char password[255];
	if(in){
		while(!in.eof()){    //prolazi od pocetka do kraja .txt fajla
            in.getline(username,255,'#'); //u string a se smjesta username (# je delimiter izmedju username-a i passworda)
            in.getline(password,255,'\n');//u string b se smejsta password
            if((strcmp(user,username)==0) && (strcmp(pass,password)==0)) //provjera da li argumenti predati funkiciji odgovaraju nekoj od kombinacija zapisanim u fajlu
                return true;
        }
        return false;
    }
}

