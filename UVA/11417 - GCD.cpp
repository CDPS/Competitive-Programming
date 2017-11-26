#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){

    int n;
    while(scanf("%d",&n) && n){

        long long res=0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                res =res + gcd(i,j);

        printf("%lld\n",res);
    }
    return 0;
}
