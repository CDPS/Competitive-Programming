#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

ll solve(){

    cin >> n;
    vector<int> a(n);

    bool allNegatives = true;
    for(int i=0;i<n;i++)
        cin >> a[i], allNegatives &= a[i] < 0;

    if(allNegatives)
        return *max_element(a.begin(), a.end());

    ll odds = 0, evens =0;
    for(int i=0; i<n;i++){
        if(i%2==0) evens+= max(a[i],0);
        else  odds += max(a[i], 0);
    }

    return max(odds, evens);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);


    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
