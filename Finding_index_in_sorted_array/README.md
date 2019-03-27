Finding index of a number in two sorted arrays combined together

PROBLEM STATEMENT:

User has a sorted array. The array gets divided into 2. The second half of the array is placed at the 
front and the front half is placed at the back. eg. 10 13 15 19 1 4 6 8. Given a number find the index
of the number in array. 

COMPILING :

Use the make file to compile

```
$make
```

or

```
$g++ main.cpp -o main.exe --std=c++11
```

gives an executable main.exe

EXECUTION :

```
$./main.exe <TC>
```

TC = number of test cases

EXAMPLE :

```
$ ./main.exe 1
number of inputs in your array : 10
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 10 20 25 27 35 1 5 7 8 9
number to find in your array : 7
The number is found at index [7]
```

TEST CASES:

1. Normal case - User inputs an array and searches for a number in it.

```
$ ./main.exe 1
number of inputs in your array : 10
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 15 17 18 19 20 0 1 4 5 6
number to find in your array : 4
The number is found at index [7] 
```

2. When there is number is not present in the array.

```
$ ./main.exe 1
number of inputs in your array : 10                      
enter 10 elements of the array seperated by a space [omits the numbers after 10 elements] : 15 17 18 19 20 0 1 4 5 6
number to find in your array : 2
did not find the number in the array
```
