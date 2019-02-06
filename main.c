
#include<stdio.h> 
#include<stdlib.h> 
#include <time.h>

int INIT_TIME;
int FIN_TIME;
int ARRIVE_MIN;
int ARRIVE_MAX;
int QUIT_PROB;
int CPU_MIN;
int CPU_MAX;
int DISK1_MIN;
int DISK1_MAX;
int DISK2_MIN;
int DISK2_MAX;


typedef struct node { 
    int data; 
    int priority; 
  
    struct node* next; 
  
} Node; 

Node* newPQNode(int index, int priority) 
{ 
    //Creating temp with a size of (2 ints + 1 sturct)
    Node* temp=(Node*)malloc(sizeof(Node)); 
    //assign data to the index passed
    temp->data=index; 
    //assign time value (priority)
    temp->priority=priority; 
    //no new link initialized so set pointed to NULL
    temp->next=NULL; 
  
    return temp; 
} 
  
int peek(Node** head) 
{ 
    //return index of top of stack
    return (*head)->data; 
} 
 
void pop(Node** head) 
{ 
    //grab head with temp to free up after popping
    Node* temp = *head;
    //Grab the next in PQ  and assign it to the first
    (*head) = (*head)->next;
    //free memory
    free(temp); 
} 

void push(Node** head, int index, int priority) 
{ 
    Node* start = (*head); 
    Node* temp = newPQNode(index, priority); 
  
    if((*head)->priority>priority){ 
        temp->next = *head; 
        (*head) = temp; 
    } 
    else{ 
        while (start->next!=NULL&&start->next->priority<priority) { 
            start=start->next; 
        } 
        temp->next = start->next; 
        start->next = temp; 
    } 
} 
//Use for while loop until PQ isn't empty
int isEmpty(Node** head) 
{   
    //use 0 for false and 1 for true
        if(*head==NULL){
            return 1;
        }else{
            return 0;
        }
} 


//FIFO LL
struct QNode 
{ 
    //Create pos holder in FIFO LL and pointer
    int key; 
    struct QNode *next; 
}; 
  
struct Queue 
{ 
    //
    struct QNode *first, *last; 
}; 
  
struct QNode* newNode(int pos) 
{ 
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    //set the key to the value passed in
    temp->key=pos; 
    //set the pointer to NULL
    temp->next=NULL; 
    return temp;  
} 

struct Queue *createQueue() 
{   
    //Create a q with size 
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    //set the first, and last index to NULL
    q->first=q->last=NULL; 
    return q; 
} 
  
void enQueue(struct Queue *q, int pos) 
{ 
    //Create new node using the value passed in
    struct QNode *temp = newNode(pos);
 
    //Queue is empty set all values to one passed in
    if (q->last==NULL){ 
       q->first=q->last=temp; 
       return; 
    } 
    //Change last to newNode passed in
    q->last->next=temp; 
    q->last=temp; 
} 
  
struct QNode *deQueue(struct Queue *q) 
{ 
    //check if there is anything at the first spot
    if (q->first == NULL){ 
       return NULL; 
    }
    //if there if value at the first set temp to it
    struct QNode *temp = q->first;
    //set q's new value to next in list
    q->first=q->first->next; 
    //Set q->last to NULL if first is NULL
    if (q->first==NULL) 
       q->last=NULL; 
    return temp; 
} 


