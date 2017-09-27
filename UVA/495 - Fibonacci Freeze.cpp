#include <bits/stdc++.h>

using namespace std;

string f[5001];

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

string fillS(string s,int n){
    for(int i=0;i<n;i++)
        s= '0' + s;
    return s;
}

void calc(){
    f[0]="0"; f[1]="1";
    for(int i=2;i<=5000;i++)
        f[i] = sum(fillS(f[i-2],f[i-1].size()-f[i-2].size()),f[i-1]);
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    calc();
    int n;
    while(cin >> n)
        cout << "The Fibonacci number for "<< n <<" is "<< f[n] << "\n";
    return 0;
}
