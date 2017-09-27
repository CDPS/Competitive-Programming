#include <bits/stdc++.h>
 
using namespace std;
 
 
long a[100001];
long n,d;
 
const int INF = 2000000000;
 
int getMid(int s, int e) {
    return  (e +s)/2;
}
 
long getRMQ(long *st, int ss, int se, int qs, int qe, int si,int f)
{
    if (qs <= ss && qe >= se)
        return st[si];
 
    if (se < qs || ss > qe){
        if(f)
            return INF;
        else
            return -1;
    }
 
    int mid = getMid(ss, se);
 
    long a;
 
    if(f)
        a = min(getRMQ(st, ss, mid, qs, qe, 2*si+1,1), getRMQ(st, mid+1, se, qs, qe, 2*si+2,1) );
    else
        a= max(getRMQ(st, ss, mid, qs, qe, 2*si+1,0), getRMQ(st, mid+1, se, qs, qe, 2*si+2,0) );
    return a;
}
 
long iRMQ(long arr[], int ss, int se, long *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    int mid = getMid(ss, se);
    st[si] =  min(iRMQ(arr, ss, mid, st, si*2+1),
              iRMQ(arr, mid+1, se, st, si*2+2) );
    return st[si];
}
 
 
long iRMQ2(long arr[], int ss, int se, long *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    int mid = getMid(ss, se);
    st[si] =  max(iRMQ2(arr, ss, mid, st, si*2+1),
              iRMQ2(arr, mid+1, se, st, si*2+2) );
    return st[si];
}
 
long *constructST(long arr[], int n,int f)
{
    int x = (int)(ceil(log2(n)));
 
    int max_size = 2*(int)pow(2, x) - 1;
 
    long *st = new long[max_size];
 
    if(f)
        iRMQ(arr, 0, n-1, st, 0);
    else
        iRMQ2(arr,0,n-1,st,0);
 
    return st;
}
 
int main(){
    int t,caseno=1;
    scanf("%d",&t);
 
    while(t--){
        scanf("%d %d",&n,&d);
 
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
 
        long *mins = constructST(a,n,1);
        long *maxs = constructST(a,n,0);
 
        priority_queue<long> pq;
 
        for(int i=d-1;i<n;i++){
 
            long mini= getRMQ(mins,0,n-1,i-(d-1),i,0,1);
 
            long maxi = getRMQ(maxs,0,n-1,i-(d-1),i,0,0);
 
            pq.push(maxi-mini);
        }
        printf("Case %d: %ld\n",caseno++,pq.top());
    }
    return 0;
}
