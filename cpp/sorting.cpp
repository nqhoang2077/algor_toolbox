#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

void print_vector(vector<int> &a, int l, int r)
{
  for (int i = l; i <= r; ++i)
    cout << a[i] << " ";
}

int *partition3(vector<int> &a, int l, int r)
{
  int x = a[l];
  int j = l;
  int c = 0;
  for (int i = l + 1; i <= r; i++)
  {
      if (a[i]<=x){
          swap(a[i], a[++j]);
          c += (a[i]==x);
          if (a[j-c]==x && a[j]<x){
              swap(a[j],a[j-c]);
          }
      }
  }
  swap(a[l], a[j]);
  
  int *ret{new int[2]{j-c, j}};
  return ret;
}
  void randomized_quick_sort(vector<int> &a, int l, int r)
  {
    if (l >= r)
    {
      return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);

    auto part = partition3(a, l, r);

    int j = part[0], h = part[1];

    randomized_quick_sort(a, l, j);
    randomized_quick_sort(a, h+1, r);
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

  randomized_quick_sort(a, 0, a.size() - 1);

  print_vector(a, 0, a.size() - 1);
}
