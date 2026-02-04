class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>count;
        for (string&s : words) count[s]++;
        vector<vector<string>>freq(words.size());
        for (auto& [a,b] : count){
            freq[b].push_back(a);
        }
        vector<string>ans;
        ans.reserve(k);
        for (int f = freq.size()-1; f >=0; --f){
            sort(freq[f].begin(),freq[f].end());
            for (string& s : freq[f]){
                ans.push_back(s);
                if (ans.size()==k) return ans;
            }
        }
        
        return ans;
    }
};