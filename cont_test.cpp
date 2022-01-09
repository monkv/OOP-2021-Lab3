#include "gtest/gtest.h"
#include "table.h"
#include "wholesale.h"
#include "retail.h"
#include "product.h"

TEST(MapTest, test1)
{
    map<int, std::string> myMap;
    myMap.emplace(1, "One");
    myMap.emplace(2, "Two");
    myMap.emplace(3, "Three");
    iterator<int, std::string> it = myMap.begin();
    EXPECT_EQ((*it).second, "One");
    EXPECT_EQ((*(++it)).second, "Two");
    EXPECT_EQ((*(++it)).second, "Three");
    it = myMap.find(2);
    EXPECT_EQ((*it).second, "Two");
    EXPECT_EQ((*myMap.find(1)).second, "One");
    myMap.erase(2);
    it = myMap.begin();
    EXPECT_EQ((*it).second, "One");
    EXPECT_EQ((*(++it)).second, "Three");

}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
