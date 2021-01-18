#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        vector<int> a, b, c;
        c.resize(num1.size() + num2.size() - 1);
        for (int i = num1.size() - 1; i >= 0; i--) a.push_back(num1[i] - '0');
        for (int i = num2.size() - 1; i >= 0; i--) b.push_back(num2[i] - '0');
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                c[i + j] += a[i] * b[j];
            }
        }
        int k = 0;
        for (int i = 0; i < c.size(); i++) {
            k += c[i];
            char c = k % 10 + '0';
            res = c + res;
            k /= 10;
        }
        while (k) {
            char c = k % 10 + '0';
            res = c + res;
            k /= 10;
        }
        while (res.size() > 1 && res[0] == '0') res.erase(res.begin());
        return res;
    }
};

int main()
{
    string num1 = "1234";
    string num2 = "567";
    Solution sol;
    string ans = sol.multiply(num1, num2);
    cout << ans << endl;

    return 0;
}