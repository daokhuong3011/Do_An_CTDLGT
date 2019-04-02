//--Dictionary--
//Tra cuu tu dien: to chuc tu dien theo danh sach lien ket kep. Moi tu gom co cac thong tin: Tu, loai tu, cac
//nghia Viet (theo cau truc danh sach lien ket), cac vi du (theo cau truc mang con tro, toi da 5 vd).
//
//Chuong trinh co cac chuc nang: nhap tu moi, hieu chinh tu, xoa tu, tra tu theo 2 cach: nhap den dau thi thanh 
//sang se nhay ngay den tu dau tien co cac ky tu dau trung voi cac ky tu vua nhap.
//Hoac dung thanh sang di chuyen den tu can tra, ghi tu vao file, load tu vao DSLK kep...
// 
//Note:
//Danh sach cac tu duoc to chuc theo cau truc bang bam
//Cac thuat toan xu ly tren tu dien deu thuc hien trong bo nho trong.
//File chi la noi luu cac tu khi co su thay doi tren tu dien trong bo nho trong.


//Danh sach viec can lam: nghien cuu graphic.h, 
//Bang ma ascii: https://theasciicode.com.ar/


#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>

typedef struct Mean //Danh sach lien ket
{
	string data;	
	struct Mean *next;	
}mean;
//typedef mean *PTR;

typedef struct  //Mang con tro
{
	int n;
	string *nodes[5];
}exlist;

typedef struct Words 
{
	char tu[20];
	char loaitu[10];
	mean* First;
	exlist exnode;
}words;

typedef struct TuDien //Danh sach lien ket kep
{
	words info;
	struct TuDien *left, *right;
}tudien;
//typedef tudien *NODEPTR;
//NODEPTR First, Last;

typedef struct HashTable //Bang bam
{
	tudien *head, *tail;
}hashtable;

//Prototype:
//Function of mean words linklist:
void insert_first_linklist();
void insert_word_last();
void tap_tudien();
//Function of display:
//Function of 
void gotoxy();
void setcolor();
void nocursortype();
void input_new_word();
void output();
void saveFile();
void loadFile();

int main()
{
	hashtable *hash = new hashtable[26];
	mean *First = NULL;
	for(int i=0; i<26; i++) hash[i].head=hash[i].tail=NULL;
	return 0;
}

void gotoxy(int x, int y) //Ham cai dat con tro trong console
{
	static HANDLE h = NULL;  
	if(!h)
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };  
	SetConsoleCursorPosition(h,c);
}

void setcolor(short x) //Ham thay doi textcolor va backgroundcolor
{ 
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, x);
}
void Nocursortype() //Ham an con tro trong console
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void insert_first_linklist(mean *&First, string nghia)
{
	mean *p = new mean;
	p->data = nghia;
	p->next = First;
	if(First == NULL) First = p;
	else 
	{
		p->next = First;
		First = p;
	}
}

void insert_word_last_linklist(hashtable *&dic, mean *p)
{
	
}

void saveFile(hashtable *&dic)
{
	ifstream f("DICTIONARY");
	if(f.is_open())
	{
		
	}
}

void loadFile(hashtable *&dic)
{
	ofstream f("DICTIONARY");
	if(f.is_open())
	{
		for(int i=0; i<26; i++)
		{
			tudien *p = dic[i].head;
			while(p!=NULL)
			{
				f<<p->info.tu<<"||";
				f<<p->info.loaitu<<"||";
				//dieu kien dung neu nguoi dung khong muon nhap them nghia
			}
			f<<"||";
			mean *na = p->info.First;
			while(na != NULL)
			{
				f<<na->data<<";";
				na = na->next;
			}
			f<<"||\n";
			p = p->right;
		}
	}
	f.close();
}

int tap_tudien(string word)
{
	if(word != "")
	{
		char x = word[0];
		if(x > 96 && x < 123) return (x-97);
	}
	return -1;
}
//Bo sung chen vao dau danh sach (neu can), them 1 ham` add xet tung truong hop
void insert_word_last(hashtable *&dic, tudien *&td) //dslk kep (2 cach)
{
	int x = tap_tudien(td->info.tu);
	if(dic[x].head == NULL) dic[x].head = dic[x].tail = td;
	else
	{
		dic[x].tail->right = td;
		td->left = dic[x].tail;
		dic[x].tail = td;
	}
}


