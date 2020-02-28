#include <iostream>
#include <thread>
#include <new>
#include <sstream>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;
std:: mutex mtx;
std::vector<long long> F;

//function to check the input
void send_error(char** arr_input)
{
	cout << arr_input[0]<< " Number Threads"<< endl;
	cout << "The Program take to input"<< endl;
	cout << " Where the first input is the Number and the second is the number of threads" <<endl;
	cout << "Note: Number of Threads should be < than Number and > than 0"<< endl;
}

// assign values from to N and threads "from char to integer"
void assign_value(char** arr, long long &Num, int &num_threads)
{
	std::istringstream(arr[1])>> Num;
	std::istringstream(arr[2])>> num_threads;	
}

// create an array to divide the Number by the number of threads
// and store them in array
void limit_control(long long *& Dyn_arr, long long &num, int &num_threads)
{
	long long e = (long long) num_threads;
	long long n = num / e;
	int j = 0;
	for(int i= num_threads; i >= 0; i--)
	{
		Dyn_arr[j]= n*i;
		j++;
	}	
}

//check if the Number is perfect or not
void start_threads(long long upper, long long lower, long long const &N, long long const &sum) 
{
	mtx.lock();// the begining of the critical section
	long long x = upper;
	long long &total= const_cast<long long&>(sum);
	long long &num = const_cast<long long&>(N);
	if(upper == num){	
		upper= upper-1;
		x= upper;
	}
	if(total < num)
	{
		for( long long i = upper; i > lower; i--)
		{
			if(num%x==0)
			{
				total += x;
				F.push_back(x);		
			}
			if(sum > num)
			{
				break;
			}			
			x--;
		}		
	}
	mtx.unlock();// the end of the critical section

}

int main(int argc , char** argv)
{
	long long N = 0, x = 0 ,sum = 0 , y = 0;
	int threads = 0 , num_of_factors = 0 , q = 0;
	long long *limit;
	vector<int> factors;
	
	if(argc != 3) 
	{
		send_error(argv);
		return 2;
	}
	assign_value(argv, N, threads);
	
	if(threads > N || threads == 0)
	{
		send_error(argv);
		return 2;
	}
	thread *t_arr[threads];
	long long p = threads +1;
	limit = new long long [p];
	limit_control(limit,N,threads);
	
	// create the threads
	for(int i = 0; i < threads; i++)
	{	
		x = limit[q];
		y = limit[++q];
		t_arr[i]= new thread(start_threads, x, y, std::ref(N),std::ref(sum));	 
	}
	
	// the threads join here
	for(int i = 0; i < threads; i++)
	{	
		t_arr[i]->join();
	}

	delete [] limit;
	
	for(long long x: F)
		cout<< x <<endl;

	cout << "  N = "<< N<< endl;
	cout << "sum = "<< sum<< endl;

	if( sum == N)
		return 0;
	else
		return 1;

}
