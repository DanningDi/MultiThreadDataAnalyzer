#ifndef WORKER
#define WORKER

#include<vector>

#include "Job.h"
#include "JobManualHub.h"
//#include "Supervisor.h"
class Supervisor;
class Worker{
    private:
//    std::vector<int> skills
    bool isActive = true;
    int workerID;
    Job *job_todo;
    Job *job_done;
    JobManualHub *myJobManualHub;
    Supervisor *supervisor;

    public:
    void callout();
    void startWork();
    Worker(Supervisor *s);
    Worker(int _workerID, Supervisor *s);
    bool requestJob();
    void doJob();
    void submmitJob();
    //void   
};

#endif