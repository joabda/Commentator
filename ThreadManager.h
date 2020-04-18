#pragma once

#include "Parse.h"
#include <pthread.h>
#include <string>
#include <map>
#include <memory>
#include <semaphore.h>

using namespace std;

typedef struct 
{
    string fileName;
    Header settings;
    Parse* parser;
    sem_t* semaphore;
} threadArgs;

class ThreadManager
{
public:
    ThreadManager(Parse* parser, const map<string, string>& files, const Header& settings);
    ~ThreadManager();

private: 
    Parse* parser_;
    const map<string, string>& files_;
    const Header& settings_;
    vector<pthread_t> tids_;
    sem_t* semaphore_;

    void createThreads();
};