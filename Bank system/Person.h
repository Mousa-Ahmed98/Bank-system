#pragma once
#include<iostream>
using namespace std;
class Person
{

	public:
		int id;
		string name;
		int age;

		Person(int id, string name, int age) {
			this->id = id;
			this->name = name;
			this->age = age;
		}

		virtual string show() = 0;	
};

