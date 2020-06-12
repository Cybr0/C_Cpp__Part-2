#include <iostream>
#include <string.h>

using namespace std;

bool exists(char *to_find, char *source){
	size_t s_len = strlen(source);
	size_t tf_len = strlen(to_find);
	if(tf_len > s_len){
		return false;
	}
	int j = 0;
	for(int i = 0; i < s_len; i++){
		if(source[i] == to_find[j]){
			j++;
			if(tf_len == j){
				return true;
			}
		}else{
			j = 0;
		}
	}
	return false;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL,"RUS");
	
	if(argc <= 1){
		cout << "Нет больше аргументов!";
		return 0;
	}
	
	FILE *readfile;
	readfile = fopen(argv[1], "r");
	if(readfile == NULL){
		cout << "Файл не найден!";
		return 0;
	}
	char t_find[64];
	cout << "Введите текст для поиска:";
	cin >> t_find;
	
	char buffer[1024];
	while(fscanf(readfile,"%s", buffer) != EOF){
		if(exists(t_find, buffer)){
			cout << buffer << endl;	
		}
	}
	
	return 0;
}
