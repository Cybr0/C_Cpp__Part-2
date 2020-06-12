#include <iostream>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct book {
	char *name = new char;
	char *author = new char;
	char *publishing_house = new char;
	char *genre = new char;
};

void print_books(book *arr,int size){
	cout << "�����:" << endl;
	for(int i = 0; i < size; i++){
		cout << "ID:\t\t" << i << endl;
		cout << "��������:\t" << arr[i].name << endl;
		cout << "�����:\t\t" << arr[i].author << endl;
		cout << "������������:\t" << arr[i].publishing_house << endl;
		cout << "����:\t\t" << arr[i].genre << endl << endl << endl;
	}
	 
}


void edit_book(book *&arr, int size){
	cout <<"�������� ����� ��� ��������������." << endl;
	for(int i = 0; i < size; i++){
		cout << "ID " << i << ".   ��������: " << arr[i].name << endl;
	} 
	cout << "������� ID �����: ";
	int choose;
	cin >> choose;
	
	if(choose < 0 || choose > 10){
		cout << "�� ����� �� ������ ID.";
		cout << "ID �� ��������� �������� - 1.";
		choose = 1;
	}
	book n_book;
	cout << "������� �������� �����: "; 
	cin >> n_book.name;
	cout << "������� ����� �����: "; 
	cin >> n_book.author;
	cout << "������� ������������ �����: "; 
	cin >> n_book.publishing_house;
	cout << "������� ���� �����: "; 
	cin >> n_book.genre;
	arr[choose] = n_book;
}


bool comparison_str(char *author, char *vs_author){
	int size = strlen(author);
	int vs_size = strlen(vs_author);
	bool c = true;
	if (size != vs_size){
		return false;
	}
	for(int i = 0; i < size; i ++){
		if(author[i] == vs_author[i]){
			c = true;
		}else{
			c = false;
			break;
		}
	}
	return c;
}
void search_books_by_author(book *arr,int size){
	char *a_book;
	cout << "������� ��� ������: ";
	cin >> a_book;
	int s = strlen(a_book);
	for(int i = 0; i < size; i++){
		if(comparison_str(a_book, arr[i].author)){
				cout << "ID:\t\t" << i << endl;
				cout << "��������:\t" << arr[i].name << endl;
				cout << "�����:\t\t" << arr[i].author << endl;
				cout << "������������:\t" << arr[i].publishing_house << endl;
				cout << "����:\t\t" << arr[i].genre << endl << endl << endl;	
			}
	}
}

void search_books_by_title(book *arr,int size){
	char *a_book;
	cout << "������� �������� �����: ";
	cin >> a_book;
	int s = strlen(a_book);
	for(int i = 0; i < size; i++){
		if(comparison_str(a_book, arr[i].name)){
				cout << "ID:\t\t" << i << endl;
				cout << "��������:\t" << arr[i].name << endl;
				cout << "�����:\t\t" << arr[i].author << endl;
				cout << "������������:\t" << arr[i].publishing_house << endl;
				cout << "����:\t\t" << arr[i].genre << endl << endl << endl;	
			}
	}
}

bool _isGreater_for_sort(char *author, char *vs_author){
	int size = strlen(author);
	int vs_size = strlen(vs_author);
	int s = 0;
	bool c = false;
	if (size > vs_size){
		s = vs_size;
	}else{
		s = size;
	}
	for(int i = 0; i < s; i ++){
		if(author[i] > vs_author[i]){
			c = true;
			return c;
		}else if(author[i] < vs_author[i]){
			c = false;
			return c;
		}
	}
	if (size > vs_size){
		c = true;
		return c;
	}else{
		c = false;
		return c;
	}
	
	return c;
}

void sort_by_namebook(book *&arr,int size){
	for(int j = 0; j < size; j++){
		for(int i = 0; i < size-1; i++){
			if(_isGreater_for_sort(arr[i].name, arr[i+1].name)){
				book temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;	
			}
		}
	}
}

void sort_by_author(book *&arr,int size){
	for(int j = 0; j < size; j++){
		for(int i = 0; i < size-1; i++){
			if(_isGreater_for_sort(arr[i].author, arr[i+1].author)){
				book temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;	
			}
		}
	}
}

void sort_by_title(book *&arr,int size){
	for(int j = 0; j < size; j++){
		for(int i = 0; i < size-1; i++){
			if(_isGreater_for_sort(arr[i].publishing_house, arr[i+1].publishing_house)){
				book temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;	
			}
		}
	}
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RUS");
	book cpp;
	cpp.name = "C++";
	cpp.author = "Timur";
	cpp.publishing_house = "Tashkent";
	cpp.genre = "Science";
	
	
	const int SIZE = 10;
	book *arr = new book[SIZE];
	for(int i = 0; i < SIZE; i++){
		arr[i] = cpp;
	}
	
	
	
	while(true){
		system("cls");
		cout << "��������� ����������." << endl;
		cout << "1.������������� �����\n"
			<< "2.������ ���� ����.\n"
			<< "3.����� ���� �� ������.\n"
			<< "4.����� ����� �� ��������.\n" 
			<< "5. ���������� �� ��������.\n"
			<< "6. ���������� �� ������.\n"
			<< "7. ���������� �� ������������.\n"
			<< "8.�����.\n>";
		int ch;
		cin >> ch;
		switch(ch){
			case 1:
				system("cls");
				edit_book(arr, SIZE);
				break;
			case 2:
				system("cls");
				print_books(arr, SIZE);
				system("pause");
				break;
			case 3:
				system("cls");
				search_books_by_author(arr, SIZE);
				system("pause");
				break;
			case 4:
				system("cls");
				search_books_by_title(arr, SIZE);
				system("pause");
				break;
			case 5: 
				system("cls");
				sort_by_namebook(arr, SIZE);
				break;
			case 6: 
				system("cls");
				sort_by_author(arr, SIZE);
				break;
			case 7: 
				system("cls");
				sort_by_title(arr, SIZE);
				break;
			case 8:
				return 0;
			default:
				cout << "�� ����� �� ���������� ����� ����." << endl;
				break;
		}
	}
	

	return 0;
}
