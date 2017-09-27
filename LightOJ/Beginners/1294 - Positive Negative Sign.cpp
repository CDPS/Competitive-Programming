#include <bits/stdc++.h>

using namespace std;


int main(){

    int t,caseno=1;
    scanf("%d",&t);
    while(t--){
        long n,m;

        scanf("%ld %ld",&n,&m);

        long long sum=(n/2)*m;

        printf("Case %d: %ld\n",caseno++,sum);

    }
}
