#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define ZERO (0)

Utils::Utils() {

}

int Utils::GetInt() {
	int varint = ZERO;
	char c;
	//scanf("%d", &varint);
	cin >> varint;
	//while ((c = getchar()) != '\n' && c != EOF);
	while ((c = getchar()) != '\n' && c != EOF);
	return varint;
}

Utils::~Utils() {

}


