#pragma once
#include<string>
using namespace std;

struct Node
{
    string data;        // ������ ����
    Node* next;     // ��������� �� ��������� ����

    Node(string value) : data(value), next(nullptr) {} // �����������
};