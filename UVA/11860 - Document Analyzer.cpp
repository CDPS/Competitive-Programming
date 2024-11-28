#include <bits/stdc++.h>

using namespace std;

void format(string &s){
    for(int i=0;i<s.size();i++)
        if( !(s[i]>='a' && s[i]<='z') )
            s[i]=' ';
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int n, caseno = 1;
    cin >> n; cin.ignore();
    string line;

    while(n--){

        vector<string> v;
        unordered_set<string> st;
        while(getline(cin, line) && line != "END"){
            format(line);
            stringstream ss(line);
            while(ss >> line)
                v.push_back(line), st.insert(line);
        }

        int rl=0, rh=v.size();
        unordered_map<string,int> curr;
        for(int i=0, j=0;i<v.size();i++){

            while(j < v.size() && curr.size() != st.size())
                curr[v[j++]]++;

            if( curr.size() == st.size() && j-i < rh-rl)
                rh = j, rl = i;

            curr[v[i]]--;
            if(curr[v[i]]==0) curr.erase(v[i]);
        }

        cout << "Document " << caseno++ << ": " << rl+1 << " " << rh << "\n";
    }

    return 0;
}
