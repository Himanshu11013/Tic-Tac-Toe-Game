//g++ tictactoe.cpp -o tictactoe -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system && ./tictactoe
// #include <SFML/Graphics.hpp>
// #include <iostream>

// const int SIZE = 3;
// char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
// char player_marker = 'X';
// char computer_marker = 'O';

// sf::RectangleShape createLine(float x1, float y1, float x2, float y2) {
//     sf::RectangleShape line;
//     line.setSize(sf::Vector2f(std::hypot(x2 - x1, y2 - y1), 5));
//     line.setPosition(x1, y1);
//     line.setFillColor(sf::Color::Black);
//     line.setRotation(atan2(y2 - y1, x2 - x1) * 180 / 3.14159265);
//     return line;
// }

// void drawBoard(sf::RenderWindow &window) {
//     window.clear(sf::Color::White);

//     // Draw grid
//     window.draw(createLine(100, 0, 100, 300));
//     window.draw(createLine(200, 0, 200, 300));
//     window.draw(createLine(0, 100, 300, 100));
//     window.draw(createLine(0, 200, 300, 200));

//     // Draw markers
//     sf::Font font;
//     if (!font.loadFromFile("arial.ttf")) {
//         std::cerr << "Error loading font\n";
//         return;
//     }

//     for (int i = 0; i < SIZE; ++i) {
//         for (int j = 0; j < SIZE; ++j) {
//             sf::Text text;
//             text.setFont(font);
//             text.setString(board[i][j]);
//             text.setCharacterSize(50);
//             text.setFillColor(sf::Color::Black);
//             text.setPosition(j * 100 + 25, i * 100 + 10);
//             window.draw(text);
//         }
//     }

//     window.display();
// }

// bool placeMarker(int slot, char marker) {
//     int row = (slot - 1) / SIZE;
//     int col = (slot - 1) % SIZE;

//     if (board[row][col] != 'X' && board[row][col] != 'O') {
//         board[row][col] = marker;
//         return true;
//     } else {
//         return false;
//     }
// }

// int winner() {
//     for (int i = 0; i < SIZE; i++) {
//         if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
//             return board[i][0] == player_marker ? 1 : 2;
//         }
//     }
//     for (int i = 0; i < SIZE; i++) {
//         if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
//             return board[0][i] == player_marker ? 1 : 2;
//         }
//     }
//     if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
//         return board[0][0] == player_marker ? 1 : 2;
//     }
//     if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
//         return board[0][2] == player_marker ? 1 : 2;
//     }
//     return 0;
// }

// void computerMove() {
//     int slot;
//     srand(time(0));
//     while (true) {
//         slot = rand() % 9 + 1;
//         if (placeMarker(slot, computer_marker)) {
//             break;
//         }
//     }
// }

// void game(sf::RenderWindow &window) {
//     int player_won = 0;
//     for (int i = 0; i < 9; i++) {
//         drawBoard(window);

//         if (i % 2 == 0) {  // Player's turn
//             int slot;
//             std::cout << "Your turn. Enter your slot: ";
//             std::cin >> slot;

//             if (slot < 1 || slot > 9) {
//                 std::cout << "Invalid slot! Try again.\n";
//                 i--;
//                 continue;
//             }

//             if (!placeMarker(slot, player_marker)) {
//                 std::cout << "That slot is occupied! Try again.\n";
//                 i--;
//                 continue;
//             }
//         } else {  // Computer's turn
//             computerMove();
//         }

//         drawBoard(window);
//         player_won = winner();

//         if (player_won == 1) {
//             std::cout << "You won! Congratulations!\n";
//             break;
//         } else if (player_won == 2) {
//             std::cout << "Computer won! Better luck next time.\n";
//             break;
//         }
//     }

//     if (player_won == 0) {
//         std::cout << "It's a tie!\n";
//     }
// }

// int main() {
//     sf::RenderWindow window(sf::VideoMode(300, 300), "Tic Tac Toe");

//     game(window);

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//     }

//     return 0;
// }
// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// const int SIZE = 3;
// char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
// char player_marker = 'X';
// char computer_marker = 'O';

