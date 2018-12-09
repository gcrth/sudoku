#include <iostream>
#include <string.h>
#include <algorithm>
#include "IO.h"
#include "generate.h"
using namespace std;

generator::generator(int numToGen_, OutFile writeFile_, char firstElement = 3) :writeFile(writeFile_)
{
	numToGen = numToGen_;
	theFirstLine[0] = firstElement;
	for (int i = 1; i < 9; i++)
	{
		theFirstLine[i] = i < firstElement ? i + 1 : i;
		if (i != 8)lineBuf[2 * i + 1] = ' ';
		else lineBuf[2 * i + 1] = '\0';
	}

	this->run();
}

bool generator::run()
{
	int numOfRow;
	numOfRow = numOfRow / 144;
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
		if (i == numOfRow - 1)output(false);
		else output(true);
	}
}

bool generator::output(bool withExtralEndl = true)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			lineBuf[2 * j] = tableBuf[i][j] + '0';
		}
		if (writeFile.puts(lineBuf) == EOF)throw runtime_error("写入文件失败");

		if (writeFile.puts("\n") == EOF)throw runtime_error("写入文件失败");
	}
	if (withExtralEndl)
	{
		if (writeFile.puts("\n") == EOF)throw runtime_error("写入文件失败");
	}
	return true;
}
