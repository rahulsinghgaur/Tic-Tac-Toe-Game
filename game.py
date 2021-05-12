# Tic-Tac-Toe Game
#Assignment By Rahul Gaur 8th Sem
from os import system
value = {1:" ",2:" ",3:" ",4:" ",5:" ",6:" ",7:" ",8:" ",9:" "}
player= {"X":"Player 1: For 'X'","O":"Player 2: For 'O'" }
def inputs():
    for i in range(1,10):
        symbol = "X" if i%2 != 0 else "O"
        print(f"\n{player[symbol]} Write place :")
        while(True):
                place = int(input())
                if value[place] == " ":
                    value[place] = symbol
                    break
                else:print("Warning! Please Selcet Empty Space:")
        printboard(),checkwin(symbol)   
def printboard():
    system('cls')
    [print("-+-+-" if i==2 else f"{value[i]}|{value[i+1]}|{value[i+2]}") for i in [1,2,4,2,7]]
def checkwin(symbol):
    for i in range(1,8,3):
        if value[i]==value[i+1]==value[i+2] != " ":
            print(f"\n---//  {player[symbol][:8]} WIN !  //---"),exit()
    for i in range(1,4):
        if value[i]==value[i+3]==value[i+6] != " ":
            print(f"\n---//  {player[symbol][:8]} WIN !  //---"),exit()
    if value[1]==value[5]==value[9] != " ":
        print(f"\n---//  {player[symbol][:8]} WIN !  //---"),exit()
    elif value[3]==value[5]==value[7] != " ":
        print(f"\n---//  {player[symbol][:8]} WIN !  //---"),exit()
printboard(),inputs()