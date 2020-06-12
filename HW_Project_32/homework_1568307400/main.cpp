#include <iostream>
#include <string.h>

bool is_greater(char *first, char *second){
	int min_size;
	int size_f = strlen(first), size_s = strlen(second);

	bool ret_val;
	
	if(size_f > size_s){ // Функция проверяет размеры обоих массивов,
		min_size = size_s;//и записывает их в переменную ret_val
		ret_val = true;
	}else{
		min_size = size_f;
		ret_val = false;
	}
	for(int i = 0; i < min_size; i++){ // Сверяет каждый элемент массива,// с другим.
		char f = '\0';
		char s = '\0';
		if(64 < first[i] && first[i] < 91){
			f = first[i] + 32;
		}else{
			f = first[i];
		}
		
		if(64 < second[i] && second[i] < 91){
			s = second[i] + 32;
		}else{
			s = second[i];
		}
		
		if(f > s ){ 
			return true;
		}else if (f < s){
			return false;
		}
	}
	return ret_val; // Если цикл For невыполнился вызываем ret_val
}

void sort_array(char **text_list, int size){
	int k;
	char x[64];
	
	for(int i = 0; i < size; i++){
		k = i;
		strcpy(x , text_list[i]);
		
		for (int j = i + 1; j < size; j++){
			if(is_greater(x, text_list[j])){
				k = j;
				strcpy(x , text_list[j]);
			}
		}
		strcpy(text_list[k] , text_list[i]);
		strcpy(text_list[i] , x);
	}
}

char ** add_string(char **text_list, int &size, char *str){
	size++;
	char ** ret_array = new char* [size];
	
	for(int i = 0; i < size-1; i++){
		ret_array[i] = text_list[i];
	}
	ret_array[size-1] = new char[strlen(str)];
	strcpy(ret_array[size-1], str);
	return ret_array;
}

char ** read_file(const char *file_name, int &count){
	count = 0;
	char **ret_list;
	FILE *file;
	file = fopen(file_name, "r");
	if(file == NULL){
		std::cout<<"damn it!!!"<<std::endl;
	}else{
		char Readfile[64];
		while(fscanf(file, "%s", Readfile) != EOF){
			ret_list = add_string(ret_list, count, Readfile);
			memset(Readfile,0, 64);
		}
	}
	return ret_list;
}

int main(int argc, char** argv) {
	int word_count = 0;
	char **word_list = read_file("input.txt", word_count);//new char* [word_count];

	
	sort_array(word_list, word_count);
	
	for(int i = 0; i < word_count; i++){
		std::cout << word_list[i]<<std::endl;
	}
	
	return 0;
}
