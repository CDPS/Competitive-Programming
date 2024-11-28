#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string line,a,b;
    unordered_map<string,string> mp;
    while(getline(cin, line) && line !=""){
        stringstream ss(line);
        ss >> a >> b;
        mp[b] = a;
    }

    while(cin >> b)
        cout << ( (mp.count(b))? mp[b] : "eh" ) << "\n";
    return 0;
}
