#include "ProcessaDados.h"
#include "WriteBuffer.h"
#include "SerialPort.h"
#include "Protocolo.h"
#include "GeraCrc16.h"
#include "ReadBuffer.h"

#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define MAX_FAILED (2)
ProcessaDados::ProcessaDados() {
}

void ProcessaDados::ProcessaInformacoes(void) {
/**********************************************/
	HANDLE SerialPortHandle;
/**********************************************/
	char bufferTeste[ ] = "teste";
	char comport	[ ] = "COM1" ;
	char retBuffer[100];	
/**********************************************/
	int  baud = 115200;
	int  endPosition;
	int  size;	
/**********************************************/
	bool isOpen  = false;
	bool iswrite = false;
	bool isRead  = false;
/**********************************************/
	SerialPort  *OpenPort  = new SerialPort ();
	Protocolo   *protocolo = new Protocolo  ();	
	WriteBuffer *escreve   = new WriteBuffer();
	ReadBuffer  *leitura   = new ReadBuffer ();
/**********************************************/
	size = sizeof(bufferTeste);
	size = size -1;
/**********************************************/
		
	isOpen = OpenPort->begin(comport, baud, &SerialPortHandle);

	if (isOpen == false) {
		printf("******************************************\n");
		printf("Falha ao abrir a porta de comunicacao\n");
		printf("******************************************\n");		
	}
	else {
		while(true) {
			printf("\n******************************************\n");
			protocolo->CriaProtocolo(bufferTeste, size, retBuffer, &endPosition);
			printf("Dados do protocolo.\n");
			for (int i = 0; i < endPosition; i++)
			{
				printf("%02x", retBuffer[i]);
			}
			printf("\n******************************************\n");
			
			iswrite = escreve->write(retBuffer, endPosition, &SerialPortHandle);			
				
			if (iswrite) {
				isRead = leitura->read(&SerialPortHandle);					
				if (isRead) {
					printf("\n******************************************\n");
					printf("Dados verificados.\n");
					printf("******************************************\n");
				}
				else {
					printf("\n******************************************\n");
					printf("Ocorreu uma falha na verificacao dos dados.\n");
					printf("******************************************\n");
				}
			}
			else
			{
				printf("\n******************************************\n");
				printf("Ocorreu uma falha no envio dos dados.\n");
				printf("******************************************\n");				
			}	
		}
	}
}

ProcessaDados::~ProcessaDados() {
}
