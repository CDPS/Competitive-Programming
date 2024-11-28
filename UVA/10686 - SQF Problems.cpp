#include <bits/stdc++.h>

using namespace std;

void solve(){

    int n; cin >> n;
    string cat,key; int k,r;

    unordered_map<string, int> frec;
    unordered_multimap<string, string> cats;
    vector<string> v;

    while(n--){
        cin >> cat >> k >> r;
        v.push_back(cat);
        frec[cat] = r;
        while(k--){
            cin >> key;
            cats.insert( {key,cat});
        }
    }
    cin.ignore();

    string line;
    unordered_map<string, int> acc;

    unordered_set<string> st;
    while(getline(cin,line) && line != ""){

        for(auto &c : line)
            if(!isalpha(c)) c = ' ';

        stringstream ss(line);
        while(ss >> key){
            if(st.count(key)) continue;
            auto range = cats.equal_range(key);
            for (auto it = range.first; it != range.second; ++it) {
                acc[it->second]++;
            }
            st.insert(key);
        }
    }

    int counts = 0;
    for(int i=0;i<v.size();i++){
        if(frec[v[i]] <= acc[v[i]] ){
            cout << ( counts >0? "," :"") <<v[i];
            counts++;
        }
    }

    if(counts == 0)
        cout << "SQF Problem.";
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
