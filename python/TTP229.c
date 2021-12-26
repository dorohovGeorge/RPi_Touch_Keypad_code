/*****************************************************************************
* | File        :   dev_hardware_i2c.c
* | Author      :   Waveshare team
* | Function    :   Read and write /dev/i2C,  hardware I2C
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2019-06-26
* | Info        :   Basic version
*
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "TTP229.h"

#include <stdio.h>
#include <stdlib.h>   //exit()  
#include <fcntl.h>    //define O_RDWR  
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int fd;
uint16_t TTP229_GetVal(void)
{
    if((fd = open("/dev/i2c-1", O_RDWR)) < 0)  {
        perror("Failed to open i2c device.\n");
        exit(1);
    }

    if(ioctl(fd, I2C_SLAVE, 0x57) < 0)  {
        printf("Failed to access bus.\n");
        exit(1);
    }

    char buf[2];
    read(fd, buf, 2);    

    if (close(fd) != 0) {
        perror("Failed to close i2c device.\n");
    }
    
    return buf[0]<< 8 | buf[1];
}