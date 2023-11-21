#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

pair<int, int> a[1000];
int n,car, pos;

bool isValid(int pos){
    return pos >=0 && pos < n;
}

int main(){

    while(cin >> n && n){

        int ans[1000] = {};
        for(int i=0;i<n;i++){
            cin >> car >> pos;
            a[i] = make_pair(car, pos);
        }

        bool valid = true;
        for(int i=0;i<n;i++){
            int nextIndex = i + a[i].s;
            if(isValid( nextIndex) && ans[nextIndex]==0){
                ans[nextIndex] = a[i].f;
            }else{
                valid = false;
            }
        }

        if(!valid){
            cout << -1 << "\n";
        }
        else{
            cout << ans[0];
            for(int i=1;i<n;i++){
                cout << " " <<ans[i];
            }
            cout << "\n";
        }
    }
    return 0;
}
