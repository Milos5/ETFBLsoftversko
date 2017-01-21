#include"form.h"
string loginform(){
	int doing=1;
	int valid=0;						//Pomocna promjenjiva
	char usernm[255]="";				//String za korisnocko ime
    char passwd[255]="";				//String za lozinku
	char id[255];                   	//Pomocna promjenjiva za odabir opcije u formi za logovanje
	while(doing){						//Petlja koja se izvrsav dok korisnik ne unese ispravne kredencijale ili odluci da napusti program
		cout<<"\t\t\t\t======S.U.M.A.======\n\n\n";
        cout<<"\t\t\tOdaberite opciju : \n\n";
		cout<<"\t\t\t1. Prijava na sistem.\n\n";
		cout<<"\t\t\t2. Izlazak iz programa.\n\n"; //opcije menija
		cout<<"\t Opcija : ";
		cin>>id;
		cout<<endl;
		if(strcmp(id,"1")==0){  		//Slucaj da je korisnik odabrao opciju 1
			int counter=0;				//Postavljanje brojaca na 0
			char tempCh; 				//Pomocna promjenjiva
			cout<<"\t Unesite korisnicko ime : ";
			cin>>usernm;
			cout<<endl;				//Unos korisnickog imena
			cout<<"\t Unesite lozinku : ";
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
				cout<<"\n\t Pogresno korisnicko ime ili pogresna lozinka!\n\n";
			else{
				doing=0;
				valid=1;
			}
		}
		if(strcmp(id,"2")==0){								//slucaj da je korisnik izabrao izlazak iz programa
			doing=0;
			valid=0;
		}
		if((strcmp(id,"1")!=0 && strcmp(id,"2")!=0)){		//Ako kosrinisk unese bilo koju opciju koja nije ponudjena menijem
			cout<<"\t Nevalidan unos.\n\n";
			valid=0;
		}
	}
	cin.ignore();
	if(valid==1)
        return string(usernm); //vraca korisnicko ime korisnika koji se uspjenso logovao na sistem
    return "0"; //vraca string "0" ukoliko je korisnik izabrao opciju za izlaz
}
