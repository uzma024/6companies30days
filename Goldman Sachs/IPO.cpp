class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector <pair<int,int>> v;
        for(int j=0;j<profits.size();j++){
            v.push_back({capital[j],profits[j]});
        }
        sort(v.begin(), v.end());
        priority_queue<int> q;
        int i=0;
        
        while(i<v.size() && k){
            if(w>=v[i].first){
                q.push(v[i].second);
                i++;
            }else{
                if(q.empty())return w;
                w+=q.top();
                q.pop();
                k--;
            }
        }
        while(k-- && !q.empty()){
            w+=q.top();
            q.pop();
        }
        return w;
    }
};