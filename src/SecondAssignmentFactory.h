//
// Created by xMellox on 11-Aug-20.
//

#ifndef TESTTASK_SECONDASSIGNMENTFACTORY_H
#define TESTTASK_SECONDASSIGNMENTFACTORY_H

#include "TaskFactory.h"
#include <map>

struct SecondAssignmentFactory: public ITaskFactory
{
    SecondAssignmentFactory();
    std::unique_ptr<ITask> CreateTask(const std::string& TaskName) override;
    
private:
   std::map<std::string, std::unique_ptr<ITask>> m_tasks;    
};


#endif //TESTTASK_SECONDASSIGNMENTFACTORY_H
