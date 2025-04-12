#include <bits/stdc++.h>

using namespace std;

int t;
int a[6] = {3,1,2,1,0,1};
int acc[10];

bool check(){
    for(int i=0;i<6;i++)
        if(acc[i]<a[i])
        return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;
    cin >> t;
    while(t--){

        cin >> n;
        memset(acc, 0, sizeof acc);

        int idx = 0;
        for(int i=0;i<n;i++){
            cin >> x;
            acc[x]++;
            if(check() && idx == 0)
                 idx = i +1;
        }

        cout << idx << "\n";
    }

    return 0;
}
