#include <bits/stdc++.h>

using namespace std;

typedef pair<double,double > point;

struct rectangle{
    double a,b,c,d;
    rectangle(double e,double f,double g,double h){
        a= e;b=f;c=g;d=h;
    }
};

vector<rectangle> v;

int main(){

    char op;
    double a,b,c,d,x,y;
    while(cin >> op && op!='*'){
        cin >> a  >> b >> c >>  d;
        v.push_back(rectangle(a,b,c,d));
    }

    int i = 1; bool f;
    while(true){
        cin >> x >> y;
        if(x==9999.9 && y == 9999.9) break;

        f = 0;
        for(int j=0;j<v.size();j++){
            if(x>v[j].a && x <v[j].c && y<v[j].b && y > v[j].d)
                cout << "Point " << i  << " is contained in figure " << j+1 << "\n",f=1;
        }

        if(!f) cout << "Point " << i << " is not contained in any figure\n";
        i++;
    }
    return 0;
}
