class Solution {
public:
    string finalString(string s) {
        string res="";
        for(auto c:s){
            if(c!='i') res+=c;
            else reverse(res.begin(),res.end());
        }
        return res;
    }
};