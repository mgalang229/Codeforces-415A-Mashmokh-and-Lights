#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	// simply check the button that is greater than or equal to the current (index + 1)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + 1) >= a[j]) {
				cout << a[j] << " ";
				break;
			}
		}
	}
	cout << '\n';
	return 0;
}
