#ifndef JOBMANUAL
#define JOBMANUAL

#include <string>
#include "Job.h"

class JobManual{
    private:
    std::string type;
    public:
    JobManual(std::string _type) {
        this -> type = _type;
    }

    Job *doJob(Job* jobToDo);
    std::string getType(){
        return type;
    }

};



#endif