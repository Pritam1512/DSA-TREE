
//binary tree creation using queue data structure

#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node *left;
    int data;
    struct node *right;

}*root = NULL;

void inorder(struct node *temp)
{
    if(temp == NULL)
        return ;
    inorder(temp->left);
        cout << temp->data <<" ";
    inorder(temp->right);
}
int main()
{
    struct node *temp;;
    queue<struct node *> q;
    int n;
    cout << "Enter the root node \n";
    cin >> n;
    root = (struct node*)malloc(sizeof(struct node));
    root->data = n;
    root->left = root->right = NULL;
    q.push(root);
    while(!q.empty())
    {
       temp = q.front();
       q.pop();

       cout << "Enter the left child\n";
       cin >> n;
       if(n != -1){
           struct node *t;
           t = (struct node*)malloc(sizeof(struct node));
           t->data = n;
           t->left = t->right = NULL;
           temp->left = t;
           q.push(t);
       }

       cout << "Enter the right child\n";
       cin >> n;

       if(n != -1)
       {
           struct node *r;
           r = (struct node*)malloc(sizeof(struct node));
           r->data = n;
           r->right = r->left = NULL;
           temp->right = r;
           q.push(r);
       }


    }

    cout << "InOrder representation  of tree is " <<endl;
    inorder(root);
    return 0;
}
