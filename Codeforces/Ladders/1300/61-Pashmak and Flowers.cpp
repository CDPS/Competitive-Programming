#include <bits/stdc++.h>

using namespace std;

long long a[200000];

int main(){

    long long n;
    cin >> n;

    map<long ,long long> mp;

    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[ a[i] ]++;
    }

    sort(a,a+n);

    long long r = a[n-1]-a[0];
    long long res =  a[0]== a[n-1]?  (n*(n-1))/2: mp[ a[0] ] * mp[ a[n-1] ];

    cout << r << " " << res;
    return 0;
}
