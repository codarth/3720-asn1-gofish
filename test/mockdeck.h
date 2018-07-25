#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../include/deck.h"

class MockDeck : public Deck
{
public:
    MOCK_METHOD0(Shuffle, void());
    MOCK_METHOD0(DealCard, Card*());
    MOCK_METHOD0(GetDeck, std::vector<Card*>());
    MOCK_METHOD0(GetCurrentCard, Card*());
    MOCK_METHOD1(SetCurrentCard, void(Card* val));
};
