class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        //while window size - count[r] > k
        //shrink window
        //need max character
        //getting max character let you see the least changes you want
        int maxF = 0;
        int maxWindow = 0;
        unordered_map<char, int> counts;
        for(int r = 0; r < s.length(); r++){
            counts[s[r]]++;
            maxF = max(maxF, counts[s[r]]);
            while(r-l + 1 - maxF > k){
                counts[s[l]]--;
                l++;
            }

            maxWindow = max(r-l + 1, maxWindow);
        }

        return maxWindow;
    }
};