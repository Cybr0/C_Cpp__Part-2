#include <iostream>
#include <conio.h>
#include <time.h>
#include "move_functions.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
enum main_game_state{
	mgs_main_menu,
	mgs_gameplay,
	mgs_endgame,
	mgs_exit_game
};

enum pause_menu_state{
	pms_resume_game,
	pms_new_game,
	pms_main_menu
};

enum game_key_actions{
	gka_undefined,
	gka_escape,
	gka_up,
	gka_down,
	gka_left,
	gka_right
};

//functions
main_game_state main_menu();//shows and proccess main menu commands
main_game_state gameplay();//main gameplay loop
void show_game_board(int game_board[4][4]);
bool is_completed(int game_board[4][4]);
game_key_actions get_key_pressed();
main_game_state endgame_menu();//shows and proccess statistics
pause_menu_state pause_menu();


int main(int argc, char** argv) {
	
	main_game_state m_state = mgs_main_menu;
	while(true){
		switch(m_state){
			case mgs_main_menu:
				m_state = main_menu();
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
	while(true){
		system("cls");
		std::cout << "1. Start game\n"
				  << "2. Exit\n";
		int m_choise;
		std::cin >> m_choise;
		if(m_choise == 1){
			return mgs_gameplay;
		}else if(m_choise == 2){
			return mgs_exit_game;
		}
	}
	return mgs_main_menu;
}

void show_game_board(int game_board[4][4]){
	system("cls");
	std::cout << "Game board\n\n";
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(game_board[i][j] == 16){
				std::cout << '\t' << " ";
			}else{
				std::cout << '\t' << game_board[i][j];
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n\n";
	std::cout << "pause - esc; ";
}

game_key_actions get_key_pressed(){
	int a=getch();
	if(a == 27){
		return gka_escape;
	}
	if(a == 224){
		a = getch();
		switch(a){
 		case 72:
 			return gka_up;
 		case 80:
 			return gka_down;
 		case 77:
 			return gka_right;
 		case 75:
 			return gka_left;
		}
	}
	return gka_undefined;
}

main_game_state gameplay(){
	int game_board[4][4];
	
	new_game(game_board);
	while(true){
		show_game_board(game_board);
		switch(get_key_pressed()){
			case gka_escape:
				switch(pause_menu()){
					case pms_resume_game:
						break;
					case pms_new_game:
						new_game(game_board);
						break;
					case pms_main_menu:
						return mgs_main_menu;
						break;
				}
				break;
			case gka_up:
				move_up(game_board);
				break;
			case gka_down:
				move_down(game_board);
				break;
			case gka_left:
				move_left(game_board);
				break;
			case gka_right:
				move_right(game_board);
				break;
			default:
				break;
		}
		if(is_completed(game_board)){
			//Statistics
		}
	}
	return mgs_gameplay;
}

bool is_completed(int game_board[4][4]){
	int b = 1;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(game_board[i][j] != b){
				return false;
			}
			b++;
		}
	}
	return true;
}

pause_menu_state pause_menu(){
	system("cls");
	std::cout<<"\t 1. Resume Game\n";
	std::cout<<"\t 2. Start New Game\n";
	std::cout<<"\t 3. Back To Main Menu\n";
	int ch;
	std::cin >> ch;
	
	switch(ch){ 
		case 1://resume
			return pms_resume_game;
		case 2://new game
			return pms_new_game;
		case 3://main menu
			return pms_main_menu;
	}
	return pms_resume_game;
}

main_game_state endgame_menu(){
	return mgs_endgame;
}

