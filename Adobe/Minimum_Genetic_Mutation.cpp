class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int mut=0,n=start.length();
        
        unordered_set <string> vis;
        vector <char> avail{'A', 'C', 'G','T'};
        
        queue <string> q;
        q.push(start);
        vis.insert(start);
        
        
        while(q.size()){
            int size=q.size();
            while(size--){
                string curr=q.front();
                q.pop();
                
                if(curr==end)return mut;
                
                for(int i=0;i<8;i++){
                    char orig = curr[i]; 
                    for(int j=0;j<4;j++){
                        curr[i]=avail[j];
                        auto fin = find(bank.begin(),bank.end(),curr);
                        if(fin!=bank.end() && vis.find(curr)==vis.end()){
                            q.push(curr);
                            vis.insert(curr);
                        }
                    }
                    curr[i]=orig;
                }
            }
            mut++;
        }
        
        return -1;
    }
};