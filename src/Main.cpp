#include "Supervisor.h"

int main(){
    Supervisor *s = new Supervisor();
    s -> callout();
    JobBoard *jobBoard = new JobBoard();
    s -> aquireJobBoard(jobBoard);
    s -> recruitWorker();
    s -> recruitWorker();
    
    s -> startWork();

    return 0;
}