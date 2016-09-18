#define LOG_NDEBUG 0
#define LOG_TAG "DEMOSERVICE"  
  
#include <utils/Log.h>  

#include "IDemoService.h"

using namespace android;

class BpDemoService : public BpInterface<IDemoService>
{
public:
    BpDemoService(const sp<IBinder>& impl) : BpInterface<IDemoService>(impl){};
    int AddNumber(int a, int b)
    {
        ALOGD("BpDemoService AddNumber a:%d , b:%d\n", a, b);

        Parcel data;  
        data.writeInterfaceToken(IDemoService::getInterfaceDescriptor());  
        data.writeInt32(a);
        data.writeInt32(b);

        Parcel reply;  
        remote()->transact(ADD_NUMBER, data, &reply);
    
        return reply.readInt32();
    }
    
    int MaxNumber(int a, int b)
    {
        ALOGD("BpDemoService MaxNumber a:%d , b:%d\n", a, b);
        Parcel data;  
        data.writeInterfaceToken(IDemoService::getInterfaceDescriptor());  
        data.writeInt32(a);
        data.writeInt32(b);
        
        Parcel reply;  
        remote()->transact(MAX_NUMBER, data, &reply);
    
        return reply.readInt32();
    }

};

IMPLEMENT_META_INTERFACE(DemoService, SERVICE_NAME);


status_t BnDemoService::onTransact(uint32_t code,const Parcel & data,Parcel * reply, uint32_t flags)
{
    switch(code)
    {
        case ADD_NUMBER:
        {
            CHECK_INTERFACE(ICamera, data, reply);
            int ret = AddNumber(data.readInt32(), data.readInt32());
            ALOGD("BpDemoService ADD_NUMBER ret:%d\n", ret);
            reply->writeInt32(ret);
            return NO_ERROR;
        }
        case MAX_NUMBER:
        {
            CHECK_INTERFACE(ICamera, data, reply);
            int ret = MaxNumber(data.readInt32(), data.readInt32());
            ALOGD("BpDemoService MAX_NUMBER ret:%d\n", ret);
            reply->writeInt32(ret);
            return NO_ERROR;
        }
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}











