void init_Var(){
    char c[128];
int k;
FILE *file;
file = fopen("values.txt", "r");
if (file!=NULL) {
    while(fgets(c,128,file)){
        
/*if statements used to detemine if the op code is single digit or double digit. 
 * It accomplishes this by subtracting its ASCII value by 48 (0).
 * If its double digit it multiplies the first digit by ten (10*2=20, 10*40=40)
 * then finally adds on the second digit. k will store this value to compare to the cases
 * in the switch statement.*/
if(c[1]==':'){
    k=(int)c[0]-48;
}else{
    k=(int)c[0]-48;
    k=k*10;
    k+=(int)c[1]-48;
}
         int temp;
         
 /*If the integer is double digits we have to move the starting position
* for scanning the values.*/
         if(k<10){
         temp=2;
         }else{
             temp=3;
         }
         
//loop through each of the op codes and assign them to the global variables
         while(c[temp]!='\n'){
         switch(k)
         {
             case 1:
             INIT_TIME=INIT_TIME*10;
             INIT_TIME+=c[temp]-48;
             //printf("INIT TIME IS: %d\n",INIT_TIME);
             break;
             case 2:
             FIN_TIME=FIN_TIME*10;
             FIN_TIME+=c[temp]-48;
             //printf("FIN TIME IS: %d\n",FIN_TIME);
             break;
             case 3:
             ARRIVE_MIN=ARRIVE_MIN*10;
             ARRIVE_MIN+=c[temp]-48;
             //printf("ARRIVE MIN IS : %d\n",ARRIVE_MIN);
             break;
             case 4:
             ARRIVE_MAX=ARRIVE_MAX*10;
             ARRIVE_MAX+=c[temp]-48;
             //printf("ARRIVE MAX IS : %d\n",ARRIVE_MAX);
             break;
             case 5:
             QUIT_PROB=QUIT_PROB*10;
             QUIT_PROB+=c[temp]-48;
             //printf("QUIT PROB IS : %d\n",QUIT_PROB);
             break;
             case 6:
             CPU_MIN=CPU_MIN*10;
             CPU_MIN+=c[temp]-48;
             //printf("CPU MIN IS : %d\n",CPU_MIN);
             break;
             case 7:
             CPU_MAX=CPU_MAX*10;
             CPU_MAX+=c[temp]-48;
             //printf("CPU MAX IS : %d\n",CPU_MAX);
             break;
             case 8:
             DISK1_MIN=DISK1_MIN*10;
             DISK1_MIN+=c[temp]-48;
             //printf("DISK1 MIN IS : %d\n",DISK1_MIN);
             break;
             case 9:
             DISK1_MAX=DISK1_MAX*10;
             DISK1_MAX+=c[temp]-48;
             //printf("DISK1 MAX IS : %d\n",DISK1_MAX);
             break;
             case 10:
             DISK2_MIN=DISK2_MIN*10;
             DISK2_MIN+=c[temp]-48;
             //printf("DISK2 MIN IS : %d\n",DISK2_MIN);
             break;
             case 11:
             DISK2_MAX=DISK2_MAX*10;
             DISK2_MAX+=c[temp]-48;
             //printf("DISK2 MAX IS : %d\n",DISK2_MAX);
             break;
             case 12:
             break;

         }
//increment temp in case there are more values to plug in
         temp++;
         }
         }
    }
    fclose(file); 
    
}
int fetch_Job(){
    
    int x=0;
    x = rand() % (ARRIVE_MAX+1-ARRIVE_MIN)+ARRIVE_MIN;
    return x;
    
}
int run_CPU(int k){
    int cpu_time;
    cpu_time = rand() % (CPU_MAX+1-CPU_MIN)+CPU_MIN;
    k=k+cpu_time;
    
    return k;
}
int run_DISK1(int k){
    int disk_time;
    disk_time = rand() % (CPU_MAX+1-CPU_MIN)+CPU_MIN;
    k=k+disk_time;
    
    return k;
}
int run_DISK2(int k){
    int disk_time;
    disk_time = rand() % (CPU_MAX+1-CPU_MIN)+CPU_MIN;
    k=k+disk_time;
    
    return k;
}
int exit_CPU(){
    int exitProb;
    exitProb = rand() % (100+1-1)+1;
    if(QUIT_PROB<exitProb){
        return 0;
    }else{return 1;}
}



