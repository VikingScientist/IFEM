//==============================================================================
//!
//! \file TestASMs3D.C
//!
//! \date Feb 14 2018
//!
//! \author Arne Morten Kvarving / SINTEF
//!
//! \brief Tests for structured 3D spline FE models.
//!
//==============================================================================

#include "ASMs3D.h"
#include "SIM3D.h"

#include "gtest/gtest.h"
#include <numeric>


class TestASMs3D : public testing::Test,
                   public testing::WithParamInterface<int>
{
};


TEST_P(TestASMs3D, Connect)
{
  SIM3D sim(3);
  std::stringstream str;
  str << "src/ASM/Test/refdata/DomainDecomposition_MPI_3D_4_orient";
  str << GetParam() << ".xinp";
  ASSERT_TRUE(sim.read(str.str().c_str()));
  ASSERT_TRUE(sim.createFEMmodel());
}

const std::vector<int> orientations3D = {0,1,2,3,5,6,7};
INSTANTIATE_TEST_CASE_P(TestASMs3D, TestASMs3D, testing::ValuesIn(orientations3D));


TEST(TestASMs3D, ConnectUneven)
{
  SIM3D sim(1);
  ASSERT_TRUE(sim.read("src/ASM/Test/refdata/3d_uneven.xinp"));
  ASSERT_TRUE(sim.createFEMmodel());
}
