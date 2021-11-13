#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int weight[101];
int value[101];
int valuelist[101];

int numberOfProduct, maxWeight;

int main() {
    
	cin >> numberOfProduct >> maxWeight;
	for (int i = 1; i <= numberOfProduct; i++) {
		cin >> weight[i] >> value[i];
	}
    
	for (int i = 1; i <= numberOfProduct; i++) {
		for (int j = 1; j <= maxWeight; j++) {
			if (weight[i] <= j) { 
				valuelist[j] = max(valuelist[j], valuelist[j - weight[i]] + value[i]);
			}
		}
	}

	cout << valuelist[maxWeight];

	return 0;
}