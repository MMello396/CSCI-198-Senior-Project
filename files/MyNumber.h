#pragma once
#include <iostream>
using namespace std;

class MyNumber
{
public:
	MyNumber() : x(0), ncomparisons(0), nassigns(0) {};
	MyNumber(int x1) : x(x1), ncomparisons(0), nassigns(0) {};
	~MyNumber() {};
	
	void ResetStats(){
		ncomparisons = 0;
		nassigns = 0;
	};
	
	int GetComps(){
		return ncomparisons;
		nassigns = 0;
	};

	int GetAssigns(){
		return nassigns;
	};

	int operator=(int a)
	{
		nassigns++;
		x = a;
	};

	int operator=(MyNumber &c1)
	{
		nassigns++;
		x = c1.x;
	};

	friend int operator+(MyNumber &c1, int x)
	{
		return c1.x + x;
	};

	friend int operator+(int x , MyNumber &c1)
	{
		return c1.x + x;
	};

	friend int operator+(MyNumber &c1, MyNumber &c2)
	{
		return c1.x + c2.x;
	};

	friend int operator-(MyNumber &c1, int x)
	{
		return c1.x - x;
	};

	friend int operator-(int x, MyNumber &c1)
	{
		return c1.x - x;
	};

	friend int operator-(MyNumber &c1, MyNumber &c2)
	{
		return c1.x - c2.x;
	};

	friend bool operator<(MyNumber &c1, MyNumber &c2)
	{
		c1.ncomparisons++;
		c2.ncomparisons++;
		return c1.x < c2.x;
	};

	friend bool operator<=(MyNumber &c1, MyNumber &c2)
	{
		c1.ncomparisons++;
		c2.ncomparisons++;
		return c1.x < c2.x;
	};

	friend bool operator>(MyNumber &c1, MyNumber &c2)
	{
		c1.ncomparisons++;
		c2.ncomparisons++;
		return c1.x > c2.x;
	};
	
	friend bool operator>=(MyNumber &c1, MyNumber &c2)
	{
		c1.ncomparisons++;
		c2.ncomparisons++;
		return c1.x >= c2.x;
	};

	friend bool operator==(MyNumber &c1, MyNumber &c2)
	{
		c1.ncomparisons++;
		c2.ncomparisons++;
		return c1.x == c2.x;
	}


	int value()
	{
		return x;
	}

	void DisplayInfo() { 
		cout << "Ncomparisons: " << ncomparisons << endl;
		cout << "Nassigns: " << nassigns << endl;
	}
private:
	int x;
	int ncomparisons;
	int nassigns;
};

