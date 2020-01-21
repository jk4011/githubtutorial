#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> a(N);
	vector<int> b(N);
	vector<int> c(N);
	vector<int> d(N);
	
	for (int i=0; i<N; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	vector<int> ab(N*N);
	vector<int> cd(N*N);
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			ab[i*N+j] = a[i]+b[j];
		}
	}
		
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++) {
			cd[i*N+j] = c[i]+d[j];
		}
	sort(ab.begin(), ab.end(), greater<int>());
	sort(cd.begin(), cd.end());
	
//	for (int i=0; i<N; i++) {
//		for (int j=0; j<N; j++) {
//			cout << ab[i*N+j] << ' ';
//		}
//	}
//	cout << endl;
//	for (int i=0; i<N; i++) {
//		for (int j=0; j<N; j++) {
//			cout << cd[i*N+j] << ' ';
//		}
//	}
	
	int idx1=0, idx2=0, result=0;
	while (idx1<N*N && idx2<N*N) {
//		cout << idx1 << ' ' << idx2 << ' '<< result << endl;
		if (ab[idx1]+cd[idx2]==0) {
			idx1++; idx2++;
			int cnt1=1, cnt2=1;
			while (idx1<N*N && ab[idx1]==ab[idx1-1]) {
				cnt1++;
				idx1++;
			}
			while (idx2<N*N && cd[idx2]==cd[idx2-1]) {
				cnt2++;
				idx2++;
			}
//			cout << cnt1 << ' ' << cnt2 << endl;
			result += cnt1*cnt2;
		}
		else if (ab[idx1]+cd[idx2] > 0) {
			idx1++;
		}
		else if (ab[idx1]+cd[idx2] < 0) {
			idx2++;
		}
	}
	cout << result << endl;
}














