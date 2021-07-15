#include "timedecoder.h"

#include "gmock/gmock.h"

using namespace testing;

class TimeDecoderFramesParamTest : public TestWithParam<std::tuple<int, int>> {

};

TEST_P(TimeDecoderFramesParamTest, GetFramesWhenPassingEncodedValueReturnsTotalFrames) {
    auto encoded_value = std::get<0>(GetParam());
    auto expected_value = std::get<1>(GetParam());

    auto actual_value = TimeDecoder::GetFrames(encoded_value);

    ASSERT_EQ(actual_value, expected_value);
}

INSTANTIATE_TEST_SUITE_P(
    TimeDecoderGetFramesTests,
    TimeDecoderFramesParamTest,
    Values(
        std::make_tuple(0, 0),
        std::make_tuple(9, 9),
        std::make_tuple(261, 15),
        std::make_tuple(521, 29)
    ));

class TimeDecoderGetSecondsParamTest : public TestWithParam<std::tuple<int, int>> {

};

TEST_P(TimeDecoderGetSecondsParamTest, GetSecondsWhenPassingEncodedValueReturnsTotalSeconds) {
    auto encoded_value = std::get<0>(GetParam());
    auto expected_value = std::get<1>(GetParam());

    auto actual_value = TimeDecoder::GetMinutes(encoded_value);

    ASSERT_EQ(actual_value, expected_value);
}

INSTANTIATE_TEST_SUITE_P(
    TimeDecoderGetSecondsTests,
    TimeDecoderGetSecondsParamTest,
    Values(
        std::make_tuple(0, 0),
        std::make_tuple(9, 9),
        std::make_tuple(773, 35),
        std::make_tuple(1289, 59)
    ));

class TimeDecoderGetMinutesParamTest : public TestWithParam<std::tuple<int, int>> {

};

TEST_P(TimeDecoderGetMinutesParamTest, GetMinutesWhenPassingEncodedValueReturnsTotalMinutes) {
    auto encoded_value = std::get<0>(GetParam());
    auto expected_value = std::get<1>(GetParam());

    auto actual_value = TimeDecoder::GetMinutes(encoded_value);

    ASSERT_EQ(actual_value, expected_value);
}

INSTANTIATE_TEST_SUITE_P(
    TimeDecoderGetMinutesTests,
    TimeDecoderGetMinutesParamTest,
    Values(
        std::make_tuple(0, 0),
        std::make_tuple(9, 9),
        std::make_tuple(773, 35),
        std::make_tuple(1289, 59)
    ));

class TimeDecoderGetHoursParamTest : public TestWithParam<std::tuple<int, int>> {

};

TEST_P(TimeDecoderGetHoursParamTest, GetHoursWhenPassingEncodedValueReturnsTotalHours) {
    auto encoded_value = std::get<0>(GetParam());
    auto expected_value = std::get<1>(GetParam());

    auto actual_value = TimeDecoder::GetMinutes(encoded_value);

    ASSERT_EQ(actual_value, expected_value);
}

INSTANTIATE_TEST_SUITE_P(
    TimeDecoderGetHoursTests,
    TimeDecoderGetHoursParamTest,
    Values(
        std::make_tuple(0, 0),
        std::make_tuple(9, 9),
        std::make_tuple(261, 15),
        std::make_tuple(515, 23)
    ));
