#ifndef __I_DEMO_SERVICE_H__
#define __I_DEMO_SERVICE_H__


#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

using namespace android;

#define SERVICE_NAME    "yancy.github.nativeservice"

enum {
    ADD_NUMBER = IBinder::FIRST_CALL_TRANSACTION,
    MAX_NUMBER
};


class IDemoService : public IInterface
{
public:
    DECLARE_META_INTERFACE(DemoService);

    virtual int AddNumber(int a, int b) = 0;
    virtual int MaxNumber(int a, int b) = 0;
};


class BnDemoService : public BnInterface<IDemoService>
{
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0); 
};

#endif /* __I_DEMO_SERVICE_H__ */















