#include "gtest/gtest.h"




class C{};

class B{

    C* ptr;

    public:

    B(C* addressOfObject): ptr{addressOfObject}{

    }




};







class A{

    B* ptr;

    public:

    A(B* addressOfObject): ptr{addressOfObject}{

    }




    bool  operation(){

        return true;

    }




};






/*

TEST(TestFixtureTestSuite,OperationTrueTest){

    //Arrange

    C cObj;

    B bObj(&cObj);

    A obj(&bObj);

    //Act and Assert

    ASSERT_TRUE(obj.operation());




}




TEST(TestFixtureTestSuite,OperationFalseTest){

    //Arrange

    C cObj;

    B bObj(&cObj);

    A obj(&bObj);

    //Act and Assert

    ASSERT_FALSE(obj.operation());




} */




class TestFixtureTestSuite:public testing::Test{

protected:

A * aPtr;

B* bPtr;

C* cPtr;

TestFixtureTestSuite(){

    //Initialize

}

~TestFixtureTestSuite(){

    //Releasing the resources

}

void SetUp(){

    //Arrange

    this->cPtr=new C();

    this->bPtr=new B(cPtr);

    this->aPtr=new A(bPtr);




}

void TearDown(){

    delete cPtr;

    delete bPtr;

    delete aPtr;

//delete resources

}




};




TEST_F(TestFixtureTestSuite,OperationTrueTest){

    //Arrange

   

    //Act and Assert

    ASSERT_TRUE(aPtr->operation());




}




TEST_F(TestFixtureTestSuite,OperationFalseTest){

    //Arrange

   

    //Act and Assert

    ASSERT_TRUE(aPtr->operation());




}