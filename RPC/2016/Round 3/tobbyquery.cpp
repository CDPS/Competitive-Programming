#include <bits/stdc++.h>

using namespace std;


int a[100000];

int getMid(int s, int e) {  return s + (e -s)/2;  }


int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
    if (qs <= ss && qe >= se)
        return st[si];

    if (se < qs || ss > qe)
        return 0;

    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) |
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}

int getSum(int *st, int n, int qs, int qe)
{
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] =  1 << arr[ss];
        return 1 << arr[ss];
    }

    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) |
              constructSTUtil(arr, mid+1, se, st, si*2+2);

    return st[si];
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));

    int max_size = 2*(int)pow(2, x) - 1;

    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);

    return st;
}


int main(){

    int n;

    while(scanf("%d",&n)==1){

        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        int *st = constructST(a, n);
        int q;

        scanf("%d",&q);
        int l,r;

        while(q--){

            scanf("%d %d",&l,&r);

            int sol = getSum(st,n,l-1,r-1);

            int res=0;

            for(int i=0;i<10;i++){
                if( (sol&(1<<i) )!=0 )
                    res++;
            }
            printf("%d\n",res);
        }

    }
    return 0;
}
