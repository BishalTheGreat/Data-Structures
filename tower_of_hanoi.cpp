// Solving Tower Of Hanoi problem
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
static int count=1;

// TOH recursive solution definition
void TOH(int n, char source, char destination, char auxilary){

    // If only one peg/disk in source, move it to destination
    if(n == 1){
        cout<<count<<". Disk "<<n<<" :: "<<source<<"  ------>  "<<destination<<endl;
        count++;
        return;
    }

    // Actual destination will be auxilary, while auxilary is destination
    TOH(n-1, source, auxilary, destination);
    cout<<count<<". Disk "<<n<<" :: "<<source<<"  ------>  "<<destination<<endl;
    count++;
    

    // Auxilary will be source and source will be auxilary
    TOH(n-1, auxilary, destination, source);
    
}

int main(){
    cout<<"***** TOWER OF HANOI *****"<<endl;
    cout<<"--------------------------"<<endl;
    int disk;
    cout<<"Enter number of disk: ";
    cin>>disk;
    cout<<endl;
    
    // Calling to TOH function; 
    // A --> source, B --> Auxilary and C --> Destination
    TOH(disk, 'A', 'C', 'B');

    cout<<"\n- - - - - END - - - - -"<<endl;
    return 0;
}