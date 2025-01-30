#include <bits/stdc++.h>

using namespace std;

int prime[100002];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    for (int i = 2; i*i <= n+1; i++)
        if (prime[i]==0)
            for (int j = i*i ; j <= n+1; j += i)
                prime[j] = 1 ;

    cout << ( n>2?  "2" : "1") << "\n";
    for(int i=2;i<=n+1;i++)
        cout << prime[i] + 1 << " \n"[i==n+1];

    return 0;
}
