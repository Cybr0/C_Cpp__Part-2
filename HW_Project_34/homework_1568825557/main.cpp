#include <iostream>
#include <string.h>
using namespace std;
struct string_list{
	char *str;
	string_list *prev;
	string_list *next;
};

string_list *add_item(string_list *c_item, char *str){
	
	string_list *new_item = new string_list(); //создаём новую структуру
	new_item->str = new char[strlen(str)];
	strcpy(new_item->str, str);
	new_item->next = 0;
	if(c_item){
		new_item->prev = c_item;
		c_item->next = new_item;
	}else{
		new_item->prev = 0;
	}
	return new_item;
}


string_list *read_file(const char *file_name){
	string_list *ret_val = 0;
	string_list *cur_list_item = 0;
	FILE *file;
	file = fopen(file_name, "r");
	if(file == NULL){
		std::cout<<"damn it!!!"<<std::endl;
	}else{
		char Readfile[64];
		
		while(fscanf(file, "%s", Readfile) != EOF){
			cur_list_item = add_item(cur_list_item, Readfile);
			memset(Readfile,0, 64);
			if(cur_list_item->prev == 0){
				ret_val = cur_list_item;
			}
		}
	}
	fclose(file);
	return ret_val;
}
	
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

void sort_array(string_list *text_list){
	//sorting linked list 
	//сортировка связанного списка
	string_list * x = text_list->next;
	string_list *copy_1 = text_list;
	string_list *copy_2 = x;
//	string_list *vvv = 0;
	int count = 0;
	string_list * proof_count = text_list;
	
	while(proof_count->next != 0){
		proof_count = proof_count->next;
		count++;
	}
	count +=1;
	int i = 0;
	while(i < count){
		do{
			if(is_greater(text_list->str, x->str)){
				char vvv[32];
				strcpy(vvv, text_list->str);
				strcpy(text_list->str, x->str);
				strcpy(x->str, vvv);
				text_list = text_list->next;
				x = x->next;
			}else{
				text_list = text_list->next;
				x = x->next;
			}
		}while (text_list->next != 0);
		text_list = copy_1;
		x = copy_2;
		i++;
	}
}





int main(int argc, char** argv) {

	string_list *list_item = read_file("input.txt");


	sort_array(list_item);
	while(list_item){
		std::cout <<list_item->str <<"\n";
		list_item = list_item->next;
	}

	
	return 0;
}
