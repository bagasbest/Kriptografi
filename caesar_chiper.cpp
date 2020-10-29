#include <bits/stdc++.h>
using namespace std;

void tab(){ //basic tab
	for(int t=0; t<3; t++){
		cout<<"\t";
	}
}

void caesarChiper () {
	string s;
	int n,pilihan;
	
	cout<<"\n\n\n\n\n\n";
	tab(); cout<<"============={PROGRAM CAESAR CHIPER}===============\n\n";
	tab(); cout<<"1. Enkripsi"<<endl;
	tab(); cout<<"2. Deskripsi"<<endl;
	tab(); cout<<"Masukkan Pilihan : "; cin>>pilihan;
	cin.ignore();
	tab(); cout<<"Input plain text / chiper teks : "; getline(cin,s);
	tab(); cout<<"Kunci enkripsi / deskripsi : "; cin>>n;
	int x = s.length();
	string chiper="";
	string plainteks="";
	
	if(pilihan==1){
		for(int i=0; i<x; i++) { //membuat enkripsi
			chiper += char(int(s[i] + n)%256);
		}	
		cout<<"\n";
		tab(); cout<<"\tKeluaran enkripsi: "<<chiper<<endl;
	}else if(pilihan==2){
		for(int i=0; i<x; i++) { //membuat deskripsi
			plainteks += char(int(s[i] - n)%256);
		}
		cout<<"\n";
		tab(); cout<<"\tKeluaran Deskripsi: "<<plainteks<<endl;
	}
	cout<<"\n\n";
	tab(); cout<<"==============={CHIPER TEXT}=======================\n";	
}

void transposisiChiper () {
	string s;
	int x,i,j,key, fill,pilihan,key_desc;
	
	cout<<"\n\n\n\n\n\n";
	tab(); cout<<"============={TRANSPOSISI CHIPER}===============\n\n";
	tab(); cout<<"1. Enkripsi"<<endl;
	tab(); cout<<"2. Deskripsi"<<endl;
	tab(); cout<<"Masukkan Pilihan : "; cin>>pilihan;
	cin.ignore();
	tab(); cout<<"MASUKKAN PLAIN TEKS / CHIPER TEKS: "; getline(cin, s);
	tab(); cout<<"MASUKKAN KEY : "; cin>>key;
	
	fill = key;
	x = s.length();
	key_desc = x / key;
	
	if(key_desc % key < key && key_desc % key != 0){ //menentukan kunci untuk deskripsi
		key_desc += 1;
	}
	
	if(pilihan == 2){ // jika pilihan deskripsi
		fill = key = key_desc;
	}
	
	vector<string>str;
	string pisah = "";
	for(i=0; i<x; i++) {
		key--;
		if(s[i] == ' ') {
				s[i] = '*';
		}
		pisah += s[i];
		if(key == 0 || i==x-1) {
				
			str.push_back(pisah);
			pisah = "";
			key = fill;
		}
	}
		
	j = 0;
	vector<string>transpose;
	string chiper = "";
	for(i=0; i<str.size(); i++) {		
		if(j>0 && i==str.size()-1){
			if(str[i][j-1] == NULL) {
				str[i][j] = NULL;
			}
		}
		
		chiper += str[i][j];
		if(i == str.size()-1 && j < key-1){
			i=-1;
			j++;
			transpose.push_back(chiper);
			chiper = "";
		} else if(i == str.size()-1 && j == key-1) {
			transpose.push_back(chiper);
			break;
		}
	}	
	
	//output hasil
	if(pilihan == 1){
		cout<<endl;
		tab();cout<<"POTONG STRING SEPANJANG MASUKAN KEY\n"<<endl;
		
		for(i=0; i<str.size(); i++) {
			tab(); cout<<str[i]<<endl;
		}
			
		cout<<endl;
		tab();cout<<"Keterangan: '*' merupakan spasi"<<endl<<endl;
		tab();cout<<"HASIL AKHIR ENKRIPSI"<<endl;
		tab();
		for(i=0; i<transpose.size(); i++) {
			cout<<transpose[i];
		}	
	}else if(pilihan == 2){
		cout<<endl;
		tab();cout<<"POTONG STRING SEPANJANG MASUKAN KEY\n"<<endl;
		for(i=0; i<str.size(); i++) {
			tab(); cout<<str[i]<<endl;
		}
		tab();
		string deskripsi = "";
		for(i=0; i<transpose.size(); i++) {
			deskripsi += transpose[i];
		}
		cout<<endl;
		tab();cout<<"HASIL AKHIR DESKRIPSI"<<endl;
		tab();
		for(i=0; i<x; i++) {
			if(deskripsi[i] == '*') {
					deskripsi[i] = ' ';
			}
			cout<<deskripsi[i];
		}	
	}
	cout<<endl<<endl;
	tab(); cout<<"==============={CHIPER TEXT}=======================\n";	
}

