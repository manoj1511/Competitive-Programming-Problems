# **Finding index of a number in two sorted arrays combined together**

## **PROBLEM STATEMENT:**

User has a sorted array. The array gets divided into 2. The second half of the array is placed at the 
front and the front half is placed at the back. eg. 10 13 15 19 1 4 6 8. Given a number find the index
of the number in array. 

## **ALGORITHM 1:**

1. Iterate till it finds the change point.
	- While iterating if it enounters the number check back and front for repititons.

	Time complexity (T). T = change point

2. after finding changepoint. Do binary search in the half after change point.
	- while doing binary search if it encounter the number check front and back for any repititions

	Time complexity log(N-T). N = Number of elements

**Log(T) + T + repitions**

## **ALGORITHM 2:**

1. Use a binary search to find the change point.

	Time complexity Log(N)

2. after finding changepoint. Do binary search in the half after change point.
	- while doing binary search if it encounter the number check front and back for any repititions


	Time complexity aproximately aroung log(N) based on T and first and second half

**Log(N) + Log(N) + repitions**

## **ALGORITHM 3**

*Implemeted only in the app with classes ie. main2.cpp*

1. Find the middle index.

2. Check the middle point if its the number. If yes voila!

3. See if the first half is sorted.
	- If yes, see if the number is in the range from begin to mid.
		- if yes, appply the search algorithm in the region.
		- if not, recur on the second half from mid + 1 to end.
4. If the second half is sorted.
	- See if the number is in this range from mid + 1 to end.
		- if yes, apply the search algorithm in this region.
		- if not, recur on the first half from 0 to mid.


## **COMPILING :**

Use the make file to compile

```
$make
```

or

```
$g++ --std=c++11 -o main_with_class.exe main2.cpp FindIndex.cpp -pedantic -Wall -Werror
```

gives an executable main.exe

## **EXECUTION :**

```
$./main_with_class.exe
```


## **EXAMPLE :**

*I'm showing examples and test cases only for class implementation*

The first line of output is using algorithm 1.
The second line of output is using algorithm 2.
The third  line of output is using algorithm 3.

```
$ ./main_with_class.exe 
number of inputs in your array : 10
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 6 7 8 9 1 2 3 4 5
number to find in your array : 7
Number is found at Index [ 2 ] 
Number is found at Index [ 2 ] 
Number is found at Index [ 2 ] 
```

## **TEST CASES:**

### 1. Normal case - User inputs an array and searches for a number in it.

```
$ ./main_with_class.exe 
number of inputs in your array : 10
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 6 7 8 9 1 2 3 4 5
number to find in your array : 7
Number is found at Index [ 2 ] 
Number is found at Index [ 2 ] 
Number is found at Index [ 2 ] 
```

### 2. When there is number is not present in the array.

```
$ ./main_with_class.exe 
number of inputs in your array : 10
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 6 7 8 9 1 2 3 4 5
number to find in your array : 10
Number is found at Index
Number is found at Index
Number is found at Index
```

### 3. When there are multiple copies of elements to be searched in first sorted array

```
$ ./main_with_class.exe 
number of inputs in your array : 10  
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 6 6 6 7 1 2 3 4 5
number to find in your array : 6
Number is found at Index [ 1 ]  [ 2 ]  [ 3 ] 
Number is found at Index [ 3 ]  [ 2 ]  [ 1 ] 
Number is found at Index [ 3 ]  [ 2 ]  [ 1 ] 
```

### 4. When there are multiple copies of elements to be searched in second sorted array

```
$ ./main_with_class.exe 
number of inputs in your array : 10
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 6 7 8 9 1 2 2 2 5
number to find in your array : 2
Number is found at Index [ 8 ]  [ 7 ]  [ 6 ] 
Number is found at Index [ 8 ]  [ 7 ]  [ 6 ] 
Number is found at Index [ 7 ]  [ 8 ]  [ 6 ] 
```

### 5. The number is divided between the two sorted arrays in the array

```
$ ./main_with_class.exe 
number of inputs in your array : 10
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 5 5 6 7 8 1 2 3 5 5
number to find in your array : 5
Number is found at Index [ 0 ]  [ 1 ]  [ 9 ]  [ 8 ] 
Number is found at Index [ 8 ]  [ 9 ]  [ 0 ]  [ 1 ] 
Number is found at Index [ 0 ]  [ 1 ]  [ 9 ]  [ 8 ]
```

### 6. When all the elements in the array are the same

``` 
$ ./main_with_class.exe 
number of inputs in your array : 5
enter 5 elements of the array seperated by a space [omits the numbers after 5 elements] : 1 1 1 1 1
number to find in your array : 1
Number is found at Index [ 0 ]  [ 1 ]  [ 2 ]  [ 3 ]  [ 4 ] 
Number is found at Index [ 4 ]  [ 3 ]  [ 2 ]  [ 1 ]  [ 0 ] 
Number is found at Index [ 4 ]  [ 3 ]  [ 2 ]  [ 1 ]  [ 0 ]
```
