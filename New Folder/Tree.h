#pragma once
#include<string>
#include<iostream>
#include <iomanip>
#include"Tools.h"
#include"queue.h"

using namespace std;

struct TreeNode
{
    string data; 
    TreeNode* left;   
    TreeNode* right; 
    TreeNode(const std::string& value) : data(value), left(nullptr), right(nullptr) {};
};

struct Tree
{
    TreeNode* root;
    string fileName;
    Tree();
    ~Tree();
    void Allocation(TreeNode* node);
    TreeNode* downTree(TreeNode* node, string value);
    void TINSERT(string elem);
    bool TSEARCH(string elem);
    TreeNode* RightOrLeft(TreeNode* node, string& value);
    int countNodes(TreeNode* node);
    bool TISCOMPLETE();
    bool isComplete(TreeNode* node, int index, int numberNodes);
    int height(TreeNode* node);
    
    void PRINT(TreeNode* root, int space = 0);

    TreeNode* findNode(TreeNode* node, const string& value);

    DL<DL<string>> getLevels();
    void LoadLevel(TreeNode* node, int level, DL<string>& levelValues);

};