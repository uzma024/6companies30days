class Solution {
public:
    vector <vector <int>> adjList;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> v;
        int inDegree[numCourses];
    
        
        for(int i=0;i<numCourses;i++){
            adjList.push_back(v);
            inDegree[i]=0;
        }
        for(int i=0;i<prerequisites.size();i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        
        stack<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int top=q.top();
            count++;
            q.pop();
            for(int i=0;i<adjList[top].size();i++){
                inDegree[adjList[top][i]]--;
                if((inDegree[adjList[top][i]])==0){
                    q.push(adjList[top][i]);
                }
            }
        }
        return count==numCourses;
    }
};