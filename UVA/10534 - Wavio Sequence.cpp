#include <bits/stdc++.h>

using namespace std;

const int inf = 2000000000;

vector<int> a,l,p;

int binarySearch(int t){
    int lo = 0, hi = l.size(),m;
    while(lo< hi){
        m = lo+ ((hi-lo)/2);
        if( t  <= l[m]) hi = m;
        else lo = m+1;
    }
    return lo;
}

vector<int>  dp(){

    l  = vector<int>(a.size(),inf);
    p = vector<int>(a.size(),-1);

    l[0]=a[0];

    for(int j=1;j<a.size();j++){
        int index = binarySearch(a[j]);
        l[index]  = a[j];
        p[j]= index+1;
    }
    return p;
}

int main(){

    int n;
    while(cin >> n){
        a = vector<int>(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        vector<int > f = dp();
        reverse(a.begin(),a.end());
        vector<int> b = dp();

        int maxi =1;
        for(int i=0;i<n;i++){
            maxi = max( maxi, 2*min(f[i],b[n-i-1]) -1 );
        }

        printf("%d\n",maxi);
    }
    return 0;
}
