#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // 지우세요~
#include <time.h>  // time measurement
#include <cstdlib> // for random value
using namespace std;

const int NumArr[6] = {100,1000,10000,100000,1000000,10000000};

void makeInput();
vector<int> getInput();
void makeAnswer(); //지울거
bool isEqual(ifstream& ans, ifstream& out);
void MergeSort(vector<int> arr, ofstream& out);
void QuickSort(vector<int> arr, ofstream& out);
void HeapSort(vector<int> arr, ofstream& out);

int main() {
	for (int i=3; i<=3; i++) {
		int n = NumArr[i];
		makeInput
	}
	
	//6가지 input의 크기
	for (int i=3; i<=3; i++) {
		int n = NumArr[i];
//		cout << "Size of input: " << n << endl;
		//input.txt 생성 
		ofstream out("Input.txt");
		for (int j=0; j<n; j++)
			out << rand()*10000+rand() << ' ';//
		out.close();
	
		//input.txt -> vector<int> arr
		ifstream in("Input.txt");
		vector<int> arr;
		while (!in.eof()) {
			int x;
			in >> x;
			arr.push_back(x);
		}
		in.close();
		
		//Answer.txt 생성 
//		ofstream out3("Answer.txt");
//		int N = arr.size();
//		sort(arr.begin(), arr.end());
//		for (int i=0; i<N; i++)
//			out3 << arr[i] << ' ';
//		out3.close();
		
		ifstream inAns("Answer.txt");
		ofstream out("Output.txt");
		int N = arr.size();
		for (int i=0; i<N; i++)
			cout << arr[i] << ' ';
		//시간
		MergeSort(arr, out2);
		if (!isEqual(out2, ans))
			cout << "Error - MergeSort" << endl;
		QuickSort(arr, out2);
		if (!isEqual(out2, ans))
			cout << "Error - QuickSort" << endl;
		HeapSort(arr, out2);
		if (!isEqual(out2, ans))
			cout << "Error - HeapSort" << endl;
		out2.close();
		
		
		//Answer.txt 와 Output.txt가 맞는지 확인 
//		ifstream ans("Answer.txt");
//		ifstream result("Output.txt");
//		bool isCorrect = 1;
//		while (!ans.eof()) {
//			int a, r;
//			ans >> a;
//			result >> r;
//			if (r!=a)
//				cout << "WRONG!!!" << endl;
//		}
//		ans.close();
//		result.close();
	}
	
	return 0;
}





//	for (int i=0; i<arr.size(); i++)
//		cout << arr[i] << endl;






