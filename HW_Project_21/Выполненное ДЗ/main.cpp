/* �� - 21*/
#include <iostream>
#include <stdlib.h>
using namespace std;

void randArray(int *& arr, int size){
	for(int i = 0; i < size; i++){
		arr[i] = rand() % 10;
	}
//	arr[3] = 0;
//	arr[2] = 0;
//	arr[0] = 0;
}

void printArray(int *& arr, int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << endl;
	}
	cout << endl;
}

void MinMax(int *& arr, int size){
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < size; i++){	
		if(max < arr[i]){
			max = arr[i];
		}
		if(min > arr[i]){
			min = arr[i];
		}
	}
	cout << "Min = " << min << endl;
	cout << "Max = " << max << endl;
}


void changeNullInArray(int *&arr, int size){
	int nuli = 0;
	for(int i = 0; i < size; ){
		if(arr[i] == 0){
			nuli++;
			for(int j = i; j < size-1; j++){
				arr[j] = arr[j+1];
			}
		}else{
			i++;
		}
	}
	int t = size - nuli;
	for(; t < size; t++){
		arr[t] = -1;
	}
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RUS");
//	while(true){
		
		cout << "\n\n������� ������ �������\n>";
		int size;
		cin >> size;
		if(1 >= size){
			cout << "\n�� ����� �� ���������� ��������\n";
			return 0;
		}
		//cout << endl;
		int *arr = new int [size];
		cout << endl;
		randArray(arr, size);
		printArray(arr, size);
		MinMax(arr, size);
		cout << endl;
		changeNullInArray(arr, size); // ������ ���� � ����� � ������� �� (-1)
		printArray(arr, size);
		
		cout << "�������� ���������� �������\n>";
		int sdvig;
		cin >> sdvig;
		
		if(sdvig > size){
			cout << "\n�� ����� �� ���������� ��������\n";
			return 0;
		}
		
		cout << "\n�������� �����:" << endl;
		cout << "1. ����� � �����" << endl;
		cout << "2. ����� � ����\n>";
		int move;
		cin >> move;
		cout << endl;
		int *arr2 = new int[size];
		
		
		if(move == 1){ //����� � __�����;
			for(int i = 0; i < size; i++){
				arr2[i] = arr[i+sdvig];
			}
			int j = 0;
			for(int i = size - sdvig; i < size; i++){
				
				arr2[i] = arr[j];
				j++;
			}
		}
		else if(move == 2){ //����� � __����;
			int j = 0;
			for(int i = size - sdvig; i < size; i++){
				
				arr2[j] = arr[i];
				j++;
			}
			
			j = 0;
			for(int i = sdvig; i < size; i++){
				arr2[i] = arr[j];
				j++;
			}
			
		}else{
			cout << "\n�� ����� �� ���������� ��������\n";
			return 0;
		}
		
		delete[] arr; // ��� ������ �� ������ ������
		arr = arr2;
		
		printArray(arr, size);
		
//	}
	return 0;
}
