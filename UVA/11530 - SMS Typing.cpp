#include <bits/stdc++.h>

using namespace std;

string a= "abcdefghijklmnopqrstuvwxyz";
string v= "12312312312312312341231234";

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,caseno = 1;
    cin >> t; cin.ignore();

    string s;
    while(t--){
        getline(cin, s);
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z')
                ans= ans + v[ s[i]-'a' ]-'0';
            else
                ans = ans +1;
        }
        cout << "Case #" << caseno++ << ": "<< ans  << "\n";
    }
    return 0;
}
