//#define LOG_NDEBUG 0
#define LOG_TAG "XmanClient"

#include <utils/Log.h>
#include <binder/IServiceManager.h>

#include "IXmanService.h"

int main(int argc, char **argv)
{
    //1、向ServiceManager查询获取XMAN_SERVICE服务对象的代理：BpBinder

    /*sp<IBinder> binder = defaultServiceManager()->getService(String16(XMAN_SERVICE)); 
    if(binder == NULL)
    {
        ALOGE("Failed to get Xman Service");
        return -1;
    }*/
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder;
    do 
    {
        binder = sm->getService(String16(XMAN_SERVICE));
        if (binder != 0)
        {
            break;
        }
        ALOGE("XMAN_SERVICE not published, waiting...");
        usleep(500000); // 0.5 s
    } while (true);

    //2、将BpBinder转换为 BpXmanService
    sp<IXmanService> service = interface_cast<IXmanService>(binder);//即：IXmanService::asInterface(binder); 
    if(service == NULL)
    {
        ALOGE("Failed to get Xman Service asInterface");
        return -1;
    }

    //通过代理对象BpXmanService调用服务端的方法(BpXmanService-->BnXmanServic-->XmanServic)
    ALOGD("begin getValue");
    int32_t val = service->getValue();
    ALOGD("Read original value from XmanService:%d", val);

    ALOGD("Add value 6 to XmanService");
    val += 6;
    service->setValue(val);

    ALOGD("begin getValue again");
    val = service->getValue();
    ALOGD("Read the value from XmanService again:%d", val);

    return 0;
}



