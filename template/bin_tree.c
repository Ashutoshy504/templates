#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
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
int maxpath(node* node,int x)
{     //node* node=node1;
    int m=INT_MIN;
    while(node->data!=x)
    {
     m=max(m,node->data);
     if(node->data>x)
     node=node->left;
     else
     node=node->right;
    }
    return max(x,m);
}
int maxele(node* p,int x,int y)
{
    //node *p=root;
    while(x>p->data&&y>p->data||x<p->data&&y<p->data)
    {
        if(x>p->data&&y>p->data)
        p=p->right;
        else
        p=p->left;
    }
    return max(maxpath(p,x),maxpath(p,y));
}
int main()
{
    fast
    node* root;
    int n,num,i,x,y;
    cin>>n;
    cin>>num;
   // root=insert(root,num);
    for(i=0;i<n;i++)
    {
        cin>>num;
       root= insert(root,num);
    }
    cin>>x>>y;
    cout<<maxele(root,x,y);
}
