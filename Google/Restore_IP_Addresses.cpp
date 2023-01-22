class Solution {
public:
    
    vector<string> ans;
    
    bool isValid(string s){
        // cout<<s<<endl;
        if(s.size()>3 || s.size()==0)return false;
        if(s.size()>1 && s[0]=='0')return false;
        if(s.size() && stoi(s)>255)return false;
        // cout<<"true^ "<<endl;
        return true;
    }
    
    void helper(int ind,int dots,string curr,string s){ 
        // cout<<s[ind]<<endl;
        if(dots==3){
            if(isValid(s.substr(ind))){
                ans.push_back(curr+ s.substr(ind));
            }
            return;
        }
        
        for(int i=ind;i<s.size();i++){
            if(isValid(s.substr(ind,i-ind+1))){
                curr.push_back(s[i]);
                curr.push_back('.');
                helper(i+1,dots+1,curr,s);
                curr.pop_back();
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        string curr;
        helper(0,0,curr,s);
        return ans;
    }
};