#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define board_size 3

int board[board_size+1][board_size+1];

int main()
{
	srand((unsigned int)time(NULL));
	int enemy_x,enemy_y,my_x,my_y;

	while(1){
		scanf("%d %d", &enemy_x, &enemy_y);
		fflush(stdin);
		//if(enemy_x != 0 && enemy_x != 0)
		board[enemy_x][enemy_y] = 2;// 2: enemy player

		//decision my_x, my_y
		while(board[my_x = rand()%3+1][my_y = rand()%3+1]);
		board[my_x][my_y] = 1;// 1: player
		printf("%d %d\n", my_x, my_y);
		fflush(stdout);
	}
	return 0;
}