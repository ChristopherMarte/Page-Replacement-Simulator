#include "policies.hpp"

void lru(char* tracefile, int nframes, int mode){
   
    // Open file and declaration of variables
    std::cout << "Total number of frames: " << nframes << "\n";
    FILE* fp;
    fp = fopen(tracefile, "r");
    if(fp == NULL){
        std::cout << "Could not open file\n";
        return;
    }
    int accesses = 0;
    int reads = 0;
    int writes = 0;
    unsigned int addr;
    char rw;
    std::deque<memElem> pageTable;
    char writeAccess = 'W';
    char readAccess = 'R';

    // Read until end of file
    while(fscanf(fp,"%x %c",&addr,&rw) != EOF){

        accesses++;
        memElem pageEntry;
        pageEntry.addr = addr/4096;
        pageEntry.rw = rw;
        bool found = false;
        int position = 0;
        // Check if the address is in page table and change rw to W if value is a 'W', otherwise keep the value
        for(int i = 0; i < int(pageTable.size()); i++){
            if(pageTable[i].addr == pageEntry.addr && pageEntry.rw == writeAccess){
                pageTable[i].rw = writeAccess;
                found = true;
                position = i;
                break;
            }
            else if(pageTable[i].addr == pageEntry.addr && pageEntry.rw == readAccess){
                found = true;
                position = i;
                break;
            } 
        }

        // Page is in LRU, update for recency 

        if(found == true){

            pageTable.push_back(pageTable[position]);
            pageTable.erase(pageTable.begin() + position);
            
        }

        // Page is not in LRU and LRU is full, if evicted page is W, increase writes

        if(int(pageTable.size()) == nframes && found == false){
            if(pageTable.front().rw == writeAccess){
                writes++;
            }

            if(mode == 0){
                std::cout << "Page table full. Removing " << pageTable.front().addr <<" with "<< pageTable.front().rw<< " and pushing " << pageEntry.addr << " with " << pageEntry.rw << " to page table.\n";
            }

            reads++;
            pageTable.pop_front();
            pageTable.push_back(pageEntry);
        }

        // Page is not in LRU and LRU is not full, push into LRU and increase reads

        else if(int(pageTable.size()) < nframes && found == false){
            pageTable.push_back(pageEntry);
            reads++;
            if(mode == 0){
                std::cout << "Pushing " << pageEntry.addr << "with " << pageEntry.rw << "to page table.\n";
            }
        }
    
    }
    // Print accesses, reads and writes
    std::cout << "Events in trace: " << accesses << "\n";
    std::cout << "Total disk reads: " << reads << "\n";
    std::cout << "Total disk writes: " << writes << "\n";
    fclose(fp);

}
