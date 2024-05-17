class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& W, vector<string>& P) {
        unordered_map<int, int> mp;       
        vector<int> ans(size(P));
		
        auto getBitmask = [](string& s) {
            int bitmask = 0;
            for(auto c : s) bitmask |= 1 << c-'a';
            return bitmask;
        };
	
        for(auto& word : W)  mp[getBitmask(word)]++;
        for(int i = 0; auto& puzzle : P) {
            int mask = getBitmask(puzzle), cnt = 0, firstLetter = 1 << puzzle[0]-'a';
            for(int submask = mask; submask; submask = (submask - 1) & mask)   
                if(submask & firstLetter)    
                    cnt += mp[submask];      
            ans[i++] = cnt;
        }
        return ans;
    }
};
