#include "ReadBuffer.h"
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define  MAX_FAILED (4)
#define  MAX_REPLAY (2)
#define  TYPE		(1)
ReadBuffer::ReadBuffer() {
}
bool ReadBuffer::read(HANDLE *SerialPortHandle) {
/******************************************/
	DWORD dwBytesToRead = TYPE;
	DWORD dwBytestRead  = TYPE;
/******************************************/
	bool isack   = false;
	bool Abort   = false;
/******************************************/
	char  buffer[10];
	char  ack = 0x06;
	char  nak = 0x15;
/******************************************/
	
	while(true) {
		if (Abort)
			break;

		if (!ReadFile(*SerialPortHandle, (void*)buffer, dwBytesToRead, &dwBytestRead, NULL)) {
			printf("********************************************\n");
			printf("Falha na leitura dos dados\n");
			printf("********************************************\n");
		}
		
		if (dwBytestRead > 0) {
			printf("\n********************************************\n");
			printf("dwBytestRead: %d\n", dwBytestRead);
			printf("%02x\n", buffer[0]);
			printf("Analisando os dados \n");
			printf("********************************************\n");
			
			if (buffer[0] == ack) {
				isack = true;
				Abort = true;
				printf("ACK\n");
				printf("********************************************\n");
			}
			else if (buffer[0] == nak) {
				isack = false;	
				Abort = true;
				printf("NAK\n");
				printf("********************************************\n");				
			}
			else {
				printf("Esperando resposta\n");//colocar um contador
				printf("********************************************\n");
				Sleep(500);						
			}			
		}
		else {
			printf("\n********************************************\n");
			printf("Falha na captura dos dados\n");
			printf("dwBytestRead: %d\n", dwBytestRead);
			printf("********************************************\n");
		}
		Sleep(500);			
	} 
	return  isack;
}
ReadBuffer::~ReadBuffer() {
}