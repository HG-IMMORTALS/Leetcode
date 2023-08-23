class Solution {
public:
    string reorganizeString(string s) {
        vector<int>count(26);
        int mostFreq=0,i=0;
        for(char c:s)
         if(++count[c-'a']>count[mostFreq])
          mostFreq=(c-'a');
        if(2*count[mostFreq]-1>s.size()) return "";
        while(count[mostFreq])
        {
            s[i]=('a'+mostFreq);
            i+=2;
            count[mostFreq]--;
        }
        for(int j=0;j<26;j++)
        {
            while(count[j])
            {
                if(i>=s.size()) i=1;
                s[i]=('a'+j);
                count[j]--;
                i+=2;
            }
        }
        return s;
    }
};