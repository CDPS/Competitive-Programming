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

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,x;
    cin >> t;

    while(t--){

        cin >> n;
        vector<int> a; a.push_back(0);
        vector<int> b;

        for(int i=0;i<n;i++){
            cin >> x;
            if(x < i +1 )
                a.push_back(i+1), b.push_back(x);
        }

        long long ans = 0;
        for(int i=0;i<b.size();i++)
             ans+= lowerBound(b[i], a);

        cout << ans << "\n";
    }

    return 0;
}
