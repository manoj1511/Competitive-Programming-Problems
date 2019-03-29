###Finding index of a number in two sorted arrays combined together

**##PROBLEM STATEMENT:**

User has a sorted array. The array gets divided into 2. The second half of the array is placed at the 
front and the front half is placed at the back. eg. 10 13 15 19 1 4 6 8. Given a number find the index
of the number in array. 

**##ALGORITHM 1:**

1. Iterate till it finds the change point.
	- While iterating if it enounters the number check back and front for repititons.

	Time complexity (T). T = change point

2. after finding changepoint. Do binary search in the half after change point.
	- while doing binary search if it encounter the number check front and back for any repititions

	Time complexity log(N-T). N = Number of elements

Log(T) + T + repitions

**##ALGORITHM 2:**

1. Use a binary search to find the change point.

	Time complexity Log(N)

2. after finding changepoint. Do binary search in the half after change point.
	- while doing binary search if it encounter the number check front and back for any repititions


	Time complexity aproximately aroung log(N) based on T and first and second half

Log(N) + Log(N) + repitions

**##COMPILING :**

Use the make file to compile

```
$make
```

or

```
$g++ main.cpp -o main.exe --std=c++11
```

gives an executable main.exe

**##EXECUTION :**

```
$./main.exe <TC>
```

TC = number of test cases

**##EXAMPLE :**

```
./main.exe 1
number of inputs in your array : 10                 
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 6 7 8 9 1 2 3 4 5
number to find in your array : 2
The number is found at index [6] using algorithm 1 
The number is found at index [6] using algorithm 2 
```

**##TEST CASES:**

#1. Normal case - User inputs an array and searches for a number in it.

```
./main.exe 1
number of inputs in your array : 10                 
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 6 7 8 9 1 2 3 4 5
number to find in your array : 2
The number is found at index [6] using algorithm 1 
The number is found at index [6] using algorithm 2 
```

#2. When there is number is not present in the array.

```
./main.exe 1
number of inputs in your array : 10
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 6 7 8 9 1 2 3 4 5
number to find in your array : 10
did not find the number in the array using algorithm 1
did not find the number in the array using alrithm 2
```

#3. When there are multiple copies of elements to be searched in first sorted array

```
$ ./main.exe 1
number of inputs in your array : 10
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 6 6 6 7 1 2 3 4 5
number to find in your array : 6
The number is found at index [1] [2] [3] using algorithm 1 
The number is found at index [3] [2] [1] using algorithm 2 
```

#4. When there are multiple copies of elements to be searched in second sorted array

```
$ ./main.exe 1
number of inputs in your array : 10
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 6 7 8 9 1 2 2 2 5
number to find in your array : 2
The number is found at index [7] [8] [6] using algorithm 1 
The number is found at index [8] [7] [6] using algorithm 2 
```

#5. The number is divided between the two sorted arrays in the array

```
$ ./main.exe 1
number of inputs in your array : 10
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 5 6 7 8 1 2 3 5 5
number to find in your array : 5
The number is found at index [0] [1] [9] [8] using algorithm 1 
The number is found at index [8] [9] [0] [1] using algorithm 2
```

#6. When all the elements in the array are the same

```
./main.exe 1
number of inputs in your array : 4
enter 4 elements of the array seperated by a space [omits the numbers after 4 elements] : 1 1 1 1
number to find in your array : 1
The number is found at index [0] [1] [2] [3] using algorithm 1 
The number is found at index [3] [2] [1] [0] using algorithm 2 
```
