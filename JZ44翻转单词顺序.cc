//翻转两次

#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    string ReverseSentence(string str)
    {
        if (str.empty())
            return str;
        reverse(str, 0, str.length() - 1);
        size_t last = 0;
        size_t next = 0;
        while ((next = str.find(' ', last)) != string::npos)
        {
            reverse(str, last, next - 1);
            cout << str << endl;
            last = next + 1;
        }
        reverse(str, last, str.length() - 1);
        return str;
    }
    void reverse(string &s, int i, int j)
    {
        while (i < j)
        {
            char tmp = s[i];
            s[i++] = s[j];
            s[j--] = tmp;
        }
    }
};

int main()
{
    Solution s;
    cout << s.ReverseSentence("I am a student.");
}