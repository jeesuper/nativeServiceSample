//#define LOG_NDEBUG 0 //for ALOGV
#define LOG_TAG "XmanServer"

#include <stdlib.h>
#include <fcntl.h>

#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

// from Android.mk LOCAL_C_INCLUDES
#include "IXmanService.h"

class XManService : public BnXmanService
{
public:
        XManService()
        {
            ALOGD("XManService");
        }

        virtual ~XManService()
        {
            ALOGD("~XManService");
        }

public:
    static void instantiate()
    {
        defaultServiceManager()->addService(String16(XMAN_SERVICE), new XManService());
    }

    int32_t getValue()
    {
        ALOGD("getValue");
        return mValue;
    }

    void setValue(int32_t val)
    {
        ALOGD("setValue:%d", val);
        mValue = val;
    }

private:
    int32_t mValue;
};


int main(int argc, char** argv)
{
    //1、打开/dev/binder设备,对返回的fd使用mmap，给Binder驱动分配一块内存来接收数据
    sp<ProcessState> proc(ProcessState::self());

    //2、向ServiceManager注册服务
    //其中defaultServiceManager()返回一个BpServiceManager；BpServiceManager的一个变量mRemote指向了BpBinder        
    XManService::instantiate();

    //3、新建一个线程，新建的线程和主线程都读取binder，查看是否有请求
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}



