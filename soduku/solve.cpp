#include "pch.h"
#include <queue>
using namespace std;

#include "solve.h"
#include "IO.h"

solver::solver(InFile &readFile_, OutFile &writeFile_) :readFile(readFile_), writeFile(writeFile_)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != 8)lineBuf[2 * i + 1] = ' ';
		else lineBuf[2 * i + 1] = '\0';
	}
	outbuf.reserve(1000000 * 170);
	outbuf.clear();
	run();
}

bool solver::run()
{
	bool withEndl;
	while (input(withEndl))
	{
		test(0);
		output(withEndl);
	}
	flush();
	return true;
}

bool solver::testWholeTable()
{
	char list[10]; bool flag = true;
	for (int i = 0; i < 81; i++)
	{
		searchAvalibleNumber(i / 9, i % 9, list);
		if (list[tableBuf[i / 9][i % 9]] != 1)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

bool solver::input(bool &withEndl)
{
	if (readFile.gets(inBuf, 18) == NULL)return false;
	for (int j = 0; j < 9; j++)
	{
		tableBuf[0][j] = inBuf[2 * j] - '0';
	}
	if (readFile.gets(inBuf, 18) == NULL)throw runtime_error("读入文件失败");
	for (int i = 1; i < 9; i++)
	{
		if (readFile.gets(inBuf, 18) == NULL)throw runtime_error("读入文件失败");
		for (int j = 0; j < 9; j++)
		{
			tableBuf[i][j] = inBuf[2 * j] - '0';
		}
		if (readFile.gets(inBuf, 18) == NULL)throw runtime_error("读入文件失败");
	}
	if (readFile.gets(inBuf, 18) != NULL)
	{
		withEndl = true;
	}
	else
	{
		withEndl = false;
	}
	return true;
}

bool solver::test(char i)
{
	if (i == 81)return true;
	if (tableBuf[i / 9][i % 9] != 0)
	{
		int j;
		for (j = i + 1; j < 81; j++)
		{
			if (tableBuf[j / 9][j % 9] == 0)break;
		}
		return test(j);
	}
	char list[10];
	searchAvalibleNumber(i / 9, i % 9, list);
	queue<char> avalibleNumber;
	for (int i = 0; i < 9; i++)
	{
		if (list[i + 1] == 1)avalibleNumber.push(i + 1);
	}
	while (avalibleNumber.empty() != true)
	{
		tableBuf[i / 9][i % 9] = avalibleNumber.front();
		avalibleNumber.pop();
		if (test(i + 1) == true)return true;
	}
	tableBuf[i / 9][i % 9] = 0;
	return false;
}

void solver::searchAvalibleNumber(char x, char y, char list[])
{
	for (int i = 0; i < 10; i++)
	{
		list[i] = 1;
	}
	for (int i = 0; i < 9; i++)
	{
		list[tableBuf[x][i]]--;
	}
	for (int i = 0; i < 9; i++)
	{
		list[tableBuf[i][y]]--;
	}
	int bigx, bigy;
	bigx = x / 3;
	bigy = y / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			list[tableBuf[bigx * 3 + i][bigy * 3 + j]]--;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		list[i] = list[i] == 1 ? 1 : 0;
	}
}

bool solver::output(bool withExtralEndl)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			lineBuf[2 * j] = tableBuf[i][j] + '0';
		}
		outbuf += lineBuf;
		outbuf += '\n';
	}
	if (withExtralEndl)
	{

		outbuf += '\n';
	}
	return true;
}

bool solver::flush()
{
	if (writeFile.puts(outbuf.c_str()) == EOF)throw runtime_error("写入文件失败");
	return 0;
}