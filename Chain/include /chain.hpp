#include<iostream>
#include<type_traits>
 class add
 {
     int sum = 0;
     public:
         friend bool operator==(const add& a, const int& i);
         friend bool operator==(const int& i, const add& a);


         int operator+(const int& i)
         {
              return getSum() + i;
         };

         int operator-(const int& i)
         {
              return getSum() - i;
         };

         add(int n_) : sum(n_){ };

         add operator()(int n) const
         {
             add new_add(0);
             new_add.sum = (sum + n);            
             return (new_add);           
         };



         int getSum() const
         {
             return sum;
         };      

 };

 bool operator==(const add& a, const int& i)
 {
     return (a.getSum() == i);
 };


 bool operator==(const int& i, const add& a)
 {
     return (a == i);
 };





