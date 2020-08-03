/*
 * blackjack2.h
 *
 *  Created on: 2020?3?11?
 *      Author: 18796
 */

#ifndef BLACKJACK_H_
#define BLACKJACK_H_
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card
{
public:
    enum rank { ACE = 1, TWO,   THREE, FOUR, FIVE,
                SIX,     SEVEN, EIGHT, NINE, TEN,
                JACK,    QUEN,  KING               };
    enum type { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(rank r = ACE, type s = SPADES);

    // return the value of a card
    int getValue() const;
    void displayCard();



private:
    rank m_Rank;
    type m_Type;
    //bool m_IsFaceUp;

    friend ostream& operator<<(ostream& os, const Card& aCard)
    {
        string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"  };
        string TYPES[] = { "C", "D", "H", "S" };
        

        { os <<(RANKS[aCard.m_Rank]) << (TYPES[aCard.m_Type]); }

        return os;
    }
};
class Hand
{
public:
    static constexpr unsigned CARD_IN_HAND { 7 };
    Hand();
    virtual ~Hand();
    // adds a card to the hand
    inline void add(Card* pCard);

    // clears hand of all cards
    void clear();

    // gets hand total value, treat ace as 1 or 11
    int getTotal() const;
protected:
    std::vector<Card*> m_Cards;
};
class Deck : public Hand
{
public:
    static constexpr unsigned DECK_SIZE { 52 };
    Deck();
    virtual ~Deck();

    // create a standard deck of 52 cards
    void populate();

    // shuffle cards
    void Shuffle();

    // deal one card to a hand
    void deal(Hand& aHand);

    // give additional cards to a generic plauer
    //void AdditionalCards(GenericPlayer& ap);
};
class AbstractPlayer : public Hand
{
public:
	AbstractPlayer();
    virtual ~AbstractPlayer();

    // indicate whther or not player wan to keep hitting
    virtual bool isDrawing() const = 0;

    // return whether generic player has busted - has a total greater than 21
    bool isBusted() const;

    // announces that the player busts
    //void Bust() const;

protected:


    friend std::ostream& operator<<(std::ostream& os, const AbstractPlayer& ap)
    {

        if (!ap.m_Cards.empty()) {
            for(const auto &c : ap.m_Cards) {  c->displayCard() ; }
            if (ap.getTotal() != 0) { std::cout << "[" << ap.getTotal() << "]"; }
        } else {
            os << "<empty>";
        }
        return os;
    }
};
class HumanPlayer : public AbstractPlayer
{
public:
    HumanPlayer(){};
    virtual ~HumanPlayer(){};

    // return whter or not the player wants another hit
    virtual bool isDrawing() const;

    // announces that the plaer wins
    void announce(Hand computer);


};
class ComputerPlayer : public AbstractPlayer
{
public:
    ComputerPlayer(){};
    virtual ~ComputerPlayer(){};

    // return whter or not the player wants another hit
    virtual bool isDrawing() const;

    // announces that the plaer wins
    //void announce(Hand computer);


};
class BlackJackGame
{
public:
	BlackJackGame();
    ~BlackJackGame();

    // plays the game of blackjack
    void play();
private:
    Deck m_Deck;
    ComputerPlayer m_casino;
    HumanPlayer human;
    //std::vector<Player> m_Players;
};

#endif /* BLACKJACK2_H_ */
