#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    // k = k % nums.size();
    auto k_pointer = nums.begin() + k;
    vector<int> temp(k_pointer, nums.end());
    for (auto it = nums.begin(); it < k_pointer; ++it)
    {
        temp.push_back(*it);
    }
    nums.swap(temp);
}

int main()
{
    vector<int> nums{1,2,3,4,5,6,7};
    rotate(nums, 3);
    cout << nums << endl;
    return 0;
}