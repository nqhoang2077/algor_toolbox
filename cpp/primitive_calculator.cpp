#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;
#define INF_POS 9999999999999

vector<int> optimal_sequence(int n)
{
  std::vector<int> sequence;
  std::vector<int> prev{0, 0, 1, 1, 2, 4};
  std::vector<int> C{0, 0, 1, 1, 2, 3};
  C.resize(n + 1);
  prev.resize(n + 1);
  for (int i = 6; i <= n; ++i)
  {
    int Cminus = C[i - 1];
    int C_3 = (i % 3 == 0) ? C[i / 3] : INF_POS;
    int C_2 = (i % 2 == 0) ? C[i / 2] : INF_POS;
    vector<int> testC{Cminus, C_2, C_3};
    auto minElement = std::min_element(testC.begin(), testC.end());
    if (*minElement == Cminus)
    {
      C[i] = Cminus + 1;
      prev[i] = i - 1;
    }
    else if (*minElement == C_2)
    {
      C[i] = C_2 + 1;
      prev[i] = i / 2;
    }
    else
    {
      C[i] = C_3 + 1;
      prev[i] = i / 3;
    }
  }
  while (n >= 1)
  {
    sequence.push_back(n);
    n = prev[n];
  }

  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
