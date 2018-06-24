/*
 * main.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: manoj1511
 */
#include<iostream>
#include<fstream>

using namespace std;

int A[100];
int n;

void add(int start,int end, int num)
{
	for (int i = start;i<=end;i++)
	{
		A[i]+=num;
	}

}

int main()
{
	ifstream in("data.in");

	int input=0;
	in>>n;
	for (int i=1;i<=n;i++)
	{
		in>>input;
		A[i] = input;
	}
	add(1,4,3);
	add(2,3,10);

	cout<<A[1]<<" "<<A[2]<<" "<<A[3]<<" "<<A[4]<<" "<<A[5]<<" "<<A[6]<<" "<<A[7];
	return 0;
}



