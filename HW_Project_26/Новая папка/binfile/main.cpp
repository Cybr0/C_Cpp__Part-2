#include <iostream>
#include <stdio.h>
struct player{
	char name[10];
	float time;
};

int main(int argc, char** argv) {
	
	player players[3];
	
	sprintf(players[0].name, "player1");
	players[0].time = 1000;
	
	sprintf(players[1].name, "player2");
	players[1].time = 2000;
	
	sprintf(players[2].name, "player3");
	players[2].time = 3000;
	
	
	FILE *file;
	
	file = fopen("test.my", "wb");
	if(file == NULL){
		std::cout << "file open error!\n";
	}else{
		fwrite(players, sizeof(player), 3, file);
		std::cout << "file created!\n";
		fclose(file);
	}
	
	player new_players[3];
	FILE *fileRead;
	fileRead = fopen("test.my", "r");
	if(fileRead == NULL){
		std::cout << "file open error!\n";
	}else{
		char fileData[64];
		fread(new_players, sizeof(player), 3, fileRead);
		fclose(fileRead);
	}
	for(int i = 0; i < 3; i++){
		std::cout<< new_players[i].name<<" "<<new_players[i].time<<"\n";
	}
	
	return 0;
}
