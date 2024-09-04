#include <bits/stdc++.h>

using namespace std;

string a[1000];

struct node{
    string s;
    node(string s): s(s){}
    bool operator < (const node & a){
        if(s.size() == a.s.size())
            return s < a.s;
        return s.size() < a.s.size();
    }
};

int main(){

    freopen("output.txt","w",stdout);
    int n;

    while(cin >> n && n){

        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a , a + n);

        string s1 = a[(n/2) -1 ];
        string s2 = a[(n/2)];
        string build = "";

        for(int i=0;i<min(s1.size(), s2.size());i++){
            if(s1[i]!=s2[i]){
                build += s1[i] + 1;
                break;
            }
            build+=s1[i];
        }

        vector<node> ans;
        ans.push_back(s1);
        if(build != s2)
            ans.push_back(build);

        sort(ans.begin(),ans.end());

        cout << ans[0].s << "\n";
    }
}


2
ZZZACXY
ZZZB
