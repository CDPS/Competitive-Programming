#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,x;
    long long sume, sumo, counte, counto;
    cin >> t;

    while(t--){

        cin >> n;
        sume=0; sumo =0; counte=0; counto=0;

        for(int i=0;i<n;i++){
            cin >> x;
            if(i%2) sumo +=x, counto++;
            else sume +=x, counte++;
        }

        bool ans = sumo%counto ==0 && sume%counte == 0 && sume/counte == sumo/counto;
        cout << ( ans? "YES" : "NO" ) << "\n";
    }
    return 0;
}
