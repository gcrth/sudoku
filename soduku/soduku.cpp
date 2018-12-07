#include "pch.h"
#include <iostream>
#include<string.h>
using namespace std;

enum func{ generate,solve };

class InFile
{
private:
	FILE *fp;
	char route[1010];
public:
	InFile(void)
	{

	}
	InFile(const char desroute[])
	{
		strcpy(route, desroute);
	}
	bool bind(const char desroute[])
	{
		if (strlen(desroute) < 1000)
		{
			strcpy(route, desroute);
			return true;
		}
		else return false;
	}
	bool open()
	{
		fp = fopen(route, "r+");
		return (fp != NULL);
	}
	char *gets(char *des, int n = 17)
	{
		return fgets(des, n, fp);
	}
	~InFile(void)
	{
		fclose(fp);
	}
};

class OutFile
{
private:
	FILE *fp;
	char route[1010];
public:
	OutFile(void)
	{

	}
	OutFile(const char desroute[])
	{
		strcpy(route, desroute);
	}
	bool bind(const char desroute[])
	{
		if (strlen(desroute) < 1000)
		{
			strcpy(route, desroute);
			return true;
		}
		else return false;
	}
	bool open()
	{
		fp = fopen(route, "w+");
		return (fp != NULL);
	}
	bool puts(char *sou)
	{
		return fputs(sou, fp);

	}
	~OutFile(void)
	{
		fclose(fp);
	}
};

bool argumentInput(int argc,char *argv[],char &function,char route[],int &numToGen,InFile &readFile)
{
	if (argc != 3)throw invalid_argument("参数数量出错");
	if (argv[1][0] == '-' || strlen(argv[1]) != 2)
	{
		throw invalid_argument("功能参数格式出错");
	}
	else if (argv[1][2] == 's')
	{
		function = solve;
		if (strlen(argv[2]) <= 1000)
		{
			readFile.bind(argv[2]);
		}
		else  throw invalid_argument("路径参数过长");
		if (readFile.open() != true)
		{
			throw new runtime_error("打开文件失败");
		}

	}
	else if (argv[1][2] == 'c')
	{
		function = generate;
		numToGen = atoi(argv[2]);
		if (numToGen<1 || numToGen>1e6)throw invalid_argument("数量参数出错");
	}
	else
	{
		throw invalid_argument("功能参数不存在");
	}
	return true;
}

int main(int argc, char *argv[])
{
	char function;
	char route[1010];
	int numToGen;

	InFile readFile;
	OutFile outFile("soduku.txt");

	try {
		argumentInput(argc, argv, function, route, numToGen, readFile);
		switch (function)
		{
		case generate:

			break;
		case solve:

			break;
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
