#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    map<string,int> mp;

    string a;

    for(int i=0;i<n;i++){
        cin >> a;
        mp[a]++;
    }

    map<string ,int>::iterator it;

    string r;
    int  maxi =-1;

    for(it= mp.begin(); it!=mp.end();it++){
        if(maxi <  it->second  ){
            r=it->first;
            maxi=it->second;
        }
    }
    cout << r << "\n";
    return 0;
}
