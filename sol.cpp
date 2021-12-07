#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int mx = INT_MIN;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	// create an adjacency list to store the indices that each button presses
	vector<int> visited(n, false);
	vector<vector<int>> button(mx + 1);
	for (int i = 0; i < m; i++) {
		for (int j = a[i]; j <= n; j++) {
			if (!visited[j - 1]) {
				button[a[i] - 1].push_back(j);
				visited[j - 1] = true;
			}
		}
	}
	// find the button that pressed the given i-th index (light)
	auto FindButton = [&](int item) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < (int) button[a[i] - 1].size(); j++) {
				if (item == button[a[i] - 1][j]) {
					return a[i];
				}
			}
		}
		return -1;
	};
	// output
	for (int i = 0; i < n; i++) {
		cout << FindButton(i + 1) << " ";
	}
	cout << '\n';
	return 0;
}
