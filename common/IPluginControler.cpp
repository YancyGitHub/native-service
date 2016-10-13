
#include "IPluginControler.h"


class BpPluginControler : public BpInterface<IPluginControler>
{
public:
    BpPluginControler(const sp<IBinder>& impl) : BpInterface<IPluginControler>(impl){};
    bool isEnable()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IPluginControler::getInterfaceDescriptor());
        remote()->transact(PLUGIN_CTRL_IS_ENABLE, data, &reply);

        bool ret = reply.readInt32();
        return ret;
    }
    void setEnable(bool enable)
    {
        printf("[BpPluginControler] setEnable %d\n", enable);
        Parcel data, reply;
        data.writeInterfaceToken(IPluginControler::getInterfaceDescriptor());
        data.writeInt32(enable);
        remote()->transact(PLUGIN_CTRL_SET_ENABLE, data, &reply);
    }
};

IMPLEMENT_META_INTERFACE(PluginControler, "yancy.github.plugin.IPluginControler");


status_t BnPluginControler::onTransact(uint32_t code,const Parcel & data,Parcel * reply,uint32_t flags)
{
    switch(code)
    {
        case PLUGIN_CTRL_IS_ENABLE:
        {
            CHECK_INTERFACE(IPluginControler, data, reply);
            bool ret = isEnable();
            reply->writeInt32(ret);
            return NO_ERROR;
        }
        case PLUGIN_CTRL_SET_ENABLE:
        {
            printf("[BnPluginControler] onTransact PLUGIN_CTRL_SET_ENABLE\n");
            CHECK_INTERFACE(IPluginControler, data, reply);
            bool enable = data.readInt32();
            setEnable(enable);

            return NO_ERROR;
        }
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}



