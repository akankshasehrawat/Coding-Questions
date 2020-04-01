#include <iostream>
#include <algorithm>
using namespace std;


struct Job
{
    int start, finish, profit;
};

bool compare(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

int bSearch(Job jobs[], int last)
{

    int low = 0, high = last - 1;


    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (jobs[mid].finish <= jobs[last].start)
        {
            if (jobs[mid + 1].finish <= jobs[last].start)
                low = mid + 1;
            else
                return mid;
        }
        else
            high = mid - 1;
    }

    return -1;
}

int MaxProfit(Job jobs[], int n)
{
    sort(jobs, jobs+n, compare);

    int *DP = new int[n];
    DP[0] = jobs[0].profit;


    for (int i=1; i<n; i++)
    {
        int inclProf = jobs[i].profit;
        int l = bSearch(jobs, i);
        if (l != -1)
            inclProf += DP[l];
        DP[i] = max(inclProf, DP[i-1]);
    }

    int result = DP[n-1];
    delete[] DP;

    return result;
}


int main()
{
   cout << "Please Enter the No of Jobs: ";
   int n;
   cin >> n;

    Job jobs[n];
    cout<< "Enter the Start time, Finish Time & Profit with space in between:"<< endl;

    for(int i=0;i<n;i++){
      cin >> jobs[i].start >> jobs[i].finish >> jobs[i].profit;
    }

    cout << "The Maximum profit is : " << MaxProfit(jobs, n);
    return 0;
}

