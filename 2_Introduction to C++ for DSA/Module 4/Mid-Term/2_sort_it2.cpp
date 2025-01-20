/*

Problem Statement

You will be given an array A and the size of that array N. You need to create a function named sort_it(). After taking the input for the size in main function, call that function by giving the size as parameter and take the array input inside that function. After that, you need to sort the array in descending order. Then, return that array from the function and receive it in the main function. Finally, print the sorted array in the main function.

Input Format

First line will contain N.
Second line will contain the array A.
Constraints

1 <= N <= 10^5
-10^9 <= A[i] <= 10^9 Where 0 <= i < N
Output Format

Ouptut the array in descending order.
Sample Input 0

5
1 4 2 3 5
Sample Output 0

5 4 3 2 1

*/

#include <iostream>
#include <algorithm>
using namespace std;

int* sort_it(int n){
    int* a = new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n, greater<int>());
    return a;
}

int main(){

    int n;
    cin >> n;
    int* sorted_array = sort_it(n);

    // Print the sorted array (it is already sorted in descending order)
    for(int i=0; i<n; i++){
        cout << sorted_array[i] << " ";
    }
    cout << endl;

    delete[] sorted_array;

    return 0;
}