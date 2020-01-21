#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//return a vector which has same value with input.txt
vector<int> getInput();

void HeapSort(const vector<int>& arr);
void HeapSort(vector<int>& arr, int n);
void MaxHeapify(vector<int>& arr, int n, int root);
void BuildMaxHeap(vector<int>& arr, int n);

int main() {
	vector<int> arr = getInput();
	HeapSort(arr);
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


void HeapSort(const vector<int>& arr) {
	int n = arr.size();
	vector<int> output(arr);
	HeapSort(output, n);
	ofstream out("Output.txt");
	for (int i=0; i<n; i++)
		out << output[i] << ' ';
	out.close();
}
void HeapSort(vector<int>& arr, int n) {
	BuildMaxHeap(arr, n);
	for (int i=n-1; i>=0; i--) {
		swap(arr[0], arr[i]);
		MaxHeapify(arr, i, 0);
	}
}

void BuildMaxHeap(vector<int>& arr, int n) {
	for (int i=n/2-1; i>=0; i--)
		MaxHeapify(arr, n, i);
}
void MaxHeapify(vector<int>& arr, int n, int root) {
	int left = 2*root + 1;
	int right = 2*root + 2;
	int largest;
	
	if (left<n && arr[left] > arr[root])
		largest = left;
	else largest = root;
	if (right<n && arr[right] > arr[largest])
		largest = right;
	if (largest != root) {
		swap(arr[root], arr[largest]);
		MaxHeapify(arr, n, largest);
	}
}
