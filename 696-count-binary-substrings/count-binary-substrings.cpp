class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=0,prev=0,curr=1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i-1]==s[i]) curr++;
            else
            {
                cnt+=min(curr,prev);
                prev=curr;
                curr=1;
            }
        }
        cnt+=min(prev,curr);
        return cnt;
    }
};