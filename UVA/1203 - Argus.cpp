#include <bits/stdc++.h>

using namespace std;

struct node{
    int period,acc, value;
    node(int a,int b,int c):acc(a),value(b),period(c){}
    bool operator < (const node &a) const{
        if(acc==a.acc)
            return value > a.value;
        return acc > a.acc;
    }
};

int main(){

    priority_queue<node> pq;
    string s;

    int value, period, k;
    while( cin >> s && s!="#"){
        cin >> value >> period;
        pq.push(node(period, value, period));
    }

    cin >> k;
    while(k--){
        node u = pq.top();
        pq.pop();
        cout << u.value << "\n";
        pq.push( node( u.acc + u.period, u.value, u.period ) );
    }
    return 0;
}
