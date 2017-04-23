#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main(){
   /* --STATEMENTS-- */
	double bet = 0;
	Hand dealerHand;
	Hand playerHand;
	Player dealer( 900 );
	Player player( 100 );

	while (dealer.access_money() > 0 && player.access_money() > 0) {
		std::cout << "You have $" << player.access_money() << ". Enter ber:";
		while (!(cin >> bet)) {
			cout << "Bad value!\n";
			std::cout << "You have $" << player.access_money() << ". Enter ber:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		Card a;
		playerHand.acceptCard(a);
		
		std::cout << "Your cards:\n";
		playerHand.printCard();


		

	}

	std::cout<<  SIETE	 <<endl ;
	
	
	return 0;

}
