class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.length();
        queue <int> q1,q2;
        
        for(int i=0;i<n;i++) senate[i]=='R'?q1.push(i):q2.push(i);
        
        while(!q1.empty() && !q2.empty()){
            int r= q1.front() , d= q2.front();
            q1.pop();
            q2.pop();
            
            r<d?q1.push(r+n):q2.push(d+n);
        }
        
        return q1.size()>q2.size()? "Radiant" : "Dire";
    }
};