#define blank_number 16
#include <chrono>
std::chrono::milliseconds ms{0};
std::chrono::duration<float, std::chrono::milliseconds::period> game_period = ms;
std::chrono::steady_clock::time_point start_time;

void clear_time(){
	game_period = ms;
}

void start_new_time(){
	start_time = std::chrono::steady_clock::now();
}

void stop_time(){
	game_period += (std::chrono::steady_clock::now() - start_time);
}

std::chrono::duration<float, std::chrono::milliseconds::period> get_total_time(){
	return game_period;
}

void move_right(int arr[4][4]){
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			if(arr[i][k]==blank_number){
				if(k == 0) return;
				arr[i][k]=arr[i][k-1];
                arr[i][k-1]=blank_number;
                return;
			}
		}
	}
}

void move_up(int arr[4][4]){
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			if(arr[i][k]==blank_number){
				if(i == 3)return;
				arr[i][k]=arr[i+1][k];
				arr[i+1][k]=blank_number;
				return;
			}
		}
	}
}

void move_down(int arr[4][4]){
	for(int i=0; i<4; i++){
			for(int k=0; k<4; k++){
				if(arr[i][k]==blank_number){
					if(i == 0)return;
					arr[i][k]=arr[i-1][k];
					arr[i-1][k]=blank_number;
					return;
			}
		}
	}
}

void move_left(int arr[4][4]){
	for(int i=0; i<4; i++){
		for(int k=0; k<4; k++){
			if(arr[i][k]==blank_number){
				if(k == 3)return;
				arr[i][k]=arr[i][k+1];
	            arr[i][k+1]=blank_number;
	            return;
			}
		}
	}
}

void new_game(int arr[4][4]){
	int b = 1;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			arr[i][j] = b;
			b++;
		}
	}
//	arr[3][2] = 16;  // Временно отключил рандом, чтобы быстрее проверить статистику
//	arr[3][3] = 15;
	srand(time(NULL));
	int rand_step = rand() % (200 - 500 + 1) + 500;
	int rand_size = rand() % 3;
	for(int i = 0; i < rand_step; i++){
		int rand_side_left = rand() % 12;
		for(int left = 0; left < rand_side_left; left++){
			move_left(arr);
		}
		
		int rand_side_up = rand() % 12;
		for(int up = 0; up < rand_side_up; up++){
			move_up(arr);
		}
		
		int rand_side_right = rand() % 12;
		for(int right = 0; right < rand_side_right; right++){
			move_right(arr);
		}
		int rand_side_down = rand() % 12;
		for(int down = 0; down < rand_side_down; down++){
			move_down(arr);
		}	
	}
	clear_time();
	start_new_time();
}



