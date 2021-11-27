#include <iostream>
using namespace std;

int parent[1000001];


void Union(int a, int b);
int Find(int tmp);


int main() {
	int n, m;
	cin >> n >> m;

	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	for (int i = 0; i < 1000001; i++) {
		parent[i] = i;
	}

	while (m--) {
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 0) {
			Union(a, b);
		}
		else {
			if (Find(a) == Find(b))
				cout << "yes\n";
			else
				cout << "no\n";
		}
	}

	return 0;
}


void Union(int a, int b) {
	int x = Find(a);
	int y = Find(b);

	if (x == y)
		return;
	else
		parent[x] = y;
}

int Find(int tmp) {
	if (tmp == parent[tmp])
		return tmp;
	else {
		parent[tmp] = Find(parent[tmp]);
		return parent[tmp];
	}
}
