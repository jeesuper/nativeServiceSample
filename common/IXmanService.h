#ifndef IXMANSERVICE_H_
#define IXMANSERVICE_H_

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

#define XMAN_SERVICE "Xman.Service"

using namespace android;

class IXmanService :  public IInterface
{
public:
	DECLARE_META_INTERFACE(XmanService);
	virtual int32_t getValue() = 0; //等于0 代表是纯虚函数
	virtual void setValue(int32_t val) = 0;
};


class BnXmanService : public BnInterface<IXmanService>
{
public:
	virtual status_t onTransact(uint32_t code, const Parcel & data, Parcel * reply, uint32_t flags = 0);

};


#endif