void mergedChiper() {
	string s;
	int n,m,pilihan,i,j,fill,key_desc;
	
	cout<<"\n\n\n\n\n\n";
	tab(); cout<<"============={PROGRAM CAESAR & TRANSPOSISI CHIPER (SUPER ENKRIPSI)}===============\n\n";
	tab(); cout<<"1. Enkripsi"<<endl;
	tab(); cout<<"2. Deskripsi"<<endl;
	tab(); cout<<"Masukkan Pilihan : "; cin>>pilihan;
	cin.ignore();
	tab(); cout<<"Input plain text / chiper teks : "; getline(cin,s);
	tab(); cout<<"Kunci 1 (caesar chiper) : "; cin>>n;
	tab(); cout<<"Kunci 2 (transosisi chiper) : "; cin>>m;
	
	int x = s.length();
	string teks="";
	
	//proses caesar chiper
	if(pilihan==1){
		for(int i=0; i<x; i++) { //membuat enkripsi
			teks += char(int(s[i] + n)%256);
		}	
	}else if(pilihan==2){
		for(int i=0; i<x; i++) { //membuat deskripsi
			teks += char(int(s[i] - n)%256);
		}
	}
	//akhir proses caesar chiper
	tab();cout<<"HASIL CAESAR CHIPER"<<endl;
	tab();cout<<teks<<endl;
	//proses transposisi chiper
	fill = m;
	key_desc = x / m;
	
	if(key_desc % m < m && key_desc % m != 0){ //menentukan kunci untuk deskripsi
		key_desc += 1;
	}
	
	if(pilihan == 2){ // jika pilihan deskripsi
		fill = m = key_desc;
	}
	
	vector<string>str;
	string pisah = "";
	for(i=0; i<x; i++) {
		m--;
		if(teks[i] == ' ') {
				teks[i] = '*';
		}
		pisah += teks[i];
		if(m == 0 || i==x-1) {
				
			str.push_back(pisah);
			pisah = "";
			m = fill;
		}
	}
		
	j = 0;
	vector<string>transpose;
	string chiper = "";
	for(i=0; i<str.size(); i++) {		
		if(j>0 && i==str.size()-1){
			if(str[i][j-1] == NULL) {
				str[i][j] = NULL;
			}
		}
		
		chiper += str[i][j];
		if(i == str.size()-1 && j < m-1){
			i=-1;
			j++;
			transpose.push_back(chiper);
			chiper = "";
		} else if(i == str.size()-1 && j == m-1) {
			transpose.push_back(chiper);
			break;
		}
	}	
	
	//output hasil
	if(pilihan == 1){
		cout<<endl;
		tab();cout<<"POTONG STRING SEPANJANG MASUKAN KEY\n"<<endl;
		
		for(i=0; i<str.size(); i++) {
			tab(); cout<<str[i]<<endl;
		}
			
		cout<<endl;
		tab();cout<<"Keterangan: '*' merupakan spasi"<<endl<<endl;
		tab();cout<<"HASIL AKHIR ENKRIPSI"<<endl;
		tab();
		for(i=0; i<transpose.size(); i++) {
			cout<<transpose[i];
		}	
	}else if(pilihan == 2){
		cout<<endl;
		tab();cout<<"POTONG STRING SEPANJANG MASUKAN KEY\n"<<endl;
		for(i=0; i<str.size(); i++) {
			tab(); cout<<str[i]<<endl;
		}
		tab();
		string deskripsi = "";
		for(i=0; i<transpose.size(); i++) {
			deskripsi += transpose[i];
		}
		cout<<endl;
		tab();cout<<"HASIL AKHIR DESKRIPSI"<<endl;
		tab();
		for(i=0; i<x; i++) {
			if(deskripsi[i] == '*') {
					deskripsi[i] = ' ';
			}
			cout<<deskripsi[i];
		}	
	}
	//akhir proses transposisi chiper
	cout<<"\n\n";
	tab(); cout<<"==============={CHIPER TEXT}=======================\n";	
}

