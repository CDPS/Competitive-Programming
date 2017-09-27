#include <bits/stdc++.h>

using namespace std;

bitset<1201> m;

map<char,int> mp;

void sieve(int n){
    m.reset(); m.flip();
    m[0]=m[1]=1;

    for(int i=2;i*i<=n;i++){
        if(m[i]){
            for(int j=i+i;j<=n;j+=i){
                m[j]=0;
            }
        }
    }
}

void pre(){
    for(int i=0;i<26;i++)
        mp[i + 'a' ]= i+1;

    for(int i=0;i<26;i++)
        mp[i + 'A' ]= i+27;
}

int main(){

    sieve(1200);
    pre();
    string s;
    while(cin >>s){
        int res=0;
        for(int i=0;i<s.size();i++)
            res+= mp [ s[i] ];
        if(m[ res ])cout << "It is a prime word.\n";
        else cout << "It is not a prime word.\n";
    }
    return 0;
}
