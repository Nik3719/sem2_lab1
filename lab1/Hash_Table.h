#pragma once
#include<iostream>
#include<string>
#include"Tools.h"

using namespace std;



struct HashNode
{
	string key;
	string value;
	bool isOccupied;
	int NoneDeletePresence;
	HashNode() : value(""), key(""), isOccupied(false), NoneDeletePresence(1) {};
};

struct Hash_Table
{
	HashNode* table;
	int size = 0;
	string fileName;
	Hash_Table(int=0);
	~Hash_Table();
	void HSET(string key, string value);
	int hashFunc(string key);
	string HGET(string key);
	string HDEL(string key);
	void resize(string key, string value);
	void PRINT();
//	void LoadHT(string key, string value);
};

