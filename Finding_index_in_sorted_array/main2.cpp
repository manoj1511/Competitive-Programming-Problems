#include "FindIndex.h"

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

int main()
{
	int n, num;
	cout << "number of inputs in your array : ";
	get(&n);
	cout << "enter " << n << " elements of the array seperated by a space [omits the numbers after ";
	cout << n << " elements] : ";

	vector<int> my_array(n,0);
	int temp;
	for (auto &it : my_array)					// get the elements of array and store it in array
	{	
		get(&temp);
		it = temp;
	}
	cin.clear();
	cin.ignore(500,'\n');
	cout << "number to find in your array : ";			// get number to find in your array
	get(&num);

	FindIndex obj(n, num, my_array);
	obj.solve_using_algorithm_1();
	obj.get_output();
	obj.solve_using_algorithm_2();
	obj.get_output();
	return 0;
}
