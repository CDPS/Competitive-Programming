#include <bits/stdc++.h>

using namespace std;

struct node{
    string s;
    int n;
    node(string a, int b){
        s=a; n=b;
    }

    bool operator < (const node &a) const{
        if(n==a.n)
            return s < a.s;
        return n > a.n;
    }
};

int main(){

    string s="1";
    getline(cin,s);

    while(true){

        map< string , set < string> > g;
        map< string , set < string> > st;

        while(s[0]>= 'A' && s[0]<= 'Z'){

            string proyect = s;
            g.insert(make_pair(proyect, set < string> () ) );

            while(getline(cin, s) && s[0]>='a' && s[0] <= 'z' ){
                g[proyect].insert(s);
                st[s].insert(proyect);
            }
        }


        if(s[0]=='1'){

            map< string , set < string> >::iterator it;
            set < string>::iterator jt;

            vector<node> v;

            for(it=g.begin();it!=g.end();it++){

                set <string> sett = it->second;

                int c=0;
                for(jt= sett.begin(); jt!=sett.end();jt++ ){
                    if(st[ *jt ].size()==1) c++;
                }
                v.push_back(node(it->first,c));
            }

            sort(v.begin(),v.end());

            for(int i=0;i<v.size();i++){
                cout << v[i].s << " " << v[i].n << "\n";
            }

            getline(cin,s);
        }else break;
    }
    return 0;
}

