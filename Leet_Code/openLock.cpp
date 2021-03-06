#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:

    string plusone(string str,int i)
    {
        if(str[i]=='9')
        {
            str[i]='0';
        }
        else{
            str[i]=str[i]+1;
        } 
        return str;
    }
    string downone(string str,int i)
    {
        if(str[i]=='0')
        {
            str[i]='9';
        }
        else{
            str[i]=str[i]-1;
        }
        return  str;
    }


    int openLock(vector<string>& deadends, string target) {
       unordered_set<string> deadset(deadends.begin(), deadends.end());
       queue<string>q;
       q.push("0000");
       unordered_set<string>visited;
       visited.insert("0000");
       int step=0;
       while(!q.empty())
       {
           int size=q.size();
           for(int i=0;i<size;i++)
           {
               string str=q.front();
               q.pop();
               if(deadset.find(str)!=deadset.end())
               {
                   continue;
               }
               if(str == target){
                    return step;
                }
               for(int i=0;i<4;i++)
               {
                   string up=plusone(str,i);
                   if(!visited.count(up))
                   {
                       q.push(up);
                       visited.insert(up);
                   }
                   string down=downone(str,i);
                   if(!visited.count(down))
                   {
                       q.push(down);
                       visited.insert(down);
                   }
               }
           }
           step++;
       }
        return -1;
    }
};

int main()
{
    vector<string> deadends{"0201","0101","0102","1212","2002"};
    string target = "0202";
    Solution sol;
    int ans = sol.openLock(deadends, target);
    cout << ans << endl;

    system("pause");
    return 0;
}