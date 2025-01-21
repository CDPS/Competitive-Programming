#include <bits/stdc++.h>

using namespace std;

int lowerBound(long long x, vector<int> &a){
    int l=0, h = a.size()-1,mid;
    while(l<h){
        mid = l + ( (h-l+1)/2 );
        if(a[mid] >= x)
             h = mid-1;
        else l = mid;
    }
    return l;
}

int upperBound(int x, vector<int> &a){
    int l=0, h = a.size()-1,mid;
    while(l< h){
        mid = l + ( (h-l)/2 );
        if( a[mid] > x)
             h = mid;
        else l = mid +1;
    }
    return l;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string s; cin >> s; s.push_back('s');

    vector<int> os, vs; vs.push_back(-1);
    for(int i=0;i<s.size();i++){
        if(s[i]=='o') os.push_back(i);
        if(s[i]=='v' && s[i+1]=='v')vs.push_back(i);
    }
    vs.push_back(100000000);

    long long n = vs.size();

    long long ans = 0;
    for(int i=0;i<os.size();i++){
        long long lower = lowerBound(os[i], vs);
        long long upper = upperBound(os[i],vs);
        ans+= (lower)*(n-(upper+1));
    }

    cout << ans << "\n";
    return 0;
}
