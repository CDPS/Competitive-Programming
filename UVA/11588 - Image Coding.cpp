#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, caseno = 1;

    cin >> t;

    int n,m,r,d;
    while(t--){

        cin >> n >> m >> r >> d;

        string s;
        vector<string> a;
        for(int i=0;i<n;i++)
            cin >> s, a.push_back(s);

        map<char,int> mp;
        int maxi = 0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mp[ a[i][j]] ++, maxi = max(maxi, mp[ a[i][j]] );

        int ans = 0;
        for(auto it = mp.begin();it != mp.end(); it++)
            if( it-> second == maxi) ans += maxi;

        cout << "Case " << caseno++ << ": " << (  ans*r + (  ((n*m)-ans) * d ) ) << "\n";
    }
    return 0;
}
