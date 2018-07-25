#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../include/player.h"

class MockPlayer : public Player
{
public:
    MOCK_METHOD0(GetName, std::string());
    MOCK_METHOD1(SetName, void(std::string val));
    MOCK_METHOD0(IncrementGroupCount, void());
    MOCK_METHOD0(GetGroupCount, unsigned());
    MOCK_METHOD0(GetHand, std::vector<Card*>());
    MOCK_METHOD1(DrawCard, Card*(Deck* deck));
    MOCK_METHOD1(CheckForCard, bool(Card* card));
    MOCK_METHOD1(AddCard, void(Card* card));
    MOCK_METHOD1(RemoveCard, std::vector<Card*>(Card* card));
};
