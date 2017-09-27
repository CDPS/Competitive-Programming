#include <bits/stdc++.h>

using namespace std;

int main(){

    long long  n,k;

    cin >> n >> k ;

    vector<long long> v;

    for(long long i=1;i<=sqrt(n);i++){
        if(n%i==0){
            v.push_back(i);
            v.push_back( (n/i) );
        }
    }

    if(k>v.size()) cout << "-1\n";
    else  cout << v[k-1] << "\n";
    return 0;
}
