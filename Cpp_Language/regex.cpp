#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(int argc, const char** argv)
{
	string email = "abc123@163.com";
	// here one \ for string, one for escape character
	regex r("[a-z0-9]+@[a-z0-9]+\\.[a-z0-9]+");
	cout << regex_match(email, r) << endl;
	return 0;
}