#include <iostream>
#include <stdio.h>
using namespace std;
 
 
int main(int argc, char** argv) {
	
	int arr[256] = {0};
	FILE *inputFile;
	inputFile = fopen("input.txt", "r");
	char text[1024] = {0};
	if(inputFile == NULL){
		cout << "ERROR!\n";
	}else{
		cout << "File Founded.\n";
		while(fgets(text, 1024, inputFile) != NULL){
			for(int i = 0; i < sizeof (text); i++ ){
				char c = text[i];
				arr[int(c)]++;		
			}
		}
		int sum;
			for(int i = 65; i < 91; i++){
				//if(arr[i] != 0){
					
				//	cout << char (i + 32) << " = " << arr[i + 32] << endl;
				//}
				sum = arr[i + 32] + arr[i];
//				cout << sum << endl;		
				
				
				if(sum != 0){
					cout << char (i) << " = " << sum << endl;
				}
		}
		
		

	}
	

	return 0;
}
