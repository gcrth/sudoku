#pragma once

#include "IO.h"
#include <string>

class solver
{
private:
	InFile &readFile;
	OutFile &writeFile;
	char tableBuf[9][9];
	char tableMark[9][9];
	char lineBuf[18];
	char inBuf[50];
	std::string outbuf;
public:
	solver(InFile &readFile_, OutFile &writeFile_);
	bool run();
	bool testWholeTable();
private:
	bool input(bool &withEndl);
	bool test(char i);
	void searchAvalibleNumber(char x, char y, char list[]);
	bool output(bool withExtralEndl = true);
	bool flush();
};