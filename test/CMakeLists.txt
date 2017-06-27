file(GLOB_RECURSE HearYeHearYeTests_SRC
        "*.cpp"
        "*.hpp"
        )

add_executable (HearYeHearYeTests ${HearYeHearYeTests_SRC})

target_link_libraries(HearYeHearYeTests LINK_PUBLIC gtest)