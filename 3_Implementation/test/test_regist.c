#include "unity.h"
#include "registration.h"

#define PROJECT_NAME    "Indian_Vaccine_Registration_System"


void test_check_reg(void);
void test_check_vac(void);

void setUp(){}

void tearDown(){}


int main()
{
  UNITY_BEGIN();


  RUN_TEST(test_check_reg);
  RUN_TEST(test_check_vac);
  
  return UNITY_END();
}


void test_check_reg(void) {
  TEST_ASSERT_EQUAL(-1, check_reg(123));
  
  TEST_ASSERT_EQUAL(-1, check_reg(150)); // Fail condition
}

void test_check_vac(void) {
  TEST_ASSERT_EQUAL(1, check_vac(1));
  
  TEST_ASSERT_EQUAL(2, check_vac(1)); // Fail condition
}

