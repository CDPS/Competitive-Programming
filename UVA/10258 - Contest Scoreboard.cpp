#include <bits/stdc++.h>

using namespace std;


struct node{
    int n,s,p;
    int ps[9]; int ss[9];

    node(int a){ n=a; s=p=0; memset(ps,0, sizeof ps); memset(ss,0, sizeof ss); }

    bool operator < (const node &a) const{
        if(s==a.s){
            if(p==a.p)
                return n < a.n;
            return p < a.p;
        }
        return s > a.s;
    }

    void reset(int a){ n=a; s=p=0; memset(ps,0, sizeof ps); memset(ss,0, sizeof ss); }

    void calcP(){
        for(int i=0;i<9;i++)
            if(ss[i])
                p+=ps[i];
    }
};



int main(){


    vector <int> a;

    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();


    string s;
    int n, p, m;
    char c;

    bool first= true;
    while(t--){
         vector < node > v(101,node(0));
        for(int i=1;i<=100;i++)
            v[i].reset(i);
        a.clear();

        if(!first)
            cout << "\n";
        first=false;

        getline(cin,s);

        do{
            stringstream ss(s);
            ss >> n >> p >> m >> c;

            a.push_back(n);

            if(c=='I' && v[n].ss[p-1]==0 )
               v[n].ps[p-1]+=20;
            if(c=='C' && v[n].ss[p-1]==0 ){ v[n].ps[p-1]+=m; v[n].s++; v[n].ss[p-1]=1;}

              getline(cin,s);
        }while(s!="");

        sort(a.begin(),a.end() );
        a.erase( unique( a.begin(), a.end() ), a.end() );

        vector < node > r;
        for(int i=0;i<a.size();i++){
              r.push_back( v[a[i]]);
              r[i].calcP();
        }

        sort(r.begin(),r.end());
        for(int i=0;i<a.size();i++){
            cout << r[i].n <<" "<<r[i].s <<" "<< r[i].p<<"\n";
        }
    }
    return 0;
}
