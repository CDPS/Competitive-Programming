#include <bits/stdc++.h>

using namespace std;

vector<int> acc;

bool check(){
    for(int i=0;i<20;i++)
        if(acc[i]!=0)return true;
    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,w,x;
    cin >> t;
    while(t--){

        cin >> n >> w;

        acc = vector<int>(20,0);
        for(int i=0;i<n;i++)
            cin >> x , acc[log2(x)]++;

        int ans = 0;
        while(check()){
            int temp = w;
            int i=19;
            while(i>=0){
                if(temp >= (1 << i) && acc[i] )
                    temp -= (1<< i), acc[i]--;
                else
                    i--;
            }
            ans++;
        }


        cout << ans << "\n";
    }

    return 0;
}
