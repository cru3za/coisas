#include <iostream>
#include <string>

using namespace std;

string Decrypter(string EncryptedData, char key[]){
	string Encrypted = EncryptedData;
	for (int i = 0; i < Encrypted.size(); i++){
		Encrypted[i] = EncryptedData[i] ^ key[i % (sizeof(key) / sizeof(char))];
	}
	return Encrypted;
}

int main(){
	char key[15] = {'C','R','U',3,'Z','A'};
	cout << Decrypter("CRU3ZA", key);
	return 0;
}
