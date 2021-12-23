#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

//template<typename T>
//void print_queue(T q) { // NB: pass by value so the print uses a copy
//  while (!q.empty()) {
//    cout << q.top() << " ";
//    q.pop();
//  }
//  cout << '\n';
//}

struct Heap {
  vector<int> v;
  int n; // Size of the heap

  explicit Heap(int i = 0) : n(i) {
    v = vector<int>(n);
  }
};

// Returns the index of
// the left_child_node_idx child node
inline int left_child_node_idx(int i) {
  return 2 * i + 1;
}

// Returns the index of
// the right_child_node_idx child node
inline int right_child_node_idx(int i) {
  return 2 * i + 2;
}

int findKthSmallest(Heap &h, int k) {
  // Create a Priority Queue
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> p;

  // Insert root into the priority queue
  p.push(make_pair(h.v[0], 0));

  for (int i = 0; i < k - 1; ++i) {
    cout << "p.top().first : " << p.top().first << " p.top().second : " << p.top().second << endl;

    int j = p.top().second;
    p.pop();

    int l_c_idx = left_child_node_idx(j), r_c_idx = right_child_node_idx(j);

    if (l_c_idx < h.n)
      p.push(make_pair(h.v[l_c_idx], l_c_idx));

    if (r_c_idx < h.n)
      p.push(make_pair(h.v[r_c_idx], r_c_idx));
  }

  return p.top().first;
}

int main() {

  Heap h(9);
  h.v = vector<int>{21, 77, 44, 29, 74, 66, 87, 99, 10};
  int k = 2;

//  Heap h(7);
//  h.v = vector<int>{10, 50, 45, 75, 60, 65, 40};
//  int k = 2;

  cout << findKthSmallest(h, k);

//  priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> p;
//  auto a = make_pair(100, -1);
//  auto b = make_pair(-100, 2);
//  p.push(a);
//  p.push(b);

//  cout << p.top().first;

}