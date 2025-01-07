#include <bits/stdc++.h>

using namespace std;

long long t, n, k;

pair<long long, long long> f(long long x){
    if(x < k) return {0,0};
    long long m = (x+1)/2;
    auto ans = f(x/2);
    return { 2ll*ans.first + x%2, 2ll*ans.second + ((x%2)*m) + (ans.first*m)};
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){
        cin >> n >> k;
        cout << f(n).second << "\n";
    }
    return 0;
}
