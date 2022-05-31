#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

template <typename T>
void print_vector(vector<T> &a, int left, int right)
{
  for_each(a.begin() + left, a.begin() + right + 1, [](T x)
           { cout << x << ", "; });
  cout << endl;
}

long long merge(vector<int> &nums, int l0, int r0, int l1, int r1)
{
  int N = r1 - l0 + 1, idx = 0;
  int result[N];
  int inv = 0;
  // cout << "Merging " << l0 << " -> " << r0 << " and " << l1 << " -> " << r1 << ", " << inv << endl;
  // cout << "Left: ";
  // print_vector(nums, l0, r0);
  // cout << "Right: ";
  // print_vector(nums, l1, r1);
  while (l0 <= r0 or l1 <= r1)
  {
    int add = -1;
    if (l0 > r0)
      add = nums[l1++];
    else if (l1 > r1)
      add = nums[l0++];
    else
    {
      // cout << "Comparing " << nums[l0] << " and " << nums[l1] << "(l0,l1)="<< l0 << "," << l1 << endl;
      inv += (nums[l0] > nums[l1]) ? r0 - l0 + 1 : 0;
      add = (nums[l0] <= nums[l1]) ? nums[l0++] : nums[l1++];
    }
    result[idx++] = add;
  }
  for (int i = N - 1; i >= 0; i--)
  {
    nums[r1--] = result[i];
  }
  // cout << "Inv: " << inv << endl;
  return inv;
}

long long merge_sort(vector<int> &nums, int left, int right)
{
  if (right <= left)
    return 0;
  int mid = (right + left) / 2;
  int invLeft = merge_sort(nums, left, mid);
  int invRight = merge_sort(nums, mid + 1, right);
  int invLR = merge(nums, left, mid, mid + 1, right);
  // print_vector(nums, 0, nums.size()-1);

  return invLeft + invRight + invLR;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }

  // vector<int> a{9,8,7,3,2,1};

  std::cout << merge_sort(a, 0, a.size() - 1) << '\n';
  // cout << "Final Array: " << endl;
  // print_vector(a, 0, a.size() - 1);
}
