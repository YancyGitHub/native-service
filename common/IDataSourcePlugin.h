#ifndef __I_DATA_SOURCE_PLUGIN_H__
#define __I_DATA_SOURCE_PLUGIN_H__


#include <IPluginControler.h>

using namespace android;
using android::sp;


class IDataSourcePlugin
{
public:
    IDataSourcePlugin(){};
    virtual ~IDataSourcePlugin(){};
    virtual void onDataSourceEvent(int val, const char * str) = 0;
    virtual void onInit(void) = 0;
    virtual void onStart(void) = 0;
    virtual void onStop(void) = 0;
    virtual sp<IPluginControler> getPluginControler(void) = 0;
};



#define PLUGIN_LIB_NAME         "libDataSourcePlugin.so"
#define PLUGIN_ENTRY_SYM        "PLUGIN_ENTRY"
#define PLUGIN_INFO             PLUGIN_ENTRY

typedef struct plugin_entry_t
{
	void * (*p_plugin_entry)(void);
	void * handle;
};

int get_plugin(const struct plugin_entry_t ** entry);








#endif /* __I_DATA_SOURCE_PLUGIN_H__ */





























