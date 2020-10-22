#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
	vector<int> findSubstring(string s, vector<string>& words) {
        if(s=="" || words.size()==0) return {};
        unordered_map<string, int> hash;
        vector<int> res;
        res.clear();
        // record size of word, words and s
        int num = words.size();
        int step = words[0].length();
        int len = s.length();
        // complete hash with word in words
        for(auto w: words)
            hash[w]++;
        auto tmp = hash;
        string buff = "";
        // loop s to match words
        for(int i = 0; i < len; i++){
            if(len - i + 1 < step * num) 
                break;  // the rest s is not enough match words, so break
            tmp = hash; // this tmp will decrease to record found word in s
            buff = s.substr(i, step);   // pos i's word with step length
            int j = i, count = 0;
            while(tmp[buff] > 0) {
                --tmp[buff];
                count++;
                j += step;
                buff = s.substr(j, step);
            }
            if(count == num) {
                // the pos i's words match words list
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
	string s("barfoothefoobarman");
	vector<string> words {"foo", "bar"};
	Solution sol;
	vector<int> res = sol.findSubstring(s, words);
	for(auto a: res)
		cout << a << endl;

	return 0;
}