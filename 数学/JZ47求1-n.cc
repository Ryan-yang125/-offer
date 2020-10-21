#include <iostream>
using namespace std;
//利用构造函数
class tmp
{
public:
    tmp()
    {
        n++;
        sum += n;
    }
    static int getSum() { return sum; }

private:
    static int n;
    static int sum;
};
int tmp::n = 0;
int tmp::sum = 0;
class Solution
{
public:
    int Sum_Solution(int n)
    {
        tmp *a = new tmp[n];
        delete[] a;
        a = nullptr;

        return tmp::getSum();
    }
};
//短路原理递归

class Solution
{
public:
    int Sum_Solution(int n)
    {
        int sum = n;
        n && (sum += Sum_Solution(n - 1));
        return sum;
    }
};