#include <bits/stdc++.h>

using namespace std;

int a[2000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];

        int total = 0;
        multiset<int> ms; ms.insert(a[n-1]);
        for(int i = n-2;i >=0;i--){
            total += distance(ms.begin(), ms.lower_bound(a[i]));
            ms.insert(a[i]);
        }

        int l=0, r =0, mini = total;
        for(int i=0;i<n;i++){
            int x= 0, y= 0;
            for(int j=i+1;j<n;j++){
                if(a[i] > a[j]) x++;
                if(a[i] < a[j]) y++;
                if(total-x+y < mini )
                    mini = total-x+y, l=i, r=j;
            }
        }

        cout << l+1 << " " << r+1 << "\n";
    }

    return 0;
}
