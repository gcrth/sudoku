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

char *InFile::gets(char *des, int n = 17)
{
	return fgets(des, n, fp);
}

InFile::~InFile(void)
{
	fclose(fp);
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

bool OutFile::puts(const char *sou)
{
	return fputs(sou, fp);

}

OutFile::~OutFile(void)
{
	fclose(fp);
}
