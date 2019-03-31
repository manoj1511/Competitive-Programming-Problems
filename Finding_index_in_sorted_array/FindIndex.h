#ifndef FindIndex_h
#define FindIndex_h

#include<iostream>
#include<vector>

using namespace std;

class FindIndex
{

private:
	int n, num;
	vector<int> arr, output;
	void check_back_repititions(int, int, int);
	void check_front_repititions(int, int, int);
	void search(int, int, int); 
	int findchangepoint(int ,int );			// fuction to find the change point

public:
	FindIndex(int, int, vector<int>);
	void get_output();
	void solve_using_algorithm_1();
	void solve_using_algorithm_2();
};
#endif
