// John Self 
//Header file for Player class
//Lab 11
//Rick Sweeney lab partner

#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>

using namespace std;

class Player {											//class definition and members
	
	public:
	Player(int , int, int, int);
	Player();
	int getGoFirst();
	void setGoFirst(int);
	int turn();
	int computerTurn2();
	void setSpace(int,char);
	int getWinner();
	void setWinner(int);
	void setLoseCount();
	int getLoseCount();
	int getWinCount();
	void setWinCount();
	
	~Player();
	
	private:
	int goFirst;
	int winner;
	int winCount;
	int loseCount;
	
	
};




	Player::Player(int GoFirst , int Winner,int WinCount,int LoseCount){		//overload constructor
	int goFirst = GoFirst;
	int winner = Winner;
	int winCount = WinCount;
	int loseCount = LoseCount;
	
};

	Player::Player(){								//default constructor
	int goFirst = 0;
	int winner = 0;
	int winCount = 0;
	int loseCount = 0;	
	}

	Player::~Player(){								// default constructor
		
	};
	
int Player::getLoseCount(){							//gets # of loses
	return loseCount;
}

void Player::setLoseCount(){						//sets # of loses
	this->loseCount = loseCount++;
}
	
int Player::getWinCount(){							//gets # of wins
	return winCount;
}

void Player::setWinCount(){							//sets # of wins
	this->winCount = winCount++;
}

int Player::getGoFirst(){							// get who goes first
	return goFirst;
};

void Player::setGoFirst(int gofirst){				//sets who goes first
	this->goFirst = gofirst;
};



int Player::turn(){									//player turn function
	int space=0;
	cout<<endl << "Please select a space to occupy\n";
	cin >> space;
	return space;
	
}

int Player::computerTurn2(){							//computer turn funtion
	int randnum;
	srand(time(NULL));
	randnum = rand()%27+1;	
	return randnum;
}

void Player::setSpace(int spacenumber, char X){		// not used
	
	
}

int Player::getWinner(){					// gets winner int
	return winner;	
}

void Player::setWinner(int WINNER){			//sets winner int
	this->winner = WINNER;
}


class Computer : public Player{							//Derived class
	public:
		Computer();
		int compTurn();
};

Computer::Computer(){								//Default contructor
};

int Computer::compTurn(){							//computer.compTurn turn funtion
	int randnum;
	srand(time(NULL));
	randnum = rand()%27+1;	
	return randnum;
}

