#include <bits/stdc++.h>

using namespace std;

long long a,b,c;

long long s(long long x){

    long long ans =0;
    while(x){
        int d = x%10;
        ans= ans+ d;
        x/=10;
    }
    return ans;
}

///a^b
long long Pow(long long a, int b){
    long long ans =1ll;
    while(b--)ans= ans*a;
    return ans;
}

int main(){

    cin >> a >> b >> c;

    vector<long long> v;
    for(int i=1;i<=81;i++){
        long long x =( b*Pow(i,a) )+ c;
        if(s(x)==1ll*i && x < 1000000000ll)v.push_back(x);
    }

    cout << v.size() << "\n";
    for(int i=0;i<v.size();i++){
        cout << v[i]; if(i!=v.size()-1) cout << " ";
    }
    return 0;
}
