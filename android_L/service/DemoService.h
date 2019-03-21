#ifndef __DEMO_SERVICE_H__
#define __DEMO_SERVICE_H__

#include "../common/IDemoService.h"


class DemoService : public BnDemoService
{
public:
    int AddNumber(int a, int b);
    int MaxNumber(int a, int b);   
    static void instance()
    {
        defaultServiceManager()->addService(String16(SERVICE_NAME), new DemoService());
    };
};

#endif /* __DEMO_SERVICE_H__ */








