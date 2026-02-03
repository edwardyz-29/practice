class Solution {
public:
    int candy(vector<int>& ratings) {
        // sweep once left, then sweep once right
        int n =  ratings.size();
        vector<int> candies(n, 1);
        //first sweep
        for(int i = 1; i<n; ++i){
            if (ratings[i]>ratings[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }
        //ratings: [1,0,2]
        //candies: [1,1,2]
        //second sweep: from right to left
        int total = 0;
        for(int i=n-2; i>=0; --i){
            if (ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1]+1); 
            }
        }
        for (auto candie:candies){
            total+=candie;
        }
        return total;
    }
};