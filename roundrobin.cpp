#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//stuff for a sorting algorithm to sort the array by burst time


class process{
	
	public:
	int id,//process ID array
	atime,//process arrival time
	btime,//process burst time
	etime,//process exit time
	ttime,//process turnaround time
	wtime;//process wait time
	
	//setter methods
	void setid(int ID);
	void setatime(int ATIME);
	void setbtime(int BTIME);
	void setetime(int ETIME);
	void setttime(int TTIME);
	void setwtime(int WTIME);
	
	//getter methods
	int getid();
	int getatime();
	int getbtime();
	int getetime();
	int getttime();
	int getwtime();
};











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

int nop;//variable for number of processes
	cout << "Enter the number of processes:";
	cin >> nop;
process p[nop];
	
	
	int timequantum=0;
	float wavg = 0;//process average wait time
	int	 q;//the amount of times the time quantum repeats
	

//collecting all the user inputs
	cout<<"Enter the time quantum:";
	cin>>timequantum;
	
	for (int i = 0; i < nop; i++)
	{
		p[i].id;
		cout << "Enter arrival time for process p"<<i<<" :";
		cin >> p[i].atime;
		cout << "Enter burst time for process p" << i << " :";
		cin >> p[i].btime;
	}

	q = ceil (q / timequantum);
	
	int n = sizeof(p[0].btime) / sizeof(p[0].btime);
    //insertionSort(atime,btime,p, n);//sorting the array based off of arrival time
	
	cout<<q<<endl;



wavg = wavg / nop;
cout<<endl<<"The average waiting time is :"<<wavg;	
}

void setid(int ID)
{
	id = ID;
}
void setatime(int ATIME)
{
	atime = ATIME;	
}
void setbtime(int BTIME)
{
	btime = BTIME;
}
void setetime(int ETIME)
{
	etime = ETIME;
}
void setttime(int TTIME)
{
	ttime = TTIME;
}
void setwtime(int WTIME)
{
	wtime = WTIME;
}


