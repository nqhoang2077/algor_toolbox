#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using std::max;
using std::min;
using std::string;
using std::vector;

using namespace std;

template <typename T>
void print_vector(const vector<T> &v)
{
  for_each(v.begin(), v.end(), [](T x)
           { cout << x << "\t"; });
  cout << endl;
}

long long int eval(long long int a, long long int b, char op)
{
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  }
  else
  {
    assert(0);
  }
}

void minMax(vector<vector<long long int>> &Min, vector<vector<long long int>> &Max, const vector<char> &ops, const int &i, const int &j)
{
  long long int _min = LLONG_MAX;
  long long int _max = LLONG_MIN;

  for (int k = i; k < j; k++)
  {
    long long int a = eval(Max[i][k], Max[k + 1][j], ops[k]);
    long long int b = eval(Max[i][k], Min[k + 1][j], ops[k]);
    long long int c = eval(Min[i][k], Max[k + 1][j], ops[k]);
    long long int d = eval(Min[i][k], Min[k + 1][j], ops[k]);
    vector<long long int> compare{a, b, c, d};
    _min = min(_min, *min_element(compare.begin(), compare.end()));
    _max = max(_max, *max_element(compare.begin(), compare.end()));
  }
  Min[i][j] = _min;
  Max[i][j] = _max;
}

long long int get_maximum_value(const string &exp)
{
  // write your code here
  if (exp.length()==1)
    return exp[0] - '0';
  auto n{exp.size() / 2};
  auto N = n + 1;
  vector<long long int> digits(N);
  vector<char> ops(N);
  for (unsigned int i = 0; i < n; i++)
  {
    digits[i] = exp[2 * i] - '0';
    digits[i + 1] = exp[2 * i + 2] - '0';
    ops[i] = exp[2 * i + 1];
  }
  // digits.insert(digits.begin(), 0);
  // ops.insert(ops.begin(), '+');

  // print_vector(digits);
  // print_vector(ops);

  vector<vector<long long int>> Min(N);
  vector<vector<long long int>> Max(N);

  for (int i = 0; i < N; i++)
  {
    Min[i] = vector<long long int>(N);
    Max[i] = vector<long long int>(N);
    Min[i][i] = Max[i][i] = digits[i];
  }
  // cout << "leu leu" << endl;
  for (int s = 1; s < N; s++)
  {
    for (int i = 0; i < N - s; ++i)
    {
      int j = i + s;
      minMax(Min, Max, ops, i, j);
    }
  }

  // DEBUG

  // cout << "Max: " << endl;
  // for (int i = 0; i < N; i++)
  // {
  //   print_vector(Max[i]);
  // }
  // cout << "Min: " << endl;

  // for (int i = 0; i < N; i++)
  // {
  //   print_vector(Min[i]);
  // }
  return Max[0][N - 1];
}

void test_case(){
  vector<string> ins {"0","0+0","9","9*9","1+5*6-3","9*5*6-3","1+1+1+1+1+1+1+1+1+1+1+1+1+1","9*9*9*9*9*9*9*9*9*9*9*9*9*9","9*9*9*9*9*9*9*9*9*9*9*9*9*9*9","6*3-2-5+5+0+0+8-6*8+0-4-2+3+2","1+0+3*5+7-3*6*4-0-7+8-4*4*1*6","0*8*3+3-7*2*1+6*3*8*0-8+1-2*7"};
  vector<long long int> ans{0,0,9,81,33,267,14,22876792454961,205891132094649,1650,149040,181125};
  for (int i=0; i<ins.size(); i++){
    cout << ins[i] << " = ";
    auto guess = get_maximum_value(ins[i]);
    cout << ans[i] << " == " << guess << " ? " << (ans[i] == guess) << endl; 
  }
}

#define DEBUG true
int main()
{
  if (DEBUG) {

  // std::cout << get_maximum_value("3") << '\n';
    test_case();
    return 1;
  }

  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
