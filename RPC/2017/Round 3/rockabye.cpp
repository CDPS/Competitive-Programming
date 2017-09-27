#include <bits/stdc++.h>

using namespace std;

const string endline = "\n";

struct drug{
    string name;
    long long f;
    int p;
    int fi;

    drug(string a, long long b, int c){
        name =a ; f=b; p=c; fi=b;
    }
    bool operator < (const drug &a) const{
        if(f==a.f){
            return p > a.p;
        }
        return f > a.f;
    }
};

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,k,f;
    string s;
    cin >> t;

    while(t--){
        cin >> n >> k;
        priority_queue<drug> pq;

        for(int i=0;i<n;i++){
            cin >> s >> f;
            pq.push(drug(s,f,i));
        }

        for(int i=0;i<k;i++){
            drug ki = pq.top();
            pq.pop();
            cout << ki.f << " " << ki.name << "\n";

            ki.f += ki.fi;
            pq.push(ki);
        }
    }
    return 0;
}

