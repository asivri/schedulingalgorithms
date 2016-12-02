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
    
    return 0;
}