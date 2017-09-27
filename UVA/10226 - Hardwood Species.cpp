#include <bits/stdc++.h>


using namespace std;


int main(){

    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();

    map<string, int> mp;
    string s;

    bool first=1;
    while(t--){

        int cant =0;

        while(getline(cin,s) && s!=""){
            mp[s]++;
            cant++;
        }

        if(!first) cout <<"\n";
        first=0;
        map<string,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            cout << it->first << " " <<  fixed << setprecision(4) << ( double(it->second)/double(cant) )*100.0 << "\n" ;
        }

        mp.clear();
    }
    return 0;
}
