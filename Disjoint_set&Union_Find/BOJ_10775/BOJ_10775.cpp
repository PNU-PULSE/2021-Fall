#include <iostream>

using namespace std;

int parent[100001];

void do_union(int, int);
int do_find(int);

void do_union(int a, int b) {
	a = do_find(a);
	b = do_find(b);

	parent[a] = b;
}

int do_find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = do_find(parent[a]);
	}
}
	


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int G, P;
	cin >> G >> P;

	int res = 0;
	for (int i = 1; i <= G; ++i) {
		parent[i] = i;
	}

	int g_i;
	for (int i = 1; i <= P; ++i) {
		cin >> g_i;

		int docking_gate = do_find(g_i);
		if (docking_gate) {
			do_union(docking_gate, docking_gate - 1);
			++res;
		}
		else {
			break;
		}
	}

	cout << res;

	return 0;
}