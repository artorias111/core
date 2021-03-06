//-------------------------------------------------------------------------------------------
//- Copyright 2017 Applied Research Associates, Inc.
//- Licensed under the Apache License, Version 2.0 (the "License"); you may not use
//- this file except in compliance with the License. You may obtain a copy of the License
//- at:
//- http://www.apache.org/licenses/LICENSE-2.0
//- Unless required by applicable law or agreed to in writing, software distributed under
//- the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
//- CONDITIONS OF ANY KIND, either express or implied. See the License for the
//-  specific language governing permissions and limitations under the License.
//-------------------------------------------------------------------------------------------
//!
//! @author David Lee
//! @date   2017 Aug 3rd
//!
//! Unit Test for Biogears-common Config
//!
#include <thread>

#include <gtest/gtest.h>

#include <biogears/cdm/properties/SEScalarLengthPerTimePressure.h>


#ifdef DISABLE_BIOGEARS_SEScalarLengthPerTimePressure_TEST
#define TEST_FIXTURE_NAME DISABLED_SEScalarLengthPerTimePressure_Fixture
#else
#define TEST_FIXTURE_NAME SEScalarLengthPerTimePressure_Fixture
#endif

// The fixture for testing class Foo.
class TEST_FIXTURE_NAME : public ::testing::Test {
protected:
  // You can do set-up work for each test here.
  TEST_FIXTURE_NAME() = default;

  // You can do clean-up work that doesn't throw exceptions here.
  virtual ~TEST_FIXTURE_NAME() = default;

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  // Code here will be called immediately after the constructor (right
  // before each test).
  virtual void SetUp() override;

  // Code here will be called immediately after each test (right
  // before the destructor).
  virtual void TearDown() override;
};

void TEST_FIXTURE_NAME::SetUp()
{
}

void TEST_FIXTURE_NAME::TearDown()
{
}

TEST_F(TEST_FIXTURE_NAME, Unload)
{
  biogears::SEScalarLengthPerTimePressure LengthPerTimePressure = biogears::SEScalarLengthPerTimePressure();
  auto ptr = LengthPerTimePressure.Unload();
  EXPECT_EQ(ptr, nullptr);
}

TEST_F(TEST_FIXTURE_NAME, IsValidUnit)
{
  bool unit0 = biogears::LengthPerTimePressureUnit::IsValidUnit("m/s mmHg");
  bool unit1 = biogears::LengthPerTimePressureUnit::IsValidUnit("cm/s mmHg");
  bool unit2 = biogears::LengthPerTimePressureUnit::IsValidUnit("m/min mmHg");
  bool unit3 = biogears::LengthPerTimePressureUnit::IsValidUnit("cm/min mmHg");
  EXPECT_EQ(unit0, true);
  EXPECT_EQ(unit1, true);
  EXPECT_EQ(unit2, true);
  EXPECT_EQ(unit3, true);
  bool unit6 = biogears::LengthPerTimePressureUnit::IsValidUnit("DEADBEEF");
  EXPECT_EQ(unit6, false);
}

TEST_F(TEST_FIXTURE_NAME, GetCompoundUnit)
{
  biogears::LengthPerTimePressureUnit mu0 = biogears::LengthPerTimePressureUnit::GetCompoundUnit("m/s mmHg");
  biogears::LengthPerTimePressureUnit mu1 = biogears::LengthPerTimePressureUnit::GetCompoundUnit("cm/s mmHg");
  biogears::LengthPerTimePressureUnit mu2 = biogears::LengthPerTimePressureUnit::GetCompoundUnit("m/min mmHg");
  biogears::LengthPerTimePressureUnit mu3 = biogears::LengthPerTimePressureUnit::GetCompoundUnit("cm/min mmHg");
  EXPECT_EQ(mu0, biogears::LengthPerTimePressureUnit::m_Per_s_mmHg);
  EXPECT_EQ(mu1, biogears::LengthPerTimePressureUnit::cm_Per_s_mmHg);
  EXPECT_EQ(mu2, biogears::LengthPerTimePressureUnit::m_Per_min_mmHg);
  EXPECT_EQ(mu3, biogears::LengthPerTimePressureUnit::cm_Per_min_mmHg);
  EXPECT_THROW(biogears::LengthPerTimePressureUnit::GetCompoundUnit("DEADBEEF"),biogears::CommonDataModelException);
}