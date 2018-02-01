#include <bits/stdc++.h>

using namespace std;

int memo[ (1 << 12) +1 ];

bool isValid(int mask){

    for(int i=0;i<=9;i++){
        int a = ( mask & ( 1 << i ) );
        int b = ( mask & ( 1 << (i+1) ) );
        int c = ( mask & ( 1 << (i+2) ) );
        if( (a==0 && b!=0 && c!=0) || (a!=0 && b!=0 && c==0) ) return true;
    }
    return false;
}

int bits(int i){
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int dp(int mask){

    if(!isValid(mask)) return bits(mask);

    if(memo[mask]!=-1) return memo[mask];

    int ans =bits(mask);
    for(int i=0;i<=9;i++){
        int a = ( mask & ( 1 << i ) );
        int b = ( mask & ( 1 << (i+1) ) );
        int c = ( mask & ( 1 << (i+2) ) );
        if(a==0 && b!=0 && c!=0) ans = min(ans , dp( mask ^ ( 0 |  (1<< (i+2) ) | (1<< (i+1) ) | (1 << (i) ) ) )  );
        if(a!=0 && b!=0 && c==0) ans = min(ans , dp( mask ^ ( 0 |  (1<< (i+2) ) | (1<< (i+1) ) | (1 << (i) ) ) ) );
    }
    return memo[mask] = ans;
}

int main(){

    memset(memo,-1,sizeof memo);

    int t; char c;

    cin >> t;
    while(t--){
        int mask = 0;
        for(int i=0;i<12;i++) cin >> c, mask = (c=='o')? mask = mask | (1 << i) : mask;
        cout << dp(mask) << "\n";
    }
    return 0;
}
