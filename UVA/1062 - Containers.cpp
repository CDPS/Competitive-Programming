#include <bits/stdc++.h>

using namespace std;

vector<stack<char>>a;

int get(char c){
    for(int i=0;i<a.size();i++)
        if(a[i].top() >= c )
            return i;
    return -1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int caseno = 1;
    string s;
    while(cin >> s && s[0]!='e'){

        a.clear();
        set<char> dist;
        for(int i=0;i<s.size();i++){
            int idx = get(s[i]);
            if(idx == -1){
                stack<char>st; st.push(s[i]);
                a.push_back(st);
            }else
                a[idx].push(s[i]);

            dist.insert(s[i]);
        }

        cout << "Case " << caseno++ << ": " << min(a.size(),dist.size())<< "\n";
    }
    return 0;
}
