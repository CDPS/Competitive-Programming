#include <bits/stdc++.h>

using namespace std;

struct node{
    string name,year;
    node(){}
    node(string name, string year): name(name), year(year){}
    bool operator < (const node &a)const{
        return year > a.year;
    }
};

int main(){

    int n;
    cin >> n;

    string name, d,m,y;
    vector<node> a;
    for(int i=0;i<n;i++){
        cin >> name >> d >> m >> y;
        if(d.size()==1) d = '0' + d;
        if(m.size()==1) m = '0' + m;
        a.push_back(node(name, y + m + d));
    }

    sort(a.begin(), a.end());
    cout << a[0].name << "\n";
    cout << a[n-1].name << "\n";
    return 0;
}
