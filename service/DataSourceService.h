#ifndef __DATA_SOURCE_SERVICE_H__
#define __DATA_SOURCE_SERVICE_H__


#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <IPluginControler.h>
#include <IDataSourceService.h>



class DataSourceServiceImpl : public BnDataSourceService
{
public:
    bool isPluginEnable(void);
    void setPluginEnable(bool enable);
    void setPluginControler(sp<IPluginControler> controler);
    void removePluginControler();

    static void instance()
    {
        defaultServiceManager()->addService(String16("DataPluginService"), new DataSourceServiceImpl());
    }

private:
    sp<IPluginControler> mPluginCtrl;
};










#endif /* __DATA_SOURCE_SERVICE_H__ */
























