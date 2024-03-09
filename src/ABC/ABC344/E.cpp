#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct Node {
  int value;
  Node* prev;
  Node* next;
};

int main() {
  int N;
  cin >> N;

  vector<Node> nodes(N);
  rep(i, N) {
    cin >> nodes[i].value;
    nodes[i].prev = nullptr;
    nodes[i].next = nullptr;
  }

  rep(i, N - 1) {
    nodes[i].next = &nodes[i + 1];
    nodes[i + 1].prev = &nodes[i];
  }

  int Q;
  cin >> Q;

  rep(_, Q) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;

      Node* node_x = &nodes[x - 1];
      Node* node_y = &nodes[y - 1];

      if (node_x->next) {
        node_x->next->prev = node_y;
      }
      node_y->next = node_x->next;
      node_x->next = node_y;
      node_y->prev = node_x;
      if (node_y->next) {
        node_y->next->prev = node_x;
      }

      swap(node_x->prev, node_y->prev);
      swap(node_x->next, node_y->next);
    } else if (t == 2) {
      int x;
      cin >> x;

      Node* node_x = &nodes[x - 1];

      if (node_x->prev) {
        node_x->prev->next = node_x->next;
      }
      if (node_x->next) {
        node_x->next->prev = node_x->prev;
      }

      if (node_x->prev == nullptr) {
        node_x->next->prev = nullptr;
      }
    }
  }

  Node* head = &nodes[0];
  while (head->prev) {
    head = head->prev;
  }

  for (Node* node = head; node != nullptr; node = node->next) {
    cout << node->value << " ";
  }
}
