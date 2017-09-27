#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;
    int n = s.size()-1;
    int u = s[n]-'0';
    int lastEven=-1;

    for(int i=0;i<n;i++){
        int d = s[i]-'0';
        if(d%2==0){
            if(u>d){ lastEven=i; break;}
            if(u<d) lastEven = i;
        }
    }

    if(lastEven==-1) cout << "-1";
    else
        swap(s[lastEven],s[n]),cout << s ;
    return 0;
}
