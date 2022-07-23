To initialise an array with all zeroes -
int arr[n]={};
int arr[n]={0};

To initialise an array with 1st element x and all other zeroes -
int arr[n]={x};

To initialise some starting elements and all other zeroes -
int arr[n]={x,y,z,w};   //arr={x,y,z,w,0,0,0,0,.......}

To find count of no. in an array -
int a[n]={1,5,2,5,6,5445,63463,6,77587,856 . . . . . . . };
Now, to find count of each -
Let max value of array is k.
int cnt[k]={};   //Initialises all values of array with value 0
for (int i=0;i<n;i++)
{
    cnt[a[i]]++;
}

But if any a[i]>10^5
Then we can not do that with arrays as in cnt[no. of elements]
The no. of values are limited to the int data type, we can not change/control that
So, we have to use maps for such cases where we can control the data type of key.


___________________________________________________________________________________
*similar datatype in array- ex) {1,'a'} is invalid
*