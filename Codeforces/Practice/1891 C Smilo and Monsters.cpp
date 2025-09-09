#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;

    cin >> t;


    while(t--){

        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];

        sort(a, a+ n);

        int i=0, j=n-1;

        ll ans = 0, temp = 0;
        while(i<j){
           if(a[i] + temp < a[j])
                ans+=a[i], temp+= a[i], a[i] = 0, i++;
           else if(a[i] + temp == a[j])
                ans+=a[i] + 1, temp = 0,a[i] = a[j] = 0, i++, j--;
           else
                a[j]-=temp, ans+= 1 + a[j], a[i]-= a[j], a[j] =0, temp =0, j--;
        }

        if(a[j]<=1){
            cout << ans + a[j] << "\n";
            continue;
        }

        ll h = a[j], x = temp;
        ll best = h;

        if(x >= h) best = 1;
        ll d = h - x;
        if(d > 0){
            ll m = d/2;
            best = min(best, h - x - m + 1);
        }

        cout << ans + best<< "\n";
    }

    return 0;
}
