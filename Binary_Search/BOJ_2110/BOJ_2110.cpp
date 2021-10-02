#include <iostream>
#include <algorithm>
using namespace std;

int location[200000];	
int N, C;	

int BinarySearch(int left, int right) {				
	int Max = 0;		

	while (left <= right) {
        int count = 1;
		int mid = (left + right) / 2;
		int available_from_this = location[0];

		for (int i = 0; i < N; i++) {
			if (available_from_this + mid <= location[i]) {
				available_from_this = location[i];
				count++;
			}
		}
		if (count >= C) {		
			left = mid + 1;
			Max = mid;		
		}
		else {
			right = mid - 1;
		}
	}
	return Max;
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
        
	int L, R;
    
	cin >> N >> C;
	
	if (N < 2)		
		return 0;   

	for (int i = 0; i < N; i++) {
		cin >> location[i];
	}

	sort(location, location + N);

	L = 1;
	R = location[N - 1] - location[0];		
	

	cout << BinarySearch(L, R);

	return 0;
}
