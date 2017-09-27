#include <bits/stdc++.h>

using namespace std;

const int inf = 2000000000;

vector<int> a,i,id,p;
int length,last;

int binarySearch(int t){
    int l = 0, h = i.size(),m;
    while(l< h){
        m = l+ ((h-l)/2);
        if( t  <= i[m]) h = m;
        else l = m+1;
    }
    return l;
}

void dp(){

    i  = vector<int>(a.size(),inf);

    p = id = vector<int>(a.size(),-1);

    i[0]=a[0];id[0]=0;
    length = 1;last=0;

    for(int j=1;j<a.size();j++){

        int index = binarySearch(a[j]);
        i[index]  = a[j];
        id[index] = j;

        p[j]= index? id[index-1] :-1;

        if(index == length)
            length++, last = j;
    }

    stack<int> s; int x = last;

    for(;p[x]>=0;x =p[x]) s.push(a[x]);
    s.push(a[x]);

    cout << "Max hits: "<< length<< "\n";
    while(!s.empty()) cout << s.top() << "\n",s.pop();
}


int toInt(string s){
    stringstream ss(s); int n;
    ss >> n;
    return n;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    string s;
    cin.ignore(); cin.ignore();

    while(t--){

        a  = vector<int>();
        int ai;
        while(getline(cin,s) && s!="") a.push_back(toInt(s));

        dp();
        if(t!=0) cout << "\n";
    }
    return 0;
}
