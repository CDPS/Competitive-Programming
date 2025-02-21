#include <bits/stdc++.h>

using namespace std;


int a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;

        map<int,int> mp;
        for(int i=0;i<n;i++) cin >> a[i], mp[a[i]]++;

        int maxi = 0, idx  = 0;
        for(int i=0;i<n;i++){
            if(mp[a[i]]==1){
                int cidx = i, acc = 0;
                while( i < n && mp[a[i++]] == 1) acc++;
                i--;
                if(acc > maxi ) idx = cidx, maxi = acc;
            }
        }

        if(maxi != 0)
            cout << (idx + 1) << " " << (idx + maxi) << "\n";
        else
            cout << 0 << "\n";

    }
    return 0;
}
