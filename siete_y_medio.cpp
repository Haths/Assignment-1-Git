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
	
	Player dealer( 900 );
	Player player( 100 );
	

	while (dealer.access_money() > 0 && player.access_money() > 0) {
		Hand dealerHand;
		Hand playerHand;
		char decision = 'y';
		bool lose = false;
		std::cout << "You have $" << player.access_money() << ". Enter ber:";
		
		while (!(cin >> bet) || bet > player.access_money() || bet < 1) {
			cout << "Bad value!\n";
			std::cout << "You have $" << player.access_money() << ". Enter ber:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		while (decision == 'y' && playerHand.handValue() < 8) {
			Card a;

			if (playerHand.handNum() > 0) {
				std::cout << "New card:" << endl;
				std::cout << "	" << a.get_spanish_rank() << " de " << a.get_spanish_suit();
				std::cout << "	(" << a.get_english_rank() << " of " << a.get_english_suit() << ").\n\n";
			}
			playerHand.acceptCard(a);
			std::cout << "Your cards:\n";
			playerHand.printCard();
			if (playerHand.handValue() > 7.5) {
				std::cout << "Your total is " << playerHand.handValue() << endl << "\nToo bad. You lose " << bet << ".\n\n";
				player.update_money(player.access_money() - bet);
				dealer.update_money(dealer.access_money() + bet);
				lose = true;
				break;
			}
			std::cout << "Your total is " << playerHand.handValue() << ". Do you want another card (y/n)?";
			while (!(cin >> decision) || (decision != 'y' &&  decision != 'n')) {
				cout << "Bad value!\n";
				std::cout << "Your total is " << playerHand.handValue() << ". Do you want another card (y/n)?";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (decision == 'y') {
				continue;
			}
			else {

				break;
			}
		}
			
			while (dealerHand.handValue() < 5.5 && lose == false ) {
						Card b;
					
						if (dealerHand.handNum() > 0) {
							std::cout << "New card:" << endl;
							std::cout << "	" << b.get_spanish_rank() << " de " << b.get_spanish_suit();
							std::cout << "	(" << b.get_english_rank() << " of " << b.get_english_suit() << ").\n\n";
						}
						dealerHand.acceptCard(b);
						if (dealerHand.handNum()==1){
							std::cout << "Dealer's cards:";
							std::cout << "	" << b.get_spanish_rank() << " de " << b.get_spanish_suit();
							std::cout << "	(" << b.get_english_rank() << " of " << b.get_english_suit() << ").\n";
						}
						else {
							std::cout << "Dealer's cards:\n";
							dealerHand.printCard();
						}
						std::cout << "The dealer's total is " << dealerHand.handValue() << ".\n\n";
					}
			if (dealerHand.handValue() > 7.5 || playerHand.handValue() > dealerHand.handValue() && lose == false ) {
				std::cout << "You win " << bet << ".\n\n";
				player.update_money(player.access_money() + bet);
				dealer.update_money(dealer.access_money() - bet);
			}
			else if (playerHand.handValue() == dealerHand.handValue()) {
				std::cout << "Draw " <<".\n\n";
			}
			else if (playerHand.handValue() < dealerHand.handValue()) {
				std::cout << "Too bad. You lose " << bet << ".\n\n";
				player.update_money(player.access_money() - bet);
				dealer.update_money(dealer.access_money() + bet);
			}
		

	}

	if (player.access_money() == 0) {
		std::cout << "You have $0. GAME OVER!\nCome back when you have more money.\n\n";
	}
	else std::cout << "Congratulations. You beat the casino!\n\n";
	
	std::cout << "Bye!\n";
	return 0;

}
