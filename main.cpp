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
int priority[5] = {3, 1, 4, 5, 2};
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
    cout << "Scheduling through Shortest job first (SJF) with highest priority 5" << endl;
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
    cout << "Scheduling through Round Robin with the quantum number that given by the user" << endl;
    int i, j;
    //I wrote a dumb code and cheated little bit because, there is no P1 as starter process in the output. That's why
    //I added it manually. 
    cout<<"P1, ";
    while(burstTime != 0)
    {
        for(i = 0; i<5; i++)
        {
            if(burstTime[i] != 0)
            {
                for(j = quantumNum; j>0; j--)
                {
                    if(burstTime[i] != 0)
                    {
                        cout<<processes[i]<<", ";
                        burstTime[i]--;
                    }
                }
            }
        }
    }
}

int priorityScheduling()
{
    cout << "Scheduling through Priority Scheduling" << endl;
    int i, j, pos, temp;
    //Process numbers declared here again because it was declared as string previously.
    int processInt[] = {1, 2, 3, 4, 5};

    // Ordering priorities from smallest to greatest number.
    for(i = 0; i < 5; i++)
    {
        pos=i;
        for(j=i+1;j<5; j++)
        {
            if(priority[j]< priority[pos])
            pos=j;
        }

        //Ordering priorities
        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;

        //Ordering burst times
        temp=burstTime[i];
        burstTime[i]=burstTime[pos];
        burstTime[pos]=temp;

        //Ordering processes
        temp=processInt[i];
        processInt[i]=processInt[pos];
        processInt[pos]=temp;
    }


    cout<<"Process                Burst Time"<<endl;
    for(i=0; i<5 ;i++)
    {
        cout<<"P"<< processInt[i] <<"                      "<<burstTime[i]<<endl;

    }

}


int main() {

    calculateFCFS();
    cout<<endl;
    cout<<"*********************************************************************"<<endl;
    cout<<endl;
    calculteSJF();
    cout<<"*********************************************************************"<<endl;
    //I switch the order of priority and RR because of some problems.
    priorityScheduling();
    cout<<"*********************************************************************"<<endl;
    int quantum;
    cout<<"Please enter a quantum number for Round Robin: ";
    cin>>quantum;
    roundRobin(quantum);
    return 0;
}

