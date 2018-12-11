#include "pch.h"
#include <iostream>
#include <string.h>
#include "IO.h"

InFile::InFile(void) {}

InFile::InFile(const char desroute[])
{
	strcpy(route, desroute);
}

bool InFile::bind(const char desroute[])
{
	if (strlen(desroute) < 1000)
	{
		strcpy(route, desroute);
		return true;
	}
	else return false;
}

bool InFile::open()
{
	fp = fopen(route, "r+");
	return (fp != NULL);
}

char *InFile::gets(char *des, int n)
{
	return fgets(des, n, fp);
}

int InFile::close()
{
	if (fp != NULL)return fclose(fp);
	else return 0;
}

InFile::~InFile(void)
{
	if (fp != NULL)fclose(fp);
}

OutFile::OutFile(void) {}

OutFile::OutFile(const char desroute[])
{
	strcpy(route, desroute);
}

bool OutFile::bind(const char desroute[])
{
	if (strlen(desroute) < 1000)
	{
		strcpy(route, desroute);
		return true;
	}
	else return false;
}

bool OutFile::open()
{
	fp = fopen(route, "w+");
	return (fp != NULL);
}

int OutFile::puts(const char *sou)
{
	return fputs(sou, fp);

}

int OutFile::close()
{
	if (fp != NULL)return fclose(fp);
	else return 0;
}

OutFile::~OutFile(void)
{
	if (fp != NULL)fclose(fp);
}
