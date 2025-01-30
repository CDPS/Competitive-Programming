#include <bits/stdc++.h>

using namespace std;

int n;
long long a[200000];
long long acc;
unordered_map<long long, int> mp;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i], acc += a[i], mp[a[i]]++;

    vector<int> ans;
    for(int i=0;i<n;i++){
        long long sum = acc - a[i];
        mp[ a[i] ]--;
        if(sum%2==0 && mp[ sum/2 ] )
            ans.push_back(i+1);
        mp[ a[i] ]++;
    }

    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " \n" [i==ans.size()-1];

    return 0;
}
