LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := ../common/IXmanService.cpp \
				./XmanServer.cpp			

LOCAL_C_INCLUDES := \
    nativeBinderSample/common/
								
LOCAL_SHARED_LIBRARIES:=libcutils libutils libbinder
LOCAL_MODULE := XManServer
include $(BUILD_EXECUTABLE)



