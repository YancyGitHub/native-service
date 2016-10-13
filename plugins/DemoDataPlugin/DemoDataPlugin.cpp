
#include "DemoDataPlugin.h"
#include <binder/IServiceManager.h>
#include <IDataSourceService.h>


extern "C"
{
    void * create_plugin()
    {
        return DemoDataPlugin::createInstance();
    }

    plugin_entry_t PLUGIN_INFO = {
        p_plugin_entry : create_plugin,
        handle         : NULL,
    };
}

DemoDataPlugin * DemoDataPlugin::createInstance()
{
    static DemoDataPlugin Singleton;
    return &Singleton;
}

DemoDataPlugin::~DemoDataPlugin()
{
}

void DemoDataPlugin::onDataSourceEvent(int val, const char * str)
{
    // Do nothing
}

void DemoDataPlugin::onInit()
{
    sp<IBinder> binder = defaultServiceManager()->getService(String16("DataPluginService"));
    if(binder == NULL)
    {
        printf("Get service fail\n");
        return;
    }

    mService = IDataSourceService::asInterface(binder);
    if(mService == NULL)
    {
        return;
    }

    sp<IPluginControler> ret = this;
    mService->setPluginControler(ret);
    ret->isEnable();
    ret->setEnable(false);
    printf("DemoDataPlugin onInit...\n");
}

void DemoDataPlugin::onStart()
{
    this->mIsEnable = true;
    printf("DemoDataPlugin onStart...\n");
}

void DemoDataPlugin::onStop()
{
    //Stop thread.
    if(mService != NULL) {
        mService->removePluginControler();
    }
    this->mIsEnable = false;
    printf("DemoDataPlugin onStop...\n");
}

sp<IPluginControler> DemoDataPlugin::getPluginControler()
{
    sp<IPluginControler> ret = this;
    
    printf("DemoDataPlugin getPluginControler... this:%p \n", this);

    return ret;
}

bool DemoDataPlugin::isEnable()
{
    printf("DemoDataPlugin isEnable...\n");
    return this->mIsEnable;
}

void DemoDataPlugin::setEnable(bool enable)
{
    printf("DemoDataPlugin setEnable enable=%d\n", enable);
    this->mIsEnable = enable;
}



