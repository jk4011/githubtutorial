#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // 지우세요~
#include <time.h>  // time measurement
#include <cstdlib> // for random value
using namespace std;

//size of input
int NumArr[100] = {10000,};

//make random input, which have size of n
void makeInput(int n);

//return a vector which has same value with input.txt
vector<int> getInput();

//지울거
void makeAnswer(const vector<int>& arr);

//make output.txt & measure the time
void MergeSort(const vector<int>& arr);
void MergeSort(vector<int>& arr, int p, int r);
void Merge(vector<int>& arr, int p, int mid, int r);
void QuickSort(const vector<int>& arr);
void QuickSort(vector<int>& arr, int p, int r);
void HeapSort(const vector<int>& arr);
void HeapSort(vector<int>& arr, int n);
void MaxHeapify(vector<int>& arr, int n, int root);
void BuildMaxHeap(vector<int>& arr, int n);
//지울거
void checkEqual();

int main() {
//	for (int i=1; i<100; i++)
//		NumArr[i] = NumArr[i-1]*2;
//	for (int i=0; i<15; i++) {
//		int n = NumArr[i];
//		makeInput(n);
		int n = 100000;
		vector<int> arr = getInput();
//		cout << "Size of input: " << arr.size() << endl;
 		makeAnswer(arr);
		checkEqual(); //
//	}
}

void makeInput(int n) {
	ofstream out("Input.txt");
	for (int j=0; j<n; j++)
		out << rand()*10000+rand() << ' ';
	out.close();
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

void makeAnswer(const vector<int>& arr) {
	ofstream out("Answer.txt");
	int N = arr.size();
	vector<int> copy(arr);
	sort(copy.begin(), copy.end());
	for (int i=0; i<N; i++)
		out << copy[i] << ' ';
	out.close();
}

void checkEqual() {
	ifstream ans("Answer.txt");
	ifstream output("Output.txt");
	while(!ans.eof()) {
		int a, o;
		ans >> a;
		output >> o;
		if (a!=o)
			cout << "Error" << endl;
	}
}

void MergeSort(const vector<int>& arr) {
	int n = arr.size();
	vector<int> output(arr);
	clock_t start, end;
	start = clock();
	MergeSort(output, 0, n-1);
	end = clock();
	cout << (double)(end-start) << endl;//<< "Time cost of MergeSort: " 
	
	ofstream out("Output.txt");
	for (int i=0; i<n; i++)
		out << output[i] << ' ';
	out.close();
}
void MergeSort(vector<int>& arr, int p, int r) {
	if(p >= r)
		return;
	int mid = (p+r)/2;
	MergeSort(arr, p, mid);
	MergeSort(arr, mid+1, r);
	Merge(arr, p, mid, r);
}
void Merge(vector<int>& arr, int p, int mid, int r) {
	int *tmp = new int[r-p+1];
	int i=p, j=mid+1, k=0;
	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i<=mid)
		tmp[k++] = arr[i++];
	while (j<=r)
		tmp[k++] = arr[j++];
	for (int i=p; i<=r; i++)
		arr[i] = tmp[i-p];
	delete[] tmp;
}

void QuickSort(const vector<int>& arr) {
	int n = arr.size();
	vector<int> output(arr);
	clock_t start, end;
	start = clock();
	QuickSort(output, 0, n-1);
	end = clock();
	cout  << (double)(end-start) << endl;//<< "Time cost of QuickSort: "
	
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

void HeapSort(const vector<int>& arr) {
	int n = arr.size();
	vector<int> output(arr);
	clock_t start, end;
	start = clock();
	HeapSort(output, n);
	end = clock();
	cout << (double)(end-start) << endl;//<< "Time cost of HeapSort: " 
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

