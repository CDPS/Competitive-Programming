#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string line;
    while(getline(cin, line)){

        deque<string> q;
        q.push_back("");
        string* s = &q.back();

        for(int i=0;i<line.size();i++){
            if(line[i]=='['){ q.push_front(""); s = &q.front(); continue;}
            if(line[i]==']'){ q.push_back("");  s = &q.back();  continue;}
            *s += line[i];
        }

        for(auto& v : q) cout << v;
        cout << "\n";
    }
    return 0;
}
