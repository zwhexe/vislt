 #include <iostream>

using namespace std;

int main()
{
	int num = 100;
	while(num > 0)
	{
		if(num%20==1)
		{
			cout << num << endl;
		}
		num--;
	}
	return 0;
}