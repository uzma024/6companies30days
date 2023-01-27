class Solution {
public:
    typedef pair<string, int> P;
    
    struct lambda {
        bool operator()(P& a, P& b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        }  
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<P, vector<P>, lambda> pq;
        
        map<string,int> m;
        
        for(auto i:words){
            m[i]++;
        }
        
        for(auto i:m){
            pq.push({i.first,i.second});
            while(pq.size()>k){
                pq.pop();
            }
        }
        
        int i = k-1;
        vector<string> result(k);
        while(!pq.empty()) {
            result[i] = pq.top().first;
            pq.pop();
            i--;
        }
        
        return result;
    }
};