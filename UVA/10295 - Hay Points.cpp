#include <bits/stdc++.h>

using namespace std;


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin >> n >> m;

    unordered_map<string,int>mp;
    string a;
    while(n--)
        cin >> a >> k, mp[a] = k;
    cin.ignore();

    while(m--){
        int acc = 0;
        while(getline(cin,a) && a != "."){
            stringstream ss(a);
            while(ss >> a) acc += mp[a];
        }
        cout << acc << "\n";
    }
    return 0;
}
