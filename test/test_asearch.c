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
    resetGlobalVariable();
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
    A_Node *end = Asearch(&start,&nodeSabah,0,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodeSabah,end);
    TEST_ASSERT_EQUAL_FLOAT(3.162278,end->totalValue);
    resetGlobalVariable();
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
    A_Node *end = Asearch(&start,&nodeJohor,0,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodeJohor,end);
    TEST_ASSERT_EQUAL_FLOAT(9.486834,end->totalValue);
    resetGlobalVariable();
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
    A_Node *end = Asearch(&start,&nodeJohor,0,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodeJohor,end);
    TEST_ASSERT_EQUAL_FLOAT(8.659379,end->totalValue);
    resetGlobalVariable();
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
    A_Node *end = Asearch(&start,&nodePenang,0,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodePenang,end);
    TEST_ASSERT_EQUAL_FLOAT(14.545729,end->totalValue);
    resetGlobalVariable();
}

/*
*                        Sarawak(0,0)
*                        /    \
*                 (1,1)Johor   Sabah(2,2)
*                      /
*                (3,3)Melaka
*
*
*
*  Start: Sarawak
*  End : Melaka
*/

void test_nearest_end_with_4_different_axis_place_with_simple_back_track(void)
{
    A_Node *start = &nodeSarawak;
    initN(&nodeSarawak,0,0,&nodeJohor,&nodeSabah);
    initN(&nodeSabah,2,2,NULL,NULL);
    initN(&nodeJohor,1,1,&nodeMelaka,NULL);
    initN(&nodeMelaka,3,3,NULL,NULL);

    A_Node *end = Asearch(&start,&nodeMelaka,0,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodeMelaka,end);
    TEST_ASSERT_EQUAL_FLOAT(4.24260,end->totalValue);
    resetGlobalVariable();
}

/*
*                        Sarawak(0,0)
*                        /    \
*                 (1,1)Johor   Sabah(2,2)
*                        \
*                   (3,3)Melaka
*
*  Start: Sarawak
*  End : Melaka
*/

void test_nearest_end_with_4_different_axis_place_with_simple_back_track_v2(void)
{
    A_Node *start = &nodeSarawak;
    initN(&nodeSarawak,0,0,&nodeJohor,&nodeSabah);
    initN(&nodeSabah,2,2,NULL,NULL);
    initN(&nodeJohor,1,1,NULL,&nodeMelaka);
    initN(&nodeMelaka,3,3,NULL,NULL);

    A_Node *end = Asearch(&start,&nodeMelaka,0,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodeMelaka,end);
    TEST_ASSERT_EQUAL_FLOAT(4.24260,end->totalValue);
    resetGlobalVariable();
}

/*
*                        Sarawak(0,0)
*                        /    \
*                 (2,2)Johor  Sabah(1,1)
*                               \
*                              Melaka(3,3)
*
*  Start: Sarawak
*  End : Melaka
*/

void test_nearest_end_with_4_different_axis_place_with_simple_back_track_v3(void)
{
    A_Node *start = &nodeSarawak;
    initN(&nodeSarawak,0,0,&nodeJohor,&nodeSabah);
    initN(&nodeSabah,1,1,NULL,&nodeMelaka);
    initN(&nodeJohor,2,2,NULL,NULL);
    initN(&nodeMelaka,3,3,NULL,NULL);

    A_Node *end = Asearch(&start,&nodeMelaka,0,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodeMelaka,end);
    TEST_ASSERT_EQUAL_FLOAT(4.24260,end->totalValue);
    resetGlobalVariable();
}

/*
*                        Sarawak(0,0)
*                        /    \
*                 (2,2)Johor  Sabah(1,1)
*                              /
*                          Melaka(3,3)
*
*  Start: Sarawak
*  End : Melaka
*/

void test_nearest_end_with_4_different_axis_place_with_simple_back_track_v4(void)
{
    A_Node *start = &nodeSarawak;
    initN(&nodeSarawak,0,0,&nodeJohor,&nodeSabah);
    initN(&nodeSabah,1,1,&nodeMelaka,NULL);
    initN(&nodeJohor,2,2,NULL,NULL);
    initN(&nodeMelaka,3,3,NULL,NULL);

    A_Node *end = Asearch(&start,&nodeMelaka,0,0);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,start);
    TEST_ASSERT_EQUAL_PTR(&nodeMelaka,end);
    TEST_ASSERT_EQUAL_FLOAT(4.24260,end->totalValue);
    resetGlobalVariable();
}
