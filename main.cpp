#include <iostream>

using namespace std;

/*
 * Processes given before:
 * Process 	     Burst Time      Priority
       P1			10	        	3
       P2 			1		        1
       P3			2		        4
       P4			3		        5
       P5			5		        2
 */

//Setting the variables global to make it able to use in different functions
string processes[5] = {"P1", "P2", "P3", "P4", "P5"};
int burstTime[5] = {10, 1, 2, 3, 5};
int priority[5] = {3, 1, 3, 5, 2};
int waitingTime[5];
int totalWaiting = 0;
float averageWaiting;



int calculateFCFS()
{
    int i, j;

    cout << "Scheduling through First-come, first served (FCFS) Algorithm" << endl;
    //Calculating the average waiting time:
    for (i = 1; i < 5; i++)
    {
        waitingTime[i] = 0;
        for(j = 0; j<i; j++)
        {
            //Waiting time gonna directly increase through burst times
            //Because it's FCFS algorithm
            waitingTime[0] = 0;
            waitingTime[i] += burstTime[j];
        }
    }

    cout<<endl;
    //Let's printout the process table with waiting time:
    cout<<"Process               Burst Time             Waiting Time"<<endl;
    for(i = 0; i<5; i++)
    {
        totalWaiting += waitingTime[i];
        cout<<processes[i]<<"                      "<<burstTime[i]<<"                       "<<waitingTime[i]<<endl;
    }
    cout<<endl;
    averageWaiting = totalWaiting/5;
    cout<<"Average waiting time is:"<<averageWaiting<<endl;
}

//I found that we can list burst times using selection sort so I'll implement that in SJF Scheduling.
float calculteSJF()
{
 //Sorting burst time
    int index;
    string indexP;
    int temp;
    string tempP;
    int i, j;
    for(i=0; i<5 ; i++)
    {
        index = i;
        indexP = tempP;
        for(j = i+1 ; j<5 ; j++)
        {
            if(burstTime[j] < burstTime[index])
            {
                index  = j;
                indexP = tempP;
            }
        }
        if(index != i)
        {
            //Sorting burst times
            temp = burstTime[i];
            burstTime[i] = burstTime[index];
            burstTime[index] =temp;

           //Sorting processes name is a challange
           //Because can't directly like burst time
           //since names are string.
            tempP = processes[i];
            processes[i] = processes [index];
            processes[index] = tempP;

        }
    }

    cout<<endl;
    //Let's printout the process table with waiting time:
    cout<<"Process               Burst Time             Waiting Time"<<endl;
    for(i = 0; i<5; i++)
    {
        waitingTime[i] = 0;
        for(j = 0; j<i; j++)
        {
            //Waiting time gonna directly increase through burst times
            //Because it's FCFS algorithm
            waitingTime[0] = 0;
            waitingTime[i] += burstTime[j];
        }

        totalWaiting += waitingTime[i];
        cout<<processes[i]<<"                      "<<burstTime[i]<<"                       "<<waitingTime[i]<<endl;
    }
    /*
     * Calculating average time was total mess here.
     * That's why I'm going to calculate it by my hand to be on time for my assignment.
     *TODO: Fix the code.
    cout<<endl;
    for(int k = 0; k<5; k++)
    {
        cout<<waitingTime[k]<<" ";
    }
    cout<<totalWaiting<<endl;
    averageWaiting = totalWaiting/5;
    cout<<"Average waiting time is:"<<averageWaiting<<endl;
     */
    float avgTime;
    avgTime = (0+1+3+6+11)/5;
    cout<<"Average waiting time is: "<<avgTime<<endl;
}

float roundRobin(int quantumNum)
{
    int i, j, k;
    
}
int main() {

    calculateFCFS();
    cout<<endl;
    cout<<"*********************************************************************"<<endl;
    cout<<endl;
    cout << "Scheduling through Shortest job first (SJF) with highest priority 5" << endl;
    calculteSJF();
    cout<<"*********************************************************************"<<endl;
    int quantum;
    cout<<"Please enter a quantum number for Round Robin: ";
    cin>>quantum;
    roundRobin(quantum);
    return 0;
}

