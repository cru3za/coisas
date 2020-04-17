#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 1024

#pragma comment(lib,"ws2_32.lib")

int main(int argc , char *argv[]){
	WSADATA wsa;
	char *hostname = "www.github.com";
	char ip[100];
	struct hostent *he;
	struct in_addr **addr_list;
	int i;
	
	printf("\nIniciando Winsock...");
	if (WSAStartup(MAKEWORD(2,2),& wsa) != 0){
		printf("Erro : %d",WSAGetLastError());
		return 1;
	}
	
	printf("Inicializado.\n");
	
		
	if ( (he = gethostbyname( hostname ) ) == NULL) {
		printf("falha ao obter o nome do host : %d" , WSAGetLastError());
		return 1;
	}
	
	addr_list = (struct in_addr **) he-> h_addr_list;
	
	for(i = 0; addr_list[i] != NULL; i++) {
		
		strcpy(ip , inet_ntoa(*addr_list[i]) );
	}
	
	printf("%s transformado para : %s\n" , hostname , ip);
    
	return 0;
}
