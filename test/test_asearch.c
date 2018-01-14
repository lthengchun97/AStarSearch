#include "unity.h"
#include "Asearch.h"
#include "nodehelper.h"

void setUp(void)
{
  initNnode();
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
/*
*                       Sarawak
*                       /   \
*                   Sabah   Johor
*
*  Start: Sarawak
*  End : Sabah
*/

void test_nearest_end_with_3_different_axis_place(void)
{
    A_Node *start = &nodeSarawak;
    initN(&nodeSarawak,1,1,&nodeSabah,&nodeJohor);
    initN(&nodeSabah,2,4,NULL,NULL);
    initN(&nodeJohor,8,6,NULL,NULL);
    A_Node *end = Asearch(&start,&nodeSabah,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodeSabah,end);
}

/*
*                       Sarawak
*                       /
*                   Sabah
*                     /
*                   Johor
*
*  Start: Sarawak
*  End : Johor
*/

void test_nearest_end_with_3_different_axis_place_v2(void)
{
    A_Node *start = &nodeSarawak;
    initN(&nodeSarawak,1,1,&nodeSabah,NULL);
    initN(&nodeSabah,2,4,&nodeJohor,NULL);
    initN(&nodeJohor,8,6,NULL,NULL);
    A_Node *end = Asearch(&start,&nodeJohor,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodeJohor,end);
    //TEST_ASSERT_EQUAL_FLOAT(8.602325,test);
}

/*
*                       Sarawak
*                           \
*                         Sabah
*                            \
*                           Johor
*
*  Start: Sarawak
*  End : Johor
*/

void test_nearest_end_with_3_different_axis_place_v3(void)
{
    A_Node *start = &nodeSarawak;
    initN(&nodeSarawak,1,1,NULL,&nodeSabah);
    initN(&nodeSabah,3,3,NULL,&nodeJohor);
    initN(&nodeJohor,8,6,NULL,NULL);
    A_Node *end = Asearch(&start,&nodeJohor,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodeJohor,end);
}

/*
*                        Sarawak
*                        /    \
*                     Johor   Sabah
*                              /
*                           Melaka
*                            /
*                         Penang
*
*  Start: Sarawak
*  End : Penang
*/

void test_nearest_end_with_5_different_axis_place(void)
{
    A_Node *start = &nodeSarawak;
    initN(&nodeSarawak,0,0,&nodeJohor,&nodeSabah);
    initN(&nodeSabah,3,3,&nodeMelaka,NULL);
    initN(&nodeJohor,-1,-2,NULL,NULL);
    initN(&nodeMelaka,8,6,&nodePenang,NULL);
    initN(&nodePenang,10,10,NULL,NULL);
    A_Node *end = Asearch(&start,&nodePenang,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodePenang,end);
}
