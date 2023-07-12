#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)s; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 辞書順にトポロジカルソート
// graphがDAGで無ければ空の配列を返す
vector<int> topologicalSort(const vector<vector<int>>& graph) {
	vector<int> indegrees(graph.size());

	for (const auto& v : graph) {
		for (const auto& to : v) {
			++indegrees[to];
		}
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < (int)graph.size(); ++i) {
		if (indegrees[i] == 0) {
			pq.push(i);
		}
	}

	vector<int> result;

	while (!pq.empty()) {
		const int from = pq.top(); pq.pop();

		result.push_back(from);

		for (const auto& to : graph[from]) {
			if (--indegrees[to] == 0) {
				pq.push(to);
			}
		}
	}

	if (result.size() != graph.size()) {
		return{};
	}

	return result;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[A].push_back(B);
  }

  vector<int> ans = topologicalSort(G);
  if (ans.size() == 0) {
    cout << -1 << endl;
  } else {
    for (int e : ans) {
      cout << e + 1 << " ";
    }
    cout << endl;
  }

}