#include <bits/stdc++.h>

using namespace std;

string sum(string a,string b){
    string res="";
    bool carry=0;
    for(int i=a.size()-1;i>=0;i--){
        int da=a[i]-'0'; int db=b[i]-'0'; int r = da+db;
        if(carry) r++,carry=0;
        if(r>=10)carry=1;
        res= char( (r%10)+'0' ) + res;
    }
    if(carry)
        res= '1'+res;
    return res;
}

void fillS(string &s,int n){
    for(int i=0;i<n;i++)
        s= '0' + s;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    string n,res="0";

    while(cin >> n && n!="0"){
        if(n.size()>res.size())
            fillS(res,n.size()-res.size());
        if(n.size()<res.size())
            fillS(n,res.size()-n.size());
        res = sum(n,res);
    }
    cout << res << "\n";
    return 0;
}
