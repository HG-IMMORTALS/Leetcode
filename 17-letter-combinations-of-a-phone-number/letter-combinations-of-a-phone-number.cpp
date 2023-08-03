class Solution {
public:
    const vector<string> pad={
        "","","abc","def","ghi","jkl",
        "mno","pqrs","tuv","wxyz"
    };
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return{};
		vector<string>sol;
        sol.push_back("");

        for(auto digit:digits)
        {
            vector<string>chiku;
            for(auto padosi:pad[digit -'0'])
            {
                for(auto s:sol) 
                {
                    chiku.push_back(s+padosi);
                }
            }
            sol.swap(chiku);
        }
        return sol;
    }
};