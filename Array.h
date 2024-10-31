#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Tools.h"


using namespace std;

struct Array
{
    int capacity = 0;
    int currentLen = 0;
    string fileName;
    string Name;
    string* arr = nullptr;
    Array(int capacity = 0, string filename = "", string Name = "");
    ~Array();
    Array(Array& other);
    Array& operator=(const Array& other);

    void MPUSH(string elem);
    void MINSERT(string elem, int index);
    string MGET(int index);
    int MLEN();
    void MDEL(int index);
    void PRINT();
    void MSET(string elem, int index);
};

