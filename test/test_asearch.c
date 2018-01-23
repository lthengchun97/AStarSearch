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

void test_findDistance_with_2_different_axis_place(void)
{
    createNode(&nodeSarawak,1,1);
    createNode(&nodeSabah,8,6);
    Node *Sabah = (Node *)malloc(sizeof(Node));
    Node *Sarawak = (Node *)malloc(sizeof(Node));
    createNodeAvl(Sabah,&nodeSabah);
    createNodeAvl(Sarawak,&nodeSarawak);

    float test = findDistance(Sarawak,Sabah);
    TEST_ASSERT_EQUAL_FLOAT(8.602325,test);
    resetGlobalVariable();
}

void test_compare_function(void)
{
  createNode(&nodeSarawak,0,0);
  createNode(&nodeSabah,2,2);
  createNode(&nodeJohor,-50,-8);
  createNode(&nodeMelaka,5,5);

  Node *Sabah = (Node *)malloc(sizeof(Node));
  Node *Sarawak = (Node *)malloc(sizeof(Node));
  Node *Johor = (Node *)malloc(sizeof(Node));
  Node *Melaka = (Node *)malloc(sizeof(Node));

  createNodeAvl(Sabah,&nodeSabah);
  createNodeAvl(Sarawak,&nodeSarawak);
  createNodeAvl(Johor,&nodeJohor);
  createNodeAvl(Melaka,&nodeMelaka);

  float d_ideal = findDistance(Sarawak,Melaka);
  float d_optimal = d_ideal * 150/100;

  int i =compareNode(Sarawak,Sabah,d_optimal,Melaka);
  int j =compareNode(Sarawak,Johor,d_optimal,Melaka);
  TEST_ASSERT_EQUAL(-1,i);
  TEST_ASSERT_EQUAL(1,j);
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
    createNode(&nodeSarawak,0,0);
    createNode(&nodeSabah,2,2);
    createNode(&nodeJohor,-50,-8);

    Node *Sabah = (Node *)malloc(sizeof(Node));
    Node *Sarawak = (Node *)malloc(sizeof(Node));
    Node *Johor = (Node *)malloc(sizeof(Node));

    createNodeAvl(Sabah,&nodeSabah);
    createNodeAvl(Sarawak,&nodeSarawak);
    createNodeAvl(Johor,&nodeJohor);

    float d_ideal = findDistance(Sarawak,Sabah);
    float d_optimal = d_ideal * 150/100;

    Node *start = NULL;
    avladdNode(&start,Sarawak,d_optimal,Sabah);
    avladdNode(&start,Sabah,d_optimal,Sabah);
    avladdNode(&start,Johor,d_optimal,Sabah);

    Node *end = (Node *)malloc(sizeof(Node));
    end=Asearch((&start),Sabah,0,0);
    TEST_ASSERT_EQUAL_PTR(Sarawak,start);
    TEST_ASSERT_EQUAL_PTR(Sabah,end);
    TEST_ASSERT_EQUAL_FLOAT(2.828427,end->totalValue);
    TEST_ASSERT_EQUAL_STRING("Sarawak->Sabah",end->totalCountry);
    resetGlobalVariable();
    free (Sabah);
    free (Sarawak);
    free (Johor);
}

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


void test_create_node_for_avl_and_add_it_to_the_tree(void)
{
    createNode(&nodeSarawak,0,0);
    createNode(&nodeSabah,1,1);

    Node *Sabah = (Node *)malloc(sizeof(Node));
    Node *Sarawak = (Node *)malloc(sizeof(Node));

    createNodeAvl(Sabah,&nodeSabah);
    createNodeAvl(Sarawak,&nodeSarawak);
    Node *start = Sarawak;

    avladdNode(&start,Sabah,0,Sabah);
    //TEST_ASSERT_EQUAL_NODE(NULL,Sabah,1,Sarawak);
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

    avladdNode(&start,Sabah,0,Sabah);
    //TEST_ASSERT_EQUAL_NODE(NULL,Sabah,1,Sarawak);

    Node *end = (Node *)malloc(sizeof(Node));

    end = Asearch((&start),Sabah,0,0);
    TEST_ASSERT_EQUAL_PTR(Sabah,end);
    TEST_ASSERT_EQUAL_FLOAT(1.414214,end->totalValue);
    TEST_ASSERT_EQUAL_STRING("Sarawak->Sabah",end->totalCountry);
    resetGlobalVariable();
    free (Sabah);
    free (Sarawak);
}

