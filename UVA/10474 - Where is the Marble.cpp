#include <bits/stdc++.h>

using namespace std;

int a[1000000];

int binarySearch(int l, int h, int t){

    while(l <= h){
        int m = (l+h)/2;
        if(a[ m] == t) return m;
        else if( t < a[m]) h = m-1;
        else l = m+1;
    }
    return -1;
}

//also solvable with lower_bound function
//just practicing the classic binary search version.
int main(){
    int n,m,caseno=1;

    while(scanf("%d %d",&n,&m)){

        if(n==0 && m==0) break;

        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);

        int q;
        printf("CASE# %d:\n",caseno++);
        while(m--){
            scanf("%d",&q);
            int idx = binarySearch(0,n-1,q);
            if(idx==-1) printf("%d not found\n",q);
            else{
                for(int i=idx-1;i >=0 && a[i]==q;i--) idx--;
                printf("%d found at %d\n",q, idx+1);
            }
        }
    }

    return 0;
}
