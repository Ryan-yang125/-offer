// 1.^
// 2.k &= -k 为第一位1

class Solution
{
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        int k = 0;
        for (int x : data)
        {
            k ^= x;
        }
        k &= (-k);
        *num1 = 0, *num2 = 0;
        for (int x : data)
        {
            if (k & x)
                *num1 ^= x;
            else
                *num2 ^= x;
        }
    }
};