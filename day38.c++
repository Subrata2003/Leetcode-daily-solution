class Solution {
public:

    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> mpp;

        int i = 0, j = 0, res = 0;
        
        while(j < fruits.size())
        {

            mpp[fruits[j]]++;
            
            if(mpp.size() <= 2)
            {

                int temp = 0;

                for(auto &it : mpp) temp += it.second;

                res = max(res, temp);
            }
            
            else
            {
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i++;
            }

            j++;
        }

        return res; 
    }
};