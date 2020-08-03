#include "functions.cpp"




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

	while(true){
		cin>> index;
		if(!checkIfLegal(index-1,board)){
		cin.clear();
		cin.ignore();
	}else{
		break;
	}
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
