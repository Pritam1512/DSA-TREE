#include<bits/stdc++.h>
using namespace std;

//CREATION OF BINARY SEARCH TREE


struct node
{
    int data;
    struct node *left;
    struct node *right;

}*root = NULL;

void createNode(int data)
{
    struct node *t;
    t = new node;
    t->data = data;
    t->left = t->right = NULL;
    if(root == NULL){
            root = t;
    }
    else
    {
        struct node *curr,*p;
        curr=root;
        while(curr)
        {
            p = curr;
            if(curr->data > t->data)
                curr = curr->left;
            else if(curr->data < t->data)
                curr = curr->right;
            else if(curr->data == t->data)
            {
                cout <<"Same data cannot be inserted in tree" <<endl;
                break;
            }
        }
        if(t->data > p->data)
        {
            p->right = t;
        }
        else if(t->data < p->data)
        {
            p->left = t;
        }

    }
}

void inorder(struct node *temp)
{
    if(temp->left!=NULL)inorder(temp->left);
        cout << temp->data << " ";
    if(temp->right != NULL)inorder(temp->right);


}
int main()
{
    int n,data;
    cout << "Enter the number of node \n";
    cin >> n;

    cout <<"Enter the value for root node\n";
    cin >> data;

    createNode(data);
   for(int i=1;i<n;i++)
    {
        cout << "Enter the data \n";
        cin>>data;
        createNode(data);

    }
    cout << "Inorder traversal of tree is :"<<endl;
    inorder(root);

}
