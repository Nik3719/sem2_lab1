#pragma once
#include<string>
#include<iostream>
#include"Tools.h"
#include"DNode.h"

using namespace std;




struct DoubleList
{
    DNode* head;
    DNode* tail;
    string fileName;
    int len = 0;
   // DoubleList();
    DoubleList(int capacity=0);
    ~DoubleList();
    void LDPUSHH(string elem);
    void LDPUSHT(string elem);
    void LDDELH();
    void LDDELT();
    void PRINT();
    void LDDELV(string elem);
    int LDISINDEX(string elem);
    string LDGET(int index);
    string& operator[](int index);
};
