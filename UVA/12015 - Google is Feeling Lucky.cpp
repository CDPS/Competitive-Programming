#include <bits/stdc++.h>

using namespace std;

vector<string> g[101];

int main(){

    int n,val, caseno =1;;
    cin >> n;
    int maxi;
    string s;
    while(n--){

        maxi=-1;
        for(int i=0;i<10;i++){
            cin >> s >> val;
            g[val].push_back(s);
            if(val> maxi)
                maxi=val;
        }

        cout << "Case #" << caseno++ << ":\n";
        for(int i=0;i<g[maxi].size();i++)
            cout << g[maxi][i] << "\n";
        for(int i=0;i<102;i++)
            g[i].clear();
    }
    return 0;
}
