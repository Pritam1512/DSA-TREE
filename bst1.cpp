#include<bits/stdc++.h>
using namespace std;

//CREATION OF BINARY SEARCH TREE
//NO OF 2DEGREE NODES
//NO OF LEAF NODES
//MIRROR OF THE TREE
////SUM OF TOTAL NODES
//LEVEL ORDER TRAVERSAL


int sum = 0;
int arr[10];
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
int height(struct node *temp)
{
    int h;
    if(temp == NULL)
        return -1;
    else{
       int x = height(temp->left);
       int y = height(temp->right);

       if(x > y)
            h = x+1;
       else
            h = y+1;
       return h;
    }
}

int leafNodes(struct node *temp)
{
    if(temp == NULL)
        return 0;
    else
    {
      int x = leafNodes(temp->left);
      int y = leafNodes(temp->right);

      if(temp->left == NULL && temp->right == NULL )
            return x+y+1;
      else
            return x+y;
    }
}
int twoDegreeNodes(struct node *temp)
{
    if(temp == NULL)
        return 0;
    else
    {
        int x = twoDegreeNodes(temp->left);
        int y = twoDegreeNodes(temp->right);
        if(temp->left != NULL && temp->right != NULL)
            return x+y+1;
        else
            return x+y;
    }
}
int sumN(struct node*temp)
{

    if(temp == NULL)
        return 0;
    else
    {
        sumN(temp->left);
        sumN(temp->right);
        sum = sum + temp->data;
    }
    return sum;
}
void levelOrder(struct node *temp)
{
    int k=0;
    queue<struct node*> q;
    q.push(temp);

    while(!q.empty())
    {
        struct node *t;
        t = q.front();
        q.pop();
        cout << t->data <<" ";
        if(t->left!=NULL)q.push(t->left);
        if(t->right!=NULL)q.push(t->right);
    }

}

void mirrorTree(struct node *temp)
{
    if(temp == NULL)
        return ;
    else
    {
        mirrorTree(temp->left);
        mirrorTree(temp->right);

        struct node *t = temp->left;
        temp->left = temp->right;
        temp->right = t;
    }
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
    cout <<"" <<endl;
    cout << "Height of tree is :" <<endl;
    cout << height(root);
    cout << "" <<endl;
    cout << "Number of leaf nodes is: "<<endl;
    cout << leafNodes(root) <<endl;

     cout << "Number of two degree nodes is: "<<endl;
    cout << twoDegreeNodes(root) <<endl;

    cout << "Level order traversal of tree is : "<<endl;
    levelOrder(root);

    cout <<""<<endl;
    cout << "Sum of all nodes is :" <<endl;
    cout << sumN(root) <<endl;

    cout << "After mirroring the tree :" <<endl;
    mirrorTree(root);

    cout << "Level order traversal of tree after mirroring is : "<<endl;
    levelOrder(root);




}
