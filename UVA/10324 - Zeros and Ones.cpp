#include <bits/stdc++.h>

using namespace std;

int acc[1000001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string line;
    int q,l,h,caseno=1;
    while(cin >> line){

        acc[0]=0;
        for(int i=0;i<line.size();i++){
            acc[i+1] = (line[i]=='1')? 1:0;
            acc[i+1] = acc[i+1] + acc[i];
        }
        cin >> q;

        cout << "Case " << caseno++ << ":\n";
        while(q--){
            cin  >> l >> h;
            if(l > h ) swap(l,h);
            int r = acc[h+1] - acc[l];
            cout << (  (r==0 || r == h-l+1)? "Yes":"No" ) << "\n";
        }
    }
    return 0;
}
