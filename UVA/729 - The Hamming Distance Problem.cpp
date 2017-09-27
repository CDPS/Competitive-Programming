#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,m;;
    cin >> t;
    string s;
    bool first =true;

    while(t--){
        cin >> n >> m;
        if(!first)cout << "\n";
        first=false;
        s="";
        for(int i=0;i<n;i++)
            s = (i>n-m-1)? s + '1':s+'0';
        do{
            cout << s << "\n";
        }while(next_permutation(s.begin(),s.end()));
    }
    return 0;
}
