// Simples criptografia xor

#include<bits/stdc++.h>

void Decrypter(char* Encrypt_Decrypt) { 
    char Chave[2] = {4, 4}; //Coloque quantas chaves quiser
    for (int i = 0; i < (strlen(Encrypt_Decrypt)); i++){ 
        Encrypt_Decrypt[i] = Encrypt_Decrypt[i] ^ Chave[i % (sizeof(Chave) / sizeof(char))]; 
        printf("%c",Encrypt_Decrypt[i]); 
    } 
} 
int main() { 
    char Cru3za[] = "www.github.com/cru3za"; //Texto a ser Criptografado
    printf("Encrypted String: "); 
    Decrypter(Cru3za); 
    printf("\n"); 
    printf("Decrypted String: "); 
    Decrypter(Cru3za);
}


// output
// Encrypted String: sss*cmplqf*gki+gvq7~e
// Decrypted String: www.github.com/cru3za
