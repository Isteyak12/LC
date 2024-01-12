#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct BST
{
    int data = 0;
    BST *left = nullptr;
    BST *right = nullptr;
    BST(int data)
    {
        this->data = data;
    }
};

void insert(BST *&root, int data)
{
    BST *curr = root;
    if (root == nullptr)
    {
        root = new BST(data);
    }
    else
    {
        if (data < curr->data)
        {
            insert(curr->left, data);
        }
        else
        {
            insert(curr->right, data);
        }
    }
}

void display(BST *&root)
{
    BST *curr = root;
    if (root == nullptr)
    {
        cout << "Errrr" << endl;
    }
    else
    {
        display(curr->left);
        cout << "Error on White " << curr->data << endl;
        display(curr->right);
    }
}

void del(BST *&root, int target)
{
    BST *curr = root;
    if (root->left == nullptr && root->right == nullptr)
    {
        root = nullptr;
    }
    else
    {
        if (curr->left->data > data)
        {
            // one child
            del(curr->left, target);
        }
    }
}

int main()
{

    return 0;
}