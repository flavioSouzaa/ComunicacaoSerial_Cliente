#include "Protocolo.h"
#include"GeraCrc16.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#define TYPE_BEGIN_PROTOCOL (3)
#define TYPE_END_PROTOCOL   (2)
#include<sstream>

Protocolo::Protocolo() {
}

void Protocolo::CriaProtocolo(char buffer[],int size,char bufferCarga[], int *endPosition) {
/**********************************************/
	GeraCrc16 *CR16 = new GeraCrc16();
	bufferCarga;
	char bufferCrc16[2];
    unsigned int sizeCRC16;
/**********************************************/

		bufferCarga[0] = '@';//inicio do comando;
		bufferCarga[1] = '0x31';//Comando de Escrita 1, Comando de leitura 2.
		bufferCarga[2] = size;

		for (int i = 0; i < size; i++)
		{
			bufferCarga[i + TYPE_BEGIN_PROTOCOL] = buffer[i];
		}
		*endPosition = size + TYPE_BEGIN_PROTOCOL;
				
/*
		sizeCRC16 = CR16->getCrc16(bufferCarga, 0, *endPosition);

		printf("%02x\n",sizeCRC16);
		printf("%d\n", sizeCRC16);	
		
		unsigned char *tipo = NULL;

		*tipo = (unsigned char)&sizeCRC16;

		printf("%d\n", tipo[0]);
		printf("%d\n", tipo[1]);
		printf("%d\n", tipo[2]);

		*endPosition = *endPosition + 2;

*/

		bufferCarga[*endPosition] = '!';//finaliza  comando
		*endPosition = *endPosition + 1;
		
}


Protocolo::~Protocolo() {
}