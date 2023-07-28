#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "policies.hpp"

int main(int argc, char *argv[]){
    
    //Input validation
    if(argc < 5){
        std::cout<<"Insufficient number of command line arguments\n";
        return 0;
    }

    char* tracefile = argv[1];
    int nframes = atoi(argv[2]);
    if(nframes <= 0){
        std::cout << "Number of frames must be greater than 0.\n";
        return 0; 
    }

    char* policy = argv[3];
    int quiet;

    for(int i = 0; i < int(strlen(policy)); i++){
        policy[i]=tolower(policy[i]);
    }
    // If 5 Arguments, must be either fifo or LRU
    if(argc == 5){
        char* mode = argv[4];
        
        for(int i = 0; i < int(strlen(mode)); i++){
            mode[i]=tolower(mode[i]);
        }
        if (strcmp(mode, "quiet")==0){
            quiet = 1;
        }
        else {
            quiet = 0; //debug mode
        }


        if(strcmp(policy, "fifo")==0){
            fifo(tracefile, nframes, quiet);
        }
        else if(strcmp(policy, "lru")==0){
            lru(tracefile, nframes, quiet);
        }
    }

    // Else, if 6 arguments, check for vms
    else if(argc == 6 && (strcmp(policy, "vms")==0)){
        int percentage = atoi(argv[4]);
        char* mode = argv[5];
        for(int i = 0; i < int(strlen(mode)); i++){
            mode[i]=tolower(mode[i]);
        }
        if (strcmp(mode, "quiet")==0){
            quiet = 1;
        }
        else {
            quiet = 0; //debug mode
        }

        segmentedfifo(tracefile, nframes, percentage,quiet);
    }
    // Otherwise, incorrect number of command line arguments for each policy
    else {

        std::cout<<"Invalid number of command line arguments\n";

    }


    return 0;
}