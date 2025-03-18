#include<bits/stdc++.h>

using namespace std;

int t, n, m, x;
int a[200001];

bool f(int x){
    int acc = 0;
    for(int i=0;i<n;i++){
        if(a[i]<= x)
            acc = max(0, acc - (((x-a[i])/2)*2) );
        else
            acc += (a[i]-x)*2;
    }
    return acc == 0;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> n >> m;

        for(int i=0;i<=n;i++) a[i] = 0;
        for(int i=0; i<m;i++) cin >> x, a[x-1]++;
        sort(a , a+n, greater<int>());

        int l = 1, h = 1e9, m;
        while(l<h){
            m = l + ((h-l)/2);
            if(f(m))
                h = m;
            else
                l = m +1;
        }

        cout << l << "\n";
    }
    return 0;
}
