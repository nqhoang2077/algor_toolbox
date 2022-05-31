#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

using namespace std;

using segment = std::pair<int, int>;

int searchPoint(segment& seg, const vector<int>& points, function<bool(int)> condition){
  auto left {0}, right{static_cast<int>(points.size()-1)};
  int mid = (left + right) / 2;
  if (condition(points[mid])){

  } else {
    
  }
}

void findIncludedPoints(segment& seg, const vector<int>& points, vector<int>& cnt){
  // Find start point
  int start = searchPoint(seg, points, [=](int value){return value >= seg.first;});

  // Find end point
  int end = searchPoint(seg, points, [=](int value){return value <= seg.second;});

  // Increase them and everything in between them by 1
  while (start < end)
    cnt[start++]++;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for_each(cnt.begin(), cnt.end(),[](int& x){x=0;});
  //write your code here
  vector<segment> segments(starts.size());
  std::sort(starts.begin(), starts.end());
  for (int i = 0; i < starts.size(); i++)
    segments.push_back({starts[i],ends[i]});

  for (segment& s : segments){
    findIncludedPoints(s, points, cnt);
  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
