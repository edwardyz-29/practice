class Solution {
public:
    string intToRoman(int num) {
        vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        const int size = 13;
        string res="";
        for(int i = 0; i < size; i++) {
            int times = num/val[i];
            for(int j = 0; j < times; j++) {
                res += sym[i];
            } 
            num %= val[i];
        }
        return res;
    }
};