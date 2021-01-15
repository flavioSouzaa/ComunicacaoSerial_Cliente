#pragma once
class OpenDirectory
{
public:
	OpenDirectory();	
	bool listFile(int size, char path[]);
	int menu(char path[]);
	~OpenDirectory();
};

