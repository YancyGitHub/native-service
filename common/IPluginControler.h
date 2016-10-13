#ifndef __I_PLUGIN_CONTROLER_H__
#define __I_PLUGIN_CONTROLER_H__

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

using namespace android;
using android::sp;


enum {
    PLUGIN_CTRL_IS_ENABLE = IBinder::FIRST_CALL_TRANSACTION,
    PLUGIN_CTRL_SET_ENABLE
};


class IPluginControler : public IInterface
{
public:
    DECLARE_META_INTERFACE(PluginControler);

    virtual bool isEnable() = 0;
    virtual void setEnable(bool enable) = 0;
};


class BnPluginControler : public BnInterface<IPluginControler>
{
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
};

#endif /* __I_PLUGIN_CONTROLER_H__ */































