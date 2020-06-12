/* 
18.09.2019

*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
using namespace std;

void main_menu(int push_button);


int main(int argc, char** argv) {
	setlocale(LC_ALL, "RUS");
	
	int push_b = 0;
	main_menu(push_b);
	const int ptf_size = 50;
	char path_to_file [ptf_size] = "output.txt";
	while(true){
		int button = getch();
		if(button == 224){
			button = getch();
			if(button == 72 || button == 80){
				push_b++;
			}
			main_menu(push_b);
		}else if(button == 27){
			return 0;
		}else if(button == 13){
			if(push_b % 2 == 0){
				goto exit;
				
			}else{
				system("cls");
				cout << "Эта функция работает в тестовом режиме. Указывайте точный путь.\nВ противном случае, файл будет выбран - по умолчанию!!\n" << endl;
				cout << "Введите путь к файлу:" << endl
					<<"Пример: С:\\files\\output.txt" << endl
					<< ">";
				cin >> path_to_file;
				goto exit;
			}
		}
	}
	exit:
	const int SIZE = 100;
	char p[SIZE] = {};
	int parentheses = 0;
	FILE *file;
	file = fopen(path_to_file, "r");
	
	if(file == NULL){
		std::cout << "Error: cannot open file." << std::endl;
	}else{
		while(fgets(p,SIZE,file)){		
			for(int b = 0; b < strlen(p); b++){
				if(p[b] == '('){
					parentheses++;
				}
				else if(p[b] == ')'){
					parentheses--;
				}
				if(parentheses == (-1)){
					break;
				}
			}
		}
	}
	fclose(file);

	if(parentheses == 0){
		system("cls");
		cout << "Ответ: Круглые скобки раставлены верно!" << endl;
	}else{
		system("cls");
		cout << "Ответ Круглые скобки раставлены НЕ верно!" << endl;
	}	
	
	return 0;
}


void main_menu(int push_button){
	if(push_button % 2 == 0){
		system("cls");
		cout << "Привет я программа проверяющая правильность раставленных круглых скобок!" << endl << endl
			<< "\n\n\n\n\t\t\t  Путь к файлу:\n\n";
		cout << "\t\t\t> По умолчанию\n\t\t\t  Выбрать" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\tEsc - выход\t\t\t\t\tEnter - выбрать" << endl;
		}else{
		system("cls");
		cout << "Привет я программа проверяющая правильность раставленных круглых скобок!" << endl << endl
			<< "\n\n\n\n\t\t\t  Путь к файлу:\n\n";
		cout << "\t\t\t  По умолчанию\n\t\t\t> Выбрать" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\tEsc - выход\t\t\t\t\tEnter - выбрать" << endl;
		}
}
