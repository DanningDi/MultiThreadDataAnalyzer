#ifndef JOBMANUALHUB
#define JOBMANUALHUB

#include <unordered_map>
#include <string>

#include "Job.h"
#include "JobManual.h"

class JobManualHub{
    private:
    std::unordered_map<std::string, JobManual*> existingManuals; 
    public:
    Job *doJob(Job* jobToDo);
    void addManual(JobManual* newManual);
};


#endif