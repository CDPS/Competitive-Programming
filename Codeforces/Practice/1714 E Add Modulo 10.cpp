#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200000];

bool check(){
    if(n==1) return true;
    for(int i=1;i<n;i++)
        if(a[i]!=a[i-1]) return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> n;

        bool flag = false;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]%5 == 0)
                flag = true, a[i] = a[i] + a[i]%10;
        }

        if(flag){
            cout << (check()? "YES" : "NO") << "\n";
        }else{

            for(int i=0;i<n;i++){
                while(a[i]%10!=2)
                    a[i] = a[i] + a[i]%10;
                a[i] = a[i]%20 == 2;
            }

            cout << (check()? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
