#include "JobBoard.h"
#include<iostream>
#include <stdlib.h>
#include <vector>

void JobBoard::addFinishedJobs(){
    nJobsFinished++;
}

int JobBoard::get_nJobsFinished(){
    return nJobsFinished;
}

void JobBoard::reportJobStatus(){
    std::cout << nJobsFinished << " ## ";
    for(auto jobQueue : jobQueues){
        std::cout << jobQueue.first << " " << (jobQueue.second) -> getSize() << " ";
    }
    std::cout << std::endl;
   // getchar();
}

Job* JobBoard::nextJob(){
    Job *j;
    boardLock.lock();
    if(jobsLeft == 0){
        j = nullptr;
    }else{
        JobQueue *jobQueue = selectQueue();
        j = jobQueue -> popJob();
        jobsLeft--;
    }
    reportJobStatus();
    boardLock.unlock();
    return j;
}

void JobBoard::pushJob(Job *job){
    boardLock.lock();
    std::cout<<"JobBoard Pushing job : "<<std::endl;
    std::cout<<job -> getType()<<std::endl;

    std::string jobType = job -> getType();
    jobQueues[jobType] -> pushJob(job);
    jobsLeft++;

    boardLock.unlock();

}

JobQueue* JobBoard::selectQueue(){
    int nQueues = jobQueues.size();
    int theOne = rand() % nQueues;
    std::vector<std::string> vstring = {"sand to gold", "gold to seed", "seed to plant", "plant to rice"};
    while (jobQueues[vstring[theOne]] -> getSize() == 0) {
        theOne = rand() % nQueues;
    }
    std::cout<<"selected job: "<<vstring[theOne]<<std::endl;
    return jobQueues[vstring[theOne]];
}