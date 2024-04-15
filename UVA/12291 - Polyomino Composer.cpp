#include <bits/stdc++.h>

using namespace std;

bool v[12][12];
string a[12], b[12];

int n,m;

struct node{
    int x,y;
    node(int x, int y) : x(x), y(y){}
};

bool isValid(int x, int y){
    return x >=0 && x < n && y>=0 && y < a[x].size() && a[x][y] == '*' && v[x][y]==false;
}

bool check(){
    for(int i=0;i<n;i++)
        for(int j=0;j<a[i].size();j++)
            if(a[i][j]=='*' && !v[i][j])
                return false;
    return true;
}

vector<node> getPath(int x,int y){
    vector<node> path;
    for(int i=0;i<m;i++)
        for(int j=0;j<b[i].size();j++)
            if(b[i][j]=='*')
                path.push_back(node(i - x, j -y));
    return path;
}

bool fit(int x, int y, vector<node> &path){
    for(int i=0;i<path.size();i++)
        if(!isValid(x + path[i].x, y + path[i].y))
            return false;
    return true;
}

void visitPath(int x, int y, vector<node> &path){
    for(int i=0;i<path.size();i++)
        v[x + path[i].x][y + path[i].y] = true;
}

void searchParent(vector<node> &path){
    for(int i=0;i<n;i++)
        for(int j=0;j<a[i].size();j++)
            if(a[i][j]=='*' && !v[i][j] && fit(i,j,path)){
                visitPath(i, j,path); return;
            }
}

bool solve(vector<node> &path){
    searchParent(path);
    searchParent(path);
    return check();
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(cin >> n >> m && (n||m) ){

        for(int i=0;i<n;i++){
            cin >> a[i];
            for(int j=0;j<a[i].size();j++)
                 v[i][j]=false;
        }

        int x = -1, y=-1;
        bool first = true;
        for(int i=0;i<m;i++){
            cin >> b[i];
            for(int j=0;j<b[i].size();j++){
                if(b[i][j]=='*' && first)
                    x = i, y = j, first= false;
            }
        }

        vector<node> path = getPath(x,y);
        cout  << solve(path) << "\n";
    }
    return 0;
}
