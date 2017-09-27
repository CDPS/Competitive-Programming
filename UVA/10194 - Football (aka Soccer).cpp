#include <bits/stdc++.h>

using namespace std;

struct node{
    int points, wins, goalD, goalScored, playedGames,goalA,ties,loses;
    string name,tolowerName;

    node(string a){
        name = tolowerName =a;
        transform(tolowerName.begin(), tolowerName.end(), tolowerName.begin(), ::tolower);
        points =  wins = goalD = goalScored = playedGames = goalA = ties = loses = 0;
    }

    bool operator < (const node &a) const{
        if(points== a.points){
            if(wins == a.wins){
                if(goalD==a.goalD){
                    if(goalScored == a.goalScored){
                        if(playedGames==a.playedGames)
                            return tolowerName > a.tolowerName;
                        return playedGames > a.playedGames;
                    }
                    return goalScored<a.goalScored;
                }
                return goalD < a.goalD;
            }
            return wins < a.wins;
        }
        return points < a.points;
    }
};

vector<node>  v;

int toInt(string s){
    stringstream ss (s);
    int n; ss >> n;
    return n;
}


void getResult(int idx,int g1,int g2){

    v [idx].goalScored+=g1;
    v [idx].playedGames++;
    v [idx].goalD += g1 - g2;
    v [idx].goalA+= g2;

    if(g1>g2){
        v[idx].points+=3;
        v[idx].wins++;
    }
    if(g1==g2){
        v[idx].points+=1;
        v[idx].ties++;
    }
    if(g1<g2){
        v[idx].points+=0;
        v[idx].loses++;
    }
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n, m;
    cin >> t;
    string tname,s;
    cin.ignore();

    bool first = true;
    while(t--){

        map <string , int > mp;

        if(!first)
         cout << "\n";

        first= false;
        getline(cin,tname);
        cin >> n;
        cin.ignore();
        for(int i=0;i<n;i++){
            getline(cin,s);
            mp[s]=i;
            v.push_back(node(s));
        }

        cin >> m;
        cin.ignore();
        string s1, s2 , n1, n2;
        int g1,g2;

        for(int j=0;j<m;j++){
            getline(cin,s);
            int i=0;
            s1= s2 = n1 = n2="" ;
            while(s[i]!='#'){ s1+=s[i]; i++;} i++;
            while(s[i]!='@'){ n1+=s[i];i++;} i++;
            while(s[i]!='#'){ n2+=s[i]; i++;} i++;
            while(i<s.length()){s2+=s[i]; i++;}
            g1 = toInt(n1); g2 = toInt(n2);
            getResult(mp[s1],g1,g2);
            getResult(mp[s2],g2,g1);
        }

        sort(v.begin(),v.end());
        cout << tname << "\n";
        int r  = v.size()-1;

        for(int i=r;i>=0;i--){
           cout << r-i+1<<") "<<v[i].name<<" "<< v[i].points<<"p, "<<v[i].playedGames<<"g ("<< v[i].wins<< "-" << v[i].ties<< "-" << v[i].loses<<"), " << v[i].goalD<< "gd ("<< v[i].goalScored<< "-" << v[i].goalA<< ")\n";
        }
        v.clear();
    }

    return 0;
}
