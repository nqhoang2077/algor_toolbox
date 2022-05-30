#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using namespace std;

int binary_search(const vector<int> &a, int x) {
  // cout << "searching " << x << " -> ";
  int left = 0, right = (int)a.size()-1; 
  //write your code here

  while (left <= right) {
    int mid = (left + right ) /2;
    int aMid = a[mid];

    if (x == aMid) {
      return mid;
    } else if (x > aMid) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  // vector<int> a {1,5,8,12,13};
  // vector<int> b {8,1,23,1,11};

  // vector<int> a {2,4,4,4,7,7,9};
  // // vector<int> a {2,4,7,9};
  // vector<int> b {9,4,7,2};
  // auto m = b.size();

  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
