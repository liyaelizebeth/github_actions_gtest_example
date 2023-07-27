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

class TestFixtureTestSuite:public testing::Test{
    protected:
    void SetUp(){
        //Arrange
        this->cPtr=new C();
        this->bPtr=new B(cPtr);
        this->aPtr=new A(bPtr);

    }
    void TearDown(){
        //delete resources
        delete cPtr;
        delete bPtr;
        delete aPtr;

    }




};

TEST_F(TestFixtureTestSuite,OperationTrueTest){
    ASSERT_TRUE(aPtr->operation());
}

TEST_F(TestFixtureTestSuite,OperationFalseTest){
    ASSERT_FALSE(aPtr->operation());
}


//TEST(TestFixtureTestSuite,OperationTrueTest){

    //Arrange

    //C cObj;

    //B bObj(&cObj);

    //A obj(&bObj);

    //Act and Assert

    //ASSERT_TRUE(obj.operation());

//}

//TEST(TestFixtureTestSuite,OperationFalseTest){

    //Arrange

    //C cObj;

    //B bObj(&cObj);

    //A obj(&bObj);

    //Act and Assert

    //ASSERT_FALSE(obj.operation());





//}