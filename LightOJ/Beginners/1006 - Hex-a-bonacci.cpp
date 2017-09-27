#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, e, f;

long long ar[10001];

long long fn( int n ) {

    ar[0]=a;
    ar[1]=b;
    ar[2]=c;
    ar[3]=d;
    ar[4]=e;
    ar[5]=f;

    for(int i=6;i<=n;i++){
        ar[i]= ((ar[i-1]% 10000007) + (ar[i-2]% 10000007) + (ar[i-3]% 10000007) + (ar[i-4]% 10000007) + (ar[i-5]%10000007) + (ar[i-6]% 10000007) )% 10000007;
    }

    return ar[n];
}

int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}