// sf::RectangleShape createLine(float x1, float y1, float x2, float y2) {
//     sf::RectangleShape line;
//     line.setSize(sf::Vector2f(std::hypot(x2 - x1, y2 - y1), 5));
//     line.setPosition(x1, y1);
//     line.setFillColor(sf::Color::Black);
//     line.setRotation(atan2(y2 - y1, x2 - x1) * 180 / 3.14159265);
//     return line;
// }

// void drawBoard(sf::RenderWindow &window, sf::Font &font) {
//     window.clear(sf::Color::White);

//     // Draw grid
//     window.draw(createLine(100, 0, 100, 300));
//     window.draw(createLine(200, 0, 200, 300));
//     window.draw(createLine(0, 100, 300, 100));
//     window.draw(createLine(0, 200, 300, 200));

//     // Draw markers
//     for (int i = 0; i < SIZE; ++i) {
//         for (int j = 0; j < SIZE; ++j) {
//             sf::Text text;
//             text.setFont(font);
//             text.setString(board[i][j]);
//             text.setCharacterSize(50);
//             if (board[i][j] == player_marker) {
//                 text.setFillColor(sf::Color::Blue);
//             } else if (board[i][j] == computer_marker) {
//                 text.setFillColor(sf::Color::Red);
//             } else {
//                 text.setFillColor(sf::Color::Black);
//             }
//             text.setPosition(j * 100 + 25, i * 100 + 10);
//             window.draw(text);
//         }
//     }

//     window.display();
// }

// bool placeMarker(int slot, char marker) {
//     int row = (slot - 1) / SIZE;
//     int col = (slot - 1) % SIZE;

//     if (board[row][col] != 'X' && board[row][col] != 'O') {
//         board[row][col] = marker;
//         return true;
//     } else {
//         return false;
//     }
// }

// int winner() {
//     for (int i = 0; i < SIZE; i++) {
//         if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
//             return board[i][0] == player_marker ? 1 : 2;
//         }
//     }
//     for (int i = 0; i < SIZE; i++) {
//         if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
//             return board[0][i] == player_marker ? 1 : 2;
//         }
//     }
//     if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
//         return board[0][0] == player_marker ? 1 : 2;
//     }
//     if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
//         return board[0][2] == player_marker ? 1 : 2;
//     }
//     return 0;
// }

// void computerMove() {
//     int slot;
//     srand(time(0));
//     while (true) {
//         slot = rand() % 9 + 1;
//         if (placeMarker(slot, computer_marker)) {
//             break;
//         }
//     }
// }

// void game(sf::RenderWindow &window, sf::Font &font) {
//     int player_won = 0;
//     for (int i = 0; i < 9; i++) {
//         drawBoard(window, font);

//         if (i % 2 == 0) {  // Player's turn
//             int slot;
//             std::cout << "Your turn. Enter your slot: ";
//             std::cin >> slot;

//             if (slot < 1 || slot > 9) {
//                 std::cout << "Invalid slot! Try again.\n";
//                 i--;
//                 continue;
//             }

//             if (!placeMarker(slot, player_marker)) {
//                 std::cout << "That slot is occupied! Try again.\n";
//                 i--;
//                 continue;
//             }
//         } else {  // Computer's turn
//             computerMove();
//         }

//         drawBoard(window, font);
//         player_won = winner();

//         if (player_won == 1) {
//             std::cout << "You won! Congratulations!\n";
//             break;
//         } else if (player_won == 2) {
//             std::cout << "Computer won! Better luck next time.\n";
//             break;
//         }
//     }

//     if (player_won == 0) {
//         std::cout << "It's a tie!\n";
//     }
// }

// int main() {
//     sf::RenderWindow window(sf::VideoMode(300, 300), "Tic Tac Toe");
//     sf::Font font;
//     if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) { // Updated path
//         std::cerr << "Error loading font\n";
//         return -1;
//     }

//     game(window, font);

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }//     }

//     return 0;
// }
// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// const int SIZE = 3;
// char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
// char player_marker = 'X';
// char computer_marker = 'O';

