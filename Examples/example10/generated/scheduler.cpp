/*

Generated with CMSIS-Stream python scripts.
The generated code is not covered by CMSIS-Stream license.

The support classes and code are covered by CMSIS-Stream license.

*/


#include <cstdint>
#include "custom.hpp"
#include "cg_enums.h"
#include "StreamNode.hpp"
#include "EventQueue.hpp"
#include "GenericNodes.hpp"
#include "AppNodes.hpp"
#include "scheduler.h"

#if !defined(CHECKERROR)
#define CHECKERROR       if (cgStaticError < 0) \
       {\
         goto errorHandling;\
       }

#endif


#if !defined(CG_BEFORE_ITERATION)
#define CG_BEFORE_ITERATION
#endif 

#if !defined(CG_AFTER_ITERATION)
#define CG_AFTER_ITERATION
#endif 

#if !defined(CG_BEFORE_SCHEDULE)
#define CG_BEFORE_SCHEDULE
#endif

#if !defined(CG_AFTER_SCHEDULE)
#define CG_AFTER_SCHEDULE
#endif

#if !defined(CG_BEFORE_BUFFER)
#define CG_BEFORE_BUFFER
#endif

#if !defined(CG_BEFORE_FIFO_BUFFERS)
#define CG_BEFORE_FIFO_BUFFERS
#endif

#if !defined(CG_BEFORE_FIFO_INIT)
#define CG_BEFORE_FIFO_INIT
#endif

#if !defined(CG_BEFORE_NODE_INIT)
#define CG_BEFORE_NODE_INIT
#endif

#if !defined(CG_AFTER_INCLUDES)
#define CG_AFTER_INCLUDES
#endif

#if !defined(CG_BEFORE_SCHEDULER_FUNCTION)
#define CG_BEFORE_SCHEDULER_FUNCTION
#endif

#if !defined(CG_BEFORE_NODE_EXECUTION)
#define CG_BEFORE_NODE_EXECUTION(ID)
#endif

#if !defined(CG_AFTER_NODE_EXECUTION)
#define CG_AFTER_NODE_EXECUTION(ID)
#endif

#if !defined(CG_NODE_NOT_EXECUTED)
#define CG_NODE_NOT_EXECUTED(ID)
#endif

#if !defined(CG_ASYNC_BEFORE_NODE_CHECK)
#define CG_ASYNC_BEFORE_NODE_CHECK(ID)
#endif

#if !defined(CG_ASYNC_AFTER_NODE_CHECK)
#define CG_ASYNC_AFTER_NODE_CHECK(ID)
#endif




CG_AFTER_INCLUDES


using namespace arm_cmsis_stream;

/*

Description of the scheduling. 

*/
static uint8_t schedule[13]=
{ 
11,12,6,1,8,0,7,2,3,4,5,9,10,
};

/*

Internal ID identification for the nodes

*/
#define DEBUG_INTERNAL_ID 1
#define DEBUG0_INTERNAL_ID 2
#define DEBUG1_INTERNAL_ID 3
#define DEBUG2_INTERNAL_ID 4
#define DEBUG3_INTERNAL_ID 5
#define DUP0_INTERNAL_ID 6
#define DUP1_INTERNAL_ID 7
#define PROC_INTERNAL_ID 8
#define SINKA_INTERNAL_ID 9
#define SINKB_INTERNAL_ID 10
#define SOURCEEVEN_INTERNAL_ID 11
#define SOURCEODD_INTERNAL_ID 12




CG_BEFORE_FIFO_BUFFERS
/***********

FIFO buffers

************/
#define FIFOSIZE0 2
#define FIFOSIZE1 2
#define FIFOSIZE2 3
#define FIFOSIZE3 2
#define FIFOSIZE4 3
#define FIFOSIZE5 2
#define FIFOSIZE6 2
#define FIFOSIZE7 2
#define FIFOSIZE8 2
#define FIFOSIZE9 2
#define FIFOSIZE10 2
#define FIFOSIZE11 2

#define BUFFERSIZE0 2
CG_BEFORE_BUFFER
int16_t buf0[BUFFERSIZE0]={0};

#define BUFFERSIZE1 2
CG_BEFORE_BUFFER
int16_t buf1[BUFFERSIZE1]={0};

#define BUFFERSIZE2 3
CG_BEFORE_BUFFER
int16_t buf2[BUFFERSIZE2]={0};

#define BUFFERSIZE3 2
CG_BEFORE_BUFFER
int16_t buf3[BUFFERSIZE3]={0};

#define BUFFERSIZE4 3
CG_BEFORE_BUFFER
int16_t buf4[BUFFERSIZE4]={0};

