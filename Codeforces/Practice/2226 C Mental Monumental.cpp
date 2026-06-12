#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int a[200000];

bool check(int x){

    vector<bool> in_set(x + 1, false);
    vector<int> usefull;
    for(int i=0; i < n ; i++ ){
        if(a[i] < x && !in_set[a[i]])
             in_set[a[i]] = true;
        else
            usefull.push_back(a[i]);
    }

    int i = 0, mex= 0;
    while(i < usefull.size() && mex < x ){
        if(in_set[mex]){ mex++; continue;}
        if(mex <= (usefull[i]-1)/2) in_set[mex++] = true;
        i++;
    }

    mex= 0;
    while(in_set[mex] ) mex++;

    return mex >= x;
}

int solve(){

    cin >> n;
    for(int i=0; i < n ; i++) cin >> a[i];
    sort(a, a + n);

    int l=0, h = n, m;
    while(l<h){
        m = l + ( (h-l+1)/2 );
        if(!check(m) )
             h = m-1;
        else l = m;
    }
    return l;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
