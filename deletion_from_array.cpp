#include<iostream>

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

	std::cout<<"\nEnter position to to be delete: ";
	int position;
	std::cin>>position;

	for(int i=position-1; i<n-1; i++)
		arr[i] = arr[i+1];

	std::cout<<"New array:\n";
	
	for(int i=0; i<n-1; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<"\n======COMPLETE======\n";
	
	return 0;
}
