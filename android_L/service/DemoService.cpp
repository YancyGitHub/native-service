

#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>  
#include "../common/IDemoService.h"  
#include "DemoService.h"

#define LOG_NDEBUG 0
#define LOG_TAG "DEMOSERVICE"  
  
#include <utils/Log.h>  


int DemoService::AddNumber(int a,int b)
{
    ALOGD("DemoService AddNumber a:%d, b:%d\n", a, b);
    return a + b;
}

int DemoService::MaxNumber(int a,int b)
{
    ALOGD("DemoService MaxNumber a:%d, b:%d\n", a, b);
    return a > b ? a : b;
}

int main(int argc, char** argv)  
{  
    DemoService::instance();  

    ProcessState::self()->startThreadPool();  
    IPCThreadState::self()->joinThreadPool();  
  
    return 0;  
} 


































