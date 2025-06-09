#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, k;
    cin >> t;
    while(t--){

        cin >> n>> k;
        for(int i=0;i<n;i++) cin >> a[i];

        int window = 0;
        for(int i=0;i<k;i++) window +=a[i];

        int target= window;
        for(int i=k;i<n;i++){


            windows - a[i-k] +
            if(a[i-k] )
        }

    }

    return 0;
}

