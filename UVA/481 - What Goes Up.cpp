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

        if(index >= length)
            length=index, last = j;
    }

    stack<int> s; int x = last;

    for(;p[x]>=0;x =p[x]) s.push(a[x]);
    s.push(a[x]);

    cout << length+1 << "\n-\n";
    while(!s.empty()) cout << s.top() << "\n",s.pop();
}

int main(){
    int ai;
    while(cin >> ai) a.push_back(ai);
    dp();
    return 0;
}
