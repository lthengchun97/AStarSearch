#include "unity.h"
#include "Asearch.h"
#include "nodehelper.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_asearch_NeedToImplement(void)
{
    initN(&nodeX,1,1);
    initN(&nodeY,8,6);
    initN(&nodeZ,2,4);
    float test = findDistance(&nodeX,&nodeY);
    TEST_ASSERT_EQUAL_FLOAT(8.602325,test);
}
