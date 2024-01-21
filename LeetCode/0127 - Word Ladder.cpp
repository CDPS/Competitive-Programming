class Solution {
public:

    unordered_set<string> allowed;
    unordered_set<string> visit;

    char ad[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    int bfs(string s, string t){

        queue<pair<string,int>> q;
        q.push(make_pair(s,1));
        visit.insert(s);

        while(!q.empty()){
            pair<string,int> u = q.front();
            q.pop();

            string us = u.first;
            int ul = u.second;

            if(us == t)
                return ul;
            
            for(int i=0;i<us.size();i++){
                char curr = us[i];
                for(int j=0;j<26;j++){
                    us[i] = ad[j];
                    if(allowed.count(us) && !visit.count(us))
                        q.push(make_pair(us, ul +1)), visit.insert(us);
                }
                us[i] = curr;
            }
        }
        return 0;
    }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        for(int i=0;i<wordList.size();i++)
            allowed.insert(wordList[i]);
        
        if(!allowed.count(endWord))
            return 0;

        return bfs(beginWord, endWord);
    }
};