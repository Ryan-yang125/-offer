//双指针，类似于滑动窗口
class Solution
{
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> ans;
        if (array.empty())
            return ans;
        ans.push_back(0);
        ans.push_back(0);
        int l = 0, r = array.size() - 1;
        int min = __INT_MAX__;
        while (l < r)
        {
            int tmp = array[l] + array[r];
            if (tmp < sum)
                l++;
            else if (tmp > sum)
                r--;
            else
            {
                int dot = array[l] * array[r];
                if (dot < min)
                {
                    min = dot;
                    ans[0] = array[l];
                    ans[1] = array[r];
                }
                r--;
            }
        }
        if (min == __INT_MAX__)
            return vector<int>();
        return ans;
    }
};