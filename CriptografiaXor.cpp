// Simples criptografia xor

#include<bits/stdc++.h>

void Decrypter(char* Encrypt_Decrypt) { 
    char Chave[6] = {'c','r','u','3','z','a'};
    for (int i = 0; i < (strlen(Encrypt_Decrypt)); i++){ 
        Encrypt_Decrypt[i] = Encrypt_Decrypt[i] ^ Chave[i % (sizeof(Chave) / sizeof(char))]; 
        printf("%c",Encrypt_Decrypt[i]); 
    } 
} 
int main() { 
    char Cru3za[] = "www.github.com/cru3za";
    printf("Encrypted String: "); 
    Decrypter(Cru3za); 
    printf("\n"); 
    printf("Decrypted String: "); 
    Decrypter(Cru3za);
}