#define BUFFERSIZE5 2
CG_BEFORE_BUFFER
int16_t buf5[BUFFERSIZE5]={0};

#define BUFFERSIZE6 2
CG_BEFORE_BUFFER
int16_t buf6[BUFFERSIZE6]={0};

#define BUFFERSIZE7 2
CG_BEFORE_BUFFER
int16_t buf7[BUFFERSIZE7]={0};

#define BUFFERSIZE8 2
CG_BEFORE_BUFFER
int16_t buf8[BUFFERSIZE8]={0};

#define BUFFERSIZE9 2
CG_BEFORE_BUFFER
int16_t buf9[BUFFERSIZE9]={0};

#define BUFFERSIZE10 2
CG_BEFORE_BUFFER
int16_t buf10[BUFFERSIZE10]={0};

#define BUFFERSIZE11 2
CG_BEFORE_BUFFER
int16_t buf11[BUFFERSIZE11]={0};


typedef struct {
FIFO<int16_t,FIFOSIZE0,0,1> *fifo0;
FIFO<int16_t,FIFOSIZE1,0,1> *fifo1;
FIFO<int16_t,FIFOSIZE2,0,1> *fifo2;
FIFO<int16_t,FIFOSIZE3,0,1> *fifo3;
FIFO<int16_t,FIFOSIZE4,0,1> *fifo4;
FIFO<int16_t,FIFOSIZE5,0,1> *fifo5;
FIFO<int16_t,FIFOSIZE6,0,1> *fifo6;
FIFO<int16_t,FIFOSIZE7,0,1> *fifo7;
FIFO<int16_t,FIFOSIZE8,0,1> *fifo8;
FIFO<int16_t,FIFOSIZE9,0,1> *fifo9;
FIFO<int16_t,FIFOSIZE10,0,1> *fifo10;
FIFO<int16_t,FIFOSIZE11,0,1> *fifo11;
} fifos_t;

typedef struct {
    NullSink<int16_t,1> *debug;
    NullSink<int16_t,1> *debug0;
    NullSink<int16_t,1> *debug1;
    NullSink<int16_t,1> *debug2;
    NullSink<int16_t,1> *debug3;
    Duplicate<int16_t,1,int16_t,1> *dup0;
    Duplicate<int16_t,1,int16_t,1> *dup1;
    ProcessingOddEven<int16_t,1,int16_t,1,int16_t,1> *proc;
    SinkAsync<int16_t,1> *sinka;
    SinkAsync<int16_t,1> *sinkb;
    SourceEven<int16_t,1> *sourceEven;
    SourceOdd<int16_t,1> *sourceOdd;
} nodes_t;


static fifos_t fifos={0};

static nodes_t nodes={0};


