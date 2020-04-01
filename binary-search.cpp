#include <iostream>
using namespace std;

void binarySearch(long long int arr[], long long int n, long long int x){
	long long int low = 0, high = n, mid = 0, flag = 0;
	while(low <= high){

		mid = low + (high-low)/2;
		if(arr[mid] == x){
			cout << "Element found at position : " << (mid+1) << endl;
			flag = 1;
			break;
		}
		if(arr[mid] < x)
			low = mid+1;

		if(arr[mid] > x)
			high = mid-1;
	}
	if(flag == 0)
		cout << "Element not found !" << endl;
}

void printArray(long long int arr[], long long int n){
	for(long long int i=0; i<n ;i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	long long int n;
	cin >> n;
	cout << "Number of elements : " << n << endl;
	long long int arr[n];
	cout << "Please enter elements in increasingly sorted fashion." << endl;
	for(long long int i=0; i<n ;i++)
		cin >> arr[i];
	cout << "Entered elements : ";
	printArray(arr,n);
	long long int x;
	cin >> x;
	cout << "Element to be searched : " << x << endl;
	binarySearch(arr,n,x);
	return 0;
}
