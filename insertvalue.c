int InsertSearch(int a[],int value,int low,int high)
{
    int mid=low+(value-a[low])/(a[high]-a[low])*(high-low);

	if(a[mid]==value)
	{
       return mid;
	}else if(a[mid]>value)
	{
       return InsertSearch(a,value,low,mid-1);

	}
    else if(a[mid]<value)
	{
        return InsertSearch(a,value,mid+1,high);

	}
}
