// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the Array of int in int_array.hpp. It is graded: the
// autograder runs it against a correct Array and against several with one bug each. A test is
// worth something only when it passes on the correct Array and fails on a broken one, so a
// test that always fails (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for the constructors, the copy and move
// operations, operator[] in and out of range, fill, and length.
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "int_array.hpp"

TEST(IntArrayTests, DefaultArrayIsEmpty) {
    const Array a;
    EXPECT_EQ(a.length(), 0);
}

TEST(IntArrayTests, SizedArrayReportsItsLength) {
    const Array a{5};
    EXPECT_EQ(a.length(), 5);
}

// ADD YOUR TESTS HERE:
TEST(IntArrayTests, Fill) {
    Array a{5};
    a.fill(10);

    for (int i = 0; i < a.length(); ++i) {
        EXPECT_EQ(a[i], 10);
    }
}

TEST(IntArrayTests, Subscript) {
    Array a{3};
    a[0] = 10;
    a[2] = 20;

    EXPECT_EQ(a[0], 10);
    EXPECT_EQ(a[2], 20);
}

TEST(IntArrayTests, OutOfBounds) {
    Array a{3};

    EXPECT_THROW(a[-1], std::string);
    EXPECT_THROW(a[3], std::string);
}

TEST(IntArrayTests, OneElement) {
    Array a{1};
    a.fill(8);

    EXPECT_EQ(a.length(), 1);
    EXPECT_EQ(a[0], 8);
    EXPECT_THROW(a[1], std::string);
}

TEST(IntArrayTests, EmptyArrayBounds) {
    Array a;
    EXPECT_THROW(a[0], std::string);
}