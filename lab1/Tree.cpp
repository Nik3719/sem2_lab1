#include"Tree.h"

static string TID = "0";

Tree::Tree() : root(nullptr)
{
    fileName = "Tree" + TID + ".data";
    PlusOne(TID);
    ofstream createFile(fileName);
    createFile.close();
}
Tree::~Tree()
{
    Allocation(root);
}
void Tree::LoadLevel(TreeNode* node, int level)
{
    ofstream fwr(fileName,ios::app);
    if (node == nullptr)
    {
        return;
    }
    if (level == 1)
    {
        fwr << node->data << " ";
    }
    else if (level > 1)
    {
        LoadLevel(node->left, level - 1);
        LoadLevel(node->right, level - 1);
    }
    fwr.close();
}
void Tree::LoadTree()
{
    ofstream clear(fileName);
    clear.close();

    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        LoadLevel(root, i);
        ofstream fwr(fileName, ios::app);
        fwr << "\n";
        fwr.close();
        // Переход на новую строку после каждого уровня
    }
}

void Tree::Allocation(TreeNode* node)
{
    if (node != nullptr) 
    {
        Allocation(node->left);
        Allocation(node->right);
        delete node;
    }
}

TreeNode* Tree::downTree(TreeNode* node, string value)
{
    if (node == nullptr) {
        return new TreeNode(value);
    }
    if (value < node->data) {
        node->left = downTree(node->left, value);
    }
    else if (value > node->data) {
        node->right = downTree(node->right, value);
    }
    return node;
}


void Tree::TINSERT(string elem)
{
    root = downTree(root, elem);
    LoadTree();

}

bool Tree::TSEARCH(string elem)
{
    return RightOrLeft(root, elem) != nullptr;
}

TreeNode* Tree:: RightOrLeft(TreeNode* node,string& value)
{
    if (node == nullptr || node->data == value) 
    {
        return node;
    }
    if (value < node->data) 
    {
        return RightOrLeft(node->left, value);
    }
    else 
    {
        return RightOrLeft(node->right, value);
    }
}






bool Tree::isComplete(TreeNode* node, int index, int numberNodes) 
{
    if (node == nullptr) 
    {
        return true;
    }
    if (index >= numberNodes)
    {
        return false;
    }
    return isComplete(node->left, 2 * index + 1, numberNodes) && isComplete(node->right, 2 * index + 2, numberNodes);
                         // левый дочерний узел                                         правый дочерний узел
}
int Tree::countNodes(TreeNode* node) 
{
    if (node == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}
bool Tree::TISCOMPLETE()
{
    int nodeCount = countNodes(root);
    return isComplete(root, 0, nodeCount);
}


int Tree::height(TreeNode* node) 
{
    if (node == nullptr) 
    {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    return  rightHeight + 1;
}



void Tree::PRINT(TreeNode* root, int space)
{
    if (!root)
    {
        return;
    }  
    space += 2;
    PRINT(root->right, space);
    for (int i = 2; i < space; ++i)
        cout << "  ";
    cout << root->data << endl;
    PRINT(root->left, space);
}

// Вспомогательный метод для поиска узла по значению
TreeNode* Tree::findNode(TreeNode* node, const string& value)
{
    if (node == nullptr) {
        return nullptr;
    }
    if (node->data == value) {
        return node;
    }
    TreeNode* leftResult = findNode(node->left, value);
    if (leftResult != nullptr) {
        return leftResult;
    }
    return findNode(node->right, value);
}

DL<DL<string>> Tree::getLevels() 
{
    DL<DL<string>> levels;
    int h = height(root);
    for (int i = 1; i <= h; i++) 
    {
        DL<string> levelValues;
        LoadLevel(root, i, levelValues);
        levels.LDPUSHT(levelValues);
    }
    return levels;
}

void Tree::LoadLevel(TreeNode* node, int level, DL<string>& levelValues)
{
    if (node == nullptr) 
    {
        return;
    }
    if (level == 1) 
    {
        levelValues.LDPUSHT(node->data);
    }
    else if (level > 1)
    {
        LoadLevel(node->left, level - 1, levelValues);
        LoadLevel(node->right, level - 1, levelValues);
    }
}