#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include"autentifikacija.h"
using namespace std;
bool authentication(char user[],char pass[]){
	ifstream in("database.txt"); //.txt fajl u kojem se nalaze imena korisnika i njehove lozinke
	char a[255];
	char b[255];
	if(in){
		while(!in.eof()){    //prolazi od pocetka do kraja .txt fajla
		in.getline(a,255,'#'); //u string a se smjesta username (# je delimiter izmedju username-a i passworda)
		in.getline(b,255,'\n');//u string b se smejsta password
		if((strcmp(user,a)==0) & (strcmp(pass,b)==0)) //provjera da li argumenti predati funkiciji odgovaraju nekoj od kombinacija zapisanim u fajlu
		return true;
	}
		return false;
}

		}

