#pragma once
class InFile
{
private:
	FILE *fp;
	char route[1010];
public:
	InFile(void);
	InFile(const char desroute[]);
	bool bind(const char desroute[]);
	bool open();
	char *gets(char *des, int n = 18);
	int close();
	~InFile(void);
};

class OutFile
{
private:
	FILE *fp;
	char route[1010];
public:
	OutFile(void);
	OutFile(const char desroute[]);
	bool bind(const char desroute[]);
	bool open();
	int puts(const char *sou);
	int close();
	~OutFile(void);
};