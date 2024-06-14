#include<iostream>
using namespace std;

// Function to display the current state of the tic-tac-toe board
void displayboard(char board[3][3]){
    cout << "\n\tTic Tac Toe\n\n";

    cout << "    Player X  -  Player 0" << endl<<endl;
    cout << "          |     |     " << endl;
    cout << "       " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "     _____|_____|_____" << endl;
    cout << "          |     |     " << endl;
    cout << "       " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "     _____|_____|_____" << endl;
    cout << "          |     |     " << endl;
    cout << "       " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "          |     |     " << endl<<endl;
}

// Function to check if a player has won
bool win(char board[3][3], char player){
    // Check rows and columns for 3 consecutive marks by the same player
    for(int i = 0; i < 3; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true; // row win
        }
        else if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return true; // column win
        }
    }
    // Check diagonals for 3 consecutive marks by the same player
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true; // diagonal (\) win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return true; // diagonal (/) win
    }
    return false; // no win condition met
}

int main(){
    string choice;
    char board[3][3] = {{' ',' ',' '}, // Initialize the tic-tac-toe board with empty spaces
                        {' ',' ',' '},
                        {' ',' ',' '}};
    int r, c; // Variables to hold row and column input from the user
    int ur, uc; // Variables to hold user input for row and column
    int turn; // Counter for the number of turns
    char player = 'X'; // Start with player 'x'

    // Loop for each turn of the game (maximum 9 turns for a 3x3 board)
    for (turn = 0; turn < 9; turn++){
        displayboard(board); // Display the current board

        // Input validation loop to ensure a valid move
        while(true){
            cout << "Player: " << player << endl;
            cout << "Enter row (1-3) and column (1-3): ";
            cin >> ur >> uc;
            r = ur - 1; // Convert to 0-based index
            c = uc - 1; // Convert to 0-based index

            // Check if the chosen position is valid
            if (board[r][c] != ' ' || r < 0 || r > 2 || c < 0 || c > 2){
                cout << "Invalid move. Try again." << endl;
            }
            else{
                break; // Valid move, exit the input loop
            }
        }
        board[r][c] = player; // Place the player's mark on the board

        // Check if the current player has won
        if(win(board, player)){
            displayboard(board); // Display final board state
            cout <<"       "<< "Player " << player << " wins!" << endl<< endl;
            cout << "===================================================" << endl;
            break; // Exit the game loop if there is a winner
        }

        // Switch player for the next turn
        if (player == 'X'){
            player = 'O';
        }
        else{
            player = 'X';
        }
    }

    // If no winner is found, it's a draw
    if(turn == 9 && !win(board, player)){
        displayboard(board); // Display final board state
        cout<<"       " << "Game is a draw." << endl;
        cout << "===================================================" << endl;
    }

    // Ask if the players want to play again?
    cout << "Do you want to play again?"<<endl;
    cout << "Enter 'y' to play again or enter anything to exit ";
    cin >> choice;
    if (choice == "y" || choice == "Y"){
        main(); // Restart game
    }
    else{
        cout << "Thank you for playing!" << endl;
        return 0; // Exit the program
    }
    return 0; // End of program
}