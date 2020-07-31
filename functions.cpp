#include<iostream> 
#include<time.h>
#include<stdlib.h>
#include<zconf.h>
using namespace std;

void greetAndInstruct(){

cout<<"Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer."<<endl;
cout<<"The board is numbered from 1 to 27 as per the following:"<<endl;
cout<<"1 | 2 | 3  10 | 11 | 12  19 | 20 | 21"<<endl;
cout<<"---------  ------------  ------------"<<endl;
cout<<"4 | 5 | 6  13 | 14 | 15  22 | 23 | 24"<<endl;
cout<<"---------  ------------  ------------"<<endl;
cout<<"7 | 8 | 9  16 | 17 | 18  25 | 26 | 27"<<endl;
cout<<"Player starts first. Simply input the number of the cell you want to occupy."<<endl;
cout<<"Player’s move is marked with X. Computer’s move is marked with O."<<endl;
cout<<"start?(y/n)"<<endl;
char var;
while(true){
	cin>> var;
	if(var!='n'&&var!='y'){
		cin.clear();
		cin.ignore();
		cout<<"please enter a valid answer"<<endl;
	}else if(var=='n'){
		exit(0);
 }else{
		break;
	}
	}
}


void displayBoard (char board[]){
	int table[27];
	for(int i=0;i<27;i++){ table[i]=1+i;}

	 for (int i=0;i<=6;i+=3){
		 if(board[i]!='X'&&board[i]!='O'){
		 	cout<<table[i]<<"|";
		 	}else{
		    cout<<board[i]<<"|";
		 	}
		 if(board[i+1]!='X'&&board[i+1]!='O'){
		 			cout<<table[i+1]<<"|";
		 			}else{
		 		    cout<<board[i+1]<<"|";
		 			}
		 if(board[i+2]!='X'&&board[i+2]!='O'){
		 			cout<<table[i+2]<<" ";
		 			}else{
		 		    cout<<board[i+2]<<" ";
		 			}

		if(board[i+9]!='X'&&board[i+9]!='O'){
			cout<<table[i+9]<<"|";
			}else{
		    cout<<board[i+9]<<"|";
			}

		if(board[i+10]!='X'&&board[i+10]!='O'){
			cout<<table[i+10]<<"|";
			}else{
			cout<<board[i+10]<<"|";
			}


		if(board[i+11]!='X'&&board[i+11]!='O'){
		cout<<table[i+11]<<" ";
		}else{
			cout<<board[i+11]<<" ";
		}

		if(board[i+18]!='X'&&board[i+18]!='O'){
		cout<<table[i+18]<<"|";
		}else{
		cout<<board[i+18]<<"|";
		}
				 if(board[i+19]!='X'&&board[i+19]!='O'){
				 			cout<<table[i+19]<<"|";
				 			}else{
				 		    cout<<board[i+19]<<"|";
				 			}
				 if(board[i+20]!='X'&&board[i+20]!='O'){
				 			cout<<table[i+20]<<endl;
				 			}else{
				 		    cout<<board[i+20]<<endl;
				 			}
		if(i<=4){
		cout<<"----- -------- --------"<<endl;
		}
	 }
	}
		



bool checkIfLegal(int cellNbre, char board[]){
	if(cellNbre>26||cellNbre<0){
		cout<<"Your input exceeds the range! Please enter a new legal number:"<<endl;
		return false;
		
	}else if(board[cellNbre]=='O'||board[cellNbre]=='X'){
		cout<<"This cell is occupied! Please enter a new legal number:"<<endl;
		return false;
	}
	return true;
}

bool checkWinner(char board[]){

    //check same cell
	    for (int i =0; i<9;i++){
	        if ( board[i] == board[i+9] && board[i+9] == board[i+18]){
	            return true;
	        }
	    }

	    //check row
	    for (int i=0; i<9; i += 3){
	        if( (board[i] == board[i+1] && board[i+1] == board[i+2])
	        || (board[i+9] == board[i+10] && board[i+10] == board[i+11])
	        || (board[i+18] == board[i+19] && board[i+19]== board[i+20])
	        || (board[i] == board[i+10] && board[i+10] == board[i+20] )
	        || (board[i+2] == board[i+10] && board[i+10] == board[i+18])){
	            return true;
	        }
	    }

	    //check column
	    for (int i =0;i<3;i++){
	        if( (board[i] == board[i+3] && board[i+3] == board[i+6])
	        || (board[i+9] == board[i+12] && board[i+12] == board[i+15])
	        || (board[i+18] == board[i+21] && board[i+21] == board[i+24])
	        || (board[i] == board[i+12] && board[i+12] == board[i+24])
	        || (board[i+6] == board[i+12] && board[i+12] == board[i+18])) {
	            return true;
	        }
	    }

	    //check diagonal
	    //right diagonal;
	    if( (board[0] == board[4] && board[4] == board[8])
	    || (board[9] == board[13] && board[13] == board[17])
	    || board[18]== board[22] && board[22] == board[26]
	    || (board[0]== board[13] && board[13] == board[26]) ){
	        return true;
	    }
	    //left diagonal;
	    if(board[2] == board[4] == board[6]
	    || board[11] == board[13] == board[15]
	    || board[20] == board[22] == board[24]
	    || board[2] == board[13] == board[24] ){
	        return true;
	    }

	    return false;
	}





void computerMove(char board[]){
  int index;
  srand((unsigned)time(NULL));
  //CHECK IF THE NEXT COMPUTER WINS
  for(int i=0;i<27;i++){
	  if(board[i]!='O'&&board[i]!='X'){
		  char save=board[i];
		  board[i]='O';
		  if(checkWinner(board)==true){
			  cout<<"computer moves at check computer "<<(i+1)<<endl;
			  return;
		  }else{
			  board[i]=save;
		  }
	  }
  }
  //check if the next human wins
  for(int i=0;i<27;i++){
  	  if(board[i]!='O'&&board[i]!='X'){
  		  char save=board[i];
  		  board[i]='X';
  		  if(checkWinner(board)==true){
  			  board[i]='O';
  			  cout<<"computer moves at check human"<<(i+1)<<endl;
  			  return;
  		  }else{
  			  board[i]=save;
  		  }
  	  }
    }
  //random step
  bool con=true;
  while(con){
  index=rand()%27;
  if(board[index]!='O'&&board[index]!='X'){
	  board[index]='O';
	  cout<<"computer moves at "<<(index+1)<<endl;
	  con=false;
  }
  }


}
void UserMove(int index,char board[]){
	board[index]='X';
}
/*
int main(){
greetAndInstruct();

char board[27];
for (int i=0;i<27;i++){
	board[i]='a'+i;
}
displayBoard(board);
int count=1;
while(count<=27){
	//human turn
	count++;
	cout<<"Please enter a index:"<<endl;
	int index;
	cin>> index;
	while(!checkIfLegal(index-1,board)){
		cin>>index;
	}
		board[index-1]='X';
        displayBoard(board);
		if(checkWinner(board)){
			cout<<"human wins!"<<endl;
			break;
		}

	//computer move
	cout<<"now it is computer's move"<<endl;
	computerMove(board);
	count++;
	displayBoard(board);
	if(checkWinner(board)){
		cout<<"computer wins!"<<endl;
		break;
	}

}
 if(count==28){
	 cout<<"TIE!"<<endl;
 }
}
*/
