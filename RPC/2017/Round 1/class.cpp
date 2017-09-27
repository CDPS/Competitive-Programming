#include <bits/stdc++.h>


using namespace std;


struct node{
  string name,lastName;
  string nameLower,lastLower;

  node(string a,string b){
    name = nameLower =a;
    lastName= lastLower=b;
    nameLower[0] = tolower(nameLower[0]);
    lastLower[0] = tolower(lastLower[0]);
  }

  bool operator < (const node &a)const{
      if(lastLower==a.lastLower)
        return nameLower < a.nameLower;
      return lastLower<a.lastLower;
  }

};

int main(){

  int n;
  cin >> n ;

  vector<node> v;

  string name,last;
  while(n--){
    cin >> name >> last;
    v.push_back(node(name,last));
  }

  sort(v.begin(),v.end());

  for(int i=0;i < v.size();i++){
    cout << v[i].name << " " << v[i].lastName << "\n";
  }
  
  return 0;
}
