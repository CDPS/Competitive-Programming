#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t; string s;
    cin >> t;

    while(t--){

        cin >> s;

        set<char> st;
        map<char,int> mp;
        for(int i=0;i<s.size();i++)
            st.insert(s[i]), mp[s[i]]++;

        bool ans = false;
        if(st.size() == 3 && st.count('M')&& st.count('E')&& st.count('?')
           && mp['M'] == 1 && mp['E'] ==1){
            int x = 0, y=0, z=0, i =0;
            while( i< s.size() && s[i] !='M')x++,i++;i++;
            while( i< s.size() && s[i] !='E')y++,i++;i++;
            while( i< s.size())z++,i++;

            ans =  x>=1 && y>=1 && z>=1;
            ans &= (y-1 >=0 && z-(y-1) == x+1  );
        }
        cout << ( (ans)? "theorem" : "no-theorem" ) << "\n";

    }
    return 0;
}
