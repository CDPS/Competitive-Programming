#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    string a,b;
    int n; cin >> n;
    cin.ignore();

    unordered_map<string, string> mp;
    while(n--){

        getline(cin, a);
        getline(cin, b);
        mp[a] = b;
    }

    cin >> n;
    cin.ignore();

    while(n--){
        getline(cin, a);
        cout << mp[a] << "\n";
    }

    return 0;
}
