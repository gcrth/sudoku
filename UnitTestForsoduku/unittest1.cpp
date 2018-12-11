#include "stdafx.h"
#include "CppUnitTest.h"
#include "../soduku/generate.h"
#include "../soduku/IO.h"
#include "../soduku/soduku.h"
#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForsoduku
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		char tableBuf[9][9];
		char inBuf[50];
		bool input(bool &withEndl,InFile &readFile)
		{
			if (readFile.gets(inBuf, 18) == NULL)return false;
			for (int j = 0; j < 9; j++)
			{
				tableBuf[0][j] = inBuf[2 * j] - '0';
			}
			for (int i = 1; i < 9; i++)
			{
				if (readFile.gets(inBuf, 18) == NULL)Assert::Fail;
				for (int j = 0; j < 9; j++)
				{
					tableBuf[i][j] = inBuf[2 * j] - '0';
				}
			}
			if (readFile.gets(inBuf, 18) == NULL)
			{
				withEndl = true;
			}
			else
			{
				withEndl = false;
			}
			return true;
		}
		bool testWholeTable()
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
		void searchAvalibleNumber(char x, char y, char list[])
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
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			int numToGen(100);
			OutFile writeFile("soduku.txt");
			generator(numToGen, writeFile, (char)3);
			writeFile.close();
			InFile readFile("soduku.txt");
			for (int i = 0; i < numToGen; i++)
			{
				bool withEndl;
				input(withEndl, readFile);
				if (i != numToGen - 1)
				{
					if (withEndl == false)Assert::Fail;
				}
				else
				{
					if (withEndl == true)Assert::Fail;
				}
				if (testWholeTable() == false)Assert::Fail;
			}
		}

	};


}