#ifndef JOB
#define JOB

#include <string>
#include "Data.h"

class Job{
    private:
    std::string job_type;
    Data* input;
    public:
    Job(std::string type);
    std::string getType();
};


#endif