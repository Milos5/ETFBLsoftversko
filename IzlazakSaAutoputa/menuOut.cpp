#include"MenuOut.h"
using namespace std;
void help(){//Funkcija help koja na ekranu ispisuje uputstvo.
	cout<<endl;
	cout<<"\t Pomoc"<<endl;
	cout<<"\t =====\n";
	cout<<"\t Kroz meni se krecete tako sto uneste redni broj opcije koju zelite izvrsiti i pritisnete\n";
	cout<<"\t tipku enter.\n";
	cout<<"\t Na raspolaganju su vam sljedece opcije :\n";
	cout<<"\t 1. Unos podataka i izdavanje racuna : Sluzi za unosenje imena ulaznog cvora i kategorije\n";
	cout<<"\t    vozila (cio broj), kao i za izadavnje racuna u pisanom obliku.\n";
	cout<<"\t 2. Pomoc : Ova opcija nudi osnovne informacije o mogucnostima svake opcije menija \n";
	cout<<"\t i nacin na koji se koriste.\n";
	cout<<"\t 3. Odjava : Pomocu ove opcije odjavljujete se sa sistema.\n";
	cout<<endl<<endl;
}
void menuOut(string Username){
	int option=1; //Pomocna promjenjiva za switch.
	int category;//Pomocna promjenjiva za kategoriju vozila.
	bool isendpointSet=false; //Promjenjiva za provjeru da li je krajnja tacka upisana.
	string startPoint;//Promjenjiva za tacku na kojoj je vozac usao.
	string endPoint;//Promjenjiva za ime radnog mjesta na kojem logovani radnik radi.
	string tempstr;//Pomocna promjenjiva pomocu koje pravimo opcije imunima na pogresne unose.
	string catemp;//Pomocna promjenjiva pomocu koje pravimo opcije imunima na pogresne unose.
	int counterwh=1,rectemp;//Pomocne promjenjive za while petlju, i za primanje vrijednosti funkcije receipt.
	int number=0;//Pomocna promjenjiva za pretvaranje stringa u cio broj.

	while(option){//Petlja u kojoj se unosi naziv trenutnog radnog mjesta, i izvrsava se samo jednom.
		if(isendpointSet==false){
			cout<<"\t\t Unesite radno mjesto na kojem se nalazite."<<endl<<endl;
			cout<<"\t Cvor : ";
			getline(cin,endPoint,'\n');
			isendpointSet=true;
			cout<<endl<<endl;
		}
		cout<<"\t\t\t\t  < < < MENU > > >\n\n\n";
		cout<<"\t\t\tOdaberite opciju : \n\n";
		cout<<"\t\t\t1. Unos podataka i izdavanje racuna.\n\n";
		cout<<"\t\t\t2. Pomoc.\n\n";
		cout<<"\t\t\t3. Odjava.\n\n";
		cout<<"\t Opcija : ";
		cin>>tempstr;//Ovde se obezbjedjujemo da je je unjeta opcija numericka i da ta opcija postoji u meniju,ostali karakteri bice okarakterisani kao greska.
		cout<<endl;
		if(tempstr=="1")
			option=1;
		else if(tempstr=="2")
			option=2;
		else if(tempstr=="3")
			option=3;
		else
			option=4;
		switch(option){
			case 1:{//Opcija 1 za unos podataka.
				cout<<"\t\t\t < Unos podataka >\n\n";
				cout<<"\t Kategorija vozila : ";
				counterwh=1;//Pomocna promjenjiva za izlaz iz while petlje.
				while(counterwh){
					getline(cin,catemp,'\n');
					for(int i=0;i<catemp.length();++i){//Prolazenje kroz unjeti string i provjera da li je cisto numericki,u slucaju bilo kojih drugi unosa prijavice se greska.
						if(catemp[i]<'0' || catemp[i]>'9'){
							cout<<"\n\n \t Sadrzi karakter koji nije cifra, probajte ponovo.\n"<<endl;
							cout<<"\t Kategorija vozila : ";
							counterwh=1;
							break;
						}
						if(i==(catemp.length()-1)){//Izlaz iz petlje kada se dodje do kraja Stringa.
							counterwh=0;
							break;
						}
					}
				}
				for(int i=0;i<catemp.length()-1;i++){//Pretvaranje stringa sa brojevnim karakterima u int vrijednost.
					number+=catemp[i]-'0';
					number*=10;
				}
				number+=catemp[catemp.length()-1]-'0';
				category=number;
				number=0;
				cout<<endl;
				cout<<"\t Ulazna tacka : ";
				getline(cin,startPoint,'\n');//Unos naziva ulazne tacke.
				rectemp=receipt(Username,startPoint,endPoint,category);//Upis vrijednosti koje vraca funkcija u promjenjivu rectemp.
				cout<<endl;
				switch(rectemp){//Ispis u zavisnosti od vracene vrijednosti.
					case 0:
						cout<<"\t Uspjesno je napravljen racun.\n"<<endl;
						break;
					case -1:
						cout<<"\t Kategorija nije pronadjena.\n"<<endl;
						break;
					case -2:
						cout<<"\t Ulazna tacka nije pronadjena.\n"<<endl;
						break;
					case -3:
						cout<<"\t Izlazna tacka nije pronadjena.\n"<<endl<<endl;
						cout<<"\t\t Unesite radno mjesto na kojem se nalazite."<<endl<<endl;
                        cout<<"\t Cvor : ";
                        getline(cin,endPoint,'\n');
                        isendpointSet=true;
                        cout<<endl<<endl;
						break;
					case -4:
						cout<<"\t Doslo je do greske u racunanju (rezultat negativna vrijednost).\n"<<endl;
						break;
					case -5:
						cout<<"\t Greska-ulazna i izlazna tacka se poklapaju\n."<<endl;
						break;
					case -6:
						cout<<"\t Ne moze se otvoriti novi txt fajl za racun\n."<<endl;
						break;
					default:
						cout<<"\t Greska!\n"<<endl;
				}
				}
				break;
			case 2:
	    		help();
				break;
			case 3:
				return;
				break;
			case 4:
			    cout<<"\n\t Nevalidan unos.\n\n"; //Ispis u slucajnu nevalidnog unosa.
				break;
			default:
				option=0;
		}
	}
}

