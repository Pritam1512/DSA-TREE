//Level Order traversal of tree
//using queue data structure

#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node *left;
    int data;
    struct node *right;

}*root = NULL;

struct node * createNode(int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return(temp);

}

void inorder(struct node *temp)
{
    if(temp == NULL)
        return ;
    inorder(temp->left);
        cout << temp->data << " ";
    inorder(temp->right);
}

void levelOrder(struct node *temp)
{
    queue<struct node *> q;
    q.push(temp);

    while(!q.empty())
    {
        struct node *t;
        t = q.front();
        q.pop();
        cout << t->data <<" ";
        if(t->left != NULL)q.push(t->left);
        if(t->right!= NULL)q.push(t->right);
    }
}
int main()
{
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

   cout <<"InOrder traversal of tree is: "<<endl;
   inorder(root);
    cout << "" <<endl;
   cout << "level order traversal of tree is: "<<endl;
   levelOrder(root);

    return 0;
}
