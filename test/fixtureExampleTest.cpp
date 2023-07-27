#include gtest/gtest.h
class A{
    B* ptr;
    public:
    A(B* addressOfObject): ptr{addressOfObject}{

    }
    bool operation(){
        return true;
    }
};
class B{
    C* ptr;
    public:
    B(C* addressOfObject): ptr{addressOfObject}{
        
    }
};
class C{};

TEST("TestFixtureTestSuite","OperationTest"){
    C cObj;
    B bObj(&cObj);
    A obj(&bObj);
    //Act and Assert
    ASSERT_TRUE(obj.operation());
}

TEST("TestFixtureTestSuite","OperationTest"){
    C cObj;
    B bObj(&cObj);
    A obj(&bObj);
    //Act and Assert
    ASSERT_FALSE(obj.operation());
}

