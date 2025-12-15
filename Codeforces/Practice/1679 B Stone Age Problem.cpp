#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, q, idx , val;

pair<int, int> a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;

    ll sum = 0;
    for(int i=0;i<n;i++)
        cin >> a[i].first, sum += a[i].first;

    int acc = 0, prev = -1;
    while(m--){

        cin >> q;
        if(q == 1){
            cin >> idx >> val;
            idx--;
            if(a[idx].second != acc)
               a[idx].first = prev,  a[idx].second = acc;
            sum+= val - a[idx].first;
            a[idx].first = val;
        }else{
            cin >> val;
            sum = 1ll*val*n;
            prev = val;
            acc++;
        }

        cout << sum << "\n";
    }
    return 0;
}
