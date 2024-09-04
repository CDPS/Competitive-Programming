#include <bits/stdc++.h>

using namespace std;

bool solved[41][26];
int  score[41][26];
int tries[41][26];

int getScore(string date){
    int ans =  ( (date[date.size()-2]-'0') * 10  ) + (date[date.size()-1]-'0');
    string partial = "";
    for(int i= date.size()-4;i>=0;i--)
        partial = date[i] + partial;
    return stoi(partial)*60 + ans;
}

struct node{
    int team, solved,score;
    node(int team, int solved, int score): team(team), solved(solved), score(score){}
    bool operator < (const node &a){
        if(solved == a.solved){
            if(score == a.score){
                return team < a.team;
            }
            return score < a.score;
        }
        return solved > a.solved;
    }
};

struct problem{
    int t; char p; int time; char acc;
    problem(int t, char  p,int time, char acc): t(t), p(p), time(time), acc(acc){}
    bool operator < (const problem &a){
        if(time == a.time)
            return acc < a.acc;
        return time < a.time;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int test;
	cin >> test;

	cin.ignore();
	cin.ignore();
    bool first = true;

	while(test--){

        string line;

        memset(score, 0, sizeof(score));
        memset(tries, 0, sizeof(tries));
        memset(solved, 0, sizeof(solved));

        int t; char p; string time; char acc;

        int maxteam = 0;
        vector<problem> problems;
        while(getline(cin, line) && line.size() != 0 ){
            stringstream ss(line);
            ss >> t >> p >> time >> acc;
            problems.push_back(problem(t,p,getScore(time),acc));
        }
        sort(problems.begin(), problems.end());

        int intimes;
        for(int i=0;i<problems.size();i++){
            t = problems[i].t;
            p = problems[i].p;
            acc = problems[i].acc;
            intimes = problems[i].time;
            score[t][p-'A'] = (acc == 'Y' && !solved[t][p-'A'])? intimes : score[t][p-'A'];
            tries[t][p-'A'] = (acc == 'N' && !solved[t][p-'A'])? tries[t][p-'A'] + 1 : tries[t][p-'A'];
            solved[t][p-'A']|= acc == 'Y';
            maxteam = max(maxteam, t);
        }

        int maxsolved = 1;
        vector<node> a;
        for(int i=1;i<=maxteam;i++){
            int totalTime =0;
            int totalSolved = 0;
            bool s = false;
            for(int j=0;j<26;j++){
                if(solved[i][j]){
                    totalSolved++;
                    s= true;
                    totalTime+= score[i][j] + (tries[i][j]*20);
                }
            }

            if(s) maxsolved++;
            a.push_back(node(i,totalSolved, totalTime));
        }
        sort(a.begin(), a.end());

        int pos = 0;
        int prev = -1;
        cout << "RANK TEAM PRO/SOLVED TIME\n";
        for(int i=0;i<a.size();i++){
            if(a[i].score != prev) pos=i+1, prev = a[i].score;
            if(a[i].solved == 0)
                cout << setw(4) << maxsolved << " " << setw(4) << a[i].team << "\n";
            else
                cout << setw(4) << pos << " " << setw(4) << a[i].team << setw(5) << a[i].solved << setw(11) << a[i].score << "\n";
        }

        if(test)
            cout << "\n";
	}
    return 0;
}
