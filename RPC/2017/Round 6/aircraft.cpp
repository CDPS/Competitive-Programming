#include <bits/stdc++.h>

using namespace std;

int xa[15],ya[15],za[15];
int xb[15],yb[15],zb[15];

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,x,a,d;
        cin >> x >> a >> d >> n;

        int m=n/2;

        map< pair<int,pair<int,int> >, long long> mp;
        string ss;

        for(int i=0;i<m;i++)
            cin >> ss >> xa[i] >> ya[i] >> za[i];

        for(int i=0;i<n-m;i++)
            cin >> ss >>xb[i] >> yb[i] >> zb[i];


        long s= (1<<m);
        for(long i=0; i<s ;i++){
            int aux=0,auy=0, auz=0;
            for(int j=0;j<m;j++){
                if( (i&(1<<j))!=0){ aux+=xa[j]; auy+=ya[j]; auz+=za[j];}
            }
            mp[ make_pair(aux,make_pair(auy,auz))]++;
        }

        s= (1<< (n-m) );
        long long res=0;

        bool f=0;
        for(long i=0; i<s; i++){
            int aux=0,auy=0,auz=0;
            for(int j=0;j<n-m;j++)
                if( (i&(1<<j))!=0){ aux+=xb[j]; auy+=yb[j]; auz+=zb[j];}
            aux =  x - aux; auy =  a - auy; auz =  d - auz;
            map<pair<int, pair<int,int> > ,long long>::iterator it = mp.find(make_pair(aux, make_pair(auy,auz)));
           if ( it != mp.end() ){ f = 1; break;}
        }

        if(f)
           cout << "POSSIBLE\n";
        else
         cout  << "IMPOSSIBLE\n";
    }

    return 0;
}
