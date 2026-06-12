#include <bits/stdc++.h>

using namespace std;

const int MAX =  1000000;
const int LMT =     1000;

int m[(MAX>>6)+1];

#define isComp(n)  (m[n>>6]&(1<<((n>>1)&31)))
#define setComp(n) m[n>>6]|=(1<<((n>>1)&31))

void sieve() {
    for (int i = 3; i <= LMT; i += 2)
        if (!isComp(i))
            for (int j = i*i; j <= MAX; j += i+i)
                setComp(j);
}

bool isPrime(int n) {
    if(n==2) return true;
    if (n < 2 || n % 2 == 0) return false;
    return ! isComp(n);
}

int t = 1, a, b, k;

int solve(){

    sieve();

    cin >> a >> b >> k;

    vector<int> mp(MAX  + 1 , 0);

    int ans = -1, acc = 0;
    for(int i=a; i<=b; i++){
        if( isPrime(i) )
            mp[++acc] = i;
        if( acc - k + 1 >= 1 )
            ans = max(ans,  i - mp[acc - k + 1]  + 1);
    }


    if (acc < k) return -1;

    ans = max(ans, mp[k] - a + 1);

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;
}
