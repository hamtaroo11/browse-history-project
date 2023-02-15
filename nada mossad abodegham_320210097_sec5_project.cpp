//name:nada mossad abodegham
//code: 320210097
//S5 G2
//Browser history
#include <iostream>
#include<string>
using namespace std;
//implementation of the stack
class stack{
private:
int top=-1;
int n =100;
int counter=0;
string arr[100];
public:
int isfull()
{
  return(top==n-1);
}
int isempty()
{
  return(top==-1);
}
void push(string v)
{
 if(!isfull())
 {
  arr[++top]=v;
   counter++;
  }
}
string pop()
{
 if(!isempty())
 {
   string x= arr[top];
   arr[top--];
   counter--;
   return x;
 }
  return 0;
}
string Top()
{
  return arr[top];
}
int size()
{
  return counter;
}
};
class BrowserHistory
{
private:
string homepage;
stack s; //first stack which the essential one
stack s1;//second stack which store elements the pop from stack s when using back ,to see it again when calling forward funcion
public:
BrowserHistory(string hp)
{
 homepage =hp;
  s.push(homepage);

}
void visit(string url)
{
  s.push(url);
  for(int i=0;i<s1.size();i++)
    {
      s1.pop(); //when visiting any website we can not move any forward steps , then s1 must be empty
    }
}
string back(int steps)
{
  if(steps>s.size())
  {
   for(int i=0;i<s.size();i++)
     {
      s1.push(s.pop());
     }
    return s.Top();
  }
  else{
    for(int i=0;i<steps;i++)
      {
       s1.push(s.pop());
      }
    return s.Top();
  }
}
string forward(int steps)
{
  if(steps>s1.size())
  {
   for(int i=0;i<s1.size();i++)
     {
      s.push(s1.pop());
     }
    return s.Top();
    }
  else{
    for(int i=0;i<steps;i++)
      {
       s.push(s1.pop());
      }
    return s.Top();
  }
}
};
int main()
{
BrowserHistory bh ("abc.com");
bh.visit("xyz.com"); // In "abc.com". Visit "xyz.com"
bh.visit("def.com"); // In "xyz.com". Visit "def.com"
bh.visit("ijk.com"); // In "def.com". Visit "ijk.com"
cout<<bh.back(1)<<endl; // In "ijk.com", back to "def.com" return "def.com"
cout<<bh.back(1)<<endl; // In "def.com", back to "xyz.com" return "xyz.com"
cout<<bh.forward(1)<<endl; // In "xyz.com", forward to "def.com" return "def.com"
bh.visit("mno.com"); // In "def.com". Visit "mno.com"
cout<<bh.forward(2)<<endl; // In "mno.com", you cannot move forward any steps.
cout<<bh.back(2)<<endl; // In "mno.com", back two steps to "def.com"
// then to "xyz.com". return "xyz.com"
cout<<bh.back(7)<<endl; // In "xyz.com", you can move back only one step
// to "abc.com". return "abc.com"
}
