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

vector<int> algorithm1(const vector<int> arr, const int num)
{
	vector<int> output;

	if(arr.size() == 0)
	{
		cout << "No elements present in array" << endl;
		return output;
	}
	
	int begin = 0;	
	int end = arr.size() - 1;

	for (int i = 0; i < arr.size(); i++)
	{
		size_t flag = 0;
		if(arr[i]==num)
		{
		 	for(int indx = i; indx < arr.size(); indx++)
			{
				if(indx == arr.size()-1) flag = 1;

				if(arr[i] == arr[indx])
				{
					output.push_back(indx);
				}
				else break;
			}
			
			if(i == 0 && !flag)
			{
				if(output[0] == 0)
				{
					for(int indx = arr.size() - 1; indx > 0; indx--)
					{
						if(arr[indx] == num)
						{
							output.push_back(indx);
						}
						else break;
					}

				}
			}

			return output;
		}
		if(arr[i] > arr[i+1])
		{
			begin = i;
			break; 
		}
	}
	
	int mid;

	while(begin <= end)
	{
	 	mid = (begin+end)/2;	
//		cout <<"\n"<< mid<<"\n";
	
		if(arr[mid] == num)
		{
			output.push_back(mid);
			for(int indx = mid+1; indx <= end; indx++)
			{
				if(arr[mid] == arr[indx])
				{
					output.push_back(indx);
				}
				else break;
			}
			for(int indx = mid-1; indx >= 0; indx--)
			{
				if(arr[mid] == arr[indx])
				{
					output.push_back(indx);
				}
				else break;
			}
			return output;
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

	return output;
}

int findchangepoint(vector<int> arr, int begin, int end)
{

	if(begin == end) return begin;

	int mid = (begin + end) / 2;
	
	if(arr[begin] > arr[mid])			// if change point is in first half
		findchangepoint(arr, begin, mid);	// recur on the first half

	if(arr[mid] > arr[end])				// if change point is in second half
		findchangepoint(arr, mid, end);		// recur on the second half

	return begin;
}
vector<int> algorithm2(vector<int> arr, const int num)
{

	int changepoint = findchangepoint(arr, 0, arr.size()-1);
	
	cout << changepoint<<endl;

	return arr;

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
	

		cout << "enter " << n << " elements of the array seperated by a space [omits the numbers after ";
		cout << n << " elements] : ";

		vector<int> my_array(n,0);

		int temp;
		for (auto &it : my_array)
		{	
			get(&temp);
			it = temp;
//			cout << it << " ";
		}
		
		cin.clear();
		cin.ignore(500,'\n');
			

		cout << "number to find in your array : ";
		get(&num);
		vector<int> out;
		out = algorithm1(my_array, num);
		if(out.size() == 0)
		{
			cout << "did not find the number in the array" << endl;
			return 1;
		}

		cout << "The number is found at index ";

		for(auto &indx : out)
			cout << "[" << indx << "]" << " ";
		cout << "using algorithm 1 " << endl;

		out.clear();

		out = algorithm2(my_array, num);
	
		my_array.clear();
	}
	return 0;
}

