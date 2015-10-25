#include "gtest/gtest.h"

#include <foo.h>

TEST(foo_test, print_test)
{
    Application::Foo sut;
    EXPECT_EQ(sut.print(), "Foo");
}