#include "unity.h"
#include "Asearch.h"
#include "nodehelper.h"

void setUp(void)
{

}

void tearDown(void)
{
}

void test_findDistance_with_2_different_axis_place(void)
{
    initN(&nodeSarawak,1,1,NULL,NULL);
    initN(&nodeSabah,8,6,NULL,NULL);
    initN(&nodeJohor,2,4,NULL,NULL);
    float test = findDistance(&nodeSarawak,&nodeSabah);
    TEST_ASSERT_EQUAL_FLOAT(8.602325,test);
}
