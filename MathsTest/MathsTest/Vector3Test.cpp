#include "gtest/gtest.h"
#include "Maths/Vector3.h"

TEST(Vector3_Constructor, Assigns_All_Components) {
    Vector3 v(3, 4, 5);
    EXPECT_EQ(v.x, 3);
    EXPECT_EQ(v.y, 4);
    EXPECT_EQ(v.z, 5);
}







