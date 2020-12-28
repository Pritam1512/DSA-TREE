#include<bits/stdc++.h>
using namespace std;

//count number of nodes in a tree
//count height of tree
//count number of leaf nodes
//count number of nodes with degree 2
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
int height(struct node *temp)
{
    int x=0,y=0;
    if(temp == NULL)
        return -1;
    else
    {
       x = height(temp->left);
       y = height(temp->right);
       if(x > y)
            return x+1;
       else
            return y+1;
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
int countLeafNodes(struct node *temp)
{
    int x,y,leaf = 0;
    if(temp == NULL)
        return 0;
    else
    {
        x = countLeafNodes(temp->left);
        y = countLeafNodes(temp->right);

        if(temp->left == NULL && temp->right == NULL)
                return x+y+1;
        else
            return x+y;

    }



}

int count2Nodes(struct node *temp)
{
    int x,y,leaf = 0;
    if(temp == NULL)
        return 0;
    else
    {
        x = count2Nodes(temp->left);
        y = count2Nodes(temp->right);

        if(temp->left != NULL && temp->right != NULL)
                return x+y+1;
        else
            return x+y;

    }



}

int main()
{
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->left->left = createNode(5);
    root->left->left->right = createNode(6);



    cout <<"No of nodes in tree "<<endl;
    int n = countNodes(root);
    cout << n << endl;

    cout <<"Height of tree is \n";
    cout << height(root);
    cout <<""<<endl;
    cout <<"Number of leaf nodes\n";
    cout << countLeafNodes(root);

     cout <<""<<endl;
    cout <<"Number of 2 degree nodes\n";
    cout << count2Nodes(root);
    return 0;
}

