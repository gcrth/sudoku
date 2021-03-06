#include "stdafx.h"
#include "CppUnitTest.h"
#include "../soduku/generate.h"
#include "../soduku/solve.h"
#include "../soduku/IO.h"
#include "../soduku/soduku.h"
#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForsoduku
{		
	TEST_CLASS(testgenerator)
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
			if (readFile.gets(inBuf, 18) == NULL)Assert::Fail();
			for (int i = 1; i < 9; i++)
			{
				if (readFile.gets(inBuf, 18) == NULL)Assert::Fail();
				for (int j = 0; j < 9; j++)
				{
					tableBuf[i][j] = inBuf[2 * j] - '0';
				}
				if (readFile.gets(inBuf, 18) == NULL)Assert::Fail();
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
		bool testWholeTable()
		{
			char list[10]; bool flag = true;
			for (int i = 0; i < 81; i++)
			{
				if (tableBuf[i / 9][i % 9] == 0)return false;
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
				if(i!=y)list[tableBuf[x][i]]--;
			}
			for (int i = 0; i < 9; i++)
			{
				if(i!=x)list[tableBuf[i][y]]--;
			}
			int bigx, bigy;
			bigx = x / 3;
			bigy = y / 3;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if((bigx * 3 + i)!=x||(bigy * 3 + j)!=y)list[tableBuf[bigx * 3 + i][bigy * 3 + j]]--;
				}
			}
			for (int i = 0; i < 10; i++)
			{
				list[i] = list[i] == 1 ? 1 : 0;
			}
		}
		TEST_METHOD(testgeneratorsmall)
		{
			// TODO: 在此输入测试代码
			int numToGen(100);
			OutFile writeFile("soduku.txt");
			writeFile.open();
			generator(numToGen, writeFile, (char)3);
			writeFile.close();
			InFile readFile("soduku.txt");
			readFile.open();
			for (int i = 0; i < numToGen; i++)
			{
				bool withEndl;
				input(withEndl, readFile);
				if (i != numToGen - 1)
				{
					if (withEndl == false)Assert::Fail();
				}
				else
				{
					if (withEndl == true)Assert::Fail();
				}
				
				if (testWholeTable() == false)Assert::Fail();
			}
		}
		TEST_METHOD(testgeneratorbig)
		{
			// TODO: 在此输入测试代码
			int numToGen(1000000);
			OutFile writeFile("soduku.txt");
			writeFile.open();
			generator(numToGen, writeFile, (char)3);
			writeFile.close();
			InFile readFile("soduku.txt");
			readFile.open();
			for (int i = 0; i < numToGen; i++)
			{
				bool withEndl;
				input(withEndl, readFile);
				if (i != numToGen - 1)
				{
					if (withEndl == false)Assert::Fail();
				}
				else
				{
					if (withEndl == true)Assert::Fail();
				}

				if (testWholeTable() == false)Assert::Fail();
			}
		}
	};
	TEST_CLASS(testsolver)
	{
	public:
		char tableBuf[9][9];
		char inBuf[50];
		bool input(bool &withEndl, InFile &readFile)
		{
			if (readFile.gets(inBuf, 18) == NULL)return false;
			for (int j = 0; j < 9; j++)
			{
				tableBuf[0][j] = inBuf[2 * j] - '0';
			}
			if (readFile.gets(inBuf, 18) == NULL)Assert::Fail();
			for (int i = 1; i < 9; i++)
			{
				if (readFile.gets(inBuf, 18) == NULL)Assert::Fail();
				for (int j = 0; j < 9; j++)
				{
					tableBuf[i][j] = inBuf[2 * j] - '0';
				}
				if (readFile.gets(inBuf, 18) == NULL)Assert::Fail();
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
		bool testWholeTable()
		{
			char list[10]; bool flag = true;
			for (int i = 0; i < 81; i++)
			{
				if (tableBuf[i / 9][i % 9] == 0)return false;
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
				if (i != y)list[tableBuf[x][i]]--;
			}
			for (int i = 0; i < 9; i++)
			{
				if (i != x)list[tableBuf[i][y]]--;
			}
			int bigx, bigy;
			bigx = x / 3;
			bigy = y / 3;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if ((bigx * 3 + i) != x || (bigy * 3 + j) != y)list[tableBuf[bigx * 3 + i][bigy * 3 + j]]--;
				}
			}
			for (int i = 0; i < 10; i++)
			{
				list[i] = list[i] == 1 ? 1 : 0;
			}
		}
		TEST_METHOD(testsolversmall)
		{
			// TODO: 在此输入测试代码
			int numToSol(4);
			OutFile writeFile("soduku.txt");
			writeFile.open();
			InFile testInput("sodukutestsamll.txt");
			//                sodukutestsamll
			testInput.open();
			solver(testInput, writeFile);
			testInput.close();
			writeFile.close();
			InFile readFile("soduku.txt");
			readFile.open();
			for (int i = 0; i < numToSol; i++)
			{
				bool withEndl;
				input(withEndl, readFile);
				if (i != numToSol - 1)
				{
					if (withEndl == false)Assert::Fail();
				}
				else
				{
					if (withEndl == true)Assert::Fail();
				}
				if (testWholeTable() == false)Assert::Fail();				
			}
		}
		TEST_METHOD(testsolverbig)
		{
			// TODO: 在此输入测试代码
			int numToSol(40);
			OutFile writeFile("soduku.txt");
			writeFile.open();
			InFile testInput("sodukutestbig.txt");
			testInput.open();
			solver(testInput, writeFile);
			testInput.close();
			writeFile.close();
			InFile readFile("soduku.txt");
			readFile.open();
			for (int i = 0; i < numToSol; i++)
			{
				bool withEndl;
				input(withEndl, readFile);
				if (i != numToSol - 1)
				{
					if (withEndl == false)Assert::Fail();
				}
				else
				{
					if (withEndl == true)Assert::Fail();
				}
				if (testWholeTable() == false)Assert::Fail();
			}
		}
	};
	TEST_CLASS(tsetmain)
	{
	public:
		char tableBuf[9][9];
		char inBuf[50];
		bool input(bool &withEndl, InFile &readFile)
		{
			if (readFile.gets(inBuf, 18) == NULL)return false;
			for (int j = 0; j < 9; j++)
			{
				tableBuf[0][j] = inBuf[2 * j] - '0';
			}
			if (readFile.gets(inBuf, 18) == NULL)Assert::Fail();
			for (int i = 1; i < 9; i++)
			{
				if (readFile.gets(inBuf, 18) == NULL)Assert::Fail();
				for (int j = 0; j < 9; j++)
				{
					tableBuf[i][j] = inBuf[2 * j] - '0';
				}
				if (readFile.gets(inBuf, 18) == NULL)Assert::Fail();
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
		bool testWholeTable()
		{
			char list[10]; bool flag = true;
			for (int i = 0; i < 81; i++)
			{
				if (tableBuf[i / 9][i % 9] == 0)return false;
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
				if (i != y)list[tableBuf[x][i]]--;
			}
			for (int i = 0; i < 9; i++)
			{
				if (i != x)list[tableBuf[i][y]]--;
			}
			int bigx, bigy;
			bigx = x / 3;
			bigy = y / 3;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if ((bigx * 3 + i) != x || (bigy * 3 + j) != y)list[tableBuf[bigx * 3 + i][bigy * 3 + j]]--;
				}
			}
			for (int i = 0; i < 10; i++)
			{
				list[i] = list[i] == 1 ? 1 : 0;
			}
		}
		TEST_METHOD(testmainsolve)
		{
			int numToSol(4);
			int argc = 3;
			char *argv[3] = {"","-s","sodukutestsamll.txt"};
			int ret;
			ret=appmain(argc, argv);
			Assert::AreEqual(ret, 0);
			InFile readFile("soduku.txt");
			readFile.open();
			for (int i = 0; i < numToSol; i++)
			{
				bool withEndl;
				input(withEndl, readFile);
				if (i != numToSol - 1)
				{
					if (withEndl == false)Assert::Fail();
				}
				else
				{
					if (withEndl == true)Assert::Fail();
				}
				if (testWholeTable() == false)Assert::Fail();
			}
		}
		TEST_METHOD(testmaingenarate)
		{
			int numToSol(40);
			int argc = 3;
			char *argv[3] = { "","-c","40" };
			int ret;
			ret = appmain(argc, argv);
			Assert::AreEqual(ret, 0);

			InFile readFile("soduku.txt");
			readFile.open();
			for (int i = 0; i < numToSol; i++)
			{
				bool withEndl;
				input(withEndl, readFile);
				if (i != numToSol - 1)
				{
					if (withEndl == false)Assert::Fail();
				}
				else
				{
					if (withEndl == true)Assert::Fail();
				}
				if (testWholeTable() == false)Assert::Fail();
			}
		}

		TEST_METHOD(testmainerror1)
		{
			int argc = 2;
			char *argv[2] = { "","-c" };
			int ret;
			ret = appmain(argc, argv);
			Assert::AreEqual(ret, -1);
		}
		TEST_METHOD(testmainerror2)
		{
			int argc = 3;
			char *argv[3] = { "","-c","11ads" };
			int ret;
			ret = appmain(argc, argv);
			Assert::AreEqual(ret, -1);
		}
		TEST_METHOD(testmainerror3)
		{
			int argc = 3;
			char *argv[3] = { "","-ca","40" };
			int ret;
			ret = appmain(argc, argv);
			Assert::AreEqual(ret, -1);
		}
		TEST_METHOD(testmainerror4)
		{
			int argc = 3;
			char *argv[3] = { "","-c","asd" };
			int ret;
			ret = appmain(argc, argv);
			Assert::AreEqual(ret, -1);
		}
		TEST_METHOD(testmainerror5)
		{
			int argc = 3;
			char *argv[3] = { "","-s","asdf" };
			int ret;
			ret = appmain(argc, argv);
			Assert::AreEqual(ret, -2);
		}
	};
}