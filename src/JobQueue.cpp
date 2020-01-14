#include "JobQueue.h"
#include <iostream>

Job* JobQueue::popJob(){
    Job *j;
    queueLock.lock();
    if(jobs.size() == 0){
        j = nullptr;
    }else{
        j = jobs.front();
    }
    jobs.pop();
    queueLock.unlock();
    return j;
    
}

void JobQueue::pushJob(Job *job){
    queueLock.lock();
    jobs.push(job);
    queueLock.unlock();
}

int JobQueue::getSize(){
    return jobs.size();
}