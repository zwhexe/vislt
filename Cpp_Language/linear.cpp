#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, const char** argv)
{
	vector<int> v;
	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	v.insert(v.begin()+1, 666);
	for(auto i : v)
		cout << i << " ";
	cout << endl;

	v.erase(v.begin()+2);
	for(auto i : v)
		cout << i << " ";
	cout << endl;
	
	return 0;
}