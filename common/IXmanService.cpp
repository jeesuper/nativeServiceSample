#define LOG_TAG "IXmanService"

#include <utils/Log.h>

#include "IXmanService.h"

using namespace android;

enum
{
    GET_VALUE = IBinder::FIRST_CALL_TRANSACTION,
	SET_VALUE
};


class BpXmanService : public BpInterface<IXmanService>
{
public:
	BpXmanService(const sp<IBinder>& impl) 
        : BpInterface<IXmanService>(impl) 
    {
    
    }

public:
    int32_t getValue()
    {
        ALOGD("BpXmanService---getValue---transact");
        Parcel data;
        data.writeInterfaceToken(IXmanService::getInterfaceDescriptor());
        
        Parcel reply;
        remote()->transact(GET_VALUE, data, &reply);
        
        int32_t val = reply.readInt32();
        return val;
    }

    void setValue(int32_t val)
    {
        ALOGD("BpXmanService---setValue---transact");
        Parcel data;
        data.writeInterfaceToken(IXmanService::getInterfaceDescriptor());
        data.writeInt32(val);

        Parcel reply;
        remote()->transact(SET_VALUE, data, &reply);
    }

};

//此宏展开即是 实现 asInterface(), getInterfaceDescriptor(), IXmanService的构造析构方法
IMPLEMENT_META_INTERFACE(XmanService, "Xman.Service");

status_t BnXmanService::onTransact(uint32_t code, const Parcel & data, Parcel * reply, uint32_t flags)
{
    switch(code)
    {
        case GET_VALUE:
        {
            ALOGD("BnXmanService---getValue---onTransact");
            CHECK_INTERFACE(IXmanService, data, reply);
            int32_t val = getValue(); //调用子类(XManService)的方法
            reply->writeInt32(val);
            return NO_ERROR;
        }
        case SET_VALUE:
        {
            ALOGD("BnXmanService---setValue---onTransact");
            CHECK_INTERFACE(IXmanService, data, reply);
            int32_t val = data.readInt32();
            setValue(val);//调用子类(XManService)的方法
            return NO_ERROR;
        }    
        default:
        {
            return BBinder::onTransact(code, data, reply, flags);
        }
    }
}




