#include <iostream>
#include <vector>

using namespace std;

void get(int *n)
{
	cin >> *n;
	while(cin.fail())
	{
		cout << "Reenter a number: ";
		cin.clear();
		cin.ignore(500,'\n');
		cin >> *n;
	}
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout << "Please enter number of test cases" << endl;
		cout << "USAGE : ./executable <no. of test case>" << endl;
		return 1;
	}
	
	int tc = atoi(argv[1]);
	for (int i = 0; i < tc ; i++)
	{
		int n;
		cout << "number of inputs in your array: ";
		get(&n);
		cout << "n is : " << n << endl;
		
		vector<int> my_array(n,0);
		int temp;
		for (auto &it : my_array)
		{	
			get(&temp);
			it = temp;
			cout << it << " ";
		}
	}
	return 0;
}

