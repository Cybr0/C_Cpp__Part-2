/* 

������ �����
������� 1 - �������� �����. ���� ��������� �� �����.


 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;



int main(int argc, char** argv) {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	cout << "������� 1 - �������� �����. ���� ��������� �� �����. Timur Y.\n\n";
	cout << "������� 2.\n";
	
	int row, col;
	cout << "������� ������ �������:\n������� ���. �����    >";
	cin >> row;
	cout << "������� ���. c������� >";
	cin >> col;
	cout << "\n\n";
	
	int **arr = new int*[row];   // �������� ������������� �������
	for(int i = 0; i < row; i++){
		arr[i] = new int[col];
	}
		
		
	for(int i = 0; i < row; i++){ //�����//������
		for(int j = 0; j < col; j++){
			arr[i][j] = (-(rand()%100)) + 50;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	
	
	
	int *character = new int [row];
	for(int i = 0; i < row; i++)
		character[i] = 0; 
		
		
	for(int i = 0; i < row; i++){ // ���������� character
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
	for(int i = 0; i < row; i++){ //�����
		for(int j = 0; j < col; j++){
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
//	for(int i = 0; i < row; i++)
//		cout << character [i] << endl;
		
		
		
	return 0;
}
