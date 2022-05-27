#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;




int lcs2(vector<int> &a, vector<int> &b)
{
  // write your code here
  size_t rows = a.size(), cols = b.size();
  int M[rows][cols];

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      int up, left, diag;
      up = (i > 0) ? M[i - 1][j] : 0;
      left = (j > 0) ? M[i][j - 1] : 0;
      diag = ((i * j > 0) ? M[i - 1][j - 1] : 0) + (a[i] == b[j]);

      M[i][j] = max(up, max(left, diag));
    }
  }
  return M[rows - 1][cols - 1];
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  // vector<int> a{2,7,5};
  // vector<int> b{2,5};

  std::cout << lcs2(a, b) << std::endl;
}
