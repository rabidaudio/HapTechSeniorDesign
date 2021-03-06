 /* Copyright (c) 2011, RidgeRun
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the RidgeRun.
 * 4. Neither the name of the RidgeRun nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY RIDGERUN ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL RIDGERUN BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "GPIO.h"
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

	int readGPIO(int pin) {
		int fd;
		char buf[32];
		char ch;

		snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", pin);

		fd = open(buf, O_RDONLY);


		if (fd < 0) {
			perror("gpio/get-value");
			return fd;
		}

		int err = read(fd, &ch, 1);

		if (err < 0) {
			std::cout <<"read failed!\n";
			return -1;
		}

		if (close(fd) < 0) {
			std::cout <<"close failed!\n";
			return -1;
		} 

		return atoi(&ch);
	}


	int readAI(int pin) {
		int fd;
		char buf[35];
		char ch;

		snprintf(buf, sizeof(buf), SYSFS_AI_DIR "/AIN%d", pin);
		fd = open(buf, O_RDONLY);
		//std::cout << "fd open: " << fd <<"\n";

		if (fd < 0) {
			perror("ain/get-value");
			return fd;
		}
		//std::cout << "fd open: " << fd <<"\n";
		int err = read(fd, &ch, 4); 
		//std::cout << "fd after open: " << fd <<"\n";*/

		if (err < 0) {
			std::cout <<"read failed!\n";
			return -1;
		}
		//std::cout << "fd read: " << fd <<"\n";

		if (close(fd) < 0) {
			std::cout <<"close failed!\n";
			return -1;
		} 
		//std::cout << "fd close: " << fd <<"\n";

		return atoi(&ch);
	}

