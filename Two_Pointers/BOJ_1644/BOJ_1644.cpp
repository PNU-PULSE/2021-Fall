#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool arr[4000001];
vector <int> eratos;


int main() {

	int N;	cin >> N;

	//arr[0] = arr[1] = 1;

	for (int i = 2; i <= sqrt(N); i++) {
		for (int j = i *
			i; j <= N; j += i) {
			if (arr[j] == 0) {
				arr[j] = 1;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (arr[i] == 0)
			eratos.push_back(i);
	}

	eratos.push_back(0);

	//vector<int>::iterator start = eratos.begin();
	//vector<int>::iterator end = eratos.begin();
	int sum = 0;
	int count = 0;
	int start = 0, end = 0;


	while (start <= end  && eratos[end] <= N) {	
		if (sum < N) {
			sum += eratos[end];
			if (end < eratos.size() - 2)
				end = end + 1;
		}
		else if (sum >= N) {
			sum -= eratos[start];
			start = start + 1;
		}
		if (sum == N) {
			count++;
		}
	}
	
	cout << count;

	return 0;
}
