#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t,n,k;
int a[300000];
string s;

bool f(int x){
    char prev = 'R';
    int acc =0;
    for(int i=0;i<n;i++){
        if(a[i]> x){
            if(s[i] == 'B' && prev == 'R'){acc++; prev = 'B'; continue;}
            if(s[i] == 'R' && prev == 'B'){prev = 'R'; continue;}
        }
    }
    return acc <= k;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> n >> k >> s;
        for(int i=0;i<n;i++) cin >> a[i];

        int l = 0, h = 1e9, m;
        while(l< h){
             m = l + ( (h-l)/2 );
            if(f(m))
                 h = m;
            else l = m +1;
        }

        cout << l << "\n";
    }

    return 0;
}