// sf::RectangleShape createLine(float x1, float y1, float x2, float y2) {
//     sf::RectangleShape line;
//     line.setSize(sf::Vector2f(std::hypot(x2 - x1, y2 - y1), 5));
//     line.setPosition(x1, y1);
//     line.setFillColor(sf::Color::Black);
//     line.setRotation(atan2(y2 - y1, x2 - x1) * 180 / 3.14159265);
//     return line;
// }

// void drawBoard(sf::RenderWindow &window, sf::Font &font) {
//     window.clear(sf::Color::White);

//     // Draw grid
//     window.draw(createLine(100, 0, 100, 300));
//     window.draw(createLine(200, 0, 200, 300));
//     window.draw(createLine(0, 100, 300, 100));
//     window.draw(createLine(0, 200, 300, 200));

//     // Draw markers
//     for (int i = 0; i < SIZE; ++i) {
//         for (int j = 0; j < SIZE; ++j) {
//             sf::Text text;
//             text.setFont(font);
//             text.setString(board[i][j]);
//             text.setCharacterSize(50);
//             if (board[i][j] == player_marker) {
//                 text.setFillColor(sf::Color::Blue);
//             } else if (board[i][j] == computer_marker) {
//                 text.setFillColor(sf::Color::Red);
//             } else {
//                 text.setFillColor(sf::Color::Black);
//             }
//             text.setPosition(j * 100 + 25, i * 100 + 10);
//             window.draw(text);
//         }
//     }

//     window.display();
// }

// bool placeMarker(int x, int y, char marker) {
//     int row = y / 100;
//     int col = x / 100;

//     if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
//         return false;
//     }

//     if (board[row][col] != 'X' && board[row][col] != 'O') {
//         board[row][col] = marker;
//         return true;
//     } else {
//         return false;
//     }
// }

// int winner() {
//     for (int i = 0; i < SIZE; i++) {
//         if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
//             return board[i][0] == player_marker ? 1 : 2;
//         }
//     }
//     for (int i = 0; i < SIZE; i++) {
//         if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
//             return board[0][i] == player_marker ? 1 : 2;
//         }
//     }
//     if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
//         return board[0][0] == player_marker ? 1 : 2;
//     }
//     if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
//         return board[0][2] == player_marker ? 1 : 2;
//     }
//     return 0;
// }

// void computerMove() {
//     int slot;
//     srand(time(0));
//     while (true) {
//         slot = rand() % 9 + 1;
//         int row = (slot - 1) / SIZE;
//         int col = (slot - 1) % SIZE;
//         if (board[row][col] != 'X' && board[row][col] != 'O') {
//             board[row][col] = computer_marker;
//             break;
//         }
//     }
// }

// void game(sf::RenderWindow &window, sf::Font &font) {
//     int player_won = 0;
//     bool playerTurn = true;

//     while (player_won == 0) {
//         drawBoard(window, font);

//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//                 return;
//             }
//             if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
//                 sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//                 int x = mousePos.x;
//                 int y = mousePos.y;
//                 if (playerTurn) {  // Player's turn
//                     if (placeMarker(x, y, player_marker)) {
//                         playerTurn = false;
//                     }
//                 }
//             }
//         }

//         if (!playerTurn) {  // Computer's turn
//             computerMove();
//             playerTurn = true;
//         }

//         player_won = winner();
//     }

//     drawBoard(window, font);

//     if (player_won == 1) {
//         std::cout << "You won! Congratulations!\n";
//     } else if (player_won == 2) {
//         std::cout << "Computer won! Better luck next time.\n";
//     } else {
//         std::cout << "It's a tie!\n";
//     }
// }

// int main() {
//     sf::RenderWindow window(sf::VideoMode(300, 300), "Tic Tac Toe");
//     sf::Font font;
//     if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) { // Update path as necessary
//         std::cerr << "Error loading font\n";
//         return -1;
//     }

//     game(window, font);

//     return 0;
// }
// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <vector>

// const int SIZE = 3;
// char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
// char player_marker = 'X';
// char computer_marker = 'O';

