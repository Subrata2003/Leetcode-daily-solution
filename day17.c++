class Solution
{
public:
    int minFlipsMonoIncr(string S)
    {
        int count_flip = 0, count_one = 0;
        for (auto i : S)
        {
            if (i == '1')
                count_one++;
            else
                count_flip++;
            count_flip = min(count_flip, count_one);
        }
        return count_flip;
    }
};