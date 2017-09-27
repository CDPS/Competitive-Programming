#include <bits/stdc++.h>

using namespace std;

struct node{
    string s;
    int att,def;

    node(string a,int b, int c){
        s = a; att = b; def=c;
    }

    bool operator < (const node &a)const{
        if(att == a.att){
            if(def==a.def)
                return s < a.s;
            return def < a.def;
        }
        return att > a.att;
    }

};

struct compare{
    bool operator () (const node &a, const node &b)const {
        return a.s <b.s;
    }
}comparator;


int main(){

    int t,caseno=1;
    cin >> t;
    while(t--){

        string s; int att,def;
        vector<node> v;

        for(int i=0;i<10;i++){
            cin >> s >> att >> def;
            v.push_back(node(s,att,def));
        }
        sort(v.begin(),v.end());

        sort(v.begin(),v.begin()+5,comparator);
        sort(v.begin()+5,v.end(),comparator);

        cout << "Case " << caseno++ <<  ":\n(";
        for(int i=0;i<5;i++)
            cout << v[i].s << (i==4? ")\n": ", ");
        cout << "(";
        for(int i=5;i<10;i++)
            cout << v[i].s << (i==9? ")\n": ", ");
    }
    return 0;
}
