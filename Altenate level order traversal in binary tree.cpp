#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int k)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=k;
    newnode->left=NULL;
    newnode->right=NULL;
};

void print(struct node *root)
{
    stack<struct node *> st1;
    stack<struct node *> st2;
    st1.push(root);
    struct node *temp;
    while(!st1.empty() || !st2.empty())
    {
        while(!st1.empty())
        {
            temp=st1.top();
            st1.pop();
            printf("%d ",temp->data);
            if(temp->left!=NULL)
                st2.push(temp->left);
            if(temp->right!=NULL)
                st2.push(temp->right);
        }

        while(!st2.empty())
        {
            temp=st2.top();
            st2.pop();
            printf("%d ",temp->data);
            if(temp->right!=NULL)
                st1.push(temp->right);
            if(temp->left!=NULL)
                st1.push(temp->left);
        }
    }
}

int main()
{
    struct node *root;
    root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    root->left->left->left=newnode(8);
    root->left->left->right=newnode(9);
    root->left->right->left=newnode(10);
    root->left->right->right=newnode(11);
    root->right->right->left=newnode(14);
    root->right->right->right=newnode(15);


    print(root);
}
