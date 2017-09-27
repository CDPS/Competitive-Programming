#include <bits/stdc++.h>

using namespace std;

struct state{
    string p1,p2;
    int turns,crono;
    state(string a,string b,int c,int d){
        p1=a;
        p2=b;
        turns=c;
        crono = d;
    }

    bool operator < (const state &a) const{
        if(turns==a.turns)
            return crono > a.crono;
        return turns < a.turns;
    }
};

int main() {

	int n;
	queue<string> q;
    priority_queue<state> pq;
	string wo,wd,bo,bd;
	cin >> n;
	cin >> wo >> bo >> wd >> bd;

    string name;

    for(int i=0;i<n-4;i++)
        cin >> name, q.push(name);

    string comands;
    cin >>  comands;

    int turnsw=0,turnsb=0;
    int losesb=0,losesw=0;

    string boa= bo , bda = bd, woa = wo, wda = wd;

    for(int i=0;i<comands.size();i++){

        if(comands[i]=='W'){

            swap(wo,wd);
            turnsw++;

            if(losesb==0)
                pq.push(state(boa,bda,turnsb,i));
            else
                pq.push(state(bda,boa,turnsb,i));

            swap(bo,bd);
            q.push(bo);
            bo = q.front();
            q.pop();
            turnsb=0;
            losesb++;
            boa = bo; bda= bd;
        }else{
            swap(bo,bd);
            turnsb++;

            if(losesw==0)
                pq.push(state(woa,wda,turnsw,i));
            else
                pq.push(state(wda,woa,turnsw,i));

            swap(wo,wd);
            q.push(wo);
            wo = q.front();
            q.pop();
            turnsw=0;
            losesw++;
            wda = wd; woa = wo;
        }
    }

    if(turnsw!=0){

        if(losesw==0)
                pq.push(state(woa,wda,turnsw,comands.size()));
            else
                pq.push(state(wda,woa,turnsw,comands.size()));
    }else{

        if(losesb==0)
                pq.push(state(boa,bda,turnsb,comands.size()));
            else
                pq.push(state(bda,boa,turnsb,comands.size()));
    }

     state u = pq.top();
    pq.pop();

    cout << u.p1 << " " << u.p2 <<"\n";
    while(!pq.empty() && u.turns==pq.top().turns){
        cout << pq.top().p1 << " " << pq.top().p2 <<"\n";
        pq.pop();
    }

	return 0;
}
