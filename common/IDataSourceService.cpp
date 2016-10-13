#include "IDataSourceService.h"


using namespace android;

class BpDataSourceService : public BpInterface<IDataSourceService>
{
public:
    BpDataSourceService(const sp<IBinder>& impl) : BpInterface<IDataSourceService>(impl){};

    bool isPluginEnable()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IDataSourceService::getInterfaceDescriptor());
        remote()->transact(IS_PLUGIN_ENABLE, data, &reply);

        bool ret = reply.readInt32();
        return ret;
    };
    void setPluginEnable(bool enable)
    {
        printf("[BpDataSourceService] setPluginEnable\n");
        Parcel data, reply;
        data.writeInterfaceToken(IDataSourceService::getInterfaceDescriptor());
        data.writeInt32(enable);
        remote()->transact(SET_PLUGIN_ENABLE, data, &reply);
    };
    void setPluginControler(sp<IPluginControler>  controler)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IDataSourceService::getInterfaceDescriptor());
        data.writeStrongBinder(controler->asBinder());
        remote()->transact(SET_PLUGIN_CONTROLER, data, &reply);
    };
    void removePluginControler()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IDataSourceService::getInterfaceDescriptor());
        remote()->transact(REMOVE_PLUGIN_CONTROLER, data, &reply);
    };
};

IMPLEMENT_META_INTERFACE(DataSourceService, "yancy.github.plugin.service");


status_t BnDataSourceService::onTransact(uint32_t code, const Parcel & data, Parcel * reply, uint32_t flags)
{
    switch(code)
    {
        case IS_PLUGIN_ENABLE:
        {
            CHECK_INTERFACE(IDataSourceService, data, reply);
            bool ret = isPluginEnable();
            reply->writeInt32(ret);
            return NO_ERROR;
        }
        case SET_PLUGIN_ENABLE:
        {
            printf("[BnDataSourceService] onTransact SET_PLUGIN_ENABLE\n");
            CHECK_INTERFACE(IDataSourceService, data, reply);
            bool enable =  data.readInt32();
            setPluginEnable(enable);
            return NO_ERROR;
        }
        case SET_PLUGIN_CONTROLER:
        {
            CHECK_INTERFACE(IDataSourceService, data, reply);
            sp<IPluginControler> controler = interface_cast<IPluginControler>(data.readStrongBinder());
            setPluginControler(controler);
            return NO_ERROR;
        }
        case REMOVE_PLUGIN_CONTROLER:
        {
            CHECK_INTERFACE(IDataSourceService, data, reply);
            removePluginControler();
            return NO_ERROR;
        }
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}


















