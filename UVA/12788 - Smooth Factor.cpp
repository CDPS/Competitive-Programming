#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;

    while(cin >> n){

        for(int i=0;i<n;i++)
            cin >> a[i];

        vector<int> acc; acc.push_back(0);

        int curr = 1;
        for(int i=0;i<n-1;i++){
            if(a[i]> a[i+1])
                acc.push_back(curr), curr =1;
            else
                curr++;
        }

        acc.push_back(curr);
        int ans =0;
        for(int i=1;i<acc.size();i++)
            ans = max( ans, acc[i]+acc[i-1]);

        cout << ans << "\n";
    }
    return 0;
}