void menu(){
	cout<<"\n\n\n\n\n\n";
	system("color 0f");
    	tab(); cout<<"                      ~~=====================~~ \n";
        tab(); cout<<"~~================~~'|Enkripsi & Deskripsi Teks|'~~===============~~\n";
        tab(); cout<<"|                     ~~=====================~~                     | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|   [1] CAESAR CHIPER                                               | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|   [2] TRANSPOSISI CHIPER                                          | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|   [3] CAESAR CHIPER + TRANSPOSISI CHIPER (SUPER ENKRIPSI)         | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|   [4] KELUAR                                                      | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|                                                                   | \n";
		tab(); cout<<"|                    ~~=====================~~                      | \n";
		tab(); cout<<"~~===============~~'~|  CREATED BY KELOMPOK   |~'~~===============~~\n";
		tab(); cout<<"                     ~~=====================~~                  \n";
}

void exit () {
	system("CLS");
	cout<<"\n\n\n\n\n\n";
	tab();tab(); cout<<"HAVE A GOOD DAY"<<endl;
	cout<<"\n\n\n\n\n\n";
}


int main () {
	
	awal:
	menu();
	int choice;
	
	tab(); cout<<"PILIHAN : "; cin>>choice;
	
	switch(choice) {
		case 1:
			caesarChiper:
			system("CLS");
			caesarChiper();
			char option;
			cout<<"\n\n";
			tab(); cout<<"APAKAH ANDA INGIN MENCOBA LAGI ? (y/n) ";
			cin>>option;
			
			if(option == 'y') {
				goto caesarChiper;
			} else {
				char backToMenu;
				tab(); cout<<"INGIN KEMBALI KE MENU UTAMA ? (y/n) "; cin>>backToMenu;
				
				if(backToMenu == 'y') {
					system("CLS");
					goto awal;
				} else {
					exit();
					return 0;
				}
			}
		break;
		case 2 : 
			transposisiChiper:
			system("CLS");
			transposisiChiper();
			char option1;
			cout<<"\n\n";
			tab(); cout<<"APAKAH ANDA INGIN MENCOBA LAGI ? (y/n) ";
			cin>>option1;
			
			if(option1 == 'y') {
				goto transposisiChiper;
			} else {
				char backToMenu;
				tab(); cout<<"INGIN KEMBALI KE MENU UTAMA ? (y/n) "; cin>>backToMenu;
				
				if(backToMenu == 'y') {
					system("CLS");
					goto awal;
				} else {
					exit();
					return 0;
				}
			}
		break;
		case 3 : 
			mergedChiper:
			system("CLS");
			mergedChiper();
			char option2;
			cout<<"\n\n";
			tab(); cout<<"APAKAH ANDA INGIN MENCOBA LAGI ? (y/n) ";
			cin>>option2;
			
			if(option2 == 'y') {
				goto mergedChiper;
			} else {
				char backToMenu;
				tab(); cout<<"INGIN KEMBALI KE MENU UTAMA ? (y/n) "; cin>>backToMenu;
				
				if(backToMenu == 'y') {
					system("CLS");
					goto awal;
				} else {
					exit();
					return 0;
				}
			}	
		break;
		
		default : 
			exit();
			return 0;
		break;
	}
		

}
