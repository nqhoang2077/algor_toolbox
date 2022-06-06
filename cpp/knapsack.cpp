#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using namespace std;
using Position = std::pair<int, int>;


struct hash_pair
{
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const
  {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);

    if (hash1 != hash2)
    {
      return hash1 ^ hash2;
    }

    // If hash1 == hash2, their XOR is zero.
    return hash1;
  }
};

#define MAX_N 301
#define MAX_W 10001

int optimal_weight2(int W, const vector<int> &ws)
{
  // write your code here
  auto n{ws.size()};
  int** valueMap = new int*[MAX_W];

  for (int i = 0; i <= W; i++)
  {
    valueMap[i] = new int[MAX_N];
    valueMap[i][0] = 0;
  }

  for (int i = 0; i <= n; i++)
    valueMap[0][i] = 0;

  for (int i = 0; i <= W; i++)
    valueMap[i][0] = 0;

  for (int i = 1; i <= n; i++)
    for (int w = 1; w <= W; w++)
    {
      valueMap[w][i] = valueMap[w][i - 1];
      if (ws[i] <= w)
      {
        int val = valueMap[w - ws[i]][i - 1] + ws[i];
        if (valueMap[w][i] < val)
          valueMap[w][i] = val;
      }
    }
  int result = valueMap[W][n];
  for (int i = 0; i <= W; i++)
    delete valueMap[i];
  delete[] valueMap;
  return result;
}


int optimal_weight1(int W, const vector<int> &ws)
{
  // write your code here
  auto n{ws.size()};
  // unordered_map<Position, int, hash_pair> valueMap;
  vector<vector<int>> valueMap(W+1);
  // int valueMap[W + 1][n + 1];

  for (int i = 0; i <= W; i++)
  {
    valueMap[i] = vector<int>(n+1);
    valueMap[i][0] = 0;
  }

  for (int i = 0; i <= n; i++)
    valueMap[0][i] = 0;

  for (int i = 0; i <= W; i++)
    valueMap[i][0] = 0;

  for (int i = 1; i <= n; i++)
    for (int w = 1; w <= W; w++)
    {
      valueMap[w][i] = valueMap[w][i - 1];
      if (ws[i] <= w)
      {
        int val = valueMap[w - ws[i]][i - 1] + ws[i];
        if (valueMap[w][i] < val)
          valueMap[w][i] = val;
      }
    }
  return valueMap[W][n];
}

int optimal_weight(int W, const vector<int> &ws)
{
  // write your code here
  auto n{ws.size()};
  unordered_map<Position, int, hash_pair> valueMap;
  for (int i = 0; i <= n; i++)
    valueMap[{0, i}] = 0;

  for (int i = 0; i <= W; i++)
    valueMap[{i, 0}] = 0;

  for (int i = 1; i <= n; i++)
    for (int w = 1; w <= W; w++)
    {
      valueMap[{w, i}] = valueMap[{w, i - 1}];
      if (ws[i] <= w)
      {
        int val = valueMap[{w - ws[i], i - 1}] + ws[i];
        if (valueMap[{w, i}] < val)
          valueMap[{w, i}] = val;
      }
    }
  return valueMap[{W, n}];
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n + 1);
  w[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight2(W, w) << '\n';
}
