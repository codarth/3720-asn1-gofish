#include <gtest/gtest.h>
#include "../include/deck.h"

struct DeckTest : public testing::Test
{
    Deck* d;
    Card* c;
    void SetUp()
    {
        d = new Deck();
        c = new Card("Ace", "Clubs");
    }
    void TearDown()
    {
        delete d;
        delete c;
    }
};

TEST_F(DeckTest, DeckSize)
{
    EXPECT_EQ(d->GetDeck().size(), 52);
}

TEST_F(DeckTest, DealTest)
{
    d->DealCard();
    EXPECT_EQ(d->GetDeck().size(), 51);
}

TEST_F(DeckTest, ShuffleTest)
{
    Card* c = d->DealCard();
    ASSERT_EQ(c->GetFace(), "King");
    ASSERT_EQ(c->GetSuit(), "Spades");

    d->Shuffle();
    d->Shuffle();
    d->Shuffle();
    c = d->DealCard();

    EXPECT_NE(c->GetFace(), "Queen");
    ASSERT_NE(c->GetSuit(), "Spades");
}

TEST_F(DeckTest, CurrentCardTest)
{
    d->SetCurrentCard(c);
    ASSERT_EQ(d->GetCurrentCard(), c);
}
