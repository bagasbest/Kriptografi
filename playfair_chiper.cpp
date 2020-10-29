#include <bits/stdc++.h>
using namespace std;



int main () {
	
	string key, keys = "", fixkey="";
	string plaintext, plain="";
	cout<<"Masukkan Kunci/Key: "; getline(cin,key);
	cout<<"Masukkan Plaintext: "; getline(cin,plaintext);
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
	cout<<plain<<"\n\n";
	
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
			for(int j=0; j<5; j++) {
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
	cout<<hasil<<endl;
}
