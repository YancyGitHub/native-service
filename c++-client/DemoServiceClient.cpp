
#include <binder/IServiceManager.h>  
#include "../common/IDemoService.h"  


int main()
{
    sp<IBinder> binder = defaultServiceManager()->getService(String16(SERVICE_NAME));  
    if(binder == NULL)
    {  
        printf("Failed to get service: %s.\n", SERVICE_NAME);  
        return -1;  
    }  

    sp<IDemoService> service = IDemoService::asInterface(binder);  
    if(service == NULL)  
    {  
        return -2;  
    }

    printf("AddNumber(12, 13)=%d\n", service->AddNumber(12, 13));
    printf("MaxNumber(12, 13)=%d\n", service->MaxNumber(12, 13));
    printf("MaxNumber(16, 13)=%d\n", service->MaxNumber(16, 13));
}







































