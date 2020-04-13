#include <vector>
#include <string>
#include <algorithm>
#include <iostream> 
using namespace std; 
 
class Queue {   
int SIZE=10; 
int *queue; 
   int head, tail; 
public :
   Queue () ; 
   void push ( int num ) ; 
   friend void show(Queue q);
   int size();
   void pop();
   int front();
   int back();
} ; 

Queue::Queue() 
{
   queue = new int[SIZE];
   head = tail = 0 ; 
} 

void show(Queue q){
    for(int i=q.head+1;i<q.tail+1;i++)
    {cout<<" "<<q.queue[i];}
}

void Queue::push ( int num ) 
{ 
   if ( tail+1 ==head || ( tail+ 1 ==SIZE && !head )) { 
    int *tmp = new int[SIZE+1];
    for (int i=0; i<SIZE;i++){
        tmp[i]=queue[i];
    }
    SIZE+=1;
    tmp[SIZE]=num;
    queue = tmp;
   }
   else{
    tail++; 
    if ( tail==SIZE ) tail = 0 ;
    queue [ tail ] = num; 
    
   }
} 

void Queue::pop() 
{ 
   if ( head == tail ) { 
     cout << "Queue are emptyl\n" ; 
     return ;
   } 
   head++; 
   if ( head==SIZE ) head = 0 ; 
  
} 

int Queue::size()
{   int s=0;
    for(int i=head;i<tail;i++)
    {
        s++;
    }
    return s;
}

int Queue::back()
{
    return queue[tail];
}

int Queue::front()
{
    return queue[head+1];
}

int main () 
{
    Queue queue1; 
    int i, n; 
    for (i= 1 ; i <= 5 ; i++ ) { 
        queue1.push ( i ) ;
       
    } 
    cout<<"start queue:"; 
    show(queue1); 
    cout<<endl;
    cout<<"new element: ";
    cin>>n; 
    queue1.push(n);
    show(queue1); 
    cout<<endl;
    cout<<"queue size:"<<queue1.size()<<endl;
    cout<<"first"<<queue1.front()<<endl;
    cout<<"last:"<<queue1.back()<<endl;
    cout<<"delete element";
    queue1.pop();
    cout<<endl;
    show(queue1); cout<<endl;
    return 0 ; 
}
