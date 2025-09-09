#include <bits/stdc++.h>

using namespace std;

int a[331];

int get(int x){
    int ans = 0;
    for(int i=x+1;i<331;i++) ans+=a[i];
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cout.setf(ios_base::fixed);
    cout.precision(3);

    int n,x;

    while(cin >> n && n){

        memset(a,0, sizeof a);

        int acc = 0;
        for(int i=0;i<n;i++){
            cin >> x;
            acc += get(x+30);
            a[x+30]++;
        }
        cout << ((n == 1)? 0.0 : ((double)acc/(double)( (n*(n-1))/2))) << "\n";
    }
    return 0;
}
