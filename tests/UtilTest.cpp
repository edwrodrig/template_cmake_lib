#include <tpl_project_tpl/Util.h>

#include "gtest/gtest.h"

TEST(testUtil, sum)
{
    auto result = tpl_project_tpl::Util::sum(1,2);


    EXPECT_EQ(3,result);
}

