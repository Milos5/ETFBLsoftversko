#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include"autentifikacija.h"
#include"forma.h"
using namespace std;
void loginform(){
	while(1){							//Petlja koja se izvrsav dok korisnik ne unese ispravne kredencijale ili odluci da napusti program
		char usernm[255];				//String za korisnocko ime	
		char passwd[255];				//String za lozinku
		char id[255];					//Pomocna promjenjiva za odabir opcije u formi za logovanje
		cout<<"\n\t\t\t > > >S.U.M.A< < <\n\n";						
		cout<<"\t\tZa prijavu na sistem pritisnite -----> 1\n\n";		//opcije menija
		cout<<"\t\tZa izlazak iz programa pritisnite----> 2\n";
		cin>>id;
		if(strcmp(id,"1")==0){  		//Slucaj da je korisnik odabrao opciju 1
			int counter=0;				//Postavljanje brojaca na 0
			char tempCh; 				//Pomocna promjenjiva
			cout<<"Unesite korisnicko ime:\n";
			cin>>usernm;				//Unos korisnickog imena
			cout<<"Unesite lozinku:\n";
			for(counter=0;;){			//beskonacna petlja
				tempCh=getch();			//smjestanje znaka ukucanog na tastaturi
				if((tempCh>='a' && tempCh<='z') || (tempCh>='A' && tempCh<='Z') || (tempCh>='0' && tempCh<='9') || (tempCh=='_')){	//ogranicavanje lozinke na alfanurmericke znakove
					passwd[counter]=tempCh;		//Smjestanje unesenog znaka u string za lozinku
					++counter;
					cout<<"*";   				//Umjesto unesenog znaka upisuje se zvjezdica
				}
				if(tempCh=='\b' && counter>=1){//U slucaju da korisnik pritisne tipku BACKSPACE
					cout<<"\b \b";
					--counter;
				}
				if(tempCh=='\r'){    			//Slucaj da je korisnik stisnuo tipku ENTER
		    		passwd[counter]='\0';		//Na kraj stringa se upisuje znak \0
		    		--counter;
		    		cout<<endl;
					break;
				}
			}
			
			if(authentication(usernm,passwd)!=true)			//Provjera validnosti unosa
			cout<<"\t\tPogresano korisnicko ime ili pogresna lozinka!\n\n";
			else {
			break;
			}
		}
		if(strcmp(id,"2")==0)								//slucaj da je korisnik izabrao izlazak iz programa
			break;
		if((strcmp(id,"1")!=0 && strcmp(id,"2")!=0))		//Ako kosrinisk unese bilo koju opciju koja nije ponudjena menijem
			cout<<"Nevalidan unos\n\n";
		
	}
	//ovde ce se u slucaju validnog unosa kredencijala pozivati funkcija za meni
}
	



