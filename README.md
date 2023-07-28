Page Replacement Simulator Program 

This program simulates a Page Replacement Algorithm based on different models. The program takes in memory traces as inputs, scans through them and stores the address (divided by 4096) and read-write permission of each in a memElem object. This object can then be either stored or used to replace an entry in our page table (simulated by a standard library deque in c++). Finally, the program keeps track of the number of events, number of reads and number of writes in memory. Read count and write count are increased when an element is removed from the page table and contains either an R or a W in their read-write access respectively. 

This page replacement simulator supports 2 different algorithms, which are FIFO (First In First Out) and LRU (Least Recently Used). 

The executable file can be created by running the make command or alternatively running the compile statement: g++ -o memsim memsim.cpp fifo.cpp lru.cpp vms.cpp dataStructures.cpp 
This creates the memsim executable, which can then be run by using the statement: ./memsim tracefile numFrames fifo/lru/vms quiet/debug 

tracefile: name of the file containing the traces.
numFrames: number of page frames the simulated page table will contain. Must be greater than 0.
fifo/lru/vms: algorithm type that will be used for page replacement. Must select only one of the three (vms currently not supported)
quiet/debug: quiet will display only the number of traces, total disk reads and writes, while debug will display every single operation done on the page table.

For example: compiling the statement ./memsim bzip.trace 14 lru quiet
Should print out: 
Total number of frames: 14
Events in trace: 1000000
Total disk reads: 3598
Total disk writes: 1146