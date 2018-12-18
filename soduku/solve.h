#pragma once

#include "IO.h"
#include <string>

class solver
{
private:
	InFile &readFile;
	OutFile &writeFile;
	char tableBuf[9][9] = {0};
	char lineBuf[18] = {0};
	char inBuf[50] = {0};
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