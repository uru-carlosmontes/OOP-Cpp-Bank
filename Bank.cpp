#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string name;
	string lastname;
	int age;
public:
	Person () {
		this->name = "Smith";
		this->lastname = "Smith";
		this->age = 23;
	}
	
	Person (string name, string lastname, int age) {
		this->name = name;
		this->lastname = lastname;
		this->age = age;
	}
	
	void setName (string name) {
		this->name = name;
	}
	
	void setLastname (string lastname) {
		this->lastname = lastname;
	}
	
	void setAge (int age) {
		this->age = age;
	}
	
	string getName () {
		return this->name;
	}
	
	string getLastname() {
		return this->lastname;
	}
	
	int getAge () {
		return this->age;
	}
};

class Account {
private:
	Person person;
	int number;
	double balance;

public:
	Account (){
		this->person = Person();
		this->number = 0;
		this->balance = 0.0;
	}
	
	Account (Person person, int number, double balance) {
		this->person = person;
		this->number = number;
		this->balance = balance;
	}
	
	void setPerson (Person person) {
		this->person = person;
	}
	
	Person getPerson() {
		return this->person;
	}
	
	void setNumber (int number) {
		this->number = number;
	}
	
	int getNumber () {
		return this->number;
	}
	
	void setBalance(double balance) {
		this->balance = balance;
	}
	
	double getBalance () {
		return this->balance;
	}
	
	virtual void deposit (double amount){}
	virtual void retire (double amount){}
};

class Checking : public Account{
private:
	float rate;
	
public:
	
	Checking (Person person, int number, double balance, float rate);
	
	void setRate (float rate) {
		this->rate = rate;
	}
	
	float getRate () {
		this->rate;
	}
	
	void info () {
		cout<<"\nCuenta Corriente N# "<<getNumber();
		cout<<"\nNombre: "<<getPerson().getName();
		cout<<"\nApellido: "<<getPerson().getLastname();
		cout<<"\nSaldo :" <<getBalance();
		cout<<"\n=================================";
	}
	
	void retire(double amount) {
		setBalance(getBalance() - amount);
	}
	
	void deposit(double amount) {
		setBalance(getBalance() + amount);
	}
};

Checking::Checking(Person person, int number, double balance, float rate) {
	setPerson (person);
	setNumber (number);
	setBalance (balance);
	setRate (rate);
}

class Operations {
public:
	void  static transfer (Account *a, Account *b, double amount) {
		if ((*a).getBalance() >= amount) {
			(*a).retire(amount);
			(*b).deposit(amount);			
			cout<<"Transaction Success"<<endl;
		} else {
			cout<<"\n Insuficent Funds"<<endl;
		}
	}
};

int main () {
	
	Person p = Person("carlos", "montes", 23);
	Person p1 = Person("carlos", "montes", 23);
	Checking c1 = Checking(p, 10001, 1000.00, 1.12);
	Checking c2 = Checking(p1, 10001, 1000.00, 1.12);
	
	c1.info();
	c2.info();
	Operations::transfer(&c1, &c2, 400.00);
	c1.info();
	c2.info();
	return 0;
}
