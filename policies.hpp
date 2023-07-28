#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <stdio.h>
#include "dataStructures.hpp"
#include <string>

#ifndef POLICIES_H
#define POLICIES_H

void fifo(char* tracefile, int nframes, int mode);
void lru(char* tracefile, int nframes, int mode);
void segmentedfifo(char* tracefile, int nframes, int percentage, int mode);

#endif