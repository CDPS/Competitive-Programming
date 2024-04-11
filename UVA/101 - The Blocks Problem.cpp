#include <bits/stdc++.h>

using namespace std;

stack<int> blocks[25];

int parent[25];

int n;

int getCurrentBlock(int idx){
    while(parent[idx]!=-1)
        idx = parent[idx];
    return idx;
}

void emptyBlock(int idx,int x){
    while(!blocks[idx].empty()){
        int u = blocks[idx].top();
        blocks[idx].pop();
        if(u == x) break;
        parent[u] =  -1;
        blocks[u].push(u);
    }
}

void m(int a, int b,bool onto ){

    int idxa = getCurrentBlock(a);
    int idxb = getCurrentBlock(b);

    if(idxa == idxb) return;

    emptyBlock(idxa,a);
    if(onto)
        emptyBlock(idxb,b), blocks[idxb].push(b);

    parent[a] = (onto)? b :blocks[idxb].top();
    blocks[idxb].push(a);
}

void p(int a, int b, bool onto){

    int idxa = getCurrentBlock(a);
    int idxb = getCurrentBlock(b);

    if(idxa == idxb) return;

    if(onto)
        emptyBlock(idxb,b),blocks[idxb].push(b);

    parent[a] = (onto)? b :blocks[idxb].top();
    stack<int> aux;
    while(!blocks[idxa].empty()){
        int u = blocks[idxa].top();
        blocks[idxa].pop();
        aux.push(u);
        if(u == a) break;
    }

    while(!aux.empty())
        blocks[idxb].push(aux.top()), aux.pop();
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    cin.ignore();

    string line, c, o;
    int a, b;

    for(int i=0;i<n;i++)
        blocks[i].push(i), parent[i]=-1;

    while(getline(cin,line) && line[0]!='q'){
        stringstream ss(line);
        ss >> c >> a >> o >> b;
        if(c[0]=='m')
            m(a,b,o == "onto");
        else
            p(a,b,o == "onto");
    }

    for(int i=0;i<n;i++){
        cout << i << ":";
        string s="";
        while(!blocks[i].empty()){
            s = " " + to_string(blocks[i].top()) + s;
            blocks[i].pop();
        }
        cout << s << "\n";
    }

    return 0;
}
