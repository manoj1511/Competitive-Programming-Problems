#include "FindIndex.h"

using namespace std;

FindIndex::FindIndex(int n, int num, vector<int> arr)
{	
	this -> n =  n;
	this -> num = num;
	this -> arr = arr;

}

void FindIndex::get_output()
{
	for(auto &i : output)
		cout << i << " ";
	cout << endl;
}

void FindIndex::check_front_repititions(int i, int begin, int end)
{
	for(int indx = i; indx <= end; indx++)					// check in front for any repitions
	{
		if(arr[indx] == arr[i-1])
		{
			output.push_back(indx);
		}
		else break;
	}
}

void FindIndex::check_back_repititions(int i, int begin, int end)
{
	for(int indx = i; indx >= begin; indx--)					// check in front for any repitions
	{
		if(arr[indx] == arr[i+1])
		{
			output.push_back(indx);
		}
		else break;
	}
}

void FindIndex::search(int begin, int end, int size)				// binary search algorithm
{
	int mid = (begin + end)/2;						// find the middle of array
	while(begin <= end)							// end loop when begin and end are same also begin goes before end
	{
	 	if(arr[mid+1] == num) mid = mid + 1;				// calculate the new mid value for every iteration
		else mid = (begin + end)/2;					// removed a small glitch did not find element when num is in mid + 1
		if(arr[mid] == num)						// if my middle number is the number being searched
		{
			output.push_back(mid);					// add the index to the output
			check_front_repititions(mid+1, begin, end);		// check in front for any repitions
			check_back_repititions(mid-1, begin, end);		// check in back for any repitions
		
			if(output.size()!=arr.size())
			{
				for(int i = 0; i < output.size(); i++)
				{
					if(output[i] == size)
					{
						check_front_repititions(0, 0, arr.size()-1);
						break;
					}
				}
			}
			return;
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


}

void FindIndex::solve_using_algorithm_1()
{

	int begin = 0;								// initialize begin and end
	int end = n - 1;
	int size = end;
	
	for (int i = 0; i < arr.size(); i++)					// iterate through the array till change has occured
	{
		if(arr[i]==num)							// if i encounter the number
		{
			output.push_back(i);
			check_front_repititions(i+1, begin, end);

			for(int i = 0; i < output.size(); i++)
			{
				if(output[i] == 0)
				{
					check_back_repititions(arr.size(), 1, arr.size());
					break;
				}
			}
			return;
		}
		if(arr[i] > arr[i+1])						// if i find the change point change begin and break out of loop
		{
			begin = i+1;
			break; 
		}
	}
	search(begin, end, size);
}

