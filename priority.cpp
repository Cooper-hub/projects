#include <iostream>
#include <algorithm>
using namespace std;

//stuff for a sorting algorithm to sort the array by burst time

void insertionSort(int array[], int array2[],int array3[], int size)
{

	for (int s = 1; s < size; s++) {
		int key = array[s];
		int key2 = array2[s];
		int key3 = array3[s];
		int i = s - 1;

		while ((key < array[i]) && (i >= 0)) 
		{
			
			array[i + 1] = array[i];
			array2[i + 1] = array2[i];
			array3[i + 1] = array3[i];
			--i;
			
		}
		
		array[i + 1] = key;
		array2[i + 1] = key2;
		array3[i + 1] = key3;
	}
}




int main()
{
int temp,place;//temporary and placeholder values to be used later
int nop;//variable for number of processes
	cout << "Enter the number of processes:";
	cin >> nop;
	string pname[nop];
	
	
	
	int p[nop];//process ID array
	int atime[nop];//process arrival time
	int btime[nop];//process burst time
	int etime[nop];//process exit time
	int ttime[nop];//process turnaround time
	int wtime[nop];//process wait time
	int priority[nop];//The priority of the process(0 is highest)
	float wavg = 0;//process average wait time

//collecting all the user inputs
	for (int i = 0; i < nop; i++)
	{
		p[i]= i;
		cout << "Enter arrival time for process p"<<i<<" :";
		cin >> atime[i];
		cout << "Enter burst time for process p" << i << " :";
		cin >> btime[i];
		cout<< "Enter the priority for the process p"<< i << " :";
		cin>>priority[i];
	}

	int n = sizeof(btime) / sizeof(btime[0]);
    insertionSort(atime,btime,p, n);//sorting the array based off of arrival time



//Dealing with processes that arrived at the same time

for(int i=0;i<nop;i++)
  {
    for(int j=i+1;j<nop;j++)
    {
      if(atime[i]==atime[j])
      {
        if(priority[i]>priority[j])//swapping equal arrival time processes based off of their burst time    
        {
          swap(atime[i],atime[j]);
          swap(btime[i],btime[j]);
		  swap(p[i],p[j]);
        }
      }
    }
  }


//completing initial value calculations

etime[0] = atime[0] + btime[0];//exit time calcualations
ttime[0] = etime[0] - atime[0];//turnaround time calculations
wtime[0] = ttime[0] - btime[0];//waiting time calculations



//calculating the place for the rest of the processes
for(int i=1;i<nop;i++)
  {
    temp = etime[i-1];//setting the temp equal to the previous exit time
    int low = btime[i];
    for(int j=i;j<nop;j++)//counting up with the remaining processes
    {
      if(temp >= atime[j] && low >=btime[j])//previous time completion is compared with arrival time and burst times are compared
      {
        low = btime[j];
        place = j;
      }
    }
	etime[place] = temp + btime[place];
    ttime[place] = etime[place] - atime[place];
    wtime[place] = ttime[place] - btime[place];
}

for (int k = 0; k<nop; k++)
{
	wavg = wtime[k] + wavg;
	
	if(k==0)//case for the first executed process
	{
		cout<<"P"<<p[k]<<":";
		cout<<atime[0];
		for(int i =1; i<etime[0];i++)
		{
			cout<<"-";
		}
		cout<<etime[0]<<endl;	
	}
else if(k!= 0)
{

cout<<"P"<<p[k]<<":";
for(int i =0; i<etime[k-1];i++)
		{
			cout<<" ";
		}
cout<<etime[k-1];
for(int i =1; i<btime[k];i++)
		{
			cout<<"-";
		}
cout<<etime[k]<<endl;
}
}
wavg = wavg / nop;
cout<<endl<<"The average waiting time is :"<<wavg;



	
}