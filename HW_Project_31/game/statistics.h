#include <string>
#include <stdio.h>
using namespace std;

const int size = 6;

struct statistic {
	char name[50];
	int score;
};

statistic players[size];
char ss = ',';
void add_player(char p_name[50], int p_time){
	FILE * file;
	file = fopen("stat//score.txt","a");
	if(file == NULL)
		cout << "Error" << endl;
	else
		fprintf(file,"\n%s %c %d",p_name, ss, p_time);
		
	fclose(file);
}

void check_file(){
	FILE * open_file;
	open_file = fopen("stat//score.txt", "r");
	if(open_file == NULL)
		cout << "Error" << endl;
	else{
		int i = 0;
			while(fscanf(open_file,"%s %c %d", players[i].name, &ss, &players[i].score) != EOF) {
			 i++;
			 if(i == 6)
			 	break;
			 }
	}
		
	fclose(open_file);
}

void selectSort_player() {
	int k;
	statistic x;
	
	for(int i = 0; i < size; i++){
		k = i;
		x = players[i];
		
		for (int j = i + 1; j < size; j++){
			if(players[j].score < x.score){
				k = j;
				x = players[j];
			}
		}
		players[k] = players[i];
		players[i] = x;
	}
}


void show_statistic(){
	cout << endl << endl << endl;
	for(int i = 0; i < 5; i ++){
		int p = players[i].score;
		int hour = p/3600;
		int min = (p % 3600)/60;
		int sec = (int)(p % 3600)%60;
		cout << "¹ "<< i+1 <<"  " << players[i].name << "\t" << "time: " << hour << ":" << min << ":" << sec << endl;
	}
}


void rewrite_stat(){
	FILE * re_file;
	re_file = fopen("stat//score.txt", "w");
	if(re_file == NULL)
		cout << "Error" << endl;
	else{
		for(int i = 0; i < (size-1); i++){
			fprintf(re_file,"%s %c %d\n",players[i].name, ss, players[i].score);
		}	
	}	
	fclose(re_file);
}
