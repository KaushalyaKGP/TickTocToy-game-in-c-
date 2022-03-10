#include <iostream>

using namespace std;

string PlayerName(int i)
{
	string name;
	cout<<"Enter Player "<<i<<" Name : ";
	cin>>name;
	return name;
}

void PrintArray(int array[3][3])
{
	
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}

void PrintArray(char array[3][3])
{
	
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}



bool checkAvailability(int positionNumber,char ticTocToy[3][3])
{
	int i = 0, j = 0;
	if(positionNumber>6)
	{
		i = 2;
		j = positionNumber - 7;
	}
	
	else
	{
		if(positionNumber>3)
		{
			i = 1;
			j = positionNumber - 4;
		}
		else
		{
			i = 0;
			j = positionNumber-1;
		}
	}
	
	if(ticTocToy[i][j]=='0')
	{
		return 1;
	}
	else
		return 0;
	
}

int checkWinninng(char ticTocToy[3][3],char currentSign)
{
	if(((ticTocToy[0][0])==currentSign)&&((ticTocToy[0][1])==currentSign)&&((ticTocToy[0][2])==currentSign))
	{
		return 1;
	}
	if(((ticTocToy[1][0])==currentSign)&&((ticTocToy[1][1])==currentSign)&&((ticTocToy[1][2])==currentSign))
	{
		return 1;
	}
	if(((ticTocToy[2][0])==currentSign)&&((ticTocToy[2][1])==currentSign)&&((ticTocToy[2][2])==currentSign))
	{
		return 1;
	}
	if(((ticTocToy[0][0])==currentSign)&&((ticTocToy[1][0])==currentSign)&&((ticTocToy[2][0])==currentSign))
	{
		return 1;
	}
	if(((ticTocToy[0][1])==currentSign)&&((ticTocToy[1][1])==currentSign)&&((ticTocToy[2][1])==currentSign))
	{
		return 1;
	}
	if(((ticTocToy[0][2])==currentSign)&&((ticTocToy[1][2])==currentSign)&&((ticTocToy[2][2])==currentSign))
	{
		return 1;
	}
	if(((ticTocToy[0][0])==currentSign)&&((ticTocToy[1][1])==currentSign)&&((ticTocToy[2][2]==currentSign)))
	{
		return 1;
	}
	if(((ticTocToy[0][2])==currentSign)&&((ticTocToy[1][1])==currentSign)&&((ticTocToy[2][0])==currentSign))
	{
		return 1;
	}
	else
		return 0;
}


int main()
{
	string playerNames[2];
	char sign[2] = {'o','x'};
	int position[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	char ticTocToy[3][3] = {{'0','0','0'},{'0','0','0'},{'0','0','0'}};
	bool currentPlayer = 0;
	char currentSign = sign[currentPlayer];
	int positionNumber = 0;
	bool winning = 0;
	
	//Set players Names Player 1 assigned to sign 'o' and player 2 --> sign 'x'

	for(int i = 0;i<2;i++)
	{	
		playerNames[i] = PlayerName(i+1);
	}
	
	//print board position names
	cout<<"Position numbering"<<endl;
	PrintArray(position);
	
	//play game
	
	while(1)
	{
		//print current board
		cout<<"current Board\n";
		PrintArray(ticTocToy);
		cout<<endl;
		
		//Scelect position
		cout<<playerNames[currentPlayer]<<" select position : ";
		cin>>positionNumber;
		//check availability & fill
		if(checkAvailability(positionNumber,ticTocToy))
		{
			int i = 0, j = 0;
			if(positionNumber>6)
			{
				i = 2;
				j = positionNumber - 7;
			}
			
			else
			{
				if(positionNumber>3)
				{
					i = 1;
					j = positionNumber - 4;
				}
				else
				{
					i = 0;
					j = positionNumber-1;
				}
			}
			ticTocToy[i][j] = currentSign;
				
			
			//check winning satatus
			winning = checkWinninng(ticTocToy,currentSign);
			if(winning)
			{
				cout<<"You win "<<playerNames[currentPlayer]<<endl;
				PrintArray(ticTocToy);
				break;
			}
			//if no win start next round
			currentPlayer = !(currentPlayer);
			currentSign = sign[currentPlayer];
			
		}
		else
		{
			cout<<"filled position, select another position \n";
		}
	}
	
	
	
	
}