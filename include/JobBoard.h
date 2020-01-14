#ifndef JOBBOARD
#define JOBBOARD

#include <string>
#include "Data.h"
#include "Job.h"
#include <mutex>
#include <unordered_map>
#include <queue>
#include "JobQueue.h"
#include <iostream>

class JobBoard{
    private:
    std::mutex boardLock;
    int jobCounter = 0;
    int jobsLeft = 10;
    std::unordered_map<std::string, JobQueue*> jobQueues;


//    std::string job_type;
//    Data* input;
    public:
    Job* nextJob();
    void pushJob(Job *job);
    JobQueue* selectQueue();
    JobBoard(){
        jobQueues["sand to gold"] = new JobQueue();
        jobQueues["gold to seed"] = new JobQueue();
        jobQueues["seed to plant"] = new JobQueue();
        jobQueues["plant to rice"] = new JobQueue();
        std::cout<<"ok?"<<std::endl;
        for (int i = 0; i < jobsLeft; ++i) {
            jobQueues["sand to gold"] -> pushJob(new Job("sand to gold"));
        }
        std::cout<<"ok!"<<std::endl;
    }
};


#endif