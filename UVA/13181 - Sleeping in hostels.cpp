#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    string s;

    while(cin >> s){

        vector<int> a;

        int res=0, i=0;
        for(;i<s.size();i++){
            if(s[i]=='X'){
                res = i-1;
                break;
            }
        }

        int acc=0;
        for(;i<s.size();i++){
            if(s[i]=='X'){
                res = max(res, ( acc%2)? acc/2 : (acc/2)-1 );
                acc =0;
            }else{
                acc++;
            }
        }

        res = (acc>0)? max(res, acc-1) : res;
        cout << res << "\n";
    }
    return 0;
}
