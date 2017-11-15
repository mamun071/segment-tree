#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int ar[MAX];
int tree[MAX*3];
void init(int node,int lo,int hi)
{
    if(lo==hi)
    {
        tree[node]=ar[lo];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(lo+hi)/2;
    init(left,lo,mid);
    init(right,mid+1,hi);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int lo,int hi,int i,int j)
{
    if(j<lo||i>hi)
        return 0;
    if(lo>=i&&hi<=j)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(lo+hi)/2;
    int n1=query(left,lo,mid,i,j);
    int n2=query(right,mid+1,hi,i,j);
    return n1+n2;
}

void update(int node,int lo,int hi,int i,int newvalue)
{
    if(i<lo||i>hi)
        return;
    if(i>=lo&&i<=hi)
        tree[node]=newvalue;
    int left=node*2;
    int right=node*2+1;
    int mid=(lo+hi)/2;
    update(left,lo,mid,i,newvalue);
    update(right,mid+1,hi,i,newvalue);
    tree[node]=tree[left]+tree[right];
}
/*
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        ar[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}*/
main()
{

}
