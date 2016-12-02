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

int main() {

    //Setting the variables which are given before.
    string processes[5] = {"P1", "P2", "P3", "P4", "P5"};
    int burstTime[5] = {10, 1, 2, 3, 5};
    int priority[5] = {3, 1, 3, 5, 2};
    int waitingTime[5];
    int totalWaiting = 0;
    float averageWaiting;
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
    averageWaiting = totalWaiting/5;
    cout<<"Average waiting time is:"<<averageWaiting<<endl;

    return 0;
}