#include <bits/stdc++.h>

using namespace std;


string toString(long long n){
    stringstream ss; ss << n;
    string s; ss >> s;
    return s;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    string n;
    cin >> n;

    int ans =0;
    while(n.size()!=1){
        long long a = 0;

        for(int i=0;i<n.size();i++ )
            a = a + int(n[i]-'0');
        n = toString(a);
        ans++;
    }

    cout << ans << "\n";
    return 0;
}
