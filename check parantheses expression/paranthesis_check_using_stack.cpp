//============================================================================
// Name        : stack.cpp
// Author      : Manoj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>


using namespace std;
char A[100];
int ptr=1;

void push(char x)
{
	A[ptr] = x;
	ptr++;
}

void pop()
{
	ptr--;
	A[ptr] = '0';
}

int top()
{
	return A[ptr];
}

bool isempty()
{
	if(ptr>1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main() {
	ifstream in("data.in");
	ofstream out("data.out");

	int num;
	char sym;

	in>>num;

	for(int i=0;i<=num-1;i++)
	{
		in>>sym;
		if(sym == '(' )
		{
			push(sym);
		}
		else if(sym == '[')
		{
			push(sym);
		}
		else if(sym == '{')
		{
			push(sym);
		}
		else if(sym == ')')
		{
			if(!isempty() && A[ptr-1] == '(')
			{
				pop();
			}
			else
			{
				out<<"not satisfied";
				break;
			}
		}
		else if(sym == ']')
		{
			if(!isempty() && A[ptr-1] == '[')
			{
				pop();
			}
			else
			{
				out<<"not satisfied";
				break;
			}
		}
		else if(sym == '}')
		{
			if(!isempty() && A[ptr-1] == '{')
			{
				pop();
			}
			else
			{
				out<<"not satisfied";
				break;
			}
		}
		else
		{
			out<<"symbol not satisfied. Use only { [ ( ) ] } in data.in"<<endl;
			break;
		}
	}
	if(isempty())
	{
		out<<"satisfied";
	}

	//cout<<A[0]<<"\t"<<A[1]<<"\t"<<A[2]<<"\t"<<A[3]<<"\t"<<A[4]<<"\t"<<A[5]<<"\t"<<A[6];

	in.close();
	out.close();


	return 0;
}
