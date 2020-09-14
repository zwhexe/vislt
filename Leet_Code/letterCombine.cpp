#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> res; //最终返回值
    string tmp; //临时字符串
    int len; // 输入字符串的长度
    string digit; // 输入字符串

    void recursive(int cur) {
        if(cur == len)
            return; //cur代表当前处理的位置，若等于n，直接返回
        string s; //定义临时字符串用于保存当前数字字符对应的可能翻译得的字母字符的集合
        switch(digit[cur]){
            case '2':
                s = "abc"; break;
            case '3':
                s = "def"; break;
            case '4':
                s = "ghi"; break;
            case '5':
                s = "jkl"; break;
            case '6':
                s = "mno"; break;
            case '7':
                s = "pqrs"; break;
            case '8':
                s = "tuv"; break;
            case '9':
                s = "wxyz"; break;
        }
        //得到s以后，对s中的所有字母字符进行递归并在递归之后完成回溯
        for(int i = 0; i < s.size(); i++) {
            tmp.push_back(s[i]); //将其中一个字母字符放如临时字符串中
            if(tmp.size() == len)
                res.push_back(tmp); //若临时字符串长度达标，直接将其放入结果中
            recursive(cur + 1); //进行下一个位置处理
            tmp.pop_back(); //将本次递归加入到临时字符串中的字符删除，完成回溯
        }
    }

    vector<string> letterCombinations(string digits) {
        len = digits.size(); //全局变量赋值，可以避免后续递归过程中的重复参数传递
        digit = digits;
        recursive(0); //开启第一次递归
        return res; // 返回最终的结果
    }
};

int main()
{
    string digits = "23";
    Solution sol;
    vector<string> strs = sol.letterCombinations(digits);
    for(auto a = strs.begin(); a != strs.end(); a++)
        cout << *a << endl;

    return 0;
}
