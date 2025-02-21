#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[200001];
bool b[200001];

int lowerBound(int x){
    int l=0, h = n, m;
    while(l<h){
        m = l + ( (h-l+1)/2 );
        if(a[m] >= x)
             h = m-1;
        else l = m;
    }
    return l;
}

int main(){


    cin >> n >> m;

    a[0] = -1; b[0] = 1;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a, a+ n);

    while(m--){

        cin >> x;
        int lower = lowerBound(x);
        if(!b[lower]){

        }
    }


    return 0;
}
