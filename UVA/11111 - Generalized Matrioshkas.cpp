#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string line;
    while(getline(cin,line)){

        int x;
        stringstream ss(line);
        stack<pair<int,int>> st;

        bool f = 1;
        while(ss >> x && f){
            if(x < 0){
                if(!st.empty())
                    if(st.top().second + x > 0)
                        st.top().second  = st.top().second  + x;
                    else
                        f = 0;
                st.push(make_pair(x,x*-1));
            }
            else{
                if(!st.empty() && st.top().first == x * -1)
                        st.pop();
                else
                    f=0;
            }
        }

        if(!f || !st.empty())
            cout << ":-( Try again." << "\n";
        else
            cout << ":-) Matrioshka!" << "\n";
    }

    return 0;
}