/* Driver program to test above function */
int main(int argc, char* argv[]) 
{ 
    srand(time(NULL));
    init_Var();
    /* Index is used to store how big job gets
     * track will be used to add jobs until it reaches index
     * top is set to top value of PQ
     * dist holds our key for where to move the next job 
     * ex: dist[5]=2, whatever job is at index 5 has the next order
     * to go to memory.
     * bool is used to check the quit CPU chance
     * disk counts are used to determine where to send a job in memory
     * */
    int cpuMAX=0;
    int disk1MAX=0;
    int disk2MAX=0;
    int index=0;
    int job[2500];
    int track=1;
    int top;
    int bool;
    int cpuCount=0;
    int cpuResponse=0;
    int disk1Count=0;
    int disk2Count=0;
    int busyServer=0;
    int busySub=0;
    int util;
    int cpuBusy=0;
    int disk1Busy=0;
    int disk1Response=0;
    int disk2Busy=0;;
    int disk2Response=0;
    int throughCPU=0;
    int throughDISK1=0;
    int throughDISK2=0;
    struct Queue *CPU = createQueue();
    struct Queue *DISK1 = createQueue();
    struct Queue *DISK2 = createQueue();
    struct QNode *dq;
    Node* pq = newPQNode(FIN_TIME,FIN_TIME);
    FILE *fp;
    fp = fopen("storeValues.txt","w");
    
    /* Creating a while loop to give me a base array
     * of jobs that i can add one by one to the priority
     * queue. The while loop will catch the last jobs value
     * if it goes over FIN_TIME and set it back to null.
     * */
    while(job[index-1]<FIN_TIME){
        if(index>0){
        job[index]=fetch_Job()+job[index-1];
        }else{
            job[index]=fetch_Job();
        }
        if(job[index]>FIN_TIME){
            job[index]==NULL;
            break;
        }
                index++;
    }
    int dist[index];
    push(&pq,0,job[0]);
    dist[0]=1;
    
    while(peek(&pq)!=FIN_TIME&&peek(&pq)<FIN_TIME){
        /*Start by adding a fresh job onto the PQ
         * This will help to determine times
         * and when to pop off jobs from cpu,disk1,or disk2
         */
        if(track<index){
        push(&pq,track,job[track]);
        dist[track]=1;
        }
        //we take the top value in the PQ
        top=peek(&pq);
        pop(&pq);
        fprintf(fp,"The job %d at top of stack with value %d\n",top,job[top]);
        /* If the CPU is completely idle and has no jobs.
         * After putting the job through run_CPU the system
         * will wait until a new job is created with a higher Value
         * then the CPU->first and Dequeue it accordingly
         * */
        if(CPU->first==NULL&&dist[top]==1){
            fprintf(fp,"the job %d with value %d is first in CPU queue\n",top,job[top]);
            busySub=job[top];
            job[top]=run_CPU(job[top]);
            busyServer+=job[top]-busySub;
            cpuBusy+=job[top]-busySub;
            fprintf(fp,"after runCPU job %d with value %d is first in CPU queue\n",top,job[top]);
            enQueue(CPU,top);
            cpuCount++;
            //cpuResponse++;
            dist[top]=0;
        }
        
        else if(CPU->first!=NULL)
        {
            //If the PQ job has a higher value than my finished job
            if(job[top]>=job[CPU->first->key])
            {
            //take it off the FIFO
            dq=deQueue(CPU);
            throughCPU++;
            cpuResponse++;
            cpuCount--;
            fprintf(fp,"Job %d with value %d STOPPED the job\n",top,job[top]);
            fprintf(fp,"Job %d with value %d just left the CPU\n",dq->key,job[dq->key]);
            //Set its distributor with value 2 for memory/exit
            dist[dq->key]=2;
            //pop it on the PQ to wait until its next in line
            push(&pq,dq->key,job[dq->key]);
            
            /*if the value that was higher also has a distributor of 1
             *Queue it into the CPU */
            if(dist[top]==1){
            enQueue(CPU,top);
            //cpuResponse++;
            cpuCount++;
            fprintf(fp,"Job %d entered the CPU queue with a value of %d\n",top,job[top]);
            }
            /* Now we need to readjust the time of the new job being worked on
             * We set it to the current time(the time the old job left the system)
             * Then we runCPU to get its value for being finished*/
            if(CPU->first!=NULL){
                //If the next in line has a lower time value than dq, set the cpu->first  time to dq-key time
                if(job[CPU->first->key]<job[dq->key]){
                job[CPU->first->key]=job[dq->key];
                busySub=job[CPU->first->key];
                job[CPU->first->key]=run_CPU(job[CPU->first->key]);
                busyServer+=job[CPU->first->key]-busySub;
                cpuBusy+=job[top]-busySub;
                }else{
                busySub=job[CPU->first->key];
                job[CPU->first->key]=run_CPU(job[CPU->first->key]);
                busyServer+=job[CPU->first->key]-busySub;
                cpuBusy+=job[top]-busySub;
                fprintf(fp,"Job %d with value %d is at CPU first\n",CPU->first->key,job[CPU->first->key]);
            }
            }
            }
            //If the PQ top value still isnt higher than our CPU->first
            else{
                //throw it on the CPU Queue if thats its dist value
                if(dist[top]==1){
            fprintf(fp,"Job %d entered the CPU queue with a value of %d\n",top,job[top]);        
            enQueue(CPU,top);
            //cpuResponse++;
            cpuCount++;
                }
                }
                
        }
        /* Handling jobs that just finished at the CPU with dist value 2
         * Call the exitCPU func to see if it will exit and if it does
         * then dist value set to 0*/
        if(dist[top]==2){
            bool=exit_CPU();
            if(bool==1){
                dist[top]==0;
                fprintf(fp,"Job %d quit!\n",top);
            }
            //If we dont exit the program
            else{
                //IF Disk1 is the most free or idle
                if(DISK1->first==NULL){
                busySub=job[top];
                job[top]=run_DISK1(job[top]);
                busyServer+=job[top]-busySub;
                disk1Busy+=job[top]-busySub;
                fprintf(fp,"Job %d with value %d first of queue in DISK1\n",top,job[top]);
                enQueue(DISK1,top);
                disk1Count++;
                }
                //IF Disk2 is the most free or idle
                else if(DISK2->first==NULL){
                busySub=job[top];
                job[top]=run_DISK2(job[top]);
                busyServer+=job[top]-busySub;
                disk2Busy+=job[top]-busySub;
                fprintf(fp,"Job %d with value %d first of queue in DISK2\n",top,job[top]);
                enQueue(DISK2,top);
                disk2Count++;
                }
                //if disk1 has less in FIFO than disk2
                else if(disk1Count<disk2Count){
                    fprintf(fp,"Job %d with value %d queued in DISK1\n",top,job[top]);
                    enQueue(DISK1,top);
                    disk1Count++;
                }
                //If disk2 has less in FIFO than disk1
                else if(disk2Count<disk1Count){
                    fprintf(fp,"Job %d with value %d queued in DISK2\n",top,job[top]);
                    enQueue(DISK2,top);
                    disk2Count++;
                }
                //the FIFO lengths are equal just send to disk1
                else if(disk1Count==disk2Count){
                    fprintf(fp,"Job %d with value %d queued in DISK1\n",top,job[top]);
                    enQueue(DISK1,top);
                    disk1Count++;
                //set dist value to 0 while in FIFO
                dist[top]=0;
            }
            
        }
        }
        /* If statements here used just like CPU
         * Were going to check if the PQ top value is higher than either
         * of my DISK->firsts and then adjust accordingly
        */
        if(DISK1->first!=NULL){
            if(job[top]>=job[DISK1->first->key]&&top!=DISK1->first->key){
            dq=deQueue(DISK1);
            disk1Response++;
            if(disk1Count>disk1MAX){
                disk1MAX=disk1Count;
            }
            throughDISK1++;
            disk1Count--;
            dist[dq->key]=1;
            push(&pq,dq->key,job[dq->key]);
            fprintf(fp,"Job %d left DISK1 with value %d\n",dq->key,job[dq->key]);
            //Whatever is on Disk1->first gets time adjusted and a new value for when its finished
            if(DISK1->first!=NULL){
               if(job[DISK1->first->key]<job[dq->key]){
                job[DISK1->first->key]=job[dq->key];
            }
                busySub=job[DISK1->first->key];
                job[DISK1->first->key]=run_DISK1(job[DISK1->first->key]);
                busyServer+=job[DISK1->first->key]-busySub;
                disk1Busy+=job[top]-busySub;
                fprintf(fp,"The new job at first is Job %d with value %d\n",DISK1->first->key,job[DISK1->first->key]);
            }
            }
        }
        if(DISK2->first!=NULL){
            if(job[top]>=job[DISK2->first->key]&&top!=DISK2->first->key){
            dq=deQueue(DISK2);
            if(disk2Count>disk2MAX){
                disk2MAX=disk2Count;
            }
            throughDISK2++;
            disk2Response++;
            disk2Count--;
            dist[dq->key]=1;
            push(&pq,dq->key,job[dq->key]);
            fprintf(fp,"Job %d left DISK2 with value %d\n",dq->key,job[dq->key]);
            //printf("The value higher is %d\n",job[top]);

            //Whatever is on Disk1->first gets time adjusted and a new value for when its finished
            if(DISK2->first!=NULL){
               if(job[DISK2->first->key]<job[dq->key]){
                job[DISK2->first->key]=job[dq->key];
            }
                busySub=job[DISK2->first->key];
                job[DISK2->first->key]=run_DISK2(job[DISK2->first->key]);
                busyServer+=job[DISK2->first->key]-busySub;
                disk2Busy+=job[top]-busySub;
                fprintf(fp,"The new job at first is Job %d with value %d\n",DISK2->first->key,job[DISK2->first->key]);
            }            
            }
        }
track++;
    }
    printf("%d\n",cpuBusy);
    printf("%d\n",cpuResponse);
    int CPUavgResponse=cpuBusy/cpuResponse;
    int DISK1avg=disk1Busy/disk1Response;
    int DISK2avg=disk2Busy/disk2Response;
    util=busyServer/(FIN_TIME-INIT_TIME);
    throughCPU=FIN_TIME/throughCPU;
    throughDISK1=FIN_TIME/throughDISK1;
    throughDISK2=FIN_TIME/throughDISK2;
    printf("The max size of the DISK1 queue is %d\n",disk1MAX);
    printf("The max size of the DISK2 queue is %d\n",disk2MAX);
    printf("The max size of the CPU queue is %d\n",cpuCount);
    printf("Average CPU response time is %d seconds\n",CPUavgResponse);
    printf("The max CPU response time is %d seconds\n",CPU_MAX);
    printf("Average DISK1 response time is %d seconds\n",DISK1avg);
    printf("The max DISK1 response time is %d seconds\n",DISK1_MAX);
    printf("Average DISK2 response time is %d seconds\n",DISK2avg);
    printf("The max DISK2 response time is %d seconds\n",DISK2_MAX);       
    fprintf(fp,"Simulation is finished at time %d",FIN_TIME);
    printf("the CPU completed %d jobs on average a job every %d seconds\n",cpuResponse,throughCPU);
    printf("DISK1 completed %d jobs on average a job every %d seconds\n",disk1Response,throughDISK1);
    printf("DISK2 completed %d jobs on average a job every %d seconds\n",disk2Response,throughDISK2);
    fclose(fp);
    return 0; 
} 


