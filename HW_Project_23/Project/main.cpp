#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
enum main_game_state{
	mgs_main_menu,
	mgs_start_menu,
	mgs_gameplay,
	mgs_endgame,
	mgs_exit_game
};
//functions
main_game_state main_menu();//shows and proccess main menu commands
main_game_state start_menu();//shows and proccess start menu commands
main_game_state gameplay();//main gameplay loop
main_game_state endgame_menu();//shows and proccess statistics

template <typename T>
void printArr(T arr[4][4], int x , int y);//print array for gameplay()
template <typename T>
void move_up(T arr[4][4], int x , int y);//button move_up for gameplay()
template <typename T>
void move_down(T arr[4][4], int x , int y);//button move_down for gameplay()
template <typename T>
void move_right(T arr[4][4], int x , int y);//button move_right for gameplay()
template <typename T>
void move_left(T arr[4][4], int x , int y);//button move_left for gameplay()
template <typename T>
void rand_game(T arr[4][4], int x , int y);//make random in gameplay()

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	
	main_game_state m_state = mgs_main_menu;
	
	while(true){
		switch(m_state){
			case mgs_main_menu:
				m_state = main_menu();
				break;
			case mgs_start_menu:
				m_state = start_menu();
				break;
			case mgs_gameplay:
				m_state = gameplay();
				break;
			case mgs_endgame:
				m_state = endgame_menu();
				break;
			case mgs_exit_game:
				return 0;
				break;
		}
	}
	return 0;
}


main_game_state main_menu(){
	int m_choise = 1;
	cout << "\n\n\n\n\n\n\t\t\t\t   " << "START" << endl;
	cout << "\n\t\t\t\t   " << "exit" << endl;
	while(true){
		int cmd = getch();
		if(cmd == 224){
			cmd = getch();
			switch (cmd){
				case 72:
					system("cls");
					m_choise++; 
					if(m_choise % 2 != 0){
						cout << "\n\n\n\n\n\n\t\t\t\t   " << "START" << endl;
						cout << "\n\t\t\t\t   " << "exit" << endl;
					}else if (m_choise % 2 == 0){
						cout << "\n\n\n\n\n\n\t\t\t\t   " << "start" << endl;
						cout << "\n\t\t\t\t   " << "EXIT" << endl;
					}
					break;
				
				case 80:
					system("cls");
					m_choise++; 
					if(m_choise % 2 != 0){
						cout << "\n\n\n\n\n\n\t\t\t\t   " << "START" << endl;
						cout << "\n\t\t\t\t   " << "exit" << endl;
					}else if (m_choise % 2 == 0){
						cout << "\n\n\n\n\n\n\t\t\t\t   " << "start" << endl;
						cout << "\n\t\t\t\t   " << "EXIT" << endl;
					}
					
					break;
			}
		}else if (cmd == 13){
			if(m_choise % 2 != 0){
				return mgs_gameplay;
			}else if(m_choise % 2 == 0){
				return mgs_exit_game;
			}
		}
	} 
	
	return mgs_gameplay;
}

main_game_state start_menu(){
	system("cls");
	std::cout << "Start game menu\n";
	return mgs_start_menu;
}
main_game_state gameplay(){
	system("cls");
	
	const int x = 4;
	const int y = 4;
	
	string arr [x][y] 
	{{"1","2","3","4"},
	{"5","6","7","8"},
	{"9","10","11","12"},
	{"13","14","15"," "}};
	rand_game(arr, x, y);
	printArr(arr, x , y);
	
	while(true){
		if(arr[0][0] == "1" && arr[0][1] == "2" && arr[0][2] == "3" && arr[0][3] == "4"
			 && arr[1][0] == "5" && arr[1][1] == "6" && arr[1][2] == "7" && arr[1][3] == "8"
			  && arr[2][0] == "9" && arr[2][1] == "10" && arr[2][2] == "11" && arr[2][3] == "12"
			   && arr[3][0] == "13" && arr[3][1] == "14" && arr[3][2] == "15" && arr[3][3] == " ")
		{
			return mgs_endgame;	
		}
		int t = getch();
		if (t = 224){
			t = getch();
			switch(t){
				case 72:
					move_up(arr,x,y);
					system("cls");
					printArr(arr, x , y);
					break;
					
				case 80:
					move_down(arr, x, y);
					system("cls");
					printArr(arr, x , y);
					break;
					
				case 77:
					move_right(arr,x,y);
					system("cls");
					printArr(arr, x , y);
					break;
					
				case 75:
					move_left(arr,x,y);
					system("cls");
					printArr(arr, x , y);
					break;
			}
		}	
	}
}

main_game_state endgame_menu(){
	system("cls");
	cout << "\n\n\n\n\n\n\t\t\t\t" << "Ñongratulation" << endl;
	cout << "\n\t\t\t\t    " << "exit" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	return mgs_exit_game;
}


template <typename T>
void printArr(T arr[4][4], int x , int y){
	cout << "\n\n\n\n\n\n\n";
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cout << "\t   " << arr[i][j] << "\t";
		}
		cout << "\n\n";
	}
	
}

template <typename T>
void move_up(T arr[4][4], int x , int y){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(arr[i][j] == " "){
				if(arr[0][0] == " " || arr[0][1] == " " || arr[0][2] == " " || arr[0][3] == " "){
					break;
				}else{	
					string move_up = arr[i][j];
					arr[i][j] = arr[i-1][j];
					arr[i-1][j] = move_up;
				}
					break;
			}
		}
	}	
}


template <typename T>
void move_down(T arr[4][4], int x , int y){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(arr[i][j] == " "){
				if(arr[3][0] == " " || arr[3][1] == " " || arr[3][2] == " " || arr[3][3] == " "){
					break;
				}else{
					string move_down = arr[i][j];
					arr[i][j] = arr[i+1][j];
					arr[i+1][j] = move_down;
				return;
				}
			}
		}
	}
}

template <typename T>
void move_right(T arr[4][4], int x , int y){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(arr[i][j] == " "){
				if(arr[0][3] == " " || arr[1][3] == " " || arr[2][3] == " " || arr[3][3] == " "){
					break;
				}else{
					string move_right = arr[i][j];
					arr[i][j] = arr[i][j+1];
					arr[i][j+1] = move_right;
					break;
				}
			}
		}
	}	
}
template <typename T>
void move_left(T arr[4][4], int x , int y){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(arr[i][j] == " "){
				if(arr[0][0] == " " || arr[1][0] == " " || arr[2][0] == " " || arr[3][0] == " "){
					break;
				}else{
					string move_left = arr[i][j];
					arr[i][j] = arr[i][j-1];
					arr[i][j-1] = move_left;
					break;
				}
			}
		}
	}
}


template <typename T>
void rand_game(T arr[4][4], int x , int y){
	//rand()%(left-right+1) + right;
	int rand_step = rand() % (200 - 500 + 1) + 500;
	for(int i = 0; i < rand_step; i++){
		int rand_side_left = rand() % 12;
		for(int left = 0; left < rand_side_left; left++){
			move_left(arr,x,y);
		}
		
		int rand_side_up = rand() % 12;
		for(int up = 0; up < rand_side_up; up++){
			move_up(arr,x,y);
		}
		
		int rand_side_right = rand() % 12;
		for(int right = 0; right < rand_side_right; right++){
			move_right(arr,x,y);
		}
		int rand_side_down = rand() % 12;
		for(int down = 0; down < rand_side_down; down++){
			move_down(arr,x,y);
		}	
	}
}
