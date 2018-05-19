#include<iostream>
#include"../include/chain.hpp"
int add:: operator+(const int& i)
{
	return getSum() + i;
};


int addLLoperator-(const int& i)
{
      return getSum() - i;
};



add add::operator()(int n) const
{
     add new_add(0);
     new_add.sum = (sum + n);            
     return (new_add);           
};



int add::getSum() const
{
     return sum;
};      



bool operator==(const add& a, const int& i)
{
     return (a.getSum() == i);
};


bool operator==(const int& i, const add& a)
{
     return (a == i);
};





