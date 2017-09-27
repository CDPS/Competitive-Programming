#include <bits/stdc++.h>

using namespace std;

int a[1000],n;

int flip(){
    int res=0;
    for ( int i = 0; i < n; i++ ) {
        for ( int j = i + 1; j < n; j++ )
            if ( a [i] > a [j] ) res++;
    }
    return res;
}

int main(){
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        printf("Minimum exchange operations : %d\n",flip());
    }
    return 0;
}
