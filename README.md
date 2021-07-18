# Linear Timecode Decoder
[!["Buy Me A Coffee"](https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png)](https://www.buymeacoffee.com/sergionnz)  
“The basic format is an 80-bit code that gives the time of day to the second, and the frame number within the second. Values are stored in binary-coded decimal, least significant bit first. There are thirty-two bits of user data, usually used for a reel number and date.”

This project decodes 16 bit unsigned integers that represent a section in the timecode structure.
![Timecode Representation](images/linear_timecode.png)


# Diagram
![Timecode Representation](images/time_decoder_diagram.png)

# References
https://en.wikipedia.org/wiki/Linear_timecode
