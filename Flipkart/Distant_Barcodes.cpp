class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()<=1)return barcodes;
        
        map<int,int>m;
        for(auto i:barcodes)m[i]++;
        
        priority_queue <pair<int,int>> q;
        for(auto i:m)q.push({i.second,i.first});
        
        vector<int> ans;
        while(q.top().first>0){
            auto p1=q.top();
            q.pop();
            ans.push_back(p1.second);
            p1.first--;
            
            auto p2=q.top();
            q.pop();
            if(p2.first>0){
                ans.push_back(p2.second);
                p2.first--;
            }
            
            q.push(p1);
            q.push(p2);
        }
        
        return ans;
    }
};