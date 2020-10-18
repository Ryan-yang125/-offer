class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.empty())
            return 0;
        int left = 0;
        int right = data.size();
        int ans = 0;
        int center;
        while (left < right)
        {
            center = left + ((right - left) >> 1);
            if (data[center] == k)
                break;
            else if (data[center] < k)
                left = center + 1;
            else
                right = center;
        }
        int index = center - 1;
        while (center < data.size() && data[center] == k)
        {
            ans++;
            center++;
        }
        while (index >= 0 && data[index] == k)
        {
            ans++;
            index--;
        }
        return ans;
    }
};
