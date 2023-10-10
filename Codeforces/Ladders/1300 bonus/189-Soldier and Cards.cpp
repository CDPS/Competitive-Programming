#include <bits/stdc++.h>

using namespace std;

set< pair< queue<int>, queue<int> > > st;

int main(){

    int n,n1,n2,x;
    cin >> n;

    queue<int> q1,q2;

    cin >> n1;
    for(int i=0;i<n1;i++)
       cin >> x, q1.push(x);

    cin >> n2;
    for(int i=0;i<n2;i++)
        cin >> x, q2.push(x);

    int res = 0;
    while(true){

        if(q1.empty()){ cout <<  res <<" 2" << "\n"; break; }

        if(q2.empty()){ cout <<  res <<" 1" << "\n"; break; }

        if(st.find( make_pair(q1, q2) ) != st.end() ){
            cout << "-1" << "\n";
            break;
        }
        st.insert( make_pair(q1, q2) );

        int c1 = q1.front(); q1.pop();
        int c2 = q2.front(); q2.pop();

        if(c1 > c2)
            q1.push(c2),q1.push(c1);
        else
            q2.push(c1),q2.push(c2);

        res++;
    }
    return 0;
}
