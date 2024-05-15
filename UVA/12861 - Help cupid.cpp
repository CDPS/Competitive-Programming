#include <bits/stdc++.h>

using namespace std;

int a[1000];

int f(int i, int j){
    return min( abs(i-j), 24-abs(i-j));
}

int main(){

    int n;

    while(cin >> n){

        for(int i=0;i<n;i++)
            cin >> a[i];

        sort(a, a+n);

        int ans1=0;
        for(int i=1;i<n;i+=2)
            ans1+= f(a[i], a[i-1]);

        int ans2=0;
        for(int i=2;i<n-1;i+=2)
            ans2+= f(a[i], a[i-1]);
        ans2+= f(a[0], a[n-1]);

        cout  << min(ans1, ans2) << "\n";
    }
    return 0;
}
