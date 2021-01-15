#include "WriteBuffer.h"
#include <stdint.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

WriteBuffer::WriteBuffer() {
}

bool WriteBuffer::write(char buffer[], int size, HANDLE *SerialPortHandle) {
/**********************************************/
	buffer;
	DWORD dwBytesToWrite = strlen(buffer) * sizeof(char);
	DWORD dwBytesWrite = 100;
	bool isWrite = false;
/**********************************************/

	if (!WriteFile(*SerialPortHandle, buffer, dwBytesToWrite, &dwBytesWrite, NULL)) {
		printf("********************************************\n");
		printf("ERROR: SerialPorte\n");
		printf("********************************************\n");
		isWrite = false;
	}
	else {
		byte b;
		if (dwBytesWrite > 0) {
			printf("Dados da escrita.\n\n");
			printf("********************************************\n");
			for (int i = 0; i < dwBytesWrite; i++) {
				b = buffer[i];
				printf("%02x ", b);
			}
			printf("\n********************************************\n");
			isWrite = true;
		}
		else {
			printf("********************************************\n");
			printf("Falha na escrita.\n");
			printf("********************************************\n");
			isWrite = false;
		}		
		return isWrite;
	}
}


WriteBuffer::~WriteBuffer() {
}
