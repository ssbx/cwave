/*
 * CWAVE Copyright (c) 2016 Sebastien Serre <ssbx@sysmo.io>.
 *
 * This file is provided to you under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See
 * the License for the specific language governing permissions and limitations
 * under the License.
 */
#include "cwave.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>


int main(int argc, char* argv[])
{

    if (argc < 3) exit(1);

    int shouldFail = strncmp(argv[2], "fail", 4);

    CWAVE_DATA* data = cwaveOpen(argv[1]);

    if (data == NULL) {
        if (shouldFail != 0) {
            printf("Read wav file status: failure\n");
            return 1;
        } else {
            printf("Read wav file status: success\n");
            return 0;
        }
    }

    printf("Read wav file status: success\n");
    cwaveFree(data);
    return 0;

}
