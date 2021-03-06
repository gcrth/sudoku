#include "pch.h"
#include <iostream>
#include <string.h>
#include "IO.h"
#include "generate.h"
#include "solve.h"

using namespace std;

enum func{ generate,solve };



bool argumentInput(int argc,char *argv[],char &function,char route[],int &numToGen,InFile &readFile)
{
	if (argc != 3)throw invalid_argument("参数数量出错");
	if (argv[1][0] != '-' || strlen(argv[1]) != 2)
	{
		throw invalid_argument("功能参数格式出错");
	}
	else if (argv[1][1] == 's')
	{
		function = func::solve;
		if (strlen(argv[2]) <= 1000)
		{
			readFile.bind(argv[2]);
		}
		else  throw invalid_argument("路径参数过长");
		if (readFile.open() != true)
		{
			throw runtime_error("打开文件失败");
		}

	}
	else if (argv[1][1] == 'c')
	{
		function = func::generate;
		for (int i = 0; i < (int)strlen(argv[2]); i++)
		{
			if(argv[2][i]<'0'|| argv[2][i]>'9')throw invalid_argument("数量参数出错");
		}
		numToGen = atoi(argv[2]);
		if (numToGen<1 || numToGen>1e6)throw invalid_argument("数量参数出错");
	}
	else
	{
		throw invalid_argument("功能参数不存在");
	}
	return true;
}

int appmain(int argc, char *argv[])
{
	char function;
	char route[1010];
	int numToGen;

	try {
		InFile readFile;
		OutFile writeFile("soduku.txt");
		if (writeFile.open() == false)throw runtime_error("打开文件失败");
		argumentInput(argc, argv, function, route, numToGen, readFile);
		switch (function)
		{
		case func::generate:
		{
			generator gen(numToGen, writeFile, (char)3);
			break;
		}
			
		case func::solve:
		{
			solver sol(readFile, writeFile);
			break;
		}
			
		}

	}
	catch (invalid_argument e)
	{
		cout << "invalid_argument" << e.what() << endl;
		return -1;
	}
	catch (runtime_error e)
	{
		cout << "runtime_error" << e.what() << endl;
		return -2;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	appmain(argc, argv);
	return 0;
}
