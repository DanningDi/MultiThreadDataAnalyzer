#ifndef JOB_QUEUE
#define JOB_QUEUE

#include <queue>
#include <mutex>
#include "Job.h"

class JobQueue{
    private:
    std::queue<Job*> jobs;
    std::mutex queueLock;
    public:
    Job* popJob();
    void pushJob(Job *job);
    int getSize();

};



#endif