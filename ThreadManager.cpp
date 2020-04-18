#include "ThreadManager.h"

ThreadManager::ThreadManager(Parse* parser, const map<string, string>& files, const Header& settings) :
    parser_(parser), files_(files), settings_(settings), semaphore_(new sem_t)
{
    sem_init(semaphore_, 0, 1);
    createThreads();
}

void* wrapperFunction(void* args)
{
    threadArgs* argsCasted = (threadArgs*) args;
    sem_wait(argsCasted->semaphore);
    argsCasted->parser->generateDocumentation(argsCasted->fileName, argsCasted->settings);
    sem_post(argsCasted->semaphore);
    return 0;
}

void ThreadManager::createThreads()
{
    threadArgs args[files_.size()];
    int i = 0;
    for(auto&& element: files_)
    {
        args[i] = (threadArgs) {element.second, settings_, parser_, semaphore_};
        pthread_create(&tids_[i++], NULL, wrapperFunction, (void*)&args[i]);
    }
    for (int j = 0; j < i; ++j)
        pthread_join(tids_[j], NULL);
}

ThreadManager::~ThreadManager()
{
    sem_destroy(semaphore_);
    delete semaphore_;
}