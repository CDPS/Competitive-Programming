#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[100000];

void solve(){

    cin >> n;

    set<int> mex, mex2;
    for(int i=0;i<n;i++)
        mex.insert(i), mex2.insert(i);

    for(int i=0;i<n;i++){
        cin >> a[i];
        if(mex.count(a[i]))
            mex.erase(a[i]);
    }

    int gmex  = ( mex.size() > 0 )? *mex.begin() : n ;
    int idx   = n;

    for(int i=0;i<n;i++){
        if(mex2.count(a[i]))
            mex2.erase(a[i]);

        int curr_mex = ( mex2.size() > 0 )? *mex2.begin() : n ;
        if(curr_mex == gmex){
            idx = i + 1;
            break;
        }
    }

    for(int i=0;i<n;i++)
        mex.insert(i);

    for(int i=idx;i<n;i++){
        if(mex.count(a[i]))
            mex.erase(a[i]);
    }


    int curr_mex = ( mex.size() > 0 )? *mex.begin() : n ;

    if( curr_mex!= gmex){
        cout << - 1<< "\n";
        return;
    }

    cout << 2 << "\n";
    cout << 1 << " " << idx  << "\n";
    cout << idx + 1 << " " << n << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        solve();

    return 0;
}