int init_scheduler()
{

    CG_BEFORE_FIFO_INIT;
    fifos.fifo0 = new (std::nothrow) FIFO<int16_t,FIFOSIZE0,0,1>(buf0);
    if (fifos.fifo0==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    fifos.fifo1 = new (std::nothrow) FIFO<int16_t,FIFOSIZE1,0,1>(buf1);
    if (fifos.fifo1==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    fifos.fifo2 = new (std::nothrow) FIFO<int16_t,FIFOSIZE2,0,1>(buf2);
    if (fifos.fifo2==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    fifos.fifo3 = new (std::nothrow) FIFO<int16_t,FIFOSIZE3,0,1>(buf3);
    if (fifos.fifo3==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    fifos.fifo4 = new (std::nothrow) FIFO<int16_t,FIFOSIZE4,0,1>(buf4);
    if (fifos.fifo4==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    fifos.fifo5 = new (std::nothrow) FIFO<int16_t,FIFOSIZE5,0,1>(buf5);
    if (fifos.fifo5==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    fifos.fifo6 = new (std::nothrow) FIFO<int16_t,FIFOSIZE6,0,1>(buf6);
    if (fifos.fifo6==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    fifos.fifo7 = new (std::nothrow) FIFO<int16_t,FIFOSIZE7,0,1>(buf7);
    if (fifos.fifo7==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    fifos.fifo8 = new (std::nothrow) FIFO<int16_t,FIFOSIZE8,0,1>(buf8);
    if (fifos.fifo8==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    fifos.fifo9 = new (std::nothrow) FIFO<int16_t,FIFOSIZE9,0,1>(buf9);
    if (fifos.fifo9==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    fifos.fifo10 = new (std::nothrow) FIFO<int16_t,FIFOSIZE10,0,1>(buf10);
    if (fifos.fifo10==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    fifos.fifo11 = new (std::nothrow) FIFO<int16_t,FIFOSIZE11,0,1>(buf11);
    if (fifos.fifo11==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }

    CG_BEFORE_NODE_INIT;

    nodes.debug = new (std::nothrow) NullSink<int16_t,1>(*(fifos.fifo4));
    if (nodes.debug==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    nodes.debug0 = new (std::nothrow) NullSink<int16_t,1>(*(fifos.fifo8));
    if (nodes.debug0==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    nodes.debug1 = new (std::nothrow) NullSink<int16_t,1>(*(fifos.fifo9));
    if (nodes.debug1==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    nodes.debug2 = new (std::nothrow) NullSink<int16_t,1>(*(fifos.fifo10));
    if (nodes.debug2==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    nodes.debug3 = new (std::nothrow) NullSink<int16_t,1>(*(fifos.fifo11));
    if (nodes.debug3==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    nodes.dup0 = new (std::nothrow) Duplicate<int16_t,1,int16_t,1>(*(fifos.fifo2),{fifos.fifo3,fifos.fifo4});
    if (nodes.dup0==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    nodes.dup1 = new (std::nothrow) Duplicate<int16_t,1,int16_t,1>(*(fifos.fifo5),{fifos.fifo6,fifos.fifo7,fifos.fifo8,fifos.fifo9,fifos.fifo10,fifos.fifo11});
    if (nodes.dup1==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    nodes.proc = new (std::nothrow) ProcessingOddEven<int16_t,1,int16_t,1,int16_t,1>(*(fifos.fifo3),*(fifos.fifo0),*(fifos.fifo1));
    if (nodes.proc==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    nodes.sinka = new (std::nothrow) SinkAsync<int16_t,1>(*(fifos.fifo6));
    if (nodes.sinka==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    nodes.sinkb = new (std::nothrow) SinkAsync<int16_t,1>(*(fifos.fifo7));
    if (nodes.sinkb==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    nodes.sourceEven = new (std::nothrow) SourceEven<int16_t,1>(*(fifos.fifo0));
    if (nodes.sourceEven==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }
    nodes.sourceOdd = new (std::nothrow) SourceOdd<int16_t,1>(*(fifos.fifo2));
    if (nodes.sourceOdd==NULL)
    {
        return(CG_MEMORY_ALLOCATION_FAILURE);
    }

/* Subscribe nodes for the event system*/


    return(CG_SUCCESS);

}

void free_scheduler()
{
    if (fifos.fifo0!=NULL)
    {
       delete fifos.fifo0;
    }
    if (fifos.fifo1!=NULL)
    {
       delete fifos.fifo1;
    }
    if (fifos.fifo2!=NULL)
    {
       delete fifos.fifo2;
    }
    if (fifos.fifo3!=NULL)
    {
       delete fifos.fifo3;
    }
    if (fifos.fifo4!=NULL)
    {
       delete fifos.fifo4;
    }
    if (fifos.fifo5!=NULL)
    {
       delete fifos.fifo5;
    }
    if (fifos.fifo6!=NULL)
    {
       delete fifos.fifo6;
    }
    if (fifos.fifo7!=NULL)
    {
       delete fifos.fifo7;
    }
    if (fifos.fifo8!=NULL)
    {
       delete fifos.fifo8;
    }
    if (fifos.fifo9!=NULL)
    {
       delete fifos.fifo9;
    }
    if (fifos.fifo10!=NULL)
    {
       delete fifos.fifo10;
    }
    if (fifos.fifo11!=NULL)
    {
       delete fifos.fifo11;
    }

    if (nodes.debug!=NULL)
    {
        delete nodes.debug;
    }
    if (nodes.debug0!=NULL)
    {
        delete nodes.debug0;
    }
    if (nodes.debug1!=NULL)
    {
        delete nodes.debug1;
    }
    if (nodes.debug2!=NULL)
    {
        delete nodes.debug2;
    }
    if (nodes.debug3!=NULL)
    {
        delete nodes.debug3;
    }
    if (nodes.dup0!=NULL)
    {
        delete nodes.dup0;
    }
    if (nodes.dup1!=NULL)
    {
        delete nodes.dup1;
    }
    if (nodes.proc!=NULL)
    {
        delete nodes.proc;
    }
    if (nodes.sinka!=NULL)
    {
        delete nodes.sinka;
    }
    if (nodes.sinkb!=NULL)
    {
        delete nodes.sinkb;
    }
    if (nodes.sourceEven!=NULL)
    {
        delete nodes.sourceEven;
    }
    if (nodes.sourceOdd!=NULL)
    {
        delete nodes.sourceOdd;
    }
}


CG_BEFORE_SCHEDULER_FUNCTION
uint32_t scheduler(int *error)
{
    int cgStaticError=0;
    uint32_t nbSchedule=0;
    int32_t debugCounter=10;





    /* Run several schedule iterations */
    CG_BEFORE_SCHEDULE;
    while((cgStaticError==0) && (debugCounter > 0))
    {
        /* Run a schedule iteration */
        CG_BEFORE_ITERATION;
        unsigned long id=0;
        for(; id < 13; id++)
        {
            CG_BEFORE_NODE_EXECUTION(schedule[id]);
            cgStaticError = 0;
            CG_ASYNC_BEFORE_NODE_CHECK(schedule[id]);
            switch(schedule[id])
            {
                case 0:
                {
                                        
                    bool canRun=true;
                    canRun &= !(fifos.fifo1->willUnderflowWith(1));
                    canRun &= !(fifos.fifo5->willOverflowWith(1));

                    if (!canRun)
                    {
                      cgStaticError = CG_SKIP_EXECUTION_ID_CODE;
                    }
                    else
                    {
                        cgStaticError = 0;
                    }
                }
                break;

                case 1:
                {
                    cgStaticError = nodes.debug->prepareForRunning();
                }
                break;

                case 2:
                {
                    cgStaticError = nodes.debug0->prepareForRunning();
                }
                break;

                case 3:
                {
                    cgStaticError = nodes.debug1->prepareForRunning();
                }
                break;

                case 4:
                {
                    cgStaticError = nodes.debug2->prepareForRunning();
                }
                break;

                case 5:
                {
                    cgStaticError = nodes.debug3->prepareForRunning();
                }
                break;

                case 6:
                {
                    cgStaticError = nodes.dup0->prepareForRunning();
                }
                break;

                case 7:
                {
                    cgStaticError = nodes.dup1->prepareForRunning();
                }
                break;

                case 8:
                {
                    cgStaticError = nodes.proc->prepareForRunning();
                }
                break;

                case 9:
                {
                    cgStaticError = nodes.sinka->prepareForRunning();
                }
                break;

                case 10:
                {
                    cgStaticError = nodes.sinkb->prepareForRunning();
                }
                break;

                case 11:
                {
                    cgStaticError = nodes.sourceEven->prepareForRunning();
                }
                break;

                case 12:
                {
                    cgStaticError = nodes.sourceOdd->prepareForRunning();
                }
                break;

                default:
                break;
            }

            CG_ASYNC_AFTER_NODE_CHECK(schedule[id]);

            if (cgStaticError == CG_SKIP_EXECUTION_ID_CODE)
            { 
              cgStaticError = 0;
              CG_NODE_NOT_EXECUTED(schedule[id]);
              continue;
            }

            
            CHECKERROR;

            switch(schedule[id])
            {
                case 0:
                {
                    
                   
                  {

                   int16_t* i0;
                   int16_t* o1;
                   i0=fifos.fifo1->getReadBuffer(1);
                   o1=fifos.fifo5->getWriteBuffer(1);
                   compute(i0,o1,1);
                   cgStaticError = 0;
                  }
                }
                break;

                case 1:
                {
                    
                   cgStaticError = nodes.debug->run();
                }
                break;

                case 2:
                {
                    
                   cgStaticError = nodes.debug0->run();
                }
                break;

                case 3:
                {
                    
                   cgStaticError = nodes.debug1->run();
                }
                break;

                case 4:
                {
                    
                   cgStaticError = nodes.debug2->run();
                }
                break;

                case 5:
                {
                    
                   cgStaticError = nodes.debug3->run();
                }
                break;

                case 6:
                {
                    
                   cgStaticError = nodes.dup0->run();
                }
                break;

                case 7:
                {
                    
                   cgStaticError = nodes.dup1->run();
                }
                break;

                case 8:
                {
                    
                   cgStaticError = nodes.proc->run();
                }
                break;

                case 9:
                {
                    
                   cgStaticError = nodes.sinka->run();
                }
                break;

                case 10:
                {
                    
                   cgStaticError = nodes.sinkb->run();
                }
                break;

                case 11:
                {
                    
                   cgStaticError = nodes.sourceEven->run();
                }
                break;

                case 12:
                {
                    
                   cgStaticError = nodes.sourceOdd->run();
                }
                break;

                default:
                break;
            }
            CG_AFTER_NODE_EXECUTION(schedule[id]);
                        CHECKERROR;
        }
       debugCounter--;
       CG_AFTER_ITERATION;
       nbSchedule++;
    }
errorHandling:
    CG_AFTER_SCHEDULE;
    *error=cgStaticError;
    return(nbSchedule);
    
}
