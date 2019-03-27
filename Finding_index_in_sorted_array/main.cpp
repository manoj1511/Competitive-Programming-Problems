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

int search(const vector<int> arr, const int num)
{
	if(arr.size() == 0)
	{
		cout << "No elements present in array" << endl;
		return 1;
	}
	
	int begin = 0;
	int end = arr.size() - 1;
	
	int mid;

	while(begin <= end)
	{
	 	mid = (begin+end)/2;	
//		cout <<"\n"<< mid<<"\n";
	
		if(arr[mid] == num)
		{
			return mid;
		}
		else if(arr[mid] < num)
		{
			begin = mid+1;
		}
		else
		{
			end = mid-1;
		}
	}	

	return (-1);
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
		int n, num;
		cout << "number of inputs in your array : ";
		get(&n);
	
	
		cout << "enter " << n << " elements of the array seperated by a space : ";

		vector<int> my_array(n,0);
		int temp;
		for (auto &it : my_array)
		{	
			get(&temp);
			it = temp;
//			cout << it << " ";
		}
		
		cout << "number to find in your array : ";
		get(&num);
	
		int pos = search(my_array, num);
		if(pos == -1)
		{
			cout << "did not find the number in the array" << endl;
		}
		cout << "\n" << pos << endl;
		my_array.clear();
	}
	return 0;
}

