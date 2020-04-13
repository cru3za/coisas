// Simples criptografia xor
// author @cru3za

#include<bits/stdc++.h>

void Decrypter(char Encrypt_Decrypt[]) { 
    // Chave  
    char Chave[6] = {'c','r','u','3','z','a'}; 
    int cru3za = strlen(Encrypt_Decrypt); 

    for (int i = 0; i < cru3za; i++){ 
        Encrypt_Decrypt[i] = Encrypt_Decrypt[i] ^ Chave[i % (sizeof(Chave) / sizeof(char))]; 
        printf("%c",Encrypt_Decrypt[i]); 
    } 
} 
int main() { 
    // Texto
    char Cru3za[] = "www.github.com/cru3za";
    printf("Encrypted String: "); 
    Decrypter(Cru3za); 
    printf("\n"); 
  
    printf("Decrypted String: "); 
    Decrypter(Cru3za); 
  
    return 0; 
} 
