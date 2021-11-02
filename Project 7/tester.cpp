#include<iostream>
#include<fstream>
using namespace std;

template <class T>
class queue{
   private:
       T *arr;
       int front,rear,capacity;
      
   public:
       queue(int size){
           capacity=size;
           front=-1;
           rear =-1;
           arr = new T[capacity];
          
       }
       bool empty(){
           return front==-1;
       }
       bool full(){
           return (rear+1)%capacity==front;
       }
       void enqueue(T data){
           rear++;
       rear%=capacity;
       arr[rear]=data;
       if(front==-1)front=rear;
       }
       T frontElement(){
           return arr[front];
       }
       void dequeue(){
       if(front==rear)
           front=rear=-1;
       else{
       front++;
       front%=capacity;}
       }
};

int main(){
   ifstream in;
   in.open("data.txt");
  
   if(!in){
       cout<<"file not opened\n";
       return 0;
   }
  
   int n,num;
   in>>n;
   int arr[n][n];
   int i=0,j=0;
   while(!in.eof()){
       in>>num;
      
       arr[i][j++] = num;
      
       if(num==-999){
           i++;
           j=0;
       }
   }
  
   queue<int> q(10);
   bool visited[10];
   for(i=0;i<10;i++)visited[i] = false;
  
   for(int i=0;i<10&&!visited[i];i++){
       q.enqueue(i);
   visited[i] = true;
   while(!q.empty()){
       int num = q.frontElement();
       cout<<num<<" ";
       q.dequeue();
       j=0;
       while(arr[num][j]!=-999){
           if(!visited[arr[num][j]]){
               q.enqueue(arr[num][j]);
               visited[arr[num][j]] = true;
           }
          
           j++;
          
       }
      
   }
   }
   return 0;
  
}