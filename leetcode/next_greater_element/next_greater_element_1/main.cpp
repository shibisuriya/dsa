#include <bits/stdc++.h>

using namespace std;

vector<int> parse_input() {
      int val = 0;
      vector<int> input;
      while (cin >> val) {
            input.push_back(val);
      }
      return input;
}

class Solution {
     public:
      vector<int> nextGreaterElement(vector<int>& nums) {
            stack<int> st;
            vector<int> indices(nums.size());
            for (int i = 0; i < nums.size(); i++) {
                  while (!st.empty() && nums[st.top()] < nums[i]) {
                        indices[st.top()] = i;
                        st.pop();
                  }
                  st.push(i);
            }
            while (!st.empty()) {
                  indices[st.top()] = -1;
                  st.pop();
            }

            vector<int> nge;
            for (int i : indices) {
                  nge.push_back(i == -1 ? -1 : nums[i]);
            }
            return nge;
      }
};

int main() {
      Solution sol;
      vector<int> input = parse_input();
      vector<int> answer = sol.nextGreaterElement(input);
      cout << "Answer -> ";
      for (int& a : answer) {
            cout << a << " ";
      }
      cout << endl;
      return 0;
}
