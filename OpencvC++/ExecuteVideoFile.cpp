#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
int main()
{
system("sudo  bash /home/pi/DeleteVideoFiles.sh");
system("sudo /home/pi/OpencvC++/30SecVid");
system("sudo bash /home/pi/ConvertVideoFile.sh");
system("sudo bash /home/pi/uploadVideo.sh");

}