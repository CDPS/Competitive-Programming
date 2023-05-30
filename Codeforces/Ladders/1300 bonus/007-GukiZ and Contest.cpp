#include <bits/stdc++.h>

using namespace std;

int a[2000];

map<int, int> mp;

int main(){

    int n;

    cin >>  n;

    for(int i =0;i<n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    for(int i =0;i<n; i++){
        int ans = 1 ;
        for(map<int, int>::reverse_iterator it=mp.rbegin();it!=mp.rend();it++){
            if(it->first == a[i]){
                cout << ans << " ";
                break;
            }
            ans+= it->second;
        }
    }
    return 0;
}
