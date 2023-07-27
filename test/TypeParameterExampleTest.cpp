#include "gtest/gtest.h"
using testing::Types;
class ITempSensor{
    public:
    virtual int getOutsideTemp()=0;      //TempSensoe becomes interface.
};

class ModelATempSensor:public ITempSensor{
    public:
    int getOutsideTemp(){
        return 23;
    }
};
class ModelBTempSensor:public ITempSensor{
    public:
    int getOutsideTemp(){
        return 23;
    }
};
class AutoTempRegulator{
    ITempSensor* tempSensorPtr;
    public:
    AutoTempRegulator(ITempSensor* address):tempSensorPtr{address}{} //what is this line??
    void regulateTemp(){
        this->tempSensorPtr->getOutSideTemp();
    }
};

/*class ModelATempSensorFixture:public testing::Test{      //Here problem is we need diff fixtures, for the diff stratergies, even if they have common interface.
    protected:
    //arrange
    ModelATempSensor objUnderTest;

}

TEST_F(ModelATempSensorFixture,GetTempTest){
    ASSERT_EQ(objUnderTest.getOutSide(),23);
}    


class ModelBTempSensorFixture:public testing::Test{
    protected:
    //arrange
    ModelBTempSensor objUnderTest;

}

TEST_F(ModelBTempSensorFixture,GetTempTest){
    ASSERT_EQ(objUnderTest.getOutSide(),23);
} */


template <typename T>
// turning fixture into template based, so can be used for all stratergies.

ITempSensor* createObject();
template <>
ITempSensor* createObject<ModelATempSensor>() { return new ModelATempSensor(); }
template <>
ITempSensor* createObject<ModelBTempSensor>() { return new ModelBTempSensor(); }

template <typename T>
class TempSensorFixture:public testing::Test{      //Here problem is we need diff fixtures, for the diff stratergies, even if they have common interface.
    protected:
    TempSensorFixture():objUnderTest{ createObject<T>()}
    //arrange
    //ModelATempSensor objUnderTest; // here tempSensorFixture depending on ModelATempSensor, violation of DIP, So we make TempSensorFixture depend on ModelATempSensor's abstracti
     
     ITempSensor* objUnderTest;

}

typedef Types<ModelATempSensor,ModelBTempSensor> Implementations;

TYPED_TEST_SUITE(TempSensorFixture, Implementations);

TYPED_TEST(TempSensorFixture, GetTempTest) {
	ASSERT_EQ(objUnderTest.getOutsideTemp(),23);
}







