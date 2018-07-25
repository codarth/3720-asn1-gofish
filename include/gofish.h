#ifndef GOFISH_H
#define GOFISH_H

#include "gofishview.h"
#include "deck.h"

/**< gofish.h */
class GoFish
{
public:
    /** Default constructor */
    GoFish();
    /** Copy constructor */
    GoFish(const GoFish &goFish);
    /** Default destructor */
    ~GoFish();


    /** \brief Setup before game loop
     *  Player, deck, deal
     * \return void
     */
    void Begin();

    /** \brief Start game loop
     * \return void
     */
    void Play();

    /** \brief deal hand to each player
     * \return void
     */
    void DealInitialHand();

    /** \brief See if there is a group of 4 cards
     *  ie. 4 Aces
     * \return void
     */
    void CheckForGroup();

    /** \brief Who to guess from
     * \return void
     */
    void SelectOpponent();

    /** \brief What card to ask for
     * \return void
     */
    void SelectCard();

    /** \brief Check the guess
     * \return void
     */
    void CheckGuess();

    /** \brief Set currentPlayer
     * \return void
     */
    void SetCurrentPlayer();

    /** \brief Check if Player has cards or not
     *  If not End Game
     * \return bool
     */
    bool CheckPlayersHandSize();

    void SetDeck(Deck* _deck) { deck = _deck;}


    template<typename T>
    void SetView(T* _view)
    {
        view = _view;
    }

private:
    GoFishView* view; //!< Member variable "view"
    Deck* deck; //!< Member variable "deck"
    int numberOfPlayers; //!< Member variable "numberOfPlayers"
    std::vector<Player*> players; //!< Member variable "players"
    Player* currentPlayer; //!< Member variable "currentPlayer"
    Card* guessCard; //!< Member variable "guessCard"
    bool keepPlaying; //!< Member variable "keepPlaying"
    Player* opponent; //!< Member variable "opponent"
};

#endif // GOFISH_H
