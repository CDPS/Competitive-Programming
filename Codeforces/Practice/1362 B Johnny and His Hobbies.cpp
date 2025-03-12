#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[1024];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;
        set<int> st;
        for(int i=0;i<n;i++)
            cin >> a[i], st.insert(a[i]);

        int ans = -1;
        for(int i=1;i<=1024;i++){
            set<int> tmp = st;
            for(int j=0;j<n;j++){
                if(tmp.count(a[j]^i))
                    tmp.erase(a[j]^i);
                else
                    break;
            }
            if(tmp.size()==0){
                ans = i; break;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}

