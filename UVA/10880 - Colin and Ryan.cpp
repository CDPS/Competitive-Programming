#include <bits/stdc++.h>

using namespace std;

int main(){

    long t,caseno = 1,c,r;
    cin >> t;

    while(t--){

        cin >> c >> r;

        long n = c - r;
        set<long> ans;

        if( n == 0){
            ans.insert(0);
        }else{
            for(long i=1;i*i<=n;i++){
                if(n%i==0){
                    if(i>r)  ans.insert(i);
                    if(n/i>r)ans.insert(n/i);
                }
            }
        }

        cout << "Case #" << caseno++ << ":";
        for(auto it= ans.begin();it!=ans.end();it++)
            cout << " " << *it;
        cout << "\n";
    }

    return 0;
}
