
#include <binder/IServiceManager.h>
#include <IDataSourceService.h>

using namespace android;
using android::sp;

int main()
{
    sp<IBinder> binder = defaultServiceManager()->getService(String16("DataPluginService"));
    if(binder == NULL)
    {
        printf("Get service fail\n");
        return 0;
    }

    sp<IDataSourceService> service = IDataSourceService::asInterface(binder);
    if(service == NULL)
    {
        printf("connect service fail\n");
        return 0;
    }

    int input = -1;
    while(1)
    {
        printf("[1]Enable plugin; [2]Disable plugin; [3]Quit: ");
        scanf("%d", &input);

        switch(input)
        {
            case 1:
                printf("DataSourceClient enable plugin\n");
                service->setPluginEnable(true);
                break;
            case 2:
                printf("DataSourceClient disable plugin\n");
                service->setPluginEnable(false);
                break;
            case 3:
                printf("DataSourceClient exit \n");
                goto Exit;
        }
    } // while

Exit:
    printf("Client exit...\n");

    return 0;
}


























