#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<long> a;
    long x;
    while(cin >> x){
        a.push_back(x);
        vector<long> b = a;
        sort(b.begin(),b.end());
        int m = (b.size()/2);
        cout << ( (b.size()%2==0) ? (b[m-1]+b[m])/2 : b[m] ) << "\n";
    }
    return 0;
}
