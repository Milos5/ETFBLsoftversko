#include"authentication.h"
using namespace std;
bool authentication(string user,string pass){
	ifstream in("database.txt"); //.txt fajl u kojem se nalaze imena korisnika i njehove lozinke
	char username[255];
	char password[255];
	if(in.is_open()){
		while(!in.eof()){    //prolazi od pocetka do kraja .txt fajla
            in.getline(username,255,'#'); //u string a se smjesta username (# je delimiter izmedju username-a i passworda)
            in.getline(password,255,'\n');//u string b se smejsta password
            if((strcmp(user.c_str(),username)==0) && (strcmp(pass.c_str(),password)==0)) //provjera da li argumenti predati funkiciji odgovaraju nekoj od kombinacija zapisanim u fajlu
                return true;
        }
    }
    else{
	
        cout << "Fajl se ne moze otvoriti.";
        
    
    }
    in.close();
    return false;
}

