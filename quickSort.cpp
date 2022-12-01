
#include<iostream>
using namespace std;

int iteration = 0;

int partition(int arr[], int low, int high, int pivot){
	int PIndex = low;
    iteration ++;
    for(int i=low;i<=high;i++) {

        if(arr[i]<=pivot) {
            swap(arr[PIndex],arr[i]);
            PIndex++;
        }
    }

    PIndex--;

	return PIndex;
}


void quickSort(int arr[], int low, int high){

	if(low < high) {
	    int pivot = arr[high];

	    int PIndex = partition(arr, low, high, pivot);
            quickSort(arr, low, PIndex-1);
            quickSort(arr, PIndex+1, high);
	}
}

void maxOccurred(int nums[], int size)
{
  int max_count = 0;
  cout << "\nMaximum occurring : ";
  for (int i=0; i<size; i++)
  {
   int count=1;
   for (int j=i+1;j<size;j++)
       if (nums[i]==nums[j])
           count++;
   if (count>max_count)
      max_count = count;
  }

  for (int i=0;i<size;i++)
  {
   int count=1;
   for (int j=i+1;j<size;j++)
       if (nums[i]==nums[j])
           count++;
   if (count==max_count)
       cout << nums[i] << " ";
  }
 }

int main()
{


	int arr[1000];
	int n;

	cout<<"Enter size of the array: ";
	cin>>n;

    cout<<"Enter array element: ";

    // taking array element from user
	for(int x = 0 ; x < n ; x++){
        cin>> arr[x];
	}

	//sorting the array
	quickSort(arr, 0 , n-1);


    cout<<endl;
	cout<<"The sorted array is: ";
	for( int i = 0 ; i < n; i++){
		cout<< arr[i]<<" ";
	}

	cout<<endl <<"Iteration: " <<iteration;
	cout<<endl <<"Maximum Number: " <<arr[n-1];

	//Maximum occurring number
    maxOccurred(arr, n-1);

    cout<<endl;
    int o;
	cin>>o;

    return 0;
}
