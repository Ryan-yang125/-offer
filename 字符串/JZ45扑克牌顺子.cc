//排序然后比较
class Solution
{
public:
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.empty())
            return false;
        sort(numbers.begin(), numbers.end());
        int zero = 0;
        bool ans = true;
        int i = 0;
        for (; i < numbers.size(); i++)
        {
            if (numbers[i])
                break;
            else
                zero++;
        }
        int tmp = numbers[i++];
        for (; i < numbers.size(); i++)
        {
            int k = numbers[i] - tmp;
            if (!k)
            {
                ans = false;
                break;
            }
            if (k > 1)
            {
                while (--k)
                {
                    if (zero)
                        zero--;
                    else
                    {
                        ans = false;
                        break;
                    }
                }
            }
            tmp = numbers[i];
        }
        return ans;
    }
};