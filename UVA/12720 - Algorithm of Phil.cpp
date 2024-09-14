#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull m = 1000000007;

ull eb(ull a, ull b){
    ull res=1;
    ull x= a%m;
    while(b>0){
        if(b%2)
            res= (res*x)%m;
        x = (x*x)%m;
        b/=2;
    }
    return res;
}

string f(string s){


    return ans;
}

int main(){

    int t;
    cin >> t;
    while(t--){

        string a;
        cin >> a;

        string b = f(a);
        ull ans = 0;
        for(int i= b.size(), j=0; i>=0; i--, j++){
            if(b[i]=='1')
                ans += eb(2,j);
        }
        cout << ans << "\n";
    }
    return 0;
}
