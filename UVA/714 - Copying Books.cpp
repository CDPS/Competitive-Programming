#include <bits/stdc++.h>

using namespace std;

unsigned long long binarySearch(vector<unsigned long long> books,int k){

    unsigned long long l = *max_element(books.begin(),books.end());
    unsigned long long h =   accumulate(books.begin(),books.end(),0);
    unsigned long long m, acc;

    int scribers;

    while(l<h){
        m = l + (h-l)/2;
        scribers= 1; acc = 0;

        for(int i=0;i<books.size();i++)
            if(acc + books[i] <= m) acc+=books[i];
            else acc=books[i] , scribers++;

        if(scribers<= k) h = m;
        else l = m +1;
    }
    return l;
}

int main(){

    int t,n,k;
    cin >> t;
    while(t--){

        cin >> n >> k;
        vector<unsigned long long> books(n);

        for(int i=0;i<n;i++)
            cin >> books[i];

        unsigned long long work = binarySearch(books,k);

        vector< vector<unsigned long long> > ans;

        unsigned long long acc=0;

        for(int i=n-1;i>=0;i--){
            vector<unsigned long long> s;
            acc=0;
            while(books[i]+ acc <= work && k-1<=i){ s.push_back(books[i]); acc+= books[i]; i--; }
            i++; k--;
            ans.push_back(s);
        }

        for(int i=ans.size()-1;i>0;i--){
            for(int j=ans[i].size()-1;j>=0;j--)
                cout << ans[i][j] << " ";
            cout << "/ ";
        }

        for(int j=ans[0].size()-1;j>=0;j--)
            cout << ans[0][j]<< (j==0?"\n":" ");
    }
    return 0;
}
