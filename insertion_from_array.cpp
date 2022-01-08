#include<iostream>
// using namespace std;

int main(){
	int arr[20], n;
	std::cout<<"Enter no. of array element: ";
	std :: cin>>n;

	std::cout<<"Enter "<<n<<" array elements:\n";
	
	for(int i=0; i<n; i++){
		std::cin>>arr[i];
	}

	std::cout<<"The array is:\n";
	
	for(int i=0; i<n; i++)
		std::cout<<arr[i] <<" ";

	std::cout<<"\nEnter new element for insertion: ";
	int element;
	std::cin>>element;

	std::cout<<"Enter position to insert: ";
	int position;
	std::cin>>position;

	for(int i=n-1; i>=position-1; i--)
		arr[i+1] = arr[i];
	arr[position-1] = element;

	std::cout<<"Inserted array:\n";
	
	for(int i=0; i<=n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<"\n======COMPLETE======\n";
	
	return 0;
}
