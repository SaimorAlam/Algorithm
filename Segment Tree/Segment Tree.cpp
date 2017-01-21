#include<bits/stdc++.h>
#define mx (int)1e5
#define tlop(i,a,b) for(int i=a;i<=b;i++)
#define lop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int tree[mx*3];
int in[mx];
//int in[]={4,-9,3,7,1,0,2};
///ans of build tree. tree[]={8,5,3,-5,10,1,2,4,-9,3,7,1,0,2}
void build(int pos,int l,int r){
    if(l==r){tree[pos]=in[r];return;}
    int mid=(l+r)/2,left=pos*2,right=pos*2+1;
    build(left,l,mid);
    build(right,mid+1,r);
    tree[pos]=tree[left]+tree[right];
}
///Input: 4 -9 3 7 1 0 2
void build(int n){
    for(int i=n-1;i>0;i--) tree[i]=tree[i*2]+tree[i*2+1];
}
int query(int pos,int l,int r,int i,int j){
    if(i>r||j<l) return 0;
    if(l>=i&&r<=j) return tree[pos];
    int mid=(l+r)/2,left=pos*2,right=pos*2+1;
    int x=query(left,l,mid,i,j),y=query(right,mid+1,r,i,j);
    return x+y;
}
int query(int l,int r,int n){       ///it's query index start's with 0
    int ret=0;
    for(l+=n,r+=n;l<=r;l=(l+1)/2,r=(r-1)/2){
        if(l&1) ret+=tree[l];
        if(!(r&1)) ret+=tree[r];
    }
    return ret;
}
void update(int pos,int l,int r,int idx,int value){
    if(idx>r||idx<l) return;
    if(l>=idx&&r<=idx) {tree[pos]=value;return;}
    int mid=(l+r)/2,left=pos*2,right=pos*2+1;
    update(left,l,mid,idx,value);
    update(right,mid+1,r,idx,value);
    tree[pos]=tree[left]+tree[right];
}
void update(int p,int v,int n){
    for(tree[p+=n]=v;p>=1;p/=2) tree[p/2]=tree[p]+tree[p^1];
}
void print(int n){
    for(int i=1;i<=2*n-1;i++) cout<<i<<" = "<<tree[i]<<endl;
}

void recursive_segtree(int n){
    ///in[1]=4,in[2]=-9,in[3]=3,in[4]=7,in[5]=1,in[6]=0,in[7]=2;
    tlop(i,1,n) cin>>in[i];
    build(1,1,n);
    int q=query(1,1,n,3,6);
    update(1,1,n,6,1);
    cout<<q<<endl;
    print(n);
}
void iterative_segtree(int n){
    lop(i,0,n) cin>>tree[n+i];   ///for iterative function
    //tree[7]=4,tree[8]=-9,tree[9]=3,tree[10]=7,tree[11]=1,tree[12]=0,tree[13]=2;
    build(n);
    int q=query(2,5,n);
    update(5,1,n);
    cout<<q<<endl;
    print(n);
}

///         ********~~~~~~~~~~~ LAZY PROPAGATION ~~~~~~~~~~~********

int lazy[mx*3];

void lazy_update(int pos,int l,int r,int i,int j,int val){
    if(lazy[pos]!=0){
        tree[pos]+=(r-l+1)*lazy[pos];
        if(l!=r){
            lazy[pos*2]+=lazy[pos];
            lazy[pos*2+1]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(l>r||l>j||r<i)return;
    if(l>=i&&r<=j){
        tree[pos]+=(l-r+1)*val;
        if(l!=r){
            lazy[pos*2]+=val;
            lazy[pos*2+1]+=val;
        }
        return;
    }
    int mid=(l+r)/2,left=pos*2,right=pos*2+1;
    lazy_update(left,l,mid,i,j,val);
    lazy_update(right,mid+1,r,i,j,val);
    tree[pos]=tree[left]+tree[right];
}

int main()
{
    int n=7;  ///array length
    //cin>>n;
    //recursive_segtree(n);
    //iterative_segtree(n);
    in[1]=4,in[2]=-9,in[3]=3,in[4]=7,in[5]=1,in[6]=0,in[7]=2;
    build(1,1,n);
    lazy_update(1,1,n,1,n,8);
    print(n);
    for(int i=1;i<=2*n-1;i++) cout<<i<<" = "<<lazy[i]<<endl;
    return 0;
}
