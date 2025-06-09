#include<bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string s;
    int n, x, maxi =-10000001;
    cin >> n;

    vector<pair<string, int>> v;

    map<string, int> score;
    for(int i=0;i<n;i++)
        cin >> s >> x, v.push_back({s,x}), score[s]+=x ;

    for(auto it= score.begin(); it!=score.end(); it++)
        maxi = max(maxi, it->second);

    set<string> winners;
    for(int i=0;i<n;i++){
        if(score[v[i].first] == maxi)
            winners.insert(v[i].first);
    }

    score.clear();

    string ans;
    for(int i=0;i<n;i++){
        score[v[i].first]+= v[i].second;
        if(score[v[i].first] >= maxi && winners.count(v[i].first)){
            ans = v[i].first;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
