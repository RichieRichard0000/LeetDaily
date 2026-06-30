class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0,r=0;
        int cnt=0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(mp.size()==3){
                cnt+=(n-r);
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return cnt;
    }
};