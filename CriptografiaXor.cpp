// Simples criptografia xor
// author cru3za

#include <iostream>
#include <string>

// using namespace std;

string Decrypter(string EncryptedData, char key[]){
	string Encrypted = EncryptedData;
	for (int i = 0; i < Encrypted.size(); i++){
		Encrypted[i] = EncryptedData[i] ^ key[i % (sizeof(key) / sizeof(char))];
	}
	return Encrypted;
}

int main(){
	char key[15] = {'C','R','U',3,'Z','A'}; //Defina as chaves
	cout << Decrypter("CRU3ZA", key); //Defina o que deseja criptografar
	return 0;
}
