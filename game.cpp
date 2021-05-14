#include <iostream>
using namespace std;
char block[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row, column;
bool draw = false;

void display(){
    system("cls");
    cout << "\n\n T I C    T A C    T O E    G A M E :)\n" << endl;
    cout << "\t'X' for Player 1 \n";
    cout << "\t'O' for Player 2 \n" << endl;

    cout << "\t\t       |       |       \n";
	cout << "\t\t   " << block[0][0] << "   |   " << block[0][1] << "   |   " << block[0][2] << "   \n";
	cout << "\t\t_______|_______|_______\n";
	cout << "\t\t       |       |       \n";
	cout << "\t\t   " << block[1][0] << "   |   " << block[1][1] << "   |   " << block[1][2] << "   \n";
	cout << "\t\t_______|_______|_______\n";
	cout << "\t\t       |       |       \n";
	cout << "\t\t   " << block[2][0] << "   |   " << block[2][1] << "   |   " << block[2][2] << "   \n";
	cout << "\t\t       |       |       \n" << endl;
}

void player_turn(){
    int choice;
    if(turn == 'X'){
        std :: cout << "Player 1 [X] Turn, Please Enter Your Place No. :  ";
    }
    if(turn == 'O'){
        cout << "Player 2 [O] Turn, Please Enter Your Place No. :  ";
    }
    
    cin >> choice; 

    switch (choice){
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;

        default:
        cout << "You've choosen Wrong Place No. : \n";
        break;
    }
    if(turn == 'X' && block[row][column] != 'X' && block[row][column] != 'O'){
        block[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && block[row][column] != 'X' && block[row][column] != 'X'){
        block[row][column] = 'O';
        turn = 'X';
    }else{
        std :: cout << "Place is Already Filled \n Please Enter Place No. Again : \n \n";
        player_turn();
    }
    display();
}

bool game_over(){
    // Check Win
    for(int i = 0; i < 3; i++){
        if(block[i][0] == block[i][1] && block[i][0] == block[i][2] || block[0][i] == block[1][i] && block[0][i] == block[2][i]){
            return false;
        }
    }
    if(block[0][0] == block[1][1] && block[0][0] == block[2][2] || block[0][2] == block[1][1] && block[1][1] == block[2][0]){
        return false;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(block[i][j] != 'X' && block[i][j] != 'O'){
                return true;
            }
        }
    }
    draw = true;
    return false;
}

int main(){
    
    while(game_over()){
        display();
        player_turn();
        game_over();
    }
    if(turn == 'X' && draw == false){
        cout << "Player 2 [X] Wins ! Congratulations :)\n" << endl;
    }else if(turn == 'O' && draw == false){
        cout << "Player 1 [X] Wins ! Congratulations :)\n" << endl;
    }else{
        cout << " Game Draw :( \n";
    }
    return 0;
}
