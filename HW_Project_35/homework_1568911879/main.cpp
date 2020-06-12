/* 

Юсупов Тимур
Задание 1 - седловые точки. Было выполнено на уроке.


 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;



int main(int argc, char** argv) {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	cout << "Задание 1 - седловые точки. Было выполнено на уроке. Timur Y.\n\n";
	cout << "Задание 2.\n";
	
	int row, col;
	cout << "Введите размер матрицы:\nВведите кол. строк    >";
	cin >> row;
	cout << "Введите кол. cтолбцов >";
	cin >> col;
	cout << "\n\n";
	
	int **arr = new int*[row];   // создание динамического массива
	for(int i = 0; i < row; i++){
		arr[i] = new int[col];
	}
		
		
	for(int i = 0; i < row; i++){ //вывод//рандом
		for(int j = 0; j < col; j++){
			arr[i][j] = (-(rand()%100)) + 50;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	
	
	
	int *character = new int [row];
	for(int i = 0; i < row; i++)
		character[i] = 0; 
		
		
	for(int i = 0; i < row; i++){ // нахождение character
		for(int j = 0; j < col; j++){
			if(arr[i][j] >= 0 && arr[i][j] % 2 == 0){
				character[i] += arr[i][j];
			}
		}
	}
	
//	for(int i = 0; i < row; i++)
//		cout << character [i] << endl;
	

	

	int x,xx;
	for(int i=0;i<row;i++){            
		for(int j=row-1;j>i;j--){     
			if(character[j-1]<character[j]){
				x=character[j-1];
				character[j-1]=character[j];
				character[j]=x;
				for(int g = 0; g < col; g++){
					xx = arr[j-1][g];
					arr[j-1][g] = arr[j][g];
					arr[j][g] = xx;
				}	
			}
		}
	}



	cout << "\n\n";
	for(int i = 0; i < row; i++){ //вывод
		for(int j = 0; j < col; j++){
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
//	for(int i = 0; i < row; i++)
//		cout << character [i] << endl;
		
		
		
	return 0;
}
