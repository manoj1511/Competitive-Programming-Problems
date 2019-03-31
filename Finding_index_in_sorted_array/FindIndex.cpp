#include "FindIndex.h"

using namespace std;

FindIndex::FindIndex(int n, int num, vector<int> arr)
{	
	this -> n =  n;
	this -> num = num;
	this -> arr = arr;

}

FindIndex::~FindIndex()
{
	arr.clear();
	output.clear();
}

void FindIndex::get_output()
{
	cout << "Number is found at Index";
	for(auto &i : output)
		cout << " [ " << i << " ] ";
	cout << endl;
}

void FindIndex::check_front_repititions(int i, int begin, int end)
{
	for(int indx = i; indx <= end; indx++)					// check in front for any repitions
	{
		if(arr[indx] == num)
		{
			output.push_back(indx);
		}
		else break;
	}
}

void FindIndex::check_back_repititions(int i, int begin, int end)
{
	for(int indx = i; indx >= begin; indx--)				// check in front for any repitions
	{
		if(arr[indx] == num)
		{
			output.push_back(indx);
		}
		else break;
	}
}

void FindIndex::search(int begin, int end, int size)				// binary search algorithm
{
	output.clear();
	
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
				int flag = 0;					// flag to do either front or back check

				for(int i = 0; i < output.size(); i++)
				{
					if(output[i] == size && flag == 0)
					{
						flag = 1;
						check_front_repititions(0, 0, arr.size()-1);
						break;
					}
					if(output[i] == 0 && flag == 0)
					{
						flag = 1;
						check_back_repititions(arr.size()-1, 0, arr.size()-1);
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
					check_back_repititions(arr.size()-1, 1, arr.size()-1);
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

int FindIndex::findchangepoint(int begin, int end)				// fuction to find the change point
{

	int mid = (begin + end) / 2;						// calculate middle value
	int changepoint = mid;							

	if(arr[begin] < arr[end]) return -1;					// algorithm fully sorted

	if(arr[mid] > arr[mid+1]) return mid;					// if the first mid itself is a change point

	if(arr[begin] > arr[mid])						// if change point is in first half
		changepoint = findchangepoint(begin, mid);			// recur on the first half

	if(arr[mid] > arr[end])							// if change point is in second half
		changepoint = findchangepoint(mid, end);			// recur on the second half

	return changepoint;

}

void FindIndex::solve_using_algorithm_2()
{
	int changepoint = findchangepoint(0, arr.size()-1);			// find changepoint

	int begin = 0;								// initialize begin and end
	int end = arr.size() - 1;
	int size = end;								// actual size of full array
	if(changepoint == -1)							// array is sorted
		search(begin, end, size);					// search in entire array

	if(num > arr[end])							// if point is in first half
		search(begin, changepoint, size);				// search the first half	
	else
		search(changepoint + 1, end, size);				// else search in second half
}

void FindIndex::algorithm_3(int begin, int end, int size)
{

	int mid = (begin + end)/2;						// find the mid value
	
	if(begin > end)
		return;
	
        if(arr[mid] == num)							// check if mid is the number
            search(mid, mid, size);						// apply search on mid
            
        if(arr[mid] > arr[begin])                                               // if front side is sorted;
        {
                if(num >= arr[begin] && num <= arr[mid])			// and the num is in between them
                        search(begin, mid , size);				// then search the region 
                else                                                		// if the number is not in the sorted region
                	algorithm_3(mid+1, end, size);				// recur on the second half
        }
        else                                                                    // if the back end is sorted
        {
            	if(num >= arr[mid+1] && num <= arr[end])			// and the number is in between them
                	search(mid+1,end,size);					// search the second half
            	else								// if the number is not in this region
                	algorithm_3(begin, mid-1, size);            		// recur on first half
        }
}

void FindIndex::solve_using_algorithm_3()
{
	algorithm_3(0, n-1, n-1);	
}


