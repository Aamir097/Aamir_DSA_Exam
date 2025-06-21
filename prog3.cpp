// Merge & Quick Sorting

#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr,int start,int mid,int end)
{
        vector<int> temp;
        int i=start, j=mid+1;

        while(i<=mid && j<=end)
        {
                if(arr[i] <= arr[j])
                {
                        temp.push_back(arr[i++]);
                }
                else
                {
                        temp.push_back(arr[j++]);
                }
        }

        while(i<=mid)
        {
                temp.push_back(arr[i++]);
        }

        while(j<=end)
        {
                temp.push_back(arr[j++]);
        }

        for(int k =0; k <temp.size(); k++)
        {
                arr[start + k] = temp[k];
        }
}

void merge_sort(vector<int>& arr,int start,int end)
{
        if (start>=end) return;

        int mid= start + (end-start) / 2;

        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
}

void print_array(vector<int>& arr)
{
        for(int i=0; i<arr.size(); i++)
        {
                cout<<arr.at(i)<<" ";
        }
        cout<<endl;
}

int main()
{
        int n;
        cout<<"Enter size of array: ";
        cin>>n;

        vector<int> arr(n);
        for(int i=0; i<n; i++)
        {
                cout<<"Enter array ["<<i<<"]: ";
                cin>>arr[i];
        }

        cout<<"*** Original Array ***"<<endl;
        print_array(arr);

        cout<<"***Sorted Array ***"<<endl;
        merge_sort(arr,0,arr.size()-1);
        print_array(arr);

        return 0;
}