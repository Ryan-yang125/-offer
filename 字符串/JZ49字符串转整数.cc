class Solution
{
public:
    int StrToInt(string str)
    {
        if (str.empty())
            return 0;
        int ans = 0;
        int carry = 1;
        for (int i = str.length() - 1; i > 0; i--)
        {
            int a = str[i] - '0';
            if (a < 0 || a > 9)
            {
                ans = 0;
                break;
            }
            ans += a * carry;
            carry *= 10;
        }
        int sign = 1;
        if (!ans)
            return ans;
        if (str[0] == '+' || str[0] == '-')
            sign = str[0] == '-' ? -1 : 1;
        else
            ans += (str[0] - '0') * carry;
        return ans * sign;
    }
};