#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"DNode.h"
#include"Tools.h"

using namespace std;

struct Queue
{
	DNode* front;
	DNode* rear;
	string fileName;
	int len = 0;
	Queue();
	bool isEmpty() { return front == nullptr; }
	~Queue(); 
	void QPUSH(string elem);
	string QPOP();
	string QGET(int index);
	void PRINT();
};