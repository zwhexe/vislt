#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        if(num < 1 || num > 4000)
            return {};
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string rop[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X",
                            "IX", "V", "IV", "I"};
        string str;
        for(int i = 0; i < 13; i++){
            while(num >= values[i]){
                num -= values[i];
                str += rop[i];
            }
        }

        return str;
    }
};

int main()
{
    int num = 58;
    Solution sol;
    string str = sol.intToRoman(num);
    cout << str << endl;

    return 0;
}