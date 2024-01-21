class Solution {
public:
    
    unordered_set<string> allowed;
    unordered_set<string> visit;

    char ad[4] = {'A','C','G', 'T'};

    int bfs(string s, string t){

        queue<pair<string,int>> q;
        q.push(make_pair(s,0));
        visit.insert(s);

        while(!q.empty()){
            pair<string,int> u = q.front();
            q.pop();

            string us = u.first;
            int ul = u.second;

            if(us == t)
                return ul;
            
            for(int i=0;i<8;i++){
                char curr = us[i];
                for(int j=0;j<4;j++){
                    us[i] = ad[j];
                    if(allowed.count(us) && !visit.count(us))
                        q.push(make_pair(us, ul +1)), visit.insert(us);
                }
                us[i] = curr;
            }
        }
        return -1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        for(int i=0;i<bank.size();i++)
            allowed.insert(bank[i]);
        
        if(!allowed.count(endGene))
            return -1;

        return bfs(startGene, endGene);
    }
};