// sf::RectangleShape createLine(float x1, float y1, float x2, float y2) {
//     sf::RectangleShape line;
//     line.setSize(sf::Vector2f(std::hypot(x2 - x1, y2 - y1), 5));
//     line.setPosition(x1, y1);
//     line.setFillColor(sf::Color::Black);
//     line.setRotation(atan2(y2 - y1, x2 - x1) * 180 / 3.14159265);
//     return line;
// }

// void drawBoard(sf::RenderWindow &window, sf::Font &font) {
//     window.clear(sf::Color::White);

//     // Draw grid
//     window.draw(createLine(100, 0, 100, 300));
//     window.draw(createLine(200, 0, 200, 300));
//     window.draw(createLine(0, 100, 300, 100));
//     window.draw(createLine(0, 200, 300, 200));

//     // Draw markers
//     for (int i = 0; i < SIZE; ++i) {
//         for (int j = 0; j < SIZE; ++j) {
//             sf::Text text;
//             text.setFont(font);
//             text.setString(board[i][j] == ' ' ? "" : std::string(1, board[i][j]));
//             text.setCharacterSize(50);
//             if (board[i][j] == player_marker) {
//                 text.setFillColor(sf::Color::Blue);
//             } else if (board[i][j] == computer_marker) {
//                 text.setFillColor(sf::Color::Red);
//             } else {
//                 text.setFillColor(sf::Color::Black);
//             }
//             text.setPosition(j * 100 + 25, i * 100 + 10);
//             window.draw(text);
//         }
//     }

//     window.display();
// }

