#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 1024

int main(int argc , char *argv[]){
	WSADATA wsa;
	char hostname[20];
	//char *hostname = "www.github.com";
	char ip[100];
	struct hostent *he;
	struct in_addr **addr_list;
	int i;
	
	printf("\nInsira o dominio: ");
	scanf("%s",&hostname);
	printf("\nIniciando Winsock...");
	if (WSAStartup(MAKEWORD(2,2),& wsa) != 0){
		printf("\n Erro : %d",WSAGetLastError());
		return 1;
	}
	printf("\nPerfeito, inicializado :)\n");
	if ( (he = gethostbyname( hostname ) ) == NULL) {
		printf("\nFalha ao obter o nome do host : %d" , WSAGetLastError());
		return 1;
	}
	addr_list = (struct in_addr **) he-> h_addr_list;
	for(i = 0; addr_list[i] != NULL; i++) {
		strcpy(ip , inet_ntoa(*addr_list[i]) );
	}
	printf("Dominio -> [ %s ]\nIP -> [ %s ]\n\n" , hostname , ip);
	return 0;
}
