#include <bits/stdc++.h>

using namespace std;

vector<int> g [20];

int visit[21], esta[21];
int l[21][21];

string to_s(int t) {
  stringstream ss;
  ss << t;
  return ss.str();
}


string dfs(int s,string e){

    string res="";

    for(int i=0;i<g[s].size();i++){
        int v = g[s][i];
        string sv = to_s(v);

        if(!visit[v]){
            res+= e+to_s(s)+"-"+sv+" pathR(G,"+sv+")\n";
            visit[v] = 1;
            res+= dfs(v,e+"  ");
        }else{

        	res+=e+to_s(s)+"-"+sv+"\n";
        }
    }
    return res;
}

int main(){

    int t,caseno=1;
    scanf("%d",&t);

    while(t--){

        int n,m;

        scanf("%d %d",&n,&m);

        int u,v;

        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
        }


        for(int i=0;i<n;i++){

        	if(g[i].size()>0){
        	 	sort(g[i].begin(), g[i].end() );
        	    g[i].erase( unique( g[i].begin(), g[i].end() ), g[i].end() );
        	}

        }

        memset(visit,0, sizeof visit);

        string s ="";
        cout<< "Caso "<<caseno++<<":"<<endl;

        int j=0;

        for(int i=0;i<n;i++){
        	if(j!=0 && !visit[i] && g[i].size()>0)
        		cout << endl;
        	if(!visit[i] && g[i].size()>0){
            	visit[i]=1;
            	s= dfs(i,"  ");
                cout << s;
                j++;
            }else{
            	visit[i]=1;
            }
        }
        cout<<endl;

        for(int i=0;i<n;i++){
            g[i].clear();
        }
    }
    return 0;
}
