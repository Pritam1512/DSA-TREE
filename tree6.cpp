#include<bits/stdc++.h>
using namespace std;

//count number of nodes in a tree

struct node
{
    struct node *left;
    int data;
    struct node *right;

}*root = NULL;

int countNodes(struct node *temp)
{
    int x , y;
    if(temp == NULL)
        return 0;
    else
    {
        x = countNodes(temp->left);
        y = countNodes(temp->right);

        return x+y+1;
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



    cout <<"No of nodes in tree "<<endl;
    int n = countNodes(root);
    cout << n << endl;
    return 0;
}

