#ifndef __I_DATA_SOURCE_SERVICE_H__
#define __I_DATA_SOURCE_SERVICE_H__

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include "IPluginControler.h"

using namespace android;
using android::sp;

enum {
    IS_PLUGIN_ENABLE = IBinder::FIRST_CALL_TRANSACTION,
    SET_PLUGIN_ENABLE,
    SET_PLUGIN_CONTROLER,
    REMOVE_PLUGIN_CONTROLER,
};

class IDataSourceService : public IInterface
{
public:
    DECLARE_META_INTERFACE(DataSourceService);

    virtual bool isPluginEnable(void) = 0;
    virtual void setPluginEnable(bool enable) = 0;
    virtual void setPluginControler(sp<IPluginControler> controler) = 0;
    virtual void removePluginControler() = 0;
};

class BnDataSourceService : public BnInterface<IDataSourceService>
{
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
};

#endif /* __I_DATA_SOURCE_SERVICE_H__ */
















