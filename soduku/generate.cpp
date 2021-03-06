#include "pch.h"
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#include "IO.h"
#include "generate.h"
#include <string>

generator::generator(int numToGen_, OutFile &writeFile_, char firstElement ) :writeFile(writeFile_)
{
	numToGen = numToGen_;
	theFirstLine[0] = firstElement;
	for (int i = 0; i < 9; i++)
	{
		if (i != 0)theFirstLine[i] = i < firstElement ? i : i + 1;
		if (i != 8)lineBuf[2 * i + 1] = ' ';
		else lineBuf[2 * i + 1] = '\0';
	}
	outbuf.reserve(170*numToGen);
	outbuf.clear();
	run();
}

bool generator::run()
{
	int numOfRow;
	numOfRow = numToGen / 144;
	for (int i = 0; i < numOfRow; i++)
	{
		for (int j = 0; j < 144; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				for (int l = 0; l < 9; l++)
				{
					tableBuf[k][l] = theFirstLine[(l + changelist[j][k]) % 9];
				}
			}
			output(true);
		}
		next_permutation(theFirstLine + 1, theFirstLine + 8);
	}
	numOfRow = numToGen % 144;
	for (int i = 0; i < numOfRow; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			for (int l = 0; l < 9; l++)
			{
				tableBuf[k][l] = theFirstLine[(l + changelist[i][k]) % 9];
			}
		}
		if (i == numOfRow - 1)
			output(false);
		else output(true);
	}
	flush();
	return true;
}

bool generator::output(bool withExtralEndl)
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

bool generator::flush()
{
	if (writeFile.puts(outbuf.c_str()) == EOF)throw runtime_error("д���ļ�ʧ��");
	return 0;
}
