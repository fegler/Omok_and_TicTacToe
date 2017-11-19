#include <stdio.h>
#include <stdlib.h>
#define board_size 3

int board[board_size+1][board_size+1];

int main()
{
	int x,y,turn;
	int n = 9;

	while(1){
		scanf("%d %d", &x, &y);
		fflush(stdin);
		turn=1;
		scanf("%d",&turn);
		fflush(stdin);

		/*if(board[x][y] != 0) {
			printf("[%d]가 이미 돌이 놓인 자리에 돌을 두려고 하였습니다.\n",turn);
			fflush(stdout);
			break;
		}*/
		board[x][y] = turn;
//┏ ┃ ┓ ━ ┛ ┗ ┣ ┻ ┳ ┫ ╋ ○ ●
		//system("clear");
		for(int i=1;i<=5;++i){
			for(int j=1;j<=5;++j){
				if(i&1 && j&1){
					if(board[i/2+1][j/2+1]==1)
						fprintf(stderr,"○");
					else if(board[i/2+1][j/2+1]==2)
						fprintf(stderr,"●");
					else fprintf(stderr," ");
				}
				else if(!(i&1) && !(j&1))
					fprintf(stderr,"╋");
				else if(i&1) fprintf(stderr,"┃");
				else if(j&1) fprintf(stderr,"━");
			}
			fprintf(stderr,"\n");
		}

		if((board[1][1] == turn && board[1][2] == turn && board[1][3] == turn) ||
			(board[2][1] == turn && board[2][2] == turn && board[2][3] == turn) ||
			(board[3][1] == turn && board[3][2] == turn && board[3][3] == turn) ||
			(board[1][1] == turn && board[2][1] == turn && board[3][1] == turn) ||
			(board[1][2] == turn && board[2][2] == turn && board[3][2] == turn) ||
			(board[1][3] == turn && board[2][3] == turn && board[3][3] == turn) ||
			(board[1][1] == turn && board[2][2] == turn && board[3][3] == turn) ||
			(board[1][3] == turn && board[2][2] == turn && board[3][1] == turn)){
			printf("[%d](이)가 이겼습니다.\n",turn);
			fflush(stdout);
			break;
		}

		printf("draw\n");
		fflush(stdout);
	}
	return 0;
}