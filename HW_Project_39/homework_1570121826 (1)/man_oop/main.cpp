#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>

using namespace std;
struct date_birth{
	int age(){
		time_t theTime = time(NULL);
		struct tm *aTime = localtime(&theTime);
		int current_year = aTime->tm_year + 1900;
		return current_year - year;
	}
	int year;
	int month;
	int day;
};

struct Man{
	char surname[32];
	char name[32];
	date_birth date;
	void print(){
		cout 
		<< surname<<" "
		<<name<<" "
		<<date.day<<"."
		<<date.month<<"."
		<<date.year <<" "
		<<date.age() <<" years"<< endl;
	}
};

template <typename T>
void addElement(T *&arr, int &size, T value){
	T *arr_2 = new T[size + 1];
	for(int i = 0; i < size; i++){
		arr_2[i] = arr[i];		
	}	
	arr_2[size] = value;
	if(size>0) {
		delete [] arr;
	}
	size++;
	arr = arr_2;
		
}

void printArray(Man *arr, int &size){
	for(int i = 0; i < size; i++){
		arr[i].print();
	}	
	system("pause");
}

template <typename T>
void deleteElement(T *&arr, int &size, int index){
	if(size == 0){
		return;
	}
	T *arr_3 = new T[size-1];
	int k = 0;
	for(int i = 0; i < (size-1); i++){
		
		
		if(i == index){
			k = k + 1;
		}
		arr_3[i] = arr[k];	
		k++;	
	}	
	
	delete [] arr;
	arr = arr_3;
	size--;
	
}

void birthday_print(Man *arr, int size, int month){
	cout<<"Именинники: \n";
	for(int i=0; i<size; i++){
		if(month == arr[i].date.month){
			arr[i].print();
		}
	}
}

bool is_bigger(Man arr, Man array){
	int min_size;
	int first_size = strlen(arr.surname);
	int second_size = strlen(array.surname);
	if(first_size>second_size){
		min_size = second_size;
	}else{
		min_size = first_size;
	}
	for(int k=0; k<min_size; k++){
		if(tolower(arr.surname[k])<tolower(array.surname[k])){	
			return false;
		}else if(tolower(arr.surname[k])>tolower(array.surname[k])){
			return true;
		}
	}
}

void sort_array(Man *text_list, int size){
	int k;
	Man x;
	
	for(int i = 0; i < size; i++){
		k = i;
		x=text_list[i];
		
		for (int j = i + 1; j < size; j++){
			if(is_bigger(x, text_list[j])){
				k = j;
				x = text_list[j];
			}
		}
		text_list[k] = text_list[i];
		text_list[i] = x;
	}
}

Man Input(){
	Man array;
	cout<<"Write surname: ";
	cin>>array.surname;
	cout<<"Write name: ";
	cin>>array.name;
	cout<<"Write day of birthday: ";
	cin>>array.date.day;
	cout<<"Write month of birthday: ";
	cin>>array.date.month;
	cout<<"Write year of birthday: ";
	cin>>array.date.year;
	return array;
}

int main(int argc, char** argv) {
	setlocale(LC_CTYPE, "Rus");
    int size = 0;
	Man *array;
	
	int MENU;
	while(true){
		system("cls");
	cout<<"1. Add new person."<<endl
		<<"2. Show people`s info"<<endl
		<<"3. Delete somebody"<<endl
		<<"4. Show birthday dates"<<endl
		<<"5. Exit"<<endl;
		cin>>MENU;
	switch(MENU){
		case 1:
			system("cls");
			addElement(array, size, Input());
		break;
		case 2:
			system("cls");
			sort_array(array, size);
			printArray(array, size);
		break;
		case 3:{
			system("cls");
			int i=0;
			cout<<"Whom you want to delete? :) ";
			cin>>i;
			deleteElement(array, size, i);
			break;
		}
		case 4:{
			int month;
			cout<<"Write month: ";
			cin>>month;
			birthday_print(array, size, month);	
			system("pause");	
			break;
		}
		case 5:
			return 0;
					
	}	
	}

	
	
	//deleteElement(array, size, 0);
	printArray(array, size);

	
	
	return 0;
}
