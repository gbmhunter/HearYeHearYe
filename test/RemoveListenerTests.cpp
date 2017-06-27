#include "gtest/gtest.h"

#include "HearYeHearYe/Event.hpp"

using namespace mn::HearYeHearYe;

namespace {

    class RemoveListenerTests : public ::testing::Test {
    protected:

        RemoveListenerTests() {
        }

        virtual ~RemoveListenerTests() {
        }
    };

    TEST_F(RemoveListenerTests, RemoveOne) {

        Event<void()> event;

        bool listener1Called = false;
        event.AddListener([&] () {
            listener1Called = true;
        });

        bool listener2Called = false;
        event.AddListener([&] () {
            listener2Called = true;
        });

        event.RemoveListener(0);
        event.Fire();

        // Listener1 should of NOT been called,
        // listener2 should of been called
        EXPECT_FALSE(listener1Called);
        EXPECT_TRUE(listener2Called);
    }

    TEST_F(RemoveListenerTests, InvalidRemove) {

        Event<void()> event;

        bool listener1Called = false;
        event.AddListener([&] () {
            listener1Called = true;
        });

        bool listener2Called = false;
        event.AddListener([&] () {
            listener2Called = true;
        });

        // Try and remove a listener that is out-of-bounds
        EXPECT_THROW(event.RemoveListener(3), std::invalid_argument);
    }

    TEST_F(RemoveListenerTests, RemoveAll) {

        Event<void()> event;

        bool listener1Called = false;
        event.AddListener([&] () {
            listener1Called = true;
        });

        bool listener2Called = false;
        event.AddListener([&] () {
            listener2Called = true;
        });

        event.RemoveAllListeners();
        event.Fire();

        // Both listeners should of NOT been called
        EXPECT_FALSE(listener1Called);
        EXPECT_FALSE(listener2Called);
    }

}  // namespace