#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define bit(n, i) ((n>>i)&1)
const int mod = 1e9+7;
typedef long long ll;

int main() {
	int t;cin >> t;
	while(t--) {
		int a, b, c;cin >> a >> b >> c;
		pair<int,int>tg[a];
		int dm = 0;
		for(int i = 0; i < a; i++) {
			cin >> tg[i].first >> tg[i].second;
			if(tg[i].first == b && tg[i].second == c) {
				++dm;
			}
		}
		if(dm) {
			cout << "0 0\n";
		} else {
			int dmm = 1e9;
			int cmm = 1e9;
			for(int i = 0; i < a; i++) {
				if(tg[i].first < b) {
					int x = 24-b+tg[i].first;
					cout << x << endl;
					int y;
					if(tg[i].second < c) {
						--x;
						y = 60-(c-tg[i].second);
					} else {
						y = tg[i].second-c;
					}
					if(dmm != 1e9) {
						if(dmm == x) {
							cmm = min(cmm, y);
						} else if(dmm > x){
							dmm = x;
							cmm = y;
						}
					} else {
						dmm = x;
						cmm = y;
					}
				} else if(tg[i].first > b){
					int x = tg[i].first-b;
					int y;
					if(tg[i].second < c) {
						--x;
						y = 60-(c-tg[i].second);
					} else {
						y = tg[i].second-c;
					}
					if(dmm != 1e9) {
						if(dmm == x) {
							cmm = min(cmm, y);
						} else if(dmm > x){
							dmm = x;
							cmm = y;
						}
					} else {
						dmm = x;
						cmm = y;
					}
				} else if(tg[i].first == b){
					if(tg[i].second > c) {
						dmm = 0;
						cmm = tg[i].second - c;
					}else {
						dmm = 23;
						cmm = 60-(c-tg[i].second);
					}
				}
			}
			cout << dmm << " " << cmm << endl;
		}
	}
}
