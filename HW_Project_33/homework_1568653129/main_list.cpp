#include <iostream> // стандартная библиотека ввода/вывода    // include - подключает библиотеки
#include <string.h> // библиотека для удобства использования строк и действиями над ними(прим. strlen())

struct string_list{ //тут создаем структуру(связанные списки)
	char *str;			// строка, в данном примере сюда записываются слова из файла
	string_list *prev; // указатель на предыдущию структуры
	string_list *next; // указатель на след. структуры
};

string_list *add_item(string_list *c_item, char *str){  //функция добавления айтема(строки в нов. структуру)
	string_list *new_item = new string_list(); //создаём новую структуру
	new_item.str = new char[strlen(str)];
	strcpy(new_item.str, str);  // это функция копирования одного элемента в другой(в первый параметр, копируется элемент со второго параметра)
	new_item.prev = c_item;
	new_item.next = nullptr;
	c_item.next = new_item;
	return new_item;
}
	
bool is_greater(char *first, char *second){  // эта функция проверки двух принимаемых строк(сравнивает по чару или по длине. Возвращает булево значение)
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
	for(int i = 0; i < min_size; i++){ // Сверяет каждый элемент массива,
		if(first[i] > second[i] ){ // с другим.
			return true;
		}else if (first[i] < second[i]){
			return false;
		}
	}
	return ret_val; // Если цикл For невыполнился вызываем ret_val
}

void sort_array(char **text_list, int size){ // сортировка двумерного массива(сортировка типа: Селект сорт)
	int k;
	char x[64];
	
	for(int i = 0; i < size; i++){
		k = i;
		strcpy(x , text_list[i]);
		
		for (int j = i + 1; j < size; j++){
			if(is_greater(x, text_list[j])){  //тут проверка с помощью функции is_greater
				k = j;
				strcpy(x , text_list[j]);
			}
		}
		strcpy(text_list[k] , text_list[i]);
		strcpy(text_list[i] , x);
	}
}

char ** add_string(char **text_list, int &size, char *str){ //функция добавления айтема(строки в двумерном массиве)
	size++;
	char ** ret_array = new char* [size];  // создание двумер. дин. массива
	
	for(int i = 0; i < size-1; i++){
		ret_array[i] = text_list[i];//
	}
	ret_array[size-1] = new char[strlen(str)];//
	strcpy(ret_array[size-1], str);
	if(text_list){
		delete [] text_list;   // удаление из памяти
	}
	return ret_array;  // возвращаемое значение типа: char **
}

char ** read_file(const char *file_name, int &count){ // чтение и запись в думерный массив(тут используется функция добавления строки в массив)
	count = 0;
	char **ret_list;
	FILE *file;
	file = fopen(file_name, "r");			// чтение из файла
	if(file == NULL){								// тут проверка на чтение файла
		std::cout<<"damn it!!!"<<std::endl;  
	}else{
		char Readfile[64];
		while(fscanf(file, "%s", Readfile) != EOF){
			ret_list = add_string(ret_list, count, Readfile);
			memset(Readfile,0, 64);  //Функция memset заполняет num байтов блока памяти, через указатель memptr. Код заполняемого символа передаётся в функцию через параметр val.
		}
	}
	return ret_list;
}

int main(int argc, char** argv) {  // это точка входа в программу
	char one[] = "abc";    // создается массив для проверки размера
	char two[] = "abcd";
	std::cout << sizeof(two) << std::endl;  // sizeof - определяет размер массива
	std::cout << strlen(two) << std::endl;  // strlen - определяет длину строки
	int word_count = 0;
//	int word_length = 64;
	char **word_list = read_file("input.txt", word_count);//new char* [word_count];  // вызов функции чтения из файла и последущее запись в массив
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
	
	sort_array(word_list, word_count);    // вызов функции сортировки
	
	for(int i = 0; i < word_count; i++){    
		std::cout << word_list[i]<<std::endl;   // вывод массива в консоль,в данном случае цикл служит для упрощенного вывода массива.
	}
	
	return 0;    // выход из программы, в данном случае return 0 означает что нет ошибок
}
