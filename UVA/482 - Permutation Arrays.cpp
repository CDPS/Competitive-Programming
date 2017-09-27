#include <bits/stdc++.h>

using namespace std;

struct node{
    int idx;
    string val;

    node (int a, string b){
        idx=a;
        val = b;
    }
    bool operator < (const node &a)const{
    return idx < a.idx;
    }
};

int main(){

    int n;

    cin >> n ;
    cin.ignore();

    string s1,s2;
    bool first = true;

    while(n--){
        if(!first)
            cout << "\n";

        first=false;
        cin.ignore();
        vector<node> a;
        getline(cin,s1);
        getline(cin,s2);

        stringstream ss1(s1),ss2(s2);

        int idx; string val;
        while( ss1 >> idx){ ss2>> val; a.push_back(node(idx,val)); }

        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
            cout << a[i].val << "\n";
    }
    return 0;
}
