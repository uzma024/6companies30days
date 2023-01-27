class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        vector <int> pos;
        int n = students.size();
        for(int i=0;i<n;i++)pos.push_back(i);
        
        int ans=0;
        do{
            int curr=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<students[pos[i]].size();j++){
                    curr += (students[pos[i]][j] == mentors[i][j]);
                }
            }
            ans=max(ans,curr);
        }while(next_permutation(pos.begin(),pos.end()));
        
        return ans;
    }
};

// Should be improved by using bitmasking