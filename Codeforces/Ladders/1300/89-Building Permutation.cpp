#include <bits/stdc++.h>

using namespace std;

long long a[300000];

int main(){

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);

    long long res =0;
    for(long long i=0;i<n;i++){
        res= res + (max(a[i],i+1) - min(a[i],i+1) );
    }

    cout << res << "\n";
    return 0;
}
