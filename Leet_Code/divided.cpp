#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

class Solution{
public:
	int div(int dividend, int divisor) {
		if(dividend < divisor)
			return 0;
		int res = 1;
		int old_divisor = divisor;

		while(dividend - divisor > divisor) {
			divisor += divisor;
			res += res;
		}
		res += div(dividend-divisor, old_divisor);
		return res;
	}

    int divide(int dividend, int divisor) {
    	int res = 0;
    	int flag = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0));
    	// first process special cases
    	if(divisor == 1) return dividend;
    	if(divisor == INT_MIN) return dividend==INT_MIN?1:0;
    	if(divisor == -1) return dividend==INT_MIN?INT_MAX:-dividend;
    	if(dividend == INT_MIN) {
    		// if dividend is INT_MIN, let it add or substract divisor first to avoid excess limit
    		dividend = (flag) ? (dividend - divisor) : (dividend + divisor);
    		res++;
    	}	
    	dividend = (dividend > 0)?dividend:-dividend;
    	divisor = (divisor > 0)?divisor:-divisor;
    	res += div(dividend, divisor);

    	return flag ? res : -res;
    }
};


int main()
{
	int dividend = 7;
	int divisor = -3;
	Solution sol;
	int ans = sol.divide(dividend, divisor);
	cout << ans << endl;

    return 0;
}
