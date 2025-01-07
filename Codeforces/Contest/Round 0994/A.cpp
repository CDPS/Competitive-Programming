#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,x;
    cin >> t;

    while(t--){

        cin >> n;

        deque<int> v;
        for(int i=0;i<n;i++)
            cin >> x, v.push_back(x);

        while(!v.empty() && v.front()==0) v.pop_front();
        while(!v.empty() && v.back()==0 ) v.pop_back();

        int ans =0;
        if(!v.empty()){
            ans++;
            for(int i=0;i<v.size();i++){
                if(v[i]==0) {ans++; break;}
            }
        }

        cout << ans  << "\n";
    }
    return 0;
}
