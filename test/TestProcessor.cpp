#include <gtest.h>
#include "Processor.h"

TEST(Processor, can_create_Realize)
{
	ASSERT_NO_THROW(Processor R);
}

TEST(Processor, can_create_Realize_2)
{
	ASSERT_NO_THROW(Processor R(10, 10, 0.5, 0.5));
}

TEST(Processor, cant_create_Realize_with_incorrect_values)
{
	ASSERT_ANY_THROW(Processor R(-10, 10001, 1, -0.5));
}

TEST(Processor, can_use_Process)
{
	Processor R;
	ASSERT_NO_THROW(R.Process());
}

TEST(Processor, can_use_Statistics)
{
	Processor R;
	ASSERT_NO_THROW(R.Statistics());
}