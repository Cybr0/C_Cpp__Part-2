#include <iostream>
#include <string>
using namespace std;
struct animal{
	string name;
	int age;
	int weight;
	virtual void say(){}
};

struct cat:animal{
	void say(){
		cout << "Meow! My name is:"<<name<<"\n";
	}
};

struct dog:animal{
	void say(){
		cout << "Woof! My name is:"<<name<<"\n";
	}
};

void say(cat &c){
	cout << "Meow! My name is:"<<c.name<<"\n";
}
int main(int argc, char** argv) {
	cat my_cat;
	my_cat.name = "cat";
	
	
	dog my_dog;
	my_dog.name = "dog";
	
	my_cat.say();
	my_dog.say();
	
	return 0;
}
