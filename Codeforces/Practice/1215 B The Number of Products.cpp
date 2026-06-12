#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int a[200001];

int main(){

    cin >> n;

    for(int i=1;i<=n;i++)
        cin >> a[i], a[i] = a[i] < 0 ? -1 : 1;


    ll ans = 0;

    int prefix = 1, pos_count = 1, neg_count = 0;
    for(int i=1; i <=n; i++){

        prefix*= a[i];

        if(prefix == -1) neg_count++;
        else  pos_count++;

        if(prefix == -1)
            ans += pos_count;
        else
            ans += neg_count;
    }

    cout << ans  << " " << ((1ll*n*(n+1))/2ll) - ans  << "\n";
    return 0;
}

