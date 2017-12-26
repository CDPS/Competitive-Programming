#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false);cin.tie(NULL);
    int caseno;
    string ans, guess;
    while(cin >> caseno && caseno!=-1){

        vector<int> v(26,0);
        cin >> ans >> guess;

        int acc=0;
        for(int i=0;i<ans.size();i++){
            if(v[ans[i]-'a']==0)acc++;
            v[ans[i]-'a']=1;
        }

        int loses=0;
        int win=0;

        int r=0;
        for(int i=0;i<guess.size();i++){
            int idx = guess[i]-'a';
            if(v[ idx  ]==0){
                   loses++;
            }if(v[ idx  ]==1){
                win++;
                v[idx]++;
            }
            if(loses== 7){r=2;break;}
            if(win==acc){r=1;break;}
        }

        cout << "Round " << caseno << "\n";
        if(r ==0){
            cout << "You chickened out.\n";
        }else if(r==1){
            cout << "You win.\n";
        }else{
            cout << "You lose.\n";
        }
    }
    return 0;
}
