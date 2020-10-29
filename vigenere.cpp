#include <bits/stdc++.h>
using namespace std;

void tab(){ //basic tab
	for(int t=0; t<3; t++){
		cout<<"\t";
	}
}

void enkripsi(){
	string plainteks,kunci;
	string chiper = "";
	int n = 0;
	cout<<"\t\t\t\t\t VIGENERE CIPHER"<<endl;
	cin.ignore();
	tab (); cout<<"masukkan plainteks = ";getline(cin,plainteks);
	tab(); cout<<"masukkan kunci = ";getline(cin,kunci);
	
	char kunci_x[plainteks.length()];
	
	//pembentukan kunci
	for(int i=0;i<plainteks.length();i++){
		if(plainteks[i] != ' ' && kunci[n] != ' '){
			kunci_x[i] = toupper(kunci[n]);
			n++;
		}else if(kunci[n] != ' '){
			kunci_x[i] = plainteks[i];
		}
		
		if(kunci[n] == ' '){
			n++;
		}
		
		if(n==kunci.length()){
			n=0;
		}
	}
	//akhir pembentukan kunci
	
	tab();cout<<"plain = "<<plainteks<<endl;
	tab();cout<<"kunci = "<<kunci_x<<endl<<endl;
	
	//proses enkripsi
	for(int i=0;i<plainteks.length();i++){
		if(isalpha(plainteks[i])){
			char karakter = char((((toupper(plainteks[i])-65)+(kunci_x[i]-65))%26)+65)	;
			if(plainteks[i]==' ' || !isalpha(plainteks[i])){
				chiper += plainteks[i];
			}else{
				chiper += toupper(karakter);
			}
		}else{
			chiper += plainteks[i];
		}
		
	}
	//akhir proses enkripsi
	tab();cout<<"HASIL ENKRIPSI"<<endl;
	tab();cout<<chiper;
}
void deskripsi(){
	string cipher,kunci;
	string plainteks = "";
	int n = 0;
	cout<<"\t\t\t\t\t VIGENERE CIPHER"<<endl;
	cin.ignore();
	tab();cout<<"masukkan cipherteks = ";getline(cin,cipher);
	tab();cout<<"masukkan kunci = ";getline(cin,kunci);
	
	char kunci_x[cipher.length()];
	
	//pembentukan kunci
	for(int i=0;i<cipher.length();i++){
		if(cipher[i] != ' ' && kunci[n] != ' '){
			kunci_x[i] = toupper(kunci[n]);
			n++;
		}else if(kunci[n] != ' '){
			kunci_x[i] = cipher[i];
		}
		
		if(kunci[n] == ' '){
			n++;
		}
		
		if(n==kunci.length()){
			n=0;
		}
	}
	//akhir pembentukan kunci
	
	tab();cout<<"cipher = "<<cipher<<endl;
	tab();cout<<"kunci = "<<kunci_x<<endl<<endl;
	
	//proses deskripsi
	for(int i=0;i<cipher.length();i++){
		int hasil;
		if(isalpha(cipher[i])){
			if((toupper(cipher[i])-65)-(kunci_x[i]-65) < 0){
				hasil = ((toupper(cipher[i])-65)-(kunci_x[i]-65))+26;
			}else{
				hasil = ((toupper(cipher[i])-65)-(kunci_x[i]-65))%26;
			}		
			char karakter = char(hasil+65);
			if(cipher[i]==' ' || !isalpha(cipher[i])){
				plainteks += cipher[i];
			}else{
				plainteks += karakter;
			}
		}else{
			plainteks += cipher[i];
		}
		
	}
	//akhir proses deskripsi
	tab();cout<<"HASIL DESKRIPSI"<<endl;
	tab();cout<<plainteks;
}

