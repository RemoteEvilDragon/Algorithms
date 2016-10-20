#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <map>
#include <chrono>
#include <thread>

void preOrderTraversal(node *root)
{
    
    cout<<root->character<<",";
    
    if(root->left!=nullptr)
    preOrderTraversal(root->left);
    
    if(root->right!=nullptr)
    preOrderTraversal(root->right);
}


void inOrderTraversal(node *root)
{
    if(root->left!=nullptr)
        inOrderTraversal(root->left);
    
    cout<<root->character<<",";
    
    if(root->right!=nullptr)
        inOrderTraversal(root->right);
}

void postOrderTraversal(node *root)
{
    if(root->left!=nullptr)
        postOrderTraversal(root->left);
    
    if(root->right!=nullptr)
        postOrderTraversal(root->right);
    
    cout<<root->character<<",";
}

int main(int argsNum,const char **args)
{
 node root={0};
    root.character = 'a';
    
    node e = {0};
    e.character = 'e';
    
    node b = {0};
    b.character = 'b';
    
    node d = {0};
    d.character = 'd';
    
    node c = {0};
    c.character = 'c';
    
    b.left = &d;
    d.parent = &b;
    
    b.right = &c;
    c.parent = &b;
    
    b.parent = &e;
    e.left = &b;
    
    e.parent = &root;
    root.left = &e;
    

    preOrderTraversal(&root);
    cout<<endl;
    
    inOrderTraversal(&root);
    cout<<endl;
    
    postOrderTraversal(&root);
    cout<<endl;

    return 0;
}