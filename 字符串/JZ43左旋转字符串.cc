//简单的字符串，也许有space:O(1)?
class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        int l = str.length();
        string ans(l, ' ');
        for (int i = 0; i < l; i++)
        {
            int index = i >= n ? i - n : (l - (n - i));
            ans[index] = str[i];
        }
        return ans;
    }
};