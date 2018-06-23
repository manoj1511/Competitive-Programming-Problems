/*
 * queue.cpp
 *
 *  Created on: Jun 23, 2018
 *      Author: manoj1511
 */

#include<iostream>

using namespace std;

int queue[100];
int fend = 0;
int bend = -1;
void push(int x)
{
	bend++;
	queue[bend] = x;

}

void pop()
{
	queue[fend]=0;
	fend++;
}

int top()
{
	return queue[fend];
}

bool isempty()
{
	if(bend<fend) return true;
	else return false;
}

int main()
{
	push(1);
	push(2);
	if(!isempty()) cout<<top()<<endl;
	pop();
	if(!isempty()) cout<<top()<<endl;
	pop();
	return 0;
}




