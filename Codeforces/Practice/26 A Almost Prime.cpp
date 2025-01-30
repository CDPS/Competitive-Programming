#include <bits/stdc++.h>

using namespace std;

int prime[3001];

int main(){

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
        if (prime[i]==0)
            for (int j = i+i ; j <= n; j += i)
                prime[j]++;

    int ans = 0;
    for(int i=1;i<=n;i++)
        if(prime[i]==2) ans++;

    cout << ans << "\n";
    return 0;
}
