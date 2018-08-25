#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int main() {
	string s, t;
	while (cin >> s >> t) {
		int s_size = s.size();
		int t_size = t.size();
		int ans = 0;

		for (int i = 0; i < s.size(); i++) {//s‚ð‚¸‚ç‚µ‚Ä‚¢‚­
			vector<int>a0(t.size());
			for (int j = 0; j < t.size(); j++) {
				if (j < t.size() && j + i < s.size() && t[j] == s[j + i]) {
					a0[j]++;
				}
				else if (j < t.size() && j + i < s.size() && t[j] != s[j + i]) {
					continue;
				}
			}
			int nagasa = 0;
			int x = 0;
			for (int i = 0; i < t.size(); i++) {
				int nagasa2 = 0;
				x = i;
				while (x < a0.size() && a0[x] == 1) {
					x++;
					nagasa2++;
				}
				nagasa = max(nagasa, nagasa2);
			}
			ans = max(ans, nagasa);
		}

		for (int i = 0; i < t.size(); i++) {//t‚ð‚¸‚ç‚µ‚Ä‚¢‚­
			vector<int>a0(s.size());

			for (int j = 0; j < s.size(); j++) {
				if (j < s.size() && j + i < t.size() && s[j] == t[j + i]) {
					a0[j]++;
				}
				else if (j < s.size() && j + i < t.size() && s[j] != t[j + i]) {
					continue;
				}
			}
			int nagasa = 0;
			int x = 0;
			for (int i = 0; i < t.size(); i++) {
				int nagasa2 = 0;
				x = i;
				while (x < a0.size() && a0[x] == 1) {
					x++;
					nagasa2++;
				}
				nagasa = max(nagasa, nagasa2);
			}
			ans = max(ans, nagasa);
		}
		cout << ans << endl;
	}
}
