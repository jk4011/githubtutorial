#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//return a vector which has same value with input.txt
vector<int> getInput();

void QuickSort(const vector<int>& arr);
void QuickSort(vector<int>& arr, int p, int r);

int main() {
	vector<int> arr = getInput();
	QuickSort(arr);
}

vector<int> getInput() {
	ifstream in("Input.txt");
	vector<int> arr;
	
	int x;
	while(in >> x) {
//		in >> x;
//		if (in.eof())
//			break;
		arr.push_back(x);
	}
	return arr;
}


void QuickSort(const vector<int>& arr) {
	int n = arr.size();
	vector<int> output(arr);
	QuickSort(output, 0, n-1);
	
	ofstream out("Output.txt");
	for (int i=0; i<n; i++)
		out << output[i] << ' ';
	out.close();
}
void QuickSort(vector<int>& arr, int p, int r) {
	if (p >= r)
		return;
	int pivot = arr[(p+r)/2];
	int left = p;
	int right = r;
	
	while (left<=right) {
		while(arr[left] < pivot)
			left++;
		while(arr[right] > pivot)
			right--;
		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	QuickSort(arr, p, right);
	QuickSort(arr, left, r);
}
