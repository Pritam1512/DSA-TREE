#include<bits/stdc++.h>
using namespace std;

//PREORDER USING STACK

struct node
{
    struct node *left;
    int data;
    struct node *right;

}*root = NULL;



void preOrderIter(struct node* temp)
{
    struct node *t;
    stack<struct node*> s;
    s.push(temp);
    while(!s.empty())
    {
        t = s.top();
        s.pop();
        cout << t->data << " ";

         if(t->right!= NULL)s.push(t->right);
         if(t->left!= NULL)s.push(t->left);

    }



}


struct node * createNode(int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return(temp);

}


int main()
{
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);


   cout <<"Pre order using iteration\n";
    preOrderIter(root);


    return 0;
}

