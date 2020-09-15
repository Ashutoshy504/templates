#include<bits/stdc++.h>
using namespace std;
struct node  {
    int data;
    node *left;
    node *right;
};
node* new_node (int data)
{   node* node1=new node();
node1->data=data;
node1->left=NULL;
node1->right=NULL;
    return node1;

}
node* insert(node* node1, int data)
{
    if(node1==NULL)
    {
        return (new_node(data));
    }
    else
    {
        if(data<=node1->data)
            node1->left=insert(node1->left,data);
        else
            node1->right=insert(node1->right,data);
    }
    return node1;
}
int minval(node* node)
{
    if(node->left==NULL)
        return node->data;
    else
        return minval(node->left);
}

int main(){
    node* root=NULL;

   root=insert(root,5);
   insert(root,6);
   insert(root,8);
   insert(root,10);
   insert(root,1);
   cout<<"minval"<<minval(root);
return 0;
}


