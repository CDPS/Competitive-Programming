#include <bits/stdc++.h>

using namespace std;

int n,m;
long long a[100000], b[100002];

long long lowerBound(long long x){
    int l=0, h = m+1,mid;
    while(l<h){
        mid = l + ( (h-l+1)/2 );
        if(b[mid] >= x)
             h = mid-1;
        else l = mid;
    }
    return b[l];
}

long long upperBound(long long x){
    int l=0, h = m+1,mid;
    while(l< h){
        mid = l + ( (h-l)/2 );
        if( b[mid] >= x)
             h = mid;
        else l = mid +1;
    }
    return b[l];
}

int main(){

    cin >> n >> m;

    for(int i=0;i<n;i++)
        cin >> a[i];

    b[0] = -1000000000000000;
    for(int i=0;i<m;i++)
        cin >> b[i+1];
    b[m+1] = 100000000000000;

    long long ans = -1;
    for(int i=0;i<n;i++){
        long long l = lowerBound(a[i]);
        long long h = upperBound(a[i]);
        ans = max ( ans , min( abs(l-a[i]),abs(h-a[i]) ));
    }

    cout << ans << "\n";
    return 0;
}
