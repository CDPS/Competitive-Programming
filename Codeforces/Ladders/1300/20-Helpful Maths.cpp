#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;
    vector<int> v;
    stringstream ss(s);
    char c; int i;
    ss >> i;
    v.push_back(i);

    while(ss >> c >> i){
        v.push_back(i);
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        printf("%d%c", v[i], i==v.size()-1? '\n':'+');
    }

    return 0;
}
