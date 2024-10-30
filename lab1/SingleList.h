#pragma once
#include<string>
#include<iostream>
#include"Tools.h"
#include"Node.h"

using namespace std;




struct SingleList
{
    Node* head;
    int len = 0;
    string fileName;
    //SingleList();
    SingleList(int capacity=0);
    ~SingleList();
    void LSPUSHT(string elem);
    void LSPUSHH(string);
    void PRINT();
    void LSDELH(); // ������� � ������
    void LSDELV(string elem); // ������� �� ��������
    string LSGET(int index);
    int LISINDEX(string);
    string& operator[](int index);



};