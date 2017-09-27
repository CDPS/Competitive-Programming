#include <bits/stdc++.h>

using namespace std;

struct node{
    char c; long long n;
    node(char a,long long b){ c = a; n =b; }
    bool operator < (const node &a )const { return n < a.n; }
};

int main(){

    long long n,k;
    string s;

    cin >> n >> k;
    cin >> s;

    map< char, long long > mp;

    for(int i=0;i<n;i++)
        mp[s[i]]++;

    map<char,long long >::iterator it;
    priority_queue<node> pq;

    for(it = mp.begin();it!=mp.end();it++)
        pq.push( node(it->first,it->second));


    long long res =0;
    while(k>0){
        node u = pq.top(); pq.pop();
        if(k>=u.n)
            res += ( u.n*mp[ u.c ] ) , k-= u.n;
        else
            res+= k*k, k=0;
    }

    cout << res << "\n";
    return 0;
}
