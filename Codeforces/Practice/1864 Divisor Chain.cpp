#include <bits/stdc++.h>

using namespace std;

int most_significant(int x){
    for(int i=30; i>=0;i--)
        if( (x&(1<<i)) !=0 )
            return (1<< i);
    return 0;
}

int n;
void solve(){

    cin >> n;

    int top = most_significant(n);

    vector<int> ans = {n};

    int i = 0, mask = 0;
    while( (1<<i) < top ){
        if( (n&(1<<i)) !=0)
            mask |= (1<<i) , ans.push_back(n-mask);
        i++;
    }
    while(top > 1)
        top/=2, ans.push_back(top);

    cout << ans.size() << "\n";
    for(int i=0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i==ans.size()-1];
}

int t;
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();
}
