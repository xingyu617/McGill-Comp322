/*
 * blackjack2.cpp
 *
 *  Created on: 2020?3?11?
 *      Author: 18796
 */
#include "blackjack.h"
#include<time.h>
#include <chrono>
#include<random>
#include<iostream>
#include <algorithm>
Card::Card(rank r, type s) : m_Rank(r), m_Type(s) {}


/*
 */
int Card::getValue() const
{
    
   { return m_Rank > 10 ? 10 : m_Rank; }
                        
}
void Card::displayCard(){
 cout<<*this<<" ";
}

Hand::Hand() { m_Cards.reserve(CARD_IN_HAND); }

Hand::~Hand() { clear(); }

inline void Hand::add(Card * pCard) {
this->m_Cards.push_back(pCard);
}


/*
 */
void Hand::clear()
{
    for (auto* c : m_Cards) {
        delete c;
        c = nullptr;
    }
    // clear std::vector of pointers
    m_Cards.clear();
}


/*
 */
int Hand::getTotal() const
{
    // if no card in hand, return 0
    if (m_Cards.empty()) { return 0; }

    // if a first card has value 0
    if (m_Cards.at(0)->getValue() == 0) { return 0; }

    // add up card value
    int total = 0;
    for(const auto* c : m_Cards) { total += c->getValue(); }

    // determine if hand contains an ace
    bool containsAce = false;
    for(const auto* c : m_Cards) {
        if (c->getValue() == Card::rank::ACE) { containsAce = true; }
    }

    // if hand contains ac and total is low enough, treat ace as 11
    if (containsAce && total <= 11) { total += 10; }
    return total;
}
Deck::Deck()
{
    m_Cards.reserve(DECK_SIZE);
    populate();
}


/*
 */
Deck::~Deck() {}


/*
 */
void Deck::populate()
{
    clear();
    //create standard deck
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
        for (int r = Card::ACE; r <= Card::KING; ++r) {
            add(new Card(static_cast<Card::rank>(r), static_cast<Card::type>(s)));
        }
    }
}


/*
 */
// Beware!! random_shuffle() was deprecated in C++14 and removed in C++17!
void Deck::Shuffle() {
	//auto rng = std::default_random_engine {};
	//std::shuffle(m_Cards.begin(), m_Cards.end(), rng);
    std::mt19937 eng { static_cast<unsigned>(
                        std::chrono::high_resolution_clock::now()
                        .time_since_epoch()
                        .count() ) };
    shuffle(m_Cards.begin(), m_Cards.end(), eng);

}

void Deck::deal(Hand& aHand)
{
    if (!m_Cards.empty()) {
        aHand.add(m_Cards.back());
        m_Cards.pop_back();
    } else {
        std::cout << "Out of cards. Unable to deal. ";
    }
}

AbstractPlayer::AbstractPlayer(){}


/*
 */
AbstractPlayer::~AbstractPlayer() {}


/*
 */
bool AbstractPlayer::isBusted() const { return getTotal() > 21; }
//HummanPlayer::HummanPlayer(): AbstractPlayer() {}


/*
 */
bool HumanPlayer::isDrawing() const
{
    std::cout <<  "do you want a draw? (Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}
void HumanPlayer::announce(Hand computer){
	if(this->isBusted()&&computer.getTotal()<21){
			cout<<"Computer wins!"<<endl;
		}else if(computer.getTotal()>=21&&!this->isBusted()){
        cout<<"Human wins!"<<endl;
    }else if(computer.getTotal()<this->getTotal()){
			cout<<"Human wins!"<<endl;
    }else if(computer.getTotal()>this->getTotal()){
			cout<<"Computer wins!"<<endl;
		}else{
			cout<<"push"<<endl;
		}
}
bool ComputerPlayer::isDrawing() const{
if (this->getTotal()<=16){
	return true;
}else{
	return false;
}
}
BlackJackGame::BlackJackGame()
{


    // seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    m_Deck.populate();
    m_Deck.Shuffle();
}

/*
 */
BlackJackGame::~BlackJackGame() {}

/*
 */
void BlackJackGame::play()
{
    // deal initial 2 cards to everyone
	//HumanPlayer human=new HumanPlayer();
    for (int i = 0; i < 2; ++i) {
        m_Deck.deal(human);

    }
    m_Deck.deal(m_casino);


    // dipslay everyone's hand
    std::cout << "Player:"<<human << '\n';
    std::cout << "Casino:"<<m_casino << '\n';


    while(human.isDrawing()) {
        // everyone still playing win
    	m_Deck.deal(human);
    	std::cout << "Player:"<<human << '\n';
    	if(human.isBusted()){
    		human.announce(m_casino);
    		break;
    	}
    }
    if(!human.isBusted()){
    while(m_casino.isDrawing()){
    	m_Deck.deal(m_casino);
    	cout<<"Casino:"<<m_casino<<endl;
    }
    human.announce(m_casino);
    }


    // remove everyone cards
    human.clear();
    m_casino.clear();
}
