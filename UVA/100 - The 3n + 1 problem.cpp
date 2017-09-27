#include <bits/stdc++.h>

using namespace std;

int calc(int n){
    int res =1;
    while(n!=1){
        if(n%2==1) n= 3*n+1;
        else n/=2;
        res++;
    }

    return res;
}

int main(){

    int n,m;

    while(scanf("%d %d",&n,&m)==2){

        bool f=0;
        if(n>m) { swap(n,m); f=1;}

        int maxi = 0;

        for(int i=n ;i<=m;i++)
            maxi = max(maxi,calc(i));
        if(f)swap(n,m);

        printf("%d %d %d\n",n,m,maxi);
    }
    return 0;
}
