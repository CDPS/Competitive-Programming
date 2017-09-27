#include <bits/stdc++.h>

using namespace std;

struct node{
    char c;
    int f;
    node(char a,int b){ c=a; f=b;}

    bool operator < (const node &a) const{
        if(f==a.f)
            return c > a.c;
        return f < a.f;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t;string s;
    cin >> t;
    cin.ignore();
    map<char,int> mp; map<char,int>::iterator it;
    priority_queue<node> pq;

    while(t--){
        getline(cin, s);
        for(int i=0;i<s.size();i++)
            if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                mp[ toupper(s[i])]++;
    }

    for(it = mp.begin();it!=mp.end();it++)
        pq.push(node(it->first,it->second));
    while(!pq.empty()){
        cout << pq.top().c << " " << pq.top().f << "\n";
        pq.pop();
    }
    return 0;
}
