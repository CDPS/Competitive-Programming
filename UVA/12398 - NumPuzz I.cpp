#include <bits/stdc++.h>

using namespace std;

int m[3][3];

map<char, vector<pair<int,int>> > mp;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    mp['a'].push_back(make_pair(0,0));
    mp['a'].push_back(make_pair(0,1));
    mp['a'].push_back(make_pair(1,0));

    mp['b'].push_back(make_pair(0,0));
    mp['b'].push_back(make_pair(0,1));
    mp['b'].push_back(make_pair(0,2));
    mp['b'].push_back(make_pair(1,1));

    mp['c'].push_back(make_pair(0,1));
    mp['c'].push_back(make_pair(0,2));
    mp['c'].push_back(make_pair(1,2));

    mp['d'].push_back(make_pair(0,0));
    mp['d'].push_back(make_pair(1,0));
    mp['d'].push_back(make_pair(1,1));
    mp['d'].push_back(make_pair(2,0));

    mp['e'].push_back(make_pair(0,1));
    mp['e'].push_back(make_pair(1,1));
    mp['e'].push_back(make_pair(1,0));
    mp['e'].push_back(make_pair(1,2));
    mp['e'].push_back(make_pair(2,1));

    mp['f'].push_back(make_pair(0,2));
    mp['f'].push_back(make_pair(1,2));
    mp['f'].push_back(make_pair(1,1));
    mp['f'].push_back(make_pair(2,2));

    mp['g'].push_back(make_pair(2,0));
    mp['g'].push_back(make_pair(1,0));
    mp['g'].push_back(make_pair(2,1));

    mp['h'].push_back(make_pair(2,0));
    mp['h'].push_back(make_pair(2,1));
    mp['h'].push_back(make_pair(1,1));
    mp['h'].push_back(make_pair(2,2));

    mp['i'].push_back(make_pair(2,2));
    mp['i'].push_back(make_pair(2,1));
    mp['i'].push_back(make_pair(1,2));

    int caseno = 1;
    string s;
    while(getline(cin, s)){

        for(int i =0;i<3;i++)
            for(int j=0;j<3;j++)
                m[i][j] = 0;

        for(int i =0; i < s.size();i++){
            for(int j=0;j<mp[s[i]].size();j++){

                int x = mp[s[i]][j].first;
                int y = mp[s[i]][j].second;
                m[x][y] = (m[x][y] + 1)%10;
            }
        }

        cout << "Case #" << caseno++ << ":\n";
        for(int i =0;i<3;i++){
            for(int j=0;j<3;j++)
                cout <<((j !=0)? " " : "")<< m[i][j];
            cout << "\n";
        }
    }
    return 0;
}
