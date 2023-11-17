#include <bits/stdc++.h>

using namespace std;

int main(){

    int t,n,k;
    string s;
    cin >> t;

    while(t--){

        cin >> n >> k >> s;

        map<char, int> mp;

        for(int i=0;i<n;i++)
            mp[s[i]]++;

        int acc = 0;
        for(map<char, int>::iterator it=mp.begin(); it!= mp.end();it++){
            if(it->second%2) acc++;
        }

        cout<<( (acc  > k + 1)? "NO": "YES" )<< "\n";
    }
    return 0;
}
