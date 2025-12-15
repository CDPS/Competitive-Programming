#include <bits/stdc++.h>

using namespace std;

int n;
int a[32], b[32];

bool check(int x){

    for(int i=0;i<32;i++) b[i] = a[i];

    for(int i=0;i<31;i++){

        if( (x&(1<<i)) !=0 ){

            int needed = 1;

            bool flag = false;
            for(int j=i; j>=0 && !flag;j--){
                if(b[j] >= needed )
                    b[j]-= needed, flag = true ;
                else
                    needed-=b[j], needed*=2, b[j] =0;
            }

            if(!flag)
                return false;
        }
    }

    return true;
}

int solve(){

    int n, op, x;

    cin >> n;

    while(n--){
        cin >> op >> x;
        if(op == 1)
            a[x]++;
        else
            cout << ( check(x)? "YES" : "NO" ) << "\n";
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}

