#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n;

    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];

        set<int> st;
        vector<int> l,f;

        for(int i=0;i<n;i++){
            if(!st.count(a[i]))
                f.push_back(i);
            st.insert(a[i]);
        }

        st.clear();

        for(int i=n-1;i>=0;i--){
            if(!st.count(a[i]))
                l.push_back(i);
            st.insert(a[i]);
        }

        long long ans = 0;
        for(int i=0;i<l.size();i++){

            while( f.back() > l[i] )
                f.pop_back();

            ans+= f.size();
        }

        cout << ans << "\n" ;
    }

    return 0;
}