// bool isMovesLeft() {
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             if (board[i][j] == ' ') {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int evaluate(char board[SIZE][SIZE]) {
//     // Check rows for a win
//     for (int row = 0; row < SIZE; row++) {
//         if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
//             if (board[row][0] == computer_marker) {
//                 return 10;
//             } else if (board[row][0] == player_marker) {
//                 return -10;
//             }
//         }
//     }

//     // Check columns for a win
//     for (int col = 0; col < SIZE; col++) {
//         if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
//             if (board[0][col] == computer_marker) {
//                 return 10;
//             } else if (board[0][col] == player_marker) {
//                 return -10;
//             }
//         }
//     }

//     // Check diagonals for a win
//     if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
//         if (board[0][0] == computer_marker) {
//             return 10;
//         } else if (board[0][0] == player_marker) {
//             return -10;
//         }
//     }
//     if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
//         if (board[0][2] == computer_marker) {
//             return 10;
//         } else if (board[0][2] == player_marker) {
//             return -10;
//         }
//     }

//     // No winner
//     return 0;
// }

// int minimax(char board[SIZE][SIZE], int depth, bool isMax) {
//     int score = evaluate(board);

//     // If Maximizer has won the game
//     if (score == 10) {
//         return score - depth;
//     }

//     // If Minimizer has won the game
//     if (score == -10) {
//         return score + depth;
//     }

//     // If there are no more moves and no winner, it's a tie
//     if (!isMovesLeft()) {
//         return 0;
//     }

//     // If this is maximizer's move
//     if (isMax) {
//         int best = -1000;

//         // Traverse all cells
//         for (int i = 0; i < SIZE; i++) {
//             for (int j = 0; j < SIZE; j++) {
//                 // Check if cell is empty
//                 if (board[i][j] == ' ') {
//                     // Make the move
//                     board[i][j] = computer_marker;

//                     // Call minimax recursively and choose the maximum value
//                     best = std::max(best, minimax(board, depth + 1, !isMax));

//                     // Undo the move
//                     board[i][j] = ' ';
//                 }
//             }
//         }
//         return best;
//     } else {
//         int best = 1000;

//         // Traverse all cells
//         for (int i = 0; i < SIZE; i++) {
//             for (int j = 0; j < SIZE; j++) {
//                 // Check if cell is empty
//                 if (board[i][j] == ' ') {
//                     // Make the move
//                     board[i][j] = player_marker;

//                     // Call minimax recursively and choose the minimum value
//                     best = std::min(best, minimax(board, depth + 1, !isMax));

//                     // Undo the move
//                     board[i][j] = ' ';
//                 }
//             }
//         }
//         return best;
//     }
// }

// void computerMove() {
//     int bestVal = -1000;
//     int bestMoveRow = -1;
//     int bestMoveCol = -1;

//     // Traverse all cells, evaluate minimax function for all empty cells
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             // Check if cell is empty
//             if (board[i][j] == ' ') {
//                 // Make the move
//                 board[i][j] = computer_marker;

//                 // Compute evaluation function for this move
//                 int moveVal = minimax(board, 0, false);

//                 // Undo the move
//                 board[i][j] = ' ';

//                 // If the value of the current move is more than the best value, update best
//                 if (moveVal > bestVal) {
//                     bestMoveRow = i;
//                     bestMoveCol = j;
//                     bestVal = moveVal;
//                 }
//             }
//         }
//     }

//     // Make the best move
//     board[bestMoveRow][bestMoveCol] = computer_marker;
// }

// bool placeMarker(int x, int y, char marker) {
//     int col = x / 100;
//     int row = y / 100;

//     if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
//         board[row][col] = marker;
//         return true;
//     }

//     return false;
// }

// void game(sf::RenderWindow &window, sf::Font &font) {
//     int player_won = 0;
//     bool playerTurn = true;

//     while (player_won == 0) {
//         drawBoard(window, font);

//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//                 return;
//             }
//             if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
//                 sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//                 int x = mousePos.x;
//                 int y = mousePos.y;
//                 if (playerTurn) {  // Player's turn
//                     if (placeMarker(x, y, player_marker)) {
//                         playerTurn = false;
//                     }
//                 }
//             }
//         }

//         if (!playerTurn) {  // Computer's turn
//             computerMove();
//             playerTurn = true;
//         }

//         player_won = evaluate(board);
//     }

//     drawBoard(window, font);

//     if (player_won == 10) {
//         std::cout << "Computer won! Better luck next time.\n";
//     } else if (player_won == -10) {
//         std::cout << "You won! Congratulations!\n";
//     } else {
//         std::cout << "It's a tie!\n";
//     }
// }

// int main() {
//     sf::RenderWindow window(sf::VideoMode(300, 300), "Tic Tac Toe");
//     sf::Font font;
//     if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) {
//         std::cerr << "Error loading font\n";
//         return -1;
//     }

//     game(window, font);

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }
//         }
//     }

//     return 0;
// }
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int SIZE = 3;
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char player_marker = 'X';
char computer_marker = 'O';

int playerWins = 0;
int computerWins = 0;

sf::RectangleShape createLine(float x1, float y1, float x2, float y2) {
    sf::RectangleShape line;
    line.setSize(sf::Vector2f(std::hypot(x2 - x1, y2 - y1), 5));
    line.setPosition(x1, y1);
    line.setFillColor(sf::Color::Black);
    line.setRotation(atan2(y2 - y1, x2 - x1) * 180 / 3.14159265);
    return line;
}

void drawBoard(sf::RenderWindow &window, sf::Font &font) {
    window.clear(sf::Color::White);

    // Draw grid
    window.draw(createLine(100, 0, 100, 300));
    window.draw(createLine(200, 0, 200, 300));
    window.draw(createLine(0, 100, 300, 100));
    window.draw(createLine(0, 200, 300, 200));

    // Draw markers
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            sf::Text text;
            text.setFont(font);
            text.setString(board[i][j] == ' ' ? "" : std::string(1, board[i][j]));
            text.setCharacterSize(50);
            if (board[i][j] == player_marker) {
                text.setFillColor(sf::Color::Blue);
            } else if (board[i][j] == computer_marker) {
                text.setFillColor(sf::Color::Red);
            } else {
                text.setFillColor(sf::Color::Black);
            }
            text.setPosition(j * 100 + 25, i * 100 + 10);
            window.draw(text);
        }
    }

    // Display win/loss counters
    sf::Text counterText;
    counterText.setFont(font);
    counterText.setCharacterSize(20);
    counterText.setFillColor(sf::Color::Black);
    counterText.setPosition(10, 310);
    counterText.setString("Wins: " + std::to_string(playerWins) + " Losses: " + std::to_string(computerWins));
    window.draw(counterText);

    window.display();
}

