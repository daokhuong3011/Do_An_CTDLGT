#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

typedef struct Words
{
	char tu[20];
	char loaiTu[10];
	struct nghia;
	struct listvidu;
}words;

typedef struct TuDien
{
	words info;
	struct TuDien *left, *right;
}tudien;
typedef tudien *NODEPTR;
NODEPTR First, Last;

typedef struct Nghia
{
	string info;	
	struct Nghia *next;	
}nghia;
typedef nghia *PTR;

typedef struct 
{
	int n;
	string *nodes[5];
}listvidu;

int main()
{

	return 0;
}


