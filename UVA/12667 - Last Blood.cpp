#include <bits/stdc++.h>

using namespace std;

pair<int,int> score[101][13];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n,t,m;

    for(int i=0;i<=100;i++)
        for(int j=0;j<=12;j++)
            score[i][j]=make_pair( -1, -1);

    cin >> n >> t >> m;

    int time, team; char problem; string veredict;

    for(int i=0;i<m;i++){
        cin >> time >> team >> problem >> veredict;
        if(veredict =="Yes" && score[team][ problem - 'A'].first == -1){
            score[team][ problem - 'A'] = make_pair(time, i);
        }
    }

    int index = -1;
    for(int i=0;i<n;i++){
        index = time = team = -1;

        for(int j=0;j<=t;j++)
            if( score[j][i].first > time)
                time = score[j][i].first, team = j, index = score[j][i].second;
            else if( score[j][i].first == time && score[j][i].second > index  )
                time = score[j][i].first, team = j, index = score[j][i].second;

        problem = 'A' + i;
        cout << problem << " ";

        if(time == -1){
            cout << "- -" << "\n";
        }else{
            cout << time << " " << team << "\n";
        }
    }

    return 0;
}