bool isMovesLeft() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return true;
            }
        }
    }
    return false;
}

int evaluate(char board[SIZE][SIZE]) {
    // Check rows for a win
    for (int row = 0; row < SIZE; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == computer_marker) {
                return 10;
            } else if (board[row][0] == player_marker) {
                return -10;
            }
        }
    }

    // Check columns for a win
    for (int col = 0; col < SIZE; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == computer_marker) {
                return 10;
            } else if (board[0][col] == player_marker) {
                return -10;
            }
        }
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == computer_marker) {
            return 10;
        } else if (board[0][0] == player_marker) {
            return -10;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == computer_marker) {
            return 10;
        } else if (board[0][2] == player_marker) {
            return -10;
        }
    }

    // No winner
    return 0;
}

int minimax(char board[SIZE][SIZE], int depth, bool isMax) {
    int score = evaluate(board);

    // If Maximizer has won the game
    if (score == 10) {
        return score - depth;
    }

    // If Minimizer has won the game
    if (score == -10) {
        return score + depth;
    }

    // If there are no more moves and no winner, it's a tie
    if (!isMovesLeft()) {
        return 0;
    }

    // If this is maximizer's move
    if (isMax) {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // Check if cell is empty
                if (board[i][j] == ' ') {
                    // Make the move
                    board[i][j] = computer_marker;

                    // Call minimax recursively and choose the maximum value
                    best = std::max(best, minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // Check if cell is empty
                if (board[i][j] == ' ') {
                    // Make the move
                    board[i][j] = player_marker;

                    // Call minimax recursively and choose the minimum value
                    best = std::min(best, minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

void computerMove() {
    int bestVal = -1000;
    int bestMoveRow = -1;
    int bestMoveCol = -1;

    // Traverse all cells, evaluate minimax function for all empty cells
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Check if cell is empty
            if (board[i][j] == ' ') {
                // Make the move
                board[i][j] = computer_marker;

                // Compute evaluation function for this move
                int moveVal = minimax(board, 0, false);

                // Undo the move
                board[i][j] = ' ';

                // If the value of the current move is more than the best value, update best
                if (moveVal > bestVal) {
                    bestMoveRow = i;
                    bestMoveCol = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    // Make the best move
    board[bestMoveRow][bestMoveCol] = computer_marker;
}

bool placeMarker(int x, int y, char marker) {
    int col = x / 100;
    int row = y / 100;

    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = marker;
        return true;
    }

    return false;
}

void game(sf::RenderWindow &window, sf::Font &font) {
    int player_won = 0;
    bool playerTurn = true;

    while (player_won == 0) {
        drawBoard(window, font);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int x = mousePos.x;
                int y = mousePos.y;
                if (playerTurn) {  // Player's turn
                    if (placeMarker(x, y, player_marker)) {
                        playerTurn = false;
                    }
                }
            }
        }

        if (!playerTurn) {  // Computer's turn
            computerMove();
            playerTurn = true;
        }

        player_won = evaluate(board);
    }

    drawBoard(window, font);

    if (player_won == 10) {
        std::cout << "Computer won! Better luck next time.\n";
        computerWins++;
    } else if (player_won == -10) {
        std::cout << "You won! Congratulations!\n";
        playerWins++;
    } else {
        std::cout << "It's a tie!\n";
    }

    // Prompt to play again
    sf::Text playAgainText;
    playAgainText.setFont(font);
    playAgainText.setCharacterSize(20);
    playAgainText.setFillColor(sf::Color::Black);
    playAgainText.setPosition(80, 350);
    playAgainText.setString("Click here to play again!");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int x = mousePos.x;
                int y = mousePos.y;
                if (x >= 80 && x <= 220 && y >= 350 && y <= 370) {
                    // Reset the game
                    for (int i = 0; i < SIZE; ++i) {
                        for (int j = 0; j < SIZE; ++j) {
                            board[i][j] = ' ';
                        }
                    }
                    game(window, font);
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(playAgainText);
        window.display();
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 400), "Tic Tac Toe");
    sf::Font font;
    if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    game(window, font);

    return 0;
}



// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <vector>

// const int SIZE = 3;
// char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
// char player_marker = 'X';
// char computer_marker = 'O';

// int playerWins = 0;
// int computerWins = 0;

// sf::RectangleShape createLine(float x1, float y1, float x2, float y2) {
//     sf::RectangleShape line;
//     line.setSize(sf::Vector2f(std::hypot(x2 - x1, y2 - y1), 5));
//     line.setPosition(x1, y1);
//     line.setFillColor(sf::Color::Black);
//     line.setRotation(atan2(y2 - y1, x2 - x1) * 180 / 3.14159265);
//     return line;
// }

// void drawBoard(sf::RenderWindow &window, sf::Font &font) {
//     window.clear(sf::Color::White);

//     // Draw grid
//     window.draw(createLine(100, 0, 100, 300));
//     window.draw(createLine(200, 0, 200, 300));
//     window.draw(createLine(0, 100, 300, 100));
//     window.draw(createLine(0, 200, 300, 200));

//     // Draw markers
//     for (int i = 0; i < SIZE; ++i) {
//         for (int j = 0; j < SIZE; ++j) {
//             sf::Text text;
//             text.setFont(font);
//             text.setString(board[i][j] == ' ' ? "" : std::string(1, board[i][j]));
//             text.setCharacterSize(50);
//             if (board[i][j] == player_marker) {
//                 text.setFillColor(sf::Color::Blue);
//             } else if (board[i][j] == computer_marker) {
//                 text.setFillColor(sf::Color::Red);
//             } else {
//                 text.setFillColor(sf::Color::Black);
//             }
//             text.setPosition(j * 100 + 25, i * 100 + 10);
//             window.draw(text);
//         }
//     }

//     // Display win/loss counters
//     sf::Text counterText;
//     counterText.setFont(font);
//     counterText.setCharacterSize(20);
//     counterText.setFillColor(sf::Color::Black);
//     counterText.setPosition(10, 310);
//     counterText.setString("Wins: " + std::to_string(playerWins) + " Losses: " + std::to_string(computerWins));
//     window.draw(counterText);

//     window.display();
// }

// bool isMovesLeft() {
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             if (board[i][j] == ' ') {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int evaluate(char board[SIZE][SIZE]) {
//     // Check rows for a win
//     for (int row = 0; row < SIZE; row++) {
//         if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
//             if (board[row][0] == computer_marker) {
//                 return 10;
//             } else if (board[row][0] == player_marker) {
//                 return -10;
//             }
//         }
//     }

//     // Check columns for a win
//     for (int col = 0; col < SIZE; col++) {
//         if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
//             if (board[0][col] == computer_marker) {
//                 return 10;
//             } else if (board[0][col] == player_marker) {
//                 return -10;
//             }
//         }
//     }

//     // Check diagonals for a win
//     if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
//         if (board[0][0] == computer_marker) {
//             return 10;
//         } else if (board[0][0] == player_marker) {
//             return -10;
//         }
//     }
//     if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
//         if (board[0][2] == computer_marker) {
//             return 10;
//         } else if (board[0][2] == player_marker) {
//             return -10;
//         }
//     }

//     // No winner
//     return 0;
// }

// int minimax(char board[SIZE][SIZE], int depth, bool isMax) {
//     int score = evaluate(board);

//     // If Maximizer has won the game
//     if (score == 10) {
//         return score - depth;
//     }

//     // If Minimizer has won the game
//     if (score == -10) {
//         return score + depth;
//     }

//     // If there are no more moves and no winner, it's a tie
//     if (!isMovesLeft()) {
//         return 0;
//     }

//     // If this is maximizer's move
//     if (isMax) {
//         int best = -1000;

//         // Traverse all cells
//         for (int i = 0; i < SIZE; i++) {
//             for (int j = 0; j < SIZE; j++) {
//                 // Check if cell is empty
//                 if (board[i][j] == ' ') {
//                     // Make the move
//                     board[i][j] = computer_marker;

//                     // Call minimax recursively and choose the maximum value
//                     best = std::max(best, minimax(board, depth + 1, !isMax));

//                     // Undo the move
//                     board[i][j] = ' ';
//                 }
//             }
//         }
//         return best;
//     } else {
//         int best = 1000;

//         // Traverse all cells
//         for (int i = 0; i < SIZE; i++) {
//             for (int j = 0; j < SIZE; j++) {
//                 // Check if cell is empty
//                 if (board[i][j] == ' ') {
//                     // Make the move
//                     board[i][j] = player_marker;

//                     // Call minimax recursively and choose the minimum value
//                     best = std::min(best, minimax(board, depth + 1, !isMax));

//                     // Undo the move
//                     board[i][j] = ' ';
//                 }
//             }
//         }
//         return best;
//     }
// }

// void computerMove() {
//     int bestVal = -1000;
//     int bestMoveRow = -1;
//     int bestMoveCol = -1;

//     // Traverse all cells, evaluate minimax function for all empty cells
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             // Check if cell is empty
//             if (board[i][j] == ' ') {
//                 // Make the move
//                 board[i][j] = computer_marker;

//                 // Compute evaluation function for this move
//                 int moveVal = minimax(board, 0, false);

//                 // Undo the move
//                 board[i][j] = ' ';

//                 // If the value of the current move is more than the best value, update best
//                 if (moveVal > bestVal) {
//                     bestMoveRow = i;
//                     bestMoveCol = j;
//                     bestVal = moveVal;
//                 }
//             }
//         }
//     }

//     // Make the best move
//     board[bestMoveRow][bestMoveCol] = computer_marker;
// }

// bool placeMarker(int x, int y, char marker) {
//     int col = x / 100;
//     int row = y / 100;

//     if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
//         board[row][col] = marker;
//         return true;
//     }

//     return false;
// }

// void game(sf::RenderWindow &window, sf::Font &font) {
//     int player_won = 0;
//     bool playerTurn = true;

//     while (true) {  // Loop until a winner or a draw
//         while (player_won == 0) {
//             drawBoard(window, font);

//             sf::Event event;
//             while (window.pollEvent(event)) {
//                 if (event.type == sf::Event::Closed) {
//                     window.close();
//                     return;
//                 }
//                 if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
//                     sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//                     int x = mousePos.x;
//                     int y = mousePos.y;
//                     if (playerTurn) {  // Player's turn
//                         if (placeMarker(x, y, player_marker)) {
//                             playerTurn = false;
//                         }
//                     }
//                 }
//             }

//             if (!playerTurn) {  // Computer's turn
//                 computerMove();
//                 playerTurn = true;
//             }

//             player_won = evaluate(board);
            
//             // If no winner and no moves left, it's a draw
//             if (player_won == 0 && !isMovesLeft()) {
//                 std::cout << "It's a tie!\n";
//                 player_won = 3;  // Set a non-zero value for draw
//             }
//         }

//         drawBoard(window, font);

//         if (player_won == 10) {
//             std::cout << "Computer won! Better luck next time.\n";
//             computerWins++;
//         } else if (player_won == -10) {
//             std::cout << "You won! Congratulations!\n";
//             playerWins++;
//         } else if (player_won == 3) {
//             std::cout << "It's a tie!\n";
//         }

//         // Wait for a moment before restarting
//         sf::sleep(sf::seconds(2));

//         // Reset the board for a new game
//         for (int i = 0; i < SIZE; ++i) {
//             for (int j = 0; j < SIZE; ++j) {
//                 board[i][j] = ' ';
//             }
//         }

//         player_won = 0;
//         playerTurn = true;
//     }
// }

// int main() {
//     sf::RenderWindow window(sf::VideoMode(300, 400), "Tic Tac Toe");
//     sf::Font font;
//     if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) {
//         std::cerr << "Error loading font\n";
//         return -1;
//     }

//     game(window, font);

//     return 0;
// }
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n; 
//     cout<< " Hello";
//     return 0;
// }