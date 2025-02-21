#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string s;
    int t , n;
    cin >> t;

    while(t--){

        cin >> n >> s;

        s= "0" + s;
        int regions = 0;

        for(int i=1;i<s.size();i++)
            if(s[i] != s[i-1])
                regions++;

        cout << regions << "\n";
    }
    return 0;
}
