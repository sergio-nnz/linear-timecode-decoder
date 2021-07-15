#pragma once

#include "encodedtime.h"

#include <map>
#include <string>

class Timecodes
{
private:
	int frame_rate;
	std::multimap<int, std::string> timecode_by_frames;
	
public:
	explicit Timecodes(const int frame_rate) : frame_rate(frame_rate) {};
	void AddEncodedTime(EncodedTime encodedTime);
	std::string GetMax() const;
	std::string GetMin() const;
	std::string GetValueFromMaxAt(const int& index) const;
};
