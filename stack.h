#pragma once
#include<string>
#include<iostream>
#include"DNode.h"
#include"Tools.h"


using namespace std;

struct Stack
{
	DNode* spointer;
	string fileName;
	int len = 0;
	Stack();
	bool isEmpty() { return spointer == nullptr; }
	~Stack();
	void SPUSH(string elem);
	string SPOP();
	string SGET(int index);
	void PRINT();
	string& operator[](int index);
};