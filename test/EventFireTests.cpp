#include "gtest/gtest.h"

#include "HearYeHearYe/Event.hpp"

using namespace mn::HearYeHearYe;

namespace {

    class EventFireTests : public ::testing::Test {
    protected:

        EventFireTests() {
        }

        virtual ~EventFireTests() {
        }
    };

    TEST_F(EventFireTests, VoidEvent) {

        Event<void()> event;

        bool listenerCalled = false;
        event.AddListener([&] () {
            listenerCalled = true;
        });

        event.Fire();

        EXPECT_TRUE(listenerCalled);
    }

    TEST_F(EventFireTests, VoidIntEvent) {

        Event<void(int)> event;

        int savedNum = 0;
        event.AddListener([&] (int value) {
            savedNum = value;
        });

        event.Fire(2);

        EXPECT_EQ(savedNum, 2);
    }

}  // namespace