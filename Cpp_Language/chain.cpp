#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, const char** argv)
{
	list<int> a;
	a.push_back(11);
	a.push_back(22);
	a.push_back(33);
	// a.insert(a.begin()+2,666);
	list<int>::iterator it;
	for(it = a.begin(); it!=a.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}