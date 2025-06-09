#include <bits/stdc++.h>

using namespace std;

int a[5000], x, n;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> x;

    map<int, pair<int,int>> mp;
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0; i< n;i++)
        for(int j=i+1;j<n;j++)
            mp[a[i] + a[j]] = {i,j};

    for(int i=0; i< n;i++){
        for(int j=i+1;j<n;j++){
            int t= x - a[i] - a[j] ;
            auto it = mp.find(t);
            if(it != mp.end() && it->second.first != i && it->second.second !=i && it->second.first !=j && it->second.second !=j ){
                cout << i + 1 << " " << j+1 << " " << it->second.second + 1 << " " << it->second.first + 1 << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << "\n";

    return 0;
}

