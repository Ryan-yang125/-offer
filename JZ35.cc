class Solution
{
    long long cnt = 0;
    const int kmod = 1000000007;

public:
    int InversePairs(vector<int> data)
    {
        if (data.empty())
            return -1;

        vector<int> tmp(data.size(), -1);
        Msort(data, tmp, 0, data.size() - 1);
        return cnt;
    }
    void Msort(vector<int> &arr, vector<int> &tmp, int left, int right)
    {
        if (left >= right)
            return;
        int center = left + ((right - left) >> 1);
        Msort(arr, tmp, left, center);
        Msort(arr, tmp, center + 1, right);
        Merge(arr, tmp, left, right);
    }
    void Merge(vector<int> &arr, vector<int> &tmp, int left, int right)
    {
        int lep = left + (right - left) / 2;
        int rsp = lep + 1;
        int index = right;
        int rep = right;
        while (lep >= left && right >= rsp)
        {
            if (arr[lep] > arr[right])
            {
                cnt += (right - rsp + 1);
                cnt %= kmod;
                tmp[index--] = arr[lep--];
            }
            else
            {
                tmp[index--] = arr[right--];
            }
        }
        while (lep >= left)
            tmp[index--] = arr[lep--];
        while (right >= rsp)
            tmp[index--] = arr[right--];
        for (int i = lep; i <= rep; i++)
            arr[i] = tmp[i];
    }
};