/*
        Sarawak (0,0)         ->        Sarawak (1,1)                 Rotate left             Sabah(3,3)
                                              \                           ->                  /     \
                                              Sabah(3,3)                             Sarawak(3,3)   Johor(8,6)
                                                \
                                                Johor(8,6)
        ->     Calculate the distance from start the end

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

    avladdNode(&start,Sabah,0,Sabah);
    avladdNode(&start,Johor,0,Sabah);
    //TEST_ASSERT_EQUAL_NODE(Sarawak,Johor,0,Sabah);
    //TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,Johor);
    //TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,Sarawak);
    TEST_ASSERT_EQUAL_PTR(Sabah,start);

    Node *end = (Node *)malloc(sizeof(Node));
    end=Asearch((&start),Johor,0,0);
    TEST_ASSERT_EQUAL_PTR(Johor,end);
    TEST_ASSERT_EQUAL_FLOAT(5.830952,end->totalValue);
    TEST_ASSERT_EQUAL_STRING("Sabah->Johor",end->totalCountry);
    resetGlobalVariable();
    free (Sabah);
    free (Sarawak);
    free (Johor);
}




void test_scenario_1(void)
{
  createNode(&nodeSarawak,0,0);
  createNode(&nodeSabah,0,1);
  createNode(&nodeJohor,-50,-8);
  createNode(&nodeMelaka,3,3);

  Node *Sabah = (Node *)malloc(sizeof(Node));
  Node *Sarawak = (Node *)malloc(sizeof(Node));
  Node *Johor = (Node *)malloc(sizeof(Node));
  Node *Melaka = (Node *)malloc(sizeof(Node));

  createNodeAvl(Sabah,&nodeSabah);
  createNodeAvl(Sarawak,&nodeSarawak);
  createNodeAvl(Johor,&nodeJohor);
  createNodeAvl(Melaka,&nodeMelaka);

  float d_ideal = findDistance(Sarawak,Melaka);
  float d_optimal = d_ideal * 300/100;
  printf("%f\n",d_optimal);
  Node *start = Sarawak;

  //avladdNode(&start,Sarawak,d_optimal,Melaka);
  avladdNode(&start,Sabah,d_optimal,Melaka);
  avladdNode(&start,Johor,d_optimal,Melaka);
  avladdNode(&start,Melaka,d_optimal,Melaka);
  //TEST_ASSERT_EQUAL_NODE(Sabah,Johor,-1,Sarawak);

  Node *end = (Node *)malloc(sizeof(Node));
  end=Asearch((&start),Melaka,0,0);
  TEST_ASSERT_EQUAL_PTR(Sarawak,start);
  TEST_ASSERT_EQUAL_PTR(Melaka,end);
  TEST_ASSERT_EQUAL_FLOAT(4.605551,end->totalValue);
  TEST_ASSERT_EQUAL_STRING("Sarawak->Sabah->Melaka",end->totalCountry);
  resetGlobalVariable();
  free (Sabah);
  free (Sarawak);
  free (Johor);
  free (Melaka);
}

void test_scenario_2(void)
{
  createNode(&nodeSarawak,0,0);
  createNode(&nodeSabah,0,2);
  createNode(&nodePenang,1,3);
  createNode(&nodeJohor,-50,-8);
  createNode(&nodeMelaka,3,3);

  Node *Sabah = (Node *)malloc(sizeof(Node));
  Node *Sarawak = (Node *)malloc(sizeof(Node));
  Node *Johor = (Node *)malloc(sizeof(Node));
  Node *Melaka = (Node *)malloc(sizeof(Node));
  Node *Penang = (Node *)malloc(sizeof(Node));

  createNodeAvl(Sabah,&nodeSabah);
  createNodeAvl(Sarawak,&nodeSarawak);
  createNodeAvl(Johor,&nodeJohor);
  createNodeAvl(Melaka,&nodeMelaka);
  createNodeAvl(Penang,&nodePenang);

  float d_ideal = findDistance(Sarawak,Melaka);
  float d_optimal = d_ideal * 300/100;
  Node *start = NULL;

  avladdNode(&start,Sarawak,d_optimal,Melaka);
  avladdNode(&start,Sabah,d_optimal,Melaka);
  avladdNode(&start,Johor,d_optimal,Melaka);
  avladdNode(&start,Penang,d_optimal,Melaka);
  avladdNode(&start,Melaka,d_optimal,Melaka);


  printf("%s\n",start->data->country);
  Node *end = (Node *)malloc(sizeof(Node));
  end=Asearch(&(start),Melaka,0,0);
  TEST_ASSERT_EQUAL_PTR(Sarawak,start);
  TEST_ASSERT_EQUAL_PTR(Melaka,end);
  TEST_ASSERT_EQUAL_FLOAT(5.162278,end->totalValue);
  TEST_ASSERT_EQUAL_STRING("Sarawak->Sabah->Melaka",end->totalCountry);
  resetGlobalVariable();
  free (Sabah);
  free (Sarawak);
  free (Johor);
  free (Melaka);

}
