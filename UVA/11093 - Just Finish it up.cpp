#include <bits/stdc++.h>

using namespace std;

int p[100001];
int q[100001];

int main(){

    cin.tie(NULL);  cin.sync_with_stdio(false);
    int t, caseno=1,n;

    cin >> t;
    while(t--){

        cin >> n;
        int sump = 0, sumq = 0;

        for(int i=0;i<n;i++)
            cin >> p[i], sump +=p[i];

        for(int i=0;i<n;i++)
            cin >> q[i], sumq +=q[i];

        cout << "Case " << caseno++ << ": ";

        if(sump < sumq){
            cout << "Not possible" << "\n";
        }else{
            int index = 0, acc = 0;
            for(int i=0;i<n;i++){
                acc += p[i]-q[i];
                if(acc <0)
                    acc = 0, index = i+1;
            }
            cout << "Possible from station " << index + 1 << "\n";
        }
    }

    return 0;
}
