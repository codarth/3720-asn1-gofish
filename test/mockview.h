#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../include/gofishview.h"
#include "../include/gofish.h"

class MockView : public GoFishView
{
public:
    MOCK_METHOD0(GetNumberOfPlayers, int());
    MOCK_METHOD1(SetName, std::string(int i));
    MOCK_METHOD1(AnnouncePlayersTurn, void(Player* player));
    MOCK_METHOD0(SelectOpponent, std::string());
    MOCK_METHOD1(PrintHand, void(Player* player));
    MOCK_METHOD0(GuessACard, std::string());
    MOCK_METHOD0(GoFish, void());
    MOCK_METHOD1(YouDraw, void(Card* card));
    MOCK_METHOD1(GoodGuess, void(size_t n));
    MOCK_METHOD0(CantPickYourself, void());
    MOCK_METHOD0(NotValidPlayer, void());
    MOCK_METHOD0(InvalidCard, void());
    MOCK_METHOD1(Results, void(std::vector<Player*> players));
};


//TEST(ViewTest, GetNumPLayers)
//{
//    MockView mv;
//
//    EXPECT_CALL(mv, GetNumberOfPlayers())
//    .Times(1);
//    //.WillOnce(::testing::Return());
//
//    mv.GetNumberOfPlayers();
//
//}
//LCOV
//TEST(ViewTest, SetName)
//{
//    MockView mv;
//
//    EXPECT_CALL(mv, SetName(::testing::_)).Times(::testing::AtLeast(1));
//
//    mv.SetName(0);
//}
//
//TEST(ViewTest, Announce)
//{
//    MockView mv;
//    Player* p;
//    EXPECT_CALL(mv, AnnouncePlayersTurn(::testing::_)).Times(1);
//
//    mv.AnnouncePlayersTurn(p);
//}
//
//TEST(ViewTest, Opponent)
//{
//    MockView mv;
//
//    EXPECT_CALL(mv, SelectOpponent())
//    .Times(1);
//    //.WillOnce(::testing::Return(""));
//
//    mv.SelectOpponent();
//}
//
//TEST(ViewTest, PrintHand)
//{
//    MockView mv;
//    Player* p;
//
//    EXPECT_CALL(mv, PrintHand(::testing::_)).Times(1);
//
//    mv.PrintHand(p);
//}
//
//TEST(ViewTest, GuessACard)
//{
//    MockView mv;
//
//    EXPECT_CALL(mv, GuessACard())
//    .Times(1);
//    //.WillOnce(::testing::Return(""));
//
//    mv.GuessACard();
//}
//
//TEST(ViewTest, GoFish)
//{
//    MockView mv;
//
//    EXPECT_CALL(mv, GoFish()).Times(1);
//
//    mv.GoFish();
//}
//
//TEST(ViewTest, YouDraw)
//{
//    MockView mv;
//    Card* c;
//
//    EXPECT_CALL(mv, YouDraw(::testing::_)).Times(1);
//
//    mv.YouDraw(c);
//}
//
//TEST(ViewTest, GoodGuess)
//{
//    MockView mv;
//    size_t n;
//    EXPECT_CALL(mv, GoodGuess(::testing::_)).Times(1);
//
//    mv.GoodGuess(n);
//}
//
//TEST(ViewTest, CantPickYourSelf)
//{
//    MockView mv;
//
//    EXPECT_CALL(mv, CantPickYourself()).Times(1);
//
//    mv.CantPickYourself();
//}
//
//TEST(ViewTest, NotValidPlayer)
//{
//    MockView mv;
//
//    EXPECT_CALL(mv, NotValidPlayer()).Times(1);
//
//    mv.NotValidPlayer();
//}
//
//TEST(ViewTest, InvalidCard)
//{
//    MockView mv;
//
//    EXPECT_CALL(mv, InvalidCard()).Times(1);
//
//    mv.InvalidCard();
//}
//
//TEST(ViewTest, Results)
//{
//    MockView mv;
//    std::vector<Player*> ps;
//
//    EXPECT_CALL(mv, Results(::testing::_)).Times(1);
//
//    mv.Results(ps);
//}
