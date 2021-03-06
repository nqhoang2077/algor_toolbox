#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int get_majority_element(vector<int> &a, int left, int right)
{
  sort(a.begin(), a.end());
  int mid = a[(left + right) / 2];
  int count = 0;
  for (auto i : a)
  {
    if (i == mid)
      count++;
  }
  if (count > a.size() / 2)
  {
    return mid;
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
