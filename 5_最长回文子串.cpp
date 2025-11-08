class Solution {
	public:
		string longestPalindrome(string s) {
			int res_len = 1;
			int res_start = 0;
			for (int i = 0; i < s.size(); ++i) {
				//ababa
				int l = i;
				int r = i;

				while (l >= 0 && s[l] == s[r] && r < s.size()) {
					if (r - l + 1 > res_len) {
						res_len = r - l + 1;
						res_start = l;
					}
					l--;
					r++;
				}

				//abba
				l = i;
				r = i + 1;
				while (l >= 0 && s[l] == s[r] && r < s.size()) {
					if (r - l + 1 > res_len) {
						res_len = r - l + 1;
						res_start = l;
					}
					l--;
					r++;
				}
			}
			return s.substr(res_start, res_len);
		}
};