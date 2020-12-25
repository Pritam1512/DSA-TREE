#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node *left;
    int data;
    struct node *right;

}*head = NULL;

struct node *CreateNode(int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;


}

void inorder(struct node *temp)
{
   if(temp == NULL)
        return ;
   inorder(temp->left);
        cout << temp->data << " ";
   inorder(temp->right);

}

void preOrder(struct node *temp)
{
    if(temp == NULL)
        return ;

    cout << temp->data << " ";
   preOrder(temp->left);
   preOrder(temp->right);

}


void someRandomOrder(struct node *temp)
{
    if(temp == NULL)
        return;
    someRandomOrder(temp->right);
    cout << temp->data <<" ";
    someRandomOrder(temp->left);

}

int height(struct node *temp)
{
    int lh;
    int rh;
    int h;
    if(temp == NULL)
        return -1;

    lh = height(temp->left);
    rh = height(temp->right);

    if(lh > rh)
        h = lh+1;
    else
        h = rh+1;

    return h;
}
int main()
{

    head = CreateNode(1);
    head->left = CreateNode(2);
    head->right = CreateNode(3);
    head->left->left = CreateNode(4);
    head->left->right = CreateNode(5);

    cout << "InOrder representation of tree is:" <<endl;
    inorder(head);
    cout << "" <<endl;
    cout << " PreOrder representation of tree is :" <<endl;
    preOrder(head);
    cout <<"" <<endl;
    cout << "Some random order is:" <<endl;
    someRandomOrder(head);

    cout << "Height of tree is : "<<height(head);

    return 0;
}
