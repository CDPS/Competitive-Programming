#include <bits/stdc++.h>

using namespace std;

bool eval(int a, int b, string op){
    if(op=="<") return a < b;
    if(op==">") return a > b;
    if(op=="<=") return a <= b;
    if(op==">=") return a >= b;
    return a == b;
}

bool isComp(string op){
    return op=="<" || op==">" || op=="<=" || op==">=" || op == "=";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n,m,a,b;
    char dt;
    string s;

    cin >> n >> m;

    unordered_map<string, double> mp;
    for(int i=0;i<n;i++)
        cin >> s >> a >> dt >> b, mp[s] =a * 10 + b;
    mp["+"] = 0;

    cin.ignore();
    for(int i=0;i<m;i++){

        getline(cin,s);
        stringstream ss(s);

        int acc =0;
        while(ss >> s){
            if(isComp(s)){
                ss >> n;
                cout << "Guess #" << i+1 << " was " << ( eval(acc,n*10, s)? "correct." : "incorrect." ) << "\n";
                break;
            }
            acc+=mp[s];
        }
    }
    return 0;
}
