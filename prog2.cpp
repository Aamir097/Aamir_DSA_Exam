// Binary Search

#include <iostream>
#include <vector>

using namespace std;

class Sorting{
    public:
    
    int Binary_search(vector<int>&arr, int key)
    {
        int start=0;
        int end=arr.size() -1;
        while(start == end)
        {
            int mid = start + (end -start) /2;
            if (arr[mid]==key)
            {
                return mid;
            }
            else if(arr[mid]<key)
            {
                start = mid+1;
            }
            else
            {
                end= mid-1;
            }
            return -1;
        }
    }

    void Print_Array(vector<int>& arr, int n )
    {
        cout<<endl;
        cout<<"Array is : ";
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    vector<int>arr;
    int ch,value,n,element,result;

    Sorting sort;

    do
    {
        cout<<"*****************"<<endl;
        cout<<"1. Enter Array: "<<endl;
        cout<<"2. Binary Search"<<endl;
        cout<<"3. Print Array"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter size of array: ";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                    int value;
                    cout<<"Enter value a["<<i<<"]: ";
                    cin>>value;
                    arr.push_back(value);
                }
            break;

            case 2:
                cout<<"Enter value to search Binary: ";
                cin>>element;

                result=sort.Binary_search(arr, element);
                if(result != -1)
                {
                    cout<<"Element at : "<<result<<endl;
                }
                else
                {
                    cout<<"Element not found! "<<endl;
                }
            break;

            case 3:
                sort.Print_Array(arr, n);
            break;
            
            case 0:
                cout<<"Bye "<<endl;
            break;

            default:
                cout<<"Invalid choice!"<<endl;
        }
    } while (ch!=0);
    
    return 0;
}