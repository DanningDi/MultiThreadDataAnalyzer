#ifndef SUPERVISOR
#define SUPERVISOR

#include <vector>
#include "Worker.h"
#include "JobBoard.h"

class Supervisor{
    private:
    std::vector<Worker*> workers;
    JobBoard *jobBoard;
    int riceCount = 0;

    public:
    void callout();
    void recruitWorker();
    void aquireJobBoard(JobBoard *jB);
    Job* giveJob();
    void startWork();
    void postJob(Job *job);
    void postResult();
};

#endif