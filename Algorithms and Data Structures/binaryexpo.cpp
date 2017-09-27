#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
 

int m=1000003;

//return (a^b)%m
 
ull eb (ull a, ull b){
 
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

//return (a*b)%m
ll mul(ull  a, ull b, ull  mod) {
    ull  ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod)    ret -= mod;
        }
    }
    return ret;
}

int main(){
	return 0;
}
