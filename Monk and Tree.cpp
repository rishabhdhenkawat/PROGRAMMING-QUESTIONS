
/*
Monk has an array 
A
A having 
N
N distinct integers and a Binary Search Tree which is initially empty. He inserts all the elements of the array from index 
1
1 to 
N
N in the BST in the order given in the array. But wait! The tree so formed turns out to be cursed. Monk is having some weird experiences since he made that tree.
So, now to stop all that, Monk has two options, to destroy the BST or to pray to God and ask for a solution. Now since Monk has to use this BST in a Code Monk Challenge, he cannot destroy it. So he prays to God.
God answer his prayers and sends an angel named Micro. Now, Micro asks Monk to find something. He tells him two values, 
X
X and 
Y
Y, present in the BST and ask him to find the maximum value that lie in the path between node having value 
X
X and node having value 
Y
Y. (including 
X
X and 
Y
Y ).
Now since, Monk is very afraid of that tree he asks for your help.
Input:
First line consists of a single integer denoting 
N
N.
Second line consists of 
N
N space separated integers denoting the array 
A
A.
Third line consists of two space separated integers denoting 
X
X and 
Y
Y.
Output:
Print the maximum value that lie in the path from node having value 
X
X and node having value 
Y
Y in a new line.
Source : Hackerearth
*/


#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node* create(int data)
{
    struct Node* temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->left=0;
    temp->right=0;
    return temp;
}

void insert(struct Node *root,int data)
{
    if(data>root->data)
    {
        if(root->right==0)
        {
            root->right=create(data);
        }
        else
        {
            insert(root->right,data);
        }
    }
    else
    {
        if(root->left==0)
        {
            root->left=create(data);
        }
        else
        {
            insert(root->left,data);
        }
    }
}

struct Node* findCommonRoot(struct Node* root,int x, int y)
{
    if(x>root->data && y >root->data)
    {
        return findCommonRoot(root->right,x,y);
    }
    else if(x<root->data && y<root->data)
    {
      return findCommonRoot(root->left,x,y);
    }
    else
    {
        return root;
    }
}

int findMax(struct Node * parent, int x,int max) 
{
    if (max<parent->data)
    {
        max=parent->data;
    }
    
    if(x==parent->data)
    {
        return max;   
    }
    else if(x>parent->data)
    {
        return findMax(parent->right,x,max);
    }
    else if(x<parent->data)
    {
        return findMax(parent->left,x,max);
    }
}

int main()
{
    int n,x,y;
    int data;
    cin>>n;
    cin>>data;
    struct Node*root=create(data);
    for(int i=0;i<n-1;i++)
    {
        cin>>data;
        insert(root,data);
    }
    cin>>x>>y;
    struct Node* parent=findCommonRoot(root,x,y);
    int max1=findMax(parent,x,0);
    int max2=findMax(parent,y,0);
    
    if(max2>max1)
    {
        cout<<max2;
    }
    else
    {
        cout<<max1;
    }

    
    
    return 0;
}

