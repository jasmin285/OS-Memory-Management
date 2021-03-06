#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include "memory.h"
#include <QString>
#include <QVector>

class Allocator
{
/*private:
    bool checkIfAvailable(QVector<unsigned long> *limits);*/

protected:
    Memory *memory;
   // virtual void allocateSegment(QString name, unsigned long limit) = 0;

public:
    Allocator(Memory *memory);
    virtual bool allocateProcess(QString processName, QVector<QString> *segmentsNames, QVector<unsigned long> *limits
                                 ,bool reallocate=false , Process * ptr = NULL) = 0 ;
    virtual bool reallocateProcess(Process *process) = 0;
};

#endif // ALLOCATOR_H_
