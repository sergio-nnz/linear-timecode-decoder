#include "timecodes.h"

#include <bitset>
#include <iostream>

#include "timedecoder.h"


void Timecodes::AddEncodedTime(EncodedTime encodedTime)
{   
    const int frames = TimeDecoder::GetFrames(encodedTime.frames);
    const int seconds = TimeDecoder::GetSeconds(encodedTime.seconds);
    const int minutes = TimeDecoder::GetMinutes(encodedTime.minutes);
    const int hours = TimeDecoder::GetHours(encodedTime.hours);

	char timecode[20];
    sprintf_s(timecode, "%02d:%02d:%02d:%02d", hours, minutes, seconds, frames);
    int total_frames = (((hours * 3600) + (minutes * 60) + seconds) * frame_rate) + frames;

    timecode_by_frames.emplace(total_frames, timecode);
	
    std::cout << timecode << std::endl;
}

std::string Timecodes::GetMax() const
{
    auto max = std::prev(timecode_by_frames.cend());
    return max->second;
}


std::string Timecodes::GetMin() const
{
    auto min = timecode_by_frames.cbegin();
    return min->second;
}

std::string Timecodes::GetValueFromMaxAt(const int& index) const
{
    if (index <= timecode_by_frames.size()) {
	    const auto time = std::prev(timecode_by_frames.cend(), index);
        return time->second;
    }
    return "";
}
