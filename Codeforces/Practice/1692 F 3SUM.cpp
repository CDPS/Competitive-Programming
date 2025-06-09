#include <bits/stdc++.h>

using namespace std;

int a[10];

bool valid(int x){
    return x >=0 && x<=9;
}

bool solve(){
    for(int i=0;i<=9;i++){
        if(a[i]>0){
            a[i]--;
            for(int j=0;j<=9;j++){
                if(a[j] > 0 ){
                    a[j]--;
                    if( valid(3-i-j) && a[3-i-j])
                        return true;
                    if(valid(13-i-j) && a[13-i-j])
                        return true;
                    if(valid(23-i-j) && a[23-i-j])
                        return true;
                    a[j]++;
                }
            }
            a[i]++;
        }
    }
    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n,x;
    cin >> t;

    while(t--){

        cin >> n;

        memset(a, 0, sizeof a);

        for(int i=0;i<n;i++)
            cin >> x, a[x%10]++;

        cout << ( solve()? "YES" : "NO" ) << "\n";
    }
    return 0;
}