void playfairChiper() {
	string key, keys = "", fixkey="";
	string plaintext, plain="";
	cin.ignore();
	cout<<"\n\n\n\n";
	tab(); cout<<"Masukkan Kunci/Key: "; getline(cin,key);
	tab(); cout<<"Masukkan Plaintext: "; getline(cin,plaintext);
	cout<<"\n";
	int x=key.length();
	int z=plaintext.length();
	
	for(int i=0; i<z; i++){
		plaintext[i] = (char)toupper(plaintext[i]);
	}
	
	plaintext.erase(remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());
	z=plaintext.length();
	
	for(int i=0; i<z; i++){
		i++;
			
			if(plaintext[i-1] == plaintext[i]){
				if(plaintext[i-1] == 'J' && plaintext[i] == 'J'){
					plain += "IX IX ";
				}else{
					plain +=plaintext[i-1];
					plain +="X ";
					
					i--;
					
				}
			}
			else if(plaintext[i-1] == 'J'){
				plain += "I ";
				plain += plaintext[i];
			}
			else if(plaintext[i] == 'J'){
				plain += plaintext[i-1];
				plain += "I ";
			}
			else {
				if(plaintext[i] == NULL){
					plain += plaintext[i-1];
					plain += "X";
					break;
				}
				
			    plain += plaintext[i-1];
				plain += plaintext[i];
				plain += " ";
			}
			
			if(i+1 ==z-1){
				if(plaintext[i+1]== 'J'){
					plain += "IX";
					break;
				}else {
					plain += plaintext[i+1];
					plain += "X";
					break;
				}
			}	
	}
	
	cout<<"\n\n";
	tab(); cout<<plain<<"\n\n";
	
	for(int i=0; i<x; i++) {
		
		if(key[i] != 'j' || key[i] == 'J') {
			keys += (char)toupper(key[i]);
		}
	}
	
	keys += "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	
	int xx = keys.length();
	
	for(int i=0; i<x; i++) {
		for(int j=i+1; j<xx; j++) {
			if(keys[i] == keys[j]){
				keys[j] =' ';
				
			}
		}
	}
	
	keys.erase(remove(keys.begin(), keys.end(), ' '), keys.end());
	keys.erase(remove(keys.begin(), keys.end(), 'J'), keys.end());
	int xxx = keys.length();
	string baris ="";
	vector<string> add;
	int y=5;
	
	for(int i=0; i<xxx; i++) {
		y--;
		baris+=keys[i];
		if(y==0 || i==xxx-1) {
			add.push_back(baris);
			baris ="";
			y=5;
		}
	}
	
	plain.erase(remove(plain.begin(), plain.end(), ' '), plain.end());
	
	vector<int> row;
	vector<int> col; 
	int itr=0, len=plain.length();
	
	
	
	awal:
	if(itr <= len-1 ){
		for(int i=0; i<add.size(); i++) {
			for(int j=0; j<5; j++) {
				if(plain[itr] == add[i][j]){
					//cout<<i<<" "<<j<<endl;
					
					row.push_back(i);
					col.push_back(j);
					
					itr++;
					goto awal;
				}	
			}
		}	
	}	
		
		vector<int> fixrow;
		vector<int> fixcol;
		
	for(int i=0; i<row.size(); i++) {
		i++;
		
		if(row[i] == row[i-1]){
			//vertikal
				if(col[i] < 5){
					col[i]++;
				}
				if(col[i-1] < 5){
					col[i-1]++;
				}
				if(col[i] == 5) {
					col[i] = 0;
				}
				if(col[i-1] == 5) {
					col[i-1] = 0;
				}
				
				fixrow.push_back(row[i-1]);
				fixcol.push_back(col[i-1]);
				
				fixrow.push_back(row[i]);
				fixcol.push_back(col[i]);
				
		} else if(col[i] == col[i-1]){
			//horizontal
				if(row[i] < 5){
					row[i]++;
				}
				if(row[i-1] < 5){
					row[i-1]++;
				}
				if(row[i] == 5) {
					row[i] = 0;
				}
				if(row[i-1] == 5) {
					row[i-1] = 0;
				}
				
				fixrow.push_back(row[i-1]);
				fixcol.push_back(col[i-1]);
				
				fixrow.push_back(row[i]);
				fixcol.push_back(col[i]);
			
		} else{
			//square
			int x = col[i-1];
			int y = col[i];
			
			col[i-1] = y;
			//row[i-1] = row[i-1];
			
			col[i] = x;
			
				fixrow.push_back(row[i-1]);
				fixcol.push_back(col[i-1]);
				
				fixrow.push_back(row[i]);
				fixcol.push_back(col[i]);
			
		}
		
		
	}
	
	
		for(int i=0; i<add.size(); i++) {
			tab(); for(int j=0; j<5; j++) {
				cout<<add[i][j]<<" ";	
			}
			cout<<endl;
		}
		cout<<"\n";
		
	
	int zz=2;
	string hasil = "";
	for(int i=0; i<fixrow.size(); i++) {

		zz--;
		
		int x = fixrow[i];
		int y = fixcol[i];
		
		
		//tampil kotak untuk cari
		for(int j=x; j<=x; j++){
			for(int k=y; k<=y; k++){
				hasil += add[x][y];
			}
		}
		
		if(zz == 0) {	
			hasil += " ";
			zz = 2;
		}	
	}
	tab(); cout<<hasil<<endl;
}


void menu(){
	cout<<"\n\n\n\n\n\n";
	system("color 0f");
    	tab(); cout<<"                      ~~=====================~~ \n";
        tab(); cout<<"~~================~~'|Enkripsi & Deskripsi Teks|'~~===============~~\n";
        tab(); cout<<"|                     ~~=====================~~                     | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|   [1] Vigenere Chiper                                             | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|   [2] Playfair Chiper                                             | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|                                                                   | \n";
		tab(); cout<<"|                    ~~=====================~~                      | \n";
		tab(); cout<<"~~===============~~'~|  CREATED BY KELOMPOK   |~'~~===============~~\n";
		tab(); cout<<"                     ~~=====================~~                  \n";
}

int main(){
	
	int dec;
	menu();
	
	tab(); cout<<"Masukkan Pilihan : ";
	cin>>dec;
	
	switch (dec) {
		case 1:
			system("CLS");
			int pilihan;
			cout<<"\n\n\n\n";
			tab(); cout<<"1. enkripsi"<<endl;
			tab(); cout<<"2. deskripsi"<<endl;
			tab(); cout<<"pilihan : ";cin>>pilihan;
				
			if(pilihan==1){
				enkripsi();
			}else if(pilihan==2){
				deskripsi();
			}
		break;
		
		case 2:
			system("CLS");
			playfairChiper();
		break;
		
		default:
			cout<<"\n\n\n\n\n\n";
			cout<<"SEE YOU....";
		break;
	}
	
	
	
}
