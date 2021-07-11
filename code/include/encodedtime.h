#pragma

struct EncodedTime {
    unsigned short frames;
    unsigned short seconds;
    unsigned short minutes;
    unsigned short hours;

    EncodedTime(unsigned short frames, unsigned short seconds, unsigned short minutes, unsigned short hours) : frames(
            frames), seconds(seconds), minutes(minutes), hours(hours) {}
};
