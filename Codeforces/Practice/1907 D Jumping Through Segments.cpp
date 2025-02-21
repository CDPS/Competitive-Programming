#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define l first
#define r second

int t,n,x,y;

bool f(int x, vector< pair<int,int> > &a){
    int al = 0, ar =0;
    for(int i=0;i<a.size();i++){
        ar = min( ar + x, a[i].r);
        al = max( al - x, a[i].l);
        if(al > ar)
            return false;
    }
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> n;
        vector< pair<int,int> > a;
        for(int i=0;i<n;i++)
            cin >> x >> y, a.push_back({x,y});

        int l = 0, h = 2e9, m;
        while(l< h){
            m = l + ( (h-l)/2 );
            if(f(m,a))
                h = m;
            else
                l = m + 1;
        }
        cout << l << "\n";
    }
    return 0;
}
