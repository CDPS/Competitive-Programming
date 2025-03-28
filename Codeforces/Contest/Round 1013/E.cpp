#include <bits/stdc++.h>

using namespace std;

const int MAX =  10000000;
const int LMT =     10000;

int m[(MAX>>6)+1];

#define isComp(n) (m[n>>6]&(1<<((n>>1)&31)))
#define setComp(n) m[n>>6]|=(1<<((n>>1)&31))

bool isPrime(int n) {
    if(n==2) return true;
    if (n < 2 || n % 2 == 0) return false;
    return ! isComp(n);
}

void sieve() {
    for (int i = 3; i <= LMT; i += 2)
        if (!isComp(i))
            for (int j = i*i; j <= MAX; j += i+i)
                setComp(j);
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    sieve();

    int t, n;
    cin >> t;
    while(t--){

        cin >> n;

        long long ans = 0;
        for(int i=2;i<=n;i++)
            if(isPrime(i))
                ans += n/i;

        cout << ans  << "\n";
    }
    return 0;
}
