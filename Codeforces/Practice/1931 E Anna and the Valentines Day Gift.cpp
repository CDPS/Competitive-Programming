#include <bits/stdc++.h>

using namespace std;

struct node{
    int l, z;
    node(int z, int l): z(z), l(l){}
    bool operator < (const node &a) const{
        return z > a.z;
    }
};

int getZeros(string s){
    int ans = 0, i = s.size()-1;
    while(i>=0 && s[i]== '0') ans++, i--;
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string s;

    int t, n, m;
    cin >> t;

    while(t--){

        cin >> n >> m;

        vector<node> v;
        for(int i=0;i<n;i++)
            cin >>s, v.push_back(node(getZeros(s), s.size()));

        sort(v.begin(), v.end());

        int ans = 0;
        for(int i=0; i < n; i++ )
             ans = (i%2 == 0)?  ans + (v[i].l - v[i].z) : ans + v[i].l;

        cout << (  ans-1 >=m ? "Sasha" : "Anna" ) << "\n";
    }
    return 0;
}
