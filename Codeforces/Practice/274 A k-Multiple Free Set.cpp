#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n,k;
    cin >> n >> k;

    if(n ==1 || k == 1){
        cout << n << "\n";
        return 0;
    }

    set<int> st;
    for(int i=0;i<n;i++)
        cin >> a[i],st.insert(a[i]);

    sort(a, a+n);

    int ans =0;
    for(int i=0;i<n;i++){
        int x = a[i] / k;
        if(x*k == a[i]){
           if(!st.count(x))
                ans++;
           else
                st.erase(a[i]);
        }
        else
            ans++;
    }


    cout <<  ans << "\n";
}
