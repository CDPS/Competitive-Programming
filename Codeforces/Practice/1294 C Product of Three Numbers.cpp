#include <bits/stdc++.h>

using namespace std;

map<int,int> factorize(int n){

    map<int,int> ans;

    while(n % 2 == 0)
        ans[2]++, n /= 2;

    for(int i = 3; i * i <= n; i += 2)
        while(n % i == 0)
            ans[i]++, n /= i;

    if(n > 1) ans[n]++;

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;

    cin >> t;

    while(t--){

        cin >> n;

        map<int,int> mp = factorize(n);

        if(mp.size() == 1){
            if(mp.begin()->second <6){
                cout << "NO" << "\n";
                continue;
            }
            int  x= mp.begin()->first;
            cout << "YES" << "\n";
            cout << x<< " " << x*x << " " << n/(x*x*x)<< "\n";
        }
        else if(mp.size() == 2 && mp.begin()->second + mp.rbegin()->second < 4){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";

            auto it = mp.begin();
            cout << it->first;
            mp[it->first]--; it++;
            cout << " " << it->first;
            mp[it->first]--;

            int rest = 1;
            for(auto it = mp.begin();it!=mp.end();it++){
                for(int j=0;j<it->second;j++)
                    rest*=it->first;
            }
            cout << " " << rest << "\n";
        }

    }
    return 0;
}
