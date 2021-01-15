#include "ProcessaDados.h"
#include "OpenDirectory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Utils.h"
int main()
{
	ProcessaDados *inicial = new ProcessaDados();	
	while (true) {
		inicial->ProcessaInformacoes();		
	}
}
