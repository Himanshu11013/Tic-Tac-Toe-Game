for (int col = 0; col < SIZE; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == computer_marker) {
                return 10;
            } else if (board[0][col] == player_marker) {
                return -10;
            }
        }