//区间和的常用优化：前缀和
class Solution
{
public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= sum / 2; i++)
        {
            int tmp = i;
            for (int j = i + 1; j < sum; j++)
            {
                tmp += j;
                if (tmp == sum)
                {
                    vector<int> a;
                    for (int m = i; m <= j; m++)
                    {
                        a.push_back(m);
                    }
                    ans.push_back(a);
                    break;
                }
                else if (tmp > sum)
                    break;
                else
                    continue;
            }
        }
        return ans;
    }
};

//滑动窗口

class Solution
{
public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        vector<vector<int>> ans;
        int l = 1, r = 1;
        int tmp = 0;
        while (l <= sum / 2)
        {
            if (tmp < sum)
            {
                tmp += r;
                r++;
            }
            else if (tmp > sum)
            {
                tmp -= l;
                l++;
            }
            else
            {
                vector<int> a;
                for (int k = l; k < r; k++)
                {
                    a.push_back(k);
                }
                ans.push_back(a);
                tmp += r;
                r++;
            }
        }
        return ans;
    }
};