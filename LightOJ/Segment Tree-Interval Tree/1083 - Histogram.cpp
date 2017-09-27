#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 2000000000;
 
struct node{
    int pos;
    int valor;
};
 
 
int getMid(int s, int e) {
    return  (e +s)/2;
}
 
node getRMQ(node *st, int ss, int se, int qs, int qe, int si)
{
    //Total Overlap
    if (qs <= ss && qe >= se)
        return st[si];
 
    //No overLap
    if (se < qs || ss > qe){
        node inf; inf.pos=0; inf.valor=INF;
        return inf;
    }
 
 
    int mid = getMid(ss, se);
    node izq= getRMQ(st, ss, mid, qs, qe, 2*si+1);
 
    node der= getRMQ(st, mid+1, se, qs, qe, 2*si+2);
 
    node minN;
 
    if(izq.valor< der.valor){
        minN=izq;
    }else{
        minN = der;
    }
 
    return minN;
}
 
node constructSTUtil(node *arr, int ss, int se, node *st, int si)
{
    if (ss == se)
    {
       st[si] = arr[ss];
       return st[si];
    }
 
    int mid = getMid(ss, se);
 
    node izq= constructSTUtil(arr, ss, mid, st, si*2+1);
 
    node der= constructSTUtil(arr, mid+1, se, st, si*2+2);
 
    if(izq.valor < der.valor){
        st[si] = izq;
    }
    else{
         st[si] = der;
    }
 
    return st[si];
}
 
node *constructST(node *arr, int n)
{
    int x = (int)(ceil(log2(n)));
 
    int max_size = 2*(int)pow(2, x) - 1;
 
    node *st =  new node[max_size];
 
    constructSTUtil(arr, 0, n-1, st, 0);
 
    return st;
}
 
node *a;
node *st;
int n;
 
long long getArea(int i,int j){
 
    if( !(i >=0 && i<= n-1 && j >=0 && j<=n-1) )
        return 0;
 
    if(i>j || j<i)
        return 0;
 
    if(i==j)
        return a[i].valor;
 
    node r = getRMQ(st,0,n-1,i,j,0);
 
    long long area = (j-i+1)*r.valor;
 
    int p = r.pos;
 
    return max(area,max(getArea(i,p-1),getArea(p+1,j)));
 
}
int main(){
 
    int t,caseno=1;
    scanf("%d",&t);
 
    while(t--){
 
 
        scanf("%d",&n);
 
        a = new node[n];
 
        int num;
        for(int i=0;i<n;i++){
            scanf("%d",&num);
            a[i].pos=i;
            a[i].valor=num;
        }
 
        st = constructST(a,n);
 
        long long area = getArea(0,n-1);
 
       printf("Case %d: %lld\n",caseno++,area);
    }
    return 0;
}
