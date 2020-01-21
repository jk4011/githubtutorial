#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//return a vector which has same value with input.txt
vector<int> getInput();

//make output.txt & measure the time
void MergeSort(const vector<int>& arr);
void MergeSort(vector<int>& arr, int p, int r);
void Merge(vector<int>& arr, int p, int mid, int r);

int main() {
	vector<int> arr = getInput();
	MergeSort(arr);
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

void MergeSort(const vector<int>& arr) {
	int n = arr.size();
	vector<int> output(arr);
	MergeSort(output, 0, n-1);
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
