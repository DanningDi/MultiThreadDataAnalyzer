#ifndef SUPERVISOR
#define SUPERVISOR

#include <vector>
#include "Worker.h"
#include "JobBoard.h"
#include "JobManualHub.h"

class Supervisor{
    private:
    std::vector<Worker*> workers;
    JobBoard *jobBoard;
    JobManualHub *myJobManualHub;
    int riceCount = 0;

    public:
    void callout();
    void recruitWorker();
    void aquireJobBoard(JobBoard *jB);
    void addJobManualHub(JobManualHub *jobManualHub);
    JobManualHub* getJobManualHub();
    Job* giveJob();
    void startWork();
    void postJob(Job *job);
    void postResult();
};

#endif