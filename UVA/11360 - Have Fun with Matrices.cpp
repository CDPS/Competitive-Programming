#include <bits/stdc++.h>

using namespace std;

int n,q;
int m[10][10],cm[10][10];
int c[10];

void tr(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cm[j][i] = m[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
             m[i][j] = cm[i][j];
}

void add(int x){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            m[i][j]= (m[i][j] + x);
            if(m[i][j]==10)m[i][j]= 0;
            if(m[i][j]==-1)m[i][j]= 9;
        }
}

void r(int a, int b){
    for(int i=0;i<n;i++){
        c[i] = m[a][i];
        m[a][i] = m[b][i];
        m[b][i] = c[i];
    }
}

void rp(int a, int b){
    for(int i=0;i<n;i++){
        c[i] = m[i][a];
        m[i][a] = m[i][b];
        m[i][b] = c[i];
    }
}

int main(){

    int t, a, b,caseno=1;
    cin >> t ;
    string s,cmd,op;
    while(t--){

        cin >> n;
        for(int i=0;i<n;i++){
            cin >> s;
            for(int j=0;j<n;j++)
                m[i][j]= s[j]-'0';
        }
        cin >> q;
        cin.ignore();

        while(q--){
            getline(cin,cmd);
            stringstream ss(cmd);
            if(cmd[0]=='t') tr();
            if(cmd[0]=='i') add(1);
            if(cmd[0]=='d') add(-1);
            if(cmd[0]=='r') ss >> op >> a >> b, r(a-1,b-1);
            if(cmd[0]=='c') ss >> op >> a >> b,rp(a-1,b-1);
        }

        cout << "Case #" << caseno++ <<"\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<< m[i][j];
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
