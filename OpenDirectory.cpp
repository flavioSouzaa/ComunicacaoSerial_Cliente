#include "OpenDirectory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Utils.h"
using namespace std;
#define MAXTYPE (3)

OpenDirectory::OpenDirectory() {	
}

bool OpenDirectory::listFile(int command, char path[]) {	
	
	return true; 
}

int OpenDirectory::menu(char path[]) {
/*******************************/
	Utils *util = new Utils();
	int type = 0;
	char buffer[100];	
/*******************************/
	while (true) {
		printf("**************************************************\n");
		printf("Escolha a forma de visualizacao do arquivo********\n");
		printf("(1) Mostrar todos arquivos do caminho espesificado\n");
		printf("(2) Mostrar os arquivos de modo recursivo*********\n");
		type = util->GetInt();
		printf("**************************************************\n");

		if (!((type == 0) || (type > MAXTYPE))) {
			printf("**************************************************\n");
			printf("Informe o nome do caminho.\n");
			printf("Path:");
			cin >> buffer;
			break;
		}
		else {
			printf("Opcao selecionada incorreta.\n");
			type = 0;
			break;
		}
	}		
	return type;
}

OpenDirectory::~OpenDirectory() {
}






