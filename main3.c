#include <stdio.h>

int main() {
    char board[3][3];
    int player = 1; 
    int row, col;
    char mark;

   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';

    while (1) {
        
        printf("\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %c ", board[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) {
                printf("---|---|---\n");
            }
        }

        mark = (player == 1) ? 'X' : 'O';
        printf("Player %d (%c), enter your move (row and column): ", player, mark);
        scanf("%d %d", &row, &col);

       
        row--;
        col--;

       
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        
        board[row][col] = mark;

       
        int winner = 0;
        for (int i = 0; i < 3; i++) {
            
            if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
                (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
                winner = 1;
                break;
            }
        }
       
        if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
            (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
            winner = 1;
        }

       
        if (winner) {
            printf("Player %d (%c) wins!\n", player, mark);
            break;
        }

      
        int draw = 1;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ') {
                    draw = 0; 
                    break;
                }

        if (draw) {
            printf("It's a draw!\n");
            break;
        }

        
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
