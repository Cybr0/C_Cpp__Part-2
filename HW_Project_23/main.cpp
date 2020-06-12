#include <iostream>

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

int main(int argc, char** argv) {
	
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
	while(true){
		system("cls");
		std::cout << "1. Start game\n"
				  << "2. Exit\n";
		int m_choise;
		std::cin >> m_choise;
		if(m_choise == 1){
			return mgs_start_menu;
		}else if(m_choise == 2){
			return mgs_exit_game;
		}
	}
	return mgs_main_menu;
}

main_game_state start_menu(){
	system("cls");
	std::cout << "Start game menu\n";
	return mgs_start_menu;
}
main_game_state gameplay(){
	return mgs_gameplay;
}

main_game_state endgame_menu(){
	return mgs_endgame;
}
