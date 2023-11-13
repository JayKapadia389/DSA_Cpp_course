#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> heights = {1, 2, 3, 2, 1};

  int max_area = 0;

  for (int i = 0; i < heights.size(); i++) {
    int current_area = heights[i];

    for (int j = i; j < heights.size(); j++) {
      current_area = max(current_area, heights[j] * (j - i + 1));
    }

    max_area = max(max_area, current_area);
  }

  cout << max_area << endl;

  return 0;
}