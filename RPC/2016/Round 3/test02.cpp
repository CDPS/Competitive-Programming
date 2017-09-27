#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

long long coins[2449];


 int dp(int n){

        int T[n+1];
        T[0] = 0;

        for(int i=1; i <= n; i++){
            T[i] = INF;
        }

        for(int j=1; j <=2448; j++){

            for(int i=1; i <= n; i++){
                if(i >= coins[j]){
                    if (T[i - coins[j]] + 1 < T[i]) {
                        T[i] = 1 + T[i - coins[j]];
                    }
                }
            }
        }
        return T[n];
}

int main(){

    long long n;

    for(int i=1;i<=2448;i++){
        coins[i]=(i*(i+1ll))/2ll;
    }

    while(scanf("%lld",&n)==1){

        int res=dp(n);
        printf("%d\n",res);
    }
    return 0;
}
