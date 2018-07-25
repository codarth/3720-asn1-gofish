#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../include/gofish.h"
#include "mockdeck.h"
#include "mockplayer.h"
#include "mockview.h"

class MockGoFish: public GoFish
{
public:
    MOCK_METHOD0(Begin, void());
    MOCK_METHOD0(Play, void());
    MOCK_METHOD0(DealInitialHand, void());
    MOCK_METHOD0(CheckForGroup, void());
    MOCK_METHOD0(SelectOpponent, void());
    MOCK_METHOD0(SelectCard, void());
    MOCK_METHOD0(CheckGuess, void());
    MOCK_METHOD0(SetCurrentPlayer, void());
    MOCK_METHOD0(CheckPlayersHandSize, bool());
};

struct GoFishTest : public testing::Test
{
    GoFish* gf;
    Deck* d;
    MockDeck* md;
    GoFishView* v;
    MockView* mv;
    Player* p1;
    Player* p2;
    MockPlayer* mp1;
    MockPlayer* mp2;
    std::vector<Player*> players;

    void SetUp()
    {
        gf = new GoFish();

        d = new MockDeck();
        md = dynamic_cast<MockDeck*>(d);

        v = new MockView();
        mv = dynamic_cast<MockView*>(v);

        p1 = new MockPlayer();
        p2 = new MockPlayer();
        mp1 = dynamic_cast<MockPlayer*>(p1);
        mp2 = dynamic_cast<MockPlayer*>(p2);

        players.push_back(p1);
        players.push_back(p2);


    }

    void TearDown()
    {
        delete d;
        delete v;
        for(Player* p : players){
            delete p;
        }

    }
};

//TEST_F(GoFishTest, Begin)
//{
//
//    EXPECT_CALL(*md, Shuffle())
//    .Times(3)
//    .WillRepeatedly(::testing::Return());
//
//EXPECT_CALL(*mv, GetNumberOfPlayers())
//    .Times(1)
//    .WillOnce(::testing::Return(2));
//
//        EXPECT_CALL(*mv, SetName(::testing::_))
//    .Times(2)
//    .WillOnce(::testing::Return("p"))
//    .WillOnce(::testing::Return("l"));
//
//        EXPECT_CALL(*mv, AnnouncePlayersTurn(::testing::_))
//    .Times(1);
//
//       EXPECT_CALL(*mv, PrintHand(::testing::_));
//
//
//
//}
//
//TEST_F(GoFishTest, GetNumPlayers)
//{
//    EXPECT_CALL(*v, GetNumberOfPlayers())
//    .Times(1)
//    .WillOnce(::testing::Return(2));
//}
//
//TEST_F(GoFishTest, SetName)
//{
//    EXPECT_CALL(*v, SetName(::testing::_))
//    .Times(2)
//    .WillOnce(::testing::Return("p"))
//    .WillOnce(::testing::Return("l"));
//}
//
//TEST_F(GoFishTest, Announce)
//{
//    EXPECT_CALL(*v, AnnouncePlayersTurn(::testing::_))
//    .Times(1);
//}
//
//TEST_F(GoFishTest, PrintHand)
//{
//    EXPECT_CALL(*v, PrintHand(::testing::_));
//}

TEST(GoFishTest, Play)
{
    MockGoFish goFish;
    EXPECT_CALL(goFish, Play()).Times(1);

    goFish.Play();
}

TEST(GoFishTest, Group)
{
    MockGoFish goFish;
    EXPECT_CALL(goFish, CheckForGroup()).Times(1);

    goFish.CheckForGroup();
}

TEST(GoFishTest, Opponent)
{
    MockGoFish goFish;
    EXPECT_CALL(goFish, SelectOpponent()).Times(1);

    goFish.SelectOpponent();
}

TEST(GoFishTest, Card)
{
    MockGoFish goFish;
    EXPECT_CALL(goFish, SelectCard()).Times(1);

    goFish.SelectCard();
}

TEST(GoFishTest, Guess)
{
    MockGoFish goFish;
    EXPECT_CALL(goFish, CheckGuess()).Times(1);

    goFish.CheckGuess();
}

TEST(GoFishTest, CurrentPlayer)
{
    MockGoFish goFish;
    EXPECT_CALL(goFish, SetCurrentPlayer()).Times(1);

    goFish.SetCurrentPlayer();
}

TEST(GoFishTest, HandSize)
{
    MockGoFish goFish;

    EXPECT_CALL(goFish, CheckPlayersHandSize()).WillOnce(::testing::Return(false));

    goFish.CheckPlayersHandSize();
}

