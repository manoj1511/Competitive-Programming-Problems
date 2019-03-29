#include <iostream>
#include <vector>

using namespace std;

void get(int *n)								// helper function to read numbers
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

vector<int> search(const vector<int> arr, int begin, int end, const int num, int size)	// binary search algorithm
{

	vector<int> output;							// create a vector to store output
	
	int mid = (begin + end)/2;						// find the middle of array

	while(begin <= end)							// end loop when begin and end are same also begin goes before end
	{
	 	if(arr[mid+1] == num) mid = (begin+end)/2;			// calculate the new mid value for every iteration
		else mid = mid + 1;						// removed a small glitch did not find element when num is in mid + 1				
	
		if(arr[mid] == num)						// if my middle number is the number being searched
		{
			output.push_back(mid);					// add the index to the output
			for(int indx = mid+1; indx <= end; indx++)		// check in front for any repitions
			{
				if(arr[mid] == arr[indx])
				{
					output.push_back(indx);
				}
				else break;
			}
			for(int indx = mid-1; indx >= 0; indx--)		// check in back for any repitions
			{
				if(arr[mid] == arr[indx])
				{
					output.push_back(indx);
				}
				else break;
			}
			for(int i = 0; i < output.size(); i++)
			{
				size_t flag = 0;
				if(output[i] == size)
				{
					flag = 1;
					for(int indx2 = 0; indx2 < arr.size(); indx2++)
					{
						if(arr[indx2] == num)
						{
							output.push_back(indx2);
						}
						else break;
					}
					break;
				}
				if(output[i] == 0 && flag == 0)
				{
					for(int indx2 = arr.size(); indx2 > 0; indx2--)
					{
						if(arr[indx2] == num)
						{
							output.push_back(indx2);
						}
						else break;
					}
					break;
				}
			}

			return output;
		}
		else if(arr[mid] < num)						// if number to be searched is in second half change my begin to mid + 1
		{
			begin = mid+1;
		}
		else								// if number to be searched is in first half change my end to mid - 1
		{
			end = mid-1;
		}
	}	

	return output;

}



vector<int> algorithm1(const vector<int> arr, const int num)			// algorithm 1. check lineraly to see where change has occured
{
	vector<int> output;							// declare output. just in case the number to be searched is even befor change

	if(arr.size() == 0)
	{
		cout << "No elements present in array" << endl;			// check array is valid
		return output;
	}
	
	int begin = 0;								// initialize begin and end
	int end = arr.size() - 1;
	int size = end;

	for (int i = 0; i < arr.size(); i++)					// iterate through the array till change has occured
	{
		size_t flag = 0;						// I'm using this flag to see if the the number if is in index 1 
										// if yes. i have to check at the end.
		if(arr[i]==num)							// if i encounter the number
		{
		 	for(int indx = i; indx < arr.size(); indx++)		// iterate to front for repitions
			{
				if(indx == arr.size()-1) flag = 1;

				if(arr[i] == arr[indx])
				{
					output.push_back(indx);			// the the indices to output
				}
				else break;
			}
			
			if(i == 0 && !flag)					// check in other side only if flag is set
			{
				if(output[0] == 0)
				{
					for(int indx = arr.size() - 1; indx > 0; indx--)	// iterate from backwards
					{
						if(arr[indx] == num)
						{
							output.push_back(indx);
						}
						else break;
					}

				}
			}

			return output;						// return the output
		}
		if(arr[i] > arr[i+1])						// if i find the change point change begin and break out of loop
		{
			begin = i;
			break; 
		}
	}

	output = search(arr, begin, end, num, size);				// call the search algorithm on second half


	return output;								// return the result
}

int findchangepoint(vector<int> arr, int begin, int end)			// fuction to find the change point
{

	int mid = (begin + end) / 2;						// calculate middle value
	int changepoint;							

	if(arr[begin] < arr[end]) return -1;					// algorithm fully sorted

	if(arr[mid] > arr[mid+1]) return mid;					// if the first mid itself is a change point

	if(arr[begin] > arr[mid])						// if change point is in first half
		changepoint = findchangepoint(arr, begin, mid);			// recur on the first half

	if(arr[mid] > arr[end])							// if change point is in second half
		changepoint = findchangepoint(arr, mid, end);			// recur on the second half

	return changepoint;

}

vector<int> algorithm2(vector<int> arr, const int num)				// algorithm 2 uses binary search to find the position of change point
{

	vector<int> output;						
	int changepoint = findchangepoint(arr, 0, arr.size()-1);		// find changepoint

	int begin = 0;								// initialize begin and end
	int end = arr.size() - 1;
	int size = end;								// actual size of full array
	if(changepoint == -1)							// array is sorted
		output  = search(arr, begin, end, num, size);				// search in entire array

	
	if(num > arr[end])							// if point is in first half
		output = search(arr, begin, changepoint, num, size);			// search the first half
	
	else
		output = search(arr, changepoint + 1, end, num, size);		// else search in second half

	return output;								// return the final output to main
}


int main(int argc, char* argv[])
{
	if(argc != 2)								// check number of arguments
	{	
		cout << "Please enter number of test cases" << endl;
		cout << "USAGE : ./executable <no. of test case>" << endl;
		return 1;
	}
	
	int tc = atoi(argv[1]);							// number of test cases
	for (int i = 0; i < tc ; i++)						// iterate through test cases
	{
		int n, num;							// initialize variables
		cout << "number of inputs in your array : ";
		get(&n);							// get size of array
	

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
		vector<int> out;						// declare the output vector
		out = algorithm1(my_array, num);				// run algorithm 1
		if(out.size() == 0)
		{
			cout << "did not find the number in the array" << endl; // algorithm did not find thr number
			return 1;
		}

		cout << "The number is found at index ";			

		for(auto &indx : out)
			cout << "[" << indx << "]" << " ";			// print the values
		cout << "using algorithm 1 " << endl;

		out.clear();

		out = algorithm2(my_array, num);				// run algorithm 2

		if(out.size() == 0)
		{
			cout << "did not find the number in the array" << endl;
			return 1;
		}

		cout << "The number is found at index ";			// print values
							
		for(auto &indx : out)
			cout << "[" << indx << "]" << " ";
		cout << "using algorithm 2 " << endl;
		
		out.clear();							
		my_array.clear();
	}
	return 0;
}

