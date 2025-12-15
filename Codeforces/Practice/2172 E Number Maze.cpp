#include <bits/stdc++.h>

using namespace std;

int t;

map<string, vector<string> > g;

vector<string> getAllPermutations(string s){
    vector<string> ps;
    do{
        ps.push_back(s);
    }while(next_permutation(s.begin(), s.end() ) );

    return ps;
}

void precalc(){
    g["12"]   = getAllPermutations("12");
    g["123"]  = getAllPermutations("123");
    g["1234"] = getAllPermutations("1234");
}

void encode(string a, string b){
    int x = 0;
    for(int i=0;i<a.size();i++)
        if(a[i] == b[i])
            x++;
    cout << x << "A" << a.size() - x<< "B" << "\n";
}

void solve(){
    string s;
    int x, y;
    cin >> s >> x >> y;
    encode(g[s][x-1],g[s][y-1]);
}

int main(){

    precalc();
    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

