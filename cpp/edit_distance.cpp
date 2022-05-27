#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using namespace std;

int edit_distance(string str1, string str2)
{
  // write your code here
  str1 = " " + str1;
  str2 = " " + str2;
  size_t c{str1.size()}, r{str2.size()};
  int M[r][c];

  for (auto rc : M)
  {
    for_each(rc, rc + c, [](int& x)
             { x = 0; });
  }

  for (int rc=0; rc<c; rc++)
    M[0][rc] = rc;
  for (int rr=0; rr<r; rr++)
    M[rr][0] = rr;

  for (int i=1; i<r; i++){
    for (int j=1; j<c; j++){
      vector<int> compare{
        M[i][j-1] + 1, // Delete
        M[i-1][j] + 1, // Insert
        M[i-1][j-1] + (str2[i]!=str1[j]) // Replace if unmatch, nothing if match
      };
      M[i][j] = *min_element(compare.begin(), compare.end());
    }
  }

  // for (auto rw : M)
  // {
  //   for_each(rw, rw + c, [](int x)
  //            { cout << x << ", "; });
  //   cout << endl;
  // }

  return M[r-1][c-1];
}

int main()
{
  string str1;
  string str2;
  str1 = "editing";
  str2 = "distance";
  std::cin >> str1 >> str2;

  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
