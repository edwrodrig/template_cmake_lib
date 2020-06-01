#include <tpl_project_tpl/Element.h>

#include "gtest/gtest.h"

TEST(testElement, sum)
{
    auto element = tpl_project_tpl::Element(1, 2);
    auto result = element.sum();


    EXPECT_EQ(3,result);
}

