#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_change(int m)
{
  // write your code here;
  vector<int> changes{0, 1, 2, 1, 1};
  changes.resize(m + 1);
  if (m < 5)
    return changes[m];
  for (int i = 5; i < m + 1; i++)
  {
    int change1 = changes[i-1] + changes[1];
    int change3 = changes[i-3] + changes[3];
    int change4 = changes[i-4] + changes[4];
    changes[i] = min(change1, min(change3, change4));
  }
  // for_each(changes.begin(), changes.end(), [](int x){cout << x << ", "; });
  return changes[m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
