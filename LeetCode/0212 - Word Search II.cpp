class Solution {
public:

    struct node {
        node *children[26];
        bool end;
        node(){
            end = false;
            for(int i=0; i<26; i++)
                children[i] = NULL;
        }
    };

    node* root;
    int n, m;
    int xs[4] = {1,-1,0,0};
    int ys[4] = {0,0,1,-1};
    bool visit[12][12];
    
    void insert(string word) {
        node *current = root;
        for(int i = 0; i< word.size(); i++){
            int index = word[i] - 'a';
            if(!current->children[index])
                current->children[index] = new node();
            current = current->children[index];
        }
        current->end =  true;
    }

    bool isValid(int x, int y){
        return x >=0 && x<n && y>=0 && y< m && !visit[x][y];
    }

    void dfs(vector<vector<char>>& board, int x, int y, node* current, string s,vector<string> & ans){
        
        visit[x][y] = true;

        if(current->end)
            ans.push_back(s), current->end = false;
    
        for(int i=0;i<4;i++){
            int vx = x + xs[i], vy = y + ys[i];
            if(isValid(vx,vy) &&  current->children[board[vx][vy]-'a'] )
                dfs(board, vx, vy,current->children[board[vx][vy]-'a'], s + board[vx][vy], ans);        
        }
        visit[x][y] = false; 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        root = new node();

        vector<string> ans;
        n = board.size();
        m = board[0].size();

        for(int i=0;i<words.size();i++)
            insert(words[i]);

        string empty = "";
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(root->children[board[i][j]-'a'])
                    dfs(board, i, j, root->children[board[i][j]-'a'], empty + board[i][j], ans);
        
        return ans;
    }
};