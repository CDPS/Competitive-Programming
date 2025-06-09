#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,k;
int a[200000];

bool f(long long x){
    long long acc = 0;
    for(int i=n/2;i < n;i++)
        if(x > a[i])
            acc += x-a[i];
    return acc <=  k;
}

int main(){

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a+n);

    long long l = 1, h = 2e9, m;
    while(l< h){
        m = l + ( (h-l+1)/2 );
        if(f(m))
           l = m;
		else
            h = m - 1;
    }
    cout << l << "\n";

    return 0;
}
