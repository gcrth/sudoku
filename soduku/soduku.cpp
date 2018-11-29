#include "pch.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	char function;
	try {
		if (argc != 3)throw invalid_argument("参数数量出错");
	}
	catch (invalid_argument e)
	{
		cout << "invalid_argument" <<e.what()<< endl;
	}
	catch (out_of_range e)
	{
		cout << "out_of_range" << endl;
	}

}
