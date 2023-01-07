class Solution {
public:
    
    class cmp {
        public:
        bool operator()(pair<int, int>& a, pair<int, int>& b) {//always put the smallest and shortest sequence on the top of the heap
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
    };
    
    bool isPossible(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        int i=0,n=nums.size();
        
        while(i<n){
            if(q.empty()){
                q.push({nums[i],1});
                i++;
            }else{
                auto temp=q.top();
                
                if(temp.first==nums[i]){
                    q.push({nums[i],1});
                    i++;
                }else if(nums[i]== temp.first +1){
                    q.pop();
                    q.push({nums[i],temp.second+1});
                    i++;
                }else{
                    if(temp.second<3){
                        return false;
                    }
                    q.pop();
                }
            }
        }
        while(!q.empty()){
            if(q.top().second<3){
                return false;
            }
            q.pop();
        }
        return true;
    }
};