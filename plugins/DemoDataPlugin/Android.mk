LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_C_INCLUDES += \
    external/android-native-service-demo/common

LOCAL_SRC_FILES := \
    ../../common/IDataSourceService.cpp \
    ../../common/IPluginControler.cpp \
    DemoDataPlugin.cpp

LOCAL_SHARED_LIBRARIES += liblog libutils libcutils libbinder

LOCAL_PRELINK_MODULE := false

LOCAL_MODULE := libDataSourcePlugin

include $(BUILD_SHARED_LIBRARY)

