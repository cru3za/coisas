#include<bits/stdc++.h> 

void Decrypter(char encrypt[]) { 
	char key = 22; //key
	int script = strlen(encrypt); 
	for (int i = 0; i < script; i++) { 
		encrypt[i] = encrypt[i] ^ key;
                printf("%c",encrypt[i]);  
	} 
} 

int main() { 
	char sampleString[] = 'example';
	// Decrypt the string 
	printf('Decrypted String: '); 
	Decrypter(sampleString);
        printf('\n'); 

	return 0; 
} 
