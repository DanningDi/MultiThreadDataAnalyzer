#include "Job.h"

Job::Job(std::string type){
    job_type = type;
}

std::string Job::getType(){
    return job_type;
}