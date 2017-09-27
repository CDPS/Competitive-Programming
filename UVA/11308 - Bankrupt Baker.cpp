#include <bits/stdc++.h>

using namespace std;

struct node{
    string cake,cakeLower;
    long c;

    node(string a,long b){
        cake = cakeLower=a; c=b;
        transform(cakeLower.begin(), cakeLower.end(), cakeLower.begin(), ::tolower);
    }

    bool operator < (const node &a) const{
        if(c==a.c)
            return cakeLower < a.cakeLower;
        return c < a.c;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    string binder;

    long m,n,b;
    string in; int c;

    string name; long total;

    bool first = 1;

    while(t--){

        cin.ignore();

        map< string, int> ingredientsB;

        vector<node > v;

        getline(cin, binder);

        cin >> m >> n >> b;


        while(m--){ cin >> in >> c; ingredientsB[in] = c; }

        first =0;

        transform(binder.begin(), binder.end(), binder.begin(), ::toupper );
        cout << binder << "\n";

        while(n--){
        	cin.ignore();

            getline(cin, name);
            cin >> m;

            total=0;

            while(m--){
                cin  >> in >> c;
                total+= ingredientsB[in]*c;
            }
            if(total<=b)v.push_back(node(name,total)) ;
        }

        sort(v.begin(),v.end());
        if(v.size()==0)cout<< "Too expensive!\n";
        else{
            for(int i=0;i<v.size();i++)
                cout << v[i].cake << "\n";
        }
        cout << "\n";
    }
    return 0;
}
