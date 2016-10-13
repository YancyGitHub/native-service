#ifndef __DEMO_DATA_PLUGIN_H__
#define __DEMO_DATA_PLUGIN_H__

#include <utils/RefBase.h>
#include <IDataSourcePlugin.h>
#include <IPluginControler.h>
#include <IDataSourceService.h>

using namespace android;
using android::sp;


class DemoDataPlugin
    : public IDataSourcePlugin, public BnPluginControler
{
public:
    static DemoDataPlugin * createInstance(void);
    ~DemoDataPlugin();
    void onDataSourceEvent(int val, const char * str);
    void onInit(void);
    void onStart(void);
    void onStop(void);
    sp<IPluginControler> getPluginControler(void);
    bool isEnable();
    void setEnable(bool enable);

private:
    sp<IDataSourceService> mService;
    bool mIsEnable;
};








#endif /* __DEMO_DATA_PLUGIN_H__ */
















