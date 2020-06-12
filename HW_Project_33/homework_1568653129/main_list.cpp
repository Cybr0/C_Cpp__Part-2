#include <iostream> // ����������� ���������� �����/������    // include - ���������� ����������
#include <string.h> // ���������� ��� �������� ������������� ����� � ���������� ��� ����(����. strlen())

struct string_list{ //��� ������� ���������(��������� ������)
	char *str;			// ������, � ������ ������� ���� ������������ ����� �� �����
	string_list *prev; // ��������� �� ���������� ���������
	string_list *next; // ��������� �� ����. ���������
};

string_list *add_item(string_list *c_item, char *str){  //������� ���������� ������(������ � ���. ���������)
	string_list *new_item = new string_list(); //������ ����� ���������
	new_item.str = new char[strlen(str)];
	strcpy(new_item.str, str);  // ��� ������� ����������� ������ �������� � ������(� ������ ��������, ���������� ������� �� ������� ���������)
	new_item.prev = c_item;
	new_item.next = nullptr;
	c_item.next = new_item;
	return new_item;
}
	
bool is_greater(char *first, char *second){  // ��� ������� �������� ���� ����������� �����(���������� �� ���� ��� �� �����. ���������� ������ ��������)
	int min_size;
	int size_f = strlen(first), size_s = strlen(second);

	bool ret_val;
	
	if(size_f > size_s){ // ������� ��������� ������� ����� ��������,
		min_size = size_s;//� ���������� �� � ���������� ret_val
		ret_val = true;
	}else{
		min_size = size_f;
		ret_val = false;
	}
	for(int i = 0; i < min_size; i++){ // ������� ������ ������� �������,
		if(first[i] > second[i] ){ // � ������.
			return true;
		}else if (first[i] < second[i]){
			return false;
		}
	}
	return ret_val; // ���� ���� For ������������ �������� ret_val
}

void sort_array(char **text_list, int size){ // ���������� ���������� �������(���������� ����: ������ ����)
	int k;
	char x[64];
	
	for(int i = 0; i < size; i++){
		k = i;
		strcpy(x , text_list[i]);
		
		for (int j = i + 1; j < size; j++){
			if(is_greater(x, text_list[j])){  //��� �������� � ������� ������� is_greater
				k = j;
				strcpy(x , text_list[j]);
			}
		}
		strcpy(text_list[k] , text_list[i]);
		strcpy(text_list[i] , x);
	}
}

char ** add_string(char **text_list, int &size, char *str){ //������� ���������� ������(������ � ��������� �������)
	size++;
	char ** ret_array = new char* [size];  // �������� ������. ���. �������
	
	for(int i = 0; i < size-1; i++){
		ret_array[i] = text_list[i];//
	}
	ret_array[size-1] = new char[strlen(str)];//
	strcpy(ret_array[size-1], str);
	if(text_list){
		delete [] text_list;   // �������� �� ������
	}
	return ret_array;  // ������������ �������� ����: char **
}

char ** read_file(const char *file_name, int &count){ // ������ � ������ � �������� ������(��� ������������ ������� ���������� ������ � ������)
	count = 0;
	char **ret_list;
	FILE *file;
	file = fopen(file_name, "r");			// ������ �� �����
	if(file == NULL){								// ��� �������� �� ������ �����
		std::cout<<"damn it!!!"<<std::endl;  
	}else{
		char Readfile[64];
		while(fscanf(file, "%s", Readfile) != EOF){
			ret_list = add_string(ret_list, count, Readfile);
			memset(Readfile,0, 64);  //������� memset ��������� num ������ ����� ������, ����� ��������� memptr. ��� ������������ ������� ��������� � ������� ����� �������� val.
		}
	}
	return ret_list;
}

int main(int argc, char** argv) {  // ��� ����� ����� � ���������
	char one[] = "abc";    // ��������� ������ ��� �������� �������
	char two[] = "abcd";
	std::cout << sizeof(two) << std::endl;  // sizeof - ���������� ������ �������
	std::cout << strlen(two) << std::endl;  // strlen - ���������� ����� ������
	int word_count = 0;
//	int word_length = 64;
	char **word_list = read_file("input.txt", word_count);//new char* [word_count];  // ����� ������� ������ �� ����� � ���������� ������ � ������
//	for(int i = 0; i < word_count; i++){
//		word_list[i] = new char[word_length];
//	}
//	strcpy(word_list[0], "How");
//	strcpy(word_list[1], "can");
//	strcpy(word_list[2], "I");
//	strcpy(word_list[3], "find");
//	strcpy(word_list[4], "out");
//	strcpy(word_list[5], "application");
//	strcpy(word_list[6], "written");
//	 	
//	if(is_greater(one, two)){
//		std::cout << "one is greater\n";
//	}else{
//		std::cout << "two is greater\n";
//	}
	
	sort_array(word_list, word_count);    // ����� ������� ����������
	
	for(int i = 0; i < word_count; i++){    
		std::cout << word_list[i]<<std::endl;   // ����� ������� � �������,� ������ ������ ���� ������ ��� ����������� ������ �������.
	}
	
	return 0;    // ����� �� ���������, � ������ ������ return 0 �������� ��� ��� ������
}
