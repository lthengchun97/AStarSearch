#include "unity.h"
#include "Asearch.h"
#include "nodehelper.h"
#include "Exception.h"
#include "CException.h"
#include "addnode.h"
#include "avlcompare.h"
#include "removenode.h"
#include "rotate.h"
#include "nodeverifier.h"

void setUp(void)
{
  initNnode();
}

void tearDown(void)
{
}
/*
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
/*
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
/*
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
/*
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
/*
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
/*
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
/*
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
/*
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
/*
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
*/
/*
void test_create_node_for_avl(void)
{
    createNode(&nodeSarawak,0,0);
    createNode(&nodeSabah,1,1);
    createNode(&nodeJohor,2,2);
    createNode(&nodeMelaka,3,3);

    Node *Johor = (Node *)malloc(sizeof(Node));
    Node *Sabah = (Node *)malloc(sizeof(Node));
    Node *Sarawak = (Node *)malloc(sizeof(Node));
    Node *Melaka = (Node *)malloc(sizeof(Node));

    createNodeAvl(Johor,&nodeJohor);
    createNodeAvl(Sabah,&nodeSabah);
    createNodeAvl(Sarawak,&nodeSarawak);
    createNodeAvl(Melaka,&nodeMelaka);
    A_Node *start = &nodeSarawak;

    //A_Node *end = Asearch(&start,&nodeMelaka,0,0);
    TEST_ASSERT_EQUAL_PTR(0,Sarawak->data->x);
    TEST_ASSERT_EQUAL_PTR(0,Sarawak->data->y);
    TEST_ASSERT_EQUAL_STRING("Sarawak",Sarawak->data->country);
    TEST_ASSERT_EQUAL_PTR(1,Sabah->data->x);
    TEST_ASSERT_EQUAL_PTR(1,Sabah->data->y);
    TEST_ASSERT_EQUAL_STRING("Sabah",Sabah->data->country);
    TEST_ASSERT_EQUAL_PTR(2,Johor->data->x);
    TEST_ASSERT_EQUAL_PTR(2,Johor->data->y);
    TEST_ASSERT_EQUAL_STRING("Johor",Johor->data->country);
    TEST_ASSERT_EQUAL_PTR(3,Melaka->data->x);
    TEST_ASSERT_EQUAL_PTR(3,Melaka->data->y);
    TEST_ASSERT_EQUAL_STRING("Melaka",Melaka->data->country);
    free (Johor);
    free (Sabah);
    free (Sarawak);
    free (Melaka);
}

/*
        Sarawak (0,0)         ->        Sarawak (0,0)
                                              \
                                              Sabah(1,1)
*/

/*
void test_create_node_for_avl_and_add_it_to_the_tree(void)
{

    createNode(&nodeSarawak,0,0);
    createNode(&nodeSabah,1,1);

    Node *Sabah = (Node *)malloc(sizeof(Node));
    Node *Sarawak = (Node *)malloc(sizeof(Node));

    createNodeAvl(Sabah,&nodeSabah);
    createNodeAvl(Sarawak,&nodeSarawak);
    Node *start = Sarawak;

    avladdNode(&start,Sabah);
    TEST_ASSERT_EQUAL_NODE(NULL,Sabah,0,Sarawak);
    TEST_ASSERT_EQUAL_PTR(Sabah,Sarawak->right);
    free (Sabah);
    free (Sarawak);
}

/*
        Sarawak (0,0)         ->        Sarawak (0,0)                 ->     Calculate the distance from start the end
                                              \
                                              Sabah(1,1)

      Start : Sarawak
      End : Sabah
*/

void test_create_node_for_avl_and_find_the_shortest_path_to_the_ending_point(void)
{

    createNode(&nodeSarawak,0,0);
    createNode(&nodeSabah,1,1);

    Node *Sabah = (Node *)malloc(sizeof(Node));
    Node *Sarawak = (Node *)malloc(sizeof(Node));

    createNodeAvl(Sabah,&nodeSabah);
    createNodeAvl(Sarawak,&nodeSarawak);
    Node *start = Sarawak;

    avladdNode(&start,Sabah);
    TEST_ASSERT_EQUAL_NODE(NULL,Sabah,0,Sarawak);

    A_Node *end = Asearch((&start),Sabah,0,0);
    TEST_ASSERT_EQUAL_PTR(Sabah,end);
    TEST_ASSERT_EQUAL_FLOAT(1.414214,end->totalValue);
    resetGlobalVariable();
    free (Sabah);
    free (Sarawak);
}

/*
        Sarawak (0,0)         ->        Sarawak (1,1)                 Rotate Left
                                              \                            ->
                                              Sabah(3,3)
                                                \
                                                Johor(8,6)

      Start : Sarawak
      End : Sabah
*/

void test_create_node_for_avl_and_find_the_shortest_path_to_the_ending_point_v2(void)
{
    createNode(&nodeSarawak,1,1);
    createNode(&nodeSabah,3,3);
    createNode(&nodeJohor,8,6);

    Node *Sabah = (Node *)malloc(sizeof(Node));
    Node *Sarawak = (Node *)malloc(sizeof(Node));
    Node *Johor = (Node *)malloc(sizeof(Node));

    createNodeAvl(Sabah,&nodeSabah);
    createNodeAvl(Sarawak,&nodeSarawak);
    createNodeAvl(Johor,&nodeJohor);
    Node *start = Sarawak;

    avladdNode(&start,Sabah);
    avladdNode(&start,Johor);
    TEST_ASSERT_EQUAL_NODE(NULL,Sabah,0,Sarawak);
    TEST_ASSERT_EQUAL_PTR(&nodeSarawak,Sarawak->data);
    TEST_ASSERT_EQUAL_PTR(1,Sarawak->data->x);
    TEST_ASSERT_EQUAL_PTR(1,Sarawak->data->y);
    TEST_ASSERT_EQUAL_NODE(NULL,Johor,0,Sabah);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,Johor);
    TEST_ASSERT_EQUAL_PTR(Sarawak,start);

    A_Node *end = Asearch((&start),Johor,0,0);
    TEST_ASSERT_EQUAL_PTR(Johor,end);
    TEST_ASSERT_EQUAL_FLOAT(8.659379,end->totalValue);
    resetGlobalVariable();
    free (Sabah);
    free (Sarawak);
    free (Johor);
}
