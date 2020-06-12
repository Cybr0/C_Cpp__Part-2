#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
	
	file = fopen("test.dat", "w");
	if(file == NULL){
		std::cout << "file open error!\n";
	}else{
		for(int i = 0; i < 3; i++){
			fprintf(file, "%s;%f\n", players[i].name, players[i].time);
		}
		std::cout << "file created!\n";
		fclose(file);
	}
	
	player new_players[3];
	FILE *fileRead;
	fileRead = fopen("test.dat", "r");
	if(fileRead == NULL){
		std::cout << "file open error!\n";
	}else{
		char fileData[64];
		while(fgets(fileData, 64, fileRead) != NULL){
			std::cout << fileData;
			//
		}
		fclose(fileRead);
	}
	
	return 0;
}
